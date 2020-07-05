#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int error = 0;
    char id[100];
    char nombre[100];
    char horasTrabajadas[100];
    char sueldo[100];

    if(pFile != NULL)
    {
        do
        {
            fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, nombre, horasTrabajadas, sueldo);
            pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

            if(pEmployee != NULL)
            {
                ll_add(pArrayListEmployee, pEmployee);
                error = 1;
            }
        } while(!feof(pFile));
    }
    return error;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int error = 0;

    if(pFile != NULL)
    {
        do
        {
            pEmployee = employee_new();
            if(pEmployee != NULL)
            {
                fread(pEmployee, sizeof(Employee), 1, pFile);
                ll_add(pArrayListEmployee, pEmployee);
                error = 1;
            }
        } while(!feof(pFile));
    }

    return 1;
}
