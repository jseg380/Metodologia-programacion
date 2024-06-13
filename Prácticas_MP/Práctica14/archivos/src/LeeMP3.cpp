/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 7
//
// Comprueba si el fichero es MP3 y si tiene ID3 TAG.
//
// Uso: LeeMP3 <fichero>
//		donde <fichero> es el fichero a verificar
//
// Fichero: LeeMP3.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include "Utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main(int argc, char **argv)
{
	// Comprobación del número y validez de los argumentos
	
	if (argc != 2) {
		cerr << endl; 
		cerr << "Error: num. de parametros incorrecto" << endl;
		cerr << "Formato: " << argv[0] << "<fichero>" << endl;
		cerr << "   <fichero> es el fich. a verificar" << endl;
		cerr << endl; 
		exit (1);
	}
	
	// Comprobar la existencia del fichero de entrada
	
	if (!ExisteFichero (argv[1])) {
		cerr << endl; 
		cerr << "Error: " << argv[1] << " no puede abrirse" << endl;
		cerr << endl; 
		exit (2);
	}

	cout << endl;
	cout  << "Analizando fichero: " <<  argv[1] << endl; 
	
	char palabra[31];

	ifstream f (argv[1], ios::binary);

	// Comprobar si es MP3: dene tener la palabra ID3 en los tres primeros 
	// bytes del fichero
 	
	f.seekg (0, ios::beg); // Colocarse al principio
	f.read (reinterpret_cast<char*> (palabra), 3);

	palabra[3] = '\0';

	bool es_MP3 = (strcmp(palabra, "ID3")==0);

	// Comprobar si es ID3TAG: dene tener la palabra TAG empezando en el 
	// byte 128 antes del final del fichero.
	f.seekg (-128, ios::end); // Colocarse 128 bytes antes del final  

	f.read (reinterpret_cast<char*> (palabra), 3);
	palabra[3] = '\0';

	bool es_ID3TAG = (strcmp(palabra, "TAG")==0);

	// Leer título
	f.read (reinterpret_cast<char*> (palabra), 30);
	palabra[30] = '\0';

	string info;
	info = palabra;

	// Leer Artista
	f.read (reinterpret_cast<char*> (palabra), 30);
	palabra[30] = '\0';

	info = info + " (" + palabra + ")";

	// Mostrar resultado

	if (es_MP3) 
		cout  << "\tes MP3" << endl; 
	else 
		cout  << "\tno es MP3" << endl; 

	if (es_ID3TAG) 
		cout  << "\tes ID3 TAG" << endl; 
	else 
		cout  << "\tno es ID3 TAG" << endl; 
	cout << endl;

	cout << "\t" << info << endl;
	cout << endl;

	f.close ();

	return (0);
}

/***************************************************************************/
/***************************************************************************/
