/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
//
// Programa que lee una serie indefinida de números enteros de la entrada
// estándar y los copia, en el mismo orden, en la salida estándar.
//	 *	En la secuencia de entrada se pueden usar espacios, tabuladores o
//		saltos de líneas (en cualquier número y combinación) para separar
//		dos números enteros consecutivos.
//	 *	En la secuencia de salida se separan dos enteros consecutivos con
//		un salto de línea.
//
// Fichero: CopiaEnteros.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	int n;

	while (cin >> n)  
		cout << setw(10) << n << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
