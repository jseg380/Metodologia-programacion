#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

#include "funciones_Kaprekar.h"

using namespace std;


/***************************************************************************/
// Función que devuelve el número de cifras de un número int.
// Entrada: num, el valor a estudiar. 
// Devuelve:  número de cifras de "num".
// PRE: num>=0
/***************************************************************************/

int NumCifras (int num)
{		
	int cont = 0; // Contador de apariciones 

    while (num != 0) {
        num = num /10; // Descartamos la cifra menos significativa
  		cont++; 
    }

    return (cont);
}

/***************************************************************************/
// Calcula si todas las cifras de "num" son iguales.
// Entrada: num, el valor a estudiar. 
// Devuelve: true, si todas las cifras de "num" son iguales.
// PRE: num>=0
/***************************************************************************/

bool TodasCifrasIguales (int num)
{
	int ref = num % 10; // Cifra menos significativa (referencia)
    num = num / 10; 	// Descartamos la cifra menos significativa
    
	bool todas_iguales = true;

    while (num != 0 && todas_iguales) {

		if (ref != num % 10) todas_iguales=false;
        else num = num / 10; // Descartamos la cifra menos significativa
    }

    return todas_iguales;
}

/***********************************************************************/
// Calcula el número más pequeño posible con los dígitos de "num".
// Recibe: num, número a convertir.
// PRE: num>=0

int MinimoValorPosible (int num) 
{	
	int digitos[10] = {0};

	while (num>0) {
		digitos[num%10]++;
		num = num/10;
	}
	
	int resultado = 0;
	
	for (int i=1; i<10; i++)
		
		while (digitos[i]>0) {
			resultado=resultado*10 + i;
			digitos[i]--;
		}
	
	return resultado;
}

/***********************************************************************/
// Calcula el número más grande posible con los dígitos de "num".
// Recibe: num, número a convertir.
// PRE: num>=0

int MaximoValorPosible (int num) 
{	
	int digitos[10] = {0};
	
	while (num>0) {
		digitos[num%10]++;
		num = num/10;
	}
	
	int resultado = 0;
	
	for (int i=9; i>=0; i--)
		
		while (digitos[i]>0) {
			resultado=resultado*10 + i;
			digitos[i]--;
		}
	
	return resultado;
}

/***********************************************************************/
// Calcula el número más grande posible con los dígitos de "num" y lo 
// completa con ceros finales hasta alcanzar "num_digitos" digitos. 
// Si num_digitos <= NumDigitos(num) no se miodifica el número de dígitos. 
// Recibe: num, número a convertir.
// 		   num_digitos, número de dígitos del resultado. 
// PRE: num>=0

int MaximoValorPosible (int num, int num_digitos) 
{
	int resultado = MaximoValorPosible (num); 
	
	int digitos_faltan = num_digitos-NumCifras(num); 
	
	for (int i=0; i<digitos_faltan; i++)  
		resultado = resultado*10; 
		
	return resultado;
}

/***********************************************************************/
// Calcula el número de iteraciones que necesita el proceso Kaprekar 
// para converger.  
// Recibe: num, número de cuatro o menos cifras a verificar. 
// Devuelve: el número de iteraciones empleadas en llegar a CTE_KAPREKAR.
//
// PRE: VerificaKaprekar(num) == true
// PRE: num>=0

int IteracionesKaprekar (int num) 
{
	const int CTE_KAPREKAR = 6174;
	
	// Como se cumplen las precondiciones se asegura la convergencia.
	// En cada paso se genera un valor "num" de acuerdo a las indicaciones 
	// y en algún paso llegará a valer "CTE_KAPREKAR".
	
	int iteraciones = 0;
	 
	while (num != CTE_KAPREKAR) {

		iteraciones++; // Se ha completado una iteración 
			
		int menor = MinimoValorPosible(num);
		int mayor = MaximoValorPosible(num, 4);
		
		num = mayor-menor; // Nuevo valor de "num"
		
	} // while (num != CTE_KAPREKAR) 
	
	return iteraciones; 				
}

/***********************************************************************/
// Calcula si el número de iteraciones que requiere el proceso de 
// Kaprekar hasta converger es correcto.
// Recibe: num, número de cuatro o menos cifras a verificar. 
// Devuelve: true si el número de iteraciones empleadas es correcto.
//
// PRE: NumCifras(num) <= 4
// PRE: num>=0

bool VerificaKaprekar (int num) 
{
	bool verifica = true; 

	if (NumCifras(num)==4 && TodasCifrasIguales(num))
	
		verifica = false; 

	else {

		const int MAX_ITERACIONES_KAPREKAR = 7; 
	
		int iterac_para_num = IteracionesKaprekar(num); 
		
		if (iterac_para_num>MAX_ITERACIONES_KAPREKAR)
			verifica = false; 
		
	}	
		
	return verifica;
}
		
/***************************************************************************/
/***************************************************************************/

