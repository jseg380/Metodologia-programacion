/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
//
// Programa que lee una secuencia indefinida de caracteres de la entrada
// estándar y copia en la salida estándar las líneas que no comienzan por
// el carácter '#'.
//
// Fichero: CopiaLineasSinAlmohadilla.cpp
//
/***************************************************************************/

#include <iostream>
#include <string>

using namespace std;



int main (void) {
	
	string linea;				// string para guardar las líneas
	string primer_caracter;		// string para guardar el primer carácter
	string caracter = "#";		// string que determina las líneas que se
								// enviarán a la salida estándar, si la línea
								// comienza por 'caracter', no se enviará
	
	getline (cin, linea);	// Lectura adelantada de la línea
	
	while (!cin.eof()) {
		
		// Extraer el primer carácter de la línea leída
		
		primer_caracter = linea.substr (0, 1);
		
		if (primer_caracter != caracter)
			cout << linea << endl;
		
		getline (cin, linea);	// Nueva lectura de línea
	}
	
	
	return 0;
}
