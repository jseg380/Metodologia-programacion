/***************************************************************************/
/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
// Basado en el cpp de Francisco José Cortijo Bon
//
// Demostración de la clase Matriz2D (versión 2).
// Incluye: 
//		* constructor de copia
//		* destructor
//		* Operador =
// 		* Operadores de acceso
//		* Operadores varios
//
// Fichero: IV_Demo-Matriz2D.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "TipoBaseMatriz2D.h"
#include "Matriz2D.h"
#include "Secuencia.h"


using namespace std; 

/**********************************************************************/
/**********************************************************************/

int main (void)
{

	Matriz2D m1;	// Constructor sin argumentos

	if (m1.EstaVacia())
		cout << "Matriz m1 esta vacia" << endl;
	else 
		cout << "Matriz m1 NO esta vacia" << endl;
	cout << endl << endl;


	Matriz2D m2(5); // Constructor con un argumento --> matriz cuadrada

	if (m2.EstaVacia())
		cout << "Matriz m2 (5x5) esta vacia" << endl;
	else 
		cout << "Matriz m2 (5x5) NO esta vacia" << endl;
	cout << endl << endl;

	cout << m2.ToString ("m2 (5x5)") << endl;
	cout << endl;

	m2 = 0;

	cout << m2.ToString ("m2 tras m2 = 0") << endl;
	cout << endl;


	// Modifica los valores de la diagonal

	for (int f=0; f<m2.NumFilas(); f++)
		m2 (f, f) = (TipoBaseMatriz2D) 1;

	cout << m2.ToString ("m2 diagonal a 1") << endl;
	cout << endl;


	// Extrae una fila y una columna

	Secuencia fila_primera = m2.Fila (0);
	Secuencia ult_columna = m2.Columna (m2.NumColumnas()-1);

	cout << "Primera fila:   " << fila_primera.ToString() << endl;
	cout << "Ultima columna: " << ult_columna.ToString() << endl;
	cout << endl << endl;
	
	
	Matriz2D m3 (2, 5); // Const. con dos argumentos --> matriz rectangular

	if (m3.EstaVacia())
		cout << "Matriz m3 (2x5) esta vacia" << endl;
	else 
		cout << "Matriz m3 (2x5) NO esta vacia" << endl;
	cout << endl << endl;

	m3 = 0;

	cout << m3.ToString ("m3 (2x5) tras m3 = 0") << endl;
	cout << endl;


	Matriz2D m4 (6, 3, 9); // Constructor con tres argumentos --> matriz 
						   // rectangular inicializada de manera explícita

	if (m4.EstaVacia())
		cout << "Matriz m4 (6x3) esta vacia" << endl;
	else 
		cout << "Matriz m4 (6x3) NO esta vacia" << endl;
	cout << endl << endl;

	cout << m4.ToString ("m4 (6x3) creada e inicializada a 9") << endl;
	cout << endl;


    // "m5" se construye como copia de "m4"
   
	Matriz2D m5 (m4);		// Constructor de copia
	
	cout << m5.ToString ("m5 creada como copia de m4") << endl;
	cout << endl;

	m5(1,1) = (TipoBaseMatriz2D) 77;
	m5(3,0) = (TipoBaseMatriz2D) 22;

	cout << m5.ToString ("m5 modificada filas 1 y 3") << endl;
	cout << endl;


	m5.EliminaFila (1);

	cout << m5.ToString ("m5 eliminada fila 1") << endl;
	cout << endl;

	m5.EliminaFila (2);

	cout << m5.ToString ("m5 eliminada fila 2") << endl;
	cout << endl;

	m5(0,1) = (TipoBaseMatriz2D) 111;
	m5(3,1) = (TipoBaseMatriz2D) 222;
	m5(2,0) = (TipoBaseMatriz2D) 333;

	cout << m5.ToString ("m5 modificada columnas 0 y 1") << endl;
	cout << endl;

	m5.EliminaColumna (1);

	cout << m5.ToString ("m5 eliminada columna 1") << endl;
	cout << endl;

	m5.EliminaColumna (0);

	cout << m5.ToString ("m5 eliminada columna 0") << endl;
	cout << endl;

	m5.EliminaTodos();
  
	cout << m5.ToString ("m5 eliminados todos") << endl;
	cout << endl;

	if (m5.EstaVacia())
		cout << "Matriz m5 esta vacia" << endl;
	else 
		cout << "Matriz m5 NO esta vacia" << endl;
	cout << endl << endl;


	/***********************************************************/
	// Añadir e insertar filas

	Matriz2D nueva (4, 3, 1);	
	
	cout << nueva.ToString ("nueva creada como 4x3 con valor 1") << endl;
  	cout << endl << endl;  

	Secuencia s;
	for (int i = 0 ; i < 3 ; i++)
		s.Aniade (88);

	cout << "Secuencia s: " << s.ToString() << endl; 

	nueva.Aniade (s);

	cout << nueva.ToString ("nueva tras aniadir s") << endl;
  	cout << endl << endl;  


	nueva.Inserta (0, s);

	cout << nueva.ToString ("nueva tras insertar s en posicion 0") << endl;
  	cout << endl << endl;  

	
	nueva.Inserta (2, s);

	cout << nueva.ToString ("nueva tras insertar s en posicion 2") << endl;
  	cout << endl << endl; 

	cout << "Filas : " << nueva.NumFilas() << endl;  
	cout << "Cols  : " << nueva.NumColumnas() << endl;  

	/***********************************************************/
	// Operador de asignación
 
	
	Matriz2D m6 (6, 3); // Constructor de matriz 6x3
  
	cout << m6.ToString ("m6 (6x3)") << endl;
  	cout << endl;  

	m6 = (TipoBaseMatriz2D) 9; // Operador de asignación

	cout << m6.ToString ("m6 tras la asignacion m6 = 9") << endl;
  	cout << endl;  


  	Matriz2D copia_m6 (m6); 

	cout << m6.ToString ("copia_m6 (m6)") << endl;
  	cout << endl;  

  	
  	if (m6 ==  copia_m6) 
  		cout << "m6 == copia_m6" << endl; 
  	else 
  		cout << "m6 NO == copia_m6" << endl; 
  	cout << endl; 	


  	if (m6 == 9) 
  		cout << "m6 == 9" << endl; 
  	else 
  		cout << "m6 NO == 9" << endl; 
  	cout << endl; 	




	Matriz2D m7; // Constructor sin argumentos (matriz vacía)

	m7 = m6; // Operador de asignación 
 
	cout << m7.ToString ("m7 tras la asignacion m7 = m6") << endl;
  	cout << endl;  

	m7 = m3; // Operador de asignación 
 
	cout << m7.ToString ("m7 tras la asignacion m7 = m3") << endl;
  	cout << endl;  

	cout << "........................................" << endl << endl;
	
	
	/***********************************************************/
	// Operadores relacionales	
			
	cout << "........................................" << endl << endl;
	
	Matriz2D m, diagonal;
	
	cout << "Creadas matrices m y diagonal -vacias-" << endl;

	diagonal = m = m2;
	
	if (m == diagonal)
		cout << "m == diagonal";
	else 
		cout << "m NO == diagonal";
	cout << endl;

	if (m == m7)
		cout << "m == m7";
	else 
		cout << "m NO == m7";
	cout << endl;
	
	cout << "........................................" << endl << endl;

	return (0);
}

/**********************************************************************/
/**********************************************************************/
