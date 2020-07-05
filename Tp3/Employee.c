#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* newEmployee;
    newEmployee = (Employee*)malloc(sizeof(Employee));

    return newEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee;
    newEmployee = employee_new();

    int id;
    int horasTrabajadas;
    int sueldo;

    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);

    if(newEmployee != NULL)
    {
        employee_setNombre(newEmployee, nombreStr);
        employee_setId(newEmployee, id);
        employee_setHorasTrabajadas(newEmployee, horasTrabajadas);
        employee_setSueldo(newEmployee, sueldo);
    }

    return newEmployee;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = 0;
    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        error = 1;
    }

    return error;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int error = 0;
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        error = 1;
    }

    return error;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int error = 0;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        error = 1;
    }

    return error;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 0;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        error = 1;
    }

    return error;
}

int employee_delete(Employee* this)
{
    int error = 0;
    if(this != NULL)
    {
        free(this);
        error = 1;
    }
    return error;
}

int employee_setId(Employee* this, int id)
{
    int error = 0;
    static int maximoId = -1;
    if(this != NULL)
    {
        if(id < 0)
        {
            maximoId++;
            this->id = maximoId;
        }else
        {
            if(id > maximoId)
            {
                maximoId = id;
            }
            this->id = id;
        }

        error = 1;
    }

    return error;
}
int employee_getId(Employee* this, int* id)
{
    int error = 0;
    if(this != NULL)
    {
        *id = this->id;
        error = 1;
    }

    return error;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int error = 0;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 1;
    }

    return error;
}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int error = 0;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 1;
    }

    return error;
}

int employee_funcionCriterioSueldo(void* item1, void* item2)
{
    int error = 0;
    int e1;
    int e2;

    employee_getSueldo(item1, &e1);
    employee_getSueldo(item2, &e2);

    if(e1 > e2)
    {
        error = 1;
    }else if(e1 < e2)
    {
        error = -1;
    }

    return error;
}

int employee_funcionCriterioHorasTrabajadas(void* item1, void* item2)
{
    int error = 0;
    int e1;
    int e2;

    employee_getHorasTrabajadas(item1, &e1);
    employee_getHorasTrabajadas(item2, &e2);

    if(e1 > e2)
    {
        error = 1;
    }else if(e1 < e2)
    {
        error = -1;
    }

    return error;
}

int employee_funcionCriterioNombre(void* item1, void* item2)
{
    int error = 0;
    char e1[50];
    char e2[50];

    employee_getNombre(item1, e1);
    employee_getNombre(item2, e2);

    if(strcmp(e1, e2) > 0)
    {
        error = 1;
    }else if(strcmp(e1, e2) < 0)
    {
        error = -1;
    }

    return error;
}

int employee_CompareByName(Employee* e1, Employee* e2)
{
    //verificar nulidad

    return strcmp(e1->nombre, e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    //verificar nulidad

    if(e1->id > e2->id)
    {
        return 1;
    }
    else
    {
        if(e1->id < e2->id)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }



    return strcmp(e1->nombre, e2->nombre);
}



