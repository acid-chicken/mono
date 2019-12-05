ICALL_TYPE(SAFEWAITHANDLE, "Microsoft.Win32.SafeHandles.SafeWaitHandle",
           SAFEWAITHANDLE_1) // && UNIX
NOHANDLES(ICALL(SAFEWAITHANDLE_1, "CloseEventInternal",
                ves_icall_System_Threading_Events_CloseEvent_internal))

ICALL_TYPE(RUNTIME, "Mono.Runtime", RUNTIME_20)
NOHANDLES(ICALL(RUNTIME_20, "AnnotateMicrosoftTelemetry_internal",
                ves_icall_Mono_Runtime_AnnotateMicrosoftTelemetry))
NOHANDLES(ICALL(RUNTIME_19, "CheckCrashReportLog_internal",
                ves_icall_Mono_Runtime_CheckCrashReportingLog))
NOHANDLES(ICALL(RUNTIME_1, "DisableMicrosoftTelemetry",
                ves_icall_Mono_Runtime_DisableMicrosoftTelemetry))
HANDLES(RUNTIME_15, "DumpStateSingle_internal",
        ves_icall_Mono_Runtime_DumpStateSingle, MonoString, 2,
        (guint64_ref, guint64_ref))
HANDLES(RUNTIME_16, "DumpStateTotal_internal",
        ves_icall_Mono_Runtime_DumpStateTotal, MonoString, 2,
        (guint64_ref, guint64_ref))
NOHANDLES(ICALL(RUNTIME_18, "EnableCrashReportLog_internal",
                ves_icall_Mono_Runtime_EnableCrashReportingLog))
HANDLES(RUNTIME_2, "EnableMicrosoftTelemetry_internal",
        ves_icall_Mono_Runtime_EnableMicrosoftTelemetry, void, 6,
        (const_char_ptr, const_char_ptr, const_char_ptr, const_char_ptr,
         const_char_ptr, const_char_ptr))
HANDLES(RUNTIME_3, "ExceptionToState_internal",
        ves_icall_Mono_Runtime_ExceptionToState, MonoString, 3,
        (MonoException, guint64_ref, guint64_ref))
HANDLES(RUNTIME_4, "GetDisplayName", ves_icall_Mono_Runtime_GetDisplayName,
        MonoString, 0, ())
HANDLES(RUNTIME_12, "GetNativeStackTrace",
        ves_icall_Mono_Runtime_GetNativeStackTrace, MonoString, 1,
        (MonoException))
NOHANDLES(ICALL(RUNTIME_21, "RegisterReportingForAllNativeLibs_internal",
                ves_icall_Mono_Runtime_RegisterReportingForAllNativeLibs))
NOHANDLES(ICALL(RUNTIME_17, "RegisterReportingForNativeLib_internal",
                ves_icall_Mono_Runtime_RegisterReportingForNativeLib))
HANDLES(RUNTIME_13, "SendMicrosoftTelemetry_internal",
        ves_icall_Mono_Runtime_SendMicrosoftTelemetry, void, 3,
        (const_char_ptr, guint64, guint64))
HANDLES(RUNTIME_14, "WriteStateToFile_internal",
        ves_icall_Mono_Runtime_DumpTelemetry, void, 3,
        (const_char_ptr, guint64, guint64))

ICALL_TYPE(RTCLASS, "Mono.RuntimeClassHandle", RTCLASS_1)
NOHANDLES(ICALL(RTCLASS_1, "GetTypeFromClass",
                ves_icall_Mono_RuntimeClassHandle_GetTypeFromClass))

ICALL_TYPE(RTPTRARRAY, "Mono.RuntimeGPtrArrayHandle", RTPTRARRAY_1)
NOHANDLES(ICALL(RTPTRARRAY_1, "GPtrArrayFree",
                ves_icall_Mono_RuntimeGPtrArrayHandle_GPtrArrayFree))

ICALL_TYPE(RTMARSHAL, "Mono.RuntimeMarshal", RTMARSHAL_1)
NOHANDLES(ICALL(RTMARSHAL_1, "FreeAssemblyName",
                ves_icall_Mono_RuntimeMarshal_FreeAssemblyName))

ICALL_TYPE(SAFESTRMARSHAL, "Mono.SafeStringMarshal", SAFESTRMARSHAL_1)
NOHANDLES(ICALL(SAFESTRMARSHAL_1, "GFree",
                ves_icall_Mono_SafeStringMarshal_GFree))
NOHANDLES(ICALL(SAFESTRMARSHAL_2, "StringToUtf8_icall",
                ves_icall_Mono_SafeStringMarshal_StringToUtf8))

ICALL_TYPE(ARGI, "System.ArgIterator", ARGI_1)
NOHANDLES(ICALL(ARGI_1, "IntGetNextArg",
                ves_icall_System_ArgIterator_IntGetNextArg))
NOHANDLES(ICALL(ARGI_2, "IntGetNextArgType",
                ves_icall_System_ArgIterator_IntGetNextArgType))
NOHANDLES(ICALL(ARGI_3, "IntGetNextArgWithType",
                ves_icall_System_ArgIterator_IntGetNextArgWithType))
NOHANDLES(ICALL(ARGI_4, "Setup", ves_icall_System_ArgIterator_Setup))

ICALL_TYPE(ARRAY, "System.Array", ARRAY_0)
NOHANDLES(ICALL(ARRAY_0, "CanChangePrimitive",
                ves_icall_System_Array_CanChangePrimitive))
HANDLES(ARRAY_4, "FastCopy", ves_icall_System_Array_FastCopy, MonoBoolean, 5,
        (MonoArray, int, MonoArray, int, int))
HANDLES(ARRAY_4a, "GetCorElementTypeOfElementType",
        ves_icall_System_Array_GetCorElementTypeOfElementType, gint32, 1,
        (MonoArray))
NOHANDLES(ICALL(ARRAY_5, "GetGenericValue_icall",
                ves_icall_System_Array_GetGenericValue_icall))
HANDLES(ARRAY_6, "GetLength", ves_icall_System_Array_GetLength, gint32, 2,
        (MonoArray, gint32))
HANDLES(ARRAY_15, "GetLongLength", ves_icall_System_Array_GetLongLength, gint64,
        2, (MonoArray, gint32))
HANDLES(ARRAY_7, "GetLowerBound", ves_icall_System_Array_GetLowerBound, gint32,
        2, (MonoArray, gint32))
HANDLES(ARRAY_8, "GetRank", ves_icall_System_Array_GetRank, gint32, 1,
        (MonoObject))
HANDLES(ARRAY_9, "GetValue", ves_icall_System_Array_GetValue, MonoObject, 2,
        (MonoArray, MonoArray))
HANDLES(ARRAY_10, "GetValueImpl", ves_icall_System_Array_GetValueImpl,
        MonoObject, 2, (MonoArray, guint32))
NOHANDLES(ICALL(ARRAY_10a, "InternalCreate",
                ves_icall_System_Array_InternalCreate))
HANDLES(ARRAY_10b, "IsValueOfElementType",
        ves_icall_System_Array_IsValueOfElementType, gint32, 2,
        (MonoArray, MonoObject))
NOHANDLES(ICALL(ARRAY_11, "SetGenericValue_icall",
                ves_icall_System_Array_SetGenericValue_icall))
HANDLES(ARRAY_12, "SetValue", ves_icall_System_Array_SetValue, void, 3,
        (MonoArray, MonoObject, MonoArray))
HANDLES(ARRAY_13, "SetValueImpl", ves_icall_System_Array_SetValueImpl, void, 3,
        (MonoArray, MonoObject, guint32))
HANDLES(ARRAY_14, "SetValueRelaxedImpl",
        ves_icall_System_Array_SetValueRelaxedImpl, void, 3,
        (MonoArray, MonoObject, guint32))

ICALL_TYPE(BUFFER, "System.Buffer", BUFFER_0)
NOHANDLES(
    ICALL(BUFFER_0, "BulkMoveWithWriteBarrier",
          ves_icall_System_Runtime_RuntimeImports_RhBulkMoveWithWriteBarrier))
NOHANDLES(ICALL(BUFFER_2, "__Memmove",
                ves_icall_System_Runtime_RuntimeImports_Memmove))
NOHANDLES(ICALL(BUFFER_3, "__ZeroMemory",
                ves_icall_System_Runtime_RuntimeImports_ZeroMemory))

ICALL_TYPE(DELEGATE, "System.Delegate", DELEGATE_1)
HANDLES(DELEGATE_1, "AllocDelegateLike_internal",
        ves_icall_System_Delegate_AllocDelegateLike_internal,
        MonoMulticastDelegate, 1, (MonoDelegate))
HANDLES(DELEGATE_2, "CreateDelegate_internal",
        ves_icall_System_Delegate_CreateDelegate_internal, MonoObject, 4,
        (MonoReflectionType, MonoObject, MonoReflectionMethod, MonoBoolean))
HANDLES(DELEGATE_3, "GetVirtualMethod_internal",
        ves_icall_System_Delegate_GetVirtualMethod_internal,
        MonoReflectionMethod, 1, (MonoDelegate))

ICALL_TYPE(DEBUGR, "System.Diagnostics.Debugger", DEBUGR_1)
NOHANDLES(ICALL(DEBUGR_1, "IsAttached_internal",
                ves_icall_System_Diagnostics_Debugger_IsAttached_internal))
NOHANDLES(ICALL(DEBUGR_2, "IsLogging",
                ves_icall_System_Diagnostics_Debugger_IsLogging))
NOHANDLES(ICALL(DEBUGR_3, "Log_icall",
                ves_icall_System_Diagnostics_Debugger_Log))

ICALL_TYPE(ENUM, "System.Enum", ENUM_1)
HANDLES(ENUM_1, "GetEnumValuesAndNames",
        ves_icall_System_Enum_GetEnumValuesAndNames, MonoBoolean, 3,
        (MonoReflectionType, MonoArrayOut, MonoArrayOut))
HANDLES(ENUM_2, "InternalBoxEnum", ves_icall_System_Enum_ToObject, MonoObject,
        2, (MonoReflectionType, guint64))
HANDLES(ENUM_3, "InternalGetCorElementType",
        ves_icall_System_Enum_InternalGetCorElementType, int, 1, (MonoObject))
HANDLES(ENUM_4, "InternalGetUnderlyingType",
        ves_icall_System_Enum_get_underlying_type, MonoReflectionType, 1,
        (MonoReflectionType))
HANDLES(ENUM_5, "InternalHasFlag", ves_icall_System_Enum_InternalHasFlag,
        MonoBoolean, 2, (MonoObject, MonoObject))

ICALL_TYPE(ENV, "System.Environment", ENV_1)
NOHANDLES(ICALL(ENV_1, "Exit", ves_icall_System_Environment_Exit))
HANDLES(ENV_1a, "FailFast", ves_icall_System_Environment_FailFast, void, 3,
        (MonoString, MonoException, MonoString))
HANDLES(ENV_2, "GetCommandLineArgs",
        ves_icall_System_Environment_GetCommandLineArgs, MonoArray, 0, ())
HANDLES(ENV_3, "GetEnvironmentVariableNames",
        ves_icall_System_Environment_GetEnvironmentVariableNames, MonoArray, 0,
        ())
NOHANDLES(ICALL(ENV_4, "GetProcessorCount",
                ves_icall_System_Environment_get_ProcessorCount))
NOHANDLES(ICALL(ENV_9, "get_ExitCode", mono_environment_exitcode_get))
HANDLES(ENV_11, "get_MachineName", ves_icall_System_Environment_get_MachineName,
        MonoString, 0, ())
NOHANDLES(ICALL(ENV_13, "get_Platform",
                ves_icall_System_Environment_get_Platform))
NOHANDLES(ICALL(ENV_15, "get_TickCount",
                ves_icall_System_Environment_get_TickCount))
NOHANDLES(ICALL(ENV_15a, "get_TickCount64",
                ves_icall_System_Environment_get_TickCount64))
HANDLES(ENV_16, "get_UserName", ves_icall_System_Environment_get_UserName,
        MonoString, 0, ())
HANDLES(ENV_17, "internalGetEnvironmentVariable_native",
        ves_icall_System_Environment_GetEnvironmentVariable_native, MonoString,
        1, (const_char_ptr))
NOHANDLES(ICALL(ENV_20, "set_ExitCode", mono_environment_exitcode_set))

ICALL_TYPE(GC, "System.GC", GC_10)
NOHANDLES(ICALL(GC_10, "GetAllocatedBytesForCurrentThread",
                ves_icall_System_GC_GetAllocatedBytesForCurrentThread))
NOHANDLES(ICALL(GC_0, "GetCollectionCount",
                ves_icall_System_GC_GetCollectionCount))
HANDLES(GC_0a, "GetGeneration", ves_icall_System_GC_GetGeneration, int, 1,
        (MonoObject))
NOHANDLES(ICALL(GC_0b, "GetMaxGeneration",
                ves_icall_System_GC_GetMaxGeneration))
HANDLES(GC_11, "GetTotalAllocatedBytes",
        ves_icall_System_GC_GetTotalAllocatedBytes, guint64, 1, (MonoBoolean))
NOHANDLES(ICALL(GC_1, "GetTotalMemory", ves_icall_System_GC_GetTotalMemory))
NOHANDLES(ICALL(GC_2, "InternalCollect", ves_icall_System_GC_InternalCollect))
NOHANDLES(ICALL(GC_4a, "RecordPressure", ves_icall_System_GC_RecordPressure))
NOHANDLES(ICALL(GC_6, "WaitForPendingFinalizers",
                ves_icall_System_GC_WaitForPendingFinalizers))
NOHANDLES(ICALL(GC_12, "_GetGCMemoryInfo", ves_icall_System_GC_GetGCMemoryInfo))
HANDLES(GC_6b, "_ReRegisterForFinalize",
        ves_icall_System_GC_ReRegisterForFinalize, void, 1, (MonoObject))
HANDLES(GC_7, "_SuppressFinalize", ves_icall_System_GC_SuppressFinalize, void,
        1, (MonoObject))
HANDLES(GC_9, "get_ephemeron_tombstone",
        ves_icall_System_GC_get_ephemeron_tombstone, MonoObject, 0, ())
HANDLES(GC_8, "register_ephemeron_array",
        ves_icall_System_GC_register_ephemeron_array, void, 1, (MonoObject))

ICALL_TYPE(STREAM, "System.IO.Stream", STREAM_1)
HANDLES(STREAM_1, "HasOverriddenBeginEndRead",
        ves_icall_System_IO_Stream_HasOverriddenBeginEndRead, MonoBoolean, 1,
        (MonoObject))
HANDLES(STREAM_2, "HasOverriddenBeginEndWrite",
        ves_icall_System_IO_Stream_HasOverriddenBeginEndWrite, MonoBoolean, 1,
        (MonoObject))

ICALL_TYPE(MATH, "System.Math", MATH_19)
NOHANDLES(ICALL(MATH_19, "Abs(double)", ves_icall_System_Math_Abs_double))
NOHANDLES(ICALL(MATH_20, "Abs(single)", ves_icall_System_Math_Abs_single))
NOHANDLES(ICALL(MATH_1, "Acos", ves_icall_System_Math_Acos))
NOHANDLES(ICALL(MATH_1a, "Acosh", ves_icall_System_Math_Acosh))
NOHANDLES(ICALL(MATH_2, "Asin", ves_icall_System_Math_Asin))
NOHANDLES(ICALL(MATH_2a, "Asinh", ves_icall_System_Math_Asinh))
NOHANDLES(ICALL(MATH_3, "Atan", ves_icall_System_Math_Atan))
NOHANDLES(ICALL(MATH_4, "Atan2", ves_icall_System_Math_Atan2))
NOHANDLES(ICALL(MATH_4a, "Atanh", ves_icall_System_Math_Atanh))
NOHANDLES(ICALL(MATH_4b, "Cbrt", ves_icall_System_Math_Cbrt))
NOHANDLES(ICALL(MATH_21, "Ceiling", ves_icall_System_Math_Ceiling))
NOHANDLES(ICALL(MATH_5, "Cos", ves_icall_System_Math_Cos))
NOHANDLES(ICALL(MATH_6, "Cosh", ves_icall_System_Math_Cosh))
NOHANDLES(ICALL(MATH_7, "Exp", ves_icall_System_Math_Exp))
NOHANDLES(ICALL(MATH_7a, "FMod", ves_icall_System_Math_FMod))
NOHANDLES(ICALL(MATH_8, "Floor", ves_icall_System_Math_Floor))
NOHANDLES(ICALL(MATH_22, "FusedMultiplyAdd",
                ves_icall_System_Math_FusedMultiplyAdd))
NOHANDLES(ICALL(MATH_23, "ILogB", ves_icall_System_Math_ILogB))
NOHANDLES(ICALL(MATH_9, "Log", ves_icall_System_Math_Log))
NOHANDLES(ICALL(MATH_10, "Log10", ves_icall_System_Math_Log10))
NOHANDLES(ICALL(MATH_24, "Log2", ves_icall_System_Math_Log2))
NOHANDLES(ICALL(MATH_10a, "ModF", ves_icall_System_Math_ModF))
NOHANDLES(ICALL(MATH_11, "Pow", ves_icall_System_Math_Pow))
NOHANDLES(ICALL(MATH_12, "Round", ves_icall_System_Math_Round))
NOHANDLES(ICALL(MATH_25, "ScaleB", ves_icall_System_Math_ScaleB))
NOHANDLES(ICALL(MATH_14, "Sin", ves_icall_System_Math_Sin))
NOHANDLES(ICALL(MATH_15, "Sinh", ves_icall_System_Math_Sinh))
NOHANDLES(ICALL(MATH_16, "Sqrt", ves_icall_System_Math_Sqrt))
NOHANDLES(ICALL(MATH_17, "Tan", ves_icall_System_Math_Tan))
NOHANDLES(ICALL(MATH_18, "Tanh", ves_icall_System_Math_Tanh))

ICALL_TYPE(MATHF, "System.MathF", MATHF_1)
NOHANDLES(ICALL(MATHF_1, "Acos", ves_icall_System_MathF_Acos))
NOHANDLES(ICALL(MATHF_2, "Acosh", ves_icall_System_MathF_Acosh))
NOHANDLES(ICALL(MATHF_3, "Asin", ves_icall_System_MathF_Asin))
NOHANDLES(ICALL(MATHF_4, "Asinh", ves_icall_System_MathF_Asinh))
NOHANDLES(ICALL(MATHF_5, "Atan", ves_icall_System_MathF_Atan))
NOHANDLES(ICALL(MATHF_6, "Atan2", ves_icall_System_MathF_Atan2))
NOHANDLES(ICALL(MATHF_7, "Atanh", ves_icall_System_MathF_Atanh))
NOHANDLES(ICALL(MATHF_8, "Cbrt", ves_icall_System_MathF_Cbrt))
NOHANDLES(ICALL(MATHF_9, "Ceiling", ves_icall_System_MathF_Ceiling))
NOHANDLES(ICALL(MATHF_10, "Cos", ves_icall_System_MathF_Cos))
NOHANDLES(ICALL(MATHF_11, "Cosh", ves_icall_System_MathF_Cosh))
NOHANDLES(ICALL(MATHF_12, "Exp", ves_icall_System_MathF_Exp))
NOHANDLES(ICALL(MATHF_22, "FMod", ves_icall_System_MathF_FMod))
NOHANDLES(ICALL(MATHF_13, "Floor", ves_icall_System_MathF_Floor))
NOHANDLES(ICALL(MATHF_24, "FusedMultiplyAdd",
                ves_icall_System_MathF_FusedMultiplyAdd))
NOHANDLES(ICALL(MATHF_25, "ILogB", ves_icall_System_MathF_ILogB))
NOHANDLES(ICALL(MATHF_14, "Log", ves_icall_System_MathF_Log))
NOHANDLES(ICALL(MATHF_15, "Log10", ves_icall_System_MathF_Log10))
NOHANDLES(ICALL(MATHF_26, "Log2", ves_icall_System_MathF_Log2))
NOHANDLES(ICALL(MATHF_23, "ModF(single,single*)", ves_icall_System_MathF_ModF))
NOHANDLES(ICALL(MATHF_16, "Pow", ves_icall_System_MathF_Pow))
NOHANDLES(ICALL(MATHF_27, "ScaleB", ves_icall_System_MathF_ScaleB))
NOHANDLES(ICALL(MATHF_17, "Sin", ves_icall_System_MathF_Sin))
NOHANDLES(ICALL(MATHF_18, "Sinh", ves_icall_System_MathF_Sinh))
NOHANDLES(ICALL(MATHF_19, "Sqrt", ves_icall_System_MathF_Sqrt))
NOHANDLES(ICALL(MATHF_20, "Tan", ves_icall_System_MathF_Tan))
NOHANDLES(ICALL(MATHF_21, "Tanh", ves_icall_System_MathF_Tanh))

ICALL_TYPE(OBJ, "System.Object", OBJ_1)
HANDLES(OBJ_1, "GetType", ves_icall_System_Object_GetType, MonoReflectionType,
        1, (MonoObject))
HANDLES(OBJ_3, "MemberwiseClone", ves_icall_System_Object_MemberwiseClone,
        MonoObject, 1, (MonoObject))

ICALL_TYPE(ASSEM, "System.Reflection.Assembly", ASSEM_2)
HANDLES(ASSEM_2, "GetCallingAssembly",
        ves_icall_System_Reflection_Assembly_GetCallingAssembly,
        MonoReflectionAssembly, 0, ())
HANDLES(ASSEM_3, "GetEntryAssembly",
        ves_icall_System_Reflection_Assembly_GetEntryAssembly,
        MonoReflectionAssembly, 0, ())
HANDLES(ASSEM_4, "GetExecutingAssembly",
        ves_icall_System_Reflection_Assembly_GetExecutingAssembly,
        MonoReflectionAssembly, 1, (MonoStackCrawlMark_ptr))
HANDLES(ASSEM_5, "InternalGetAssemblyName",
        ves_icall_System_Reflection_Assembly_InternalGetAssemblyName, void, 3,
        (MonoString, MonoAssemblyName_ref, MonoStringOut))
HANDLES(ASSEM_6, "InternalGetType",
        ves_icall_System_Reflection_Assembly_InternalGetType,
        MonoReflectionType, 5,
        (MonoReflectionAssembly, MonoReflectionModule, MonoString, MonoBoolean,
         MonoBoolean))
HANDLES(ASSEM_7, "InternalLoad",
        ves_icall_System_Reflection_Assembly_InternalLoad,
        MonoReflectionAssembly, 3,
        (MonoString, MonoStackCrawlMark_ptr, gpointer))

ICALL_TYPE(ASSEMN, "System.Reflection.AssemblyName", ASSEMN_0)
NOHANDLES(ICALL(ASSEMN_0, "GetNativeName",
                ves_icall_System_Reflection_AssemblyName_GetNativeName))
NOHANDLES(ICALL(ASSEMN_3, "ParseAssemblyName",
                ves_icall_System_Reflection_AssemblyName_ParseAssemblyName))
NOHANDLES(ICALL(ASSEMN_2, "get_public_token", mono_digest_get_public_token))

ICALL_TYPE(MCATTR, "System.Reflection.CustomAttribute", MCATTR_1)
HANDLES(MCATTR_1, "GetCustomAttributesDataInternal",
        ves_icall_MonoCustomAttrs_GetCustomAttributesDataInternal, MonoArray, 1,
        (MonoObject))
HANDLES(MCATTR_2, "GetCustomAttributesInternal",
        ves_icall_MonoCustomAttrs_GetCustomAttributesInternal, MonoArray, 3,
        (MonoObject, MonoReflectionType, MonoBoolean))
HANDLES(MCATTR_3, "IsDefinedInternal",
        ves_icall_MonoCustomAttrs_IsDefinedInternal, MonoBoolean, 2,
        (MonoObject, MonoReflectionType))

ICALL_TYPE(CATTR_DATA, "System.Reflection.CustomAttributeData", CATTR_DATA_1)
HANDLES(
    CATTR_DATA_1, "ResolveArgumentsInternal",
    ves_icall_System_Reflection_CustomAttributeData_ResolveArgumentsInternal,
    void, 6,
    (MonoReflectionMethod, MonoReflectionAssembly, gpointer, guint32,
     MonoArrayOut, MonoArrayOut))

ICALL_TYPE(ASSEMB, "System.Reflection.Emit.AssemblyBuilder", ASSEMB_1)
HANDLES(ASSEMB_1, "UpdateNativeCustomAttributes",
        ves_icall_AssemblyBuilder_UpdateNativeCustomAttributes, void, 1,
        (MonoReflectionAssemblyBuilder))
HANDLES(ASSEMB_2, "basic_init", ves_icall_AssemblyBuilder_basic_init, void, 1,
        (MonoReflectionAssemblyBuilder))

ICALL_TYPE(CATTRB, "System.Reflection.Emit.CustomAttributeBuilder", CATTRB_1)
HANDLES(CATTRB_1, "GetBlob", ves_icall_CustomAttributeBuilder_GetBlob,
        MonoArray, 7,
        (MonoReflectionAssembly, MonoObject, MonoArray, MonoArray, MonoArray,
         MonoArray, MonoArray))

ICALL_TYPE(DYNM, "System.Reflection.Emit.DynamicMethod", DYNM_1)
HANDLES(DYNM_1, "create_dynamic_method",
        ves_icall_DynamicMethod_create_dynamic_method, void, 1,
        (MonoReflectionDynamicMethod))

ICALL_TYPE(ENUMB, "System.Reflection.Emit.EnumBuilder", ENUMB_1)
HANDLES(ENUMB_1, "setup_enum_type", ves_icall_EnumBuilder_setup_enum_type, void,
        2, (MonoReflectionType, MonoReflectionType))

ICALL_TYPE(MODULEB, "System.Reflection.Emit.ModuleBuilder", MODULEB_10)
HANDLES(MODULEB_10, "GetRegisteredToken",
        ves_icall_ModuleBuilder_GetRegisteredToken, MonoObject, 2,
        (MonoReflectionModuleBuilder, guint32))
HANDLES(MODULEB_8, "RegisterToken", ves_icall_ModuleBuilder_RegisterToken, void,
        3, (MonoReflectionModuleBuilder, MonoObject, guint32))
HANDLES(MODULEB_2, "basic_init", ves_icall_ModuleBuilder_basic_init, void, 1,
        (MonoReflectionModuleBuilder))
HANDLES(MODULEB_5, "getMethodToken", ves_icall_ModuleBuilder_getMethodToken,
        gint32, 3,
        (MonoReflectionModuleBuilder, MonoReflectionMethod, MonoArray))
HANDLES(MODULEB_6, "getToken", ves_icall_ModuleBuilder_getToken, gint32, 3,
        (MonoReflectionModuleBuilder, MonoObject, MonoBoolean))
HANDLES(MODULEB_7, "getUSIndex", ves_icall_ModuleBuilder_getUSIndex, guint32, 2,
        (MonoReflectionModuleBuilder, MonoString))
HANDLES(MODULEB_9, "set_wrappers_type",
        ves_icall_ModuleBuilder_set_wrappers_type, void, 2,
        (MonoReflectionModuleBuilder, MonoReflectionType))

ICALL_TYPE(SIGH, "System.Reflection.Emit.SignatureHelper", SIGH_1)
HANDLES(SIGH_1, "get_signature_field",
        ves_icall_SignatureHelper_get_signature_field, MonoArray, 1,
        (MonoReflectionSigHelper))
HANDLES(SIGH_2, "get_signature_local",
        ves_icall_SignatureHelper_get_signature_local, MonoArray, 1,
        (MonoReflectionSigHelper))

ICALL_TYPE(TYPEB, "System.Reflection.Emit.TypeBuilder", TYPEB_1)
HANDLES(TYPEB_1, "create_runtime_class",
        ves_icall_TypeBuilder_create_runtime_class, MonoReflectionType, 1,
        (MonoReflectionTypeBuilder))

ICALL_TYPE(FIELDI, "System.Reflection.FieldInfo", FILEDI_1)
HANDLES(FILEDI_1, "get_marshal_info",
        ves_icall_System_Reflection_FieldInfo_get_marshal_info,
        MonoReflectionMarshalAsAttribute, 1, (MonoReflectionField))

HANDLES(FILEDI_2, "internal_from_handle_type",
        ves_icall_System_Reflection_FieldInfo_internal_from_handle_type,
        MonoReflectionField, 2, (MonoClassField_ref, MonoType_ref))

ICALL_TYPE(MBASE, "System.Reflection.MethodBase", MBASE_1)
HANDLES(MBASE_1, "GetCurrentMethod", ves_icall_GetCurrentMethod,
        MonoReflectionMethod, 0, ())

ICALL_TYPE(MMETHI, "System.Reflection.MonoMethodInfo", MMETHI_4)
NOHANDLES(ICALL(MMETHI_4, "get_method_attributes",
                ves_icall_get_method_attributes))
HANDLES(MMETHI_1, "get_method_info", ves_icall_get_method_info, void, 2,
        (MonoMethod_ptr, MonoMethodInfo_ref))
HANDLES(MMETHI_2, "get_parameter_info",
        ves_icall_System_Reflection_MonoMethodInfo_get_parameter_info,
        MonoArray, 2, (MonoMethod_ptr, MonoReflectionMethod))
HANDLES(MMETHI_3, "get_retval_marshal",
        ves_icall_System_MonoMethodInfo_get_retval_marshal,
        MonoReflectionMarshalAsAttribute, 1, (MonoMethod_ptr))

ICALL_TYPE(RASSEM, "System.Reflection.RuntimeAssembly", RASSEM_1)
HANDLES(RASSEM_1, "GetExportedTypes",
        ves_icall_System_Reflection_RuntimeAssembly_GetExportedTypes, MonoArray,
        1, (MonoReflectionAssembly))
HANDLES(RASSEM_1a, "GetFilesInternal",
        ves_icall_System_Reflection_RuntimeAssembly_GetFilesInternal,
        MonoObject, 3, (MonoReflectionAssembly, MonoString, MonoBoolean))
HANDLES(RASSEM_2, "GetManifestModuleInternal",
        ves_icall_System_Reflection_Assembly_GetManifestModuleInternal,
        MonoReflectionModule, 1, (MonoReflectionAssembly))
HANDLES(
    RASSEM_3, "GetManifestResourceInfoInternal",
    ves_icall_System_Reflection_RuntimeAssembly_GetManifestResourceInfoInternal,
    MonoBoolean, 3,
    (MonoReflectionAssembly, MonoString, MonoManifestResourceInfo))
HANDLES(RASSEM_4, "GetManifestResourceInternal",
        ves_icall_System_Reflection_RuntimeAssembly_GetManifestResourceInternal,
        gpointer, 4,
        (MonoReflectionAssembly, MonoString, gint32_ref,
         MonoReflectionModuleOut))
HANDLES(RASSEM_5, "GetManifestResourceNames",
        ves_icall_System_Reflection_RuntimeAssembly_GetManifestResourceNames,
        MonoArray, 1, (MonoReflectionAssembly))
HANDLES(RASSEM_6, "GetModulesInternal",
        ves_icall_System_Reflection_RuntimeAssembly_GetModulesInternal,
        MonoArray, 1, (MonoReflectionAssembly))
HANDLES(RASSEM_6b, "GetTopLevelForwardedTypes",
        ves_icall_System_Reflection_RuntimeAssembly_GetTopLevelForwardedTypes,
        MonoArray, 1, (MonoReflectionAssembly))
HANDLES(RASSEM_7, "InternalGetReferencedAssemblies",
        ves_icall_System_Reflection_Assembly_InternalGetReferencedAssemblies,
        GPtrArray_ptr, 1, (MonoReflectionAssembly))
HANDLES(RASSEM_8, "InternalImageRuntimeVersion",
        ves_icall_System_Reflection_RuntimeAssembly_InternalImageRuntimeVersion,
        MonoString, 1, (MonoReflectionAssembly))
HANDLES(RASSEM_9, "get_EntryPoint",
        ves_icall_System_Reflection_RuntimeAssembly_get_EntryPoint,
        MonoReflectionMethod, 1, (MonoReflectionAssembly))
HANDLES(RASSEM_10, "get_code_base",
        ves_icall_System_Reflection_RuntimeAssembly_get_code_base, MonoString,
        2, (MonoReflectionAssembly, MonoBoolean))
HANDLES(RASSEM_11, "get_fullname",
        ves_icall_System_Reflection_RuntimeAssembly_get_fullname, MonoString, 1,
        (MonoReflectionAssembly))
HANDLES(RASSEM_12, "get_location",
        ves_icall_System_Reflection_RuntimeAssembly_get_location, MonoString, 1,
        (MonoReflectionAssembly))

ICALL_TYPE(MCMETH, "System.Reflection.RuntimeConstructorInfo", MCMETH_1)
HANDLES(MCMETH_1, "GetGenericMethodDefinition_impl",
        ves_icall_RuntimeMethodInfo_GetGenericMethodDefinition,
        MonoReflectionMethod, 1, (MonoReflectionMethod))
HANDLES(MCMETH_2, "InternalInvoke", ves_icall_InternalInvoke, MonoObject, 4,
        (MonoReflectionMethod, MonoObject, MonoArray, MonoExceptionOut))
HANDLES(MCMETH_3, "get_core_clr_security_level",
        ves_icall_RuntimeMethodInfo_get_core_clr_security_level, int, 1,
        (MonoReflectionMethod))
HANDLES_REUSE_WRAPPER(MCMETH_4, "get_metadata_token",
                      ves_icall_reflection_get_token)

ICALL_TYPE(MEV, "System.Reflection.RuntimeEventInfo", MEV_1)
HANDLES(MEV_1, "get_event_info", ves_icall_RuntimeEventInfo_get_event_info,
        void, 2, (MonoReflectionMonoEvent, MonoEventInfo_ref))
HANDLES_REUSE_WRAPPER(MEV_2, "get_metadata_token",
                      ves_icall_reflection_get_token)
HANDLES(MEV_3, "internal_from_handle_type",
        ves_icall_System_Reflection_EventInfo_internal_from_handle_type,
        MonoReflectionEvent, 2, (MonoEvent_ref, MonoType_ref))

ICALL_TYPE(MFIELD, "System.Reflection.RuntimeFieldInfo", MFIELD_1)
HANDLES(MFIELD_1, "GetFieldOffset", ves_icall_RuntimeFieldInfo_GetFieldOffset,
        gint32, 1, (MonoReflectionField))
HANDLES(MFIELD_2, "GetParentType", ves_icall_RuntimeFieldInfo_GetParentType,
        MonoReflectionType, 2, (MonoReflectionField, MonoBoolean))
HANDLES(MFIELD_3, "GetRawConstantValue",
        ves_icall_RuntimeFieldInfo_GetRawConstantValue, MonoObject, 1,
        (MonoReflectionField))
HANDLES(MFIELD_4, "GetTypeModifiers",
        ves_icall_System_Reflection_FieldInfo_GetTypeModifiers, MonoArray, 2,
        (MonoReflectionField, MonoBoolean))
HANDLES(MFIELD_5, "GetValueInternal",
        ves_icall_RuntimeFieldInfo_GetValueInternal, MonoObject, 2,
        (MonoReflectionField, MonoObject))
HANDLES(MFIELD_6, "ResolveType", ves_icall_RuntimeFieldInfo_ResolveType,
        MonoReflectionType, 1, (MonoReflectionField))
HANDLES(MFIELD_7, "SetValueInternal",
        ves_icall_RuntimeFieldInfo_SetValueInternal, void, 3,
        (MonoReflectionField, MonoObject, MonoObject))
HANDLES_REUSE_WRAPPER(MFIELD_8, "UnsafeGetValue",
                      ves_icall_RuntimeFieldInfo_GetValueInternal)
HANDLES(MFIELD_9, "get_core_clr_security_level",
        ves_icall_RuntimeFieldInfo_get_core_clr_security_level, int, 1,
        (MonoReflectionField))
HANDLES_REUSE_WRAPPER(MFIELD_10, "get_metadata_token",
                      ves_icall_reflection_get_token)

ICALL_TYPE(RMETHODINFO, "System.Reflection.RuntimeMethodInfo", RMETHODINFO_1)
HANDLES(RMETHODINFO_1, "GetGenericArguments",
        ves_icall_RuntimeMethodInfo_GetGenericArguments, MonoArray, 1,
        (MonoReflectionMethod))
HANDLES_REUSE_WRAPPER(RMETHODINFO_2, "GetGenericMethodDefinition_impl",
                      ves_icall_RuntimeMethodInfo_GetGenericMethodDefinition)
HANDLES(RMETHODINFO_3, "GetMethodBodyInternal",
        ves_icall_System_Reflection_RuntimeMethodInfo_GetMethodBodyInternal,
        MonoReflectionMethodBody, 1, (MonoMethod_ptr))
HANDLES(
    RMETHODINFO_4, "GetMethodFromHandleInternalType_native",
    ves_icall_System_Reflection_RuntimeMethodInfo_GetMethodFromHandleInternalType_native,
    MonoReflectionMethod, 3, (MonoMethod_ptr, MonoType_ptr, MonoBoolean))
HANDLES(RMETHODINFO_5, "GetPInvoke", ves_icall_RuntimeMethodInfo_GetPInvoke,
        void, 4, (MonoReflectionMethod, int_ref, MonoStringOut, MonoStringOut))
HANDLES_REUSE_WRAPPER(RMETHODINFO_6, "InternalInvoke", ves_icall_InternalInvoke)
HANDLES(RMETHODINFO_7, "MakeGenericMethod_impl",
        ves_icall_RuntimeMethodInfo_MakeGenericMethod_impl,
        MonoReflectionMethod, 2, (MonoReflectionMethod, MonoArray))
HANDLES(RMETHODINFO_8, "get_IsGenericMethod",
        ves_icall_RuntimeMethodInfo_get_IsGenericMethod, MonoBoolean, 1,
        (MonoReflectionMethod))
HANDLES(RMETHODINFO_9, "get_IsGenericMethodDefinition",
        ves_icall_RuntimeMethodInfo_get_IsGenericMethodDefinition, MonoBoolean,
        1, (MonoReflectionMethod))
HANDLES(RMETHODINFO_10, "get_base_method",
        ves_icall_RuntimeMethodInfo_get_base_method, MonoReflectionMethod, 2,
        (MonoReflectionMethod, MonoBoolean))
HANDLES_REUSE_WRAPPER(RMETHODINFO_11, "get_core_clr_security_level",
                      ves_icall_RuntimeMethodInfo_get_core_clr_security_level)
HANDLES_REUSE_WRAPPER(RMETHODINFO_12, "get_metadata_token",
                      ves_icall_reflection_get_token)
HANDLES(RMETHODINFO_13, "get_name", ves_icall_RuntimeMethodInfo_get_name,
        MonoString, 1, (MonoReflectionMethod))

ICALL_TYPE(MODULE, "System.Reflection.RuntimeModule", MODULE_2)
HANDLES(MODULE_2, "GetGlobalType",
        ves_icall_System_Reflection_RuntimeModule_GetGlobalType,
        MonoReflectionType, 1, (MonoImage_ptr))
HANDLES(MODULE_3, "GetGuidInternal",
        ves_icall_System_Reflection_RuntimeModule_GetGuidInternal, void, 2,
        (MonoImage_ptr, MonoArray))
HANDLES(MODULE_14, "GetHINSTANCE",
        ves_icall_System_Reflection_RuntimeModule_GetHINSTANCE, gpointer, 1,
        (MonoImage_ptr))
HANDLES(MODULE_4, "GetMDStreamVersion",
        ves_icall_System_Reflection_RuntimeModule_GetMDStreamVersion, gint32, 1,
        (MonoImage_ptr))
HANDLES(MODULE_5, "GetPEKind",
        ves_icall_System_Reflection_RuntimeModule_GetPEKind, void, 3,
        (MonoImage_ptr, gint32_ptr, gint32_ptr))
HANDLES(MODULE_6, "InternalGetTypes",
        ves_icall_System_Reflection_RuntimeModule_InternalGetTypes, MonoArray,
        1, (MonoImage_ptr))
HANDLES(MODULE_7, "ResolveFieldToken",
        ves_icall_System_Reflection_RuntimeModule_ResolveFieldToken,
        MonoClassField_ptr, 5,
        (MonoImage_ptr, guint32, MonoArray, MonoArray,
         MonoResolveTokenError_ref))
HANDLES(MODULE_8, "ResolveMemberToken",
        ves_icall_System_Reflection_RuntimeModule_ResolveMemberToken,
        MonoObject, 5,
        (MonoImage_ptr, guint32, MonoArray, MonoArray,
         MonoResolveTokenError_ref))
HANDLES(MODULE_9, "ResolveMethodToken",
        ves_icall_System_Reflection_RuntimeModule_ResolveMethodToken,
        MonoMethod_ptr, 5,
        (MonoImage_ptr, guint32, MonoArray, MonoArray,
         MonoResolveTokenError_ref))
HANDLES(MODULE_10, "ResolveSignature",
        ves_icall_System_Reflection_RuntimeModule_ResolveSignature, MonoArray,
        3, (MonoImage_ptr, guint32, MonoResolveTokenError_ref))
HANDLES(MODULE_11, "ResolveStringToken",
        ves_icall_System_Reflection_RuntimeModule_ResolveStringToken,
        MonoString, 3, (MonoImage_ptr, guint32, MonoResolveTokenError_ref))
HANDLES(MODULE_12, "ResolveTypeToken",
        ves_icall_System_Reflection_RuntimeModule_ResolveTypeToken,
        MonoType_ptr, 5,
        (MonoImage_ptr, guint32, MonoArray, MonoArray,
         MonoResolveTokenError_ref))
HANDLES(MODULE_13, "get_MetadataToken", ves_icall_reflection_get_token, guint32,
        1, (MonoObject))

ICALL_TYPE(PARAMI, "System.Reflection.RuntimeParameterInfo", MPARAMI_1)
HANDLES_REUSE_WRAPPER(MPARAMI_1, "GetMetadataToken",
                      ves_icall_reflection_get_token)
HANDLES(MPARAMI_2, "GetTypeModifiers",
        ves_icall_RuntimeParameterInfo_GetTypeModifiers, MonoArray, 4,
        (MonoReflectionType, MonoObject, int, MonoBoolean))

ICALL_TYPE(MPROP, "System.Reflection.RuntimePropertyInfo", MPROP_1)
HANDLES(MPROP_1, "GetTypeModifiers",
        ves_icall_RuntimePropertyInfo_GetTypeModifiers, MonoArray, 2,
        (MonoReflectionProperty, MonoBoolean))
HANDLES(MPROP_2, "get_default_value", ves_icall_property_info_get_default_value,
        MonoObject, 1, (MonoReflectionProperty))
HANDLES_REUSE_WRAPPER(MPROP_3, "get_metadata_token",
                      ves_icall_reflection_get_token)
HANDLES(MPROP_4, "get_property_info",
        ves_icall_RuntimePropertyInfo_get_property_info, void, 3,
        (MonoReflectionProperty, MonoPropertyInfo_ref, PInfo))
HANDLES(
    MPROP_5, "internal_from_handle_type",
    ves_icall_System_Reflection_RuntimePropertyInfo_internal_from_handle_type,
    MonoReflectionProperty, 2, (MonoProperty_ptr, MonoType_ptr))

ICALL_TYPE(RUNH, "System.Runtime.CompilerServices.RuntimeHelpers", RUNH_1)
HANDLES(RUNH_1, "GetObjectValue",
        ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetObjectValue,
        MonoObject, 1, (MonoObject))
HANDLES(
    RUNH_2, "GetUninitializedObjectInternal",
    ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetUninitializedObjectInternal,
    MonoObject, 1, (MonoType_ptr))
HANDLES(
    RUNH_3, "InitializeArray",
    ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray,
    void, 2, (MonoArray, MonoClassField_ptr))
HANDLES(RUNH_7, "InternalGetHashCode", mono_object_hash_icall, int, 1,
        (MonoObject))
HANDLES(RUNH_3a, "PrepareMethod",
        ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_PrepareMethod,
        void, 3, (MonoMethod_ptr, gpointer, int))
HANDLES(
    RUNH_4, "RunClassConstructor",
    ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_RunClassConstructor,
    void, 1, (MonoType_ptr))
HANDLES(
    RUNH_5, "RunModuleConstructor",
    ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_RunModuleConstructor,
    void, 1, (MonoImage_ptr))
NOHANDLES(ICALL(
    RUNH_5h, "SufficientExecutionStack",
    ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_SufficientExecutionStack))
NOHANDLES(ICALL(
    RUNH_6, "get_OffsetToStringData",
    ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetOffsetToStringData))

ICALL_TYPE(GCH, "System.Runtime.InteropServices.GCHandle", GCH_1)
HANDLES(GCH_1, "InternalAlloc", ves_icall_System_GCHandle_InternalAlloc,
        gpointer, 2, (MonoObject, gint32))
HANDLES(GCH_2, "InternalFree", ves_icall_System_GCHandle_InternalFree, void, 1,
        (gpointer))
HANDLES(GCH_3, "InternalGet", ves_icall_System_GCHandle_InternalGet, MonoObject,
        1, (gpointer))
HANDLES(GCH_4, "InternalSet", ves_icall_System_GCHandle_InternalSet, void, 2,
        (gpointer, MonoObject))

ICALL_TYPE(MARSHAL, "System.Runtime.InteropServices.Marshal", MARSHAL_2)
HANDLES(MARSHAL_2, "AllocCoTaskMem",
        ves_icall_System_Runtime_InteropServices_Marshal_AllocCoTaskMem,
        gpointer, 1, (int))
HANDLES(MARSHAL_3, "AllocHGlobal",
        ves_icall_System_Runtime_InteropServices_Marshal_AllocHGlobal, gpointer,
        1, (gsize))
NOHANDLES(ICALL(MARSHAL_50, "BufferToBSTR",
                ves_icall_System_Runtime_InteropServices_Marshal_BufferToBSTR))
HANDLES(MARSHAL_4, "DestroyStructure",
        ves_icall_System_Runtime_InteropServices_Marshal_DestroyStructure, void,
        2, (gpointer, MonoReflectionType))
NOHANDLES(ICALL(MARSHAL_5, "FreeBSTR",
                ves_icall_System_Runtime_InteropServices_Marshal_FreeBSTR))
NOHANDLES(ICALL(MARSHAL_6, "FreeCoTaskMem",
                ves_icall_System_Runtime_InteropServices_Marshal_FreeCoTaskMem))
NOHANDLES(ICALL(MARSHAL_7, "FreeHGlobal",
                ves_icall_System_Runtime_InteropServices_Marshal_FreeHGlobal))
HANDLES(
    MARSHAL_9, "GetDelegateForFunctionPointerInternal",
    ves_icall_System_Runtime_InteropServices_Marshal_GetDelegateForFunctionPointerInternal,
    MonoDelegate, 2, (gpointer, MonoReflectionType))
HANDLES(
    MARSHAL_10, "GetFunctionPointerForDelegateInternal",
    ves_icall_System_Runtime_InteropServices_Marshal_GetFunctionPointerForDelegateInternal,
    gpointer, 1, (MonoDelegate))
NOHANDLES(
    ICALL(MARSHAL_11, "GetLastWin32Error",
          ves_icall_System_Runtime_InteropServices_Marshal_GetLastWin32Error))
HANDLES(MARSHAL_48a, "IsPinnableType",
        ves_icall_System_Runtime_InteropServices_Marshal_IsPinnableType,
        MonoBoolean, 1, (MonoReflectionType))
HANDLES(MARSHAL_12, "OffsetOf",
        ves_icall_System_Runtime_InteropServices_Marshal_OffsetOf, int, 2,
        (MonoReflectionType, MonoString))
HANDLES(MARSHAL_13, "PrelinkInternal",
        ves_icall_System_Runtime_InteropServices_Marshal_Prelink, void, 1,
        (MonoReflectionMethod))
HANDLES(MARSHAL_17, "PtrToStringBSTR",
        ves_icall_System_Runtime_InteropServices_Marshal_PtrToStringBSTR,
        MonoString, 1, (mono_bstr_const))
HANDLES(MARSHAL_20, "PtrToStructureInternal",
        ves_icall_System_Runtime_InteropServices_Marshal_PtrToStructureInternal,
        void, 3, (gconstpointer, MonoObject, MonoBoolean))
HANDLES(MARSHAL_43, "ReAllocCoTaskMem",
        ves_icall_System_Runtime_InteropServices_Marshal_ReAllocCoTaskMem,
        gpointer, 2, (gpointer, int))
HANDLES(MARSHAL_23, "ReAllocHGlobal",
        ves_icall_System_Runtime_InteropServices_Marshal_ReAllocHGlobal,
        gpointer, 2, (gpointer, gsize))
NOHANDLES(
    ICALL(MARSHAL_29a, "SetLastWin32Error",
          ves_icall_System_Runtime_InteropServices_Marshal_SetLastWin32Error))
HANDLES(MARSHAL_30, "SizeOf",
        ves_icall_System_Runtime_InteropServices_Marshal_SizeOf, guint32, 1,
        (MonoReflectionType))
HANDLES(MARSHAL_31, "SizeOfHelper",
        ves_icall_System_Runtime_InteropServices_Marshal_SizeOfHelper, guint32,
        2, (MonoReflectionType, MonoBoolean))
HANDLES(MARSHAL_34, "StructureToPtr",
        ves_icall_System_Runtime_InteropServices_Marshal_StructureToPtr, void,
        3, (MonoObject, gpointer, MonoBoolean))

ICALL_TYPE(NATIVEL, "System.Runtime.InteropServices.NativeLibrary", NATIVEL_1)
HANDLES(NATIVEL_1, "FreeLib",
        ves_icall_System_Runtime_InteropServices_NativeLibrary_FreeLib, void, 1,
        (gpointer))
HANDLES(NATIVEL_2, "GetSymbol",
        ves_icall_System_Runtime_InteropServices_NativeLibrary_GetSymbol,
        gpointer, 3, (gpointer, MonoString, MonoBoolean))
HANDLES(NATIVEL_3, "LoadByName",
        ves_icall_System_Runtime_InteropServices_NativeLibrary_LoadByName,
        gpointer, 5,
        (MonoString, MonoReflectionAssembly, MonoBoolean, guint32, MonoBoolean))
HANDLES(NATIVEL_4, "LoadFromPath",
        ves_icall_System_Runtime_InteropServices_NativeLibrary_LoadFromPath,
        gpointer, 2, (MonoString, MonoBoolean))

ICALL_TYPE(ALC, "System.Runtime.Loader.AssemblyLoadContext", ALC_5)
HANDLES(
    ALC_5, "GetLoadContextForAssembly",
    ves_icall_System_Runtime_Loader_AssemblyLoadContext_GetLoadContextForAssembly,
    gpointer, 1, (MonoReflectionAssembly))
HANDLES(
    ALC_4, "InternalGetLoadedAssemblies",
    ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalGetLoadedAssemblies,
    MonoArray, 0, ())
HANDLES(
    ALC_2, "InternalInitializeNativeALC",
    ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalInitializeNativeALC,
    gpointer, 3, (gpointer, MonoBoolean, MonoBoolean))
HANDLES(ALC_1, "InternalLoadFile",
        ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFile,
        MonoReflectionAssembly, 3,
        (gpointer, MonoString, MonoStackCrawlMark_ptr))
HANDLES(
    ALC_3, "InternalLoadFromStream",
    ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFromStream,
    MonoReflectionAssembly, 5, (gpointer, gpointer, gint32, gpointer, gint32))

ICALL_TYPE(RFH, "System.RuntimeFieldHandle", RFH_1)
HANDLES(RFH_1, "GetValueDirect",
        ves_icall_System_RuntimeFieldHandle_GetValueDirect, MonoObject, 4,
        (MonoReflectionField, MonoReflectionType, MonoTypedRef_ptr,
         MonoReflectionType))
HANDLES(RFH_1a, "SetValueDirect",
        ves_icall_System_RuntimeFieldHandle_SetValueDirect, void, 5,
        (MonoReflectionField, MonoReflectionType, MonoTypedRef_ptr, MonoObject,
         MonoReflectionType))
HANDLES_REUSE_WRAPPER(RFH_2, "SetValueInternal",
                      ves_icall_RuntimeFieldInfo_SetValueInternal)

ICALL_TYPE(MHAN, "System.RuntimeMethodHandle", MHAN_1)
HANDLES(MHAN_1, "GetFunctionPointer",
        ves_icall_RuntimeMethodHandle_GetFunctionPointer, gpointer, 1,
        (MonoMethod_ptr))

ICALL_TYPE(RT, "System.RuntimeType", RT_1)
HANDLES(RT_1, "CreateInstanceInternal",
        ves_icall_System_Activator_CreateInstanceInternal, MonoObject, 1,
        (MonoReflectionType))
HANDLES(RT_2, "GetConstructors_native",
        ves_icall_RuntimeType_GetConstructors_native, GPtrArray_ptr, 2,
        (MonoReflectionType, guint32))
HANDLES(RT_30, "GetCorrespondingInflatedConstructor",
        ves_icall_RuntimeType_GetCorrespondingInflatedMethod,
        MonoReflectionMethod, 2, (MonoReflectionType, MonoReflectionMethod))
HANDLES_REUSE_WRAPPER(RT_31, "GetCorrespondingInflatedMethod",
                      ves_icall_RuntimeType_GetCorrespondingInflatedMethod)
HANDLES(RT_3, "GetEvents_native", ves_icall_RuntimeType_GetEvents_native,
        GPtrArray_ptr, 3, (MonoReflectionType, char_ptr, guint32))
HANDLES(RT_5, "GetFields_native", ves_icall_RuntimeType_GetFields_native,
        GPtrArray_ptr, 4, (MonoReflectionType, char_ptr, guint32, guint32))
HANDLES(RT_6, "GetGenericArgumentsInternal",
        ves_icall_RuntimeType_GetGenericArguments, MonoArray, 2,
        (MonoReflectionType, MonoBoolean))
HANDLES(RT_9, "GetGenericParameterPosition",
        ves_icall_RuntimeType_GetGenericParameterPosition, gint32, 1,
        (MonoReflectionType))
HANDLES(RT_10, "GetInterfaceMapData", ves_icall_RuntimeType_GetInterfaceMapData,
        void, 4,
        (MonoReflectionType, MonoReflectionType, MonoArrayOut, MonoArrayOut))
HANDLES(RT_11, "GetInterfaces", ves_icall_RuntimeType_GetInterfaces, MonoArray,
        1, (MonoReflectionType))
HANDLES(RT_12, "GetMethodsByName_native",
        ves_icall_RuntimeType_GetMethodsByName_native, GPtrArray_ptr, 4,
        (MonoReflectionType, const_char_ptr, guint32, guint32))
HANDLES(RT_13, "GetNestedTypes_native",
        ves_icall_RuntimeType_GetNestedTypes_native, GPtrArray_ptr, 4,
        (MonoReflectionType, char_ptr, guint32, guint32))
HANDLES(RT_14, "GetPacking", ves_icall_RuntimeType_GetPacking, void, 3,
        (MonoReflectionType, guint32_ref, guint32_ref))
HANDLES(RT_15, "GetPropertiesByName_native",
        ves_icall_RuntimeType_GetPropertiesByName_native, GPtrArray_ptr, 4,
        (MonoReflectionType, char_ptr, guint32, guint32))
HANDLES(RT_17, "MakeGenericType", ves_icall_RuntimeType_MakeGenericType,
        MonoReflectionType, 2, (MonoReflectionType, MonoArray))
HANDLES(RT_18, "MakePointerType", ves_icall_RuntimeType_MakePointerType,
        MonoReflectionType, 1, (MonoReflectionType))
HANDLES(RT_19, "getFullName", ves_icall_System_RuntimeType_getFullName,
        MonoString, 3, (MonoReflectionType, MonoBoolean, MonoBoolean))
HANDLES(RT_21, "get_DeclaringMethod", ves_icall_RuntimeType_get_DeclaringMethod,
        MonoReflectionMethod, 1, (MonoReflectionType))
HANDLES(RT_22, "get_DeclaringType", ves_icall_RuntimeType_get_DeclaringType,
        MonoReflectionType, 1, (MonoReflectionType))
HANDLES(RT_23, "get_Name", ves_icall_RuntimeType_get_Name, MonoString, 1,
        (MonoReflectionType))
HANDLES(RT_24, "get_Namespace", ves_icall_RuntimeType_get_Namespace, MonoString,
        1, (MonoReflectionType))
HANDLES(RT_26, "make_array_type", ves_icall_RuntimeType_make_array_type,
        MonoReflectionType, 2, (MonoReflectionType, int))
HANDLES(RT_27, "make_byref_type", ves_icall_RuntimeType_make_byref_type,
        MonoReflectionType, 1, (MonoReflectionType))

ICALL_TYPE(RTH, "System.RuntimeTypeHandle", RTH_1)
HANDLES(RTH_1, "GetArrayRank", ves_icall_RuntimeTypeHandle_GetArrayRank, gint32,
        1, (MonoReflectionType))
HANDLES(RTH_2, "GetAssembly", ves_icall_RuntimeTypeHandle_GetAssembly,
        MonoReflectionAssembly, 1, (MonoReflectionType))
HANDLES(RTH_3, "GetAttributes", ves_icall_RuntimeTypeHandle_GetAttributes,
        guint32, 1, (MonoReflectionType))
HANDLES(RTH_4, "GetBaseType", ves_icall_RuntimeTypeHandle_GetBaseType,
        MonoReflectionType, 1, (MonoReflectionType))
HANDLES(RTH_4a, "GetCorElementType",
        ves_icall_RuntimeTypeHandle_GetCorElementType, guint32, 1,
        (MonoReflectionType))
HANDLES(RTH_5, "GetElementType", ves_icall_RuntimeTypeHandle_GetElementType,
        MonoReflectionType, 1, (MonoReflectionType))
HANDLES(RTH_19, "GetGenericParameterInfo",
        ves_icall_RuntimeTypeHandle_GetGenericParameterInfo,
        MonoGenericParamInfo_ptr, 1, (MonoReflectionType))
HANDLES(RTH_6, "GetGenericTypeDefinition_impl",
        ves_icall_RuntimeTypeHandle_GetGenericTypeDefinition_impl,
        MonoReflectionType, 1, (MonoReflectionType))
HANDLES_REUSE_WRAPPER(RTH_7, "GetMetadataToken", ves_icall_reflection_get_token)
HANDLES(RTH_8, "GetModule", ves_icall_RuntimeTypeHandle_GetModule,
        MonoReflectionModule, 1, (MonoReflectionType))
HANDLES(RTH_9, "HasInstantiation", ves_icall_RuntimeTypeHandle_HasInstantiation,
        MonoBoolean, 1, (MonoReflectionType))
HANDLES(RTH_20, "HasReferences", ves_icall_RuntimeTypeHandle_HasReferences,
        MonoBoolean, 1, (MonoReflectionType))
HANDLES(RTH_21, "IsByRefLike", ves_icall_RuntimeTypeHandle_IsByRefLike,
        MonoBoolean, 1, (MonoReflectionType))
HANDLES(RTH_12, "IsComObject", ves_icall_RuntimeTypeHandle_IsComObject,
        MonoBoolean, 1, (MonoReflectionType))
HANDLES(RTH_13, "IsGenericTypeDefinition",
        ves_icall_RuntimeTypeHandle_IsGenericTypeDefinition, MonoBoolean, 1,
        (MonoReflectionType))
HANDLES(RTH_14, "IsGenericVariable",
        ves_icall_RuntimeTypeHandle_IsGenericVariable, MonoBoolean, 1,
        (MonoReflectionType))
HANDLES(RTH_15, "IsInstanceOfType",
        ves_icall_RuntimeTypeHandle_IsInstanceOfType, guint32, 2,
        (MonoReflectionType, MonoObject))
// HANDLES(RTH_17a, "is_subclass_of",
// ves_icall_RuntimeTypeHandle_is_subclass_of, MonoBoolean, 2, (MonoType_ptr,
// MonoType_ptr))
HANDLES(RTH_17a, "internal_from_name",
        ves_icall_System_RuntimeTypeHandle_internal_from_name,
        MonoReflectionType, 6,
        (MonoString, MonoStackCrawlMark_ptr, MonoReflectionAssembly,
         MonoBoolean, MonoBoolean, MonoBoolean))
NOHANDLES(ICALL(RTH_17b, "is_subclass_of",
                ves_icall_RuntimeTypeHandle_is_subclass_of))
HANDLES(RTH_18, "type_is_assignable_from",
        ves_icall_RuntimeTypeHandle_type_is_assignable_from, guint32, 2,
        (MonoReflectionType, MonoReflectionType))

ICALL_TYPE(STRING, "System.String", STRING_1)
NOHANDLES(ICALL(STRING_1, ".ctor(System.ReadOnlySpan`1<char>)",
                ves_icall_System_String_ctor_RedirectToCreateString))
NOHANDLES(ICALL(STRING_1a, ".ctor(char*)",
                ves_icall_System_String_ctor_RedirectToCreateString))
NOHANDLES(ICALL(STRING_2, ".ctor(char*,int,int)",
                ves_icall_System_String_ctor_RedirectToCreateString))
NOHANDLES(ICALL(STRING_3, ".ctor(char,int)",
                ves_icall_System_String_ctor_RedirectToCreateString))
NOHANDLES(ICALL(STRING_4, ".ctor(char[])",
                ves_icall_System_String_ctor_RedirectToCreateString))
NOHANDLES(ICALL(STRING_5, ".ctor(char[],int,int)",
                ves_icall_System_String_ctor_RedirectToCreateString))
NOHANDLES(ICALL(STRING_6, ".ctor(sbyte*)",
                ves_icall_System_String_ctor_RedirectToCreateString))
NOHANDLES(ICALL(STRING_7, ".ctor(sbyte*,int,int)",
                ves_icall_System_String_ctor_RedirectToCreateString))
NOHANDLES(ICALL(STRING_8, ".ctor(sbyte*,int,int,System.Text.Encoding)",
                ves_icall_System_String_ctor_RedirectToCreateString))
HANDLES(STRING_9, "FastAllocateString",
        ves_icall_System_String_FastAllocateString, MonoString, 1, (gint32))
HANDLES(STRING_10, "InternalIntern", ves_icall_System_String_InternalIntern,
        MonoString, 1, (MonoString))
HANDLES(STRING_11, "InternalIsInterned",
        ves_icall_System_String_InternalIsInterned, MonoString, 1, (MonoString))

ICALL_TYPE(NATIVEC, "System.Threading.EventWaitHandle", EWH_1) // && Unix
HANDLES(EWH_1, "CreateEventInternal",
        ves_icall_System_Threading_Events_CreateEvent_icall, gpointer, 5,
        (MonoBoolean, MonoBoolean, const_gunichar2_ptr, gint32, gint32_ref))
NOHANDLES(ICALL(EWH_2, "ResetEventInternal",
                ves_icall_System_Threading_Events_ResetEvent_internal))
NOHANDLES(ICALL(EWH_3, "SetEventInternal",
                ves_icall_System_Threading_Events_SetEvent_internal))

ICALL_TYPE(ILOCK, "System.Threading.Interlocked", ILOCK_1)
NOHANDLES(ICALL(ILOCK_1, "Add(int&,int)",
                ves_icall_System_Threading_Interlocked_Add_Int))
NOHANDLES(ICALL(ILOCK_2, "Add(long&,long)",
                ves_icall_System_Threading_Interlocked_Add_Long))
NOHANDLES(ICALL(ILOCK_4, "CompareExchange(double&,double,double)",
                ves_icall_System_Threading_Interlocked_CompareExchange_Double))
NOHANDLES(ICALL(ILOCK_5, "CompareExchange(int&,int,int)",
                ves_icall_System_Threading_Interlocked_CompareExchange_Int))
NOHANDLES(
    ICALL(ILOCK_6, "CompareExchange(int&,int,int,bool&)",
          ves_icall_System_Threading_Interlocked_CompareExchange_Int_Success))
NOHANDLES(ICALL(ILOCK_7, "CompareExchange(intptr&,intptr,intptr)",
                ves_icall_System_Threading_Interlocked_CompareExchange_IntPtr))
NOHANDLES(ICALL(ILOCK_8, "CompareExchange(long&,long,long)",
                ves_icall_System_Threading_Interlocked_CompareExchange_Long))
NOHANDLES(ICALL(ILOCK_9, "CompareExchange(object&,object&,object&,object&)",
                ves_icall_System_Threading_Interlocked_CompareExchange_Object))
NOHANDLES(ICALL(ILOCK_10, "CompareExchange(single&,single,single)",
                ves_icall_System_Threading_Interlocked_CompareExchange_Single))
NOHANDLES(ICALL(ILOCK_11, "Decrement(int&)",
                ves_icall_System_Threading_Interlocked_Decrement_Int))
NOHANDLES(ICALL(ILOCK_12, "Decrement(long&)",
                ves_icall_System_Threading_Interlocked_Decrement_Long))
NOHANDLES(ICALL(ILOCK_14, "Exchange(double&,double)",
                ves_icall_System_Threading_Interlocked_Exchange_Double))
NOHANDLES(ICALL(ILOCK_15, "Exchange(int&,int)",
                ves_icall_System_Threading_Interlocked_Exchange_Int))
NOHANDLES(ICALL(ILOCK_16, "Exchange(intptr&,intptr)",
                ves_icall_System_Threading_Interlocked_Exchange_IntPtr))
NOHANDLES(ICALL(ILOCK_17, "Exchange(long&,long)",
                ves_icall_System_Threading_Interlocked_Exchange_Long))
NOHANDLES(ICALL(ILOCK_18, "Exchange(object&,object&,object&)",
                ves_icall_System_Threading_Interlocked_Exchange_Object))
NOHANDLES(ICALL(ILOCK_19, "Exchange(single&,single)",
                ves_icall_System_Threading_Interlocked_Exchange_Single))
NOHANDLES(ICALL(ILOCK_20, "Increment(int&)",
                ves_icall_System_Threading_Interlocked_Increment_Int))
NOHANDLES(ICALL(ILOCK_21, "Increment(long&)",
                ves_icall_System_Threading_Interlocked_Increment_Long))
NOHANDLES(
    ICALL(ILOCK_22, "MemoryBarrierProcessWide",
          ves_icall_System_Threading_Interlocked_MemoryBarrierProcessWide))
NOHANDLES(ICALL(ILOCK_23, "Read(long&)",
                ves_icall_System_Threading_Interlocked_Read_Long))

ICALL_TYPE(MONIT, "System.Threading.Monitor", MONIT_0)
HANDLES(MONIT_0, "Enter", ves_icall_System_Threading_Monitor_Monitor_Enter,
        void, 1, (MonoObject))
HANDLES(MONIT_1, "Exit", mono_monitor_exit_icall, void, 1, (MonoObject))
HANDLES(MONIT_2, "Monitor_pulse",
        ves_icall_System_Threading_Monitor_Monitor_pulse, void, 1, (MonoObject))
HANDLES(MONIT_3, "Monitor_pulse_all",
        ves_icall_System_Threading_Monitor_Monitor_pulse_all, void, 1,
        (MonoObject))
HANDLES(MONIT_4, "Monitor_test_owner",
        ves_icall_System_Threading_Monitor_Monitor_test_owner, MonoBoolean, 1,
        (MonoObject))
HANDLES(MONIT_5, "Monitor_test_synchronised",
        ves_icall_System_Threading_Monitor_Monitor_test_synchronised,
        MonoBoolean, 1, (MonoObject))
HANDLES(MONIT_7, "Monitor_wait",
        ves_icall_System_Threading_Monitor_Monitor_wait, MonoBoolean, 3,
        (MonoObject, guint32, MonoBoolean))
NOHANDLES(ICALL(MONIT_8, "get_LockContentionCount",
                ves_icall_System_Threading_Monitor_Monitor_LockContentionCount))
HANDLES(MONIT_9, "try_enter_with_atomic_var",
        ves_icall_System_Threading_Monitor_Monitor_try_enter_with_atomic_var,
        void, 4, (MonoObject, guint32, MonoBoolean, MonoBoolean_ref))

ICALL_TYPE(MUTEX, "System.Threading.Mutex", MUTEX_1)
HANDLES(MUTEX_1, "CreateMutex_icall",
        ves_icall_System_Threading_Mutex_CreateMutex_icall, gpointer, 4,
        (MonoBoolean, const_gunichar2_ptr, gint32, MonoBoolean_ref))
HANDLES(MUTEX_2, "OpenMutex_icall",
        ves_icall_System_Threading_Mutex_OpenMutex_icall, gpointer, 4,
        (const_gunichar2_ptr, gint32, gint32, gint32_ref))
NOHANDLES(ICALL(MUTEX_3, "ReleaseMutex_internal",
                ves_icall_System_Threading_Mutex_ReleaseMutex_internal))

ICALL_TYPE(SEMA, "System.Threading.Semaphore", SEMA_1)
HANDLES(SEMA_1, "CreateSemaphore_icall",
        ves_icall_System_Threading_Semaphore_CreateSemaphore_icall, gpointer, 5,
        (gint32, gint32, const_gunichar2_ptr, gint32, gint32_ptr))
HANDLES(SEMA_2, "OpenSemaphore_icall",
        ves_icall_System_Threading_Semaphore_OpenSemaphore_icall, gpointer, 4,
        (const_gunichar2_ptr, gint32, gint32, gint32_ptr))
HANDLES(SEMA_3, "ReleaseSemaphore_internal",
        ves_icall_System_Threading_Semaphore_ReleaseSemaphore_internal,
        MonoBoolean, 3, (gpointer, gint32, gint32_ref))

ICALL_TYPE(THREAD, "System.Threading.Thread", THREAD_1)
HANDLES(THREAD_1, "ClrState", ves_icall_System_Threading_Thread_ClrState, void,
        2, (MonoInternalThread, guint32))
HANDLES(ITHREAD_2, "FreeInternal",
        ves_icall_System_Threading_InternalThread_Thread_free_internal, void, 1,
        (MonoInternalThread))
HANDLES(THREAD_15, "GetCurrentOSThreadId",
        ves_icall_System_Threading_Thread_GetCurrentOSThreadId, guint64, 0, ())
HANDLES(THREAD_3, "GetState", ves_icall_System_Threading_Thread_GetState,
        guint32, 1, (MonoInternalThread))
HANDLES(THREAD_4, "InitInternal",
        ves_icall_System_Threading_Thread_InitInternal, void, 1,
        (MonoThreadObject))
HANDLES(THREAD_5, "InitializeCurrentThread",
        ves_icall_System_Threading_Thread_GetCurrentThread, MonoThreadObject, 0,
        ())
HANDLES(THREAD_6, "InterruptInternal",
        ves_icall_System_Threading_Thread_Interrupt_internal, void, 1,
        (MonoThreadObject))
HANDLES(THREAD_7, "JoinInternal",
        ves_icall_System_Threading_Thread_Join_internal, MonoBoolean, 2,
        (MonoThreadObject, int))
HANDLES(THREAD_8, "SetName_icall",
        ves_icall_System_Threading_Thread_SetName_icall, void, 3,
        (MonoInternalThread, const_gunichar2_ptr, gint32))
HANDLES(THREAD_9, "SetPriority", ves_icall_System_Threading_Thread_SetPriority,
        void, 2, (MonoThreadObject, int))
HANDLES(THREAD_10, "SetState", ves_icall_System_Threading_Thread_SetState, void,
        2, (MonoInternalThread, guint32))
HANDLES(THREAD_11, "SleepInternal",
        ves_icall_System_Threading_Thread_Sleep_internal, void, 2,
        (gint32, MonoBoolean))
HANDLES(THREAD_12, "SpinWait_nop",
        ves_icall_System_Threading_Thread_SpinWait_nop, void, 0, ())
HANDLES(THREAD_13, "StartInternal",
        ves_icall_System_Threading_Thread_StartInternal, void, 1,
        (MonoThreadObject))
NOHANDLES(ICALL(THREAD_14, "YieldInternal",
                ves_icall_System_Threading_Thread_YieldInternal))

ICALL_TYPE(WAITH, "System.Threading.WaitHandle", WAITH_1)
HANDLES(WAITH_1, "SignalAndWait_Internal",
        ves_icall_System_Threading_WaitHandle_SignalAndWait_Internal, gint32, 3,
        (gpointer, gpointer, gint32))
HANDLES(WAITH_2, "Wait_internal",
        ves_icall_System_Threading_WaitHandle_Wait_internal, gint32, 4,
        (gpointer_ptr, gint32, MonoBoolean, gint32))

ICALL_TYPE(TYPE, "System.Type", TYPE_1)
HANDLES(TYPE_1, "internal_from_handle",
        ves_icall_System_Type_internal_from_handle, MonoReflectionType, 1,
        (MonoType_ref))

ICALL_TYPE(TYPEDR, "System.TypedReference", TYPEDR_1)
HANDLES(TYPEDR_1, "InternalMakeTypedReference",
        ves_icall_System_TypedReference_InternalMakeTypedReference, void, 4,
        (MonoTypedRef_ptr, MonoObject, MonoArray, MonoReflectionType))
HANDLES(TYPEDR_2, "InternalToObject", ves_icall_System_TypedReference_ToObject,
        MonoObject, 1, (MonoTypedRef_ptr))

ICALL_TYPE(VALUET, "System.ValueType", VALUET_1)
HANDLES(VALUET_1, "InternalEquals", ves_icall_System_ValueType_Equals,
        MonoBoolean, 3, (MonoObject, MonoObject, MonoArrayOut))
HANDLES(VALUET_2, "InternalGetHashCode",
        ves_icall_System_ValueType_InternalGetHashCode, gint32, 2,
        (MonoObject, MonoArrayOut))
