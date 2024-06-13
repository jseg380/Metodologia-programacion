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
// Crea una lista enlazada con "num_nodos" nodos. Inicializa los nodos con
// valores aleatorios comprendidos entre min y max.
// La funcionalidad sería similar a la de un constructor.
// Parámetros:
//  	num_nodos, número de nodos que se van a crear. 
//		min, extremo inferior del intervalo donde se generan números aleatorios.
//		max, extremo superior del intervalo donde se generan números aleatorios.
// Devuelve: un dato de tipo Lista.
//
// PRE: num_nodos >= 0
// NOTA: Si num_nodos==0 la lista queda vacía.

Lista ConstruyeListaAleatoria (int num_nodos=0, int min=MIN_ALEAT, 
							   int max=MAX_ALEAT);

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

void EliminaTodos (Lista & l);

/***************************************************************************/
/***************************************************************************/
// Hace una copia profunda de origen en destino.
// Parámetros:
//		origen (referencia), la lista que va a ser copiada.
//		destino (referencia), la lista en la que se hará la copia.

void Clona (Lista & destino, const Lista & origen);

/***************************************************************************/
/***************************************************************************/
// Compara dos listas, dimensiones y contenidos.
// Parámetros:
//		l1 (referencia), una lista.
//		l2 (referencia), otra lista.
// Devuelve  : true si son exactamante iguales.

bool SonIguales (const Lista & l1, const Lista & l2);

/***************************************************************************/
/***************************************************************************/
// Extrae una lista de original y la deja en resultado . La lista 
// resultado es una copia de una parte de original formada por un 
// máximo de num_nodos nodos, formada a partir del nodo que ocupa 
// la posición pos_inic de original.
// Parámetros:
//		original (referencia), lista de la que se extraerá una sublista.
//		resultado (referencia), sublista extraída de original.
//		pos_inic, posición desde la que se empieza a fabricar la sublista.
//		num_nodos, máxima cantidad de nodos que tendrá la sublista.

void SubLista (Lista & resultado, const Lista & original, int pos_inic, 
			int num_nodos);

/***************************************************************************/
/***************************************************************************/
// Añade (al final de la lista) un nodo con el valor indicado en "valor". 

// Parámetros:
// 		l (referencia), lista resultante.
//		valor, el valor que se añade a la lista "l"

void Aniade (Lista & l, TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Cambia todos los valores de una lista existente con números aleatorios
// comprendidos entre min y max.
// Parámetros:
// 		l (referencia), lista que será rellenada con números aleatorios.
//		min, extremo inferior del intervalo donde se generan números aleatorios.
//		max, extremo superior del intervalo donde se generan números aleatorios.

void RellenaAleatoriamente (Lista & l, int min = MIN_ALEAT, 
							int max = MAX_ALEAT);

/***************************************************************************/
/***************************************************************************/
// Elimina el nodo que se encuentra en la posición pos. 
// Parámetros:
// 		l (referencia), lista resultante.
//		pos, la posición que va a ser eliminada.
// PRE:  1 <= pos <= NumElementos (l)

void Elimina (Lista & l, int pos);

/***************************************************************************/
/***************************************************************************/
// Inserta un nodo con el valor indicado en valor en la posición pos.
// Parámetros:
// 		l (referencia), lista resultante.
//		valor, el valor que contendrá el nuevo nodo.
//		pos, la posición en la que se insertará el nodo.
// PRE:  1 <= pos <= NumElementos (l)
// Nota: Si pos > NumElementos (l) se añadirá el elemento usando Aniade

void Inserta (Lista & l, TipoBase valor, int pos);

/***************************************************************************/
/***************************************************************************/
// Invierte una lista.
// Parámetros:
// 		l (referencia), lista resultante.

void InvierteLista (Lista & l);

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
