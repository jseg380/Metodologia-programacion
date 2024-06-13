/***************************************************************************/
//
// Demostración del uso de los métodos pertenecientes a la clase Matriz2D.
//
// Fichero: III_Demo-Matriz2D.cpp
//
/***************************************************************************/

#include <iostream>

#include "Matriz2D.h"

using namespace std;

int main (void)
{
	// .....................................................................
	// Constructores de la clase
	
	Matriz2D matriz1 (5, 8, -5);
	
	Matriz2D matriz2 (7, 3);
	
	Matriz2D matriz3 (4);
	
	Matriz2D matriz4;
	
	Matriz2D copia_matriz1 (matriz1);
	
	cout << endl << "Matriz 1: " << matriz1.ToString();
	cout << endl << "Matriz 2: " << matriz2.ToString();
	cout << endl << "Matriz 3: " << matriz3.ToString();
	cout << endl << "Matriz 4: " << matriz4.ToString();
	cout << endl << "Copia de matriz 1: " << copia_matriz1.ToString();
	
	// .....................................................................
	// EstaVacia
	
	if (matriz1.EstaVacia())
		cout << endl << "Matriz 1 está vacía" << endl;
	else
		cout << endl << "Matriz 1 NO está vacía" << endl;
	
	if (matriz4.EstaVacia())
		cout << endl << "Matriz 4 está vacía" << endl;
	else
		cout << endl << "Matriz 4 NO está vacía" << endl;
	
	// .....................................................................
	// Métodos NumFilas y NumColumnas
	
	cout << endl << "Matriz 1 tiene " << matriz1.NumFilas() << " filas y "
		 << matriz1.NumColumnas() << " columnas" << endl;
	
	// .....................................................................
	// Ecualiza y EliminaTodos
	
	matriz1.Ecualiza (99);
	
	cout << endl << "Matriz 1 tras Ecualiza (99): " << matriz1.ToString();
	
	matriz2.EliminaTodos();
	
	cout << endl << "Matriz 2 tras EliminaTodos: " << matriz2.ToString();
	
	// .....................................................................
	// Elemento como rvalue y lvalue
	
	cout << endl << "Elemento (3, 3) de matriz 1: " << matriz1.Elemento (3, 3);
	
	matriz1.Elemento (3, 3) = -8;
	
	cout << endl << "Ahora el elemento (3, 3) de la matriz 1 es -8: " 
		 << matriz1.ToString();
	
	// .....................................................................
	// Clona matriz1 en matriz2
	
	matriz2.Clona (matriz1);
	
	cout << endl << "Matriz 2 clon de matriz 1:" << matriz2.ToString();
	
	// .....................................................................
	// EsIgualA
	
	if (matriz1.EsIgualA (matriz3))
		cout << endl << "Matriz 1 es IGUAL a matriz 3" << endl;
	else
		cout << endl << "Matriz 1 es DIFERENTE a matriz 3" << endl;
	
	if (matriz1.EsIgualA (matriz2))
		cout << endl << "Matriz 1 es IGUAL a matriz 2" << endl;
	else
		cout << endl << "Matriz 1 es DIFERENTE a matriz 2" << endl;
	
	// .....................................................................
	// Aniade
	
	Secuencia fila_nueva(matriz1.NumColumnas());
	
	for (int i = 0 ; i < matriz1.NumColumnas() ; i++)
		fila_nueva.Aniade (matriz1.NumFilas() * 10 + i);
	
	matriz1.Aniade (fila_nueva);
	
	cout << endl << "Matriz 1 con la secuencia añadida:" << matriz1.ToString();
	
	// .....................................................................
	// Inserta
	
	fila_nueva.EliminaTodos();
	
	for (int i = 0 ; i < matriz1.NumColumnas() ; i++)
		fila_nueva.Aniade (3 * 10 + i);
	
	matriz1.Inserta (3, fila_nueva);
	
	cout << endl << "Matriz 1 con una secuencia insertada en la fila 3:" 
		 << matriz1.ToString();
	
	// .....................................................................
	// EliminaFila
	
	matriz1.EliminaFila (2);
	
	cout << endl << "Matriz 1 tras eliminar la fila 2:" << matriz1.ToString();
	
	// .....................................................................
	// EliminaColumna
	
	matriz1.EliminaColumna (1);
	
	cout << endl << "Matriz 1 tras eliminar la columna 1:" 
		 << matriz1.ToString();
	
	// .....................................................................
	// Fila
	
	Secuencia fila (matriz1.Fila (3));
	
	cout << endl << "Fila 3 de la matriz 1:" << fila.ToString() << endl;
	
	// .....................................................................
	// Columna
	
	Secuencia columna (matriz1.Columna (2));
	
	cout << endl << "Columna 2 de la matriz 1:" << columna.ToString() << endl;
	
	// .....................................................................
	// SubMatriz
	
	Matriz2D submatriz1 (matriz1.SubMatriz (2, 1, 4, 3));
	
	cout << endl << "Submatriz de matriz 1:" << submatriz1.ToString();
	
	// .....................................................................
	// Destructor de la clase (implícito, se llama cuando termina el ámbito
	// en que está declarada la función).
	
	return 0;
}
