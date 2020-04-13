#include "delocca.h"
#include <stdio.h>

/** \brief recibe dos parametros y los suma
 *
 * \param numero 1
 * \param numero 2
 * \return el resultado de la suma de los dos numeros
 *
 */

float suma(float a, float b){

	float resultado = 0.0;

	resultado = a + b;

	return resultado;

}

/** \brief recibe dos parametros y los resta
 *
 * \param numero 1
 * \param numero 2
 * \return el resultado de la resta de los dos numeros
 *
 */

float resta(float a, float b){

	float resultado = 0.0;

	resultado = a - b;

	return resultado;
}

/** \brief recibe dos parametros y los multiplica
 *
 * \param numero 1
 * \param numero 2
 * \return el resultado de la multiplicacion de los dos numeros
 *
 */

float multiplicacion(float a, float b){

	float resultado = 0.0;

	resultado = a * b;

	return resultado;
}

/** \brief recibe dos parametros y los divido
 *
 * \param numero 1
 * \param numero 2
 * \return el resultado de la division de los dos numeros
 *
 */

float division(float a, float b){

	float resultado = 0.0;

    resultado = a / b;

    return resultado;

}

/** \brief recibe un parametro y calcula el factorial
 *
 * \param numero 1
 * \return el factorial de ese numero
 *
 */

float factorial (float a){

	float resultadoRUno = 1;

	int i;

	for(i = 1 ; i <= a ; i++){

		resultadoRUno = resultadoRUno * i;
	}

	return resultadoRUno;

}

/** \brief recibe una posicion de memoria y declara el mismo como 0
 *
 * \param posicion de memoria
 * \return
 *
 */

void limpiarVar(float *p){

    *p = 0;

	return;
}
