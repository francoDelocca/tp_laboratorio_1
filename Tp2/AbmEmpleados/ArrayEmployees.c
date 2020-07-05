#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int idAutoGenerico = 1;

int initEmployees(eEmployee listEmployees[], int lenEmployees)
{
    int i;
    for(i=0;i < lenEmployees;i++)
    {
        listEmployees[i].isEmpty = LIBRE;
    }
    return 0;
}

int addEmployee(eEmployee listEmployees[], int lenEmployees, char name[],char
lastName[],float salary,int sector)
{
    int i;
    char banderaEmpty = 'n';
    for(i = 0;i < lenEmployees;i++)
    {
        if(listEmployees[i].isEmpty == LIBRE)
        {
            listEmployees[i].id = idAutoGenerico;
            listEmployees[i].isEmpty = OCUPADO;
            strcpy(listEmployees[i].name,name);
            strcpy(listEmployees[i].lastName,lastName);
            listEmployees[i].salary = salary;
            listEmployees[i].sector = sector;
            banderaEmpty = 's';
            break;
        }
    }

    if(banderaEmpty == 'n')
    {
        return -1;
    }

    idAutoGenerico++;
    return 0;
}

int findEmployeeById(eEmployee listEmployees[], int lenEmployees,int id)
{
    int i;

    for(i = 0;i < lenEmployees;i++)
    {
        if(listEmployees[i].id == id)
        {
           return i;
        }

    }
    return -1;
}

int removeEmployee(eEmployee listEmployees[], int lenEmployees, int id)
{
    int i;
    for(i=0;i<lenEmployees;i++)
    {
        if(listEmployees[i].id == id)
        {
           listEmployees[i].isEmpty = LIBRE;
           return 0;
        }
    }
    return -1;
}

int sortEmployees(eEmployee listEmployees[], int lenEmployees, int order)
{
    int i;
    int j;
    eEmployee auxEmployee;

    for(i=0; i<lenEmployees-1; i++)
    {
        for(j=i+1; j<lenEmployees; j++)
        {
            if(strcmp(listEmployees[i].lastName,listEmployees[j].lastName)>0 && listEmployees[i].isEmpty == OCUPADO && listEmployees[j].isEmpty == OCUPADO)
            {
                if(order == 1)
                {
                    auxEmployee =  listEmployees[i];
                    listEmployees[i] = listEmployees[j];
                    listEmployees[j] = auxEmployee;
                }else if(order == 0)
                {
                    auxEmployee =  listEmployees[j];
                    listEmployees[j] = listEmployees[i];
                    listEmployees[i] = auxEmployee;
                }
            }
            else
            {
               if(strcmp(listEmployees[i].lastName,listEmployees[j].lastName)==0)
               {
                   if(listEmployees[i].sector>listEmployees[j].sector)
                   {
                        if(order == 1)
                        {
                            auxEmployee =  listEmployees[i];
                            listEmployees[i] = listEmployees[j];
                            listEmployees[j] = auxEmployee;
                        }else if(order == 0)
                        {
                            auxEmployee =  listEmployees[j];
                            listEmployees[j] = listEmployees[i];
                            listEmployees[i] = auxEmployee;
                        }
                   }
               }
            }

        }
    }
    return 0;
}

int printEmployees(eEmployee listEmployees[], int lenEmployees)
{
    int i;
    printf("%8s %20s %20s %10s %8s\n", "Id",
                                       "Nombre",
                                       "Apellido",
                                       "Salario",
                                       "Sector");

    for(i = 0; i < lenEmployees; i++)
    {
          if(listEmployees[i].isEmpty == OCUPADO)
            {
                printEmployee(listEmployees[i]);
            }

    }

    return 0;
}

void printEmployee(eEmployee myEmployee)
{
    printf("%8d %20s %20s %10.2f %8d\n", myEmployee.id,
                                           myEmployee.name,
                                           myEmployee.lastName,
                                           myEmployee.salary,
                                           myEmployee.sector);
}

int modifyEmployee(eEmployee listEmployees[], int position)
{
    int option, sector;
    char name[51], lastName[51];
    float salary;
    printf("Ingrese el numero de opcion a modificar\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Salario\n");
    printf("4. Sector\n");
    scanf("%d", &option);

    switch(option)
    {
    case 1:
        printf("Ingrese el nuevo nombre de %s\n", listEmployees[position].name);
        scanf("%s", name);
        strcpy(listEmployees[position].name,name);
        break;

    case 2:
        printf("Ingrese el nuevo apellido de %s\n", listEmployees[position].lastName);
        scanf("%s", lastName);
        strcpy(listEmployees[position].lastName,lastName);
        break;

    case 3:
        printf("Ingrese el nuevo salario. Salario anterior: %.2f\n", listEmployees[position].salary);
        scanf("%f", &salary);
        listEmployees[position].salary = salary;
        break;

    case 4:
        printf("Ingrese el nuevo sector. Sector anterior: %d\n", listEmployees[position].sector);
        scanf("%d", &sector);
        listEmployees[position].sector = sector;
        break;
    }

    return 0;
}

void calcSalary(eEmployee listEmployees[], int lenEmployees)
{
    float salaryTotal = 0, avgSalary;
    int contEmployees = 0, contEmployeesSalary = 0, i;
    for(i = 0; i < lenEmployees; i++)
    {
      if(listEmployees[i].isEmpty == OCUPADO)
      {
        salaryTotal += listEmployees[i].salary;
        contEmployees++;
      }
    }
    avgSalary = salaryTotal / contEmployees;
    for(i = 0; i < lenEmployees; i++)
    {
      if(listEmployees[i].isEmpty == OCUPADO)
      {
        if(listEmployees[i].salary >= avgSalary)
        {
            contEmployeesSalary++;
        }
      }
    }
    printf("\nEl salario total es: %.2f\nEl promedio de los salarios es: %.2f\n%d empleados superan o igualan el salario promedio\n",
           salaryTotal, avgSalary, contEmployeesSalary);
}

int haveEmployees(eEmployee listEmployees[], int lenEmployees)
{
    int i;

    for(i = 0; i < lenEmployees; i++)
    {
        if(listEmployees[i].isEmpty == OCUPADO)
        {
            return 1;
        }
    }

    return 0;
}
