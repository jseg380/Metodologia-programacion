/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 7
//
// Programa que convierte un PGM(P2) a un PGM(P5).
//
// Uso: PGMP2_to_PGMP5 <Imagen_PGM_P2>  <Imagen_PGM_P5>
//			<Imagen_PGM_P2>
//						Es el fichero de entrada, que contiene
//						una imagen PGM P2 en niveles de gris.
//			<Imagen_PGM_P5>
//						Es el fichero de salida, que contendrá 
//						una imagen PGM P5 en niveles de gris.
//
// Fichero: PGMP2_to_PGMP5.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>

#include "Utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

typedef unsigned char byte;

/***************************************************************************/
/***************************************************************************/

int main(int argc, char **argv)
{
	 
	/************************************************************************/
	// Comprobación del número y validez de los argumentos
	
	if (argc != 3) {
		cerr << "Error: num. de parametros incorrecto" << endl;
		cerr << "Formato: " << argv[0] << "<Imagen_PGM_P2> <Imagen_PGM_P5>";
		cerr << endl;
		cerr << "   <Imagen_PGM_P2> es el fich. PGM P2" << endl;
		cerr << "   <Imagen_PGM_P5> es el fich. PGM P5" << endl;
		exit (1);
	}
	
	//Comprobar la existencia del fichero de entrada
	
	if (!ExisteFichero (argv[1])) {
		cerr << "Error: " << argv[1] << " no puede abrirse" << endl;
		exit (2);
	}
	
	int tam = TamanioFichero (argv[1]);  // Calcular el tamanio del fichero


	/************************************************************************/
	// Leer datos del fichero PGM y cargar los píxeles de la imagen en memoria
	
	int filas;
	int columnas;
	
	const int TAM = 256;
	char cad [TAM];


	// Abrir fichero y comprobar si es PGM P2
 
	ifstream fi (argv[1], ios::binary);  // Abrir el fichero para lectura

	fi.getline (cad, TAM); // Leer primera linea ("numero magico")

	if (strcmp("P2", cad)) {
		cerr << "Error: " << argv[1] << " NO es un fichero PGM P2." << endl;
		exit (4);
	}

	// Crear fichero y escribir P2

	ofstream fo (argv[2], ios::binary); // Abrir el fichero para escritura
	if (fo.fail()) {
		cerr << "\nError: " << argv[3] << " no puede crearse.\n\n";
		exit (1);
	}

	// Escribir el "numero magico"
	fo << "P5\n"; 


	// Lectura y copia de comentarios

	fi.getline (cad, TAM);
	while (cad[0]=='#') {
		fo << cad << endl;
		fi.getline (cad, TAM);
	}

	// Añadir el nuevo comentario
	fo << "# Transformado desde " << argv[1] << " - PGM(P2)" <<  endl; 


	// La cadena "cad" contiene las dimensiones de la imagen 
	// Extraerlas y copiarlas

	istringstream iss_cad;
	iss_cad.str (cad); // Asociar cad-->iss_cad
	
	iss_cad >> columnas >> filas;
	fo  << columnas << "  " << filas << endl; 


	// Leer y copiar el maximo valor
	fi.getline (cad, TAM);
	fo  << cad << endl; 


	// Reservar espacio para una fila de la imagen de salida
	byte * valores_fila_out = new byte[columnas];	


	string una_fila; 

	for (int fila=0; fila<filas; fila++) {

		getline (fi, una_fila); // Leer una fila 

		istringstream iss (una_fila); 

		int valor; 
		
		for (int col=0; col<columnas; col++) {
		
			iss >> valor; // Leer un dato int
			valores_fila_out[col] = (byte) valor; // Guardarlo como byte
		}

		// Guardar cada fila
		fo.write ((const char *) valores_fila_out, columnas);
	}

	fi.close (); // Cerrar el fichero de entrada 
	fo.close (); // Cerrar el fichero de salida
	
	/***********************************************************************/
	// Finalizar: liberar memoria
	
	delete [] valores_fila_out;

	/***********************************************************************/

	return 0;
}

/****************************************************************************/
/****************************************************************************/
