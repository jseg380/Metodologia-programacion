/***************************************************************************/
//
// RELACION DE PROBLEMAS 2
//
// Declaración del tipo "VectorDinamico" y de las funciones básicas para 
// su gestión.
//  
// Fichero: FuncsVectorDinamico_basico.h
//
/***************************************************************************/
 
#ifndef FUNCS_VECTOR_DINAMICO_BASICO
#define FUNCS_VECTOR_DINAMICO_BASICO

#include <string>
using namespace std; 

/***************************************************************************/
/***************************************************************************/

// Tipo enumerado para representar tipos de redimensionamiento
enum class TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

// Capacidad inicial 
const int TAM_INICIAL = 10;

// Tamanio del bloque para redimensionar
const int TAM_BLOQUE = 5;

// Valor por defecto para los valores del vector
const int VALOR_DEF = 0;

typedef int TipoBase; // Tipo de los datos almacenados

typedef struct {

	TipoBase * datos; 		// Puntero para acceder a los datos
	int   usados;			// Num. casillas usadas
	int   capacidad;		// NUm. casillas reservadas

	// PRE: 0 <= usados <= capacidad 
	// Inicialmente, capacidad = TAM_INICIAL
	
	TipoRedimension tipo_redim; // Modelo de crecimiento

} VectorDinamico;


/***************************************************************************/
/***************************************************************************/
// Crear vector dinámico
// Argumentos: 
//	capacidad_inicial, número de casillas con las que se crea el vector.
// 		   tipo, el tipo de redimensión que se va a aplicar. 
// Devuelve: el vector dinámico creado.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"

VectorDinamico CreaVectorDinamico (int capacidad_inicial=TAM_INICIAL, 
					TipoRedimension tipo = TipoRedimension :: EnBloques);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector dinámico
// Argumentos: v (referencia) El vector que se va liberar.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es 0

void LiberaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Deja el vector dinámico vacío
// Argumentos: v (referencia) El vector que se va "vaciar"
// POST: El número de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas usadas de un vector dinámico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el número de casillas usadas de un vector dinámico

int UsadosVectorDinamico (const VectorDinamico v);

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas reservadas de un vector dinámico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el número de casillas reservadas de un vector dinámico

int CapacidadVectorDinamico (const VectorDinamico v); 

/***************************************************************************/
/***************************************************************************/
// Serializa un dato de tipo "VectorDinamico"
// Argumentos: v (referencia), el vector que se va a serializar.

string ToString (const VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Añade un valor al vector dinámico
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a añadir al vector. 
// PRE: hay espacio disponible en el vector dinámico

void AniadeVectorDinamico (VectorDinamico & v, const int valor);

/***************************************************************************/
/***************************************************************************/
// Consulta ó modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// Argumentos: 	
//		v (referencia), referencia al vector. 
//		num_casilla, número de casilla (índice) en la que estamos interesados.
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

int & ValorVectorDinamico (const VectorDinamico & v, const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector dinámico "v" de acuerdo al tipo de redimensión 
// registrado en "v". 
// Además, copia todos los datos en el nuevo vector.  
// Argumentos: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector dinámico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// Argumentos: 	
//		v (referencia), referencia al vector que se va a reajustar. 
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Muestra por pantalla un vector dinámico
// Argumentos: 	
//		v (referencia), vector que se va a mostrar

void MuestraVectorDinamico(VectorDinamico v);

/***************************************************************************/
/***************************************************************************/
// Copia los datos del vector destino al vector origen 
// Argumentos: 	
//		destino (referencia), referencia al vector que va a ser copiado
//		origen (referencia), referencia al vector donde se va a copiar
// POST: capacidad = usados

void Clona (VectorDinamico & destino, const VectorDinamico & origen);

/***************************************************************************/
/***************************************************************************/
// Inicializa el vector dinámico, sustituyendo el contenido de todas las
// casillas por el valor valor
// Argumentos: 	
//		v (referencia), vector que será inicializado
//		valor, valor al que se inicializará el vector

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Inserta un valor de tipo TipoBase en la posición dada en num_casilla
// Argumentos: 	
//		v (referencia), vector al que se le insertará un elemento
//		valor, valor que se insertará
//		num_casilla, posición en la que se insertará valor
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void InsertaVectorDinamico (VectorDinamico &v, const TipoBase valor,
					const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Elimina el valor que se encuentre en la posición dada en num_casilla
// Argumentos: 	
//		v (referencia), vector al que se le insertará un elemento
//		num_casilla, posición que se "eliminará"
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void EliminaVectorDinamico (VectorDinamico &v, const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Borra todas las componentes del vector que estén repetidas dejando el
// vector con elementos que no están repetidos
// Argumentos: 	
//		v (referencia), vector al que se le realizará el borrado "físico"

void BorradoFisicoDesplazamiento (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Borra todas las componentes del vector que estén repetidas dejando el
// vector con elementos que no están repetidos mediante dos apuntadores
// Argumentos: 	
//		v (referencia), vector al que se le realizará el borrado "físico"

void BorradoFisicoApuntadores (VectorDinamico & v);


/***************************************************************************/
/***************************************************************************/

#endif
