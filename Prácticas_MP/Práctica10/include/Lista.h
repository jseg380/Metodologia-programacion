/***************************************************************************/
/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
// Basado en el h de Francisco Jos� Cortijo Bon
//
// Clase "Lista"
//
// Declaraci�n de la clase Lista (versi�n 1).
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
	
	int tamanio;		// N�mero de nodos
	
public:
	
	/***********************************************************************/
	/***********************************************************************/
	// CONSTRUCTORES Y DESTRUCTOR
	/***********************************************************************/
	/***********************************************************************/

	/***********************************************************************/
	/***********************************************************************/
	// Constructor unificado:
	//	a) Constructor sin argumentos, que crea una lista vac�a.
	//  b) Constructor con un argumento, que crea una lista con un n�mero de 
	//		nodos indicado en el argumento.
	//	c) Constructor con dos argumentos, que crea una lista con un n�mero 
	//		de nodos indicado en el primer argumento. Inicia todos los nodos 
	//		de la lista al valor indicado en el segundo argumento.
	//
	// Crea una lista enlazada con "num_nodos" nodos. Inicializa todos 
	// los nodos a un valor com�n, el indicado en el par�metro "valor". 
	// Par�metros:
	//  	num_nodos, n�mero de nodos que se van a crear. 
	//		valor, valor com�n que se copiar� en las casillas. 
	// Devuelve: un dato de tipo Lista.
	//
	// PRE:  num_nodos >= 0 
	// NOTA: Si num_nodos==0 la lista queda vac�a. 

	Lista (int num_nodos=0, TipoBaseLista valor=VALOR_DEF_LISTA);

	/***********************************************************************/
	// Constructor de copia

	Lista (const Lista & otro);
	
	/***********************************************************************/
    // Destructor

    ~Lista (void);


	/***********************************************************************/
	/***********************************************************************/
	// M�TODOS DE CONSULTA
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
	// M�TODOS QUE MODIFICAN TODA LA LISTA
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
	// Par�metros: valor, el valor com�n  que se escribir� en todos  
	//					los nodos (por defecto, VALOR_DEF_LISTA)

	void Ecualiza (const TipoBaseLista valor=VALOR_DEF_LISTA);


	/***********************************************************************/
	/***********************************************************************/
	// SERIALIZACI�N
	/***********************************************************************/
	/***********************************************************************/

	/***********************************************************************/
	/***********************************************************************/
	// Devuelve un string con el resultado de "serializar" una lista.
	// Par�metros: msg, mensaje que precede al contenido de la lista. 

	string ToString (const char * const msg); 


	/***********************************************************************/
	/***********************************************************************/
	// M�TODOS DE ACCESO
	/***********************************************************************/
	/***********************************************************************/

	/***********************************************************************/
	/***********************************************************************/
	// Consulta � modifica el valor de un nodo dado por su posici�n. 
	// Si se utiliza como rvalue se emplea para consulta. Si se utiliza  
	// como lvalue se emplea para modificaci�n.
	//
	// Par�metros: pos, la posici�n (n�mero de nodo) a la que se accede.  	
	// 		El criterio seguido para especificar una posicion ser� : 
	// 		1 -> primero, 2 -> segundo,...
	//
	// PRE: 1 <= pos <= Tamanio()

	//TipoBaseLista & Valor (int pos);
	//TipoBaseLista & Valor (int pos) const;

	/***********************************************************************/
	/***********************************************************************/
	// Busca la posici�n de un nodo dado un valor especificado. 
	// Par�metros: valor, el valor buscado. 
	// Devuelve la posici�n del primer nodo coincidente, 
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
	// M�todo para hacer una copia profunda desde la lista expl�cita 
	// "otra" en la lista impl�cita.
	// Par�metros: otra (referencia), referencia al objeto expl�cito
	// El contenido de la lista impl�cita se pierde, se sustituye por una  
	// copia del contenido de "origen". 

	void Clona (const Lista & otra);



	/***********************************************************************/
	/***********************************************************************/
	// M�TODOS QUE MODIFICAN (UNA CASILLA) EL CONTENIDO DE LA LISTA 
	/***********************************************************************/
	/***********************************************************************/

	/***********************************************************************/
	// A�ade (al final de la lista) un nodo con el valor indicado en "valor". 
	//
	// Par�metros:
	//		valor, el valor que se a�ade a la lista 

	void Aniadir (TipoBaseLista valor);

	/***********************************************************************/
	// Inserta un nuevo elemento en la posici�n "pos_insertar"
	// PRE: 1 <= pos_insertar <= tamanio+1
	// El criterio seguido para especificar una posicion ser� : 
	// 1 -> primero, 2 -> segundo,...
	// Nota: Si pos_insertar == tamanio+1, el resultado es id�ntico a la 
	// 		 ejecuci�n del m�todo Aniade()

	void Insertar (TipoBaseLista valor, int pos_insertar);

	/***********************************************************************/
	// Borra el elemento de la posici�n "pos_borrar" 
	// PRE: 1 <= pos_borrar <= tamanio
	// El criterio seguido para especificar una posicion ser� : 
	// 1 -> primero, 2 -> segundo,...

	void Eliminar (int pos_borrar);

	/***********************************************************************/
	// Borra el primer nodo que contiene el valor elemento de "pos" 
	//
	// PRE: 1 <= pos <= NumElementos(l)
	// El criterio seguido para especificar una posicion ser�: 
	// 1 -> primero, 2 -> segundo,...

	void EliminarValor (TipoBaseLista valor);
	

	/***********************************************************************/
	/***********************************************************************/
	// M�TODOS QUE RECIBEN/DEVUELVEN LISTAS
	/***********************************************************************/
	/***********************************************************************/

	/***************************************************************************/
	/***************************************************************************/
	// Construye y devuelve sublista de lista impl�cita.
	// La sublista devuelta es una copia de una parte de "original" formada 
	// por un m�ximo de "num_nodos" nodos, formada a partir del nodo que 
	// ocupa la posici�n "pos_inic" de "original". 
	//
	// Par�metros:
	//		pos_inic, posici�n de "original" a partir d ela que se va a 
	//			realizar la copia.
	//		num_nodos, n�mero (m�ximo) de nodos a extraer.
	//
	// PRE: 1 <= pos_inic < NumElementos(original)
	// PRE: 0 <= num_nodos
	// 		Si no se cumplen, la lista devuelta es una lista vac�a.

	Lista SubLista (int pos_inic, int num_nodos);
	
	/***********************************************************************/
	// Operador de asignaci�n.
	// Devuelve: un objeto de la clase Lista.
	
	Lista & operator = (const Lista & otra);
	
	/***********************************************************************/
	// Operador de asignaci�n (variante).
	// Recibe un n�mero e inicializa toda la Lista a ese n�mero.
	// Devuelve: un objeto de la clase Lista.
	
	Lista & operator = (const TipoBaseLista valor);
	
	/***********************************************************************/
	// Sobrecarga del operador []
	// Accede a un elemento de la lista dado su �ndice.
	// Par�metros: indice, indice del elemento al que se acceder�
	// Devuelve: el elemento en la posici�n (indice).
	//
	// PRE: 0 < indice < Tamanio()
	
	TipoBaseLista & operator [] (const int indice);
	
	TipoBaseLista & operator [] (const int indice) const;
	
	/***********************************************************************/
	// Operadores relacionales.
	// Devuelve: una variable booleana.
	
	bool operator == (const Lista & otra);
	
	bool operator != (const Lista & otra);
	
	bool operator  > (const Lista & otra);
	
	bool operator <= (const Lista & otra);
	
	bool operator  < (const Lista & otra);
	
	bool operator >= (const Lista & otra);
	

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
	// M�todo PRIVADO compartido por:
	// 		TipoBaseLista & Valor (int pos);
	// 		TipoBaseLista & Valor (int pos) const;
	// para evitar la duplicidd de c�digo.
	// 
	// Devuelve una referencia al campo info de un nodo, dado por su posici�n.
	//
	// Par�metros: pos, la posici�n (n�mero de nodo) a la que se accede.
	// 		El criterio seguido para especificar una posicion ser� : 
	// 		1 -> primero, 2 -> segundo,...

	TipoBaseLista & el_valor (int pos) const;
	
	/***********************************************************************/
	/***********************************************************************/
	// M�todo para comparar dos listas. Devuelve true si las listas 
	// impl�cita y "otra" son exactamente iguales (dimensiones y contenidos).
	// Par�metros: otra (referencia), referencia al objeto expl�cito
	// Devuelve "true" i las listas impl�cita y "otra" son exactamente 
	// iguales (dimensiones y contenidos).

	bool EsIgualA (const Lista & otra) const;

	/***********************************************************************/
 
};

/***************************************************************************/
/***************************************************************************/

#endif

