#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "../Library.Validate/Validate.h"

int initEmployees(Employee* list, int len){
int retorno = -1;
	for(int i=0;i<len;i++){
		list[i].isEmpty = 1;
		retorno = 0;
		}
return retorno;
}

int FindFreePlace(Employee vec[], int len){
	int i;
	int retorno = -1;
	for(i = 0; i < len; i++){
		if (vec[i].isEmpty){
			retorno = i;
			break;
		}
	}
	return retorno;
}

int chargeEmployeeData(Employee* list, int listLen, int* thisID){
	int isLoaded = -1;
	Employee auxEmployee;
	int newId;
	newId = *thisID;

	if((list!=NULL && listLen>0)){
		utn_getNombre(auxEmployee.name, 51, "\nNombre: ", "\nNombre incorrecto\n", 20);
		utn_getNombre(auxEmployee.lastName, 51, "\nApellido: ", "\nApellido incorrecto\n", 20);
		utn_getNumeroFlotante(&auxEmployee.salary, "\nSalario: ", "\nSalario incorrecto\n", 0, 300000.00, 10);
		utn_getNumero(&auxEmployee.sector, "\nSector: ", "\nSector incorrecto", 1, 10, 20);
		if(addEmployee(list, listLen, newId, auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector)==-1){
			printf("\nError");
		}
		else {
			isLoaded = 1;
			(*thisID)++;
		}
	}
	return isLoaded;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
	int sucess = -1;
	int index;
	Employee auxiliar;

	if(list!=NULL && len > 0){
		index = FindFreePlace(list,len); // buscar libre
			if (index <0){
				printf("\nError");
			}
			else{
			auxiliar.id = id;
			strcpy(auxiliar.name, name);
			strcpy(auxiliar.lastName, lastName);
			auxiliar.salary = salary;
			auxiliar.sector = sector;
			auxiliar.isEmpty = 0;
			sucess = 0;
			list[index]=auxiliar;
		}
	}
	return sucess;
}

int findEmployeeById(Employee* list, int len,int id){
	int i;
	int retorno = -1;
	for(i = 0; i < len; i++){
		if (list[i].id == id && list[i].isEmpty==0){
			retorno = i;
			break;
		}
	}
	return retorno;
}

int removeEmployee(Employee* list, int len, int id){

	int retorno = -1;
	int indice = -1;

	indice= findEmployeeById(list,len,id);

	if(indice == -1){
		printf("No se encontro al empleado: %d.\n",id);
		system("pause");
	}
	else{
		showEmployee(list[indice]);
		list[indice].isEmpty = 1;
		printf("Se borro al empleado\n");
		retorno = 0;
		system("pause");
	}
	return retorno;
}

int menu(){
	char opcionElegida;

	printf("---Menu---\n");
	printf("Seleccionar una opcion: \n");
	printf("A - Dar de alta.\n");
	printf("B - Modificar empleado.\n");
	printf("C - Dar de baja empleado.\n");
	printf("D - Informes.\n");
	printf("E - Salir.\n");
	fflush(stdin);
	getString(&opcionElegida,sizeof(opcionElegida));
	opcionElegida = tolower(opcionElegida);

	return opcionElegida;
}

void totalAverageSalary(int* totalSalary, float* averageSalary,Employee list[],int len){
	int totalSalaryEmployee = 0;
	int totalEmployee = 0;
	float averageSalaryEmployee = 0;

	for(int i = 0; i < len; i++){
			if (list[i].isEmpty==0){
				totalSalaryEmployee += list[i].salary;
				totalEmployee++;
				//break;
			}
		}
	*totalSalary = totalSalaryEmployee;
	if (totalEmployee!=0){
		averageSalaryEmployee = (float)totalSalaryEmployee/totalEmployee;
		*averageSalary = averageSalaryEmployee;
	}
	printf("\nEl salario total es  $ %d\n",totalSalaryEmployee);
	printf("El promedio es $ %.2f\n",averageSalaryEmployee);
}

void knowHowManySalaryBigger(float* averageSalary,int flag, Employee list[],int len){
	for(int i = 0; i < len; i++){
			if (list[i].salary > *averageSalary && list[i].isEmpty == 0){
				showEmployee(list[i]);
				flag = 1;
			}
	}
}

int sortEmployees(Employee* list, int len, int order){
    Employee employee;
    int sortOrder = order;
    int everythingOK = -1;

     if(sortOrder==1){
        for(int i=0; i<len-1; i++){ //Ascending
            for(int j=i+1; j<len; j++){
                if(strcmp(list[j].lastName,list[i].lastName)<0){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0 &&
                			list[i].sector>list[j].sector){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
            }
        }
        everythingOK = 1;
    }

    if(sortOrder==0){
        for(int i=0; i<len-1; i++){ //Descending
            for(int j=i+1; j<len; j++) {
                if(strcmp(list[j].lastName,list[i].lastName)>0){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0 &&
                				list[i].sector<list[j].sector){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
            }
        }
        everythingOK = 1;
    }

    printEmployees(list,len);
    return everythingOK;
}

void showEmployee(Employee emplo){
   printf("\n    %d    %10s   %10s   %.2f       %d\n", emplo.id, emplo.name,emplo.lastName,emplo.salary,emplo.sector);
}

int printEmployees(Employee* list, int length){
	printf("\n----------------------- Empleado ----------------------- \n");
	printf("   Id       Nombre        Apellido     Salario     Sector\n");

	for (int i = 0;i<length;i++){
		if (list[i].isEmpty==0){
			showEmployee(list[i]);
		}
	}
	return 0;
}

void modifyEmployee(Employee vec[], int tam){

	int id;
	int indice;
	char confirma;
	Employee auxEmpleadoChange;

	int opcionModificar;

	system("cls");
	printf("--- Modificar ---\n\n");
	printEmployees(vec,tam);

	utn_getNumero(&id,"\nId: ","\nId incorrecta ",500,2000,200);

	indice = findEmployeeById(vec,tam,id); //devuelve la posicion donde esta el empleado, o -1

	if(indice == -1)
	{
		printf("\nLa id: %d no se encuentra.", id);
	}
	else
	{
		printf("\nEl empleado %d es: \n", id);
		printf("   Id       Nombre        Apellido     Salario     Sector\n");
		showEmployee(vec[indice]);
		printf("\nQue quiere modificar?");
		printf("\n1 - Nombre."
			   "\n2 - Apellido."
			   "\n3 - Salario."
			   "\n4 - Sector."
			   "\n5 - Atras.\n");
				scanf("%d",&opcionModificar);
		do{
			switch(opcionModificar){
			case 1: 
				printf("\nCambiar nombre? y/n: ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 'y'){
					if (utn_getNombre(auxEmpleadoChange.name,51,"Escribir el nombre nuevo: \n","Error\n",0)==0){
						strncpy(vec[indice].name,auxEmpleadoChange.name,51);
						printf("\nEl nombre del empleado se cambio\n");
					}

				}
				else{
					printf("\nSe cancelo\n");
					confirma ='n';
				}
				break;
			case 2: 
				printf("\nCambiar apellido? y/n: ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 'y'){

					if(utn_getNombre(auxEmpleadoChange.lastName,51,"\nEscribir el apellido nuevo: ","\nError",0)==0){
						strncpy(vec[indice].lastName,auxEmpleadoChange.lastName,51);
						printf("\nEl apellido del empleado se cambio\n");
					}
				}
				else{
					printf("\nSe cancelo\n");
					confirma ='n';
				}
				break;
			case 3: // Salary
				printf("\nCambiar salario? y/n: ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 'y'){
					
					utn_getNumeroFlotante(&auxEmpleadoChange.salary,"\nEscribir el nuevo salario: ","\nError tiene que ser entre 15k y 75k.",15000,75000,2);
					
					vec[indice].salary = auxEmpleadoChange.salary;
					printf("\nEl salario del empleado se cambio\n");
				}
				else{
					printf("\nSe cancelo\n");
					confirma ='n';
				}
				break;
			case 4: 
				printf("\nCambiar sector? y/n: ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 'y'){
					utn_getNumero(&auxEmpleadoChange.sector,"\nEscribir el sector nuevo:","\nERROR tiene que ser entre 1 y 5.",1,5,2);
					vec[indice].sector = auxEmpleadoChange.sector;
					printf("\nSe actualizo\n");
				}
				else{
					printf("\nSe cancelo.\n");
					confirma ='n';
				}
				break;
			default:
				confirma ='n';
				break;
			}
			system("pause");
		}while(confirma=='s');
	}
}
