/***************************************************************************/
//
// Implementación de las funciones que gestionan listas simples.
//
// Declaraciones en Lista.h
//
// Fichero: Lista.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "Lista.h"
#include "TipoBaseLista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// DECLARACIÓN DE FUNCIONES "PRIVADAS"
/***************************************************************************/
/***************************************************************************/
// Reserva memoria para "num_nodos" nodos.
// El contenido de los nodos queda INDEFINIDO.
// Parámetros:
//  	num_nodos, número de nodos que se van a crear. 
// Devuelve: un dato Lista (una lista enlazada con "num_nodos" nodos con 
//		valor indefinido. 
//
// PRE: num_nodos >= 0 
// NOTA: Si num_nodos==0 la lista queda vacía. 

Lista ReservaMemoria (int num_nodos=0);

/***************************************************************************/
// Libera la memoria ocupada por una lista. 
// Parámetros: 
//		l (referencia), la lista que va a "liberarse". 
// POST: La lista queda vacía.

void LiberaMemoria (Lista & l);

/***************************************************************************/
/***************************************************************************/
// FIN DECLARACIÓN DE FUNCIONES "PRIVADAS"
/***************************************************************************/
/***************************************************************************/


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

Lista ConstruyeLista (int num_nodos, TipoBase valor)
{
	Lista l = ReservaMemoria (num_nodos); 

	if (num_nodos > 0) {

		PNodo p = l; // "p" apunta al primer nodo

		// Rellenar todos los nodos con "valor" 

		for (int i=0; i<num_nodos; i++) {

			p->info = valor; 
			p = p->sig; // Avanzar "p"
		}
	}

	return l; 
}

/***************************************************************************/
/***************************************************************************/
// "Destruye" una lista y la deja en un estado no útil (vacía). 
// La funcionalidad sería similar a la de un destructor.
// Parámetros: 
//		l (referencia), la lista que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeLista (Lista & l)
{
  	LiberaMemoria (l); 
}

/***************************************************************************/
/***************************************************************************/
// Cambia todos los valores de la lista l y los fija todos iguales a valor.
// Parámetros: 
//	l (referencia), lista a ecualizar
//	valor, valor al que se ecualizará la lista

void Ecualiza (Lista & l, TipoBase valor=VALOR_DEF) {
	
	// Solo si la lista no está vacía se ecualizará
	
	if (l) {  // if (l != 0) -> l == 0 <=> l == nullptr
		
		PNodo p = l; // Apunta al primer nodo
		
		// (*p).info = valor HASTA que encuentre un (*p).sig == nulptr
		
		while (p->sig != nullptr){
		
			p->info = valor;
			
			p = p->sig;
		}
	}
}

/***************************************************************************/
/***************************************************************************/
// Devuelve el número de nodos de una lista
// Parámetros: 
//		l (referencia), la lista que va a procesar. 
// Devuelve: número de nodos de la lista

int NumElementos (const Lista & l)
{
	int contador = 0; 

	for (PNodo p=l; p!=nullptr; contador++, p=p->sig);

	return contador;
}

/***************************************************************************/
/***************************************************************************/
// Consulta si una lista está vacía (sin nodos)
// Parámetros: 
//		l (referencia), la lista que va a procesarse. 
// Devuelve: true, si la lista está vacía
   
bool EstaVacia (const Lista & l)
{
	return (l==nullptr);	
}
 
/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de ``serializar'' una lista.
// Parámetros: 
//		l (referencia), la lista que va a procesar. 

string ToString (const Lista & l)
{
	int num_elementos = NumElementos(l);
	string cad; 
	cad = cad + "Num. nodos = " + to_string(num_elementos) + "\n";

	if (num_elementos > 0)  {

		cad = cad + "Valores almacenados en la lista: \n"; 
		cad = cad + "{ ";

		PNodo p; 
		int pos = 1;

		for (p=l, pos=1; pos<num_elementos; pos++, p=p->sig)
			cad = cad + to_string(p->info) + ", "; 
		
		cad = cad + to_string(p->info) + "}"; // Último nodo 
	}
	else 
		cad = cad + "Lista vacia";

	cad = cad + "\n\n";

	return cad;
}

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
// PRE: 1 <= pos <= NumElementos (l)

TipoBase & Valor (const Lista & l, int pos)
{
	int num_elementos = NumElementos(l);

	PNodo p = l; 
	for (int posic=1; posic<pos; posic++) p=p->sig;

	return p->info; 
}

/***************************************************************************/
/***************************************************************************/
// Elimina todos los valores. 
// Al finalizar, NumElementos(l)==0 EstaVacia(l)==true. 
// La lista, aunque vacía, sigue ``activa''.

void  EliminaTodos (Lista & l)
{
	LiberaMemoria (l); 
}

/***************************************************************************/
/***************************************************************************/
// Añade (al final de la lista) un nodo con el valor indicado en "valor". 
//
// Parámetros:
// 		l (referencia), lista resultante.
//		valor, el valor que se añade a la lista "l"

void Aniade (Lista & l, TipoBase valor)
{
	// Crear un nodo (será el último) y rellenarlo
	PNodo p_nodo_nuevo = new Nodo; 
	p_nodo_nuevo->info = valor; 	 
	p_nodo_nuevo->sig  = nullptr; 
 
	// Buscar el último nodo de la lista

	PNodo p = l; 

	if (l) { // lista no vacía 

		while (p->sig) p = p->sig; // Avanzar hasta llegar al último nodo
		p->sig = p_nodo_nuevo; 

	}
	else { // Lista vacía: el nuevo nodo será el primero

		l = p_nodo_nuevo; 
	}
}

/***************************************************************************/
/***************************************************************************/



/***************************************************************************/
/***************************************************************************/
//
// FUNCIONES DE ORDENACIÓN
//
/***************************************************************************/
/***************************************************************************/
// Comprueba si una lista está ordenada.
// Parámetros: 
//	l (referencia) lista a comprobar
// Devuelve: true, si la lista está ordenada

bool EstaOrdenada (const Lista l)
{
	PNodo p = l; 
	TipoBase anterior; 

	if (p) { // si hay al menos un nodo
		anterior = p->info; //  valor del primer nodo
		p = p->sig;		    //  apuntar al segundo
	}
	
	bool ordenada = true; // por defecto, una lista vacia esta ordenada

	while (p && ordenada) {
		
		if (p->info >= anterior) {
			anterior = p->info;
			p = p->sig;			 //  apuntar al segundo
		}
		else ordenada = false; 
	}
	
	return (ordenada);
}

/***************************************************************************/
/***************************************************************************/
// Ordena una lista (algoritmo de seleccion).
// Parámetros: 
//	l (referencia) lista a ordenar.

void OrdenaSeleccion (Lista & l)
{
	if (l) { // Lista no vacía --> si la lista esta vacia, no se hace nada

		PNodo primero = l; // marca el inicio de la parte NO ordenada
		
		while (primero->sig != nullptr) {

			// El primer menor es el primer elemento de la parte no ordenada

			TipoBase val_min = primero->info; 
			PNodo    pos_min = primero;           

			// Para buscar el menor de la parte no ordenada

			PNodo p = primero->sig;  

			while (p!=nullptr) {

				if (p->info < val_min) {   // se encuentra un nuevo menor
					val_min = p->info;
					pos_min = p;
				}
				p = p->sig;  // se sigue avanzando
			}

			// Intercambio: el menor pasa a ocupar la posicion marcada 
			// por el puntero "primero"
			  
			TipoBase tmp = primero->info; 
			primero->info = pos_min->info;
			pos_min->info = tmp; 

			primero = primero->sig; // avanza la parte no ordenada
		
		} // while (primero->sig != 0)
		
	} // if (l!=0)
	
}

/***************************************************************************/
/***************************************************************************/



/***************************************************************************/
/***************************************************************************/
//
// FUNCIONES "PRIVADAS"
//
/***************************************************************************/
/***************************************************************************/
// Reserva memoria para "num_nodos" nodos.
// El contenido de los nodos queda INDEFINIDO.
// Parámetros:
//  	num_nodos, número de nodos que se van a crear. 
// Devuelve: un dato Lista (una lista enlazada con "num_nodos" nodos con 
//		valor indefinido. 
//
// PRE: num_nodos >= 0 
// NOTA: Si num_nodos==0 la lista queda vacía. 

Lista ReservaMemoria (int num_nodos)
{
	Lista l = nullptr; // Lista vacía 

	if (num_nodos > 0) {

		l = new Nodo;  // Pedir memoria para el primer nodo 

		PNodo p = l; // "p" apunta al primer nodo

		// Pedir memoria para el resto de los nodos 

		for (int i=1; i<num_nodos; i++) {

			p->sig = new Nodo;  // Pedir memoria para un nuevo nodo 
			p = p->sig; // Avanzar "p"
		}

		p->sig = nullptr;
	}

	return l; 
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por una lista. 
// Parámetros: 
//		l (referencia), la lista que va a "liberarse". 
// POST: La lista queda vacía.

void LiberaMemoria (Lista & l)
{
 	if (l != nullptr) { // Importante: prevenir de la lista vacía

        PNodo p = l; // Colocar "p" al principio

        while (p->sig != nullptr) {
            p = p->sig;   // Adelantar "p"
            delete l;     // Borrar el primero
            l = p;        // Actualizar "l"
        }
        
        delete l; // Borrar el único nodo que queda
    }

    l = nullptr; // El puntero que da acceso a la lista queda con valor 0
}

/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// FIN FUNCIONES "PRIVADAS"
/***************************************************************************/
/***************************************************************************/

