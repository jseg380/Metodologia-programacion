/***************************************************************************/
//
// Demostración de las funciones de la biblioteca Lista
//
// Fichero: II_Demo-Lista.cpp
//
/***************************************************************************/
#include <iostream>
#include <string>

#include "Lista.h"
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void) {
	
	// Declaración y construcción de una lista
	
	Lista l = ConstruyeLista (7);
	
	// Muestra la lista
	
	cout << "Lista l:" << endl << ToString (l) << endl;
	
	// .....................................................................
	// Ecualiza la lista a un valor
	
	Ecualiza (l, -23);
	
	cout << "Lista l:" << endl << ToString (l) << endl;
	
	// .....................................................................
	// Clona la lista l en l_copia
	
	Lista l_copia = ConstruyeLista ();
	
	Clona (l_copia, l);
	
	// Cambia la lista l y muestra las listas
	
	Valor (l, 2) = 99;
	Valor (l, 3) = -52;
	Valor (l, 5) = 3;
	Valor (l, 6) = 14;
	Valor (l, 7) = 159;
	
	cout << "Lista l:" << endl << ToString (l) << endl;
	cout << "Lista l_copia:" << endl << ToString (l_copia) << endl;
	
	// .....................................................................
	// Se comprueba si son iguales
	
	if (SonIguales(l, l_copia))
		cout << "l y l_copia son iguales" << endl;
	else
		cout << "l y l_copia no son iguales" << endl;
	
	// .....................................................................
	// Sublista de l almacenada en l_copia
	
	SubLista (l_copia, l, 3, 20);
	
	cout << "Lista l:" << endl << ToString (l) << endl;
	cout << "Sublista de l:" << endl << ToString (l_copia) << endl;
	
	// .....................................................................
	// Destrucción de listas
	
	DestruyeLista (l);
	DestruyeLista (l_copia);
}

/***************************************************************************/
/***************************************************************************/
