#ifndef FUNCIONES_ERATOSTENES_FACTORES_PRIMOS
#define FUNCIONES_ERATOSTENES_FACTORES_PRIMOS


// Valor terminador para la lectura 
const int TERMINADOR = 0;

// Mostrar DATOS_POR_LINEA núms. por línea
const int DATOS_POR_LINEA = 10;
		

// Máximo primo permitido en el resultado. 
const int MAX_PRIMO = 5000; 


// Máximo número de primos que se pueden almacenar. 
// PRE: MAX_DATOS <= MAX_PRIMO
// Todos estarán entre 1 y MAX_PRIMO (Es posible que no quepan todos)	
const int MAX_DATOS = 1000;

// Número máximo de factores primos permitidos
const int MAX_FACTORES = 50;


////////////////////////////////////////////////////////////////////////////
// Función que hace todo el proceso de la descomposición de Eratostenes en
// factores primos. Para ello:
// 1. Inicializa el vector de bool necesario para rellenar el vector de primos.
// 2. Rellena el vector de primos.
// 3. Muestra por pantalla el vector de primos.
// 4. Lee un número.
// 5. Hace la descomposición en factores primos del número introducido.
// 6. Sigue leyendo hasta que se introduce el número TERMINADOR.
// Parámetros : Puntero que apunte a un vector de enteros

void EratostenesDescomposicionFactoresPrimos (int *primos);


#endif
