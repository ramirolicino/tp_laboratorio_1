#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

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

    int flagTxt = 0;
    int flagBin = 0;
    int flagAdd = 0;

    char seguir = 'n';
    char salir;



    do
    {
        switch(menu())
        {
        case 1:
            if(flagBin||flagTxt)
            {
                printf(" * LOS EMPLEADOS YA SE CARGARON * \n\n");
            }
            else
            {
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf(" * EMPLEADOS CARGADOS EXITOSAMENTE (texto) *\n\n");
                    flagTxt=1;
                }
                else
                {
                    printf(" * ERROR AL CARGAR EMPLEADOS (texto) *\n\n");
                }
            }
            break;

        case 2:
            if(flagTxt||flagBin)
            {
                printf(" * LOS EMPLEADOS YA SE CARGARON *\n\n");
            }
            else
            {
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf(" * EMPLEADOS CARGADOS EXITOSAMENTE (bin) *\n\n");
                    flagBin=1;
                }
                else
                {
                    printf(" * ERROR AL CARGAR EMPLEADOS (bin) *\n\n");
                }
            }
            break;

        case 3:
            if(!controller_addEmployee(listaEmpleados))
            {
                printf(" * ALTA EXITOSA * \n\n");
                flagAdd=1;
            }
            else
            {
                printf(" * ERROR EN EL ALTA * \n\n");
            }
            break;

        case 4:
            if(flagAdd||flagBin||flagTxt)
            {
                switch(controller_editEmployee(listaEmpleados))
                {
                case -1:
                    printf(" * ERROR AL MODIFICAR * \n\n");//parametro null o id no existe
                    break;
                case 0:
                    printf(" * MODIFICACION EXITOSA * \n\n");
                    break;
                case 1:
                    printf(" * OPERACION CALNCELADA * \n\n");
                    break;
                }
            }
            else
            {
                printf(" * PRIMERO CARGAR EMPLEADO... * \n\n");
            }
            break;

        case 5:
            if(flagAdd||flagBin||flagTxt)
            {
                switch(controller_removeEmployee(listaEmpleados))
                {
                case -1:
                    printf(" * ERROR AL ELIMINAR * \n\n");//parametro null o id no existe
                    break;
                case 0:
                    printf(" * ELIMINACION EXITOSA * \n\n");
                    break;
                case 1:
                    printf(" * OPERACION CALNCELADA * \n\n");
                    break;
                }
            }
            else
            {
                printf(" * PRIMERO CARGAR EMPLEADO... * \n\n");
            }
            break;

        case 6:
            if(flagAdd||flagBin||flagTxt)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf(" * PRIMERO CARGAR EMPLEADO... * \n\n");
            }
            break;

        case 7:
            if(flagAdd||flagBin||flagTxt)
            {
                if(!controller_sortEmployee(listaEmpleados))
                {
                    printf(" * EMPLEADOS ORDENADOS * \n\n");
                }
                else
                {
                    printf(" * ERROR AL ORDENAR EMPLEADOS * \n\n");
                }
            }
            else
            {
                printf(" * PRIMERO CARGAR EMPLEADO... * \n\n");
            }
            break;

        case 8:
            if(flagAdd||flagBin||flagTxt)
            {
                if(!controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf(" * EMPLEADOS GUARDADOS EXITOSAMENTE (texto) * \n\n");
                }
                else
                {
                    printf(" * PROBLEMAS PARA GUARDAR EMPLEADOS (texto) * \n\n");
                }
            }
            else
            {
                printf(" * NO HAY EMPLEADOS PARA GUARDAR  * \n\n");
            }
            break;

        case 9:
            if(flagAdd||flagBin||flagTxt)
            {
                if(!controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf(" * EMPLEADOS GUARDADOS EXITOSAMENTE (bin) * \n\n");
                }
                else
                {
                    printf(" * PROBLEMAS PARA GUARDAR EMPLEADOS (bin) * \n\n");
                }
            }
            else
            {
                printf(" * NO HAY EMPLEADOS PARA GUARDAR  * \n\n");
            }
            break;

        case 10:
            printf("SALIR?(S/N)-> ");
            fflush(stdin);
            scanf("%c", &salir);

            if(salir == 's')
            {
                seguir = 's';
            }

            break;

        default:
            printf("Ingrese opcion correcta... \n");
            break;
        }

        system("pause");
    }
    while(seguir == 'n');

    ll_deleteLinkedList(listaEmpleados);


    return 0;
}
