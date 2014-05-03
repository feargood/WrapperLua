/**
* Autor: Torsten Buchholz
* Company: Hochschule Offenburg
* Project: Scripting mit Lua
*
**/

#include "stdafx.h"

using namespace System;
using namespace std;
using namespace WrapperLua;

int _tmain(int argc, _TCHAR* argv[])
{

	Lua lua;
	lua.loadDefaultLibs();
	lua.dostring("a = 54 print (a)");
	lua.dostring("b = 213 + 34  print (b)");
	lua.dostring("a = 42 print (a)");

	system("pause");

	return 0;
}

