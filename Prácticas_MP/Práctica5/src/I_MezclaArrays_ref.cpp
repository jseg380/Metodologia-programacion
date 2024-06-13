#include <iostream>
#include <cstdlib>

#include "ProcesamientoArrayInt.h"
using namespace std;


int main (int argc, const char ** argv){
	
	// Declaración de un vector de tamaño TAM
	
	const int TAM = 100;
	int vector1[TAM], vector2[TAM];
	int util_vector = 0, min_aleat, max_aleat;
	const char * afirmacion = "no";
	
	
	// Comprobación de argumentos
	
	if (argc > 5){
		cerr << "Error: demasiados argumentos" << endl;
		cerr << "Se esperaban 5 o menos argumentos" << endl;
		
		// Escribir como sería su uso
		
		exit(1);
	}
	
	// Si se ejecuta el programa sin argumentos
	
	// Si se ponen en la declaración los valores que se piden se puede
	// 1. Recolección de argumentos
	// 2. Comprobación de argumentos
	// 3. Comprobación de la validez de los argumentos
	
	// Todo lo que no es 0 es true, 0 es false
	// 0 == false
	// !0 == true
	
	if (argc == 1){
		
		// Se establece el número de elementos útiles de ambos
		// vectores al tamaño de estos (TAM)
		
		util_vector = TAM;
		util_vector = TAM;
		
		// También se puede hacer así
		util_vector1 = util_vector2 = TAM;
		
		// Se establecen el mínimo y máximo para generar los números aleatorios
		// que rellenarán a los vectores a 1 y 200 respectivamente
		
		min_aleat = 1;
		max_aleat = 200;
	}
	
	// Si se ejecuta el programa con un argumento
	
	else if (argc == 2){
		
		// Se establece el número de elementos útiles de ambos vectores
		// al número que se ha introducido en el argumento 1
		
		util_vector = atoi(argv[1]);
		util_vector = util_vector;
		
		// Se establecen el mínimo y máximo para generar los números aleatorios
		// que rellenarán a los vectores a 1 y 200 respectivamente
		
		min_aleat = 1;
		max_aleat = 200;
	}
	
	// Si se ejecuta el programa con dos argumentos
	
	else if (argc == 3){
		
		// Se establece el número de elementos útiles de ambos vectores
		// al número que se ha introducido en el argumento 1
		
		util_vector = atoi(argv[1]);
		util_vector = util_vector;
		
		// Se establece el mínimo para generar los números aleatorios
		// que rellenarán a los vectores a 1
		
		min_aleat = 1;
		
		// Se establece el máximo para generar los números aleatorios
		// que rellenarán a los vectores al número que se ha introducido
		// en el argumento 2
		
		max_aleat = atoi(argv[2]);
	}
	
	else if (argc == 4){
		
		// Se establece el número de elementos útiles de ambos vectores
		// al número que se ha introducido en el argumento 1
		
		util_vector = atoi(argv[1]);
		
		
		// Se establecen el mínimo y máximo para generar los números aleatorios
		// que rellenarán a los vectores con los argumentos 2 y 3
		
		int arg2, arg3;
		
		arg2 = atoi(argv[2]);
		arg3 = atoi(argv[3]);
		
		if (arg2 > arg3){
			int tmp;
			
			tmp = arg2;
			arg2 = arg3;
			arg3 = tmp;
		}	
			
		min_aleat = arg2;
		max_aleat = arg3;
	}
	
	else if (argc == 5){
		
		// Se establece el número de elementos útiles de ambos vectores
		// al número que se ha introducido en el argumento 1
		
		util_vector = atoi(argv[1]);
		
		
		// Se establecen el mínimo y máximo para generar los números aleatorios
		// que rellenarán a los vectores con los argumentos 2 y 3
		
		int arg2, arg3;
		
		arg2 = atoi(argv[2]);
		arg3 = atoi(argv[3]);
		
		if (arg2 > arg3){
			int tmp;
			
			tmp = arg2;
			arg2 = arg3;
			arg3 = tmp;
		}	
			
		min_aleat = arg2;
		max_aleat = arg3;
		
		afirmacion = argv[4];
	}
	
	
	// Rellena los vectores con util_vector números
	// aleatorios entre min_aleat y max_aleat
	
	RellenaVector(vector1, util_vector, min_aleat, max_aleat);
	RellenaVector(vector2, util_vector, min_aleat, max_aleat);
	
	// Se ordenan los vectores por el método de selección
	
	OrdenaSeleccion(vector1, util_vector);
	OrdenaSeleccion(vector2, util_vector);
	
	// Se muestran por pantalla los vectores
	
	const char * mensaje = "Vector 1:";
	const int DATOS_LINEA = 10;
	
	MuestraVector(mensaje, vector1, util_vector, DATOS_LINEA);
	
	mensaje = "Vector 2:";
	
	MuestraVector(mensaje, vector2, util_vector, DATOS_LINEA);
	
	// Vector donde se mezclaran los otros vectores
	
	int util_mezcla = 2 * util_vector;
	int mezcla[util_mezcla];
	
	// Se mezclan los vectores en función del argumento 4, si este
	// argumento es "SI", "si", "sI" o "Si" entonces la ordenación
	// se hace selectivamente, en caso contrario se hace ordenación normal.
	
	mensaje = "Vector ordenado:";
	
	MezclaVectores(mezcla, util_mezcla, vector1, util_vector, vector2,
				   util_vector, afirmacion);
	
	MuestraVector(mensaje, mezcla, util_mezcla, DATOS_LINEA);
	
	return 0;
}
