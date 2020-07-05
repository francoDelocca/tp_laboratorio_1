#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Validation.h"
#define LENGTHEMPLOYEES 1000

int main()
{
    eEmployee listEmployees[LENGTHEMPLOYEES];
    int opcion, a, sector, m, idMod, b, idDel, i, init;
    char name[51], lastName[51], nameFunc[51], lastnameFunc[51];
    float salary;
    init = initEmployees(listEmployees, LENGTHEMPLOYEES);
    if(init == 0)
    {
        printf("Empleado inicializados correctamente");
    }else {
        printf("No se pudo inicializar los empleados");
    }
    do
    {
        system("cls");
        printf("1. Alta de empleado\n");
        printf("2. Modificar empleado\n");
        printf("3. Baja de empleado\n");
        printf("4. Informar\n");
        printf("5. Salir\n");
        printf("Elija una opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            getString("Ingrese el nombre: ", nameFunc);
            while(isOnlyLetters(nameFunc) == 0)
            {
                printf("Por favor ingrese un nombre valido\n");
                getString("Ingrese el nombre: ", nameFunc);
            }

            getString("Ingrese el apellido: ", lastnameFunc);
            while(isOnlyLetters(lastnameFunc) == 0)
            {
                printf("Por favor ingrese un apellido valido\n");
                getString("Ingrese el apellido: ", lastnameFunc);
            }

            strcpy(name, nameFunc);
            strcpy(lastName, lastnameFunc);

            salary = getFloat("Ingrese el salario: ");
            while(isPositive(salary) == 0)
            {
                printf("Por favor ingrese un salario valido\n");
                salary = getFloat("Ingrese el salario: ");
            }

            sector = getInt("Ingrese el sector: ");
            while(isPositive(sector) == 0)
            {
                printf("Por favor ingrese un sector valido\n");
                sector = getInt("Ingrese el sector: ");
            }

            a = addEmployee(listEmployees, LENGTHEMPLOYEES, name,
                lastName, salary, sector);
            if(a == 0)
            {
                printf("Empleado agregado correctamente\n");
            }else {
                printf("No se pudo agregar el empleado\n");
            }
            system("pause");
            break;
        case 2:
            if(haveEmployees(listEmployees, LENGTHEMPLOYEES) == 1)
            {
                printf("Ingrese el id del empleado a modificar: ");
                scanf("%d", &idMod);
                m = findEmployeeById(listEmployees, LENGTHEMPLOYEES, idMod);
                if(m != -1)
                {
                    modifyEmployee(listEmployees, m);
                }else {
                    printf("No se pudo modificar el empleado, Ingrese un id valido\n");
                }
            } else
            {
                printf("Primero debe cargar un empleado\n");
            }

            system("pause");
            break;
        case 3:
            if(haveEmployees(listEmployees, LENGTHEMPLOYEES) == 1)
            {
                printf("Ingrese el id del empleado a borrar: ");
                scanf("%d", &idDel);
                b = removeEmployee(listEmployees, LENGTHEMPLOYEES, idDel);
                if(b == 0)
                {
                    printf("Empleado borrado correctamente\n");
                }else {
                    printf("No se pudo borrar el empleado, Ingrese un id valido\n");
                }
            } else
            {
                printf("Primero debe cargar un empleado\n");
            }
            system("pause");
            break;
        case 4:
            if(haveEmployees(listEmployees, LENGTHEMPLOYEES) == 1)
            {
                i = sortEmployees(listEmployees, LENGTHEMPLOYEES, 1);
                if(i == 0)
                {
                    system("cls");
                    printf("Los empleados se ordenaron correctamente\n");
                    printEmployees(listEmployees, LENGTHEMPLOYEES);
                    calcSalary(listEmployees, LENGTHEMPLOYEES);
                }else {
                    system("cls");
                    printf("No se pudo ordenar los empleados correctamente\n");
                }
            } else
            {
                printf("Primero debe cargar un empleado\n");
            }
            system("pause");
            break;
        case 5:
            break;
        default:
            printf("\nOpcion incorrecta");
            system("pause");
            break;
        }
    } while(opcion != 5);
    return 0;
}
