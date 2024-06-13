/***************************************************************************/
//
// Pruebas sobre el tipo Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos "TipoBase" en la que cada 
//           fila es un vector dinamico independiente.
//
// Juan Manuel Segura Duarte
//
// Fichero: II_Demo-Matriz2D.cpp
//
/***************************************************************************/

#include <iostream>

#include "Matriz2D.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Lectura de las dimensiones de la matriz

	int num_filas, num_cols; 

	do  {
		cout << endl;
		cout << "Introduzca num. filas de la matriz: ";
		cin >> num_filas; 
	} while (num_filas <= 0);	

	do  {
		cout << endl;
		cout << "Introduzca num. columnas de la matriz: ";
		cin >> num_cols; 
	} while (num_cols <= 0);	

	cout << endl << endl;

	// .....................................................................
	// Creación de una matriz y rellenar sus casillas  

	Matriz2D m = CreaMatriz (num_filas, num_cols);

	for (int f=0; f<m.fils; f++) 
		for (int c=0; c<m.cols; c++) 
			m.datos[f][c] = ((10*(f+1))+c+1);
	
	cout << "Matriz m: ";
	cout << ToString (m);
	
	
	// .....................................................................
	// Clonación de la matriz m
	
	Matriz2D m_copia = CreaMatriz (num_filas, num_cols);
	
	Clona (m_copia, m);
	
	cout << "Matriz m_copia clonada de m: ";
	cout << ToString (m_copia);
	
	// .....................................................................
	// Comprobación de que ambas matrices son iguales
	
	if (SonIguales (m, m_copia))
		cout << "m y m_copia son iguales" << endl << endl;
	else
		cout << "m y m_copia NO son iguales" << endl << endl;
	
	// .....................................................................
	// Espejo Horizontal de la matriz m
	
	EspejoHorizontal (m);
	
	cout << "Matriz m \"reflejada\" horizontalmente: ";
	cout << ToString (m);
	
	// .....................................................................
	// Espejo Vertical de la matriz m
	
	EspejoVertical (m);
	
	cout << "Matriz m \"reflejada\" verticalmente: ";
	cout << ToString (m);
	
	// .....................................................................
	// Comprobación de que ambas matrices son iguales
	
	if (SonIguales (m, m_copia))
		cout << "m y m_copia son iguales" << endl << endl;
	else
		cout << "m y m_copia NO son iguales" << endl << endl;
	
	// Variables para introducir en los parámetros
	
	int valor1, valor2, valor3, valor4;
	
	// .....................................................................
	// Ecualización de la matriz m
	
	cout << "Introduce a qué número quieres ecualizar la matriz: ";
	cin >> valor1;
	cout << endl;
	
	Ecualiza (m, valor1);
	
	cout << "Matriz m ecualizada a " << valor1 << ": ";
	cout << ToString (m);
	
	// .....................................................................
	// Valor como lvalue y rvalue
	
	cout << "Introduce la posición del elemento a modificar: " << endl;
	
	do{
		cout << "Fila: ";
		cin >> valor1;
	} while (valor1 < 0 || valor1 >= m.fils);
	
	do{
		cout << "Columna: ";
		cin >> valor2;
	} while (valor2 < 0 || valor2 >= m.cols);
	
	cout << endl << "Valor en (0, 0): " << Valor (m, 0, 0) << endl << endl;
	
	cout << "Introduce qué valor quieres introducir en la posición ("
		 << valor1 << ", " << valor2 << "): ";
	cin >> valor3;
	
	Valor (m, valor1, valor2) = valor3;
	
	cout << "Matriz m con el valor (" << valor1 << ", " << valor2 
		 << ") a " << valor3 << ": ";
	cout << ToString (m);
	
	// Restablecer los valores de m a sus valores iniciales
	
	Clona (m, m_copia);
	cout << "Matriz m restablecida a sus valores iniciales: ";
	cout << ToString (m);
	
	// .....................................................................
	// Elimina la segunda fila de la matriz m
	
	do{
		cout << "Introduce qué fila quieres eliminar: ";
		cin >> valor1;
	} while (valor1 < 0 || valor1 >= m.fils);
	
	EliminaFila (m, valor1);
	
	cout << "Matriz m sin la fila " << valor1 << ": ";
	cout << ToString (m);
	
	// .....................................................................
	// Elimina la primera fila de la matriz m
	
	do{
		cout << "Introduce qué columna quieres eliminar: ";
		cin >> valor1;
	} while (valor1 < 0 || valor1 >= m.cols);
	
	EliminaColumna (m, valor1);
	
	cout << "Matriz m sin la columna " << valor1 << ": ";
	cout << ToString (m);
	
	// .....................................................................
	// Submatriz de m_copia
	
	cout << "Introduce los datos para obtener una submatriz: " << endl;
	
	do{
		cout << "Fila inicial: ";
		cin >> valor1;
	} while (valor1 < 0 || valor1 >= m.fils);
	
	do{
		cout << "Columna inicial: ";
		cin >> valor2;
	} while (valor2 < 0 || valor2 >= m.cols);
	
	do{
		cout << "Número de filas: ";
		cin >> valor3;
	} while (valor3 <= 0 || valor3 > m.fils);
	
	do{
		cout << "Número de columnas: ";
		cin >> valor4;
	} while (valor4 <= 0 || valor4 > m.cols);
	
	SubMatriz (m, m_copia, valor1, valor2, valor3, valor4);
	
	cout << "Matriz m_copia: ";
	cout << ToString (m_copia);
	
	cout << "Submatriz de m_copia: ";
	cout << ToString (m);
	
	// .....................................................................
	// Destruye las matrices 

	DestruyeMatriz (m);
	DestruyeMatriz (m_copia);

	// .....................................................................

	return 0; 
}

/***************************************************************************/
/***************************************************************************/
