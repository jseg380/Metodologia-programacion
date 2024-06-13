/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
//
// Programa que enumera las líneas de los contenidos que recibe por el flujo
// de entrada y lo envía al flujo de salida. Si el programa no recibe ningún
// argumento los flujos de entrada y salida serán cin y cout respectivamente.
// Si recibe un argumento el flujo de entrada se asociará a un fichero cuyo
// nombre sea el del argumento (si existe). Si recibe dos argumentos los flujos
// de entrada y salida se asociarán a ficheros que tengan los nombres del primer
// y segundo argumento respectivamente.
// Respuesta basada en el comentario de Gnurou de este artículo de stackoverflow
// https://stackoverflow.com/questions/2407077/read-from-cin-or-a-file
//
// Fichero: NumeraLineas_Ampliacion.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;


int main (int argc, char * argv[])
{
	
	// .....................................................................
	// Procesamiento de argumentos
	
	if (argc > 3) {
		cerr << "Se esperaban un máximo de 2 argumentos." << endl;
		cerr << "Formato: " << argv[0] << " <fichero_entrada> <fichero_salida>" 
			 << endl;
		exit (1);
	}
	
	// Por defecto flujos de entrada/salida asociados a cin/cout
	
	istream * input_stream = & cin;		// Puntero a flujo de entrada
	ostream * output_stream = & cout;	// Puntero a flujo de salida
	
	// Los flujos a ficheros han de declararse aquí
	// para que su ámbito el programa
	
	ifstream file_input;
	ofstream file_output;
	
	if (argc > 1) {
		
		file_input.open (argv[1]);
		input_stream = & file_input;
		
		if (argc > 2) {
			
			file_output.open (argv[2]);
			output_stream = & file_output;
		}
	}
	
	// .....................................................................
	// Comprobación de la validez de argumentos
	
	if (argc > 1) {
		
		if (!file_input) {
			cerr << "Error: No pudo abrirse " << argv[1] << endl;
			exit (2);
		}
		
		if (argc > 2) {
			
			if (!file_output) {
				cerr << "Error: No pudo crearse " << argv[2] << endl;
				exit (3);
			}
		}
		
	}
	
	// .....................................................................
	// Procesamiento
	
	string cad;						// Para leer/escribir cada línea
	int cont = 0;					// Numero de línea
	
	getline ((*input_stream), cad);	// Lectura adelantada

	while (!(*input_stream).eof()) {

		// Escribe en el flujo de salida num.linea + cadena
		
		(*output_stream) << setw(4) << ++cont << "  " << cad << endl;

		getline ((*input_stream), cad);	// Nueva lectura
	}

	// Cierre de flujos (Solo si han abierto ficheros)
	
	if (argc > 1) {
		file_input.close();
		
		if (argc > 2)
			file_output.close();
	}
	
	return 0;
	
}
