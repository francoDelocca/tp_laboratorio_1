#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Validation.h"


int controller_findLastId(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int i;
    int idMayor = 0;
    int idEmployee;
    int tamLista;

    if(pArrayListEmployee != NULL)
    {
        tamLista = ll_len(pArrayListEmployee);
        if(!tamLista > 0)
        {
            idMayor = 0;
        }else
        {
            for(i = 0; i < tamLista; i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                employee_getId(pEmployee, &idEmployee);
                if(idEmployee > idMayor)
                {
                    idMayor = idEmployee;
                }
            }
        }
    }
    return idMayor;
}


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int error = 0;

    pArchivo = fopen(path, "r");

    if(pArchivo != NULL)
    {
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
        error = 1;
    }
    fclose(pArchivo);

    return error;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int error = 0;

    pArchivo = fopen(path, "r");
    if(pArchivo != NULL)
    {
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
        error = 1;
    }
    fclose(pArchivo);
    return error;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    pEmployee = employee_new();

    int error = 0;
    int sueldo;
    int horasTrabajadas;
    int id;
    char nombre[50];

    if(pArrayListEmployee != NULL && pEmployee != NULL)
    {
        id = controller_findLastId(pArrayListEmployee) + 1;
        printf("\nIngrese un nombre: ");
        scanf("%s", nombre);
        while(isOnlyLetters(nombre) == 0)
        {
            printf("\nIngrese un nombre correcto: ");
            scanf("%s", nombre);
        }

        sueldo = getInt("\nIngrese un sueldo: ");
        while(isPositive(sueldo) == 0)
        {
            printf("\nIngrese un numero positivo");
            sueldo = getInt("\nIngrese un sueldo: ");
        }

        horasTrabajadas = getInt("\nIngrese las horas trabajadas: ");
        while(isPositive(horasTrabajadas) == 0)
        {
            printf("\nIngrese un numero positivo");
            horasTrabajadas = getInt("\nIngrese las horas trabajadas: ");
        }

        employee_setId(pEmployee, id);
        employee_setNombre(pEmployee, nombre);
        employee_setSueldo(pEmployee, sueldo);
        employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
        ll_add(pArrayListEmployee, pEmployee);
        error = 1;
    }

    return error;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    int error = 0;
    int i;
    int opcion;
    int sueldo;
    int horasTrabajadas;
    int idIngresado;
    int idCliente;
    int tamlista;
    char nombre[50];
    char encontroEmpleado = 'n';

    if(pArrayListEmployee != NULL)
    {
        tamlista = ll_len(pArrayListEmployee);

        idIngresado = getInt("\nIngrese el id del empleado a modificar: ");
        while(isPositive(idIngresado) == 0)
        {
            printf("\nIngrese un id mayor a 0");
            idIngresado = getInt("\nIngrese el id del empleado a modificar: ");
        }

        for(i = 0; i < tamlista; i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(pEmployee, &idCliente);

            if(idIngresado == idCliente)
            {
                encontroEmpleado = 's';
                printf("\nIngrese campo a modificar");
                printf("\n1.Nombre");
                printf("\n2.Sueldo");
                printf("\n3.Horas de trabajo");

                opcion = getInt("\nElija una opcion: ");
                while(opcion > 3 || opcion < 1)
                {
                    printf("\nIngrese una opcion valida");
                    opcion = getInt("\nElija una opcion");
                }

                switch(opcion)
                {
                    case 1:
                        getString("\nIngrese el nuevo nombre: ", nombre);
                        while(isOnlyLetters(nombre) == 0)
                        {
                            printf("\nIngrese un nombre valido");
                            getString("\nIngrese el nuevo nombre: ", nombre);
                        }
                        employee_setNombre(pEmployee, nombre);
                        error = 1;
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        sueldo = getInt("\nIngrese el nuevo sueldo: ");
                        while(isPositive(sueldo) == 0)
                        {
                            printf("\nIngrese un sueldo mayor a 0");
                            sueldo = getInt("\nIngrese el nuevo sueldo: ");
                        }
                        employee_setSueldo(pEmployee, sueldo);
                        error = 1;
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        horasTrabajadas = getInt("\nIngrese las nuevas horas trabajadas: ");
                        while(isPositive(horasTrabajadas) == 0)
                        {
                            printf("\nIngrese horas trabajadas mayor a 0");
                            horasTrabajadas = getInt("\nIngrese las nuevas horas trabajadas: ");
                        }
                        employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
                        error = 1;
                        system("pause");
                        system("cls");
                        break;
                    default:
                        printf("\nIngrese una opcion correcta");
                        system("pause");
                        system("cls");
                        break;
                }
            }
        }
        if(encontroEmpleado == 'n')
        {
            printf("\nNo se encontro ningun empleado con ese id\n");
        }

    }

    return error;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    int error = 0;
    int i;
    int opcion;
    int idIngresado;
    int idCliente;
    int tamlista;
    char encontroEmpleado = 'n';

    if(pArrayListEmployee != NULL)
    {
        tamlista = ll_len(pArrayListEmployee);

        idIngresado = getInt("\nIngrese el id del empleado a eliminar: ");
        while(isPositive(idIngresado) == 0)
        {
            printf("\nIngrese un id mayor a 0");
            idIngresado = getInt("\nIngrese el id del empleado a eliminar: ");
        }

        for(i = 0; i < tamlista; i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(pEmployee, &idCliente);

            if(idIngresado == idCliente)
            {
                encontroEmpleado = 's';
                ll_remove(pArrayListEmployee,i);
                system("pause");
                error = 1;
            }
        }
        if(encontroEmpleado == 'n')
        {
            printf("\nNo se encontro ningun empleado con ese id\n");
        }
    }

    return error;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int error = 0;
    int i;
    int tamLista;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[50];

    if(pArrayListEmployee != NULL)
    {
        tamLista = ll_len(pArrayListEmployee);

        printf("\nId Nombre Sueldo Horas");
        for(i = 0; i < tamLista; i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(pEmployee, &id);
            employee_getNombre(pEmployee, nombre);
            employee_getSueldo(pEmployee, &sueldo);
            employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
            printf("\n%d %s %d %d\n", id, nombre, sueldo, horasTrabajadas);
            error = 1;
        }
    }

    return error;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error = 0;
    int opcion;

    if(pArrayListEmployee != NULL)
    {
        printf("\nIngrese opcion para ordenamiento");
        printf("\n1.Nombre");
        printf("\n2.Sueldo");
        printf("\n3.Horas de trabajo");

        opcion = getInt("\nElija una opcion: ");
        while(opcion > 3 || opcion < 1)
        {
            printf("\nIngrese una opcion valida");
            opcion = getInt("\nElija una opcion");
        }

        switch(opcion)
        {
            case 1:
                ll_sort(pArrayListEmployee, employee_funcionCriterioNombre, 1);
                error = 1;
                system("pause");
                break;
            case 2:
                ll_sort(pArrayListEmployee, employee_funcionCriterioSueldo, 1);
                error = 1;
                system("pause");
                break;
            case 3:
                ll_sort(pArrayListEmployee, employee_funcionCriterioHorasTrabajadas, 1);
                error = 1;
                system("pause");
                break;
            default:
                printf("\nIngrese una opcion correcta");
                system("pause");
                break;
        }
    }
    return error;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* pEmployee;
    int error = 0;
    int i;
    int tamLista;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[50];

    pArchivo = fopen(path,"w");

    if(pArchivo != NULL)
    {
        tamLista = ll_len(pArrayListEmployee);
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i<tamLista; i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(pEmployee, &id);
            employee_getNombre(pEmployee, nombre);
            employee_getSueldo(pEmployee, &sueldo);
            employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
            fprintf(pArchivo,"%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
        }

        fclose(pArchivo);
        error = 1;
    }
    return error;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* pEmployee;
    int error = 0;
    int i;
    int tamLista;

    pArchivo = fopen(path,"wb");

    if(pArchivo != NULL)
    {
        tamLista = ll_len(pArrayListEmployee);

        for(i=0; i<tamLista; i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            fwrite(pEmployee, sizeof(Employee), 1, pArchivo);
        }

        fclose(pArchivo);
        error = 1;
    }
    return error;
}

