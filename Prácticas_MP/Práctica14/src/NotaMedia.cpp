/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
//
// Programa que calcula las calificaciones medias de un listado de estudiantes.
// NotaMedia <fichero_binario_datos> <fichero_texto_publicar>
//
// Fichero: NotaMedia.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

#include "Utils.h"

using namespace std;

const int CASILLAS_DNI = 15;
const int CASILLAS_NOMBRE = 50;
const int CASILLAS_APELLIDO = 50;

struct RegEstudiante {
	
	char DNI [CASILLAS_DNI];
	char Nombre [CASILLAS_NOMBRE];
	char Apellidos [CASILLAS_APELLIDO];
	
	double Nota_EC;
	double Nota_EP1;
	double Nota_EP2;
	double Nota_EXAMEN;
};


int main (int argc, char * argv[]) {
	
	// Comprobar numero de argumentos

	if (argc != 3) {
		cerr << endl; 		
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Uso: " << argv[0] << " <fichero_binario_datos> "
			 << "<fichero_texto_publicar> " << endl;
		cerr << "   <fichero_binario_datos> es un fichero binario con los "
			 << "datos de los estudiantes" << endl;
		cerr << "   <fichero_texto_publicar> es un fichero de texto a partir"
			 << " del cual se puede publicar un listado de las notas" << endl;
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


	// Asociación de flujos a ficheros
	
	ifstream fi (argv[1], ios::binary);
	ofstream fo (argv[2]);
	
	if (!fo) {
		cerr << endl;
		cerr << "Error: No pudo crearse " << argv[2] << endl;
		cerr << endl; 
		exit (4);
	}

	// Procesamiento
	
	RegEstudiante actual;
	
	cout << left << setw(12) << "DNI" 
		 << left << setw(24) << "APELLIDOS"
		 << left << setw(24) << "NOMBRE"
		 << left << setw(5) << "NOTA" << endl;
	
	fo << left << setw(11) << "DNI"
	   << left << setw(5) << "NOTA" << endl;
	
	// Lectura adelantada
	
	fi.read (reinterpret_cast<char *>(&actual), sizeof(RegEstudiante));
	
	while (!fi.eof()) {
		
		double nota_media;
		
		nota_media = (actual.Nota_EC + actual.Nota_EP1 + actual.Nota_EP2 
			         + actual.Nota_EXAMEN) / 4;
		
		cout << left << setw(12) << actual.DNI
			 << left << setw(24) << actual.Apellidos
			 << left << setw(24) << actual.Nombre
			 << left << setw(5)  << nota_media << endl;
		
		fo << left << "*" << actual.DNI[1] << "**" 
		   << actual.DNI[4] << actual.DNI[5] << actual.DNI[6] << actual.DNI[8]
		   << "   " << left << setw(5) << nota_media << endl;
		
		fi.read (reinterpret_cast<char *>(&actual), sizeof(RegEstudiante));
	}
	

	// Cierre de flujos
	
	fi.close();
	fo.close();

	return 0;
}



