/***************************************************************************/
//
// RELACION DE PROBLEMAS 2
//
// Fichero: II_Demo-VectorDinamico_basico.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "FuncsVectorDinamico_basico.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (int argc, char ** argv)
{

	// ......................................................................
	// Comprobación de los argumentos
	
	if (argc > 2){
		cout << endl;
		cout << "Error se esperaban 1 o menos argumentos.";
		cout << "Uso:\n" << argv[0] << "<tipo_redimension>" << endl;
		cout << endl;
		exit (1);
	}
	
	// Establecer tipo de redimensión por defecto
	TipoRedimension el_tipo = TipoRedimension :: DeUnoEnUno;
	
	if (argc > 1){
		int tipo;
		
		tipo = atoi(argv[1]);
		
		// Validez de los argumentos
	
		if (tipo < 1 || tipo > 3){
			cout << endl;
			cout << "Tipo de redimensión no válido." << endl;
			cout << endl;
			
			tipo = 1;
		}
		
		switch (tipo){
			case 1: cout << "Utilizando redimensión de uno en uno" << endl;
					break;
			case 2: cout << "Utilizando redimension en bloques" << endl;
					el_tipo = TipoRedimension :: EnBloques;
					break;
			case 3: cout << "Utilizando redimension duplicando" << endl;
					el_tipo = TipoRedimension :: Duplicando;
					break;
		}
	}
	
	else
		cout << "Utilizando redimensión de uno en uno" << endl;

	// ......................................................................
	// Crear un vector dinámico
	
	VectorDinamico v = CreaVectorDinamico (TAM_INICIAL, el_tipo); 

	// Se han reservado TAM casillas y actualmente se están usando 0.
	
	/*
	
	//Lectura "normal" en la que se pueden introducir enteros positivos
	// y negativos y se para de leer cuando se introduce FIN
	

	// ......................................................................
	// Leer valores y guardarlos en el vector dinámico. 
	// Se redimensiona cuando no hay espacio para un nuevo dato. 
	
	const int TAM_CAD = 20;
	char  valor[TAM_CAD];

	// Primera lectura - lectura adelantada
	cout << "Introducir un valor (FIN para finalizar): "; 
	cin.getline (valor, TAM_CAD);

	while (strcmp(valor, "FIN")) {

		int el_valor = atoi (valor); 

		// Añadir "valor". Si no cabe se redimensiona 

		AniadeVectorDinamico (v, el_valor);

		// Nueva lectura
		cout << "Introducir un valor (FIN para finalizar): "; 
		cin.getline (valor, TAM_CAD);
	}
	
	*/
	
	// Lectura según ejercicio 6: Solo se pueden introducir positivos
	// y el programa se detendrá cuando se introduzca un negativo
	
	int valor_int;
	
	// Primera lectura - lectura adelantada
	
	cout << "Introducir un valor positivo (número negativo para finalizar): ";
	cin >> valor_int;
	
	while (valor_int >= 0){
		
		// Añadir el valor. Si no cabe se redimension
		
		AniadeVectorDinamico (v, valor_int);
		
		// Nueva lectura de otro valor
		
		cout << "Introducir un valor positivo "
			 << "(número negativo para finalizar): ";
		cin >> valor_int;
	}


	// ......................................................................
	// Muestra el vector

	MuestraVectorDinamico (v);
	
	// ......................................................................
	// Reajusta y muestra el vector

	ReajustaVectorDinamico (v);

	MuestraVectorDinamico (v);

	// ......................................................................
	// Borrado "físico" de los valores que están repetidos en el vector
	// usando ambos métodos
	
	cout << "Borrado \"físico\" mediante desplazamiento : " << endl;
	
	BorradoFisicoDesplazamiento (v);
	MuestraVectorDinamico (v);
	
	VectorDinamico v_copia = CreaVectorDinamico ();
	Clona (v_copia, v);
	
	cout << "Borrado \"físico\" mediante apuntadores : " << endl;
	
	BorradoFisicoApuntadores (v_copia);
	MuestraVectorDinamico (v_copia);

	// ......................................................................
	// Insertar en casilla 1 y penultima y mostrar el vector

	cout << "Insertando -1 en casilla 1: "; 

	InsertaVectorDinamico (v, -1, 1);

	MuestraVectorDinamico (v);

	cout << "Insertando -2 en casilla penultima: "; 

	InsertaVectorDinamico (v, -2, UsadosVectorDinamico(v)-1);

	MuestraVectorDinamico (v);

	// ......................................................................
	// Eliminar las casilla insertadas 
	
	cout << "Eliminando los valores insertados: "; 

	EliminaVectorDinamico (v, 1);

	MuestraVectorDinamico (v);

	EliminaVectorDinamico (v, UsadosVectorDinamico(v)-2);

	MuestraVectorDinamico (v);
	
	// ......................................................................
	// Reajusta y muestra el vector

	ReajustaVectorDinamico (v);

	MuestraVectorDinamico (v);

	// ......................................................................
	// Prueba de valor (como rvalue) e inserción --> Hacer espejo

	cout << "Construyendo array espejo: ";

	for (int i=v.usados-1; i>=0; i--)
		AniadeVectorDinamico (v, ValorVectorDinamico (v, i)); 

	MuestraVectorDinamico (v);

	// ......................................................................
	// Prueba de valor como lvalue --> invertir 
	
	cout << "Invertir los valores: "; 

	for (int i=0; i<v.usados; i++) 
		ValorVectorDinamico (v, i) *= -1; 

	MuestraVectorDinamico (v);

	// ......................................................................
	// Prueba de valor (como rvalue) --> Mostrar las posiciones pares 

	cout << "Valores en posiciones pares: ";

	cout << endl;
	for (int i=0; i<v.usados; i+=2) 
		cout << "Pos " << i << " = " << ValorVectorDinamico (v, i) << endl; 
	cout << endl;

	MuestraVectorDinamico (v);

	// ......................................................................
	// "Vaciar" vector dinámico
	
	cout << "Vaciando: ";

	EliminaTodosVectorDinamico (v);
	
	MuestraVectorDinamico (v);

	// ......................................................................
	// "Alimentar" el vector dinámico

	AniadeVectorDinamico (v, 1);
	AniadeVectorDinamico (v, 3);
	AniadeVectorDinamico (v, 5);

	MuestraVectorDinamico (v);
	
	// ......................................................................
	// Liberar memoria
	
	cout << "Liberando memoria y finalizando" << endl;
	cout << endl;

	LiberaVectorDinamico (v);
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
