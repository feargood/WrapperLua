/**
* Autor: Torsten Buchholz
* Company: Hochschule Offenburg
* Project: Scripting mit Lua
*
**/

#pragma once


using namespace System;

namespace WrapperLua{


	public ref class Lua{

	private:
		/**
		* Klassenmember
		**/
		lua_State * state;

		/**
		* Luafunktionen
		**/
		void close();


		/**
		* Hilfsmethoden
		**/
		const char* stringTopChar(System::String^);

	public:
		
		/**
		* Konstruktor & Destruktor
		**/
		Lua();
		~Lua();

		/**
		* Luafunktionen
		**/
		void loadDefaultLibs();
		
		bool dofile(System::String^);

		bool dostring(System::String^);

		
	};

}



