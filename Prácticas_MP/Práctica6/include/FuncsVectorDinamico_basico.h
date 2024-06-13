/***************************************************************************/
//
// RELACION DE PROBLEMAS 2
//
// Declaraci�n del tipo "VectorDinamico" y de las funciones b�sicas para 
// su gesti�n.
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
// Crear vector din�mico
// Argumentos: 
//	capacidad_inicial, n�mero de casillas con las que se crea el vector.
// 		   tipo, el tipo de redimensi�n que se va a aplicar. 
// Devuelve: el vector din�mico creado.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es "capacidad_inicial"

VectorDinamico CreaVectorDinamico (int capacidad_inicial=TAM_INICIAL, 
					TipoRedimension tipo = TipoRedimension :: EnBloques);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector din�mico
// Argumentos: v (referencia) El vector que se va liberar.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es 0

void LiberaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Deja el vector din�mico vac�o
// Argumentos: v (referencia) El vector que se va "vaciar"
// POST: El n�mero de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas usadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas usadas de un vector din�mico

int UsadosVectorDinamico (const VectorDinamico v);

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

int CapacidadVectorDinamico (const VectorDinamico v); 

/***************************************************************************/
/***************************************************************************/
// Serializa un dato de tipo "VectorDinamico"
// Argumentos: v (referencia), el vector que se va a serializar.

string ToString (const VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// A�ade un valor al vector din�mico
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a a�adir al vector. 
// PRE: hay espacio disponible en el vector din�mico

void AniadeVectorDinamico (VectorDinamico & v, const int valor);

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

int & ValorVectorDinamico (const VectorDinamico & v, const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector din�mico "v" de acuerdo al tipo de redimensi�n 
// registrado en "v". 
// Adem�s, copia todos los datos en el nuevo vector.  
// Argumentos: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector din�mico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// Argumentos: 	
//		v (referencia), referencia al vector que se va a reajustar. 
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Muestra por pantalla un vector din�mico
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
// Inicializa el vector din�mico, sustituyendo el contenido de todas las
// casillas por el valor valor
// Argumentos: 	
//		v (referencia), vector que ser� inicializado
//		valor, valor al que se inicializar� el vector

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Inserta un valor de tipo TipoBase en la posici�n dada en num_casilla
// Argumentos: 	
//		v (referencia), vector al que se le insertar� un elemento
//		valor, valor que se insertar�
//		num_casilla, posici�n en la que se insertar� valor
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void InsertaVectorDinamico (VectorDinamico &v, const TipoBase valor,
					const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Elimina el valor que se encuentre en la posici�n dada en num_casilla
// Argumentos: 	
//		v (referencia), vector al que se le insertar� un elemento
//		num_casilla, posici�n que se "eliminar�"
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void EliminaVectorDinamico (VectorDinamico &v, const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Borra todas las componentes del vector que est�n repetidas dejando el
// vector con elementos que no est�n repetidos
// Argumentos: 	
//		v (referencia), vector al que se le realizar� el borrado "f�sico"

void BorradoFisicoDesplazamiento (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Borra todas las componentes del vector que est�n repetidas dejando el
// vector con elementos que no est�n repetidos mediante dos apuntadores
// Argumentos: 	
//		v (referencia), vector al que se le realizar� el borrado "f�sico"

void BorradoFisicoApuntadores (VectorDinamico & v);


/***************************************************************************/
/***************************************************************************/

#endif
