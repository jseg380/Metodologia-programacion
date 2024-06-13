/***************************************************************************/
//
// Fichero de cabecera con declaraciones de los tipos "Nodo", "PNodo" 
// y "Lista", por un lado, y la declaraci�n de las funciones sobre �stos. 
// Declaraci�n de las funciones m�nimas que gestionan listas simples.
// 
// Implementaci�n en Lista.cpp
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
// a un valor com�n, el indicado en el par�metro "valor". 
// La funcionalidad ser�a similar a la de un constructor.
// Par�metros:
//  	num_nodos, n�mero de nodos que se van a crear. 
//		valor, valor com�n que se copiar� en las casillas. 
// Devuelve: un dato de tipo Lista.
//
// PRE: num_nodos >= 0 
// NOTA: Si num_nodos==0 la lista queda vac�a. 

Lista ConstruyeLista (int num_nodos=0, TipoBase valor=VALOR_DEF);

/***************************************************************************/
/***************************************************************************/
// Crea una lista enlazada con "num_nodos" nodos. Inicializa los nodos con
// valores aleatorios comprendidos entre min y max.
// La funcionalidad ser�a similar a la de un constructor.
// Par�metros:
//  	num_nodos, n�mero de nodos que se van a crear. 
//		min, extremo inferior del intervalo donde se generan n�meros aleatorios.
//		max, extremo superior del intervalo donde se generan n�meros aleatorios.
// Devuelve: un dato de tipo Lista.
//
// PRE: num_nodos >= 0
// NOTA: Si num_nodos==0 la lista queda vac�a.

Lista ConstruyeListaAleatoria (int num_nodos=0, int min=MIN_ALEAT, 
							   int max=MAX_ALEAT);

/***************************************************************************/
/***************************************************************************/
// "Destruye" una lista y la deja en un estado no �til (vac�a). 
// La funcionalidad ser�a similar a la de un destructor.
// Par�metros: 
//		l (referencia), la lista que va a "destruirse". 
// POST: La matriz queda vac�a (todos sus campos a cero)

void DestruyeLista (Lista & l);

/***************************************************************************/
/***************************************************************************/
// Cambia todos los valores de la lista l y los fija todos iguales a valor.
// Par�metros: 
//	l (referencia), lista a ecualizar
//	valor, valor al que se ecualizar� la lista

void Ecualiza (Lista & l, TipoBase valor=VALOR_DEF);

/***************************************************************************/
/***************************************************************************/
// Devuelve el n�mero de nodos de una lista
// Par�metros: 
//		l (referencia), la lista que va a procesarse. 
// Devuelve: n�mero de nodos de la lista

int NumElementos (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// Consulta si una lista est� vac�a (sin nodos)
// Par�metros: 
//		l (referencia), la lista que va a procesar. 
// Devuelve: true, si la lista est� vac�a
   
bool EstaVacia (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de ``serializar'' una lista.
// Par�metros: 
//		l (referencia), la lista que va a procesar. 

string ToString (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// Consulta � modifica el valor de un nodo dado por su posici�n. 
// Si se utiliza como rvalue se emplea para consulta. Si se utiliza como 
// lvalue se emplea para modificaci�n.
//
// Par�metros: 
//		l (referencia), la lista que va a consultar/modificar. 
//		pos, posici�n de la lista a la que se accede.
//
// PRE: 1<= pos <= NumElementos (l)

TipoBase & Valor (const Lista & l, int pos);

/***************************************************************************/
/***************************************************************************/
// Elimina todos los valores. 
// Al finalizar, NumElementos(l)==0 EstaVacia(l)==true. 
// La lista, aunque vac�a, sigue ``activa''.

void EliminaTodos (Lista & l);

/***************************************************************************/
/***************************************************************************/
// Hace una copia profunda de origen en destino.
// Par�metros:
//		origen (referencia), la lista que va a ser copiada.
//		destino (referencia), la lista en la que se har� la copia.

void Clona (Lista & destino, const Lista & origen);

/***************************************************************************/
/***************************************************************************/
// Compara dos listas, dimensiones y contenidos.
// Par�metros:
//		l1 (referencia), una lista.
//		l2 (referencia), otra lista.
// Devuelve  : true si son exactamante iguales.

bool SonIguales (const Lista & l1, const Lista & l2);

/***************************************************************************/
/***************************************************************************/
// Extrae una lista de original y la deja en resultado . La lista 
// resultado es una copia de una parte de original formada por un 
// m�ximo de num_nodos nodos, formada a partir del nodo que ocupa 
// la posici�n pos_inic de original.
// Par�metros:
//		original (referencia), lista de la que se extraer� una sublista.
//		resultado (referencia), sublista extra�da de original.
//		pos_inic, posici�n desde la que se empieza a fabricar la sublista.
//		num_nodos, m�xima cantidad de nodos que tendr� la sublista.

void SubLista (Lista & resultado, const Lista & original, int pos_inic, 
			int num_nodos);

/***************************************************************************/
/***************************************************************************/
// A�ade (al final de la lista) un nodo con el valor indicado en "valor". 

// Par�metros:
// 		l (referencia), lista resultante.
//		valor, el valor que se a�ade a la lista "l"

void Aniade (Lista & l, TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Cambia todos los valores de una lista existente con n�meros aleatorios
// comprendidos entre min y max.
// Par�metros:
// 		l (referencia), lista que ser� rellenada con n�meros aleatorios.
//		min, extremo inferior del intervalo donde se generan n�meros aleatorios.
//		max, extremo superior del intervalo donde se generan n�meros aleatorios.

void RellenaAleatoriamente (Lista & l, int min = MIN_ALEAT, 
							int max = MAX_ALEAT);

/***************************************************************************/
/***************************************************************************/
// Elimina el nodo que se encuentra en la posici�n pos. 
// Par�metros:
// 		l (referencia), lista resultante.
//		pos, la posici�n que va a ser eliminada.
// PRE:  1 <= pos <= NumElementos (l)

void Elimina (Lista & l, int pos);

/***************************************************************************/
/***************************************************************************/
// Inserta un nodo con el valor indicado en valor en la posici�n pos.
// Par�metros:
// 		l (referencia), lista resultante.
//		valor, el valor que contendr� el nuevo nodo.
//		pos, la posici�n en la que se insertar� el nodo.
// PRE:  1 <= pos <= NumElementos (l)
// Nota: Si pos > NumElementos (l) se a�adir� el elemento usando Aniade

void Inserta (Lista & l, TipoBase valor, int pos);

/***************************************************************************/
/***************************************************************************/
// Invierte una lista.
// Par�metros:
// 		l (referencia), lista resultante.

void InvierteLista (Lista & l);

/***************************************************************************/
/***************************************************************************/
// Comprueba si una lista est� ordenada.
// Par�metros: 
//	l (referencia) lista a comprobar
// Devuelve: true, si la lista est� ordenada

bool EstaOrdenada (const Lista l);

/***************************************************************************/
/***************************************************************************/
// Ordena una lista (algoritmo de seleccion).
// Par�metros: 
//	l (referencia) lista a ordenar.

void OrdenaSeleccion (Lista & l);

/***************************************************************************/
/***************************************************************************/

#endif
