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

using namespace std;



int main (int argc, char * argv[]) {
	
	// .....................................................................
	// Procesamiento de argumentos
	
	if (argc != 2){
		cerr << "Se esperaba 1 argumento" << endl;
		cerr << argv[0] << " <carácter> "<< endl;
		exit(1);
	}
	
	char caracter = argv[1][0];
	char actual;
	int contador = 0;
	
	while (cin >> actual)
		if (actual == caracter)
			contador++;
	
	cout << "Hay " << contador << " caracteres " << caracter << "." << endl;
}
