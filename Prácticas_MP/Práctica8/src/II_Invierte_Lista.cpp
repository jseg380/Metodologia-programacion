/***************************************************************************/
//
// Ejercicio 20 de la Relación de Problemas II
//
// Fichero: II_Invierte_Lista.cpp
//
/***************************************************************************/
#include <iostream>
#include <string>

#include "Lista.h"
using namespace std;


/***************************************************************************/
/***************************************************************************/

int main (void) {
	
	// Valores por defecto
	
	int num_nodos = 10;
	int min = MIN_ALEAT;
	int max = MAX_ALEAT;
	
	
	// .....................................................................
	// Creación de una lista
	
	// Crea una lista con num_nodos elementos conteniendo
	// números aleatorios entre min y max
	
	Lista l = ConstruyeListaAleatoria (num_nodos, min, max);
	
	// Muestra l
	
	cout << endl << ToString (l);
	
	Inserta (l, 999, 5);
	
	cout << "Número 999 insertado en la quinta posición";
	cout << endl << ToString (l);
	
	Elimina (l, 9);
	
	cout << "Noveno elemento eliminado";
	cout << endl << ToString (l);
	
	InvierteLista (l);
	
	cout << "Lista invertida";
	cout << endl << ToString (l);
}

/***************************************************************************/
/***************************************************************************/
