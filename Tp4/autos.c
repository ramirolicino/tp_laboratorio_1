#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"





Autos* car_new()
{
    return (Autos*) malloc(sizeof(Autos));
}

Autos* car_newParams(int id,char* marca,int modelo,int precio)
{
    Autos* newCar = car_new();

    if(newCar)
    {
        if(
            car_setId(newCar,id)== -1 ||
            car_setMarca(newCar,marca)== -1 ||
            car_setModelo(newCar,modelo)== -1 ||
            car_setPrecio(newCar,precio)==- 1
        )

        {
            car_delete(newCar);
        }
    }

    return newCar;
}

void car_delete(Autos* lista)
{
    if(lista != NULL)
    {
        free(lista);
        lista = NULL;
    }
}

void mostrarAuto(Autos* lista)
{
    int auxId;
    char auxMarca[25];
    int auxModelo;
    int auxPrecio;

    if(lista != NULL)
    {
        if(
            !car_getId(lista,&auxId) &&
            !car_getMarca(lista,auxMarca) &&
            !car_getModelo(lista,&auxModelo) &&
            !car_getPrecio(lista,&auxPrecio)
        )
        {
            printf(" %2d %10s %4d %d\n",auxId,auxMarca,auxModelo,auxPrecio);
        }
    }
}

int findCarById(LinkedList*pArray,int id)
{
    int retorno = -1;
    int tam;
    int auxId;
    Autos* auxCar;

    if(pArray != NULL && id >= 0)
    {
        tam = ll_len(pArray);
        for(int i=0; i<tam; i++)
        {
            auxCar = ll_get(pArray,i);
            car_getId(auxCar,&auxId);

            if(auxId == id)
            {
                retorno = i;
                break;
            }

        }
    }

    return retorno;
}

int car_setId(Autos* lista,int id)
{
    int retorno = -1;

    if(lista != NULL && id >= 0)
    {
        lista->id = id;
        retorno = 0;
    }

    return retorno;
}

int car_getId(Autos* lista,int* id)
{
    int retorno = -1;

    if(lista != NULL && id != NULL)
    {
        *id = lista->id;
        retorno = 0;
    }

    return retorno;
}


int car_setMarca(Autos* lista,char* marca)
{
    int retorno = -1;

    if(lista != NULL && marca != NULL)
    {
        strcpy(lista->marca, marca);
        retorno = 0;
    }

    return retorno;
}

int car_getMarca(Autos* lista,char* marca)
{
    int retorno = -1;

    if(lista != NULL && marca != NULL)
    {
        strcpy(marca,lista->marca);
        retorno = 0;
    }

    return retorno;
}


int car_setModelo(Autos* lista,int modelo)
{
    int retorno = -1;

    if(lista != NULL && modelo > 0)
    {
        lista->modelo = modelo;
        retorno = 0;
    }

    return retorno;
}

int car_getModelo(Autos* lista,int* modelo)
{
    int retorno = -1;

    if(lista != NULL && modelo != NULL)
    {
        *modelo = lista->modelo;
        retorno = 0;
    }

    return retorno;
}


int car_setPrecio(Autos* lista,int precio)
{
    int retorno = -1;

    if(lista != NULL && precio > 0)
    {
        lista->precio = precio;
        retorno = 0;
    }

    return retorno;
}

int car_getPrecio(Autos* lista,int* precio)
{
    int retorno = -1;

    if(lista != NULL && precio != NULL)
    {
        *precio = lista->precio;
        retorno = 0;
    }

    return retorno;
}

/********/

int compararPorId(void* car1,void* car2)
{
    int retorno;
    Autos* a = (Autos*) car1;
    Autos* b = (Autos*) car2;
    int auxIdA;
    int auxIdB;

    car_getId(a,&auxIdA);
    car_getId(b,&auxIdB);

    if(auxIdA>auxIdB)
    {
        retorno = 1;
    }
    else if(auxIdA==auxIdB)
    {
        retorno = 0;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}

int compararPorMarca(void* car1,void* car2)
{
    int retorno;
    Autos* a = (Autos*) car1;
    Autos* b = (Autos*) car2;
    char bufferA[128];
    char bufferB[128];

    car_getMarca(a,bufferA);
    car_getMarca(b,bufferB);

    retorno = stricmp(bufferA,bufferB);

    return retorno;
}

int compararPorModelo(void* car1,void* car2)
{
    int retorno;
    Autos* a = (Autos*) car1;//lo casteo poruqe era puntero a void
    Autos* b = (Autos*) car2;
    int auxIdA;
    int auxIdB;

    car_getModelo(a,&auxIdA);
    car_getModelo(b,&auxIdB);

    if(auxIdA>auxIdB)
    {
        retorno = 1;
    }
    else if(auxIdA==auxIdB)
    {
        retorno = 0;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}

int compararPorPrecio(void* car1,void* car2)
{
    int retorno;
    Autos* a = (Autos*) car1;//lo casteo poruqe era puntero a void
    Autos* b = (Autos*) car2;
    int auxIdA;
    int auxIdB;

    car_getPrecio(a,&auxIdA);
    car_getPrecio(b,&auxIdB);

    if(auxIdA>auxIdB)
    {
        retorno = 1;
    }
    else if(auxIdA==auxIdB)
    {
        retorno = 0;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}




