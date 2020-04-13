#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "delocca.h"


int main() {

	int dataEntry;
	int calc;
	float a = 0.0;
	float b = 0.0;
	float sumaR = 0.0;
	float restaR = 0.0;
	float divisionR = 0.0;
	float multiplicacionR = 0.0;
	float factorialRUno = 0.0;

	do{

		printf("---Bienvenido al programa de la calculadora---\n");
		printf("1 - Ingresar 1er oprando (A = %f) \n", a);
		printf("2 - Ingresar 2do oprando (B = %f)\n", b);
		printf("3 - Calcular todas las operaciones\n");
		printf("4 - Informar resultados\n");
		printf("5 - Salir\n");

		scanf("%d", &dataEntry);

		system("cls");

		switch(dataEntry){
			case 1:
					printf("Ingrese el 1er operando: ");
					scanf("%f", &a);
					dataEntry = 0;
					system("cls");
			break;

			case 2:
					printf("Ingrese el 2do operando: ");
					scanf("%f", &b);
					dataEntry = 0;
					system("cls");
			break;

			case 3:
					do{
					printf("1 - Calcular la suma (A+B) \n");
					printf("2 - Calcular la resta (A - B) \n");
					printf("3 - Calcular la multiplicacion (A * B) \n");
					printf("4 - Calcular la division (A / B) \n");
					printf("5 - Calcular el factorial (A!) \n");
					printf("6 - Atras\n");

					scanf("%d", &calc);
					system("cls");

					switch(calc){
						case 1:
								sumaR = suma(a, b);
								printf("Se calculo la suma de A + B \n");
								printf("Presione ENTER para continuar");
								getch();
								system("cls");
								calc = 0;
						break;

						case 2:
								restaR = resta(a, b);
								printf("Se calculo la resta de A - B \n");
								printf("Presione ENTER para continuar");
								getch();
								system("cls");
								calc = 0;
						break;

						case 3:
								multiplicacionR = multiplicacion(a, b);
								printf("Se calculo la multiplicacion de A * B \n");
								printf("Presione ENTER para continuar");
								getch();
								system("cls");
								calc = 0;
						break;

						case 4:
						    if(b == 0.0){
                                printf("El segundo operando es 0, no se puede dividir por 0 \n");
                                printf("Presione ENTER para continuar");
                                getch();
                                system("cls");
								calc = 0;
						    }else{
						        divisionR = division(a, b);
						        printf("Se calculo la division de A / B \n");
								printf("Presione ENTER para continuar");
								getch();
								system("cls");
								calc = 0;
						    }

						break;

						case 5:
								factorialRUno = factorial(a);
								printf("Se calculo el factorial de A \n");
								printf("Presione ENTER para continuar");
								getch();
								system("cls");
								calc = 0;
						break;

						case 6: goto back;
						break;
					}

					}while(calc != 1 || calc != 2 || calc != 3 || calc != 4 || calc != 5 || calc != 6);

					back:

					dataEntry = 0;
					system("cls");

			break;

			case 4:
				printf("El resultado de A + B es: %f \n", sumaR);
				printf("El resultado de A - B es: %f \n", restaR);
				printf("El resultado de A * B es: %f \n", multiplicacionR);
				printf("El resultado de A / B es: %f \n", divisionR);
				printf("El resultado de A es %f \n", factorialRUno);
				limpiarVar(&sumaR);
				limpiarVar(&restaR);
				limpiarVar(&multiplicacionR);
				limpiarVar(&divisionR);
				limpiarVar(&factorialRUno);
				getch();
				system("cls");
			break;

			case 5: goto end;
			break;
		}

	}while(dataEntry != 1 || dataEntry != 2 || dataEntry != 3 || dataEntry != 4 || dataEntry != 5);

	end:

	printf("Usted salio del programa \n");

	getch();
	return 0;
}
