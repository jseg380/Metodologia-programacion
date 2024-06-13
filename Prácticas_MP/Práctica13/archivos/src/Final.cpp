/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
//
// Programa que muestra las �ltimas l�neas de un fichero de texto.
//
// Uso: Final <NumLineas> [<Fich>]
//			<NumLineas>	N�mero de l�neas (m�ximo) que se muestran.
//			<Fich>		Fichero del que se van a mostrar las l�neas. 
//						Es opcional: si no se indica ning�n fichero 
//						se toman los datos de cin.
//
// Por ejemplo, la ejecuci�n de: 
//		final 15 datos.txt
//
// mostrar� las �ltimas 15 l�neas del fichero "datos.txt". 
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
// Fichero: Final.cpp
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

void Tail  (istream & in, const int);

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	// Comprobar n�mero y validez de argumentos  

	if ((argc < 2) || (argc > 3)) {
		cerr << "Error: Num. de params. erroneo\n";
		cerr << "Uso: " << argv[0]<< " <num_lineas> [<fich>]\n\n";
		exit (1);
	}

	int num_lineas_mostrar = atoi (argv[1]);
	if (num_lineas_mostrar <= 0) {
		cerr << "Error: El n�mero de lineas debe ser >=0\n";
		exit (2);
	}

	if (argc == 2) {
		Tail (cin, num_lineas_mostrar);
	}
	else {

		// Comprobar si existe/puede abrirse el fichero 

		if (!ExisteFichero(argv[2])) {
			cerr << "\nError: no puedo abrir " << argv[2] << "\n\n";
			exit (3);
		}

		ifstream f (argv[2]);

		Tail (f, num_lineas_mostrar);

		f.close();
	}

	return (0);
}

/***************************************************************************/
/***************************************************************************/
// Construye un estructura de datos que guarda las �ltimas 
// "num_lineas_mostrar" le�das del flujo "in". 
// Finalmente llama a la funci�n "PintaLineas()" para mostrarlas.  

void Tail (istream & in, const int num_lineas_mostrar)
{
	const int MAX = 500;
	char cad[MAX];		// Para leer cada una de las lineas

	// Declaracion y reserva de la estructura de datos que va a guardar las 
	// �ltimas l�neas le�das. Se reserva y libera espacio para cada linea 
	// en el momento de su lectura y registro

	char ** ultimas = new char * [num_lineas_mostrar]; // vector de char *

	int primera, ultima;	// indices de la primera y ultima linea 
							// de las guardadas en "ultimas" 

	// Lectura de las primeras "num_lineas_mostrar" lineas

	int num_linea = 0;		// Numero de linea
	primera = ultima = 0;	// Iniciaci�n de �ndices

	in.getline (cad, MAX); // Lectura adelantada

	while (!(in.eof()) && (num_linea < num_lineas_mostrar)) {

		ultimas[num_linea] = new char[strlen(cad) + 1];
		strcpy (ultimas[num_linea], cad);

		ultima = num_linea;
		num_linea++;	

		in.getline (cad, MAX); // Lectura de una nueva linea
	}


	// Se han leido un m�ximo de "num_lineas" l�meas. 
	//	*	Si en "in" hubieran menos l�neas, in.eof() ser�a TRUE.
	//  *	Si hubieran m�s l�neas, la �ltima lectura tuvo �xito y 
	//		esa l�nea debe pasar a ser la �ltima y la primera debe 
	///		descartarse (la segunda ocupa su lugar). A continuaci�n se 
	//		lee otra l�nea, y se sigue hasta agotar el flujo "in"

	while (!(in.eof())) {

		// Se ha podido leer una nueva linea (cad) que debe guardarse en
		// "ultimas" sustituyendo a la que estaba en la posicion siguiente
		// a la "ultima" (que es la "primera").
		// Se deben actualizar las posiciones "primera" y "ultima", que
		// seran las posiciones siguientes a las que tenian anteriormente
		// a la sustitucion.

		primera = (primera + 1) % num_lineas_mostrar;	// Posicion siguiente
		ultima = (ultima + 1) % num_lineas_mostrar;		// Posicion siguiente

		delete [] ultimas[ultima]; // Liberar la memoria de la antigua cadena

		ultimas[ultima] = new char[strlen(cad) + 1];  // Pedir memoria y
		strcpy (ultimas[ultima], cad);				  // copiar correctamente

		num_linea++;	

		in.getline (cad, MAX); // Lectura de una nueva linea
	}

	// Se acab� el flujo: mostrar el resultado

	for (int i = primera; i != ultima; i = ((i+1) % num_lineas_mostrar))
		cout << ultimas[i] << endl;

	cout << ultimas[ultima] << endl;		// Debe mostrarse la �ltima
}

/***************************************************************************/
/***************************************************************************/
