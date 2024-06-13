/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 7
//
// Programa que convierte un PGM(P5) a un PGM(P2).
//
// Uso: PGMP5_to_PGMP2 <Imagen_PGM_P5>  <Imagen_PGM_P2>
//			<Imagen_PGM_P5>
//						Es el fichero de entrada, que contiene
//						una imagen PGM P5 en niveles de gris.
//			<Imagen_PGM_P2>
//						Es el fichero de salida, que contendrá 
//						una imagen PGM P2 en niveles de gris.
//
// Fichero: PGMP5_to_PGMP2.cpp
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
		cerr << "Formato: " << argv[0] << "<Imagen_PGM_P5> <Imagen_PGM_P2>";
		cerr << endl;
		cerr << "   <Imagen_PGM_P5> es el fich. PGM P5" << endl;
		cerr << "   <Imagen_PGM_P2> es el fich. PGM P2" << endl;
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


	// Abrir fichero y comprobar si es PGM P5
 
	ifstream fi (argv[1], ios::binary);  // Abrir el fichero para lectura

	fi.getline (cad, TAM); // Leer primera linea ("numero magico")

	if (strcmp("P5", cad)) {
		cerr << "Error: " << argv[1] << " NO es un fichero PGM P5." << endl;
		exit (4);
	}

	// Crear fichero y escribir P2

	ofstream fo (argv[2], ios::binary); // Abrir el fichero para escritura
	if (fo.fail()) {
		cerr << "\nError: " << argv[3] << " no puede crearse.\n\n";
		exit (1);
	}

	// Escribir el "numero magico"
	fo << "P2\n"; 


	// Lectura y copia de comentarios

	fi.getline (cad, TAM);
	while (cad[0]=='#') {
		fo << cad << endl;
		fi.getline (cad, TAM);
	}

	// Añadir el nuevo comentario
	fo << "# Transformado desde " << argv[1] << " - PGM(P5)" <<  endl; 


	// La cadena "cad" contiene las dimensiones de la imagen 
	// Extraerlas y copiarlas

	istringstream iss_cad;
	iss_cad.str (cad); // Asociar cad-->iss_cad
	
	iss_cad >> columnas >> filas;
	fo  << columnas << "  " << filas << endl; 


	// Leer y copiar el maximo valor
	fi.getline (cad, TAM);
	fo  << cad << endl; 


	// Reservar espacio para la imagen
	byte *image = new byte[filas*columnas];

	// La imagen empieza en la posición actual del fichero 
	
	int pos_init_image = fi.tellg ();
	
	// Comprobamos si realmente quedan filas*columnas pixeles en el fichero
	
	if ((pos_init_image + (filas*columnas)) != tam) {
		cerr << "Error: La imagen es inconsistente con dimensiones." << endl;
		exit(5);
	}


	// Leer el bloque de imagen del fichero y guardarlo en "image"

	fi.seekg (tam-(filas*columnas), ios::beg); // Inicio del bloque imagen
											   // (por si acaso)

	fi.read (reinterpret_cast<char*> (image), filas*columnas);

	if (fi.gcount() != filas*columnas) {
		cerr << "Error: No se pudo leer correctamente la imagen." << endl;
		exit(6);
	}

	fi.close (); // Cerrar el fichero


	/************************************************************************/
	// Guardar el resultado en un fichero PGM P2

	byte * p_image = image; 

	for (int fila=0; fila<filas; fila++) {
						
		for (int col=0; col<columnas; col++) {
			fo << setw(4) << (int) *p_image;
			p_image++; 
		}
		fo << endl;
	}

	fo.close (); // Cerrar el fichero
	
	/***********************************************************************/
	// Finalizar: liberar memoria
	
	delete [] image;

	/***********************************************************************/

	return 0;
}

/****************************************************************************/
/****************************************************************************/
