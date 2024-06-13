/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
//
// Programa que reconstruye un fichero a partir de una serie de ficheros que
// contienen sus partes.
// Reconstruye <nombre_fichero_original>
//
// Fichero: Reconstruye.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

#include "Utils.h"

using namespace std;

string NombreFicheroCtrl (const string &);

int main (int argc, char * argv[]) {
	
	// Comprobar numero de argumentos

	if (argc != 2) {
		cerr << endl; 		
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Uso: " << argv[0] << " <nombre_fichero_original> " << endl;
		cerr << "   <nombre_fichero_original> es un fichero dividido en partes" 
			 << " con el programa ParteFicheroPorNumBytes" << endl;
		cerr << endl; 
		exit (1);
	}

	// Comprobaciones y acciones previas
	
	string fichero_ctrl = NombreFicheroCtrl (argv[1]);
	
	if (!ExisteFichero(fichero_ctrl)) {
		cerr << endl; 		
		cerr << "Error: No existe o no puede abrirse " << fichero_ctrl << endl;
		cerr << endl; 
		exit (2);
	}


	// Asociación de flujos a ficheros
	
	ifstream fi (fichero_ctrl);
	
	string nombre_original;
	int contador;
	
	getline (fi, nombre_original);
	
	fi >> contador;
	
	fi.close();
	
	ofstream fo (nombre_original, ios::binary);
	
	if (!fo) {
		cerr << endl; 		
		cerr << "Error: No pudo crearse " << argv[1] << endl;
		cerr << endl; 
		exit (4);
	}

	// Procesamiento
	
	// Se copian los datos de los ficheros divididos en orden
	
	for (int i = 1 ; i <= contador ; i++) {
		
		ostringstream oss;
		
		oss << nombre_original << "_" << setfill('0') << setw(3) << i;
		
		// Abrir un fichero
		
		fi.open (oss.str());
		
		// Si hay algún fallo detener el programa
		
		if (fi.fail()) {
			cerr << endl;
			cerr << "No se pudo abrir el fichero " << oss.str() << endl;
			cerr << endl;
			exit (5);
		}
		
		// Copiar datos del flujo de entrada al flujo de salida
		
		char * buffer;
		int tam = TamanioFichero (oss.str());
		
		buffer = new char [tam];
		
		fi.read (reinterpret_cast<char*>(buffer), tam);
		
		fo.write (reinterpret_cast<const char*>(buffer), tam);
		
		// Cerrar el flujo ifstream
		
		fi.close();
	}

	// Cierre de flujos
	
	fo.close();

	cout << "Fichero reconstruido correctamente" << endl;

	return 0;
}


string NombreFicheroCtrl (const string & original)
{
	int ultima_barra = 0;
	string nombre = original;
	
	// Saber el número de barras que hay en la ruta completa
	
	for (int i = 0 ; i < original.length() ; i++)
		if (original[i] == '/')
			ultima_barra = i;
	
	// Añadir un punto inmediatamente después de la última barra
	
	nombre.insert (ultima_barra + 1, ".");
	
	nombre += ".ctrl";
	
	return nombre;
}
