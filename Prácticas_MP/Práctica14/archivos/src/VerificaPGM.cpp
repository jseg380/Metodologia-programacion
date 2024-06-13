/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 7
//
// Comprueba la integridad de un fichero PGM de niveles de gris.
//
// Uso: VerificaPGM <Imagen_PGM>
//			<Imagen_PGM_original>
//						Es el fichero a verificar, que contiene
//						una imagen PGM en niveles de gris.
//
// Fichero: VerificaPGM.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
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
		cerr << "Formato: " << argv[0] << "<fichPGM>" << endl;
		cerr << "   <fichPGM> es el fich. PGM a veriificar" << endl;
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
	
	// Verificar fichero y mostrar resultado

	bool es_correcto = true;

	const int SIZE = 256;
	char cad [SIZE];

	int tam = TamanioFichero (argv[1]);  // Calcular el tamanio del fichero
	
	ifstream f(argv[1], ios::binary);  // Abrir el fichero para lectura

	f.getline (cad, SIZE); // Leer primera linea ("numero magico")

	if (strcmp("P5", cad)) {
		cerr << endl; 
		cerr << "Error: " << argv[1] << " NO es un fichero PGM." << endl;
		es_correcto = false;
	}

	if (es_correcto) {

		// Lectura y salto de comentarios

		do {
			f.getline (cad, SIZE);
		} while (cad[0]=='#');
 
		istringstream iss_cad;
		iss_cad.str (cad); // Asociar cad-->iss_cad
	
		int filas, columnas;
	
		iss_cad >> columnas >> filas;

		// Leer el maximo valor
		f.getline (cad, SIZE);

		// La imagen empieza en la posición actual del fichero 
	
		int pos_init_image = f.tellg ();
	
		f.close (); // Cerrar el fichero

		// Comprobamos si realmente quedan filas*columnas pixeles 
		// en el fichero desde la posición "pos_init_image"

		if ((pos_init_image + (filas*columnas)) != tam)
			es_correcto = false;
	}

	cout << endl;
	if (es_correcto) 
		cout  << "El fichero " <<  argv[1] << " es correcto" << endl; 
	else 
		cout  << "El fichero " <<  argv[1] << " no es correcto" << endl; 
	cout << endl;

	return (0);
}

/***************************************************************************/
/***************************************************************************/
