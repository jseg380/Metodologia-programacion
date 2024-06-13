/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
//
// Programa que recibe como argumentos los nombres de dos ficheros de texto:
// el primero es un texto "convencional" y el segundo contiene números enteros
// que indican las palabras que conforman el mensaje oculto.
// Para cada palabra hay dos números: el número de línea y el número de palabra
// dentro de cada línea.
//
// Fichero: MensajesOcultos-2.cpp
//
/***************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;


string EliminaSignos (const string & cadena);


int main (int argc, char * argv[])
{
	
	// .....................................................................
	// Procesamiento de argumentos
	
	if (argc != 3) {
		cerr << "Se esperaban 2 argumentos." << endl;
		cerr << "Formato: " << argv[0] << " <fichero_texto> " 
			 << "<fichero_claves>" << endl;
		exit (1);
	}
	
	ifstream texto (argv[1]);
	ifstream claves (argv[2]);
	
	// .....................................................................
	// Comprobación de la validez de argumentos
	
	if (!texto) {
		cerr << "Error: No pudo abrirse " << argv[1] << endl;
		exit (2);
	}
	
	if (!claves) {
		cerr << "Error: No pudo abrirse " << argv[2] << endl;
		exit (3);
	}
	
	// .....................................................................
	// Procesamiento de los datos
	
	string cad;
	
	claves >> cad;	// Lectura adelantada
	
	while (!claves.eof()) {
		
		string linea;
		istringstream flujo_linea;
		string palabra;
		
		// Ir al principio del documento
		
		texto.clear ();		// Reinicia el eof bit
		texto.seekg (0);	// Va al principio
		
		// Ir a la línea indicada
		
		for (int i = 1 ; i <= stoi (cad) ; i++)
			getline (texto, linea);
		
		claves >> cad;
		
		flujo_linea.str (linea);
		
		// En la línea extraer la palabra indicada
		
		for (int i = 1 ; i <= stoi (cad) ; i++)
			flujo_linea >> palabra;
		
		palabra = EliminaSignos (palabra);
		
		cout << palabra << " ";
		
		claves >> cad;
	}
	
	cout << endl;
	
	return 0;
	
}


string EliminaSignos (const string & cadena)
{
	string resultado = "";
	char actual;
	
	for (int i = 0 ; i < cadena.length() ; i++) {
		actual = cadena[i];
		if (actual <= 32 || actual >= 48)
			resultado += actual;
	}
	
	return resultado;
}
