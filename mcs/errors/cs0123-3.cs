// CS0123: The method `X.f1(int, object)' parameters do not match delegate `bool X.Function(int, int)' parameters
// Line: 13

using System;

class X
{
	public delegate bool Function(int arg1, int arg2);

	static void Main ()
	{
		Delegate [] d = new Delegate [] {
			new Function (f1),
		};
	}

	static bool f1 (int a, object b)
	{
		return false;
	}
}
