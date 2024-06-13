/***************************************************************************/
//
// RELACION DE PROBLEMAS 2
//
// Implementaci�n de las funciones b�sicas de gesti�n del tipo "VectorDinamico".
// Declaraciones en VectorDinamico_basico.h
//  
// Fichero: FuncsVectorDinamico_basico.cpp
//
/***************************************************************************/

#define DEBUG_FUNCS_VECTOR_DINAMICO_BASICO

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>

#include "FuncsVectorDinamico_basico.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Crear vector din�mico
// Argumentos: capacidad_inicial, n�mero de casillas con 
// 			   las que se crea el vector
//			   tipo, tipo de redimensi�n que le ocurrir� 
// Devuelve: el vector din�mico creado.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es "capacidad_inicial"

VectorDinamico CreaVectorDinamico (int capacidad_inicial,
						TipoRedimension tipo)
{
	VectorDinamico nuevo;

	// Pedir memoria para el nuevo almacen 
	nuevo.datos = new int[capacidad_inicial]; 

	// Iniciar capacidad y ocupaci�n
	nuevo.capacidad = capacidad_inicial;
	nuevo.usados = 0;
	
	nuevo.tipo_redim = tipo;

	return (nuevo);
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector din�mico
// Argumentos: v (referencia) El vector que se va liberar.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es 0

void LiberaVectorDinamico (VectorDinamico & v) 
{
	if (v.datos)
		delete [] v.datos;

	// Modificar las propiedades de "v" para que quede "vac�o"
	v.datos = 0; // Puntero "nulo"
	
	v.usados = 0;
	v.capacidad = 0;
}

/***************************************************************************/
/***************************************************************************/
// Deja el vector din�mico vac�o
// Argumentos: v (referencia) El vector que se va "vaciar"
// POST: El n�mero de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v) 
{
	v.usados = 0;
}

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas usadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas usadas de un vector din�mico

int  UsadosVectorDinamico (const VectorDinamico v) 
{
	return (v.usados);
}

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

 int CapacidadVectorDinamico (const VectorDinamico v) 
{
	return (v.capacidad);
}	

/***************************************************************************/
/***************************************************************************/
// Serializa un dato de tipo "VectorDinamico"
// Argumentos: v (referencia), el vector que se va a serializar.

string ToString (const VectorDinamico & v)
{
	string cad; 
	cad = cad + "Capacidad = " + to_string(v.capacidad); 
	cad = cad + "  Ocupadas  = " + to_string(v.usados) + "\n";

	if (v.usados > 0)  {

		cad = cad + "Valores almacenados en el vector: \n"; 

		cad = cad + "[ ";

		for (int i=0; i<v.usados-1; i++) 
			cad = cad + to_string(ValorVectorDinamico (v, i)) + ", "; 

		cad = cad + to_string(ValorVectorDinamico (v, v.usados-1)); 
		cad = cad + " ]";
	}
	else 
		cad = cad + "Vector vacio";

	cad = cad + "\n\n";

	return (cad);
}

/***************************************************************************/
/***************************************************************************/
// A�ade un valor al vector din�mico
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a a�adir al vector. 
// NOTA: Si no hay espacio libre, la funci�n pide espacio adicional usando 
//		 la funci�n RedimensionaVectorDinamico. 

void AniadeVectorDinamico (VectorDinamico &v, const int valor)
{
	// Si no cabe --> redimensionar

	if (v.usados == v.capacidad) {

		// Redimensionar 
		RedimensionaVectorDinamico (v);
	}

	// Se haya redimensionado o no, en este punto hay sitio para la inserci�n

	v.datos[v.usados] = valor;
	v.usados++;
}

/***************************************************************************/
/***************************************************************************/
// Consulta � modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// Argumentos: 	
//		v (referencia), referencia al vector. 
//		num_casilla, n�mero de casilla (�ndice) en la que estamos interesados.
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

TipoBase & ValorVectorDinamico (const VectorDinamico & v, int num_casilla) 
{
	return (v.datos[num_casilla]);
}	

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector din�mico "v" de acuerdo al tipo de redimensi�n 
// registrado en "v". 
// Adem�s, copia todos los datos en el nuevo vector.  
// Argumentos: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v)
{
	int nueva_capacidad = v.capacidad + TAM_BLOQUE;

    #ifdef DEBUG_FUNCS_VECTOR_DINAMICO_BASICO
	cout << endl;
	cout << "REDIMENSIONADO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	cout << endl;
	#endif

	// Pedir memoria para el nuevo almacen 
	int * tmp = new int[nueva_capacidad]; 

	// Copiar los datos 
	for (int i=0; i<v.usados; i++) 
		tmp[i] = v.datos[i]; 
		
	// Considerar esta copia eficiente:
	// memcpy (tmp, v.datos, v.usados*sizeof(TipoBase)); 
	
	// Liberar la memoria del antiguo almac�n
	delete [] v.datos; 

	// Actualizar vector din�mico redimensionado

	v.datos = tmp;
	v.capacidad = nueva_capacidad;
	// v.usados se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector din�mico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// Argumentos: 	
//		v (referencia), referencia al vector que se va a reajustar. 
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v)
{
	int nueva_capacidad = v.usados;

	cout << endl;
	cout << "REAJUSTANDO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	cout << endl;

	// Pedir memoria para el nuevo almacen 
	int * tmp = new int[nueva_capacidad]; 

	// Copiar los datos 
	for (int i=0; i<v.usados; i++) 
		tmp[i] = v.datos[i]; 
		
	// Considerar esta copia eficiente:
	// memcpy (tmp, v.datos, v.usados*sizeof(TipoBase)); 
	
	// Liberar la memoria del antiguo almac�n
	delete [] v.datos; 

	// Actualizar vector din�mico redimensionado

	v.datos = tmp;
	v.capacidad = nueva_capacidad;
	// v.usados se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/
// Muestra por pantalla un vector din�mico
// Argumentos: 	
//		v (referencia), vector que se va a mostrar

void MuestraVectorDinamico (VectorDinamico vector){
	
	cout << endl;
	cout << ToString (vector);
	cout << endl;
	
}

/***************************************************************************/
/***************************************************************************/
// Copia los datos del vector destino al vector origen 
// Argumentos: 	
//		destino (referencia), referencia al vector que va a ser copiado
//		origen (referencia), referencia al vector donde se va a copiar

void Clona (VectorDinamico & destino, const VectorDinamico & origen){
	
	// Establece el n�mero de componentes usadas en el vector
	// destino igual que el del vector origen
	
	destino.usados = origen.usados;
	
	// Establece el modelo de crecimiento del vector destino
	// igual que el del vector origen
	
	destino.tipo_redim = origen.tipo_redim;
	
	// Reajusta el vector destino para que tenga la misma capacidad que
	// el vector origen
	
	destino.capacidad = origen.capacidad;
	
	// Copia elemento a elemento los elementos del vector origen
	// en los elementos del vector destino
	
	for (int i = 0 ; i < destino.usados ; i++){
		destino.datos[i] = origen.datos[i];
	}
	
}

/***************************************************************************/
/***************************************************************************/
// Inicializa el vector din�mico, sustituyendo el contenido de todas las
// casillas por el valor valor
// Argumentos: 	
//		v (referencia), vector que ser� inicializado
//		valor, valor al que se inicializar� el vector

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor){
	
	// Inicializa el vector casilla a casilla por el valor especificado
	
	for (int i = 0 ; i < v.usados ; i++){
		v.datos[i] = valor;
	}
}

/***************************************************************************/
/***************************************************************************/
// Inserta un valor de tipo TipoBase en la posici�n dada en num_casilla
// Argumentos: 	
//		v (referencia), vector al que se le insertar� un elemento
//		valor, valor que se insertar�
//		num_casilla, posici�n en la que se insertar� valor
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void InsertaVectorDinamico (VectorDinamico &v, const TipoBase valor,
					const int num_casilla){
	
	// En caso de que el vector tenga todas sus casillas ocupadas
	// se amplia para que pueda alojar el nuevo valor
	
	if (v.usados == v.capacidad)
		RedimensionaVectorDinamico(v);
	
	// Se amplia en 1 el n�mero de casillas utilizadas
	
	v.usados++;
	
	// Se mueven hacia la derecha los elementos a partir del n�mero
	// de casilla indicado
	
	for (int i = v.usados ; i > num_casilla ; i--){
		v.datos[i] = v.datos[i-1];
	}
	
	// Se inserta en la posici�n num_casilla el valor indicado
	
	v.datos[num_casilla] = valor;
	
	// Se reajusta el vector para que ocupe el m�nimo n�mero de
	// casillas posible
	
	ReajustaVectorDinamico (v);
}

/***************************************************************************/
/***************************************************************************/
// Elimina el valor que se encuentre en la posici�n dada en num_casilla
// Argumentos: 	
//		v (referencia), vector al que se le insertar� un elemento
//		num_casilla, posici�n que se "eliminar�"
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void EliminaVectorDinamico (VectorDinamico &v, const int num_casilla){
	
	// Se mueven hacia la izquierda todos los elementos que hay a partir
	// de la casilla eliminada
	
	for (int i = num_casilla ; i < v.usados ; i++){
		v.datos[i] = v.datos[i + 1];
	}
	
	// Se reduce la capacidad del vector en 1
	
	v.usados--;
	
	// Se reajusta el vector para que ocupe el m�nimo n�mero de
	// casillas posible
	
	ReajustaVectorDinamico (v);
}

/***************************************************************************/
/***************************************************************************/
// Borra todas las componentes del vector que est�n repetidas dejando el
// vector con elementos que no est�n repetidos mediante desplazamiento
// Argumentos: 	
//		v (referencia), vector al que se le insertar� un elemento

void BorradoFisicoDesplazamiento (VectorDinamico & v){
	
	// Examina elemento a elemento para buscar si est� repetido
	// el valor que hay en ese elemento en el resto del vector
	
	int i = 0;
	int j;
	
	// No puede ser secuencial -> No usar un bucle for, porque la
	// casilla que antes era 2 ahora puede ser 1 y se la puede saltar
	// si ya ha hecho la antigua casilla 1
	
	// Se recorren las posiciones buscando n�meros iguales
	
	while (i < v.usados - 1){
		
		// Busca elementos iguales desde la posici�n siguiente a la que
		// nos encontramos (i + 1) hasta la �ltima posici�n ocupada
		// del vector (v.usados - 1)
		
		j = i + 1;
		
		while (j < v.usados){
			
			// Si encuentra un elemento que sea igual al que estamos
			// comparando entonces lo eliminamos
			
			if (v.datos[j] == v.datos[i])
				EliminaVectorDinamico (v, j);
			
			// Si no ha encontrado uno igual aumenta el contador
			// para que compare el siguiente elemento del vector
			
			else
				j++;
			
		}
		
		i++;
	}
	
	// Se reajusta el vector para que ocupe el m�nimo n�mero de
	// casillas posible
	
	ReajustaVectorDinamico (v);
}

/***************************************************************************/
/***************************************************************************/
// Borra todas las componentes del vector que est�n repetidas dejando el
// vector con elementos que no est�n repetidos mediante dos apuntadores
// Argumentos: 	
//		v (referencia), vector al que se le insertar� un elemento

void BorradoFisicoApuntadores (VectorDinamico & v){
	
	// Usaremos dos variables, posicion_lectura y posicion_escritura, 
	// que van indicando, en cada momento, la posici�n del dato que se
	// est� leyendo y el sitio d�nde tiene que escribirse
	
	int posicion_escritura = 1;
	int posicion_lectura = 1;
	
	while (posicion_lectura < v.usados){
		
		bool es_diferente = true;
		
		for (int i = 0 ; i < posicion_lectura && es_diferente; i++){
			if (v.datos[i] == v.datos[posicion_lectura])
				es_diferente = false;
		}
		
		if (es_diferente){
			v.datos[posicion_escritura] = v.datos[posicion_lectura];
			posicion_escritura++;
		}
		
		posicion_lectura++;
		
	}
	
	v.usados = posicion_escritura;
}

/***************************************************************************/
/***************************************************************************/
