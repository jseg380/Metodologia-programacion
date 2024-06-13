/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
/* 
	El matemático D.R. Kaprekar descubrió en 1949 una característica del 
	número 6174 (conocido como constante de Kaprekar), la cual está 
	relacionada con el siguiente proceso iterativo. 
	
		Dado un número estrictamente positivo de cuatro cifras (o menos) 
		que tenga al menos dos dígitos diferentes (los numeros con menos 
		de cuatro dígitos se completan colocando el dígito 0 al principio, 
		por lo que el numero 9 se convierte en 0009, por ejemplo):
		
			1. 	Colocar sus dígitos en orden descendente y en orden ascendente 
				para formar dos nuevos números.
			2. 	Restar el menor al mayor.
			3. 	Volver al paso 1 considerando ahora el resultado de la resta 
				del paso 2.

	La curiosa característica de este proceso es que SIEMPRE converge al 
	número 6174 (y como mucho, en 7 iteraciones).	
	
	Observe cómo se alcanza la constante de Kaprekar para los números 
	3524, 1121 y 25 en 7 ó menos iteraciones:
	
			 | 	 3524            |     1121          |      25
	(Paso 1) | 5432..2345 = 3087 | 2111..1112 = 0999 | 5200..0025 = 5175 | 
	(Paso 2) | 8730..0378 = 8352 | 9990..0999 = 8991 | 7551..1557 = 5994 |
	(Paso 3) | 8532..2358 = 6174 | 9981..1899 = 8082 | 9954..4599 = 5355 |
	(Paso 4) |                   | 8820..0288 = 8532 | 5553..3555 = 1998 |
	(Paso 5) |                   | 8532..2358 = 6174 | 9981..1899 = 8082 | 
	(Paso 6) |                   |                   | 8820..0288 = 8532 | 
	(Paso 7) |                   |                   | 8532..2358 = 6174 |

	Debemos tener en cuenta que los únicos números de cuatro
	cifras para los que el proceso de Kaprekar no alcanza el número 6174 
	son aquellos cuyas cuatro cifras son iguales (como 1111), pues, en 
	la primera iteración, se alcanzará el valor 0.	
	
	Este programa lee un número indeterminado de enteros estrictamente 
	positivos (termina con un valor negativo) de cuatro o menos cifras y 
	compruebe la convergencia del proceso descrito para cada uno de ellos. 
	
	El programa indica: 
		1) si se verifica la convergencia y 
		2) cuántas iteraciones se han necesitado.
*/
/***************************************************************************/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

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

int main()
{	
	cout.setf (ios::fixed);
	cout.setf (ios::showpoint);

	int num; 
	
	// Lectura adelantada del número que se analiza
	
	cout << endl; 			
	cout << "Escriba un numero de cuatro o menos cifras"
	     << " (negativo o cero para finalizar) = "; 
	cin >> num;	
	
	while (num > 0) {

		cout << endl; 
						
		if (NumCifras(num)>4) 
			
			cout << "Numero no admitido (mas de cuatro cifras)." << endl;
		
		else {
							
			if (VerificaKaprekar(num)) {
				
				int iterac = IteracionesKaprekar(num);
				cout << "Se verifica la propiedad de Kaprekar." << endl;	
				cout << "Iteraciones requeridas = ";  
				cout << setw(2) << iterac << endl;	
			}
			else  {
				
				cout << "No se verifica la propiedad de Kaprekar." << endl;	

			 	if (TodasCifrasIguales(num)) 
			 		cout << "Todas las cifras con iguales" << endl;	
				else 
			 		cout << "Demasiadas iteraciones" << endl;	
			}		
		}
		
		cout << endl; 
		
		// Nueva lectura
		
		cout << endl; 			
		cout << "Escriba un numero de cuatro o menos cifras"
		     << " (negativo o cero para finalizar) = "; 
		cin >> num;	

	} // while (num > 0)
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
