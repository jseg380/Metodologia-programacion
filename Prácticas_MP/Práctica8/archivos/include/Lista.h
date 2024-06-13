/***************************************************************************/
//
// Fichero de cabecera con declaraciones de los tipos "Nodo", "PNodo" 
// y "Lista", por un lado, y la declaración de las funciones sobre éstos. 
// Declaración de las funciones mínimas que gestionan listas simples.
// 
// Implementación en Lista.cpp
//
// Fichero: Lista.h
//
/***************************************************************************/

#ifndef LISTA
#define LISTA

#include <string>
#include "TipoBaseLista.h"

using namespace std; 


/***************************************************************************/
// Definiciones de tipos

// Cada nodo de la lista es de tipo "Nodo"

struct Nodo {	
   TipoBase info; 
   Nodo *sig; 
};

typedef Nodo * PNodo; 	// Para los punteros a nodos
typedef Nodo * Lista;	// Para la lista


/***************************************************************************/
/***************************************************************************/
// Crea una lista enlazada con "num_nodos" nodos. Inicializa todos los nodos 
// a un valor común, el indicado en el parámetro "valor". 
// La funcionalidad sería similar a la de un constructor.
// Parámetros:
//  	num_nodos, número de nodos que se van a crear. 
//		valor, valor común que se copiará en las casillas. 
// Devuelve: un dato de tipo Lista.
//
// PRE: num_nodos >= 0 
// NOTA: Si num_nodos==0 la lista queda vacía. 

Lista ConstruyeLista (int num_nodos=0, TipoBase valor=VALOR_DEF);

/***************************************************************************/
/***************************************************************************/
// "Destruye" una lista y la deja en un estado no útil (vacía). 
// La funcionalidad sería similar a la de un destructor.
// Parámetros: 
//		l (referencia), la lista que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeLista (Lista & l);

/***************************************************************************/
/***************************************************************************/
// Cambia todos los valores de la lista l y los fija todos iguales a valor.
// Parámetros: 
//	l (referencia), lista a ecualizar
//	valor, valor al que se ecualizará la lista

void Ecualiza (Lista & l, TipoBase valor=VALOR_DEF);

/***************************************************************************/
/***************************************************************************/
// Devuelve el número de nodos de una lista
// Parámetros: 
//		l (referencia), la lista que va a procesarse. 
// Devuelve: número de nodos de la lista

int NumElementos (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// Consulta si una lista está vacía (sin nodos)
// Parámetros: 
//		l (referencia), la lista que va a procesar. 
// Devuelve: true, si la lista está vacía
   
bool EstaVacia (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de ``serializar'' una lista.
// Parámetros: 
//		l (referencia), la lista que va a procesar. 

string ToString (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// Consulta ó modifica el valor de un nodo dado por su posición. 
// Si se utiliza como rvalue se emplea para consulta. Si se utiliza como 
// lvalue se emplea para modificación.
//
// Parámetros: 
//		l (referencia), la lista que va a consultar/modificar. 
//		pos, posición de la lista a la que se accede.
//
// PRE: 1<= pos <= NumElementos (l)

TipoBase & Valor (const Lista & l, int pos);

/***************************************************************************/
/***************************************************************************/
// Elimina todos los valores. 
// Al finalizar, NumElementos(l)==0 EstaVacia(l)==true. 
// La lista, aunque vacía, sigue ``activa''.

void  EliminaTodos (Lista & l);

/***************************************************************************/
/***************************************************************************/
// Añade (al final de la lista) un nodo con el valor indicado en "valor". 
//
// Parámetros:
// 		l (referencia), lista resultante.
//		valor, el valor que se añade a la lista "l"

void Aniade (Lista & l, TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Comprueba si una lista está ordenada.
// Parámetros: 
//	l (referencia) lista a comprobar
// Devuelve: true, si la lista está ordenada

bool EstaOrdenada (const Lista l);

/***************************************************************************/
/***************************************************************************/
// Ordena una lista (algoritmo de seleccion).
// Parámetros: 
//	l (referencia) lista a ordenar.

void OrdenaSeleccion (Lista & l);

/***************************************************************************/
/***************************************************************************/

#endif
