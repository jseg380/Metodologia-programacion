/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
//
// Programa que lee una secuencia indefinida de líneas de la entrada
// estándar y muestra el número de palabras por línea. 
// 
// Procesamiento a nivel de LINEA y gestion con flujos (BUENA DECISION) 
//
// Fichero: Cuenta_palabras_por_linea.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	int num_linea = 0; 

	string cad; 

	// Lectura adelantada
	getline (cin, cad);

	while (!cin.eof()) {
	
		num_linea++; 

		// Se asocia un flujo a cad

		istringstream flujo_cad (cad); 

		int num_palabras = 0; 
		string palabra;

		// Extraer y contar palabras

		while (flujo_cad >> palabra) 
			num_palabras++; 
		
		cout << "Linea " << setw(4) << num_linea << ": " 
		     << setw(4) << num_palabras << " palabras" << endl;

		// Lectura adelantada
		getline (cin, cad);

	} // while (!cin.eof());  
	

	return (0);
}

/***************************************************************************/
/***************************************************************************/
