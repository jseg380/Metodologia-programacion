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
// Declaración de la clase Lista (versión 1).
// Definiciones en Lista.cpp
//
// Incluye: 
//		* constructor de copia
//		* destructor 
//
// Fichero: Lista.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef LISTA
#define LISTA

#include <string>

#include "TipoBase_Lista.h"

using namespace std;

/***************************************************************************/
// Definiciones de tipos

struct TipoNodo 		// Tipo de cada nodo
{
	TipoBaseLista   info;	// Valor guardado en el nodo
	TipoNodo 	  * sig;	// Puntero al siguiente
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Lista 
{

private:
	
	TipoNodo * primero; // Puntero al primer nodo 

	// PRE: tamanio >= 0
	
	int tamanio;		// Número de nodos
	
public:
	
	/***********************************************************************/
	/***********************************************************************/
	// CONSTRUCTORES Y DESTRUCTOR
	/***********************************************************************/
	/***********************************************************************/

	/***********************************************************************/
	/***********************************************************************/
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

	Lista (int num_nodos=0, TipoBaseLista valor=VALOR_DEF_LISTA);

	/***********************************************************************/
	// Constructor de copia

	Lista (const Lista & otro);
	
	/***********************************************************************/
    // Destructor

    ~Lista (void);


	/***********************************************************************/
	/***********************************************************************/
	// MÉTODOS DE CONSULTA
	/***********************************************************************/
	/***********************************************************************/

	/***********************************************************************/
    // Consulta si la lista esta vacia
    // Devuelve: true si la lista esta vacia. 

	bool EstaVacia (void) const;
	
	/***********************************************************************/
	// Devuelve el numero de elementos
	
	int  Tamanio (void) const;


	/***********************************************************************/
	/***********************************************************************/
	// MÉTODOS QUE MODIFICAN TODA LA LISTA
	/***********************************************************************/
	/***********************************************************************/

	/***********************************************************************/
	// Elimina todos los valores de la lista. 
	// POST: EstaVacia() == true

	void EliminaTodos (void);

	/***********************************************************************/
	/***********************************************************************/
	// Ecualizar una lista: cambia todos los todos valores de la lista y los 
	// fija todos iguales e iguales a "valor".
	// Parámetros: valor, el valor común  que se escribirá en todos  
	//					los nodos (por defecto, VALOR_DEF_LISTA)

	void Ecualiza (const TipoBaseLista valor=VALOR_DEF_LISTA);


	/***********************************************************************/
	/***********************************************************************/
	// SERIALIZACIÓN
	/***********************************************************************/
	/***********************************************************************/

	/***********************************************************************/
	/***********************************************************************/
	// Devuelve un string con el resultado de "serializar" una lista.
	// Parámetros: msg, mensaje que precede al contenido de la lista. 

	string ToString (const char * const msg); 


	/***********************************************************************/
	/***********************************************************************/
	// MÉTODOS DE ACCESO
	/***********************************************************************/
	/***********************************************************************/

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
	// PRE: 1 <= pos <= Tamanio()

	TipoBaseLista & Valor (int pos);
	TipoBaseLista & Valor (int pos) const;

	/***********************************************************************/
	/***********************************************************************/
	// Busca la posición de un nodo dado un valor especificado. 
	// Parámetros: valor, el valor buscado. 
	// Devuelve la posición del primer nodo coincidente, 
	// 		o -1 si no se encuentra.
	/***********************************************************************/
	
	int Buscar (TipoBaseLista valor) const;


	/***********************************************************************/
	/***********************************************************************/
	// COPIA PROFUNDA 
	/***********************************************************************/
	/***********************************************************************/

	/***********************************************************************/
	/***********************************************************************/
	// Método para hacer una copia profunda desde la lista explícita 
	// "otra" en la lista implícita.
	// Parámetros: otra (referencia), referencia al objeto explícito
	// El contenido de la lista implícita se pierde, se sustituye por una  
	// copia del contenido de "origen". 

	void Clona (const Lista & otra);

	/***********************************************************************/
	/***********************************************************************/
	// Método para comparar dos listas. Devuelve true si las listas 
	// implícita y "otra" son exactamente iguales (dimensiones y contenidos).
	// Parámetros: otra (referencia), referencia al objeto explícito
	// Devuelve "true" i las listas implícita y "otra" son exactamente 
	// iguales (dimensiones y contenidos).

	bool EsIgualA (const Lista & otra) const;


	/***********************************************************************/
	/***********************************************************************/
	// MÉTODOS QUE MODIFICAN (UNA CASILLA) EL CONTENIDO DE LA LISTA 
	/***********************************************************************/
	/***********************************************************************/

	/***********************************************************************/
	// Añade (al final de la lista) un nodo con el valor indicado en "valor". 
	//
	// Parámetros:
	//		valor, el valor que se añade a la lista 

	void Aniadir (TipoBaseLista valor);

	/***********************************************************************/
	// Inserta un nuevo elemento en la posición "pos_insertar"
	// PRE: 1 <= pos_insertar <= tamanio+1
	// El criterio seguido para especificar una posicion será : 
	// 1 -> primero, 2 -> segundo,...
	// Nota: Si pos_insertar == tamanio+1, el resultado es idéntico a la 
	// 		 ejecución del método Aniade()

	void Insertar (TipoBaseLista valor, int pos_insertar);

	/***********************************************************************/
	// Borra el elemento de la posición "pos_borrar" 
	// PRE: 1 <= pos_borrar <= tamanio
	// El criterio seguido para especificar una posicion será : 
	// 1 -> primero, 2 -> segundo,...

	void Eliminar (int pos_borrar);

	/***********************************************************************/
	// Borra el primer nodo que contiene el valor elemento de "pos" 
	//
	// PRE: 1 <= pos <= NumElementos(l)
	// El criterio seguido para especificar una posicion será: 
	// 1 -> primero, 2 -> segundo,...

	void EliminarValor (TipoBaseLista valor);
	

	/***********************************************************************/
	/***********************************************************************/
	// MÉTODOS QUE RECIBEN/DEVUELVEN LISTAS
	/***********************************************************************/
	/***********************************************************************/

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

	Lista SubLista (int pos_inic, int num_nodos);

	/***********************************************************************/

private:
	
	/***********************************************************************/
	// Pide memoria para "num_elementos" nodos
	// PRE: num_elementos > 0

	void ReservarMemoria (int num_elementos);

	/***********************************************************************/
	// Liberar memoria
	
	void LiberarMemoria (void); 

	/***********************************************************************/
    // Copiar datos desde otro objeto de la clase
	// PRE: Se ha reservado memoria para los datos
	
	void CopiarDatos (const Lista & otro);

	/***********************************************************************/
	// Método PRIVADO compartido por: 
	// 		TipoBaseLista & Valor (int pos);
	// 		TipoBaseLista & Valor (int pos) const;
	// para evitar la duplicidd de código.
	// 
	// Devuelve una referencia al campo info de un nodo, dado por su posición. 
	//
	// Parámetros: pos, la posición (número de nodo) a la que se accede.  	
	// 		El criterio seguido para especificar una posicion será : 
	// 		1 -> primero, 2 -> segundo,...

	TipoBaseLista & el_valor (int pos) const;

	/***********************************************************************/
 
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// Muestra el contenido de una lista 
void PintaLista (const Lista & l, const char * const msg);

/***************************************************************************/
/***************************************************************************/

#endif

