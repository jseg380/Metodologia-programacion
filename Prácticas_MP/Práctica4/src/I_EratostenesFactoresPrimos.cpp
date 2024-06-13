/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Fichero: Eratostenes_Array_para_Descomposicion.cpp
//
/*	
	Uso de los primos calculados mediante la criba de Eratóstenes.
	Se usarán para descomposición los primos hasta MAX_PRIMO (incluido).
	
	Aplicación: Calcular la descomposición en factores primos de un número.
*/
/***************************************************************************/

#include "FuncionesEratostenesFactoresPrimos.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	
	// El vector "primos" contendrá los "MAX_DATOS" primeros primos 
	int  primos[MAX_DATOS];
	
	EratostenesDescomposicionFactoresPrimos (primos);
	
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
