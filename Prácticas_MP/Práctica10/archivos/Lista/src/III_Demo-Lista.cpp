/***************************************************************************/
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
//
// Demostración de la funcionalidad de la clase Lista (1).
//
// Incluye: 
//		* constructor de copia
//		* destructor
//
// Fichero: III_Demo-Lista.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "TipoBase_Lista.h"
#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	// Constructor con un argumento: Crea una lista con 5 nodos y los 
	// inicializa al valor establecido por defecto

	Lista lista(5);

	cout << lista.ToString("Despues de crear la lista con tamaño 5");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << "Tercer elemento = " << lista.Valor(3) << endl;
	cout << endl;

	// Escribe el valor 0 en todos los nodos de la lista 

	lista.Ecualiza (0);
	cout << lista.ToString("Despues de lista.Ecualiza(0)");
	cout << endl;


	// Pruebas de inserción 

	// Inserta un nuevo nodo con valor 7 en la posicion 2 
	lista.Insertar(7,2); 

	cout << lista.ToString("Despues de lista.Insertar(7,2)");
	cout << "Tamanio = " << lista.Tamanio() << endl;	
	cout << endl;

	// Inserta un nuevo nodo con valor 9 al final (equivale a Insertar)
	lista.Insertar(9,lista.Tamanio()+1);

	cout << lista.ToString("Despues de lista.Insertar(9, lista.Tamanio()+1)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;
	
	// Inserta un nuevo nodo con valor 6 en la posicion 3 
	lista.Insertar(6,3);

	cout << lista.ToString("Despues de lista.Insertar(6,3)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;
	

	// Acceso (para lectura) elemento a elemento. 
	// Observe que 1 <= pos <= Tamanio()

	cout << "Valores de la lista, elemento a elemento: "<< endl;

	for (int pos=1; pos<=lista.Tamanio(); pos++)
		cout << "Elemento " << setw(2) << pos 
		     << " = " << setw (3) << lista.Valor(pos) << endl;
	cout << endl;


	// Pruebas de búsqueda 

	cout << endl; 
	cout << "Buscando el 7 ..." << endl;
	
	// Búsqueda con éxito
	int pos_7 = lista.Buscar (7);
	
	if (pos_7 != -1) 
		cout << "Encontrado en la posicion " << pos_7;
	else 
		cout << "No se ha encontrado.";
	cout << endl; 

	cout << endl; 
	cout << "Buscando el 33 ..." << endl;

	// Búsqueda con fracaso
	int pos_33 = lista.Buscar (33);
	
	if (pos_33 != -1) 
		cout << "Encontrado en la posicion " << pos_33;
	else 
		cout << "No se ha encontrado.";
	cout << endl; 


	// Pruebas de borrado y adición

	// Eliminar el nodo de la posición 2 
	lista.EliminarValor(2);

	cout << endl; 
	cout << lista.ToString("Despues de EliminarValor(2)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;

	// Eliminar el nodo de la posición 6 
	lista.EliminarValor(6);
	cout << lista.ToString("Despues de EliminarValor(6)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;
	
	// Eliminar el nodo de la posición 2 
	lista.Eliminar(2);
	cout << lista.ToString("Despues de Eliminar(2)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;
	
	// Añadir un nodo (al final) con el valor 3 
	lista.Aniadir(3);
	cout << lista.ToString("Despues de Aniadir(3)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl << endl;


	// Acceso (para escritura) para modificar el contenido de nodos.

	lista.Valor(1) = 1; // Modificar el contenido del nodo 1. Nuevo valor = 1
	lista.Valor(4) = 2; // Modificar el contenido del nodo 4. Nuevo valor = 2

	cout << lista.ToString("Despues de cambiar dos elementos");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;


	// Pruebas de borrado

	// Eliminaemos todos los nodos de la lista, uno a uno. 

	cout << "Borrando " << lista.Tamanio() << " nodos..." << endl;

	int num_nodos = lista.Tamanio();

	for (int i=1; i<=num_nodos; i++) {
	
		cout << "Borrando nodo con " << lista.Valor(1) << endl; 
	
		lista.Eliminar (1); // Borrar el primer nodo
	
		cout << lista.ToString("Borrado nodo 1");
		cout << "Quedan " << lista.Tamanio() << " nodos..." << endl;
		cout << endl;
	}

	if (lista.EstaVacia())
		cout << "La lista esta vacia" << endl;
	else 
		cout << "La lista NO esta vacia" << endl;
	cout << lista.ToString("");
	cout << endl;


	// Constructor sin argumentos: lista vacía

	Lista vacia;
	cout << vacia.ToString("Despues de crear lista vacia");
	cout << "Tamanio = " << vacia.Tamanio() << endl;
	cout << "Lista: ";
	if (vacia.EstaVacia())
		cout << "La lista esta vacia" << endl;
	else 
		cout << "La lista NO esta vacia" << endl;

	cout << endl;


	// Constructor con dos argumentos.

	// Crea una lista con lista con 6 nodos, todos con valor 9
	Lista lista_de_6_nodos (6, 9);

	cout << lista_de_6_nodos.ToString("Creada lista_de_6_nodos, todos a 9");
	cout << "Tamanio = " << lista_de_6_nodos.Tamanio() << endl;
	cout << "Tercer elemento = " << lista_de_6_nodos.Valor(3) << endl;

	if (lista_de_6_nodos.EstaVacia())
		cout << "La lista esta vacia" << endl;
	else 
		cout << "La lista NO esta vacia" << endl;

	cout << endl;


	// Prueba de constructor de copia 

	Lista copia (lista_de_6_nodos);
	cout << copia.ToString("copia de lista_de_6_nodos");
	
	cout << "Iguales copia y lista_de_6_nodos = " 
	     << (copia.EsIgualA(lista_de_6_nodos) ? "SI": "NO") << endl;	
	cout << endl;


	// Pruebas de clonación y de la función de comparación entre listas

	cout << endl;	
	cout << lista.ToString("lista antes de recibir un clon");

	lista.Clona (lista_de_6_nodos);

	cout << endl;	
	cout << lista.ToString("lista tras lista.Clona (lista_de_6_nodos)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	
	cout << "Lista: ";
	if (lista.EstaVacia())
		cout << "lista esta vacia" << endl;
	else 
		cout << "lista NO esta vacia" << endl;
	cout << endl;
	
	// Deberían ser iguales
	cout << "Iguales lista y lista_de_6_nodos = " 
	     << (lista.EsIgualA(lista_de_6_nodos) ? "SI": "NO") << endl;	
	cout << endl;

	cout << "Modifico casilla 2 de lista: " << endl; 
	lista.Valor (2) = 22; 
	cout << lista.ToString("lista tras lista.Valor (2) = 22");

	// No deberían ser iguales
	cout << "Iguales lista y lista_de_6_nodos = " 
	     << (lista.EsIgualA(lista_de_6_nodos) ? "SI": "NO") << endl;	
	cout << endl;


	//......................................................................
	// Pruebas de SubLista

	cout << endl;	
	cout << ".........................................." << endl;	
	cout << endl;	

	// "sub" debería ser una lista vacía
	Lista sub (lista.SubLista(-1, 22));

	cout << "Se ha ceado sub (lista.SubLista(-1, 22)) : " << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	
	
	cout << sub.ToString("Lista sub (lista.SubLista(-1, 22))");
	cout << endl;

	// "sub" debería ser una lista vacía
	sub.Clona(lista.SubLista(lista.Tamanio()+1, 22));

	cout << "sub.Clona(lista.SubLista(lista.Tamanio()+1, 22))" << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	
	
	cout << sub.ToString("sub.Clona(lista.SubLista(lista.Tamanio()+1, 22))");
	cout << endl;

	// "sub" debería ser una copia de "lista" 
	sub.Clona(lista.SubLista(1, lista.Tamanio()));

	cout << "sub.Clona(lista.SubLista(1, lista.Tamanio())" << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	
	
	cout << sub.ToString("sub.Clona(lista.SubLista(1, lista.Tamanio())");

	cout << "Iguales lista y sub = " 
	     << (lista.EsIgualA(sub) ? "SI": "NO") << endl;	
	cout << endl;

	// "sub" debería ser una copia de "lista" 
	sub.Clona(lista.SubLista(1, lista.Tamanio()+22));

	cout << "sub.Clona(lista.SubLista(1, lista.Tamanio()+22)" << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	
	
	cout << sub.ToString("sub.Clona(lista.SubLista(1, lista.Tamanio()+22)");

	cout << "Iguales lista y sub = " 
	     << (lista.EsIgualA(sub) ? "SI": "NO") << endl;	
	cout << endl;

	// "sub" debería tener 2 nodos menos que "lista". En este caso no se 
	// toman ni el primero ni el último 	
	sub.Clona(lista.SubLista(2, lista.Tamanio()-2));

	cout << "sub.Clona(lista.SubLista(2, lista.Tamanio()-2)" << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	
	
	cout << sub.ToString("sub.Clona(lista.SubLista(2, lista.Tamanio()-2)");

	cout << "Iguales lista y sub = " 
	     << (lista.EsIgualA(sub) ? "SI": "NO") << endl;	
	cout << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
