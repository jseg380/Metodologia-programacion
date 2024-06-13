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
// Versión completa.
//  
// Fichero: FuncsVectorDinamico.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef VECTOR_DINAMICO
#define VECTOR_DINAMICO

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

// Un "VectorDinamico" se representa (por ahora) con un struct  

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

//...........................................................................

TipoRedimension LeeTipoRedimension (void);

void MuestraTipoRedimension (TipoRedimension);

//...........................................................................

TipoBase TransformaATipoBase (char * valor_cad);

void Intercambia (TipoBase & r1, TipoBase & r2);

//...........................................................................
// NUEVAS FUNCIONES

VectorDinamico ObtenerCopiaVectorDinamicoOrdenado (const VectorDinamico & v, 
	                                            const char * creciente="si");

void OrdenaVectorDinamico (VectorDinamico & v, const char * creciente="si");

void OrdenaVectorDinamicoCreciente (VectorDinamico & v);

void OrdenaVectorDinamicoDecreciente (VectorDinamico & v);

VectorDinamico ObtenerCopiaMezclaVectoresDinamicos (const VectorDinamico & v1, 
                      const VectorDinamico & v2, const char * selectiva="no");

void MezclaVectoresDinamicos (VectorDinamico &mezcla,const VectorDinamico &v1, 
                          const VectorDinamico & v2,  const char * selectiva);

void MezclaVectoresDinamicosTotal (VectorDinamico &v3,const VectorDinamico &v1, 
                                   const VectorDinamico & v2);

void MezclaVectoresDinamicosSelectiva (VectorDinamico & v3, 
	            const VectorDinamico & v1, const VectorDinamico & v2);

//...........................................................................
*/


/***************************************************************************/
/***************************************************************************/
// Crear vector dinámico
// Parámetros: capacidad_inicial, número de casillas para crear el vector.
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
// Parámetros: v (referencia) El vector que se va liberar.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es 0

void LiberaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas usadas de un vector dinámico.
// Parámetros: v, el vector que se va a consultar.
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
// Deja el vector dinámico vacío
// Parámetros: v (referencia) El vector que se va "vaciar"
// POST: El número de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Inicializa el vector dinámico copiando en todas las casillas "valor" 
// Parámetros: 	v (referencia) El vector que se va inicializar
//				valor, el valor que se va a copiar en todas las casillas.

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor);

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
// Ordena el vector dinámico v y devuelve un nuevo vector dinámico que 
// contiene los datos de v ordenados. 
// El vector v no se modifica. 
// Los datos resultantes están en orden creciente (por defecto). 
// Si desea un orden decreciente deberá indicarlo de manera explícita 
// escribiendo como segundo argumento no, NO, No ó incluso nO.

VectorDinamico ObtenerCopiaVectorDinamicoOrdenado (const VectorDinamico & v, 
	                                            const char * creciente="si");

/***************************************************************************/
/***************************************************************************/
// Ordena el vector dinámico v, modificándose su contenido (la ordenación se 
// hace sobre el propio vector v). El segundo argumento sigue las mismas 
// normas que la versión anterior.
// Parámetros:
//		v (referencia), referencia al vector dinámico que se ordena. 
//		creciente, 

void OrdenaVectorDinamico (VectorDinamico & v, const char * creciente="si");

/***************************************************************************/
/***************************************************************************/
// Ordena (sentido creciente) el vector dinámico v. 
// Se modifica su contenido (la ordenación se hace sobre el propio vector v). 
// Parámetros:
//		v (referencia), referencia al vector dinámico que se ordena. 

void OrdenaVectorDinamicoCreciente (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Ordena (sentido creciente) el vector dinámico v. 
// Se modifica su contenido (la ordenación se hace sobre el propio vector v). 
// Parámetros:
//		v (referencia), referencia al vector dinámico que se ordena. 

void OrdenaVectorDinamicoDecreciente (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/

void Intercambia (TipoBase & r1, TipoBase & r2);


/***************************************************************************/
/***************************************************************************/
// Mezcla dos vectores dinámicos ordenados y devuelve un nuevo vector 
// dinámico con el resultado de la mezcla. 
// La mezcla puede ser selectiva (sin valores repetidos) -por defecto- o no 
// (sin valores repetidos, solo se selecciona uno).  
// Parámetros: 	
//		v1 (referencia), referencia al primer vector dinámico. 
//		v2 (referencia), referencia al segundo vector dinámico. 
//      selectiva (referencia, parámetro OPCIONAL). Si su valor es "si", "SI", 
//             "Si" ó "sI" la mezcla será selectiva (sin valores repetidos). 
//              La mezcla será completa (puede tener valores repetidos) si se 
//              llama con cualquier otro valor (o ninguno).
//
// PRE: "v1" y "v2" están ordenados
// POST: Los vectores v1 y v2 NO se modifican.

VectorDinamico ObtenerCopiaMezclaVectoresDinamicos (const VectorDinamico & v1, 
                      const VectorDinamico & v2, const char * selectiva="no");

/***************************************************************************/
/***************************************************************************/
// Mezcla dos vectores dinámicos ordenados y devuelve el resultado de la 
// mezcla en otro vector dinámico que ya existe. 
// La mezcla puede ser selectiva (sin valores repetidos, solo se selecciona 
// uno de ellos) o no selectiva -por defecto- (puede contener repetidos).  
// Parámetros: 	
//		mezcla (referencia), referencia al vector dinámico con el resultado. 
//		v1 (referencia), referencia al primer vector dinámico que se mezcla. 
//		v2 (referencia), referencia al segundo vector dinámico que se mezcla.  
//      selectiva (referencia, parámetro OPCIONAL). Si su valor es "si", "SI", 
//             "Si" ó "sI" la mezcla será selectiva (sin valores repetidos). 
//              La mezcla será completa (puede tener valores repetidos) si se 
//              llama con cualquier otro valor (o ninguno).
//
// PRE: "v1" y "v2" están ordenados
// POST: El contenido original de "mezcla" se pierde. Se sustituye por la 
//       mezcla de "v1" y "v2".  
// POST: Los vectores "v1" y "v2" NO se modifican.


void MezclaVectoresDinamicos (VectorDinamico &mezcla,const VectorDinamico &v1, 
                          const VectorDinamico & v2,  const char * selectiva);

/***************************************************************************/
/***************************************************************************/
// Mezcla no selectiva de dos vectores dinámicos.
// La mezcla puede contener valores repetidos. 
// Parámetros: 	
//		mezcla (referencia), referencia al vector dinámico con el resultado. 
//		v1 (referencia), referencia al primer vector dinámico que se mezcla. 
//		v2 (referencia), referencia al segundo vector dinámico que se mezcla. 
// 
// PRE: "v1" y "v2" están ordenados
// POST: El contenido original de "mezcla" se pierde. Se sustituye por la 
//       mezcla de "v1" y "v2".  
// POST: Los vectores "v1" y "v2" NO se modifican.

void MezclaVectoresDinamicosTotal (VectorDinamico &v3,const VectorDinamico &v1, 
                                   const VectorDinamico & v2);

/***************************************************************************/
/***************************************************************************/
// Mezcla selectiva de dos vectores dinámicos.
// En el caso de encontrar valores repetidos solo selecciona uno de ellos.
// Parámetros: 	
//		mezcla (referencia), referencia al vector dinámico con el resultado. 
//		v1 (referencia), referencia al primer vector dinámico que se mezcla. 
//		v2 (referencia), referencia al segundo vector dinámico que se mezcla. 
// 
// PRE: "v1" y "v2" están ordenados
// POST: El contenido original de "mezcla" se pierde. Se sustituye por la 
//       mezcla de "v1" y "v2".  
// POST: Los vectores "v1" y "v2" NO se modifican.

void MezclaVectoresDinamicosSelectiva (VectorDinamico & v3, 
	            const VectorDinamico & v1, const VectorDinamico & v2);

/***************************************************************************/
/***************************************************************************/

#endif
