/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Fichero: II_EstadisticaBasica_Lista.cpp 
//
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "Lista.h"
#include "TipoBaseLista.h"

using namespace std; 


/***************************************************************************/
/***************************************************************************/
// DECLARACIÓN DE FUNCIONES ESPECÍFICAS DEL EJERCICIO
/***************************************************************************/
/***************************************************************************/
// Calcula el valor medio de los valores almacenados en una lista 
// Parámetros: l, la lista que se va a procesar. 
// Devuelve: el valor medio de los valores guardados en la lista

double Media (const Lista & l);

/***************************************************************************/
// Calcula la varianza de los valores almacenados en una lista 
// Parámetros: l, la lista que se va a procesar. 
// Devuelve: la varianza de los valores guardados en la lista

double Varianza (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// FIN DECLARACIÓN DE FUNCIONES ESPECÍFICAS DEL EJERCICIO
/***************************************************************************/
/***************************************************************************/



/***************************************************************************/
/***************************************************************************/

int main (void)
{
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);	


	Lista l = ConstruyeLista(); // Crea una lista vacía

	//.............................................................

	cout << endl;
	cout << "Paso 1: Leer valores positivos para la lista." << endl;
	cout << endl;

	TipoBase valor; 

	cout << endl;
	cout << "Introduzca valor para aniadir a la lista "; 
	cout << "(negativo para finalizar): "; 
	cin >> valor; 

	while (valor > 0) {

		Aniade (l, valor); 

		cout << "Introduzca valor para aniadir a la lista "; 
		cout << "(negativo para finalizar): "; 
		cin >> valor; 
	}

	cout << endl;
	cout << ToString (l); 
	cout << endl;

	cout << "Lista original:" << endl;	
	if (!EstaVacia(l)) {
		cout << "\tNumero de elementos = " 
		     << setw(3) << NumElementos(l) << endl;
		cout << "\tLa media es    " << setw(7) << setprecision(2) 
		     << Media (l) << endl;
		cout << "\tLa varianza es " << setw(7) << setprecision(2) 
		     << Varianza(l) << endl;
	}
	else 
		cout << "La lista esta vacia." << endl;

	cout << endl;


	//.............................................................

	cout << endl;
	cout << "Paso 2: Crear y rellenar listas de pares e impares." << endl;
	cout << endl;

	Lista pares =   ConstruyeLista(); 
	Lista impares = ConstruyeLista(); 

	for (int pos=1; pos<=NumElementos(l); pos++) {

		int valor_pos = (int) Valor(l, pos); 

		if (valor_pos%2 == 0) Aniade(pares, (TipoBase)valor_pos);
		else Aniade(impares, (TipoBase)valor_pos);
	}

	cout << endl;
	cout << "Lista de pares:" << endl;
	cout << ToString (pares); 
	cout << endl;

	cout << endl;
	cout << "Lista de impares:" << endl;
	cout << ToString (impares); 
	cout << endl;


	//.............................................................

	cout << endl;
	cout << "Paso 3: Estadísticas de las listas de pares e impares." << endl;
	cout << endl;


	cout << "Lista de pares:" << endl;	
	if (!EstaVacia(pares) > 0) {
		cout << "\tNumero de elementos = " 
		     << setw(3) << NumElementos(pares) << endl;
		cout << "\tLa media es    " << setw(7) << setprecision(2) 
		     << Media (pares) << endl;
		cout << "\tLa varianza es " << setw(7) << setprecision(2) 
		     << Varianza(pares) << endl;
	}
	else 
		cout << "La lista esta vacia." << endl;

	cout << endl;

	cout << "Lista de impares:" << endl;
	if (!EstaVacia(impares) > 0) {
		cout << "\tNumero de elementos = " 
		     << setw(3) << NumElementos(impares) << endl;
		cout << "\tLa media es    " << setw(7) << setprecision(2) 
		     << Media (impares) << endl;
		cout << "\tLa varianza es " << setw(7) << setprecision(2) 
		     << Varianza(impares) << endl;
	}
	else 
		cout << "La lista esta vacia." << endl;

	cout << endl;

	//.............................................................

	DestruyeLista (l);
	DestruyeLista (pares);
	DestruyeLista (impares);
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
// Calcula el valor medio de los valores almacenados en la lista 
// Recibe: un puntero al primer nodo de la lista
// Devuelve: el valor medio de los valores guardados en la lista

double Media (const Lista & l)
{
	double suma = 0.0; 
	int num_elementos = NumElementos(l);

	for (PNodo p=l; p!=0; suma+=p->info, p=p->sig);

	/*
	PNodo p=l;

	while (p != 0) {
		suma+=p->info;
		p=p->sig;
	}
	*/

	return (suma/num_elementos);
}

/***************************************************************************/
/***************************************************************************/
// Calcula la varianza de los valores almacenados en la lista 
// Recibe: un puntero al primer nodo de la lista
// Devuelve: la varianza de los valores guardados en la lista

double Varianza (const Lista & l)
{
	PNodo p = l; 
	double suma = 0.0; 
	int num_elementos = NumElementos(l);
	double media = Media (l);

	while (p!=0) {
		double dif = p->info-media;
		double sqrdif = dif*dif;
		suma+=sqrdif;
		p=p->sig;
	}
	return (suma/num_elementos);
}

/***************************************************************************/
/***************************************************************************/
