#include <iostream>
#include <iomanip>
#include <string>

#include "FuncionesEratostenesFactoresPrimos.h"



////////////////////////////////////////////////////////////////////////////
// Función que inicializa el vector de bool tal que criba los números
// que los elementos que contengan true serán primos (el número del lugar
// que ocupa).
// Parámetros : Puntero que apunte a un vector de bool

void InicializaVectorBool (bool *es_primo){

	using namespace std;
	
	cout << endl;
	cout << "Se calcularan los primos menores que " << MAX_PRIMO << endl;
	cout << "con un máximo de " << MAX_DATOS << " valores." << endl;
	cout << endl;
	
	
	// Inicialmente se considerarán todos primos y se irán "tachando" 
	// (fijándose a FALSE) los valores no-primos. 
	
	for (int i=0; i<=MAX_PRIMO; i++) 
		es_primo[i] = true;

	// Criba 
	
	for (int num=2; num*num <= MAX_PRIMO; num++) { // empezar por num=2 y 
										           // terminar si num^2>limite
		if (es_primo[num]) {

			for (int k=2; k*num <= MAX_PRIMO; k++) { // marcar los múltiplos de   
				es_primo[k*num] = false;		  	 // "num" como no-primos
			}
		} // if (es_primo[num])

	} // for num
}


////////////////////////////////////////////////////////////////////////////
// Función que inicializa un vector de enteros con números primos desde
// 1 hasta MAX_PRIMO, utilizando un vector de bool con el valor true en 
// las posiciones que son representadas por números primos
// Parámetros : Puntero que apunte a un vector de bool
//				Puntero que apunte a un vector de enteros
// Devuelve : 	El valor de números que tiene el vector

int RellenaVectorPrimos (bool *es_primo, int *primos){
	int num_primos = 0; // Número de casillas ocupadas
	//PRE: 0 <= num_primos < MAX_DATOS
		
	// Ya están "tachados" los números no-primos en "es_primo".  
	// Ahora recorremos "es_primo" completamente y copiamos a 
	// "primos" únicamente los que permacenen a "true". 

	for (int i=1; i<=MAX_PRIMO; i++) { 
									
		if (es_primo[i]) {	
		
			if (num_primos<MAX_DATOS) {
				primos[num_primos] = i;  // Añadir "i" a "primos"
				num_primos++;  	// Actualizar "num_primos"
			}
		}
		
	} // for
	
	return num_primos;
}


////////////////////////////////////////////////////////////////////////////
// Función que muestra los primos calculados en la función RellenaVectorPrimos
// Parámetros : Puntero que apunte a un vector de enteros que
//				contiene los números primos

void MuestraVectorPrimos (int *primos,int num_primos){
	
	using namespace std;
	
	cout << endl;
	cout << "Se han calculado " << num_primos << " primos." << endl;
	cout << endl;

	cout << "------------------------------------------------" << endl;
	cout << "Primos calculados: " << endl; 
	cout << endl; 


	for (int i=0; i<num_primos; i++) 
		cout <<setw(4) << primos[i] << (((i+1)%DATOS_POR_LINEA!=0)?" ":"\n");
	cout << endl;		

	cout << endl; 
	cout << "------------------------------------------------" << endl;
}


////////////////////////////////////////////////////////////////////////////
// Función que lee un valor para calcular su descomposición en factores primos
// Parámetros : Puntero que apunte al vector con los primos
//				La cantidad de números primos que tiene el vector

void DescomposicionFactoresPrimos (int *primos, int num_primos){
	
	using namespace std;
	
	// struct para guardar las parejas primo-potencia
	
	struct Pareja {
		int primo;		// Número primo (factor primo)
		int potencia;	// Veces que aparece en la descomposición 
	}; 


	const string TITULO_LECTURA = "Valor a descomponer (finalizar con " + 
	                              to_string(TERMINADOR) + ") : ";

	int valor; // Número a descomponer
	
	//  Lectura	

	do {
		cout << endl;
		cout << TITULO_LECTURA;
		cin >> valor;
	} while ((valor <= 1) && (valor !=TERMINADOR));
	
	
	while (valor !=TERMINADOR) {
				
		Pareja descomposicion[MAX_FACTORES] = {{0,0}};
	
		int utilizados_descomposicion = 0; // Inicializar descomposición

		
		/*****************************************************************/
		// Calcular descomposición en factores primos
		/*****************************************************************/		

		int n = valor; // copia para salvaguardar "valor"
	
		// Los primos que se evalúan como posibles divisores de "n" se 
		// toman del array "primos". 
		// Se empieza con el 2 (ocupa la casilla 1 de "primos"). Recuerde 
		// que la casilla 0 está ocupada por el 1.
			
		int pos_primo = 1;					
		int candidato = primos[pos_primo];  // El primer candidato es 2
						
		int veces = 0; // exponente --> candidato^veces 
										  
		while ((n > 1) && (pos_primo<num_primos) && 
		   	   (utilizados_descomposicion<MAX_FACTORES)) {
			
			if  (n % candidato == 0)	{ // "candidato" es un factor primo
				
				veces = 1; 
				
				// Se sigue probando con el mismo factor ("candidato")
				
				n = n / candidato;
			
				while (n % candidato == 0) {
					
					veces++; 
					n = n / candidato;
				}
				
				// Actualizar el array de factores primos
				descomposicion[utilizados_descomposicion].primo = candidato;				
				descomposicion[utilizados_descomposicion].potencia = veces;
				
				utilizados_descomposicion++;
			} 
			
			// Probar con el siguiente primo
			pos_primo++;
			candidato = primos[pos_primo];
				
		} // while 
		

		if ((pos_primo>=num_primos) || 
			(utilizados_descomposicion>=MAX_FACTORES))  {
		
			utilizados_descomposicion = 0; 
		}	


		/*******************************************************************/
		// Mostrar descomposición en factores primos
		/*******************************************************************/	

		if (utilizados_descomposicion == 0) {

			cout << endl; 
			cout << "ERROR: Faltan primos para resultado o se requieren " 
			     << "demasiados factores." << endl;
			cout << endl; 

		}

		else {
					
			cout << endl; 
			cout << valor << " = ";

			for (int i=0; i<utilizados_descomposicion; i++) {
				
				int veces_primo = descomposicion[i].potencia; 
				
				if (veces_primo > 0) { // No se muestran los 
									   // valores no primos

					cout << setw(2) << descomposicion[i].primo;  // base

					// Se escribe el exponente solo si es mayor que 1
					if (veces_primo > 1) cout <<  "^" << veces_primo;
					
					if (i<utilizados_descomposicion-1) 
						cout << " * "; // evita el último *
				}

			} // for

			cout << endl; 
		}


		// Lectura del siguiente valor a descomponer
		
		do {
			cout << endl;
			cout << TITULO_LECTURA; 
			cin >> valor;
		} while ((valor <= 1) && (valor !=TERMINADOR));
		
				
	} // while (valor !=TERMINADOR)
	
	cout << endl;
}


////////////////////////////////////////////////////////////////////////////
// Función que hace todo el proceso de la descomposición de Eratostenes en
// factores primos. Para ello:
// 1. Inicializa el vector de bool necesario para rellenar el vector de primos.
// 2. Rellena el vector de primos.
// 3. Muestra por pantalla el vector de primos.
// 4. Lee un número.
// 5. Hace la descomposición en factores primos del número introducido.
// 6. Sigue leyendo hasta que se introduce el número TERMINADOR.
// Parámetros : Puntero que apunte a un vector de enteros


void EratostenesDescomposicionFactoresPrimos (int *primos){
	
	// Emplearemos un vector de datos lógicos para la criba de manera que  
	// "es_primo[i]" será TRUE si "i" es primo.
	bool es_primo[MAX_PRIMO+1];
	
	InicializaVectorBool (es_primo);
	
	int num_primos;
	
	num_primos = RellenaVectorPrimos (es_primo, primos);
	
	MuestraVectorPrimos (primos, num_primos);
	
	DescomposicionFactoresPrimos (primos, num_primos);
}
