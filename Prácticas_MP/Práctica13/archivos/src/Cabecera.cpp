/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
//
// Programa que muestra las primeras l�neas de un fichero de texto.
//
// Uso: Cabecera <NumLineas> [<Fich>]
//			<NumLineas>	N�mero de l�neas (m�ximo) que se muestran.
//			<Fich>		Fichero del que se van a mostrar las l�neas. 
//						Es opcional: si no se indica ning�n fichero 
//						se toman los datos de cin.
// 
// Por ejemplo, la ejecuci�n de:
//		Cabecera 15 datos.txt
//
// mostrar� las primeras 15 l�neas del fichero "datos.txt".
// Si el fichero tiene menos de 15 l�neas, se mostrar�n todas. 
//
// Las restricciones que se impon�an a este programa son:
//	1)	El n�mero de ficheros que se pueden proporcionar es ilimitado.
//	1)	Cada uno de los ficheros s�lo puede ser le�do una �nica vez, y 
//		no pueden copiarse completo en memoria. 
//	2)	Se desconoce a priori el n�mero de l�neas del fichero. 
//	3)	Las l�neas del fichero tiene una longitud indeterminada, aunque 
//		nunca mayor de 500. 
//
// Fichero: Cabecera.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "Utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

void Head  (istream & in, const int);

/***************************************************************************/
/***************************************************************************/


int main (int argc, char **argv)
{

	// Comprobar numero y validez de argumentos  

	if ((argc < 2) || (argc > 3)) {
		cerr << "Error: Num. de params. erroneo\n";
		cerr << "Uso: " << argv[0]<< " <num_lineas> [<fich>]\n\n";
		exit (1);
	}

	int num_lineas = atoi (argv[1]);
	if (num_lineas < 0) {
		cerr << "Error: El num. de lineas no puede ser negativo.\n";
		cerr << "		(valor proporcionado = " << argv[1] << endl; 
		exit (2);
	}

	if (argc == 2) {
		Head (cin, num_lineas);
	}
	else {

		// Comprobar si existe/puede abrirse el fichero 

		if (!ExisteFichero(argv[2])) {
			cerr << "\nError: no puedo abrir " << argv[2] << "\n\n";
			exit (3);
		}

		ifstream f (argv[2]);

		Head (f, num_lineas);

		f.close();
	}

	return 0;
}

/***************************************************************************/
/***************************************************************************/
// Muestra las primeras "num_lineas" del flujo "in"

void Head (istream & in, const int num_lineas)
{

	const int MAX = 500;
	char cad[MAX];		// Para leer cada una de las lineas

	int num_linea = 0;	// Contador de l�neas mostradas


	in.getline (cad, MAX); // Lectura adelantada

	while (!(in.eof()) && (num_linea < num_lineas)) {

		cout << cad << endl;

		num_linea++;	

		in.getline (cad, MAX); // Lectura de una nueva linea
	}

}

/***************************************************************************/
/***************************************************************************/
