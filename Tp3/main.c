#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();

    int opcion;
    int validator;
    do
    {
        system("cls");
        printf("1. Cargar los datos de los empleados desde el archivo csv\n");
        printf("2. Cargar los datos de los empleados desde el archivo binario\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados desde el archivo csv\n");
        printf("9. Guardar los datos de los empleados desde el archivo binario\n");
        printf("10. Salir\n");
        printf("Elija una opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            validator = controller_loadFromText("data.csv", listaEmpleados);
            if(validator == 1)
            {
                printf("\nSe ha cargado el archivo correctamente");
            }else
            {
                printf("\nNo se ha cargado el archivo correctamente");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            validator = controller_loadFromBinary("data.bin", listaEmpleados);
            if(validator == 1)
            {
                printf("\nSe ha cargado el archivo correctamente");
            }else
            {
                printf("\nNo se ha cargado el archivo correctamente");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            validator = controller_addEmployee(listaEmpleados);
            if(validator == 1)
            {
                printf("\nSe ha cargado el empleado correctamente");
            }else
            {
                printf("\nNo se pudo cargar el empleado correctamente");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            controller_ListEmployee(listaEmpleados);
            validator = controller_editEmployee(listaEmpleados);
            if(validator == 1)
            {
                printf("\nSe ha modificado el empleado correctamente");
            }else
            {
                printf("\nNo se pudo modificar el empleado correctamente");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            controller_ListEmployee(listaEmpleados);
            validator = controller_removeEmployee(listaEmpleados);
            if(validator == 1)
            {
                printf("\nSe ha eliminado el empleado correctamente");
            }else
            {
                printf("\nNo se pudo eliminar el empleado correctamente");
            }
            system("pause");
            system("cls");
            break;
        case 6:
            validator = controller_ListEmployee(listaEmpleados);
            if(validator == 0)
            {
                printf("\nNo se pudo listar los empleados");
            }
            system("pause");
            system("cls");
            break;
        case 7:
            validator = controller_sortEmployee(listaEmpleados);
            if(validator == 1)
            {
                printf("\nSe ordenaron correctamente los empleados");
            }else
            {
                printf("\nNo se pudo ordenar los empleados correctamente");
            }
            system("pause");
            system("cls");
            break;
        case 8:
            validator = controller_saveAsText("dataNuevo.csv", listaEmpleados);
            if(validator == 1)
            {
                printf("\nArchivo de lectura guardado");
            }else
            {
                printf("\nNo se pudo guardar el archivo de lectura");
            }
            system("pause");
            system("cls");
            break;
        case 9:
            validator = controller_saveAsBinary("dataNuevo.bin", listaEmpleados);
            if(validator == 1)
            {
                printf("\nArchivo binario guardado");
            }else
            {
                printf("\nNo se pudo guardar el archivo binario");
            }
            system("pause");
            system("cls");
            break;
        case 10:
            break;
        default:
            printf("\nOpcion incorrecta");
            system("pause");
            break;
        }
    } while(opcion != 10);
    return 0;
}
