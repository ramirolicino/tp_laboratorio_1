#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "autos.h"
#include "menu.h"
#include "validar.h"


//-1 ERROR  0 OK


static int obtenerId(int* id)
{
    int todoOk = -1;
    FILE* f;

    if(id != NULL)
    {
        *id = 1001;

        f = fopen("proxId.bin","rb");

        if(f!=NULL)
        {
            fread(id,sizeof(int),1,f);
            todoOk = 0;

            fclose(f);
        }
    }

    return todoOk;
}

static int actualizarId(int id)
{
    int todoOk = -1;
    FILE* f;

    id++;

    f  = fopen("proxId.bin","wb");

    if(f != NULL)
    {
        fwrite(&id,sizeof(int),1,f);
        todoOk = 0;
        fclose(f);
    }

    return todoOk;
}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"r");

        if(pFile != NULL)
        {
            if(!parser_CarFromText(pFile,pArrayListEmployee))
            {
                todoOk = 0;
            }

            fclose(pFile);
        }
    }

    return todoOk;
}




int controller_addCar(LinkedList* pArrayListCar)
{
    int todoOk = -1;
    int auxId;
    int auxModelo;
    char auxMarca[128];
    float auxPrecio;
    eAutos* newCar = NULL;

    if(pArrayListCar != NULL)
    {
        system("cls");
        printf("   *** ALTA AUTO **\n\n");

        newCar = car_new();

        if(newCar != NULL)
        {
            getString(auxMarca,sizeof(auxMarca),"Ingrese marca:","ReIngrese marca:");
            getInt(&auxModelo,"Ingrese modelo:","ReIngrese modelo:");
            getFloat(&auxPrecio, "Ingrese precio:", "ReIngrese precio:");
            obtenerId(&auxId);
            actualizarId(auxId);

            if(!car_setId(newCar,auxId)&&
                    !car_setMarca(newCar,auxMarca)&&
                    !car_setModelo(newCar,auxModelo)&&
                    !car_setPrecio(newCar,auxPrecio))
            {
                ll_add(pArrayListCar,newCar);
                todoOk = 0;
            }
        }
    }

    return todoOk;
}


int controller_editCar(LinkedList* pArrayListCar)
{
    int todoOk = -1;
    int bufferModelo;
    int auxId;
    int indice;
    float bufferPrecio;
    char bufferMarca[128];
    char confirma;
    eAutos* auxCar;

    if(pArrayListCar != NULL)
    {
        system("cls");
        printf("   *** MODIFICACIONES ***\n\n");

        controller_ListCar(pArrayListCar);

        getInt(&auxId,"Ingrese id a modificar: ","ReIngrese id: ");

        indice = findCarsById(pArrayListCar,auxId);

        if(indice != -1)
        {
            auxCar = ll_get(pArrayListCar,indice);

            if(auxCar != NULL)
            {
                printf("\n\n");
                printf("ID      MARCA MODELO   PRECIO\n");

                mostrarCar(auxCar);

                getCharTwoOptions(&confirma,"Auto a modificar? (s/n)\n","Ingrese s o n:",'s','n');

                if(confirma == 's')
                {
                    switch(submenuModificar(pArrayListCar))
                    {
                    case 'a':
                        getString(bufferMarca,sizeof(bufferMarca),"\nIngrese nuevo marca: ","ReIngrese marca: ");
                        if(!car_setMarca(auxCar,bufferMarca))
                        {
                            todoOk = 0;
                        }
                        break;

                    case 'b':
                        getInt(&bufferModelo,"Ingrese modelo: ","ReIngrese modelo: ");
                        if(!car_setModelo(auxCar,bufferModelo))
                        {
                            todoOk = 0;
                        }
                        break;

                    case 'c':
                        getFloat(&bufferPrecio,"Ingrese nuevo precio: ","ReIngrese precio: ");
                        if(!car_setPrecio(auxCar,bufferPrecio))
                        {
                            todoOk = 0;
                        }
                        break;

                    default:
                        printf("Ingrese opcion valida...\n");
                        break;
                    }
                }
                else
                {
                    todoOk = 1;
                }
            }

        }
    }

    return todoOk;
}


int controller_removeCar(LinkedList* pArrayListCar)
{
    int todoOk = -1;
    int auxId;
    int indice;
    char confirma;
    eAutos* auxCar;

    if(pArrayListCar != NULL)
    {
        system("cls");
        printf("   *** BAJA AUTO ***\n\n");

        controller_ListCar(pArrayListCar);

        getInt(&auxId,"Ingrese el id a dar de baja: ","ReIngrese id: ");

        indice = findCarsById(pArrayListCar,auxId);

        if(indice != -1)
        {
            auxCar = ll_get(pArrayListCar,indice);

            printf("\n\n");
            printf("ID      MARCA MODELO   PRECIO\n");
            mostrarCar(auxCar);

            getCharTwoOptions(&confirma,"Auto a dar de baja? (s/n)\n","Ingrese s o n:",'s','n');

            if(confirma=='s')
            {
                ll_remove(pArrayListCar,indice);
                todoOk = 0;
            }
            else
            {
                todoOk = 1;
            }
        }
    }

    return todoOk;
}


int controller_ListCar(LinkedList* pArrayListCar)
{
    int todoOk = -1;
    int tam;
    int flag = 0;
    eAutos* auxCar;

    if(pArrayListCar != NULL)
    {
        system("cls");
        printf("    *** LISTA DE AUTOS ***\n\n");
        printf(" ID  MARCA  MODELO  PRECIO\n");

        tam = ll_len(pArrayListCar);

        for(int i=0; i<tam; i++)
        {
            auxCar = (eAutos*) ll_get(pArrayListCar,i);

            if(auxCar != NULL)
            {
                mostrarCar(auxCar);
                flag = 1;
            }
        }

        if(!flag)
        {
            printf(" * NO HAY AUTOS * \n\n");
        }

        todoOk = 0;
    }

    return todoOk;
}


int controller_sortCar(LinkedList* pArrayListCar)
{
    int todoOk = -1;
    int orden;

    if(pArrayListCar != NULL)
    {
        getInt(&orden,"\nIngrese 1(ascendente) o 0(descendente):","Ingrese 1 o 0:");

        while(orden !=0 && orden !=1)
        {
            getInt(&orden,"Ingrese 1 o 0:","Ingrese 1 o 0:");
        }

        switch(submenuOrdenar())
        {
        case 'a':
            ll_sort(pArrayListCar,compararXid,orden);
            break;

        case 'b':
            ll_sort(pArrayListCar,compararXMarca,orden);
            break;

        case 'c':
            ll_sort(pArrayListCar,compararXModelo,orden);
            break;

        case 'd':
            ll_sort(pArrayListCar,compararXPrecio,orden);
            break;

        default:
            printf("Ingrese opcion valida...\n");
            break;
        }

        todoOk = 0;
    }

    return todoOk;
}


int controller_saveAsText(char* path, LinkedList* pArrayListCar)
{
    int todoOk = -1;
    int tam;
    FILE* pFile;
    eAutos* auxCar;

    int auxId;
    char auxMarca[128];
    int auxModelo;
    int auxPrecio;

    if(path != NULL && pArrayListCar != NULL)
    {
        pFile = fopen(path,"w");

        if(pFile != NULL)
        {
            tam = ll_len(pArrayListCar);
            fprintf(pFile,"id,marca,modelo,precio\n");//encabezado

            for(int i=0;i<tam;i++)
            {
                auxCar = ll_get(pArrayListCar,i);

                if(auxCar != NULL)
                {
                    if(!car_getId(auxCar,&auxId)&&
                       !car_getMarca(auxCar,auxMarca)&&
                       !car_getModelo(auxCar,&auxModelo)&&
                       !car_getPrecio(auxCar,&auxPrecio))
                    {
                        fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxMarca,auxModelo,auxPrecio);
                        todoOk = 0;
                    }
                }
            }

            fclose(pFile);
        }
    }

    return todoOk;
}
