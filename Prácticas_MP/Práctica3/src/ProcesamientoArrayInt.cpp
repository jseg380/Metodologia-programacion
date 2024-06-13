#include <iostream>
#include <iomanip>
#include "GeneradorAleatorioEnteros.h"
#include "ProcesamientoArrayInt.h"

using namespace std;


void MuestraVector (int *p, int num_datos, int num_datos_linea)
{
	for (int i=0; i<num_datos; i++) {

		char separador = (((i+1)%num_datos_linea)==0) ? '\n':' ';
		cout <<setw(4)<< *(p+i) << separador;
	}
}

void RellenaVector (int *p, int num_datos, int min_aleat, int max_aleat)
{
	GeneradorAleatorioEnteros generador(min_aleat, max_aleat);
	
	for (int i = 0 ; i < num_datos ; i++)
		*(p+i) = generador.Siguiente();
}

void OrdenaSeleccion (int *v, int pos_inic, int pos_final)
{
}

void OrdenaInsercion (int *v, int pos_inic, int pos_final)
{
}

void OrdenaIntercambio (int *v, int pos_inic, int pos_final)
{
}
