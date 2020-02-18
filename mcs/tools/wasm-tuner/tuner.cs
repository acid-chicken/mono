//
// tuner.cs: WebAssembly build time helpers
//
//
using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Json;
using System.Collections.Generic;
using Mono.Cecil;

class Icall : IComparable<Icall> {
  public Icall(string name, string func, bool handles) {
    Name = name;
    Func = func;
    Handles = handles;
  }

  public string Name;
  public string Func;
  public string Assembly;
  public bool Handles;
  public int TokenIndex;
  public MethodReference Method;

  public int CompareTo(Icall other) { return TokenIndex - other.TokenIndex; }
}

class IcallClass {
  public IcallClass(string name) {
    Name = name;
    Icalls = new Dictionary<string, Icall>();
  }

  public string Name;
  public Dictionary<string, Icall>Icalls;
}

class Pinvoke {
  public Pinvoke(string entry_point, string module, MethodReference method) {
    EntryPoint = entry_point;
    Module = module;
    Method = method;
  }

  public string EntryPoint;
  public string Module;
  public MethodReference Method;
}

public class WasmTuner {
  public static int Main(String[] args) { return new WasmTuner().Run(args); }

  List<Icall>icalls;

  Dictionary<string, IcallClass>runtime_icalls;

  List<Pinvoke>pinvokes;

  // Read the icall table generated by mono --print-icall-table
  void ReadTable(string filename) {
    JsonValue json;
    using(var stream = File.OpenText(filename)) {
      json = JsonValue.Load(stream);
    }

    runtime_icalls = new Dictionary<string, IcallClass>();
    var arr = (JsonArray) json;
    foreach(var v in arr) {
      if ((string) v["klass"] == "")
        // Dummy value
        continue;
      var icall_class = new IcallClass((string) v["klass"]);
      runtime_icalls[icall_class.Name] = icall_class;
      foreach(JsonObject icall_j in v["icalls"]) {
        if (icall_j.Count == 0)
          continue;
        string name = (string) icall_j["name"];
        string func = (string) icall_j["func"];
        bool handles = (bool) icall_j["handles"];

        icall_class.Icalls[name] = new Icall(name, func, handles);
      }
    }
  }

  void Usage() {
    Console.WriteLine("Usage: tuner.exe <arguments>");
    Console.WriteLine("Arguments:");
    Console.WriteLine("--gen-icall-table icall-table.json <assemblies>.");
    Console.WriteLine(
        "--gen-pinvoke-table <list of native library names separated by commas> <assemblies>.");
    Console.WriteLine("--gen-empty-assemblies <filenames>.");
  }

  int Run(String[] args) {
    if (args.Length < 1) {
      Usage();
      return 1;
    }
    string cmd = args[0];
    if (cmd == "--gen-icall-table") {
      if (args.Length < 3) {
        Usage();
        return 1;
      }
      return GenIcallTable(args);
    } else if (cmd == "--gen-pinvoke-table") {
      return GenPinvokeTable(args);
    } else if (cmd == "--gen-empty-assemblies") {
      return GenEmptyAssemblies(args);
    } else {
      Usage();
      return 1;
    }
  }

  static string MapType(TypeReference t) {
    if (t.Name == "Void")
      return "void";
    else if (t.Name == "Double")
      return "double";
    else if (t.Name == "Single")
      return "float";
    else if (t.Name == "Int64")
      return "int64_t";
    else if (t.Name == "UInt64")
      return "uint64_t";
    else
      return "int";
  }

  static string GenPinvokeDecl(Pinvoke pinvoke) {
    var sb = new StringBuilder();
    var method = pinvoke.Method;
    sb.Append(MapType(method.ReturnType));
    sb.Append($" {pinvoke.EntryPoint} (");
    int pindex = 0;
    foreach(var p in method.Parameters) {
      if (pindex > 0)
        sb.Append(",");
      sb.Append(MapType(method.Parameters[pindex].ParameterType));
      pindex++;
    }
    sb.Append(");");
    return sb.ToString();
  }

  int GenPinvokeTable(String[] args) {
    var modules = new Dictionary<string, string>();
    foreach(var module in args[1].Split(',')) modules[module] = module;

    args = args.Skip(2).ToArray();
    pinvokes = new List<Pinvoke>();
    foreach(var fname in args) {
      var a = AssemblyDefinition.ReadAssembly(fname);

      foreach(var type in a.MainModule.Types) {
        ProcessTypeForPinvoke(type);
        foreach(var nested in type.NestedTypes) ProcessTypeForPinvoke(nested);
      }
    }

    Console.WriteLine("// GENERATED FILE, DO NOT MODIFY");
    Console.WriteLine("typedef struct {");
    Console.WriteLine("const char *name;");
    Console.WriteLine("void *func;");
    Console.WriteLine("} PinvokeImport;");
    Console.WriteLine();

    foreach(var pinvoke in pinvokes) {
      if (modules.ContainsKey(pinvoke.Module))
        Console.WriteLine(GenPinvokeDecl(pinvoke));
    }

    foreach(var module in modules.Keys) {
      string symbol = module.Replace(".", "_") + "_imports";
      Console.WriteLine("static PinvokeImport " + symbol + " [] = {");
      foreach(var pinvoke in pinvokes) {
        if (pinvoke.Module == module)
          Console.WriteLine("{\"" + pinvoke.EntryPoint + "\", " +
                            pinvoke.EntryPoint + "},");
      }
      Console.WriteLine("{NULL, NULL}");
      Console.WriteLine("};");
    }
    Console.Write("static void *pinvoke_tables[] = { ");
    foreach(var module in modules.Keys) {
      string symbol = module.Replace(".", "_") + "_imports";
      Console.Write(symbol + ",");
    }
    Console.WriteLine("};");
    Console.Write("static char *pinvoke_names[] = { ");
    foreach(var module in modules.Keys) {
      Console.Write("\"" + module + "\"" + ",");
    }
    Console.WriteLine("};");

    return 0;
  }

  void ProcessTypeForPinvoke(TypeDefinition type) {
    foreach(var method in type.Methods) {
      var info = method.PInvokeInfo;
      if (info == null)
        continue;
      pinvokes.Add(new Pinvoke(info.EntryPoint, info.Module.Name, method));
    }
  }

  static string GenIcallDecl(Icall icall) {
    var sb = new StringBuilder();
    var method = icall.Method;
    sb.Append(MapType(method.ReturnType));
    sb.Append($" {icall.Func} (");
    int pindex = 0;
    int aindex = 0;
    if (method.HasThis) {
      sb.Append("int");
      aindex++;
    }
    foreach(var p in method.Parameters) {
      if (aindex > 0)
        sb.Append(",");
      sb.Append(MapType(method.Parameters[pindex].ParameterType));
      pindex++;
      aindex++;
    }
    if (icall.Handles) {
      if (aindex > 0)
        sb.Append(",");
      sb.Append("int");
      pindex++;
    }
    sb.Append(");");
    return sb.ToString();
  }

  //
  // Given the runtime generated icall table, and a set of assemblies, generate
  // a smaller linked icall table mapping tokens to C function names
  //
  int GenIcallTable(String[] args) {
    var icall_table_filename = args[1];
    args = args.Skip(2).ToArray();

    ReadTable(icall_table_filename);

    icalls = new List<Icall>();

    foreach(var fname in args) {
      var a = AssemblyDefinition.ReadAssembly(fname);

      foreach(var type in a.MainModule.Types) {
        ProcessType(type);
        foreach(var nested in type.NestedTypes) ProcessType(nested);
      }
    }

    var assemblies = new Dictionary<string, string>();
    foreach(var icall in icalls) assemblies[icall.Assembly] = icall.Assembly;

    foreach(var assembly in assemblies.Keys) {
      var sorted = icalls.Where(i => i.Assembly == assembly).ToArray();
      Array.Sort(sorted);

      Console.WriteLine($"#define ICALL_TABLE_{assembly} 1\n");

      Console.WriteLine($"static int {assembly}_icall_indexes [] = {{");
      foreach(var icall in sorted)
          Console.WriteLine(String.Format("{0},", icall.TokenIndex));
      Console.WriteLine("};");
      foreach(var icall in sorted) Console.WriteLine(GenIcallDecl(icall));
      Console.WriteLine($"static void *{assembly}_icall_funcs [] = {{");
      foreach(var icall in sorted) {
        Console.WriteLine(String.Format("// token {0},", icall.TokenIndex));
        Console.WriteLine(String.Format("{0},", icall.Func));
      }
      Console.WriteLine("};");
      Console.WriteLine($"static uint8_t {assembly}_icall_handles [] = {{");
      foreach(var icall in sorted)
          Console.WriteLine(String.Format("{0},", icall.Handles ? "1"
                                          : "0"));
      Console.WriteLine("};");
    }

    return 0;
  }

  // Append the type name used by the runtime icall tables
  void AppendType(StringBuilder sb, TypeReference t) {
    switch (t.MetadataType) {
    case MetadataType.Char:
      sb.Append("char");
      break;
    case MetadataType.Boolean:
      sb.Append("bool");
      break;
    case MetadataType.Byte:
      sb.Append("byte");
      break;
    case MetadataType.SByte:
      sb.Append("sbyte");
      break;
    case MetadataType.Int16:
      sb.Append("int16");
      break;
    case MetadataType.UInt16:
      sb.Append("uint16");
      break;
    case MetadataType.Int32:
      sb.Append("int");
      break;
    case MetadataType.UInt32:
      sb.Append("uint");
      break;
    case MetadataType.Int64:
      sb.Append("long");
      break;
    case MetadataType.UInt64:
      sb.Append("ulong");
      break;
    case MetadataType.IntPtr:
      sb.Append("intptr");
      break;
    case MetadataType.UIntPtr:
      sb.Append("uintptr");
      break;
    case MetadataType.Single:
      sb.Append("single");
      break;
    case MetadataType.Double:
      sb.Append("double");
      break;
    case MetadataType.Object:
      sb.Append("object");
      break;
    case MetadataType.String:
      sb.Append("string");
      break;
    case MetadataType.Array:
      AppendType(sb, (t as TypeSpecification).ElementType);
      sb.Append("[]");
      break;
    case MetadataType.ByReference:
      AppendType(sb, (t as TypeSpecification).ElementType);
      sb.Append("&");
      break;
    case MetadataType.Pointer:
      AppendType(sb, (t as TypeSpecification).ElementType);
      sb.Append("*");
      break;
    default:
      sb.Append(t.FullName);
      break;
    }
  }

  void ProcessType(TypeDefinition type) {
    foreach(var method in type.Methods) {
      if ((method.ImplAttributes & MethodImplAttributes.InternalCall) == 0)
        continue;

      if (method.Name == ".ctor")
        continue;

      var klass_name = method.DeclaringType.FullName;
      if (!runtime_icalls.ContainsKey(klass_name))
        // Registered at runtime
        continue;

      var klass = runtime_icalls[method.DeclaringType.FullName];

      Icall icall = null;

      // Try name first
      if (klass.Icalls.ContainsKey(method.Name)) {
        icall = klass.Icalls[method.Name];
      }
      if (icall == null) {
        // Then with signature
        var sig = new StringBuilder(method.Name + "(");
        int pindex = 0;
        foreach(var par in method.Parameters) {
          if (pindex > 0)
            sig.Append(",");
          var t = par.ParameterType;
          AppendType(sig, t);
          pindex++;
        }
        sig.Append(")");

        if (klass.Icalls.ContainsKey(sig.ToString())) {
          icall = klass.Icalls[sig.ToString()];
        }
      }
      if (icall == null)
        // Registered at runtime
        continue;

      icall.Method = method;
      icall.TokenIndex = (int) method.MetadataToken.RID;
      icall.Assembly = method.DeclaringType.Module.Assembly.Name.Name;
      icalls.Add(icall);
    }
  }

  // Generate empty assemblies for the filenames in ARGS if they don't exist
  int GenEmptyAssemblies(String[] args) {
    foreach(var fname in args) {
      if (File.Exists(fname))
        continue;
      var basename =
          Path.GetFileName(fname).Replace(".exe", "").Replace(".dll", "");
      var assembly = AssemblyDefinition.CreateAssembly(
          new AssemblyNameDefinition(basename, new Version(0, 0, 0, 0)),
          basename, ModuleKind.Dll);
      assembly.Write(fname);
    }
    return 0;
  }
}