/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Implementación de las funciones de gestión del tipo "VectorDinamico".
// Declaraciones en FuncsVectorDinamico.h
//
// Versión completa.
//  
// Fichero: FuncsVectorDinamico.cpp
//
/***************************************************************************/
/***************************************************************************/

#define DEBUG_FUNCS_VECTOR_DINAMICO

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>

#include "FuncsVectorDinamico.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Crear vector dinámico
// Parámetros: capacidad_inicial, número de casillas con las que se crea el vector.
// 		   tipo, el tipo de redimensión que se va a aplicar. 
// Devuelve: el vector dinámico creado.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"
//       El número tipo de redimensión es "tipo"

VectorDinamico CreaVectorDinamico (int capacidad_inicial, 
 					 			   TipoRedimension tipo)
{
	VectorDinamico nuevo;

	// Pedir memoria para el nuevo almacen 
	nuevo.datos = new TipoBase[capacidad_inicial]; 

	// Iniciar capacidad y ocupación
	nuevo.capacidad = capacidad_inicial;
	nuevo.usados = 0;

	// Iniciar tipo de redimensión
	nuevo.tipo_redimension = tipo;

	return (nuevo);
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector dinámico
// Parámetros: v (referencia) El vector que se va liberar.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es 0

void LiberaVectorDinamico (VectorDinamico & v) 
{
	if (v.datos)
		delete [] v.datos;

	// Modificar las propiedades de "v" para que quede "vacío"
	v.datos = 0; // Puntero "nulo"
	
	v.usados = 0;
	v.capacidad = 0;
}

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas usadas de un vector dinámico.
// Parámetros: v, el vector que se va a consultar.
// Devuelve: el número de casillas usadas de un vector dinámico

int  UsadosVectorDinamico (const VectorDinamico v) 
{
	return (v.usados);
}	

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas reservadas de un vector dinámico.
// Parámetros: v, el vector que se va a consultar.
// Devuelve: el número de casillas reservadas de un vector dinámico

 int CapacidadVectorDinamico (const VectorDinamico v) 
{
	return (v.capacidad);
}	

/***************************************************************************/
/***************************************************************************/
// Deja el vector dinámico vacío
// Parámetros: v (referencia) El vector que se va "vaciar"
// POST: El número de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v) 
{
	v.usados = 0;
}

/***************************************************************************/
/***************************************************************************/
// Inicializa el vector dinámico copiando en todas las casillas "valor" 
// Parámetros: 	v (referencia) El vector que se va inicializar
//				valor, el valor que se va a copiar en todas las casillas.

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor)
{
	for (int i=0; i<v.usados; i++) 
		v.datos[i] =  valor;
}

/***************************************************************************/
/***************************************************************************/
// Copia profunda. Hace una copia profunda de "origen" en "destino".
// Parámetros: destino (referencia), el vector que recibe la copia. 
//             origen (referencia), el vector del que se hace la copia. 

void Clona (VectorDinamico & destino, const VectorDinamico & origen)
{
	LiberaVectorDinamico (destino);

	destino.capacidad = origen.capacidad; 
	destino.usados = origen.usados;
	destino.tipo_redimension = origen.tipo_redimension;

	// Pedir memoria para el nuevo almacen la copia
	destino.datos = new TipoBase[origen.capacidad]; 

	// Copiar los valores 
	memcpy (destino.datos, origen.datos, destino.usados*sizeof(TipoBase));
}

/***************************************************************************/
/***************************************************************************/
// Serializa un dato de tipo "VectorDinamico"
// Parámetros: v, el vector que se va a serializar.

string ToString (const VectorDinamico v)
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
// Añade un valor al vector dinámico
// Parámetros: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a añadir al vector. 
// NOTA: Si no hay espacio libre, la función pide espacio adicional usando 
//		 la función RedimensionaVectorDinamico. 

void AniadeVectorDinamico (VectorDinamico &v, const TipoBase valor)
{
	// Si no cabe --> redimensionar

	if (v.usados == v.capacidad) {

		// Redimensionar 
		RedimensionaVectorDinamico (v);
	}

	// Se haya redimensionado o no, en este punto hay sitio para la inserción

	v.datos[v.usados] = valor;
	v.usados++;
}

/***************************************************************************/
/***************************************************************************/
// Consulta ó modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

 TipoBase & ValorVectorDinamico (const VectorDinamico v, int num_casilla) 
{
	return (v.datos[num_casilla]);
}	

/***************************************************************************/
/***************************************************************************/
// Inserción. Inserta un valor en una posición dada. Los valores que están 
// desde esa posición (incluida) hasta la última se “desplazan” una posición 
// hacia índices mayores.
// Si el vector dinámico estuviera lleno se tiene que redimensionar (de 
// acuerdo al tipo de redimensión establecido) para poder acoger a "valor". 

void InsertaVectorDinamico (VectorDinamico & v, const TipoBase valor, 
	                        const int num_casilla)
{
	// Si no cabe --> redimensionar

	if (v.usados == v.capacidad) {

		// Redimensionar 
		RedimensionaVectorDinamico (v);
	}

	// Desplazar los valores de las casillas "num_casilla", "num_casilla"+1, 
	// ... "usados" una posición (hacia posiciones mayores)  
    TipoBase * pos_inic_bloque = &v.datos[num_casilla];
    memmove (pos_inic_bloque+1, pos_inic_bloque, 
                          (v.usados-num_casilla)*sizeof(TipoBase)); 

	*pos_inic_bloque = valor; // Escribir "valor" en la casilla "num_casilla"
	(v.usados)++; // Actualizar "usados"
}

/***************************************************************************/
/***************************************************************************/
// Borrado. Elimina un valor en una posición dada. Los valores que están 
// desde la posición siguiente a la dada hasta la última se “desplazan” una 
// posición hacia índices menores. 
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void EliminaVectorDinamico (VectorDinamico & v, const int num_casilla)
{
    if ((num_casilla >= 0) && (num_casilla < v.usados)) {

		// Desplazar los valores de las casillas "num_casilla+1", 
		// "num_casilla"+2,..."usados" una posición (hacia posiciones menores)  
        TipoBase * pos_inic_bloque = &(v.datos[num_casilla+1]);
        memmove (pos_inic_bloque-1, pos_inic_bloque, 
                              (v.usados-num_casilla-1)*sizeof(TipoBase)); 
		(v.usados)--; // Actualizar "usados"
    }
}

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector dinámico "v" de acuerdo al tipo de redimensión 
// registrado en "v". 
// Además, copia todos los datos en el nuevo vector.  
// Parámetros: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v)
{
	int nueva_capacidad;
	
    switch (v.tipo_redimension) {

        case (TipoRedimension::DeUnoEnUno): // 1 casilla más
            nueva_capacidad = v.capacidad+1;
            break;

        case (TipoRedimension::EnBloques): // TAM_BLOQUE casillas más
            nueva_capacidad = v.capacidad+TAM_BLOQUE;
            break;

        case (TipoRedimension::Duplicando): // Duplicar tamaño
            nueva_capacidad = v.capacidad*2;
            break;
    }

    #ifdef DEBUG_FUNCS_VECTOR_DINAMICO
	cout << endl;
	cout << "REDIMENSIONADO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	cout << endl;
	#endif

	// Pedir memoria para el nuevo almacen 
	TipoBase * tmp = new TipoBase[nueva_capacidad]; 

	// Copiar los datos 
	for (int i=0; i<v.usados; i++) 
		tmp[i] = v.datos[i]; 
		
	// Considerar esta copia eficiente:
	// memcpy (tmp, v.datos, v.usados*sizeof(TipoBase)); 
	
	// Liberar la memoria del antiguo almacén
	delete [] v.datos; 

	// Actualizar vector dinámico redimensionado

	v.datos = tmp;
	v.capacidad = nueva_capacidad;
	// v.usados se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector dinámico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// Parámetros: 	
//		v (referencia), referencia al vector que se va a reajustar. 
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v)
{
	int nueva_capacidad = v.usados;

	cout << endl;
	cout << "REAJUSTANDO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	cout << endl;

	// Pedir memoria para el nuevo almacen 
	TipoBase * tmp = new TipoBase[nueva_capacidad]; 

	// Copiar los datos 
	for (int i=0; i<v.usados; i++) 
		tmp[i] = v.datos[i]; 
		
	// Considerar esta copia eficiente:
	// memcpy (tmp, v.datos, v.usados*sizeof(TipoBase)); 
	
	// Liberar la memoria del antiguo almacén
	delete [] v.datos; 

	// Actualizar vector dinámico redimensionado

	v.datos = tmp;
	v.capacidad = nueva_capacidad;
	// v.usados se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/
// Transforma "valor_cad" a TipoBase

TipoBase TransformaATipoBase (char * valor_cad)
{
	TipoBase el_valor; 

	#ifdef INT
	el_valor = atoi(valor_cad);
	#else 
		#ifdef DOUBLE
		el_valor = atof(valor_cad);
		#else 
			#ifdef CHAR
			el_valor = valor_cad[0];
			#endif
		#endif
	#endif

	return (el_valor);
}

/***************************************************************************/
/***************************************************************************/
// Muestra el tipo de redimensionamiento que se empleará
// Recibe: el valor del tipo enumerado asociado al tipo de redimensión.
	
void MuestraTipoRedimension (TipoRedimension tipo)
{
	cout << endl;
	cout << "TIPO DE REDIMENSION --> ";

	switch (tipo) { 
	
		case (TipoRedimension::DeUnoEnUno):	
					cout << "de uno en uno";
					break;
		case (TipoRedimension::EnBloques):	
					cout << "en bloques";
					break;
		case (TipoRedimension::Duplicando):	
					cout << "duplicando";
					break; 
	}
	cout << endl << endl;
}

/***************************************************************************/
/***************************************************************************/
// Lee y devuelve el tipo de redimensionamiento que se empleará.
// Devuelve: el valor del tipo enumerado apropiado al valor leido.

TipoRedimension LeeTipoRedimension (void)
{
	TipoRedimension tipo; 
	int opcion; 

	do {
		cout << "Introducir tipo de redimensionamiento:"<< endl;
		cout << "   1.- De uno en uno" << endl;
		cout << "   2.- En bloques de tamano " << TAM_BLOQUE << endl;
		cout << "   3.- Duplicando" << endl;
		cout << "Opcion: "; 
		cin >> opcion;
	}
	while ((opcion <1) || (opcion > 3));

	switch (opcion) { 
		case (1):	tipo = TipoRedimension::DeUnoEnUno;
					break;
		case (2):	tipo = TipoRedimension::EnBloques;
					break;
		case (3):	tipo = TipoRedimension::Duplicando;
					break; 
	}
	return (tipo); 
}

/***************************************************************************/
/***************************************************************************/
// Ordena el vector dinámico v y devuelve un nuevo vector dinámico que 
// contiene los datos de v ordenados.  
// Los datos resultantes están en orden creciente (por defecto). 
// Si desea un orden decreciente deberá indicarlo de manera explícita 
// escribiendo como segundo argumento no, NO, No ó incluso nO.
//
// POST: El vector v no se modifica. 

VectorDinamico ObtenerCopiaVectorDinamicoOrdenado (const VectorDinamico & v, 
	                                               const char * creciente)
{
	// Creqar e inicializar el vector dinámico resultado

	VectorDinamico tmp = CreaVectorDinamico();

	Clona (tmp, v); 

	OrdenaVectorDinamico (tmp, creciente); 

	return (tmp);
}

/***************************************************************************/
/***************************************************************************/
// Ordena el vector dinámico v, modificándose su contenido (la ordenación se 
// hace sobre el propio vector v). El segundo argumento sigue las mismas 
// normas que la versión anterior.
//
// POST: El contenido original de "v" se pierde (se sustituye por los mismos 
//       valores, pero ordenados)

void OrdenaVectorDinamico (VectorDinamico & v, const char * creciente)
{
	// Analizar segundo argumento

	char si_no[3];

	if (strlen(creciente) != 2) 
	
		strcpy(si_no, "SI"); 
	
	else { // "creciente" tiene longitud 2
		
		// Pasar a mayúculas "creciente"

		si_no[0]=toupper(creciente[0]);
		si_no[1]=toupper(creciente[1]);
		si_no[2]= '\0';
	}
	
	// Comparar el valor de "creciente" con "NO"

	if (!strcmp(si_no, "NO")) { // Decreciente

		OrdenaVectorDinamicoDecreciente (v);
	}
	else { // Creciente

		OrdenaVectorDinamicoCreciente (v); 
	}
}

/***************************************************************************/
/***************************************************************************/
// Ordena (sentido creciente) el vector dinámico v. 
// Se modifica su contenido (la ordenación se hace sobre el propio vector v). 
// Paráetros:
//		v (referencia), referencia al vector dinámico que se ordena. 

void OrdenaVectorDinamicoCreciente (VectorDinamico & v)
{
	for (int izda = 0; izda < v.usados; izda++) {

		// Calcular el mínimo entre "izda" y "total_utilizados"-1

		int minimo = v.datos[izda]; // Valor del mínimo
		int pos_min = izda;   // Posición del mínimo

		for (int i = izda + 1; i < v.usados; i++)

			if (v.datos[i] < minimo){ // Nuevo mínimo
			    minimo = v.datos[i];
			    pos_min = i;
			 }

		// Intercambiar los valores guardados en "izda" y "pos_min"  

		Intercambia (v.datos[izda], v.datos[pos_min]);
   }
}

/***************************************************************************/
/***************************************************************************/
// Ordena (sentido creciente) el vector dinámico v. 
// Se modifica su contenido (la ordenación se hace sobre el propio vector v). 
// Paráetros:
//		v (referencia), referencia al vector dinámico que se ordena. 

void OrdenaVectorDinamicoDecreciente (VectorDinamico & v)
{
	for (int izda = 0; izda < v.usados; izda++) {

		// Calcular el máximo entre "izda" y "total_utilizados"-1

		int maximo = v.datos[izda]; // Valor del máximo
		int pos_max= izda;   // Posición del máximo

		for (int i = izda + 1; i < v.usados; i++)

			if (v.datos[i] > maximo){ // Nuevo máximo
			    maximo = v.datos[i];
			    pos_max = i;
			 }

		// Intercambiar los valores guardados en "izda" y "pos_min"  

		Intercambia (v.datos[izda], v.datos[pos_max]);
   }
}

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
                            const VectorDinamico & v2, const char * selectiva)
{
	VectorDinamico mezcla = CreaVectorDinamico();

	MezclaVectoresDinamicos (mezcla, v1, v2, selectiva); 

	return (mezcla);
}

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
                           const VectorDinamico & v2,  const char * selectiva)
{
	char si_no[3];

	if (strlen(selectiva) != 2) 
	
		strcpy(si_no, "no"); 
	
	else { // "selectiva" tiene longitud 2
		
		// Pasar a mayúculas "selectiva"

		si_no[0]=toupper(selectiva[0]);
		si_no[1]=toupper(selectiva[1]);
		si_no[2]= '\0';

		// Comparar el valor de "selectiva" con "SI"

		if (!strcmp(si_no, "SI")) // Mezcla selectiva

			MezclaVectoresDinamicosSelectiva (mezcla, v1, v2);

		else // Mezcla NO selectiva

			MezclaVectoresDinamicosTotal (mezcla, v1, v2); 
	}
}

/***************************************************************************/
/***************************************************************************/
// Mezcla no selectiva de dos vectores dinámicos.
// La mezcla puede contener valores repetidos. 
// Parámetros: 	
//		v3 (referencia), referencia al vector dinámico con el resultado. 
//		v1 (referencia), referencia al primer vector dinámico que se mezcla. 
//		v2 (referencia), referencia al segundo vector dinámico que se mezcla. 
// 
// PRE: "v1" y "v2" están ordenados
// POST: El contenido original de "v3" se pierde. Se sustituye por la 
//       mezcla de "v1" y "v2".  
// POST: Los vectores "v1" y "v2" NO se modifican.

void MezclaVectoresDinamicosTotal (VectorDinamico &v3,const VectorDinamico &v1, 
                                   const VectorDinamico & v2)
{
	EliminaTodosVectorDinamico (v3);

	// Colocar punteros al inicio de los datos de los tres vectores
	const TipoBase * p1 = v1.datos;
	const TipoBase * p2 = v2.datos;

	// Marcar el final de los vectores a mezclar
	const TipoBase * end1 = v1.datos+v1.usados;
	const TipoBase * end2 = v2.datos+v2.usados;


	// mientras queden datos por examinar en los dos vectores

	while ((p1<end1) && (p2<end2)) {
		
		if (*p1 < *p2) {
			AniadeVectorDinamico (v3, *p1); // copiar de v1
			p1++;
			
		}
		else {
			AniadeVectorDinamico (v3, *p2); // copiar de v2
			p2++;
		}
	}

	// copiar lo que quede en v1

	while (p1<end1){

		AniadeVectorDinamico (v3, *p1); // copiar de v1
		p1++;
	} 
	
	// copiar lo que quede en v2

	while (p2<end2){

		AniadeVectorDinamico (v3, *p2); // copiar de v2
		p2++;
	}
}

/***************************************************************************/
/***************************************************************************/
// Mezcla selectiva de dos vectores dinámicos.
// En el caso de encontrar valores repetidos solo selecciona uno de ellos.
// Parámetros: 	
//		v3 (referencia), referencia al vector dinámico con el resultado. 
//		v1 (referencia), referencia al primer vector dinámico que se mezcla. 
//		v2 (referencia), referencia al segundo vector dinámico que se mezcla. 
// 
// PRE: "v1" y "v2" están ordenados
// POST: El contenido original de "v3" se pierde. Se sustituye por la 
//       mezcla de "v1" y "v2".  
// POST: Los vectores "v1" y "v2" NO se modifican.

void MezclaVectoresDinamicosSelectiva (VectorDinamico & v3, 
	            const VectorDinamico & v1, const VectorDinamico & v2)
{
	EliminaTodosVectorDinamico (v3);

	// El primer paso consiste en calcular la mezcla típica (que puede 
	// incluir valores repetidos) con la función "MezclaVectoresTodo" 

	MezclaVectoresDinamicosTotal (v3, v1, v2);

	// Empleando la técnica de los dos apuntadores (lectura/escritura) 
	// eliminamos los valores repetidos.

	TipoBase * fin_v3 = v3.datos+v3.usados; // Delimitar el final de "v3" 

	TipoBase * pos_escritura = v3.datos+1; // La primera casilla se mantiene 
	TipoBase * pos_lectura   = v3.datos+1; // siempre en el resultado 

	// Cuando "pos_lectura" se iguale a "fin_mezcla" se termina el cálculo.

	while (pos_lectura != fin_v3) {

		if (*pos_lectura != *(pos_escritura-1)) { // Mantener el contenido 
			*pos_escritura = *pos_lectura;        // de "pos_lectura" --> 
			pos_escritura++;                      // adelantar "pos_escritura"
		}
		pos_lectura++;  // En cualquier caso, adelantar "pos_lectura"
	}

	v3.usados = pos_escritura-v3.datos; // OBSERVE: El valor mínimo es 1 
}

/***************************************************************************/
/***************************************************************************/
// Intercambia los valores de los datos referenciados por "r1" y "r2"

void Intercambia (TipoBase & r1, TipoBase & r2)
{
	TipoBase tmp = r1;
	r1 = r2;
	r2 = tmp;
}

/***************************************************************************/
/***************************************************************************/