#include <iostream>
#include <iomanip>

#include "funciones_Kaprekar.h"

using namespace std;

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
