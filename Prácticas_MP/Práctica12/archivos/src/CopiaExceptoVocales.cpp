/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
//
// Lee una secuencia indefinida de caracteres de la entrada estándar
// y los copia en la salida estándar, exceptuando las vocales.
//
// Procesamiento a nivel de CARACTER 
//
// Fichero: CopiaExceptoVocales.cpp
//
/***************************************************************************/

#include <iostream>
//#include <string>
#include <cstring>
#include <cctype>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	char c;

	// Version simple:

	c = cin.get();	// Lectura adelantada

	while (!cin.eof()) {

		// Procesar el carácter leído 

		char c_may = toupper(c); // Convertir a mayúscula

		if ((c_may != 'A') && (c_may != 'E') && (c_may != 'I') && 
			(c_may != 'O') && (c_may != 'U')) 
			
			cout.put (c);

		c = cin.get(); 	// Lectura adelantada
	}

	/***********************************************************************/
	// Version con busqueda en string (debe descomentar #include <string>)
	/*

	string tabu = "AEIOU";

	c = cin.get();	// Lectura adelantada

	while (!cin.eof()) {

		// Procesar el carácter leído 

		int pos = tabu.find(toupper(c)); // Buscar en el string "tabu"

		// Si está en la cadena (0<=pos<tabu.length()), no se mostrará
		
		bool esta_en_tabu = ((pos >= 0) && (pos < tabu.length()));

		if (!esta_en_tabu) cout.put (c);

		// Alternativamente (preferible): 
		// if (tabu.find(toupper(c)) == string::npos) // "c" no está en "tabu" 
		//    cout.put (c);

		c = cin.get(); // Lectura adelantada
	}
	*/
	
	/***********************************************************************/
	/*
	// Version con busqueda en cadena clásica:

	const char * tabu = "AEIOU";

	c = cin.get();	// Lectura adelantada

	while (!cin.eof()) {

		// Procesar el carácter leído

		char * pos = strchr (tabu, toupper(c)); // Buscar en el string "tabu"

		// Si está en la cadena, no se mostrará.
		// Si no está (pos == 0), mostrarlo.

		if (pos == 0) cout.put (c);

		c = cin.get(); // Lectura adelantada
	}
	*/

	return 0;
}

/***************************************************************************/
/***************************************************************************/
