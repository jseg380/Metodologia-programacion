/***************************************************************************/
/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
// Basado en el cpp de Francisco José Cortijo Bon
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
	(*this) = valor;
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
// Añade (al final de la lista) un nodo con el valor indicado en "valor". 
//
// Parámetros:
//		valor, el valor que se añade a la lista 
/*
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
*/
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
		sublista = resultado; 

	} // if (1<=pos_inic && pos_inic<=NumElementos(original) &&  0<=num_nodos)

	return (sublista);

}

/***********************************************************************/
// Operador de asignación.
// Devuelve: un objeto de la clase Lista.

Lista & Lista :: operator = (const Lista & otra)
{
	if (this != &otra) {
		
		// Libera la memoria ocupada
		LiberarMemoria ();
		
		// Reserva de memoria para los valores de la lista
		ReservarMemoria (otra.tamanio);
		
		// Copia el contenido de la matriz y los campos privados
		CopiarDatos (otra);
	}
	
	return (*this);
}

/***********************************************************************/
// Operador de asignación (variante).
// Recibe un número e inicializa toda la Lista a ese número.
// Devuelve: un objeto de la clase Lista.

Lista & Lista :: operator = (const TipoBaseLista valor)
{
	TipoNodo * p = primero; // Apuntar al primero.

	for(int i = 0; i < tamanio; i++) {
		p->info = valor; // Inicializar nodo.
		p = p->sig;		 // Adelantar "p".
	}
	
	return (*this);
}

/***********************************************************************/
// Sobrecarga del operador []
// Accede a un elemento de la lista dado su índice.
// Parámetros: indice, indice del elemento al que se accederá
// Devuelve: el elemento en la posición (indice).
//
// PRE: 0 < indice < Tamanio()

TipoBaseLista & Lista :: operator [] (const int indice)
{
	return el_valor (indice);
}

TipoBaseLista & Lista :: operator [] (const int indice) const
{
	return el_valor (indice);
}

/***********************************************************************/
// Operadores relacionales.
// Devuelve: una variable booleana.

bool Lista :: operator == (const Lista & otra) const
{
	return EsIgualA (otra);
}

bool Lista :: operator != (const Lista & otra) const
{
	return (!((*this) == otra));
}

bool Lista :: operator  > (const Lista & otra) const
{
	int fin1 = tamanio;			// Número de nodos de las  
	int fin2 = otra.tamanio;	// dos lista a commparar
	

	// Recorrer las dos listas mientras queden elementos por 
	// explorar y continúen siendo iguales en las dos listas 

	int pos=1; // Posición común en ambas listas 

	bool iguales = true; 

	TipoBaseLista valor_este; // valor del nodo del objeto implícito 
	TipoBaseLista valor_otra; // valor del nodo del objeto "otro"

	while ((pos<=fin1) && (pos<=fin2) && (iguales)) {

		valor_este = (*this)[pos]; 	// operator []
		valor_otra = otra[pos];		// operator []

		if (valor_este != valor_otra) iguales = false;
		else pos++;
	}

	bool mayor = false;

	// No se ha alcanzado el final en ninguna lista, pero se ha 
	// encontrado una discrepancia
	if ((pos<=fin1) && (pos<=fin2) && (valor_este > valor_otra)) 
		mayor = true; 

	// Se ha agotado la lista "otro"
	if ((pos<=fin1) && (pos>fin2)) 
		mayor = true; 

	return (mayor);
}

bool Lista :: operator <= (const Lista & otra) const
{
	return (!((*this) > otra));
}

bool Lista :: operator  < (const Lista & otra) const
{
	return (!((*this) > otra) && !((*this) == otra));
}

bool Lista :: operator >= (const Lista & otra) const
{
	return (((*this) > otra) || ((*this) == otra));
}

/***********************************************************************/
// Operadores binarios + y -

// Operador +

// Versión 1: [Lista] + [Lista]

Lista operator + (const Lista & lista1, const Lista & lista2)
{
	// Se crea una lista con capacidad para almacenar los datos de las 2 listas
	
	Lista resultado (lista1.tamanio + lista2.tamanio);
	
	// Se copian los datos de lista1 en resultado
	
	TipoNodo * p = resultado.primero;	// Puntero al primer nodo de resultado
	TipoNodo * p2 = lista1.primero; 	// Puntero al primer nodo de lista1
	
	while (p2) { // p2 != nullptr
		
		// Se copian los datos
		
		p->info = p2->info;
		
		// Se avanzan los punteros
		
		p = p->sig;
		p2 = p2->sig;
	}
	
	// Se copian los datos de lista2 en resultado
	
	p2 = lista2.primero;
	
	while (p2) {
		
		// Se copian los datos
		
		p->info = p2->info;
		
		// Se avanzan los punteros
		
		p = p->sig;
		p2 = p2->sig;
	}
	
	return resultado;
}

// Versión 2: [Lista] + [TipoBaseLista]

Lista operator + (const Lista & lista, const TipoBaseLista valor)
{
	// Se crea una lista con un nodo que contiene valor
	
	Lista lista_valor (1, valor);
	
	return lista + lista_valor;
}

// Versión 3: [TipoBaseLista] + [Lista]

Lista operator + (const TipoBaseLista valor, const Lista & lista)
{
	// Se crea una lista con un nodo que contiene valor
	
	Lista lista_valor (1, valor);
	
	return lista_valor + lista;
}

// Operador -

// Versión 1: [Lista] - [Lista]

Lista operator - (const Lista & lista1, const Lista & lista2)
{
	// Se crea una copia de lista1
	
	Lista resultado (lista1);
	
	// Se va recorriendo la lista2 eliminando los elementos de resultado
	// que contengan los valores de lista2
	
	TipoNodo * p2;
	
	p2 = lista2.primero;
	
	while (p2) {// p != nullptr
	
		resultado.EliminarValor (p2->info);
		
		p2 = p2->sig;
	}
	
	return resultado;
}

// Versión 2: [Lista] - [TipoBaseLista]

Lista operator - (const Lista & lista, const TipoBaseLista valor)
{
	// Se crea una copia de lista
	
	Lista otra (1, valor);
	
	// Se elimina el elemento que contenga valor de la lista, en caso de que
	// haya algún elemento que lo contenga, en caso contrario no se hace nada
	
	return lista - otra;
}

/***********************************************************************/
// Sobrecarga de los operadores combinados += y -=

// Operador +=

// Versión 1: [Lista] += [Lista]

Lista & Lista :: operator += (const Lista & otra)
{
	(*this) = (*this) + otra;
	
	return (*this);
}

// Versión 2: [Lista] += [TipoBaseLista]

Lista & Lista :: operator += (const TipoBaseLista valor)
{
	(*this) = (*this) + valor;
	
	return (*this);
}

// Operador -=

// Versión 1: [Lista] -= [Lista]

Lista & Lista :: operator -= (const Lista & otra)
{
	(*this) = (*this) - otra;
	
	return (*this);
}

// Versión 2: [Lista] -= [TipoBaseLista]

Lista & Lista :: operator -= (const TipoBaseLista valor)
{
	(*this) = (*this) - valor;
	
	return (*this);
}

/***********************************************************************/
// Sobrecarga de >> y <<

istream & operator >> (istream & entrada, Lista & lista)
{
	// Se libera la memoria ocupada por lista
	
	lista.LiberarMemoria ();
	
	TipoBaseLista valor;
	
	while (!entrada.eof()) { // Mientras no se llegue al final del fichero
		
		entrada >> valor;
		
		lista += valor;
	}
	
	return entrada;
}

ostream & operator << (ostream & salida, const Lista & lista)
{
	TipoNodo * p = lista.primero;	// Puntero al primer nodo
	
	if (p) { // Solo actuará si la lista no está vacía
		while (p->sig) {	// p->sig != nullptr
			
			salida << setw(ANCHO_LISTA) << p->info << " ";
			
			p = p->sig;
		}
		
		// Último nodo
		
		salida << setw(ANCHO_LISTA) << p->info;
	}
	
	return salida;
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
	if (primero != nullptr) {
		
		TipoNodo *p = primero; // Colocar "p" al principio

		while (primero->sig != nullptr) {

			primero = primero->sig;  // Nuevo "primero"
			delete p;     // Borrar el antiguo primero
			p = primero;  // Actualizar "p"
		}

		delete primero; // Borrar el único que queda
		
		// Lista vacía
		
		primero = nullptr; // MUY IMPORTANTE
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
