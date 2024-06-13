/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
//
// Programa que binariza una imagen pgm.
// Binariza <nombre_pgm_original> <valor_umbral> <nombre_pgm_binarizado>
//
// Fichero: Binariza.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

#include "Utils.h"

using namespace std;

int main (int argc, char * argv[]) {
	
	// Comprobar número de argumentos

	if (argc != 4) {
		cerr << endl; 		
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Uso: " << argv[0] << " <nombre_pgm_original> <valor_umbral> "
			 << "<nombre_pgm_binarizado>" << endl;
		cerr << endl; 
		exit (1);
	}

	// Comprobaciones y acciones previas
	
	if (!ExisteFichero(argv[1])) {
		cerr << endl; 		
		cerr << "Error: No existe o no puede abrirse " << argv[1] << endl;
		cerr << endl; 
		exit (2);
	}
	
	int umbral = atoi (argv[2]);
	
	if (umbral < 0 || umbral > 255) {
		cerr << endl;
		cerr << "Error: El valor umbral debe ser un número entero entre" 
			 << "0 y 255" << endl;
		cerr << endl;
		exit (3);
	}


	// Entrada / Cálculos / Salida
	
	// Entrada
	
	// Asociación de flujos a ficheros
	
	ifstream fi (argv[1], ios::binary);
	
	// Copiar la cabecera del fichero original en el fichero binarizado
	
	const int TAM = 100;
	string cadena;
	string formato;
	string comentarios[TAM];
	int num_comentarios = 0;
	
	getline (fi, cadena);
	formato = cadena;
	
	// Copiar los comentarios de la cabecera
	
	while (fi.peek() == '#') {
		
		getline (fi, cadena);
		
		comentarios[num_comentarios] = cadena;
		
		num_comentarios++;
		
		// Más avanzado
		// comentarios[num_comentarios++] = cadena;
	}
	
	// Columnas y filas
	
	int filas, columnas, gris;
	
	fi >> columnas >> filas >> gris;
	
	getline (fi, cadena);	// Leer el salto de línea que no ha cogido '>>'
	
	typedef unsigned char byte;
	
	byte * imagen = new byte [filas * columnas];
	byte pixel;	// unsigned para que sea [0, 255]
	
	if (formato == "P5") {
		
		for (int i = 0 ; i < (filas * columnas) ; i++) {
			
			// Leer un pixel
			
			fi.read (reinterpret_cast<char *>(&pixel), 1);
			
			// Guardar el pixel
			
			imagen[i] = pixel;
		}
	}
	else if (formato == "P2") {
		int valor;
		
		for (int i = 0 ; i < (filas * columnas) ; i++) {
			
			// Leer un pixel
			
			fi >> valor;
			
			// Guardar el pixel
			
			imagen[i] = (byte)(valor);
		}
	}
	
	// Cerrar el fichero de entrada
	
	fi.close();
	
	// Procesamiento (Cálculos)
	
	for (int i = 0 ; i < filas * columnas ; i++) {
		
		if ((int)imagen[i] >= umbral)
			imagen[i] = (byte) 255;
		else
			imagen[i] = (byte) 0;
		
		// Igual
		// imagen[i] = ((int)imagen[i] >= umbral) ? (byte) 255 : (byte) 0;
	}
	
	// Salida
	
	ofstream fo (argv[3], ios::binary);
	
	/*
	if (!fo) {
		cerr << endl; 		
		cerr << "Error: No pudo crearse " << argv[3] << endl;
		cerr << endl; 
		exit (4);
	}
	*/
	
	fo << formato << endl;
	
	for (int i = 0 ; i < num_comentarios ; i++)
		fo << comentarios[i] << endl;
	
	fo << "# Comentario añadido en el programaa" << endl;
	
	fo << columnas << " " << filas << endl;
	fo << gris << endl;
	
	if (formato == "P5") {
		
		fo.write ((const char *)imagen, filas*columnas);
		
		if (fo.fail()) {
			cerr << "Error: No se puede escribir en " << argv[3] << endl;
			exit (3);
		}
		
	}
	else if (formato == "P2")
		for (int i = 0 ; i < filas*columnas ; i++)
			fo << setw(4) << (int)imagen[i];
	
	
	// Cerrar el fichero de salida
	
	fo.close();
	
	// Liberar espacio
	
	delete [] imagen;

	cout << "Binarización realizada con éxito." << endl;

	return 0;
}


