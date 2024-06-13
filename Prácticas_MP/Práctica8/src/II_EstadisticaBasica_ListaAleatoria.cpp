/***************************************************************************/
//
// Ejercicio 19 de la Relación de Problemas II
//
// Fichero: II_EstadisticaBasica_ListaAleatoria.cpp
//
/***************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>

#include "Lista.h"
using namespace std;


/***************************************************************************/
/***************************************************************************/
// DECLARACIÓN DE FUNCIONES ESPECÍFICAS DEL EJERCICIO
/***************************************************************************/
/***************************************************************************/
// Calcula el valor medio de los valores almacenados en una lista 
// Parámetros: l, la lista que se va a procesar. 
// Devuelve: el valor medio de los valores guardados en la lista

double Media (const Lista & l);

/***************************************************************************/
// Calcula la varianza de los valores almacenados en una lista 
// Parámetros: l, la lista que se va a procesar. 
// Devuelve: la varianza de los valores guardados en la lista

double Varianza (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// FIN DECLARACIÓN DE FUNCIONES ESPECÍFICAS DEL EJERCICIO
/***************************************************************************/
/***************************************************************************/



/***************************************************************************/
/***************************************************************************/

int main (int argc, char * argv[]) {
	
	// .....................................................................
	// Procesamiento de argumentos
	
	if (argc > 4){
		cerr << "Se esperaban 3 o menos argumentos. Uso" << endl;
		cerr << argv[0] << " <número_elementos> <mínimo_aleatorio>"
			 << "máximo aleatorio>" << endl;
		exit(1);
	}
	
	// Valores por defecto
	
	int num_nodos = 0;
	int min = MIN_ALEAT;
	int max = MAX_ALEAT;
	
	if (argc > 1)
		num_nodos = atoi (argv[1]);
		
		if (argc > 2)
			max = atoi (argv[2]);
			
			if (argc > 3)
				min = atoi (argv[3]);

	// Comprobación de la validez de argumentos
	
	if (num_nodos < 0)  // Si se introduce un número negativo, entonces
		num_nodos = 0;  // se creará una lista con 0 nodos
	
	if (min > max){
		int temp;
		temp = max;
		max = min;
		min = temp;
	}
	
	
	// .....................................................................
	// Creación de una lista
	
	// Crea una lista con num_nodos elementos conteniendo
	// números aleatorios entre min y max
	
	Lista l = ConstruyeListaAleatoria (num_nodos, min, max);
	
	// Muestra l
	
	cout << endl << ToString (l);
	
	// .....................................................................
	// Media y varianza de los elementos de la lista
	
	cout << "Media: " << Media (l) << endl;
	cout << "Varianza: " << Varianza (l) << endl;
	
	// .....................................................................
	// Ecualiza y luego rellena aleatoriamente
	
	Ecualiza (l, 0);
	
	cout << endl << ToString (l);
	
	RellenaAleatoriamente (l, min, max);
	
	cout << endl << ToString (l);
	
	// .....................................................................
	// Media y varianza de los nuevos elementos de la lista
	
	cout << "Media: " << Media (l) << endl;
	cout << "Varianza: " << Varianza (l) << endl;
}

/***************************************************************************/
/***************************************************************************/
// Calcula el valor medio de los valores almacenados en la lista 
// Recibe: un puntero al primer nodo de la lista
// Devuelve: el valor medio de los valores guardados en la lista

double Media (const Lista & l)
{
	double suma = 0.0; 
	int num_elementos = NumElementos(l);

	for (PNodo p=l; p!=0; suma+=p->info, p=p->sig);

	/*
	PNodo p=l;

	while (p != 0) {
		suma+=p->info;
		p=p->sig;
	}
	*/

	return (suma/num_elementos);
}

/***************************************************************************/
/***************************************************************************/
// Calcula la varianza de los valores almacenados en la lista 
// Recibe: un puntero al primer nodo de la lista
// Devuelve: la varianza de los valores guardados en la lista

double Varianza (const Lista & l)
{
	PNodo p = l; 
	double suma = 0.0; 
	int num_elementos = NumElementos(l);
	double media = Media (l);

	while (p!=0) {
		double dif = p->info-media;
		double sqrdif = dif*dif;
		suma+=sqrdif;
		p=p->sig;
	}
	return (suma/num_elementos);
}

/***************************************************************************/
/***************************************************************************/
