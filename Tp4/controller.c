#include <stdlib.h>
#include <stdio.h>
#include "controller.h"
#include "parser.h"
#include "autos.h"
#include "validar.h"
#include "menu.h"



static int obtenerId(int* id)
{
    int retorno = -1;
    FILE* f;

    if(id!=NULL)
    {
        *id = 51;

        f = fopen("proxId.bin","rb");
        if(f != NULL)
        {
            fread(id,sizeof(int),1,f);
            retorno = 0;

            fclose(f);
        }
    }

    return retorno;
}

/** \brief actualiza el id y carga lo que sera el proximo id en un archivo binario
 *
 * \param id int Id actual para saber cual sera el proximo
 * \return int 0 si salio todo bien y sino -1
 *
 */
static int actualizarId(int id)
{
    int retorno = -1;
    FILE* f;

    id++;

    f = fopen("proxId.bin","wb");
    if(f != NULL)
    {
        fwrite(&id,sizeof(int),1,f);
        retorno = 0;
        fclose(f);
    }

    return retorno;
}

int controller_loadFromTxt(LinkedList*pArrayAutos,char*path)
{
    int retorno = -1;
    FILE* f;

    if(pArrayAutos != NULL)
    {
        f = fopen(path,"r");
        if(f != NULL)
        {
            if(!parserAutoFromTxt(f,pArrayAutos))
            {
                retorno = 0;
            }

            fclose(f);
        }
    }

    return retorno;
}


int controller_list(LinkedList* pArrayAutos)
{
    int retorno = -1;
    int tam;
    Autos* auxCar;

    if(pArrayAutos != NULL)
    {
        tam = ll_len(pArrayAutos);
        system("cls");
        printf("    *** LISTA AUTOS ***\n\n");
        printf(" ID    MARCA MODELO PRECIO\n");

        for(int i=0; i<tam; i++)
        {
            auxCar = ll_get(pArrayAutos,i);
            mostrarAuto(auxCar);
        }

        retorno = 0;
    }

    return retorno;
}


int controller_add(LinkedList*pArrayAutos)
{
    int retorno = -1;
    int auxId;
    char auxMarca[25];
    int auxModelo;
    int auxPrecio;
    Autos* newCar;

    if(pArrayAutos != NULL)
    {
        system("cls");
        printf("   *** ALTA AUTO ***\n\n");

        newCar = car_new();
        if(newCar != NULL)
        {
            obtenerId(&auxId);
            getString(auxMarca,sizeof(auxMarca),"Ingrese marca:","ReIngrese marca:");
            getInt(&auxModelo, "Ingrese modelo:", "ReIngrese modelo:");
            getInt(&auxPrecio, "Ingrese precio:", "ReIngrese precio:");
            if(
                !car_setId(newCar,auxId) &&
                !car_setMarca(newCar,auxMarca) &&
                !car_setModelo(newCar,auxModelo) &&
                !car_setPrecio(newCar,auxPrecio)
            )
            {
                ll_add(pArrayAutos,newCar);
                actualizarId(auxId);
                retorno = 0;
            }
        }
    }

    return retorno;
}

int controller_edit(LinkedList*pArrayAutos)
{
    int retorno = -1;
    int indice;
    int auxId;
    char auxMarca[128];
    int auxModelo;
    int auxPrecio;
    Autos* auxCar;

    if(pArrayAutos != NULL)
    {
        system("cls");
        printf("   *** MODIFICAR AUTO ***\n\n");
        controller_list(pArrayAutos);
        printf("************************************************\n");

        getInt(&auxId,"Ingrese id a eliminar:","ReIngrese id:");
        indice = findCarById(pArrayAutos,auxId);

        if(indice != -1)
        {
            auxCar = ll_get(pArrayAutos,indice);

            switch(submenuModificar())
            {
            case 'a':
                getString(auxMarca,sizeof(auxMarca),"\nIngrese nueva marca:","ReIngrese marca:");
                if(!car_setMarca(auxCar,auxMarca))
                {
                    retorno = 0;
                }
                break;

            case 'b':
                getInt(&auxModelo,"\nIngrese nuevo modelo:","ReIngrese modelo:");
                if(!car_setModelo(auxCar,auxModelo))
                {
                    retorno = 0;
                }
                break;

            case 'c':
                getInt(&auxPrecio,"\nIngrese nuevo precio:","ReIngrese precio:");
                if(!car_setPrecio(auxCar,auxPrecio))
                {
                    retorno = 0;
                }
                break;

            case 'd'://salir
                break;

            default:
                printf("Ingerse opcion valida...\n\n");
                break;
            }
        }
    }

    return retorno;
}

int controller_remove(LinkedList*pArrayAutos)
{
    int retorno = -1;
    int auxId;
    int indice;
    Autos* auxCar;

    if(pArrayAutos != NULL)
    {
        system("cls");
        printf("   *** BAJA AUTO ***\n\n");
        controller_list(pArrayAutos);
        printf("************************************************\n");

        getInt(&auxId,"Ingrese id a eliminar:","ReIngrese id:");
        indice = findCarById(pArrayAutos,auxId);

        if(indice != -1)
        {
            auxCar = ll_pop(pArrayAutos,indice);

            if(auxCar != NULL)
            {
                mostrarAuto(auxCar);
                printf(" * AUTO DE BAJA *\n\n");
                retorno = 0;
            }
        }
    }

    return retorno;
}

int controller_sort(LinkedList*pArrayAutos)
{
    int retorno = -1;
    int orden;

    if(pArrayAutos != NULL)
    {
        getInt(&orden,"\nIngrese ascendente (1)\n o descendente (0)?","ReIngrese 0 o 1:");
        while(orden!=1&&orden!=0)
        {
            getInt(&orden,"\nIngrese 0 o 1:","ReIngrese 0 o 1:");
        }

        switch(submenuOrdenar())
        {
        case 'a':
            if(!ll_sort(pArrayAutos,compararPorId,orden))
            {
                retorno = 0;
            }
            break;

        case 'b':
            if(!ll_sort(pArrayAutos,compararPorMarca,orden))
            {
                retorno = 0;
            }
            break;

        case 'c':
            if(!ll_sort(pArrayAutos,compararPorModelo,orden))
            {
                retorno = 0;
            }
            break;

        case 'd':
            if(!ll_sort(pArrayAutos,compararPorPrecio,orden))
            {
                retorno = 0;
            }
            break;

        default:
            printf("Ingrese opcion valida...\n\n");
            break;
        }
    }

    return retorno;
}


int controller_insertCar(LinkedList*pArrayAutos)
{
    int retorno = -1;
    int tam;
    int auxIndice;
    int auxId;
    char auxMarca[25];
    int auxModelo;
    int auxPrecio;
    Autos* newCar = NULL;

    if(pArrayAutos != NULL)
    {
        getInt(&auxIndice,"En que lugar desea insertar el auto?","RIngrese indice:");

        tam = ll_len(pArrayAutos);
        if(auxIndice > 0 && auxIndice <= tam)
        {
            newCar = car_new();
            if(newCar != NULL)
            {
                obtenerId(&auxId);
                getString(auxMarca,sizeof(auxMarca),"Ingrese marca:","ReIngrese marca:");
                getInt(&auxModelo, "Ingrese modelo:", "ReIngrese modelo:");
                getInt(&auxPrecio, "Ingrese precio:", "ReIngrese precio:");

                if(
                    !car_setId(newCar,auxId) &&
                    !car_setMarca(newCar,auxMarca) &&
                    !car_setModelo(newCar,auxModelo) &&
                    !car_setPrecio(newCar,auxPrecio)
                )
                {
                    ll_push(pArrayAutos,auxIndice,newCar);
                    actualizarId(auxId);
                    if(ll_indexOf(pArrayAutos,newCar) == auxIndice)
                    {
                        retorno = 0;
                    }
                }
            }
        }
    }

    return retorno;
}

int controller_clearList(LinkedList*pArrayAutos)
{
    int retorno = -1;
    char confirma;

    if(pArrayAutos!=NULL)
    {
        printf(" * SE BORRARAN TODOS LOS ELEMENTOS *\n");
        getCharTwoOptions(&confirma,"Desea vaciar la lista? (s/n)","ReIngrese s / n:",'s','n');
        if(confirma == 's')
        {
            if(!ll_clear(pArrayAutos))
            {
                retorno = 0;
            }
        }
        else
        {
            retorno = 1;
        }
    }


    return retorno;
}

int controller_saveAsTxt(LinkedList*pArrayAutos,char*path)
{
    int retorno = -1;
    int tam;
    int auxId;
    char auxMarca[25];
    int auxModelo;
    int auxPrecio;
    Autos* auxCar;
    FILE* pFile;

    if(pArrayAutos != NULL && path != NULL)
    {
        pFile = fopen(path,"w");

        if(pFile != NULL)
        {
            tam = ll_len(pArrayAutos);
            fprintf(pFile,"id,marca,modelo,precio\n");

            for(int i=0; i<tam; i++)
            {
                auxCar = ll_get(pArrayAutos,i);

                if(
                    !car_getId(auxCar,&auxId) &&
                    !car_getMarca(auxCar,auxMarca) &&
                    !car_getModelo(auxCar,&auxModelo) &&
                    !car_getPrecio(auxCar,&auxPrecio)
                )
                {
                    fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxMarca,auxModelo,auxPrecio);
                    retorno = 0;
                }
            }

            fclose(pFile);
        }
    }

    return retorno;
}

