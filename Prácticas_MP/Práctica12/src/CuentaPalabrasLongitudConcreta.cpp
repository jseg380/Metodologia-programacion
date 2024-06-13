/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
//
// Programa que lee una secuencia indefinida de caracteres de la entrada
// estándar y copia en la salida estándar las líneas que no comienzan por
// el carácter '#'.
//
// Fichero: CuentaCaracteresConcretos.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;



int main (int argc, char * argv[]) {
	
	// .....................................................................
	// Procesamiento de argumentos
	
	if (argc != 2){
		cerr << "Se esperaba 1 argumento" << endl;
		cerr << argv[0] << " <carácter> "<< endl;
		exit(1);
	}
	
	int longitud = atoi (argv[1]);
	int contador = 0;
	string actual;
	
	while (cin >> actual)
		if (actual.length() == longitud)
			contador++;
	
	cout << "Hay " << contador << " palabras de " << longitud
		 << " caracteres de longitud." << endl;
}
