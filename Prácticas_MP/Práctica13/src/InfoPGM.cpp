/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
//
// Programa que recibe el nombre de un fichero PGM y muestra su cabecera.
//
// Fichero: InfoPGM.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int main (int argc, char * argv[]) {
	
	// Carácter por el que comienzan los comentarios
	
	const char CHAR_COMENTARIO = '#';
	
	// .....................................................................
	// Procesamiento de argumentos
	
	if (argc != 2) {
		cerr << "Se esperaban 1 argumento." << endl;
		cerr << "Formato: " << argv[0] << " <archivo_pgm>" << endl;
		exit (1);
	}
	
	// .....................................................................
	// Comprobación de la validez de argumentos
	
	// Si es un archivo .pgm debe tener en la primera línea la cadena P5
	
	ifstream archivo (argv[1]);
	const string cadena_magica = "P5";
	string cadena;
	
	getline (archivo, cadena);
	
	if (cadena != cadena_magica) {
		cerr << "El archivo introducido debe estar en formato .pgm." << endl;
		exit (2);
	}
	
	// .....................................................................
	// Mostrar la cabecera
	
	char caracter;
	
	cout << cadena << endl;	// Primera línea que contiene la cadena mágica
	
	getline (archivo, cadena);
	
	caracter = cadena[0];
	
	while (caracter == CHAR_COMENTARIO) {
		
		cout << cadena << endl;
		
		getline (archivo, cadena);
		
		caracter = cadena[0];
	}
	
	// Después de los comentarios debe haber 3 palabras
	
	// La primera línea después de los comentarios ya está almacenada en cadena
	// Se extraen tantas palabras como se pueda
	
	istringstream input_stream (cadena);
	int contador = 1;
	
	input_stream >> cadena;
	
	while (!input_stream.eof()) {
		
		cout << cadena << " ";
		
		input_stream >> cadena;
		
		contador++;
	}
	
	cout << endl;
	
	while (contador <= 3) {
		archivo >> cadena;
		
		cout << cadena;
		
		contador++;
	}
	
	cout << endl;
	
	return 0;
}
