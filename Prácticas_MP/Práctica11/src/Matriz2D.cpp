/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
//
// Fichero con la definición de las funciones asociadas el tipo Matriz2D.
//
// Matriz2D: Matriz 2D dinamica de datos TipoBaseMatriz2D en la que cada 
// fila es un vector dinamico independiente. 
//
// Fichero: Matriz2D.cpp
//
/***************************************************************************/

#include "Matriz2D.h"

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

/***********************************************************************/
// Constructor con tres argumentos.
// Parámetros:
//				nfils, número de filas.
//				ncols, número de columnas.
//				valor, valor que se copiará en las casillas.
// PRE: 0 < nfils y 0 < ncols

Matriz2D :: Matriz2D (int nfils, int ncols, TipoBaseMatriz2D valor)
{
	ReservaMemoria (nfils, ncols);
	
	// Inicializa la matriz a valor
	
	(*this) = valor;
}

/***********************************************************************/
// Constructor con dos argumentos.
// Parámetros:
//				nfils, número de filas.
//				ncols, número de columnas.
// PRE: 0 < nfils y 0 < ncols

Matriz2D :: Matriz2D (int nfils, int ncols)
	: Matriz2D (nfils, ncols, 0)
{
}

/***********************************************************************/
// Constructor con un argumento. Crea una matriz cuadrada.
// Parámetros:
//				nfils, número de filas (al ser cuadrada es el número de
//					   columnas también).

Matriz2D :: Matriz2D (int nfils)
	: Matriz2D (nfils, nfils, 0)
{
}

/***********************************************************************/
// Constructor sin argumentos. Crea una matriz vacía.

Matriz2D :: Matriz2D (void)
	: Matriz2D (0, 0, 0)
{
}

/***********************************************************************/
// Constructor de copia.

Matriz2D :: Matriz2D (const Matriz2D & otra)
{
	ReservaMemoria (otra.fils, otra.cols);
	CopiaDatos (otra);
}

/***********************************************************************/
// Destructor.

Matriz2D :: ~Matriz2D (void)
{
	LiberaMemoria ();
}



/***********************************************************************/
// Consulta si la matriz está vacía.

bool Matriz2D :: EstaVacia (void) const
{
	bool vacia = false;
	
	if (fils == 0 && cols == 0)
		vacia = true;
	
	return vacia;
}

/***********************************************************************/
// Consulta el número de filas de la matriz.

int Matriz2D :: NumFilas (void) const
{
	return fils;
}

/***********************************************************************/
// Consulta el número de columnas de la matriz.

int Matriz2D :: NumColumnas (void) const
{
	return cols;
}

/***********************************************************************/
// Elimina todos los valores de la matriz. La matriz queda vacía.

void Matriz2D :: EliminaTodos (void)
{
	LiberaMemoria ();
}

/***********************************************************************/
// Devuelve un string con el resultado de "serializar" una matriz.

string Matriz2D :: ToString (string mensaje)
{
	string cad;

	string delimitador = "..................................";

	cad = "\n" + delimitador + "\n" + mensaje + "\n";
	cad = cad + "Filas = " + to_string (fils) + 
	      ", Columnas = " + to_string (cols) + "\n\n";

	for (int f = 0 ; f < fils ; f++) {
		cad = cad + "Fila " + to_string(f) + " --> ";
		
		for (int c = 0 ; c < cols ; c++) 
			cad = cad + to_string (datos[f][c]) + "  ";
		cad = cad + "\n";
	}
	
	cad = cad + delimitador + "\n\n";

	return (cad);
}

/***********************************************************************/
// Añade una fila a la matriz.
// PRE: fila_nueva debe tener el mismo número de casillas
//		que columnas tenga la matriz.

void Matriz2D :: Aniade (const Secuencia & fila_nueva)
{
	// Se añade una fila más a la matriz al final de esta
	
	Redimensiona ();
	
	// Copia los valores de fila_nueva en la última fila de la matriz
	
	for (int c = 0 ; c < cols ; c++)
		datos[fils - 1][c] = fila_nueva.Valor (c + 1);
}

/***********************************************************************/
// Inserta una fila en la posición dada.
// PRE: fila_nueva debe tener el mismo número de casillas
//		que columnas tenga la matriz.

void Matriz2D :: Inserta (int indice, const Secuencia & fila_nueva)
{
	if (indice >= 0 && indice < fils){
		
		// Se añade una fila más al final de la matriz
		
		Redimensiona ();
		
		// Se desplazan las filas desde la indice hasta la última "hacia abajo"
		
		for (int f = fils - 1 ; f > indice ; f--)
			memmove (datos[f], datos[f - 1], cols * sizeof (TipoBaseMatriz2D));
		
		// Se inserta la nueva fila
		
		for (int c = 0 ; c < cols ; c++)
			datos[indice][c] = fila_nueva.Valor (c + 1);
	}
}

/***********************************************************************/
// Elimina la fila indice.

void Matriz2D :: EliminaFila (int indice)
{
	if (indice >= 0 && indice < fils){ // Solo actuará si el índice es válido
		
		// Se suprime la fila que se quería eliminar
		
		delete [] datos [indice];
		
		// Nuevo vector de punteros con una casilla menos
		
		TipoBaseMatriz2D ** nuevo_datos;
		
		nuevo_datos = new TipoBaseMatriz2D * [fils - 1];
		
		// Se copian los contenidos del vector de punteros antiguo al nuevo
		// excepto el puntero a la fila que se acaba de eliminar
		
		for (int f = 0, i = 0 ; f < fils ; f++)
			if (f != indice){
				nuevo_datos[i] = datos[f];
				i++;
			}
		
		// Se elimina el antiguo vector de punteros y se sustituye por el nuevo
		
		delete [] datos;
		
		datos = nuevo_datos;
		
		// Se actualiza el número de filas que tiene la matriz
		
		fils--;
	}
}

/***********************************************************************/
// Elimina la columna indice.

void Matriz2D :: EliminaColumna (int indice)
{
	if (indice >= 0 && indice < cols){ // Solo actuará si el índice es válido
		
		// Se guardan los datos actuales de la matriz
		
		TipoBaseMatriz2D ** antiguo_datos;
		
		antiguo_datos = datos;
		
		// Se reserva memoria para una matriz con una columna menos
		
		ReservaMemoria(fils, cols - 1);
		
		// Se copian los datos de la matriz antigua a la nueva excepto la
		// columna que se quería eliminar
		
		for (int f = 0 ; f < fils ; f++)
			for (int c = 0, i = 0; c < cols + 1 ; c++)
				if (c != indice){
					datos[f][i] = antiguo_datos[f][c];
					i++;
				}
		
		// Se libera el espacio que ocupaban los datos antiguos
		
		for (int f = 0 ; f < fils ; f++)
			delete [] antiguo_datos[f];
		
		delete [] antiguo_datos;
	}
}

/***********************************************************************/
// Obtiene una fila completa.
// Devuelve: un objeto de la clase Secuencia, que contiene la fila completa.

Secuencia Matriz2D :: Fila (int indice)
{
	Secuencia fila (cols);
	
	if (datos) // Solo actuará si no está vacía
		for (int c = 0 ; c < cols ; c++)
			fila.Aniade (datos[indice][c]);
	
	return fila;
}

/***********************************************************************/
// Obtiene una columna completa.
// Devuelve: un objeto de la clase Secuencia, que contiene
//			 la columna completa.

Secuencia Matriz2D :: Columna (int indice)
{
	Secuencia columna (fils);
	
	if (datos) // Solo actuará si no está vacía
		for (int f = 0 ; f < fils ; f++)
			columna.Aniade (datos[f][indice]);
	
	return columna;
}

/***********************************************************************/
// Obtiene una sumatriz de la matriz implícita.
// Devuelve: un objeto de la clase Matriz2D, que contiene la submatriz.

Matriz2D Matriz2D :: SubMatriz (int fila_inic, int col_inic, 
								int num_filas, int num_cols)
{
	// Manejo de errores
	
	if (fila_inic >= fils || fila_inic < 0 || 
		col_inic >= cols || col_inic < 0 || 
		num_filas > fils || num_filas < 1 || 
		num_cols > cols || num_cols < 1)
		
		// Si hay algún error con los datos introducidos se creará 
		// una matriz con 0 columnas y 0 filas, es decir, una matriz vacia
		
		fila_inic = col_inic = num_filas = num_cols = 0;
	
	else{
		if (fila_inic + num_filas > fils)
			num_filas = fils - fila_inic;
		if (col_inic + num_cols > cols)
			num_cols = cols - col_inic;
	}
	
	Matriz2D resultado (num_filas, num_cols);
	
	for (int f = 0 ; f < num_filas ; f++)
		for (int c = 0 ; c < num_cols; c++)
			resultado.datos[f][c] = datos[f + fila_inic][c + col_inic];
	
	return resultado;
}

/***********************************************************************/
// Operador de asignación.
// Devuelve: un objeto de la clase Matriz2D.

Matriz2D & Matriz2D :: operator = (const Matriz2D & otra)
{
	if (this != &otra) {
		
		// Libera la memoria que estaba ocupando la matriz implícita
		
		LiberaMemoria ();
		
		// Reserva la misma memoria que ocupa otra
		
		ReservaMemoria (otra.fils, otra.cols);
		
		// Hace una copia profunda de los datos
		
		CopiaDatos (otra);
	}
	
	return (*this); 
}

/***********************************************************************/
// Operador de asignación (variante).
// Recibe un número e inicializa toda la matriz a ese número.
// Devuelve: un objeto de la clase Matriz2D.

Matriz2D & Matriz2D :: operator = (const TipoBaseMatriz2D valor)
{
	if (datos) // Solo si la matriz no está vacía actuará
		for (int f = 0 ; f < fils ; f++)
			for (int c = 0 ; c < cols ; c++)
				datos[f][c] = valor;
	
	return (*this);
}

/**************************************************************/
// Sobrecarga del operador ()
// Accede a un elemento de la matriz dados sus índices.
// Parámetros: fila, fila a la que se accede
//			   columna, columna a la que se accede
// Devuelve: el elemento en la posición (fila, columna).
//
// PRE: 0<=fila<NumFilas()
// PRE: 0<=columna<NumColumnas()

TipoBaseMatriz2D & Matriz2D :: operator () (const int fila, const int columna)
{
	return el_elemento (fila, columna);
}

TipoBaseMatriz2D & Matriz2D :: operator () (const int fila, 
											const int columna) const
{
	return el_elemento (fila, columna);
}

/***********************************************************************/
// Operadores relacionales == y !=.
// Devuelve: una variable booleana.

bool Matriz2D :: operator == (const Matriz2D & otra) const
{
	bool iguales = (fils == otra.fils) && (cols == otra.cols);
	
	// Solo si tienen mismo número de columnas y filas se
	// comprueba la igualdad de su contenido
	
	if (iguales)
		for (int f = 0 ; f < fils && iguales ; f++)
			for (int c = 0 ; c < fils && iguales ; c++)
				if (datos[f][c] != otra.datos[f][c])
					iguales = false;
	
	return iguales;
}

bool Matriz2D :: operator != (const Matriz2D & otra) const
{
	return (!((*this) == otra));
}

/***********************************************************************/
// Operadores unarios + y -

Matriz2D Matriz2D :: operator + (void) const
{
	return (*this);
}

Matriz2D Matriz2D :: operator - (void) const
{
	// Matriz que contiene lo mismo que la implícita
	
	Matriz2D resultado (*this);
	
	// Opuesto de todos los elementos
	
	for (int f = 0 ; f < fils ; f++)
		for (int c = 0 ; c < cols ; c++)
			resultado.datos[f][c] = -resultado.datos[f][c];
	
	return resultado;
}


/***********************************************************************/
// Operadores binarios + y -

// Operador +

// Versión 1: [Matriz2D] + [Matriz2D]

Matriz2D operator + (const Matriz2D & matriz1,
					 const Matriz2D & matriz2)
{
	Matriz2D resultado;		// Matriz vacía por defecto
	
	// Solo se sumarán si matriz1 y matriz2 tienen las mismas dimensiones
	
	if (matriz1.fils == matriz2.fils && matriz1.cols == matriz2.cols) {
		
		resultado = matriz1;
		
		for (int f = 0 ; f < resultado.fils ; f++)
			for (int c = 0 ; c < resultado.cols ; c++)
				resultado.datos[f][c] += matriz2.datos[f][c];
	}
	
	return resultado;
}

// Versión 2: [Matriz2D] + [TipoBaseMatriz2D]

Matriz2D operator + (const Matriz2D & matriz,
					 const TipoBaseMatriz2D valor)
{
	Matriz2D resultado;
	
	Matriz2D matriz2 (matriz.fils, matriz.cols, valor);
	
	resultado = matriz + matriz2;
	
	return resultado;
}

// Versión 3: [TipoBaseMatriz2D] + [Matriz2D]

Matriz2D operator + (const TipoBaseMatriz2D valor,
					 const Matriz2D & matriz)
{
	Matriz2D resultado;
	
	resultado = matriz + valor;
	
	return resultado;
}

// Operador -

// Versión 1: [Matriz2D] - [Matriz2D]

Matriz2D operator - (const Matriz2D & matriz1,
					 const Matriz2D & matriz2)
{
	Matriz2D resultado;
	
	resultado = matriz1 + (-matriz2);
	
	return resultado;
}

// Versión 2: [Matriz2D] - [TipoBaseMatriz2D]

Matriz2D operator - (const Matriz2D & matriz,
					 const TipoBaseMatriz2D valor)
{
	Matriz2D resultado;
	
	resultado = matriz + (-valor);
	
	return resultado;
}

// Versión 2: [Matriz2D] - [TipoBaseMatriz2D]

Matriz2D operator - (const TipoBaseMatriz2D valor,
					 const Matriz2D & matriz)
{
	Matriz2D resultado;
	
	resultado = matriz + (-valor);
	
	return resultado;
}

/***********************************************************************/
// Sobrecarga de los operadores combinados += y -=

// Operador +=

// Versión 1: [Matriz2D] += [Matriz2D]

Matriz2D & Matriz2D :: operator += (const Matriz2D & otra)
{
	(*this) = (*this) + otra;
	
	return (*this);
}

// Versión 2: [Matriz2D] += [TipoBaseMatriz2D]

Matriz2D & Matriz2D :: operator += (const TipoBaseMatriz2D valor)
{
	(*this) = (*this) + valor;
	
	return (*this);
}

// Operador -=

// Versión 1: [Matriz2D] -= [Matriz2D]

Matriz2D & Matriz2D :: operator -= (const Matriz2D & otra)
{
	(*this) = (*this) - otra;
	
	return (*this);
}

// Versión 2: [Matriz2D] += [TipoBaseMatriz2D]

Matriz2D & Matriz2D :: operator -= (const TipoBaseMatriz2D valor)
{
	(*this) = (*this) - valor;
	
	return (*this);
}




///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//
//	MÉTODOS PRIVADOS DE LA CLASE Matriz2D
//
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

/***********************************************************************/
// Reserva memoria para los datos de una matriz dinámica con "nfils" 
// filas y "ncols" columnas.
// El contenido de las "nfils"x"ncols" casillas queda INDEFINIDO.
// Parámetros:
//		nfils, número de filas de la matriz.
//		ncols, número de columnas de la matriz.
// PRE: 0 < nfils y 0 < ncols
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos 
// para poder disponer de una matriz no vacía. Si alguno de los dos
// valores fuera 0 no se reserva memoria, y la matriz queda vacía. 

void Matriz2D :: ReservaMemoria (int nfils, int ncols)
{
	// Por defecto, matriz vacía
	datos = nullptr;
	fils  = 0;
	cols  = 0;

	// Solo si se cumplen las precondiciones se reserva memoria 

	if (nfils>0 && ncols>0) {

		datos = new TipoBaseMatriz2D * [nfils];

		for (int f=0; f<nfils; f++)
			datos[f] = new TipoBaseMatriz2D [ncols];

		fils = nfils;
		cols = ncols;
	}
}

/***********************************************************************/
// Libera la memoria ocupada por una matriz dinámica.
// POST: La matriz queda vacía (todos sus campos a cero)

void Matriz2D :: LiberaMemoria (void)
{
	if (datos){ // Solo actuará si la matriz no está vacía
		
		// Liberar cada una de las filas
		
		for (int f = 0 ; f < fils ; f++)
			delete [] datos[f];
		
		// Liberar el vector de punteros
		
		delete [] datos;
		
		// Poner a 0 todos los datos de la matriz
		
		datos = nullptr;
		fils = 0;
		cols = 0;
	}
}

/***********************************************************************/
// Copia datos desde otro objeto de la misma clase. (Copia profunda).
// PRE: Se ha reservado memoria para los datos.

void Matriz2D :: CopiaDatos (const Matriz2D & otra)
{
	// Copia los valores de los campos privados desde "otra"
	fils = otra.fils;
	cols = otra.cols;

	// Copia los valores de los datos
	for (int f = 0 ; f < fils ; f++)
		memcpy (datos[f], otra.datos[f], cols * sizeof (TipoBaseMatriz2D));
}

/***********************************************************************/
// Redimensiona la matriz añadiendole una fila.
// NOTA: Los valores de la fila están indefinidos (contienen basura).

void Matriz2D :: Redimensiona (void)
{
	if (datos){
		
		// Crea el nuevo vector de punteros con capacidad para un puntero más
		
		TipoBaseMatriz2D ** nuevo_datos;
		
		nuevo_datos = new TipoBaseMatriz2D * [fils + 1];
		
		// Copia el contenido del antiguo vector de punteros al nuevo
		
		for (int i = 0 ; i < fils ; i++)
			nuevo_datos[i] = datos[i];
		
		// Se le añade al final la nueva fila con cols columnas
		
		nuevo_datos[fils] = new TipoBaseMatriz2D [cols];
		
		// Se intercambian los vectores de punteros y se elimina el antiguo
		
		delete [] datos;
		
		datos = nuevo_datos;
		
		// Se actualiza el número de filas que tiene la matriz
		
		fils++;
	}
}

/***********************************************************************/
// Método PRIVADO compartido por: 
//      TipoBaseMatriz2D & Elemento (inf fila, int columna);
//      TipoBaseMatriz2D & Elemento (int fila, int columna) const;
// para evitar la duplicidad de código.
//
// Devuelve una referencia a un dato TipoBaseMatriz2D de la matriz
// dado su posición.
// PRE: 0 <= fila < NumFilas()
//		0 <= columna < NumColumnas()

TipoBaseMatriz2D & Matriz2D :: el_elemento (int fila, int columna) const
{
	return (datos[fila][columna]);
}




