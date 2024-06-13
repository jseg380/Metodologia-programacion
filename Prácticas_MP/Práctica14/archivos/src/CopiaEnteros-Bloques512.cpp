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
// Uso: CopiaEnteros-Bloques512 <fich1> <fich2>
//
//			<fich1>	es el fichero de entrada, que contiene una serie 
//					indefinida de números enteros. Es un fichero de texto.
//			<fich2> es el fichero de salida. Es un fichero binario.
// 
// Restricción: El programa LEE los números de entrada DE UNO EN UNO y 
//				los COPIA al fichero de salida EN BLOQUES DE 512 bytes. 
//
// Fichero: CopiaEnteros-Bloques512.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
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

	// Número de bytes del buffer
	const int TAM_BUFFER = 512; 

	// Número de datos int que caben en el buffer
	const int num_int_en_buffer = (TAM_BUFFER / sizeof(int));

	// Buffer de TAM_BUFFER bytes que guardará "num_int_en_buffer" datos int
	int buffer[num_int_en_buffer];


	cout << endl;
	cout << "Cada escritura transfiere: " << num_int_en_buffer 
		 << " enteros ("<< TAM_BUFFER << ") bytes." << endl;

	int num; // Para leer cada numero (de uno en uno)

	int cont_buffer = 0;	// Contador de numeros copiados al buffer
	int cont_total = 0;		// Contador total

	int cont_bloques = 0;

	while (fi >> num) {	// Lectura --> uno a uno
		
		if (cont_buffer < num_int_en_buffer) {

			// Copiar al buffer y actualizar el contador
	
			buffer[cont_buffer] = num;
			cont_buffer++;
		}

		else { // Buffer lleno: escribir en fo y preparalo para otra serie

			// Escribir el buffer (TAM_BUFFER bytes)
			fo.write ((const char *) buffer, TAM_BUFFER);

			cont_total += num_int_en_buffer;
	
			cout << endl;
			cout << "\tTransferido bloque " << setw(5) << ++cont_bloques;
			cout << " con " << setw(5) << TAM_BUFFER << " bytes";
			cout << " --> Bytes transferidos totales = " 
				 << setw(6) << cont_bloques*TAM_BUFFER;

			// Guardar el numero leido (que no se guardó) y actualizar el 
			// contador de datos guardados en el buffer

			buffer[0] = num;
			cont_buffer = 1;
		}

	} // while (fi >> num)

	// Se escribe lo que queda en el buffer

	int num_bytes_quedan = cont_buffer*sizeof(int);
	fo.write ((const char *) buffer, num_bytes_quedan);
	cont_total += cont_buffer;

	cout << endl;
	cout << "\tTransferido ultimo bloque con " 
         << setw(4) << cont_buffer*sizeof(int) << " bytes";
	cout << " --> Bytes transferidos totales = " 
		 << setw(6) << (cont_bloques*TAM_BUFFER)+num_bytes_quedan;
	cout << endl;

	// finalizacion: cierre de flujos 

	fi.close();
	fo.close();

	cout << endl;
	cout << "Se han transferido " << cont_total << " datos "; 
	cout << "(" << cont_total*sizeof(int)<< " bytes)" << endl;
	cout << endl;

	return (0);
}

/***************************************************************************/
/***************************************************************************/
