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
#include "GeneradorAleatorioEnteros.h"

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
// Crea una lista enlazada con "num_nodos" nodos. Inicializa los nodos con
// valores aleatorios comprendidos entre min y max.
// La funcionalidad sería similar a la de un constructor.
// Parámetros:
//  	num_nodos, número de nodos que se van a crear. 
//		min, extremo inferior del intervalo donde se generan números aleatorios
//		max, extremo superior del intervalo donde se generan números aleatorios
// Devuelve: un dato de tipo Lista.
//
// PRE: num_nodos >= 0
// NOTA: Si num_nodos==0 la lista queda vacía.

Lista ConstruyeListaAleatoria (int num_nodos, int min, int max){

	Lista l = ReservaMemoria (num_nodos);
	
	if (num_nodos > 0){
		
		PNodo p = l;
		GeneradorAleatorioEnteros generador(min, max);
		
		for (int i = 0 ; i <num_nodos ; i++) {
			
			p->info = generador.Siguiente();
			p = p->sig;
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

void Ecualiza (Lista & l, TipoBase valor) {
	
	// Solo si la lista no está vacía se ecualizará
	
	if (l) {  // if (l != 0) -> l == 0 <=> l == nullptr
		
		PNodo p = l; // Apunta al primer nodo
		
		// Ecualiza los nodos hasta que llegue al último de estos
		
		while (p != nullptr){
		
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
// Hace una copia profunda de origen en destino.
// Parámetros:
//		origen (referencia), la lista que va a ser copiada.
//		destino (referencia), la lista en la que se hará la copia.

void Clona (Lista & destino, const Lista & origen){
	
	// Si la lista origen está vacía no hay que hacer nada
	
	if (origen){
	
		// Libera la memoria que estaba ocupando destino
		
		LiberaMemoria (destino);
		
		// Recorre toda la lista origen copiando cada nodo en la lista destino
		
		PNodo p = origen;
		
		while (p != nullptr){
			
			Aniade (destino, p->info);
			
			p = p->sig;
		}
	}
}

/***************************************************************************/
/***************************************************************************/
// Compara dos listas, dimensiones y contenidos.
// Parámetros:
//		l1 (referencia), una lista.
//		l2 (referencia), otra lista.
// Devuelve  : true si son exactamante iguales.

bool SonIguales (const Lista & l1, const Lista & l2){
	
	bool iguales = false;
	
	// Solo se comprueba que la igualdad de sus contenidos cuando
	// ambas listas no estén vacías y tengan igual número de elementos
	
	if (l1 && l2 && (NumElementos (l1) == NumElementos (l2))){
		
		iguales = true;
		
		for (int i = 0 ; i < NumElementos (l1) && iguales ; i++){
			if (Valor (l1, i) != Valor (l2, i))
				iguales = false;
		}
	}
	// Si las dos listas están vacías "son iguales"
	else if (!l1 && !l2)
		iguales = true;
	
	return iguales;
}

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
			int num_nodos){
	
	// Manejo de errores
	
	if (pos_inic < 1 || pos_inic > NumElementos (original) || num_nodos < 0){
		pos_inic = 1;
		num_nodos = 0;
	}
	
	if ((pos_inic + num_nodos) > NumElementos (original))
		num_nodos = NumElementos (original) - pos_inic + 1;
	
	// Libera la memoria que estaba ocupando resultado
	
	LiberaMemoria (resultado);
	
	for (int i = pos_inic ; i < num_nodos + pos_inic ; i++){
		double valor;
		
		valor = Valor (original, i);
		
		Aniade (resultado, valor);
	}
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
// Cambia todos los valores de una lista existente con números aleatorios
// comprendidos entre min y max.
//
// Parámetros:
// 		l (referencia), lista que será rellenada con números aleatorios.
//		min, extremo inferior del intervalo donde se generan números aleatorios.
//		max, extremo superior del intervalo donde se generan números aleatorios.

void RellenaAleatoriamente (Lista & l, int min, int max){
	
	// Si la lista está vacía no hay que hacer nada
	
	if (l){
		
		PNodo p = l;	// p apunta al principio de la lista
		
		GeneradorAleatorioEnteros generador (min, max);
		
		while (p != nullptr){
			
			p->info = generador.Siguiente();
			
			p = p->sig;
		}
	}
}

/***************************************************************************/
/***************************************************************************/
// Elimina el nodo que se encuentra en la posición pos. 
// Parámetros:
// 		l (referencia), lista resultante.
//		pos, la posición que va a ser eliminada.
// PRE:  1 <= pos <= NumElementos (l)

void Elimina (Lista & l, int pos){
	
	// Si la lista está vacía o la posición es incorrecta no se hace nada
	
	if (l && pos >= 1 && pos <= NumElementos (l)){
		PNodo p = l;
		
		// Llega hasta el nodo anterior al que quiere eliminar
		for (int i = 1 ; i < pos - 1 ; i++)
			p = p->sig;
		
		// Variable temporal en la que se almacenará la dirección del nodo
		PNodo temp = p->sig;
		
		p->sig = temp->sig;
		
		delete temp;
	}
}

/***************************************************************************/
/***************************************************************************/
// Inserta un nodo con el valor indicado en valor en la posición pos.
// Parámetros:
// 		l (referencia), lista resultante.
//		valor, el valor que contendrá el nuevo nodo.
//		pos, la posición en la que se insertará el nodo.
// PRE:  1 <= pos <= NumElementos (l)
// Nota: Si pos > NumElementos (l) se añadirá el elemento usando Aniade
// Nota: Si pos < 1 entonces se insertará el elemento en la posición 1

void Inserta (Lista & l, TipoBase valor, int pos){
	
	// Si pos < 1 se insertará el elemento en la posición 1
	
	if (pos < 1)
		pos = 1;
	
	PNodo p_nodo_nuevo = new Nodo;
	p_nodo_nuevo->info = valor;
	
	if (pos == 1){
		p_nodo_nuevo->sig = l;
		l = p_nodo_nuevo;
	}
	
	// Si la lista no está vacía y la posición del nodo a insertar no es mayor
	// que el número de elementos de la lista se inserta
	
	else if (l && pos < NumElementos (l)){
		PNodo p = l;
		
		// Llega hasta el nodo anterior de donde se insertará el nuevo nodo
		for (int i = 1 ; i < pos - 1 ; i++)
			p = p->sig;
		
		// Variable temporal en la que se almacena la dirección del nodo
		PNodo temp = p->sig;
		
		p->sig = p_nodo_nuevo;
		p_nodo_nuevo->sig = temp;
		
		
	}
	// Si la lista está vacía o pos > NumElementos (l) se añade
	
	else if (!l || pos > NumElementos (l))
		Aniade (l, valor);
}

/***************************************************************************/
/***************************************************************************/
// Invierte una lista.
// Parámetros:
// 		l (referencia), lista resultante.

void InvierteLista(Lista & l){
	PNodo actual = l;
	PNodo anterior = nullptr;
	PNodo siguiente = nullptr;

	while (actual != nullptr) {
		siguiente = actual->sig;

		actual->sig = anterior;

		anterior = actual;
		actual = siguiente;
	}
	
	l = anterior;
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

