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
// Procesamiento a nivel de LINEA y gestion con flujos (BUENA DECISION) 
//
// Fichero: ComprimeLineas-ProcesamientoLineasFlujo.cpp
//
/***************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	string cad; 

	getline(cin, cad);	// Lectura adelantada de una cadena

	while (!cin.eof()) {

		//istringstream flujo_cad;	// Crear "flujo_cad"
		//flujo_cad.str (cad); // Asociar cad-->iss_cad

		istringstream flujo_cad (cad); 

		string palabra; 

		while (flujo_cad >> palabra) 
			cout << palabra; 

		cout << endl; 


		getline(cin, cad);		// Nueva lectura

	} // while (!cin.eof()) 

	return (0);
}

/***************************************************************************/
/***************************************************************************/
