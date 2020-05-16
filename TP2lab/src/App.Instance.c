#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//Bibliotecas
#include "Library/Library.Validate/Validate.h"
#include "Library/ArrayEmployees/ArrayEmployees.h"

#define LEN 4
#define HARCO 4

int ABM(void){
	char confirm = 'y';
	//Employee list[HARCO] = {{1000,"Jorgito","Rodriguez",15000,1},{1001,"luigi","billi",25000,1},{1002,"pepe","sand",20000,2}};
	Employee list[LEN];
	int id;
	int freeId = 1004;
	int sortOrder;
	char answer = 'y';
	int totalSalary;
	float averageSalary;

	//Datos ABM para cargar los datos
	initEmployees(list,LEN); // Comentar para hardcodear

	// menu de opciones
	do{
		switch( menu()){
		case 'a': // Alta
			system("cls");
			printf("---Registro de empleados---\n\n");
			chargeEmployeeData(list, LEN, &freeId);

			break;
		case 'b': // Modificacion
			modifyEmployee(list,LEN);
			break;
		case 'c': // Baja
			system("cls");
			printf("---Dar de baja empleado---\n\n");
			utn_getNumero(&id,"\nIngrese una ID: ","\nERROR: ",0,5000,10);
			removeEmployee(list, LEN, id);
			break;
		case 'd': // Sort
			system("cls");
			printf("---Menu---\n\n");

			printf(
					" 0- Descendente \n"
					" 1- Ascendente \n"
					" 2- Salario y promedio. \n"
					" 3- Empleados con mayor salario\n");
			utn_getNumero(&sortOrder,"\nPlease, type an option: ","\nERROR: ",0,3,10);
			if (sortOrder==0){ // Descending
				sortEmployees(list,LEN,sortOrder);
			}
			else if (sortOrder==1){ // Ascending
				sortEmployees(list,LEN,sortOrder);
			}
			else if (sortOrder==2){
				totalAverageSalary(&totalSalary, &averageSalary,list,LEN);
			}
			else if (sortOrder==3){
				if (&averageSalary >=0){
					knowHowManySalaryBigger(&averageSalary,1, list,LEN);
				}
				else{
					printf("\nNecesitas calcular el salario primero.\n");
				}
			}

			break;

		case 'e': // Get Out
			printf("Esta seguro?. y/n\n");
			fflush(stdin);
			getString(&confirm,sizeof(confirm));
			if(confirm == 'y'){
				answer = 'y';
			}
			break;
		default: // Error
			printf("\nSolo se pueden ingresar de la A a la E");
			break;


		}
		system("pause");
		system("cls");
	}while(answer=='y');

	return EXIT_SUCCESS;
}
