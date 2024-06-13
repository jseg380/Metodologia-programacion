/***************************************************************************/
//
// Fichero de cabecera asociado al tipo Matriz2D.
//
// Matriz2D: Matriz 2D dinamica de datos TipoBaseMatriz2D en la que cada 
// fila es un vector dinamico independiente. 
//
// Fichero: Matriz2D.h
//
/***************************************************************************/

#ifndef MATRIZ2D
#define MATRIZ2D

#include <string>

#include "Secuencia.h"

using namespace std;

typedef int TipoBaseMatriz2D;

/////////////////////////////////////////////////////////////////////////////
// Matriz2D


class Matriz2D {
private:
	
	// Valor por defecto para rellenar y ecualizar la matriz
	static const TipoBaseMatriz2D VALOR_DEF = 0;
	
	TipoBaseMatriz2D ** datos;			// Puntero a vector de punteros
	
	int fils;					// Número de filas
	int cols;					// Número de columnas
	
	// PRE: 0 < fils, 0 < cols
	// PRE: Si filas == 0, columnas == 0

public:
	
	/***********************************************************************/
	// Constructor con tres argumentos.
	// Parámetros:
	//				nfils, número de filas.
	//				ncols, número de columnas.
	//				valor, valor que se copiará en las casillas.
	
	Matriz2D (int nfils, int ncols, TipoBaseMatriz2D valor);
	
	/***********************************************************************/
	// Constructor con dos argumentos.
	// Parámetros:
	//				nfils, número de filas.
	//				ncols, número de columnas.
	
	Matriz2D (int nfils, int ncols);
	
	/***********************************************************************/
	// Constructor con un argumento. Crea una matriz cuadrada.
	// Parámetros:
	//				nfils, número de filas (al ser cuadrada es el número de
	//					   columnas también).
	
	Matriz2D (int nfils);
	
	/***********************************************************************/
	// Constructor sin argumentos. Crea una matriz vacía.
	
	Matriz2D (void);
	
	/***********************************************************************/
	// Constructor de copia.
	
	Matriz2D (const Matriz2D & otra);
	
	/***********************************************************************/
	// Destructor.
	
	~Matriz2D (void);
	
	
	
	/***********************************************************************/
	// Consulta si la matriz está vacía.
	// Devuelve: trivial.
	
	bool EstaVacia (void) const;
	
	/***********************************************************************/
	// Consulta el número de filas de la matriz.
	// Devuelve: trivial.
	
	int NumFilas (void) const;
	
	/***********************************************************************/
	// Consulta el número de columnas de la matriz.
	// Devuelve: trivial.
	
	int NumColumnas (void) const;
	
	/***********************************************************************/
	// Elimina todos los valores de la matriz. La matriz queda vacía.
	
	void EliminaTodos (void);
	
	/***********************************************************************/
	// Inicializa todas las casillas de la matriz al valor indicado como
	// argumento.
	
	void Ecualiza (TipoBaseMatriz2D valor = VALOR_DEF);
	
	/***********************************************************************/
	// "Serializa" una matriz.
	// Devuelve: un string la matriz "serializada".
	
	string ToString (void);
	
	/***********************************************************************/
	// Accede a un elemento de la matriz dados sus índices.
	// Devuelve: el elemento en la posición (fila, columna).
	
	TipoBaseMatriz2D & Elemento (int fila, int columna);
	TipoBaseMatriz2D & Elemento (int fila, int columna) const;
	
	/***********************************************************************/
	// Hace una copia profunda de la matriz explícita en la implícita.
	
	void Clona (const Matriz2D & otra);
	
	/***********************************************************************/
	// Compara dos matrices.
	// Devuelve: true si las matrices implícita y explícita son iguales.
	
	bool EsIgualA (const Matriz2D & otra) const;
	
	/***********************************************************************/
	// Añade una fila a la matriz.
	// PRE: fila_nueva debe tener el mismo número de casillas
	//		que columnas tenga la matriz.
	
	void Aniade (const Secuencia & fila_nueva);
	
	/***********************************************************************/
	// Inserta una fila en la posición dada.
	// PRE: fila_nueva debe tener el mismo número de casillas
	//		que columnas tenga la matriz.
	
	void Inserta (int indice, const Secuencia & fila_nueva);
	
	/***********************************************************************/
	// Elimina la fila indice.
	
	void EliminaFila (int indice);
	
	/***********************************************************************/
	// Elimina la columna indice.
	
	void EliminaColumna (int indice);
	
	/***********************************************************************/
	// Obtiene una fila completa.
	// Devuelve: un objeto de la clase Secuencia, que contiene la fila completa.
	
	Secuencia Fila (int indice);
	
	/***********************************************************************/
	// Obtiene una columna completa.
	// Devuelve: un objeto de la clase Secuencia, que contiene
	//			 la columna completa.
	
	Secuencia Columna (int indice);
	
	/***********************************************************************/
	// Obtiene una sumatriz de la matriz implícita.
	// Devuelve: un objeto de la clase Matriz2D, que contiene la submatriz.
	
	Matriz2D SubMatriz (int fila_inic, int col_inic, 
						int num_filas, int num_cols);
	

private:
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

	void ReservaMemoria (int nfils, int ncols);
	
	/***********************************************************************/
	// Libera la memoria ocupada por una matriz dinámica.
	// POST: La matriz queda vacía (todos sus campos a cero).

	void LiberaMemoria (void);
	
	/***********************************************************************/
	// Copia datos desde otro objeto de la misma clase. (Copia profunda).
	// PRE: Se ha reservado memoria para los datos.

	void CopiaDatos (const Matriz2D & otra);
	
	/***********************************************************************/
	// Redimensiona la matriz añadiendole una fila.
	// NOTA: Los valores de la fila están indefinidos (contienen basura).

	void Redimensiona (void);
	
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

    TipoBaseMatriz2D & el_elemento (int fila, int columna) const;
};

#endif
