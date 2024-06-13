#ifndef FUNCIONES_LEY_DHONDT
#define FUNCIONES_LEY_DHONDT


// La informacion de cada partido se guarda en un struct
struct Partido {
	char sigla;		// "Nombre" del partido
	long votos;		// Votos recibidos
	int escagnos;	// Escaños conseguidos
};

/////////////////////////////////////////////////////////////////////
// Función que lee el número de escaños, partidos y votos.
// Parámetros: Puntero que apunte a un vector de datos tipo
// 			   "Partido"
//			   Tamaño del vector de "Partidos"
//			   Puntero a vector de enteros donde almacenará
//			   el número de escaños en la posición 0 y el número
//			   de partidos en la posición 1

void LeeDatos (Partido *resultados, int tamanio, int *array_datos);

/////////////////////////////////////////////////////////////////////
// Función que calcula la cantidad de escaños 
// que le corresponden a cada partido.
// Parámetros: Puntero que apunte a un vector de datos tipo
// 			   "Partido"
//			   Número de escaños
//			   Número de partidos

void CalculaEscagnos (Partido *resultado, int num_escagnos, int num_partidos);

/////////////////////////////////////////////////////////////////////
// Función que muestra la cantidad de escaños 
// que le corresponden a cada partido.
// Parámetros: Puntero que apunte a un vector de datos tipo
// 			   "Partido"
//			   Número de partidos

void MuestraResultado (Partido *resultado, int num_partidos);


#endif
