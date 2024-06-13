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
// estándar y muestra en la salida estándar precedidas del número de línea.
//
// Procesamiento a nivel de LINEA 
//
// Fichero: NumeraLineas.cpp
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

	int num_linea = 0; // Contador (num. de línea) 

	cin.getline(cad, TAM);	// Lectura adelantada de una cadena

	while (!cin.eof()) {

		num_linea++;

		cout << setw(5) << num_linea << " " << cad;	
		cout << endl;  
		
		cin.getline(cad, TAM);		// Nueva lectura
	}
   
	return 0;
}

/***************************************************************************/
/***************************************************************************/
