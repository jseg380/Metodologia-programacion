/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
//
// Programa que divide un fichero de cualquiero tipo en diferentes ficheros.
// Uso:
// ParteFicheroPorNumBytes <fichero_original> <máximo_número_bytes>
//
// Fichero: ParteFicheroPorNumBytes.cpp
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

	if (argc != 3) {
		cerr << endl; 		
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Uso: " << argv[0] << " <fichero_original> " 
			 << "<máximo_número_bytes> " << endl;
		cerr << "   <fichero_original> es un fichero de cualquier tipo" << endl;
		cerr << "   <máximo_número_bytes> es un número natural" << endl;
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

	if (atoi (argv[2]) <= 0) {
		cerr << endl;
		cerr << "Error: El máximo número de bytes debe ser un número"
			 << "natural mayor que 0" << endl;
		cerr << endl;
		exit (3);
	}


	// Asociación de flujos a ficheros

	ifstream fi (argv[1], ios::binary);

	// Procesamiento

	const int TAM_BUFFER = 1024;
	int tamanio_fichero = atoi (argv[2]);
	int contador = 1;
	char buffer [TAM_BUFFER];
	
	ostringstream oss ("");
	
	// Se lee y escribe en bloques de tamanio_fichero mientras se pueda
	
	while (fi.read (reinterpret_cast<char *>(buffer), tamanio_fichero)) {
		
		// Nombre del archivo
		
		oss << argv[1] << "_" << setfill('0') << setw(3) << contador;
		
		// Flujo de salida a un archivo
		
		ofstream fo (oss.str(), ios::binary);
		
		fo.write (reinterpret_cast<const char *>(buffer), tamanio_fichero);
		
		contador++;
		
		// 'Vaciar' el flujo ostringstream
		
		oss.str("");
		
		// Cerrar el flujo ofstream
		
		fo.close();
	}
	
	// Escribir los últimos datos leídos
	
	oss << argv[1] << "_" << setfill('0') << setw(3) << contador;
	
	ofstream fo (oss.str(), ios::binary);
	
	if (!fo) {
		cerr << endl; 		
		cerr << "Error: No pudo crearse " << oss.str() << endl;
		cerr << endl; 
		exit (4);
	}
	
	fo.write (reinterpret_cast<const char *>(buffer), fi.gcount());
	
	// Fichero oculto con información
	
	fo.close ();
	
	fo.open (NombreFicheroCtrl (argv[1]));
	
	if (!fo) {
		cerr << endl; 		
		cerr << "Error: No pudo crearse " << NombreFicheroCtrl (argv[1]) 
			 << endl;
		cerr << endl; 
		exit (4);
	}
	
	fo << argv[1] << endl << contador;

	// Cierre de flujos
	
	fi.close();
	fo.close();

	cout << "Fichero dividido correctamente" << endl;

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
