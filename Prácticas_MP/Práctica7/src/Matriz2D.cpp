/***************************************************************************/
//
// Fichero con la definición de las funciones asociadas el tipo Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos int en la que cada 
// fila es un vector dinamico independiente. 
//
// Fichero: Matriz2D.cpp
//
/***************************************************************************/

#include "Matriz2D.h"

#include <string>
#include <cstring>
using namespace std; 

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

Matriz2D CreaMatriz (int nfils, int ncols, TipoBase valor)
{
	// Pedir memoria para los datos
	
	Matriz2D matriz = ReservaMemoria (nfils, ncols); 
	
	// Inicializar las casillas de la matriz

	for (int f=0; f<matriz.fils; f++) 
		for (int c=0; c<matriz.cols; c++) 
			matriz.datos[f][c] = valor;

	return (matriz); 
}

/***************************************************************************/
/***************************************************************************/
// "Destruye" una matriz dinámica y la deja en un estado no útil (vacía). 
// Parámetros: 
//		matriz (referencia), la matriz que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeMatriz (Matriz2D & matriz)
{
	LiberaMemoria (matriz); 
}

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

Matriz2D ReservaMemoria (int nfils, int ncols)
{
	Matriz2D matriz; 

	// Por defecto, matriz vacía
	matriz.datos = nullptr;
	matriz.fils  = 0;
	matriz.cols  = 0;

	// Solo si se cumplen las precondiciones se reserva memoria 

	if (nfils>0 && ncols>0) {

		// "matriz" apuntará a un vector de punteros a las filas
		matriz.datos = new int * [nfils];

		for (int f=0; f<nfils; f++) {

			// "matriz[f]" apuntará a un vector de datos int
			matriz.datos[f] = new int [ncols];
		}

		matriz.fils = nfils;
		matriz.cols = ncols;
	}

	return (matriz);
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por una matriz dinámica. 
// Parámetros: 
//		matriz (referencia), la matriz que va a "liberarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void LiberaMemoria (Matriz2D & matriz)
{
	if (matriz.datos != 0) {

		// Liberar cada una de las filas
		for (int f=0; f<matriz.fils; f++)
 			delete [] matriz.datos[f];

 		// Liberar el vector de punteros
 		delete [] matriz.datos; 
   
		// La matriz debe quedar "vacía" --> la referencia "matriz" pone a 0 
		// el puntero que da acceso al vector de punteros a filas

		matriz.datos = 0;
		matriz.fils  = 0;
		matriz.cols  = 0;
	}
}

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una matriz.
// Parámetros: matriz (referencia), la matriz que va a serializarse. 

string ToString (const Matriz2D & matriz)
{
	string cad;

	string delimitador = "..................................";

	cad = "\n" + delimitador + "\n";
	cad = cad + "Filas = " + to_string(matriz.fils) + 
	      ", Columnas = " + to_string (matriz.cols) + "\n\n";

	for (int f=0; f<matriz.fils; f++) {
		cad = cad + "Fila " + to_string(f) + " --> ";
		
		for (int c=0; c<matriz.cols; c++) 
			cad = cad + to_string(matriz.datos[f][c]) + "  ";
		cad = cad + "\n";
	}
	cad = cad + delimitador + "\n\n";

	return (cad);
}

/***************************************************************************/
/***************************************************************************/


/***************************************************************************/
/***************************************************************************/
// Devuelve el número de filas/columnas de la matriz.
// Parámetros: matriz (referencia), la matriz que se va a consultar. 

int NumFilas (const Matriz2D & matriz)
{
	return (matriz.fils);
}

/***************************************************************************/
/***************************************************************************/

int NumColumnas (const Matriz2D & matriz)
{
	return (matriz.cols);
}

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

TipoBase & Valor (const Matriz2D & matriz, int num_fila, int num_columna) 
{
	return (matriz.datos[num_fila][num_columna]);
}

/***************************************************************************/
/***************************************************************************/
// Consulta si una matriz está vacía, devuelve true si está vacía y false si
// no lo está. Para que esté vacía la matriz debe apuntar a nullptr
// Parámetros: matriz (referencia), la matriz.

bool EstaVacia (const Matriz2D & matriz){
	bool vacia = false;
	
	// Si el vector de punteros apunta a nullptr entonces la matriz está vacia
	
	if (matriz.datos == nullptr)
		vacia = true;
	
	return vacia;
}

/***************************************************************************/
/***************************************************************************/
// Rellena la matriz con el valor indicado en el segundo parámetro.
// Parámetros: matriz (referencia), la matriz.
//			   valor, valor con el que se rellenará la matriz

void Ecualiza (Matriz2D & matriz, TipoBase valor){
	
	// Inicializa todos los elementos a valor
	
	for (int f = 0 ; f < matriz.fils ; f++)
		for (int c = 0 ; c < matriz.cols ; c++)
			matriz.datos[f][c] = valor;
}

/***************************************************************************/
/***************************************************************************/
// Deja la matriz en un estado no útil (vacía). La matriz queda con todos
// sus campos a cero.
// Parámetros: matriz (referencia), la matriz.

void EliminaTodos (Matriz2D & matriz){
	
	// Se libera la memoria que ocupaba la matriz
	
	LiberaMemoria (matriz);
}

/***************************************************************************/
/***************************************************************************/
// Hace una copia profunda de origen a destino.
// Parámetros: destino (referencia), la matriz en la que se hará la copia.
// 			   origen (referencia), la matriz que será copiada en destino.

void Clona (Matriz2D & destino, const Matriz2D & origen){
	
	// Se libera el contenido de la matriz destino
	
	DestruyeMatriz (destino);
	
	// Se establecen el número de filas y columnas en la matriz
	// destino al mismo que el de la matriz origen para asegurarse de
	// que no falta espacio
	
	destino = CreaMatriz (origen.fils, origen.cols);
	
	
	// Copia profunda haciendo uso de memcpy
	
	for (int i = 0 ; i < origen.fils ; i++)
		memcpy (destino.datos[i], origen.datos[i],
				origen.cols * sizeof (TipoBase));
	
}

/***************************************************************************/
/***************************************************************************/
// Compara dos matrices y devuelve true si son exactamente iguales.
// Parámetros: una (referencia), una matriz.
//			   otra (referencia), otra matriz.

bool SonIguales (const Matriz2D & una, const Matriz2D & otra){
	bool iguales = true;
	
	// Si no tienen igual número de filas y columnas
	// no pueden ser iguales
	
	if (una.fils != otra.fils || una.cols != otra.cols)
		iguales = false;
	
	// Se comprueba elemento a elemento si son iguales, en el momento en el que
	// haya un elemento que sea diferente se puede saber que no son iguales
	
	for (int f = 0 ; f < una.fils && iguales ; f++)
		for (int c = 0 ; c < una.cols && iguales ; c++)
			if (una.datos[f][c] != otra.datos[f][c])
				iguales = false;
	
	return iguales;
}

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
				int col_inic, int num_filas, int num_cols){
	
	// Manejo de errores
	
	if (fila_inic >= original.fils || fila_inic < 0 || 
		col_inic >= original.cols || col_inic < 0 || 
		num_filas > original.fils || num_filas < 1 || 
		num_cols > original.cols || num_cols < 1){
		
		// Si hay algún error con los datos introducidos se creará 
		// una matriz con 0 columnas y 0 filas, es decir, una matriz vacia
		
		fila_inic = col_inic = num_filas = num_cols = 0;
	}
	
	else{
		if (fila_inic + num_filas > original.fils)
			num_filas = original.fils - fila_inic;
		if (col_inic + num_cols > original.cols)
			num_cols = original.cols - col_inic;
	}
	
	// Se libera el contenido de resultado en la memoria
	
	DestruyeMatriz (resultado);
	
	resultado = CreaMatriz (num_filas, num_cols);
	
	for (int f = 0 ; f < num_filas ; f++)
		for (int c = 0 ; c < num_cols; c++)
			//cout << "Elemento (" << f + fila_inic << ", " << c + col_inic 
			//	 << ") : " << original.datos[f + fila_inic][c + col_inic] 
			//	 << endl;
			resultado.datos[f][c] = original.datos[f + fila_inic][c + col_inic];
}

/***************************************************************************/
/***************************************************************************/
// Elimina la fila num_fila de la matriz matriz.
// Parámetros: matriz (referencia), la matriz.
//			   num_fila, la fila que será eliminada.
// PRE: 0 <= num_fila < matriz.fils

void EliminaFila (Matriz2D & matriz, int num_fila){
	
	// Haciendo uso de la función memcpy se copia cada fila "una fila antes"
	// a partir de la fila que se quiere eliminar
	
	for (int i = num_fila ; i < matriz.fils - 1 ; i++)
		memcpy (matriz.datos[i], matriz.datos[i + 1], 
				matriz.cols * sizeof(TipoBase));
	
	// Se reduce el tamaño de filas de la matriz
	
	matriz.fils--;
	
	// Para evitar que ocupe más de lo necesario:
	// Se crea la matriz temporal con espacio suficiente para albergar
	// los contenidos de matriz
	
	Matriz2D copia_matriz = CreaMatriz (matriz.fils, matriz.cols);
	
	// Se copian los contenidos de matriz en copia_matriz
	
	Clona (copia_matriz, matriz);
	
	// Se libera matriz en memoria
	
	DestruyeMatriz (matriz);
	
	// Se ajusta matriz para que tenga el tamaño mínimo necesario
	
	matriz = CreaMatriz (copia_matriz.fils, copia_matriz.cols);
	
	// Se copian los contenidos de copia_matriz a matriz
	
	Clona (matriz, copia_matriz);
	
	// Se borra la matriz temporal
	
	DestruyeMatriz (copia_matriz);
}

/***************************************************************************/
/***************************************************************************/
// Elimina la columna num_col de la matriz matriz.
// Parámetros: matriz (referencia), la matriz.
//			   num_col, la columna que será eliminada.
// PRE: 0 <= num_col < matriz.cols

void EliminaColumna (Matriz2D & matriz, int num_col){
	
	// En cada fila se mueven los elementos a "una columna antes" a partir
	// de la columna que se quiere eliminar
	
	for (int f = 0 ; f < matriz.fils ; f++)
		for (int c = num_col ; c < matriz.cols ; c++)
			matriz.datos[f][c] = matriz.datos[f][c + 1];
	
	// Se reduce el tamaño de columnas de la matriz
	
	matriz.cols--;
	
	// Para evitar que ocupe más de lo necesario:
	// Se crea la matriz temporal con espacio suficiente para albergar
	// los contenidos de matriz
	
	Matriz2D copia_matriz = CreaMatriz (matriz.fils, matriz.cols);
	
	// Se copian los contenidos de matriz en copia_matriz
	
	Clona (copia_matriz, matriz);
	
	// Se libera matriz en memoria
	
	DestruyeMatriz (matriz);
	
	// Se ajusta matriz para que tenga el tamaño mínimo necesario
	
	matriz = CreaMatriz (copia_matriz.fils, copia_matriz.cols);
	
	// Se copian los contenidos de copia_matriz a matriz
	
	Clona (matriz, copia_matriz);
	
	// Se borra la matriz temporal
	
	DestruyeMatriz (copia_matriz);
}

/***************************************************************************/
/***************************************************************************/
// Cambia de orden las filas de la matriz.
// Parámetros: matriz (referencia), la matriz.

void EspejoHorizontal (Matriz2D & matriz){
	
	Matriz2D copia_matriz = CreaMatriz (matriz.fils, matriz.cols);
	
	Clona (copia_matriz, matriz);
	
	for (int f = 0 ; f < matriz.fils ; f++)
		memcpy (matriz.datos[f], copia_matriz.datos[matriz.fils - f - 1],
				matriz.cols * sizeof(TipoBase));
	
	DestruyeMatriz (copia_matriz);
}

/***************************************************************************/
/***************************************************************************/
// Cambia de orden las columnas de la matriz.
// Parámetros: matriz (referencia), la matriz.

void EspejoVertical (Matriz2D & matriz){
	
	Matriz2D copia_matriz = CreaMatriz (matriz.fils, matriz.cols);
	
	Clona (copia_matriz, matriz);
	
	for (int f = 0 ; f < matriz.fils ; f++)
		for (int c = 0 ; c < matriz.cols ; c++)
			matriz.datos[f][c] = copia_matriz.datos[f][matriz.cols - c - 1];
	
	DestruyeMatriz (copia_matriz);
}


/***************************************************************************/
/***************************************************************************/
