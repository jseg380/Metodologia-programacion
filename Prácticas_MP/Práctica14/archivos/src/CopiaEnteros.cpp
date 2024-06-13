/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 7
//
// Copia, en el mismo orden, los números que contiene el fichero de 
// entrada en el fichero de salida.
//
// Uso: CopiaEnteros <fich1> <fich2>
//
//			<fich1>	es el fichero de entrada, que contiene una serie 
//					indefinida de números enteros. Es un fichero de texto.
//			<fich2> es el fichero de salida. Es un fichero binario.
//
// Restricción: El programa lee y escribe números DE UNO EN UNO.
//
// Fichero: CopiaEnteros.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	// Comprobar numero de argumentos  

	if (argc != 3) {
		cerr << endl; 		
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Formato: " << argv[0] << " <fich1> <fich2>" << endl;
		cerr << "   <fich1> es un fich. (texto) con enteros." << endl;
		cerr << "   <fich2> contendra los datos leidos (binario)." << endl;
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

	if (ExisteFichero(argv[2])) {

		cerr << endl; 
		cerr << "Aviso: El fichero resultado " << argv[2] << " existe."<< endl;

		char respuesta;	

		do {		
			cerr << "Desea borrarlo (s/n)? ";
			cin >> respuesta;
			respuesta = toupper(respuesta);
		} while (respuesta != 'S' && respuesta != 'N');
		
		cerr << endl;
		if (respuesta == 'N') {
			cerr << "Terminando la ejecucion de " << argv[0] << endl;
			cerr << "--> Se mantiene intacto el fichero " << argv[2] << endl;
			exit (3);
		}
		else {
			cerr << "Continuando la ejecucion de " << argv[0] << endl;
			cerr << "--> Se borra el contenido del fichero " << argv[2]<< endl;
		}
		cerr << endl; 

	} // if (ExisteFichero(argv[2]))



	// Asociacion de flujos a ficheros

	// fi --> flujo de entrada, texto
	ifstream fi (argv[1]);

	// fo --> flujo de salida, binario
	ofstream fo (argv[2], ios::binary);
	if (!fo) {
		cerr << endl; 		
		cerr << "Error: No pudo crearse " << argv[2] << endl;
		cerr << endl; 
		exit (4);
	}


	// Procesamiento

	cout << endl;
	cout << "Cada escritura transfiere unicamente un dato." << endl;

	int num;			// Para leer cada numero 
	int cont_total = 0;	// Contador de datos transferidos

	while (fi >> num) {	// Lectura --> uno a uno
		
		cout << num << " "; 
		
		// Escribir el dato leido
		fo.write ((const char *) &num, sizeof(int));
		cont_total++;
	}

	// finalizacion: cierre de flujos 
	fi.close();
	fo.close();

	cout << endl;
	cout << "Se han transferido " << cont_total << " datos." << endl;
	cout << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
