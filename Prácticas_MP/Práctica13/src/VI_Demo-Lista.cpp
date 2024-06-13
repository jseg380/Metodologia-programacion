/***************************************************************************/
/***************************************************************************/
//
// Autor: Juan Manuel Segura Duarte
// Basado en el .cpp de Francisco José Cortijo Bon
//
// RELACION DE PROBLEMAS 6
//
// Demostración de la funcionalidad de la clase Lista.
//
// Fichero: VI_Demo-Lista.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	Lista lista(5);

	cout << lista.ToString ("Despues de crear la lista con 5 nodos");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	cout << endl;

	
	lista = 0;
	cout << lista.ToString ("Despues de lista = 0");

	lista.Insertar(7,2);
	cout << lista.ToString ("Despues de lista.Inserta(7,2)");

	lista.Insertar(9,lista.Tamanio()+1);
	cout << lista.ToString ("Despues de lista.Inserta(9, lista.Tamanio()+1)");
	
	lista.Insertar(6,3);
	cout << lista.ToString ("Despues de lista.Inserta(6,3)");
	
	cout << lista.ToString ("Mostrando informacion");


	cout << endl;
	cout << ".................." << endl;
	cout << endl;
	cout << "Resultado de cout << lista " << endl;
	cout << endl;

	cout << lista << endl;
	
	cout << ".................." << endl;
	cout << endl;


	for (int pos=1; pos<=lista.Tamanio(); pos++)
		cout << "Elemento " << setw(2) << pos 
		     << " = " << setw (3) << lista[pos]<< endl;
	cout << endl;


	// Guardar lista en un fichero
	

	cout << endl;
	cout << "Escribiendo lista en fichero" << endl; 
	cout << endl;

	lista.EscribirLista ("datos/datos_de_lista.txt");

	cout << lista.ToString ("lista despues de EscribirLista");
	cout << endl;


	// Constructor leyendo datos de un fichero
	
	Lista lista_leida ("datos/datos_de_lista.txt");
	
	cout << lista_leida.ToString ("Despues de crear lista_leida");


	if (lista != lista_leida) 
		cout << "Ha habido algun problema guardando o leyendo datos." << endl;
	else 
		cout << "Perfecto: se ha guardado y leido correctamente." << endl;
	cout <<  endl;


	// Prueba del metodo de lectura desde un fichero

	Lista otra_lista_leida;
	
	otra_lista_leida.LeerLista ("datos/datos_de_lista.txt");

	cout << otra_lista_leida.ToString ("Despues de leer con LeerLista");


	if (lista != otra_lista_leida) 
		cout << "Ha habido algun problema guardando o leyendo datos." << endl;
	else 
		cout << "Perfecto: se ha guardado y leido correctamente." << endl;
	cout <<  endl;
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
