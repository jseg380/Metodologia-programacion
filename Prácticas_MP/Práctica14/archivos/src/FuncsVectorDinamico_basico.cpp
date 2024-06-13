/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Implementaci�n de las funciones de gesti�n del tipo "VectorDinamico".
// Declaraciones en FuncsVectorDinamico.h
//
// Versi�n b�sica.
//  
// Fichero: FuncsVectorDinamico_basico.cpp
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
// Crear vector din�mico
// Recibe: capacidad_inicial, n�mero de casillas con las que se crea el vector.
// 		   tipo, el tipo de redimensi�n que se va a aplicar. 
// Devuelve: el vector din�mico creado.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es "capacidad_inicial"
//       El n�mero tipo de redimensi�n es "tipo"

VectorDinamico CreaVectorDinamico (int capacidad_inicial, 
 					 			   TipoRedimension tipo)
{
	VectorDinamico nuevo;

	// Pedir memoria para el nuevo almacen 
	nuevo.datos = new TipoBase[capacidad_inicial]; 

	// Iniciar capacidad y ocupaci�n
	nuevo.capacidad = capacidad_inicial;
	nuevo.usados = 0;

	// Iniciar tipo de redimensi�n
	nuevo.tipo_redimension = tipo;

	return (nuevo);
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector din�mico
// Recibe: v (referencia) El vector que se va liberar.
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
// Inicializa el vector din�mico copiando en todas las casillas "valor" 
// Par�metros: 	v (referencia) El vector que se va inicializar
//				valor, el valor que se va a copiar en todas las casillas.

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor)
{
	for (int i=0; i<v.usados; i++) 
		v.datos[i] =  valor;
}

/***************************************************************************/
/***************************************************************************/
// Deja el vector din�mico vac�o
// Recibe: v (referencia) El vector que se va "vaciar"
// POST: El n�mero de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v) 
{
	v.usados = 0;
}

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas usadas de un vector din�mico.
// Recibe: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas usadas de un vector din�mico

int  UsadosVectorDinamico (const VectorDinamico v) 
{
	return (v.usados);
}	

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Recibe: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

 int CapacidadVectorDinamico (const VectorDinamico v) 
{
	return (v.capacidad);
}	

/***************************************************************************/
/***************************************************************************/
// Copia profunda. Hace una copia profunda de "origen" en "destino".
// Argumentos: destino (referencia), el vector que recibe la copia. 
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
// Recibe: v, el vector que se va a serializar.

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
// A�ade un valor al vector din�mico
// Recibe: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a a�adir al vector. 
// NOTA: Si no hay espacio libre, la funci�n pide espacio adicional usando 
//		 la funci�n RedimensionaVectorDinamico. 

void AniadeVectorDinamico (VectorDinamico &v, const TipoBase valor)
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
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

 TipoBase & ValorVectorDinamico (const VectorDinamico v, int num_casilla) 
{
	return (v.datos[num_casilla]);
}	

/***************************************************************************/
/***************************************************************************/
// Inserci�n. Inserta un valor en una posici�n dada. Los valores que est�n 
// desde esa posici�n (incluida) hasta la �ltima se �desplazan� una posici�n 
// hacia �ndices mayores.
// Si el vector din�mico estuviera lleno se tiene que redimensionar (de 
// acuerdo al tipo de redimensi�n establecido) para poder acoger a "valor". 

void InsertaVectorDinamico (VectorDinamico & v, const TipoBase valor, 
	                        const int num_casilla)
{
	// Si no cabe --> redimensionar

	if (v.usados == v.capacidad) {

		// Redimensionar 
		RedimensionaVectorDinamico (v);
	}

	// Desplazar los valores de las casillas "num_casilla", "num_casilla"+1, 
	// ... "usados" una posici�n (hacia posiciones mayores)  
    TipoBase * pos_inic_bloque = &v.datos[num_casilla];
    memmove (pos_inic_bloque+1, pos_inic_bloque, 
                          (v.usados-num_casilla)*sizeof(TipoBase)); 

	*pos_inic_bloque = valor; // Escribir "valor" en la casilla "num_casilla"
	(v.usados)++; // Actualizar "usados"
}

/***************************************************************************/
/***************************************************************************/
// Borrado. Elimina un valor en una posici�n dada. Los valores que est�n 
// desde la posici�n siguiente a la dada hasta la �ltima se �desplazan� una 
// posici�n hacia �ndices menores. 
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void EliminaVectorDinamico (VectorDinamico & v, const int num_casilla)
{
    if ((num_casilla >= 0) && (num_casilla < v.usados)) {

		// Desplazar los valores de las casillas "num_casilla+1", 
		// "num_casilla"+2,..."usados" una posici�n (hacia posiciones menores)  
        TipoBase * pos_inic_bloque = &(v.datos[num_casilla+1]);
        memmove (pos_inic_bloque-1, pos_inic_bloque, 
                              (v.usados-num_casilla-1)*sizeof(TipoBase)); 
		(v.usados)--; // Actualizar "usados"
    }
}

/***********************************************************************/
// Busca la primera ocurrencia de "buscado" en el vector v, entre las 
// posiciones "pos_izda" y "pos_dcha". 
//
// Par�metros: 
//		v, vector din�mico.
//		pos_izda, pos_dcha: posiciones entre las que se realiza la b�squeda.
// 		buscado:  el valor buscado entre "pos_izda" y "pos_dcha".
//
// Devuelve: un entero, la posici�n donde se encuentra la primera aparici�n 
//		de "buscado" entre "pos_izda" y "pos_dcha".
//		Si no se encuentra, devuelve -1
//
// PRE: 0 <= pos_izda <= pos_dcha < v.usados

int PrimeraOcurrenciaEntre (VectorDinamico & v, int pos_izda, int pos_dcha, 
	                        int buscado)
{
	int pos = pos_izda; // Posici�n de la izquierda
	bool encontrado = false;

	while ((pos <= pos_dcha) && (!encontrado))

		if (v.datos[pos] == buscado) //�xito: terminar
			encontrado = true;
		else
			pos++; // Siguiente posici�n

	return (encontrado ? pos : -1); 
}

/***************************************************************************/
/***************************************************************************/
// Elimina los valores repetidos. 
// Par�metros: 
//		v, vector din�mico.

void EliminaRepetidosVectorDinamico_ineficiente (VectorDinamico & v)
{
	/*
		Recorrer todas las componentes del vector original
			Si la componente se encuentra en alguna posici�n anterior 
				Eliminarla.
	*/ 

	// Recorrer todas las componentes del vector original
	// OJO: no deber�a emplearse un ciclo for, porque en cada iteraci�n 
	// puede cambiar el valor de "total_utilizados" 

	int pos = 1; 

	while (pos < v.usados) {

		// NO empleamos un ciclo "for" porque se modifica el n�mero de 
		// componentes usadas por lo que habr�a que llamar a la funci�n 
		// "UsadosVectorDinamico" en cada iteraci�n. 
		// Preferimos emplear un ciclo "while".
		
		// Buscar la primera ocurrencia de v.datos[i] entre las posiciones 
		// 0 y "pos"-1 (la parte que NO contiene valores repetidos). 
		
		int pos_encontrado = PrimeraOcurrenciaEntre(v, 0, pos-1, v.datos[pos]);

		if (pos_encontrado != -1) {	// Est�: hay que borrarla

			memmove (&v.datos[pos], &v.datos[pos+1], 
				                    (v.usados-pos)*sizeof(TipoBase));

			(v.usados)--; // Actualizar "usados"
		}
		else pos++; // Si no est�, probar con el siguiente

	} // while (pos < total_utilizados)
}

/***************************************************************************/
/***************************************************************************/
// Elimina (de manera eficiente) los valores repetidos. 
// Par�metros: 
//		v, vector din�mico.

void EliminaRepetidosVectorDinamico (VectorDinamico & v)
{
	/*
	Las componentes no repetidas se almacenan al principio del vector
	Empleamos apuntadores para las posiciones de lectura y escritura. 

		Recorrer las componentes "v.datos[pos_lectura]" con "pos_lectura">0
			Si la componente "v.datos[pos_lectura]" NO se encuentra entre 
					las posiciones 0 y "pos_escritura",
				Colocamos dicha componente en "pos_escritura".     
	*/ 

	int pos_escritura = 1;	// La primera componente (posici�n 0) es 
							// parte de la soluci�n, por eso se empieza
			
	// Empiezamos la lectura por la posici�n 1 (no es preciso empezar 
	// por la la posici�n 0 porque es parte de la soluci�n)

	for (int pos_lectura=1; pos_lectura<v.usados; pos_lectura++) {

		// Busco el caracter actual (el de "pos_lectura") en el 
		// subvector izquierdo (posiciones: 0 hasta "pos_escritura"-1)

		int pos_encontrado = PrimeraOcurrenciaEntre (v, 0, pos_escritura-1,
										 v.datos[pos_lectura]);
 
		if (pos_encontrado == -1){  
		
			// Si no est�, lo copiamos en la posici�n indicada por 
			// "pos_escritura" y adelantamos la posici�n de escritura. 

			v.datos[pos_escritura] = v.datos[pos_lectura];
			pos_escritura++;
		}

	} // for pos_lectura

	v.usados = pos_escritura; // actualizo el tama�o
}

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector din�mico "v" de acuerdo al tipo de redimensi�n 
// registrado en "v". 
// Adem�s, copia todos los datos en el nuevo vector.  
// Recibe: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v)
{
	int nueva_capacidad;
	
    switch (v.tipo_redimension) {

        case (TipoRedimension::DeUnoEnUno): // 1 casilla m�s
            nueva_capacidad = v.capacidad+1;
            break;

        case (TipoRedimension::EnBloques): // TAM_BLOQUE casillas m�s
            nueva_capacidad = v.capacidad+TAM_BLOQUE;
            break;

        case (TipoRedimension::Duplicando): // Duplicar tama�o
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
	
	// Liberar la memoria del antiguo almac�n
	delete [] v.datos; 

	// Actualizar vector din�mico redimensionado

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
// Muestra el tipo de redimensionamiento que se emplear�
// Recibe: el valor del tipo enumerado asociado al tipo de redimensi�n.
	
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
// Lee y devuelve el tipo de redimensionamiento que se emplear�.
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
// Ordena el vector din�mico v y devuelve un nuevo vector din�mico que 
// contiene los datos de v ordenados.  
// Los datos resultantes est�n en orden creciente (por defecto). 
// Si desea un orden decreciente deber� indicarlo de manera expl�cita 
// escribiendo como segundo argumento no, NO, No � incluso nO.
//
// POST: El vector v no se modifica. 

VectorDinamico ObtenerCopiaVectorDinamicoOrdenado (const VectorDinamico & v, 
	                                               const char * creciente)
{
	// Creqar e inicializar el vector din�mico resultado

	VectorDinamico tmp = CreaVectorDinamico();

	Clona (tmp, v); 

	OrdenaVectorDinamico (tmp, creciente); 

	return (tmp);
}

/***************************************************************************/
/***************************************************************************/
// Ordena el vector din�mico v, modific�ndose su contenido (la ordenaci�n se 
// hace sobre el propio vector v). El segundo argumento sigue las mismas 
// normas que la versi�n anterior.
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
		
		// Pasar a may�culas "creciente"

		si_no[0]=toupper(creciente[0]);
		si_no[1]=toupper(creciente[1]);
		si_no[2]= '\0';

		// Comparar el valor de "creciente" con "NO"

		if (!strcmp(si_no, "NO")) { // Decreciente

			OrdenaVectorDinamicoDecreciente (v);
		}
		else { // Creciente

			OrdenaVectorDinamicoCreciente (v); 
		}
	}
}

/***************************************************************************/
/***************************************************************************/
// Ordena (sentido creciente) el vector din�mico v. 
// Se modifica su contenido (la ordenaci�n se hace sobre el propio vector v). 
// Par�etros:
//		v (referencia), referencia al vector din�mico que se ordena. 

void OrdenaVectorDinamicoCreciente (VectorDinamico & v)
{
	for (int izda = 0; izda < v.usados; izda++) {

		// Calcular el m�nimo entre "izda" y "total_utilizados"-1

		int minimo = v.datos[izda]; // Valor del m�nimo
		int pos_min = izda;   // Posici�n del m�nimo

		for (int i = izda + 1; i < v.usados; i++)

			if (v.datos[i] < minimo){ // Nuevo m�nimo
			    minimo = v.datos[i];
			    pos_min = i;
			 }

		// Intercambiar los valores guardados en "izda" y "pos_min"  

		Intercambia (v.datos[izda], v.datos[pos_min]);
   }
}

/***************************************************************************/
/***************************************************************************/
// Ordena (sentido creciente) el vector din�mico v. 
// Se modifica su contenido (la ordenaci�n se hace sobre el propio vector v). 
// Par�etros:
//		v (referencia), referencia al vector din�mico que se ordena. 

void OrdenaVectorDinamicoDecreciente (VectorDinamico & v)
{
	for (int izda = 0; izda < v.usados; izda++) {

		// Calcular el m�ximo entre "izda" y "total_utilizados"-1

		int maximo = v.datos[izda]; // Valor del m�ximo
		int pos_max= izda;   // Posici�n del m�ximo

		for (int i = izda + 1; i < v.usados; i++)

			if (v.datos[i] > maximo){ // Nuevo m�ximo
			    maximo = v.datos[i];
			    pos_max = i;
			 }

		// Intercambiar los valores guardados en "izda" y "pos_min"  

		Intercambia (v.datos[izda], v.datos[pos_max]);
   }
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
