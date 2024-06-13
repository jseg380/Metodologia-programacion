/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
//
// Clase "Lista"
//
// Definición de la clase Lista (versión 1).
// Declaraciones en Lista.h
//
// Incluye: 
//		* constructor de copia
//		* destructor 
//
// Fichero: Lista.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

#include "TipoBase_Lista.h"
#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Constructor unificado:
//	a) Constructor sin argumentos, que crea una lista vacía.
//  b) Constructor con un argumento, que crea una lista con un número de 
//		nodos indicado en el argumento.
//	c) Constructor con dos argumentos, que crea una lista con un número 
//		de nodos indicado en el primer argumento. Inicia todos los nodos 
//		de la lista al valor indicado en el segundo argumento.
//
// Crea una lista enlazada con "num_nodos" nodos. Inicializa todos 
// los nodos a un valor común, el indicado en el parámetro "valor". 
// Parámetros:
//  	num_nodos, número de nodos que se van a crear. 
//		valor, valor común que se copiará en las casillas. 
// Devuelve: un dato de tipo Lista.
//
// PRE:  num_nodos >= 0 
// NOTA: Si num_nodos==0 la lista queda vacía. 

Lista :: Lista (int num_nodos, TipoBaseLista valor) 
               : primero(0), tamanio(num_nodos)
{
	ReservarMemoria (tamanio);
	Ecualiza (valor);
}

/***************************************************************************/		
// Constructor de copia

Lista :: Lista (const Lista & otro)
{	
	// Reservar memoria para los nodos de la lista
	ReservarMemoria (otro.tamanio);

	// Copiar campos privados y los valores de la lista
	CopiarDatos (otro);
}		
	
/***************************************************************************/
// Destructor
Lista :: ~Lista (void)
{
    LiberarMemoria ();
}

/***************************************************************************/
// Consulta si la lista esta vacia
// Devuelve: true si la lista esta vacia. 

bool Lista :: EstaVacia(void) const
{
	return (tamanio == 0);
}	

/***************************************************************************/
// Devuelve el número de nodos de la lista

int Lista :: Tamanio(void)	const
{
	return tamanio;
}

/***********************************************************************/
/***********************************************************************/
// Elimina todos los valores de la lista. 
// POST: EstaVacia() == true

void Lista :: EliminaTodos (void)
{
    LiberarMemoria ();
}

/***************************************************************************/
/***************************************************************************/
// Ecualizar una lista: cambia todos los todos valores de la lista y los 
// fija todos iguales e iguales a "valor".
// Parámetros: valor, el valor común  que se escribirá en todos  
//					los nodos (por defecto, VALOR_DEF_LISTA)

void Lista :: Ecualiza (const TipoBaseLista valor)
{
	TipoNodo * p = primero; // Apuntar al primero.

	for(int i = 0; i < tamanio; i++) {
		p->info = valor; // Inicializar nodo.
		p = p->sig;		 // Adelantar "p".
	}						
}

/***********************************************************************/
/***********************************************************************/
// Devuelve un string con el resultado de "serializar" una lista.
// Parámetros: msg, mensaje que precede al contenido de la lista. 

string Lista :: ToString (const char * const msg)
{
	string cad = "--------------------------------------------------\n";
	cad = cad + msg + "\n";
	cad = cad + "Num. nodos = " + to_string(tamanio) + "\n";

	if (tamanio > 0)  {

		cad = cad + "Valores almacenados en la lista: \n"; 
		cad = cad + "{ ";

		TipoNodo * p; 
		int pos;

		// Se evita el último nodo 

		for (p=primero, pos=1; pos<tamanio; pos++, p=p->sig)  {
			#ifdef INT
			cad = cad + to_string(p->info);	
			#else
			#ifdef CHAR
			cad = cad + p->info;	
			#else
			#ifdef DOUBLE
			cad = cad + to_string(p->info);	
			#endif
			#endif
			#endif

			cad = cad + ", ";
		}
			
		// Ultimo nodo

		#ifdef INT
		cad = cad + to_string(p->info);	
		#else
		#ifdef CHAR
		cad = cad + p->info;	
		#else
		#ifdef DOUBLE
		cad = cad + to_string(p->info);	
		#endif
		#endif
		#endif
 
		cad = cad + "}\n";  
	}
	else 
		cad = cad + "Lista vacia\n";

	cad = cad + "--------------------------------------------------\n\n";

	return cad;
}


/***********************************************************************/
/***********************************************************************/
// Consulta ó modifica el valor de un nodo dado por su posición. 
// Si se utiliza como rvalue se emplea para consulta. Si se utiliza  
// como lvalue se emplea para modificación.
//
// Parámetros: pos, la posición (número de nodo) a la que se accede.  	
// 		El criterio seguido para especificar una posicion será : 
// 		1 -> primero, 2 -> segundo,...
//
// PRE: 1 <= pos <= l.Tamanio()

TipoBaseLista & Lista :: Valor (int pos)
{
	return el_valor(pos); 
}

TipoBaseLista & Lista :: Valor (int pos) const
{
	return el_valor(pos); 
}

/***************************************************************************/
/***************************************************************************/
// Busca la posición de un nodo dado un valor especificado. 
// Parámetros: valor, el valor buscado. 
// Devuelve la posición del primer nodo coincidente, 
// 		o -1 si no se encuentra.

int Lista :: Buscar (TipoBaseLista valor) const
{
    TipoNodo * p = primero;

    bool sigo = true;
    bool encontrado = false;

	int pos = 0;
    	
    while ((p!=0) && sigo) {
    	
		pos++; // Actualizar posición

        if (p->info == valor) {
            sigo = false;
            encontrado = true;
        }
        else 
            p = p->sig;
	}
	
	return (encontrado ? (pos) : -1); 
}	

/***************************************************************************/
/***************************************************************************/
// Método para hacer una copia profunda desde la lista explícita 
// "otra" en la lista implícita.
// Parámetros: otra (referencia), referencia al objeto explícito
// El contenido de la lista implícita se pierde, se sustituye por una  
// copia del contenido de "origen". 

void Lista :: Clona (const Lista & otra) {

	// Limpiar la lista implícita
	LiberarMemoria ();

	int num_nodos = otra.tamanio;

	// Pedir memoria para poder recibir los datos de "origen" 
	ReservarMemoria (num_nodos); 

	// Copiar valor a valor 

	TipoNodo * p_origen  = otra.primero;  // Apunta al primer nodo de "otra"
	TipoNodo * p_destino = primero; // Apunta al primer nodo de la lista implícita

	for (int pos=1; pos<=num_nodos; pos++) {
		
		p_destino->info = p_origen->info; // Copiar valor

		p_origen  = p_origen->sig;   // Adelantar 
		p_destino = p_destino->sig;	 // punteros 
	}
}

/***************************************************************************/
/***************************************************************************/
// Método para comparar dos listas. Devuelve true si las listas 
// implícita y "otra" son exactamente iguales (dimensiones y contenidos).
// Parámetros: otra (referencia), referencia al objeto explícito
// Devuelve "true" i las listas implícita y "otra" son exactamente 
// iguales (dimensiones y contenidos).

bool Lista :: EsIgualA (const Lista & otra) const
{
	int num_nodos_una  = tamanio;
	int num_nodos_otra = otra.tamanio;

	bool dimensiones_iguales  = (num_nodos_una == num_nodos_otra);

	bool iguales = false; 

	// Si las dimensiones coinciden podemos seguir. Si no coinciden entonces 
	// son diferentes (en ese caso no entra al if pero nos hemos asegurado 
	// que "iguales" vale false). 

	if (dimensiones_iguales) {

		// La comprobación se hará con un ciclo while para salir cuando se 
		// encuentre una discrepancia entre "una" y "otra". 

		TipoNodo * p_una  = primero;  // Al primer nodo de la lista implícita
		TipoNodo * p_otra = otra.primero; // Al primer nodo de "otra"

		bool sigo = true;

		while (p_una && sigo) {

			if (p_una->info != p_otra->info) sigo = false;
			else {
				p_una  = p_una->sig;	// Adelantar 
				p_otra = p_otra->sig;	// punteros 
			}

		} // while 

		// En este punto, si "sigo" no ha cambiado de valor (inicialmente 
		// true) es porque no ha encontrado diferencias, por lo que cambiamos 
		// el valor de "iguales" para hacerlo true (estaba fijado a false).
		// Si "sigo" es false (se encontró alguna diferencia) el valor de 
		// "iguales" no se cambia y sigue a false. 

		if (sigo) iguales = true;
	}

	return iguales;	
}

/***************************************************************************/
/***************************************************************************/
// Añade (al final de la lista) un nodo con el valor indicado en "valor". 
//
// Parámetros:
//		valor, el valor que se añade a la lista 

void  Lista :: Aniadir (TipoBaseLista valor)
{
	// Crear un nuevo (último) nodo y rellenar sus campos
	TipoNodo * nuevo = new TipoNodo;
	nuevo->info = valor;
	nuevo->sig = 0;

	if (primero != 0) {  // La lista no está vacía

		// Buscar el último nodo
		TipoNodo * p = primero;
		
		for(int i=1; i<tamanio; i++)
			p = p->sig;

		// "p" apunta al último nodo	
					
		p->sig = nuevo;
	}
	else { // La lista estaba vacía
		primero = nuevo; 
	}
	
	tamanio++;
}

/***************************************************************************/
/***************************************************************************/
// Inserta un nuevo elemento en la posición "pos_insertar"
// PRE: 1 <= pos_insertar <= tamanio+1
// El criterio seguido para especificar una posicion será : 
// 1 -> primero, 2 -> segundo,...
// Nota: Si pos_insertar == tamanio+1, el resultado es idéntico a la 
// 		 ejecución del método Aniadir()

void Lista :: Insertar (TipoBaseLista valor, int pos_insertar)
{
	TipoNodo * ant = primero;
	TipoNodo * resto = primero;

	// Crear el nodo que se va a insertar e iniciarlo
	TipoNodo * nuevo = new TipoNodo; 
	nuevo->info = valor; 

	// Buscar el sitio que le corresponde 
	for (int i=1; i<pos_insertar; i++) { 
		ant = resto; 
		resto = resto->sig;
	}

	if (pos_insertar==1)   // El nuevo nodo sera el primero 
		primero = nuevo;
	else		  // Enlazar el nuevo con el anterior 
		ant->sig = nuevo;

	nuevo->sig = resto; // Enlazar el nuevo nodo con el resto

	tamanio++; // Actualizar tamanio
}
	
/***************************************************************************/
/***************************************************************************/
// Borra el elemento de la posición "pos_borrar" 
// PRE: 1 <= pos_borrar <= tamanio
// El criterio seguido para especificar una posicion será : 
// 1 -> primero, 2 -> segundo,...

void Lista :: Eliminar (int pos_borrar)
{
	TipoNodo * ant = primero;
	TipoNodo * pos = primero;

	// Colocar "ant" y "act" 
	for (int i=1; i<pos_borrar; i++) { 
		ant = pos; 
		pos = pos->sig;
	}

	// "pos" apunta al nodo que se va a borrar
	// "ant" apunta al nodo anterior

	if (pos_borrar==1)   // Saltar el primero 
		primero = primero->sig;
	else 
		ant->sig = pos->sig;
		// Enlazar el anterior con el siguiente 

	delete pos; // Borrar nodo
	
	tamanio--;  // Actualizar tamanio
}

/***************************************************************************/
/***************************************************************************/
// Borra el primer nodo que contiene el valor elemento de "pos" 
//
// PRE: 1 <= pos <= NumElementos(l)
// El criterio seguido para especificar una posicion será: 
// 1 -> primero, 2 -> segundo,...

void Lista :: EliminarValor (TipoBaseLista valor)
{
	int pos = Buscar (valor);

	// Si pos > 0 se encontró el alumno buscado: eliminarlo
	if (pos > 0) Eliminar (pos);
}



/***************************************************************************/
/***************************************************************************/
// MÉTODOS QUE RECIBEN/DEVUELVEN LISTAS
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// Construye y devuelve sublista de lista implícita.
// La sublista devuelta es una copia de una parte de "original" formada 
// por un máximo de "num_nodos" nodos, formada a partir del nodo que 
// ocupa la posición "pos_inic" de "original". 
//
// Parámetros:
//		pos_inic, posición de "original" a partir d ela que se va a 
//			realizar la copia.
//		num_nodos, número (máximo) de nodos a extraer.
//
// PRE: 1 <= pos_inic < NumElementos(original)
// PRE: 0 <= num_nodos
// 		Si no se cumplen, la lista devuelta es una lista vacía.

Lista Lista :: SubLista (int pos_inic, int num_nodos)
{
	Lista sublista; // Vacía

	// Comprobar que no sean casos erroneos (se cumplen las precondiciones) 

	if (1<=pos_inic && pos_inic<=tamanio &&  0<=num_nodos)  {

		int pos_fin = ((pos_inic+num_nodos-1)<=tamanio) ? 
					    pos_inic+num_nodos-1 : tamanio;

		// Número de nodos de la sublista que se va a crear.
		int num_nodos_res = pos_fin-pos_inic+1;

		// Reserva memoria para la lista resultado.  
		Lista resultado (num_nodos_res);

		// Posicionar un puntero en la casilla "pos_inic" de "orig"

		TipoNodo * p_original = primero; 
		for (int pos=1; pos<pos_inic; pos++) p_original = p_original->sig;

		// Copia, valor a valor, desde "original" a "resultado".

		TipoNodo * p_resultado = resultado.primero; 
		for (int pos=pos_inic; pos<=pos_fin; pos++) {

			p_resultado->info = p_original->info; // Copiar valor

			p_original = p_original->sig;	// Adelantar 
			p_resultado = p_resultado->sig; // punteros
		}

		// Copiar la matriz "resultado" en "submatriz"
		sublista.Clona(resultado); 

	} // if (1<=pos_inic && pos_inic<=NumElementos(original) &&  0<=num_nodos)

	return (sublista);

}




/***************************************************************************/
/***************************************************************************/
// METODOS PRIVADOS
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// Pide memoria para "num_elementos" nodos
// PRE: num_elementos > 0

void  Lista :: ReservarMemoria (int num_elementos)
{
	if (num_elementos > 0) {
		
		primero = new TipoNodo;		// Crear primer nodo.

		TipoNodo * ultimo = primero; // Apuntar al último.
		TipoNodo * p;

		for (int i = 1; i < num_elementos; i++) {

			p = new TipoNodo;	// Crear un nodo.
			ultimo->sig = p;	// Enlazar el nuevo nodo. 
			ultimo = p;			// Pasa a ser el último.
		}						

		ultimo->sig = 0; // Finalizar la lista

		tamanio = num_elementos;
	} 
	else { // Lista vacía

		primero = 0; // MUY IMPORTANTE
		tamanio = 0;
	}
}

/***************************************************************************/
/***************************************************************************/
// Liberar memoria

void  Lista :: LiberarMemoria (void)
{
	if (primero !=0) {
		
		TipoNodo *p = primero; // Colocar "p" al principio

		while (primero->sig != 0) {

			primero = primero->sig;  // Nuevo "primero"
			delete p;     // Borrar el antiguo primero
			p = primero;  // Actualizar "p"
		}

		delete primero; // Borrar el único que queda
		
		// Lista vacía
		
		primero = 0; // MUY IMPORTANTE
		tamanio = 0;
	}
}

/***************************************************************************/
/***************************************************************************/
// Copiar datos desde otro objeto de la clase
// PRE: Se ha reservado memoria para los datos

void Lista :: CopiarDatos (const Lista & otro)
{
    // Copia los campos privados

    tamanio = otro.tamanio; // Copia el núm. de nodos

    // Copia el contenido de los nodos

	TipoNodo * p_este = primero; 
	TipoNodo * p_otro = otro.primero; 

	for(int i = 0; i < tamanio; i++) {

		// Copiar valor
		p_este->info = p_otro->info; 

		// Adelantar punteros
		p_este = p_este->sig;		 
		p_otro = p_otro->sig;		 
	}	
}

/***************************************************************************/
/***************************************************************************/
// Método PRIVADO compartido por: 
// 		TipoBaseLista & Valor (int pos);
// 		TipoBaseLista & Valor (int pos) const;
// para evitar la duplicidad de código.
// 
// Devuelve una referencia al campo info de un nodo, dado por su posición. 
//
// Parámetros: pos, la posición (número de nodo) a la que se accede.  	
// 		El criterio seguido para especificar una posicion será : 
// 		1 -> primero, 2 -> segundo,...

TipoBaseLista & Lista :: el_valor (int pos) const
{
	int num_elementos = tamanio;

	TipoNodo * p; 
	int posic;

	for (p=primero,posic=1; posic<pos; posic++) p=p->sig;

	return p->info; 
}

/***************************************************************************/
/***************************************************************************/