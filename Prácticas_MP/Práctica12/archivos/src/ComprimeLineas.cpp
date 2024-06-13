/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
//
// Programa que lee una secuencia indefinida de caracteres de la entrada 
// estándar y "comprime" todas las líneas de esa secuencia, eliminando 
// los separadores que hay en cada línea, exceptuando el '\n'. 
//
// Procesamiento a nivel de CARACTER 
//
// Fichero: ComprimeLineas.cpp
//
/***************************************************************************/

#include <iostream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	char c;

	c = cin.get();	// lectura adelantada

	while (!cin.eof()) {

		// Si el carácter no es un separador, escribirlo. 
		// Excepción: el carácter '\n' también se escribe

		if (c!=' ' && c!='\t' && c!='\v' && c!='\f' && c!='\r') 
			cout << c;					
				
		c = cin.get();	// lectura adelantada

	} // while (!cin.eof()) 

	return (0);
}

/***************************************************************************/
/***************************************************************************/
