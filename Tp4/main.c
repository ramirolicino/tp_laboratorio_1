#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "autos.h"
#include "validar.h"
#include "Controller.h"
#include "menu.h"



int main()
{
     LinkedList* listaAutos = ll_newLinkedList();

    int flagTxt = 0;
    char seguir = 'n';
    char salir;



    do
    {
        switch(menu())
        {
        case 1:
            if(flagTxt)
            {
                printf(" * LOS AUTOS YA SE CARGARON * \n\n");
            }
            else
            {
                if(!controller_loadFromText("AUTOS.csv",listaAutos))
                {
                    printf(" * AUTOS CARGADOS EXITOSAMENTE (texto) *\n\n");
                    flagTxt=1;
                }
                else
                {
                    printf(" * ERROR AL CARGAR AUTOS (texto) *\n\n");
                }
            }
            break;

        case 3:
            if(!controller_addCar(listaAutos))
            {
                printf(" * ALTA EXITOSA * \n\n");
            }
            else
            {
                printf(" * ERROR EN EL ALTA * \n\n");
            }
            break;

        case 4:
            if(flagTxt)
            {
                switch(controller_editCar(listaAutos))
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
            if(flagTxt)
            {
                switch(controller_removeCar(listaAutos))
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
            if(flagTxt)
            {
                controller_ListCar(listaAutos);
            }
            else
            {
                printf(" * PRIMERO CARGAR EMPLEADO... * \n\n");
            }
            break;

        case 7:
            if(flagTxt)
            {
                if(!controller_sortCar(listaAutos))
                {
                    printf(" * AUTOS ORDENADOS * \n\n");
                }
                else
                {
                    printf(" * ERROR AL ORDENAR AUTOS * \n\n");
                }
            }
            else
            {
                printf(" * PRIMERO CARGAR EMPLEADO... * \n\n");
            }
            break;

        case 8:
            if(flagTxt)
            {
                if(!controller_saveAsText("data.csv",listaAutos))
                {
                    printf(" * AUTOS GUARDADOS EXITOSAMENTE (texto) * \n\n");
                }
                else
                {
                    printf(" * PROBLEMAS PARA GUARDAR AUTOS (texto) * \n\n");
                }
            }
            else
            {
                printf(" * NO HAY AUTOS PARA GUARDAR  * \n\n");
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

    ll_deleteLinkedList(listaAutos);

    return 0;
}
