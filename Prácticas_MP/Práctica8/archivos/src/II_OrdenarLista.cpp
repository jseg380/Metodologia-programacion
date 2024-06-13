/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Rellena de manera aleatoria una secuencia de 10 valores reales positivos 
// entre 1 y 100, los guarda en una lista enlazada y los muestra. 
// A continuación ordena la lista
// Finalmente, libera el espacio ocupado. 
//
// Fichero: II_OrdenarLista.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstdlib>

#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (int argc, char ** argv)
{
	const int MIN_ALEAT =   0;  // Mínimo valor aleatorio permitido
	const int MAX_ALEAT = 100;	// Máximo valor aleatorio permitido

	//.............................................................
	// Procesar argumentos

	if (argc>5) {
		cerr << "Error: demasiados argumentos" << endl << endl;
		cerr << "Uso: "<<argv[0]<< "[tipo][num_datos][min_aleat][max_aleat]" 
		     << endl;
		cerr << "tipo = 1(selec), 2(ins), 3(inter) y 4(inter_mej)" << endl; 
		exit(1);
	}
	
	// Valores por defecto

	int tipo_ordenacion = 1;
	int num_valores = 10;
	int min_aleat = MIN_ALEAT;
	int max_aleat = MAX_ALEAT;


	// Otros valores 

	if (argc > 1) {

		tipo_ordenacion= atoi(argv[1]); // "tipo_ordenacion" será argv[1] 
		
		if (argc > 2) {

			num_valores = atoi(argv[2]); // "usados" será argv[2] 
		
			if (argc > 3) {

				max_aleat = atoi(argv[3]); // actualizar "max_aleat". 
										   // "min_aleat" es MIN_ALEAT
				if (argc > 4) {	

					max_aleat = atoi(argv[3]); // actualizar "max_aleat" y 
					min_aleat = atoi(argv[4]); // "min_aleat"
				}
			}
		}
	}

	// Comprobar la validez de "tipo_ordenacion"
	if ((tipo_ordenacion < 1) || (tipo_ordenacion > 4))  {
		cerr << "Error: tipo ordenacion (" << tipo_ordenacion << ") erroneo. "; 
		cerr << "Debe ser 1(selec), 2(ins), 3(inter) o 4(inter_mej)"<< endl;
		exit(2);
	}

	// Comprobar la validez de "usados"
	if (num_valores < 0)  {
		cerr << "Error: numero de casillas (" << num_valores << ") incorrecto. "; 
		cerr << "Debe ser 0 <= num_valores "<< endl << endl;
		exit(3);
	}


	cout << endl; 
	cout << "Se va a crear una lista de " << num_valores << " datos." << endl;
	cout << "Los datos estarán comprendidos entre "<< min_aleat << " y " 
         << max_aleat << " (incluidos)" << endl; 
	cout << endl; 

	// Fin comprobación argumentos
	//.......................................................................

	Lista l = CreaListaAleatoria (num_valores, min_aleat, max_aleat); 

	if (!EstaVacia(l)) {

		cout << "Lista original:" << endl;	
		cout << endl;
		cout << ToString (l); 
		cout << endl;

		cout << endl;
		cout << "Ordenar una secuencia de datos" << endl;
		cout << endl;

		if (EstaOrdenada(l))

			cout << "Esta ordenada" << endl;

		else  {
		
			cout << "No esta ordenada --> Ordenando lista" << endl;
			cout << endl;		

			Lista copia_l = CreaLista(); 
			Clona (copia_l, l);

			switch (tipo_ordenacion) {
				case (1) : 	
					cout << "Ordenando por seleccion" << endl;  
					OrdenaSeleccion (copia_l); 
					break; 
				case (2) : 	
					cout << "Ordenando por insercion" << endl;  
					OrdenaInsercion (copia_l); 
					break; 
				case (3) : 	
					cout << "Ordenando por intercambio" << endl;  
					OrdenaIntercambio (copia_l); 
					break;  
				case (4) : 	
					cout << "Ordenando por intercambio mejorado" << endl;  
					OrdenaIntercambioMejorado (copia_l); 
					break;  
			}
				
			if (EstaOrdenada (copia_l)) {

				cout << endl;
				cout << "Esta ordenada" << endl;
				cout << endl;

				cout << "Lista ordenada:" << endl;	
				cout << endl;
				cout << ToString (copia_l); 
				cout << endl;

			}
			else {

				cout << "No esta ordenada (PROBLEMA)" << endl;
				exit (1);
			}

			DestruyeLista (copia_l);

		} // else EstaOrdenada (l)

	}
	else cout << "La lista esta vacia." << endl;

	cout << endl; 
	

	// Destruir listas
	
	DestruyeLista (l);
		
	return 0;
}

/***************************************************************************/
/***************************************************************************/
