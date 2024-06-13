#ifndef FUNCIONES_KAPREKAR
#define FUNCIONES_KAPREKAR

/***************************************************************************/
// Función que devuelve el número de cifras de un número int.
// Entrada: num, el valor a estudiar. 
// Devuelve:  número de cifras de "num".
// PRE: num>=0
/***************************************************************************/

int NumCifras (int num);


/***************************************************************************/
// Calcula si todas las cifras de "num" son iguales.
// Entrada: num, el valor a estudiar. 
// Devuelve: true, si todas las cifras de "num" son iguales.
// PRE: num>=0
/***************************************************************************/

bool TodasCifrasIguales (int num);


/***********************************************************************/
// Calcula el número más pequeño posible con los dígitos de "num".
// Recibe: num, número a convertir.
// PRE: num>=0

int MinimoValorPosible (int num);

/***********************************************************************/
// Calcula el número más grande posible con los dígitos de "num".
// Recibe: num, número a convertir.
// PRE: num>=0

int MaximoValorPosible (int num);


/***********************************************************************/
// Calcula el número más grande posible con los dígitos de "num" y lo 
// completa con ceros finales hasta alcanzar "num_digitos" digitos. 
// Si num_digitos <= NumDigitos(num) no se miodifica el número de dígitos. 
// Recibe: num, número a convertir.
// 		   num_digitos, número de dígitos del resultado. 
// PRE: num>=0

int MaximoValorPosible (int num, int num_digitos);


/***********************************************************************/
// Calcula el número de iteraciones que necesita el proceso Kaprekar 
// para converger.  
// Recibe: num, número de cuatro o menos cifras a verificar. 
// Devuelve: el número de iteraciones empleadas en llegar a CTE_KAPREKAR.
//
// PRE: VerificaKaprekar(num) == true
// PRE: num>=0

int IteracionesKaprekar (int num);


/***********************************************************************/
// Calcula si el número de iteraciones que requiere el proceso de 
// Kaprekar hasta converger es correcto.
// Recibe: num, número de cuatro o menos cifras a verificar. 
// Devuelve: true si el número de iteraciones empleadas es correcto.
//
// PRE: NumCifras(num) <= 4
// PRE: num>=0

bool VerificaKaprekar (int num);

#endif
