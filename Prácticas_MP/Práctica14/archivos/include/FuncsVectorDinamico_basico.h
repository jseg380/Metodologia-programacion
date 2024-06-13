/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Declaración del tipo "VectorDinamico"y de las funciones de gestión.
// Implementaciones en FuncsVectorDinamico.cpp
//
// Versión básica.
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

	TipoRedimension tipo_redimension; // Método de redimensión del conjunto.

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
// Crear vector dinámico
// Recibe: capacidad_inicial, número de casillas con las que se crea el vector.
// 		   tipo, el tipo de redimensión que se va a aplicar. 
// Devuelve: el vector dinámico creado.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"
//       El número tipo de redimensión es "tipo"

VectorDinamico CreaVectorDinamico (int capacidad_inicial=TAM_INICIAL, 
 					 TipoRedimension tipo=TipoRedimension::EnBloques);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector dinámico
// Recibe: v (referencia) El vector que se va liberar.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es 0

void LiberaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Inicializa el vector dinámico copiando en todas las casillas "valor" 
// Parámetros: 	v (referencia) El vector que se va inicializar
//				valor, el valor que se va a copiar en todas las casillas.

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Deja el vector dinámico vacío
// Recibe: v (referencia) El vector que se va "vaciar"
// POST: El número de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas usadas de un vector dinámico.
// Recibe: v, el vector que se va a consultar.
// Devuelve: el número de casillas usadas de un vector dinámico

int UsadosVectorDinamico (const VectorDinamico v);

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas reservadas de un vector dinámico.
// Recibe: v, el vector que se va a consultar.
// Devuelve: el número de casillas reservadas de un vector dinámico

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
// Añade un valor al vector dinámico
// Recibe: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a añadir al vector. 
// PRE: hay espacio disponible en el vector dinámico

void AniadeVectorDinamico (VectorDinamico & v, const TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Consulta ó modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

TipoBase & ValorVectorDinamico (VectorDinamico v, const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Inserción. Inserta un valor en una posición dada. Los valores que están 
// desde esa posición (incluida) hasta la última se “desplazan” una posición 
// hacia índices mayores.
// Si el vector dinámico estuviera lleno se tiene que redimensionar (de 
// acuerdo al tipo de redimensión establecido) para poder acoger a "valor". 

void InsertaVectorDinamico (VectorDinamico & v, const TipoBase valor, 
	                        const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Borrado. Elimina un valor en una posición dada. Los valores que están 
// desde la posición siguiente a la dada hasta la última se “desplazan” una 
// posición hacia índices menores. 
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void EliminaVectorDinamico (VectorDinamico & v, const int num_casilla);

/***********************************************************************/
// Busca la primera ocurrencia de "buscado" en el vector v, entre las 
// posiciones "pos_izda" y "pos_dcha". 
//
// Parámetros: 
//		pos_izda, pos_dcha: posiciones entre las que se realiza la búsqueda.
// 		buscado:  el valor buscado entre "pos_izda" y "pos_dcha".
//
// Devuelve: un entero, la posición donde se encuentra la primera aparición 
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
// Redimensiona el vector dinámico "v" de acuerdo al tipo de redimensión 
// registrado en "v". 
// Además, copia todos los datos en el nuevo vector.  
// Parámetros: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector dinámico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Transforma "valor_cad" a TipoBase

TipoBase TransformaATipoBase (char * valor_cad);

/***************************************************************************/
/***********************************************s****************************/
// Lee y devuelve el tipo de redimensionamiento que se empleará.
// Devuelve: el valor del tipo enumerado apropiado al valor leido.

TipoRedimension LeeTipoRedimension (void);

/***************************************************************************/
/***************************************************************************/
// Muestra el tipo de redimensionamiento que se empleará
// Recibe: el valor del tipo enumerado asociado al tipo de redimensión.

void MuestraTipoRedimension (TipoRedimension);
	
/***************************************************************************/
/***************************************************************************/

#endif
