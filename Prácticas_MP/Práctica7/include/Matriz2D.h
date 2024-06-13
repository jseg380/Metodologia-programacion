/***************************************************************************/
//
// Fichero de cabecera asociado al tipo Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos int en la que cada 
// fila es un vector dinamico independiente. 
//
// Fichero: Matriz2D.h
//
/***************************************************************************/

#ifndef MATRIZ2D
#define MATRIZ2D

#include <string>
using namespace std; 


/***************************************************************************/
// Definiciones de tipos

typedef int TipoBase;

typedef struct {

	int ** datos;	// Puntero a vector de punteros a los datos

	int fils;			// Num. de filas
	int cols; 			// Num. de columnas

} Matriz2D;


/***************************************************************************/
/***************************************************************************/
// Crea una matriz dinámica con "nfils" filas y "ncols" columnas. 
// El contenido de las "fils"x"cols" casillas se inicializa a un valor común, 
// el indicado en el parámetro "valor"
// Parámetros:
//		nfils, número de filas de la matriz (por defecto 0).
//		ncols, número de columnas de la matriz (por defecto 0).
//		valor, valor común que se copiará en las casillas (por defecto 0). 
// Devuelve: un dato de tipo Matriz2D.
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

Matriz2D CreaMatriz (int nfils=0, int ncols=0, TipoBase valor=0);

/***************************************************************************/
/***************************************************************************/
// "Destruye" una matriz dinámica y la deja en un estado no útil (vacía). 
// Parámetros: 
//		matriz (referencia), la matriz que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeMatriz (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Reserva memoria para los datos de una matriz dinámica con "nfils" filas 
// y "ncols" columnas. 
// El contenido de las "nfils"x"ncols" casillas queda INDEFINIDO.
// Parámetros:
//		nfils, número de filas de la matriz.
//		ncols, número de columnas de la matriz. 
// Devuelve: un dato Matriz2D con memoria reservada.
// 		El contenido de las "fils"x"cols" casillas queda indefinido. 
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

Matriz2D ReservaMemoria (int nfils, int ncols);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por una matriz dinámica. 
// Parámetros: 
//		matriz (referencia), la matriz que va a "liberarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void LiberaMemoria (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una matriz.
// Parámetros: matriz (referencia), la matriz que va a serializarse. 

string ToString (const Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/


/***************************************************************************/
/***************************************************************************/
// Devuelve el número de filas/columnas de la matriz.
// Parámetros: matriz (referencia), la matriz que se va a consultar. 

int NumFilas (const Matriz2D & matriz);
int NumColumnas (const Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Consulta ó modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consulta. Si se utiliza como lvalue se emplea 
// para modificación.
// Parámetros: matriz (referencia), la matriz. 
//			   num_fila, número de fila.
//			   num_columna, número de columna.
// PRE: 0<=num_fila<NumFilas(m)
// PRE: 0<=num_columna<NumColumnas(m)

TipoBase & Valor (const Matriz2D & matriz, int num_fila, int num_columna);

/***************************************************************************/
/***************************************************************************/
// Consulta si una matriz está vacía, devuelve true si está vacía y false si
// no lo está. Para que esté vacía la matriz debe apuntar a nullptr
// Parámetros: matriz (referencia), la matriz.

bool EstaVacia (const Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Rellena la matriz con el valor indicado en el segundo parámetro.
// Parámetros: matriz (referencia), la matriz.
//			   valor, valor con el que se rellenará la matriz

void Ecualiza (Matriz2D & matriz, TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Deja la matriz en un estado no útil (vacía). La matriz queda con todos
// sus campos a cero.
// Parámetros: matriz (referencia), la matriz.

void EliminaTodos (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Hace una copia profunda de origen a destino.
// Parámetros: destino (referencia), la matriz en la que se hará la copia.
// 			   origen (referencia), la matriz que será copiada en destino.

void Clona (Matriz2D & destino, const Matriz2D & origen);

/***************************************************************************/
/***************************************************************************/
// Compara dos matrices y devuelve true si son exactamente iguales.
// Parámetros: una (referencia), una matriz.
//			   otra (referencia), otra matriz.

bool SonIguales (const Matriz2D & una, const Matriz2D & otra);

/***************************************************************************/
/***************************************************************************/
// Extrae una submatriz de original y la deja en resultado. La submatriz
// resultado es una zona rectangular de original que empieza en la casilla
// (fila_inic, col_inic) y que tiene num_filas filas y num_cols columnas.
// Parámetros: original (referencia), matriz de la que se copiará una submatriz.
//			   resultado (referencia), matriz en la que será copiada la
//						  submatriz extraída de original.
//			   fila_inic, fila desde la cual empieza la submatriz.
//			   col_inic, columna desde la cual empieza la submatriz.
//			   num_filas, número de filas que tendrá la submatriz.
//			   num_cols, número de columnas que tendrá la submatriz.

void SubMatriz (Matriz2D & resultado, const Matriz2D & original, int fila_inic,
				int col_inic, int num_filas, int num_cols);

/***************************************************************************/
/***************************************************************************/
// Elimina la fila num_fila de la matriz matriz.
// Parámetros: matriz (referencia), la matriz.
//			   num_fila, la fila que será eliminada.
// PRE: 0 <= num_fila < matriz.fils

void EliminaFila (Matriz2D & matriz, int num_fila);

/***************************************************************************/
/***************************************************************************/
// Elimina la columna num_col de la matriz matriz.
// Parámetros: matriz (referencia), la matriz.
//			   num_col, la columna que será eliminada.
// PRE: 0 <= num_col < matriz.cols

void EliminaColumna (Matriz2D & matriz, int num_col);

/***************************************************************************/
/***************************************************************************/
// Cambia de orden las filas de la matriz.
// Parámetros: matriz (referencia), la matriz.

void EspejoHorizontal (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Cambia de orden las columnas de la matriz.
// Parámetros: matriz (referencia), la matriz.

void EspejoVertical (Matriz2D & matriz);


/***************************************************************************/
/***************************************************************************/


#endif
