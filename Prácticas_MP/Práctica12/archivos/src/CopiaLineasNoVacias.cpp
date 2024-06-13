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
// estándar y muestra en la salida estándar únicamente las líneas no 
// vacías que hay en esa secuencia.
//
// Procesamiento a nivel de LINEA 
//
// Fichero: CopiaLineasNoVacias.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	const int TAM = 256;	// Máxima longitud de la cadena empleada
	char cad[TAM];			// para leer cada línea

	cin.getline(cad, TAM);	// Lectura adelantada de una cadena

	while (!cin.eof()) {

		if (strlen(cad) > 0) {	// Si la longitud es mayor que cero, 
			cout << cad;	    // no está vacía: enviarla a cout
			cout << endl;  
		}
		
		cin.getline(cad, TAM);		// Nueva lectura
	}
   
	return (0);
}

/***************************************************************************/
/***************************************************************************/
