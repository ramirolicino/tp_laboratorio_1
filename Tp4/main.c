#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "menu.h"
#include "autos.h"
#include "validar.h"


int main()
{
    LinkedList* listaAutos = ll_newLinkedList();

    char rta;
    char seguir = 'n';
    char salir;
    int flag = 0;

    do
    {
        switch(menu())
        {
        case 1:
            if(!flag)
            {
                if(!controller_loadFromTxt(listaAutos,"autosData.csv"))
                {
                    printf(" * CORRECTO * \n\n");
                    flag=1;

                }
                else
                {
                    printf(" * ERROR AL CARGAR *\n\n");
                }
            }
            else
            {
                printf(" * AUTOS YA CARGADOS *\n\n");
            }
            break;

        case 2:
            if(!controller_add(listaAutos))
            {
                printf(" * ALTA EXITOSA *\n\n");
            }
            else
            {
                printf(" * ERROR ALTA *\n\n");
            }
            break;

        case 3:
            if(!ll_isEmpty(listaAutos))
            {
                if(!controller_edit(listaAutos))
                {
                    printf(" * MODIFICACION EXITOSA *\n\n");
                }
                else
                {
                    printf(" * ERROR MODIFICACION *\n\n");
                }
            }
            else
            {
                printf(" * PRIMERO CARGAR AUTOS *\n\n");
            }
            break;

        case 4:
            if(!ll_isEmpty(listaAutos))
            {
                if(!controller_remove(listaAutos))
                {
                    printf(" * BAJA EXITOSA *\n\n");
                }
                else
                {
                    printf(" * ERROR BAJA *\n\n");
                }
            }
            else
            {
                printf(" * PRIMERO CARGAR AUTOS *\n\n");
            }
            break;

        case 5:
            if(!ll_isEmpty(listaAutos))
            {
                if(!controller_sort(listaAutos))
                {
                    printf(" * ORDENAMINETO EXITOSO *\n\n");
                }
                else
                {
                    printf(" * ERROR ORDENAMINETO *\n\n");
                }
            }
            else
            {
                printf(" * PRIMERO CARGAR AUTOS *\n\n");
            }
            break;

        case 6:
            if(!ll_isEmpty(listaAutos))
            {
                controller_list(listaAutos);
            }
            else
            {
                printf(" * NO HAY AUTOS *\n\n");
            }
            break;

        case 7:
            if(!controller_insertCar(listaAutos))
            {
                printf(" * AUTO AGREGADO EXITOSAMENTE *\n\n");
            }
            else
            {
                printf(" * ERROR AUTO AGREGADO *\n\n");
            }
            break;

        case 8:
            if(!ll_isEmpty(listaAutos))
            {
                rta = controller_clearList(listaAutos);
                if(rta == -1)
                {
                    printf(" * ERROR CARGAR LA LISTA *\n\n");
                }
                else if(!rta)
                {
                    printf(" * LISTA VACIA *\n\n");
                }
                else
                {
                    printf(" * OPERACION CANCELADA *\n\n");
                }
            }
            else
            {
                printf(" * PRIMERO CARGAR AUTOS *\n\n");
            }
            break;

             case 9:
            if(!ll_isEmpty(listaAutos))
            {
                printf(" * PRIMERO CARGAR AUTOS *\n\n");
            }
            else
            {
                if(!controller_saveAsTxt(listaAutos,"autosData.csv"))
                {
                    printf(" * AUTOS GUARDADOS EXITOSAMENTE *\n\n");
                }else
                {
                    printf(" * ERROR AL GUARDAR LISTA *\n\n");
                }
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
            printf("\nOpcion no valida\n\n");
            break;
        }

        system("pause");

    }
    while(seguir != 's');

    ll_deleteLinkedList(listaAutos);//borro la lista cuando termina el programa


    return 0;
}
