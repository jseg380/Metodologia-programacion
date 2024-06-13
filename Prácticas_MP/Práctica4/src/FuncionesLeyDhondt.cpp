#include <iostream>
#include <iomanip>

#include "FuncionesLeyDhondt.h"

using namespace std;


/////////////////////////////////////////////////////////////////////
// Función que lee el número de escaños, partidos y votos.
// Parámetros: Puntero que apunte a un vector de datos tipo
// 			   "Partido"
//			   Tamaño del vector de "Partidos"
//			   Puntero a vector de enteros donde almacenará
//			   el número de escaños en la posición 0 y el número
//			   de partidos en la posición 1


void LeeDatos (Partido *resultado, int tamanio, int *array_datos){
	
    int num_partidos; 	// Numero de partidos presentados	
	int num_escagnos;	// Numero de escaños a asignar
	
	// Lectura del número de escaños
	
	do{
		cout << "Num. de escagnos = ";
		cin >> num_escagnos;
	} while (num_escagnos<=0);
	
	cout << endl;
	
	// Lectura del número de partidos
	
	do{
		cout << "Num. de partidos = ";
		cin >> num_partidos;
	} while ((num_partidos<=0)||(num_partidos>tamanio));
	cout << endl;
	
	// Lectura del número de votos de cada partido
	
    cout << "Introducir el numero de votos de cada partido." << endl;
    
    for (int p = 0; p < num_partidos; p++) {

		long los_votos_partido_p;
		
		cout << endl; 

		do{
			cout << "\tPartido " << (char)('A'+ p) << " : ";
           	cin >>  los_votos_partido_p;
		} while (los_votos_partido_p < 0);       
        
        resultado[p].votos = los_votos_partido_p;
        resultado[p].sigla = 'A'+ p;
 		resultado[p].escagnos = 0;    
    }
    
    array_datos[0] = num_escagnos;
    array_datos[1] = num_partidos;
    
}


/////////////////////////////////////////////////////////////////////
// Función que calcula la cantidad de escaños 
// que le corresponden a cada partido.
// Parámetros: Puntero que apunte a un vector de datos tipo
// 			   "Partido"
//			   Número de escaños
//			   Número de partidos


void CalculaEscagnos (Partido *resultado, int num_escagnos, int num_partidos){
	
	int partido_max, max;
	
	// Cada escaño "e" se asigna de acuerdo al mayor cociente entre votos y 
	// escaños ya conseguidos más uno.
	// Esto es, el partido "p" para el que el cociente entre los votos totales 
	// conseguidos (distribucion[p].voto) y el número de escaños que le han 
	// sido asignados hasta ese momento (distribucion[p].escagnos) más uno 
	// sea mayor consigue el escaño "e"
	
    for (int e = 0; e < num_escagnos; e++) {
    	
    	max = -1; // Primer máximo
    	
    	// El máximo se calcula entre todos los partidos
    	
        for (int p = 0; p < num_partidos; p++) {
		
			
			
			// Cociente para el partido "p"
			double coc_p = resultado[p].votos/(resultado[p].escagnos+1);
			
			if (coc_p > max ) {
				max = coc_p;
                partido_max = p; 
			}
		}

		// Asignación el eacaño al partido "p"
		resultado[partido_max].escagnos++;
    }
}


/////////////////////////////////////////////////////////////////////
// Función que muestra la cantidad de escaños 
// que le corresponden a cada partido.
// Parámetros: Puntero que apunte a un vector de datos tipo
// 			   "Partido"
//			   Número de partidos


void MuestraResultado (Partido *resultado, int num_partidos){
	
	cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Distribucion de escaños: " << endl;
    cout << endl;
    
    
    for (int p = 0; p < num_partidos; p++) {
        cout << "\tPartido " << resultado[p].sigla;
 	    cout << " ("<< setw(8) << resultado[p].votos <<" votos) -->";
		cout << setw(3) << resultado[p].escagnos << " Escaños" << endl;
	}
	
    cout << "----------------------------------------------------" << endl;
    cout << endl;
}


