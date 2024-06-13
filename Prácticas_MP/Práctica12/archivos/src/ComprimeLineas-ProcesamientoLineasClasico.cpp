/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
//
// Programa que lee una secuencia indefinida de caracteres de la entrada
// estándar y "comprime" todas las líneas de esa secuencia, eliminando
// los separadores que hay en cada línea, exceptuando el '\n'.
//
// Procesamiento a nivel de LINEA y gestion clásica (MALA DECISION) 
//
// Fichero: ComprimeLineas-ProcesamientoLineasClasico.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	const int TAM = 256;	// Máxima longitud de la cadena empleada
	char cad[TAM];			// para leer cada línea

	int pos_escritura;  // posición donde escribir 
	int pos_lectura;	// posición donde leer 


	cin.getline(cad, TAM);	// Lectura adelantada de una cadena

	while (!cin.eof()) {

		if (strlen(cad) > 0) {

			/* Algoritmo: 

			Recorrer todas las componentes que hay en el vector
				Si la componente actual no es un separador
					ponedla donde indique pos_escritura
				Avanzar pos_lectura
			*/

			pos_escritura = 0;		
		
			for (pos_lectura = 0; pos_lectura < strlen(cad); pos_lectura++){

				char c = cad[pos_lectura];	// Carácter a estudiar

				if (c!=' ' && c!='\t' && c!='\v' && c!='\f' && c!='\r') {

					cad[pos_escritura] = cad[pos_lectura];
					pos_escritura++;					
				
				}	// OJO: "pos_lectura" SIEMPRE avanza (for), mientras que
					// "pos_escritura" lo hace cuando salta un separador.

			} // for 

			cad[pos_escritura] = '\0';	// IMPORTANTE

		} // if (strlen(cad) > 0)

		cout << cad << endl;		// enviarla "comprimida" a cout

		cin.getline(cad, TAM);		// Nueva lectura

	} // while (!cin.eof()) 

	return (0);
}

/***************************************************************************/
/***************************************************************************/
