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
// y muestra en la salida estándar el número total de caracteres leidos.
//
// Procesamiento a nivel de CARACTER 
//
// Fichero: CuentaCaracteres.cpp
//
/***************************************************************************/

#include <iostream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	char c;
	int contador = 0;

	c = cin.get();

	while (!cin.eof()) {
		contador++;
		c = cin.get();
	}

	cout << "Caracteres leidos= " << contador << endl; 

	return 0;
}

/***************************************************************************/
/***************************************************************************/
