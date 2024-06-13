/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Rellena de manera aleatoria una secuencia de "num_valores" valores 
// (son valores aleatorios comprendidos entre "min_aleat" y "max_aleat". 
//
// Uso: II_OrdenarLista_Basico [num_valores][min_aleat][max_aleat]" 
//
// A continuación ordena la lista por el método de selección. 
// Finalmente, libera el espacio ocupado. 
//
// Fichero: II_OrdenarLista_Basico.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstdlib>

#include "TipoBaseLista.h"
#include "Lista.h"
#include "GeneradorAleatorioEnteros.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (int argc, char ** argv)
{
	const int MIN_ALEAT =   0;  // Mínimo valor aleatorio permitido
	const int MAX_ALEAT = 100;	// Máximo valor aleatorio permitido

	//.............................................................
	// Procesar argumentos

	if (argc>4) {
		cerr << "Error: demasiados argumentos" << endl << endl;
		cerr << "Uso: "<<argv[0]<< "[num_valores][min_aleat][max_aleat]" 
		     << endl;
		exit(1);
	}
	
	// Valores por defecto

	int num_valores = 10;
	int min_aleat = MIN_ALEAT;
	int max_aleat = MAX_ALEAT;


	// Otros valores 

	if (argc > 1) {

		num_valores = atoi(argv[1]); // "usados" será argv[1] 
	
		if (argc > 2) {

			max_aleat = atoi(argv[2]); // actualizar "max_aleat". 
									   // "min_aleat" es MIN_ALEAT
			if (argc > 3) {	

				max_aleat = atoi(argv[2]); // actualizar "max_aleat" y 
				min_aleat = atoi(argv[3]); // "min_aleat"
			}
		}
	}

	// Comprobar la validez de "num_valores"
	if (num_valores < 0)  {
		cerr << "Error: numero de casillas ("<< num_valores<< ") incorrecto."; 
		cerr << " Debe ser 0 <= num_valores "<< endl << endl;
		exit(3);
	}

	if (min_aleat > max_aleat) {
		int tmp = min_aleat; 
		min_aleat = max_aleat;
		max_aleat = tmp;
	}

	cout << endl; 
	cout << "Se va a crear una lista de " << num_valores << " datos." << endl;
	cout << "Los datos estarán comprendidos entre "<< min_aleat << " y " 
         << max_aleat << " (incluidos)" << endl; 
	cout << endl; 


	// Fin comprobación argumentos
	//.......................................................................

	// Crear una lista de valores aleatorios, y mostrarla

	GeneradorAleatorioEnteros generador (min_aleat, max_aleat);

	Lista l = ConstruyeLista();

	for (int i=0; i<num_valores; i++) 
		Aniade (l, (TipoBase) generador.Siguiente()); 

	cout << "Lista original:" << endl;	
	cout << endl;
	cout << ToString (l); 
	cout << endl;


	// Ordenar la lista (si no está vacía y no está ordenada) 

	if (!EstaVacia(l)) {

		if (EstaOrdenada(l))

			cout << "Esta ordenada" << endl;

		else  {
		
			cout << "No esta ordenada --> Ordenando por seleccion" << endl;
			cout << endl;		

			OrdenaSeleccion (l); 
				
			// Comprobamos si está bien ordenada....
			
			if (EstaOrdenada (l)) {

				cout << endl;
				cout << "Lista ordenada." << endl;
				cout << endl;
				cout << ToString (l); 
				cout << endl;
			}
			else {
				cout << "No esta ordenada (PROBLEMA)" << endl;
				cout << endl;
				cout << ToString (l); 
				cout << endl;
			}

		} // else EstaOrdenada (l)

	} // if (!EstaVacia(l)) 
	
	cout << endl; 
	

	// Destruir lista
	
	DestruyeLista (l);
		
	return 0;
}

/***************************************************************************/
/***************************************************************************/
