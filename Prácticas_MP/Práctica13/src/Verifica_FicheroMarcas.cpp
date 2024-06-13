/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
//
// Programa que verifica si un fichero de marcas es correcto. Para que sea
// correcto debe empezar por la cadena mágica MARCAS, debe indicar el número
// de pruebas que contiene, siendo este número estrictamente positivo y 
// que represente las pruebas que se presentan a continuación.
// Todas las marcas tienen que tener la estructura 
// <prueba> <fecha> <licencia> <tiempo>
// en el que <prueba> representa una de las pruebas del principio.
//
// Fichero: Verifica_FicheroMarcas.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


/*
/////////////////////////////////////////////////////////////////////////
//
//	IMPORTANTE: Para no usar continue también se podría hacer uso de una
// 				variable bool que indicase si el fichero es correcto
//				en todo momento y en caso de no serlo que "no haga mucho
//				más", pero el problema de ello es que igualmente se
//				realizarían algunas instrucciones, aquellas que no están
//				dentro de bucles o condicionales. Una solución sería meter
//				todo en condicionales (if) pero eso sería poco viable porque
//				habría que 'indentar' demasiado
//
/////////////////////////////////////////////////////////////////////////
*/

int main (int argc, char * argv[]) {
	
	const char CHAR_COMENTARIO = '#';		// Carácter por el que comienzan
											// los comentarios
	
	const string cadena_magica = "MARCAS";	// Cadena mágica
	
	const int TAM = 50;
	
	// .....................................................................
	// Procesamiento de argumentos
	
	if (argc < 2) {
		cerr << "Se esperaba al menos 1 argumento." << endl;
		cerr << "Formato: " << argv[0] << " <archivo_marcas>" << endl;
		exit (1);
	}
	
	for (int arg_num = 1 ; arg_num < argc ; arg_num++) {
		
		// ...................................................................
		// Comprobación de la validez del argumento actual
		
		// Si es un archivo de marcas en la primera línea debe tener
		// solo la cadena mágica "MARCAS"
		
		ifstream archivo (argv[arg_num]);
		string cadena;
		
		getline (archivo, cadena);
		
		if (cadena != cadena_magica) {
			cerr << argv[arg_num] << " no es un archivo de marcas válido." 
				 << endl;
			continue;	// Pasar a comprobar el siguiente archivo
		}
		
		
		// ...................................................................
		// Saltar comentarios
		
		char caracter;
		
		istringstream input_stream;
		int num_pruebas;
		int cont_lineas = 1;
		int contador = 0;
		
		getline (archivo, cadena);
		cont_lineas++;
		
		caracter = cadena[0];
		
		while (caracter == CHAR_COMENTARIO) {
			
			getline (archivo, cadena);
			cont_lineas++;
			
			caracter = cadena[0];
		}
		
		
		// ...................................................................
		// Número de pruebas
		
		// Leer hasta que encuentre una línea no vacía
		
		while (cadena[0] == '\0') {
			getline (archivo, cadena);
			cont_lineas++;
		}
		
		// 'cadena' ahora contiene una línea no vacía
		
		input_stream.str (cadena);
		
		input_stream >> cadena;
		
		// Vector que contendrá las pruebas disponibles
		
		string pruebas[TAM];
		
		num_pruebas = stoi (cadena);
		
		if (num_pruebas <= 0) {
			cerr << "Error en la línea " << cont_lineas << endl;
			cerr << "El número de pruebas debe ser estrictamente positivo." 
				 << endl;
			continue;	// Pasar a comprobar el siguiente archivo
		}
		
		// Lectura de las pruebas
		
		while (input_stream >> cadena) { 		// Leerá mientras haya 
												// palabras en el flujo
			pruebas[contador] = cadena;
			contador++;
			
		}
		
		// El número de pruebas debe ser el indicado por el número entero
		
		if (num_pruebas != contador) {
			cerr << "Error en la línea " << cont_lineas << endl;
			cerr << "El número de pruebas no coincide con el indicado." << endl;
			continue;
		}
		
		// ...................................................................
		// Comprobación de las marcas
		
		bool correcto = true;
		
		// Se lee línea a línea hasta el final del fichero
		
		getline (archivo, cadena);
		cont_lineas++;
		
		while (!archivo.eof() && correcto) {
			
			// Solo se comprueba si la línea no está vacía
			
			if (cadena.length() != 0) {
				
				// Si se usa el istringstream input_stream no funciona bien
				// porque al hacer input_stream >> cadena manda todo el contenido
				// de input_stream a cadena, no 'la primera palabra' (habiendo
				// realizado anteriormente input_stream.str (cadena))
				
				istringstream linea;
				
				linea.str (cadena);
				
				linea >> cadena;
				
				// Comprobar que coincide con alguna de las pruebas recogidas
				
				bool prueba_encontrada = false;
				
				for (int i = 0 ; i < num_pruebas && !prueba_encontrada ; i++)
					if (cadena == pruebas[i])
						prueba_encontrada = true;
				
				// En caso de que la prueba no coincida con ninguna
				// se puede dejar de comprobar el fichero
				
				if (!prueba_encontrada) {
					cerr << "Error en la línea " << cont_lineas << endl;
					cerr << "La prueba no coincide" << endl;
					//continue;		// Seguiría comprobando las siguientes marcas
					//break;		// Se saldría del bucle
					correcto = false;
				}
				
				// Leer el resto de palabras de la línea
				
				contador = 0;
				
				while (linea >> cadena && correcto)
					contador++;
				
				if (contador != 3 && correcto) {
					cerr << "Error en la línea " << cont_lineas << endl;
					cerr << "Formato de marca incorrecto. El formato esperado"
						 << " es <prueba> <fecha> <licencia> <tiempo>" << endl;
					//continue;		// Seguiría comprobando las siguientes marcas
					//break;		// Se saldría del bucle
					correcto = false;
				}
			}
			
			getline (archivo, cadena);
			cont_lineas++;
		}
		
		if (correcto)
			cout << argv[arg_num] << " verificado correctamente." << endl;
		else {
			cerr << argv[arg_num] << " no es un fichero de marcas correcto." 
				 << endl;
		}
		
	}
	
	return 0;
}
