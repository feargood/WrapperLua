/**
* Include Section
**/
#include "stdafx.h"		//Projekt include
#include "WrapperLua.h"	//Header

/**
* Autor: Torsten Buchholz
* Company: Hochschule Offenburg
* Project: Scripting mit Lua
*
**/

using namespace System;
using namespace System::Runtime::InteropServices;

namespace WrapperLua{

	/**
	* Leerer Konstruktor um automatisch alle Standardbibliotheken zu laden.
	**/
	Lua::Lua()
	{
		this->state = luaL_newstate();
		this->loadDefaultLibs();
	};

	/**
	* Destuktor
	**/
	Lua::~Lua()
	{
		this->close();
	}

	/**
	* Zerst�rt den erzeugten Lua-State
	**/
	void Lua::close()
	{
		lua_close(this->state);
	}

	/**
	* �bergabe: Ein Dateiname zu einem Lua Script
	* R�ckgabe:	Boolean (Lua liefert nil bei Fehler)
	*
	* Der �bergebene Dateiname wird in ein const Char pointer gewandelt und an Lua weitergeleitet.
	**/
	bool Lua::dofile(System::String^ filename)
	{
		return luaL_dofile(this->state, this->stringTopChar(filename));
	}

	/**
	* �bergabe: Ein String mit Lua Script
	* R�ckgabe:	Boolean (Lua liefert nil bei Fehler)
	*
	* Der �bergebene String wird in ein const Char pointer gewandelt und an Lua weitergeleitet.
	**/
	bool Lua::dostring(System::String^ luastring)
	{
		return luaL_dostring(this->state,this->stringTopChar(luastring));
	}

	/**
	* L�d alle Standardbibliotheken
	**/
	void Lua::loadDefaultLibs()
	{
		luaL_openlibs(this->state);
	}

	/**
	* Wandelt einen String in einen const Char pointer (const Char*) um
	**/
	const char* Lua::stringTopChar(System::String^ string)
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(string);
		return static_cast<char*>(p.ToPointer());
	}
}