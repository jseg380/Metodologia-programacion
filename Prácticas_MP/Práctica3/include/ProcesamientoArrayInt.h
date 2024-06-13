#ifndef PROCESAMIENTO_ARRAY_INT
#define PROCESAMIENTO_ARRAY_INT

/***************************************************************************/
// Función que muestra un vector por pantalla.
// Entrada: la dirección desde la cual se quiere mostrar el vector,
//			la cantidad de elementos del vector a mostrar y la cantidad
//			de elementos por pantalla que se desean mostrar
// Devuelve: 
// PRE: *p apunte a un vector

void MuestraVector (int *p, int num_datos, int num_datos_linea);

/***************************************************************************/
// Función que rellena un vector con números aleatorios de un cierto intervalo.
// Entrada: la dirección desde la cual se quiere rellenar el vector,
//			la cantidad de elementos del vector a rellenar y los extremos
//			del intervalo del cual se escogeran números aleatorios para
//			introducir en el vector.
// Devuelve: 
// PRE: *p apunte a un vector

void RellenaVector (int *p, int num_datos, int min_aleat, int max_aleat);

/***************************************************************************/
// Función que ordena un vector utilizando el método de ordenación de
// selección.
// Entrada: una dirección de un elemento del vector, las posiciones de los
//			intervalos en los que se quiere ordenar el vector
// Devuelve: 
// PRE: *p apunte a un elemento de un vector
//		pos_inic >= 0 && pos_final < Tamaño del vector

void OrdenaSeleccion (int *v, int pos_inic, int pos_final);

/***************************************************************************/
// Función que ordena un vector utilizando el método de ordenación de
// inserción.
// Entrada: una dirección de un elemento del vector, las posiciones de los
//			intervalos en los que se quiere ordenar el vector
// Devuelve: 
// PRE: *p apunte a un elemento de un vector
//		pos_inic >= 0 && pos_final < Tamaño del vector

void OrdenaInsercion (int *v, int pos_inic, int pos_final);

/***************************************************************************/
// Función que ordena un vector utilizando el método de ordenación de
// intercambio.
// Entrada: una dirección de un elemento del vector, las posiciones de los
//			intervalos en los que se quiere ordenar el vector
// Devuelve: 
// PRE: *p apunte a un elemento de un vector
//		pos_inic >= 0 && pos_final < Tamaño del vector

void OrdenaIntercambio (int *v, int pos_inic, int pos_final);

/***********************************************************************/

#endif
