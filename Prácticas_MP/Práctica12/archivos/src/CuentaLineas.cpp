/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// 
// Lee una secuencia indefinida de caracteres de la entrada estándar 
// y los copia en la salida estándar y muestra en la salida estándar 
// el número de líneas no vacías que hay en esa secuencia.
// Nota: Se entiende que una línea es vacía si contiene únicamente el 
// carácter '\n'
//
// Procesamiento a nivel de LINEA 
//
// Fichero: CuentaLineas.cpp
//
/***************************************************************************/

#include <iostream>
#include <string>

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	int contador_vacias = 0;
	int contador_no_vacias = 0;
	int contador_total = 0;

	string cad; 

	getline(cin, cad);	// Lectura adelantada de una cadena

	while (!cin.eof()) {

		contador_total++; 

		if (cad.length()>0) 
			contador_no_vacias ++; // Línea NO vacía
		else 
			contador_vacias++; // Línea vacía

		getline(cin, cad);	// Nueva lectura
	}

	cout << endl; 
	cout << "Lineas totales   = " << contador_total << endl; 
	cout << "Lineas vacias    = " << contador_vacias << endl; 
	cout << "Lineas no vacias = " << contador_no_vacias << endl; 
	cout << endl; 

	return 0;
}

/***************************************************************************/
/***************************************************************************/
