/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Fichero: Ley_Dhondt.cpp
//
/*	El sistema d'Hondt es un método que se utiliza para asignar escaños en 
   	sistemas de representación proporcional por listas electorales.

	Reparto:
		Tras escrutar todos los votos, se calculan cocientes sucesivos para 
		cada lista electoral. La fórmula de los cocientes es:

	    cociente = V_i / (S_i + 1)

	donde: 

    	V_i representa el número total de votos recibidos por el partido i, 
    	S_i representa el número de escaños que ha obtenido hasta el momento 
			el partido i (inicialmente 0 para cada lista).

	El número de votos recibidos por cada lista se divide sucesivamente por 
	cada uno de los divisores, desde 1 hasta el número total de escaños 
	a repartir. Cada escaño se asigna al partido cuyo cociente sea máximo. 
	La asignación de cada escaño se determina hallando el máximo de los 
	cocientes y asignando a cada uno un escaño, hasta que éstos se agoten
	
	Ejemplo:
	Supongamos unas elecciones a las que se presentan 5 partidos, 
	entre los que deben repartirse 7 escaños

		    Partido A       Partido B      Partido C    Partido D   Partido E
	Votos 	340000          280000         160000       60000 		15000

	Escaño
 	   1   *(340/1) 340     (280/1) 280    (160/1) 160  (60/1) 60 	(15/1) 15
 	   2    (340/2) 170    *(280/1) 280    (160/1) 160  (60/1) 60 	(15/1) 15
 	   3   *(340/2) 170     (280/2) 140    (160/1) 160  (60/1) 60 	(15/1) 15
 	   4    (340/3) 113.3   (280/2) 140   *(160/1) 160  (60/1) 60 	(15/1) 15
 	   5    (340/3) 113.3  *(280/2) 140    (160/2)  80  (60/1) 60 	(15/1) 15
 	   6   *(340/3) 113.3   (280/3)  93.3  (160/2)  80  (60/1) 60 	(15/1) 15
 	   7    (340/4)  85    *(280/3)  93.3  (160/2)  80  (60/1) 60 	(15/1) 15
 	
	Escaños asignados: Partido A = 3, Partido B = 3 y Partido C = 1
*/
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "FuncionesLeyDhondt.h"

using namespace std;


int main()
{
	// La información de los partidos se guarda en un array de datos "Partido"
	const int  CAPACIDAD = 20;
	Partido resultado[CAPACIDAD];
	
	int array_datos[CAPACIDAD];
	
	int num_escagnos;	// Numero de escaños a asignar
    int num_partidos; 	// Numero de partidos presentados
	
	
	LeeDatos (resultado, CAPACIDAD, array_datos);
	
	num_escagnos = array_datos[0];
	num_partidos = array_datos[1];
	
	
	CalculaEscagnos (resultado, num_escagnos, num_partidos);
    
    
	MuestraResultado (resultado, num_partidos);
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
