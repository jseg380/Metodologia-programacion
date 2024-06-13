/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Declaraci�n del tipo "VectorDinamico"y de las funciones de gesti�n.
// Implementaciones en FuncsVectorDinamico.cpp
//
// Versi�n b�sica.
//  
// Fichero: FuncsVectorDinamico_basico.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef VECTOR_DINAMICO_BASICO
#define VECTOR_DINAMICO_BASICO

#include <string>
#include "TipoBase.h"
using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Tipo enumerado para representar los tipos de redimensionamiento permitidos

enum class TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

// Capacidad inicial 
const int TAM_INICIAL = 10; 

// Tamanio del bloque para redimensionar
const int TAM_BLOQUE = 5;

typedef struct {

	TipoBase * datos; 	// Puntero para acceder a los datos
	int usados;			// Num. casillas usadas
	int capacidad;		// NUm. casillas reservadas

	// PRE: 0 <= usados <= capacidad 
	// Inicialmente, capacidad = TAM_INICIAL

	TipoRedimension tipo_redimension; // M�todo de redimensi�n del conjunto.

} VectorDinamico;


/***************************************************************************/
/***************************************************************************/
// Prototipos de las funciones ofertadas: 
/*

VectorDinamico CreaVectorDinamico (int capacidad_inicial=TAM_INICIAL, 
 					     TipoRedimension tipo=TipoRedimension::EnBloques);

void LiberaVectorDinamico (VectorDinamico & v);

void  RedimensionaVectorDinamico (VectorDinamico & v);

void  ReajustaVectorDinamico (VectorDinamico & v);

int UsadosVectorDinamico (const VectorDinamico v);

int CapacidadVectorDinamico (const VectorDinamico v); 

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor);

void EliminaTodosVectorDinamico (VectorDinamico & v);

void Clona (VectorDinamico & destino, const VectorDinamico & origen);

string ToString (const VectorDinamico v);

TipoBase & ValorVectorDinamico (VectorDinamico v, const int num_casilla);

void AniadeVectorDinamico (VectorDinamico & v, const TipoBase valor);

void InsertaVectorDinamico (VectorDinamico & v, const TipoBase valor, 
	                        const int num_casilla);

void EliminaVectorDinamico (VectorDinamico & v, const int num_casilla);

int PrimeraOcurrenciaEntre (VectorDinamico & v, int pos_izda, int pos_dcha, 
	                        int buscado);

void EliminaRepetidosVectorDinamico_ineficiente (VectorDinamico & v);
 
void EliminaRepetidosVectorDinamico (VectorDinamico & v);

//...........................................................................

TipoRedimension LeeTipoRedimension (void);

void MuestraTipoRedimension (TipoRedimension);

//...........................................................................

TipoBase TransformaATipoBase (char * valor_cad);

void Intercambia (TipoBase & r1, TipoBase & r2);

//...........................................................................
*/


/***************************************************************************/
/***************************************************************************/
// Crear vector din�mico
// Recibe: capacidad_inicial, n�mero de casillas con las que se crea el vector.
// 		   tipo, el tipo de redimensi�n que se va a aplicar. 
// Devuelve: el vector din�mico creado.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es "capacidad_inicial"
//       El n�mero tipo de redimensi�n es "tipo"

VectorDinamico CreaVectorDinamico (int capacidad_inicial=TAM_INICIAL, 
 					 TipoRedimension tipo=TipoRedimension::EnBloques);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector din�mico
// Recibe: v (referencia) El vector que se va liberar.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es 0

void LiberaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Inicializa el vector din�mico copiando en todas las casillas "valor" 
// Par�metros: 	v (referencia) El vector que se va inicializar
//				valor, el valor que se va a copiar en todas las casillas.

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Deja el vector din�mico vac�o
// Recibe: v (referencia) El vector que se va "vaciar"
// POST: El n�mero de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas usadas de un vector din�mico.
// Recibe: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas usadas de un vector din�mico

int UsadosVectorDinamico (const VectorDinamico v);

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Recibe: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

 int CapacidadVectorDinamico (const VectorDinamico v); 

/***************************************************************************/
/***************************************************************************/
// Copia profunda. Hace una copia profunda de "origen" en "destino".
// Argumentos: destino (referencia), el vector que recibe la copia. 
//             origen (referencia), el vector del que se hace la copia. 

void Clona (VectorDinamico & destino, const VectorDinamico & origen);

/***************************************************************************/
/***************************************************************************/
// Serializa un dato de tipo "VectorDinamico"
// Recibe: v, el vector que se va a serializar.

string ToString (const VectorDinamico v);

/***************************************************************************/
/***************************************************************************/
// A�ade un valor al vector din�mico
// Recibe: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a a�adir al vector. 
// PRE: hay espacio disponible en el vector din�mico

void AniadeVectorDinamico (VectorDinamico & v, const TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Consulta � modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

TipoBase & ValorVectorDinamico (VectorDinamico v, const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Inserci�n. Inserta un valor en una posici�n dada. Los valores que est�n 
// desde esa posici�n (incluida) hasta la �ltima se �desplazan� una posici�n 
// hacia �ndices mayores.
// Si el vector din�mico estuviera lleno se tiene que redimensionar (de 
// acuerdo al tipo de redimensi�n establecido) para poder acoger a "valor". 

void InsertaVectorDinamico (VectorDinamico & v, const TipoBase valor, 
	                        const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Borrado. Elimina un valor en una posici�n dada. Los valores que est�n 
// desde la posici�n siguiente a la dada hasta la �ltima se �desplazan� una 
// posici�n hacia �ndices menores. 
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void EliminaVectorDinamico (VectorDinamico & v, const int num_casilla);

/***********************************************************************/
// Busca la primera ocurrencia de "buscado" en el vector v, entre las 
// posiciones "pos_izda" y "pos_dcha". 
//
// Par�metros: 
//		pos_izda, pos_dcha: posiciones entre las que se realiza la b�squeda.
// 		buscado:  el valor buscado entre "pos_izda" y "pos_dcha".
//
// Devuelve: un entero, la posici�n donde se encuentra la primera aparici�n 
//		de "buscado" entre "pos_izda" y "pos_dcha".
//		Si no se encuentra, devuelve -1
//
// PRE: 0 <= pos_izda <= pos_dcha < v.usados

int PrimeraOcurrenciaEntre (VectorDinamico & v, int pos_izda, int pos_dcha, 
	                        int buscado);

/***************************************************************************/
/***************************************************************************/
// Elimina (de manera ineficiente) los valores repetidos. 

void EliminaRepetidosVectorDinamico_ineficiente (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Elimina (de manera eficiente) los valores repetidos. 

void EliminaRepetidosVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector din�mico "v" de acuerdo al tipo de redimensi�n 
// registrado en "v". 
// Adem�s, copia todos los datos en el nuevo vector.  
// Par�metros: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector din�mico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Transforma "valor_cad" a TipoBase

TipoBase TransformaATipoBase (char * valor_cad);

/***************************************************************************/
/***********************************************s****************************/
// Lee y devuelve el tipo de redimensionamiento que se emplear�.
// Devuelve: el valor del tipo enumerado apropiado al valor leido.

TipoRedimension LeeTipoRedimension (void);

/***************************************************************************/
/***************************************************************************/
// Muestra el tipo de redimensionamiento que se emplear�
// Recibe: el valor del tipo enumerado asociado al tipo de redimensi�n.

void MuestraTipoRedimension (TipoRedimension);
	
/***************************************************************************/
/***************************************************************************/

#endif
