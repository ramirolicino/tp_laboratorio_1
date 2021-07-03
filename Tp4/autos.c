#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "autos.h"
#include "validar.h"


eAutos* car_new()
{
    return (eAutos*) malloc(sizeof(eAutos));
}

eAutos* car_newParametros(char* id, char* marca, char* modelo, char* precio)
{
    eAutos* nuevoCar = car_new();

    if(nuevoCar != NULL)
    {
        if(
            car_setId(nuevoCar, atoi(id)) == -1 ||
            car_setMarca(nuevoCar,marca) == -1 ||
            car_setModelo(nuevoCar, atoi(modelo)) == -1 ||
            car_setPrecio(nuevoCar, atof(precio)) == -1
        )
        {
            car_delete(nuevoCar);
        }
    }

    return nuevoCar;
}

void car_delete(eAutos* lista)
{
    if(lista != NULL)
    {
        free(lista);
        lista = NULL;
    }
}

int mostrarCar(eAutos* car)
{
    int todoOk = -1;
    int auxId;
    int auxModelo;
    float auxPrecio;
    char auxMarca[128];

    if(car != NULL)
    {
        if(
            !car_getId(car,&auxId) &&
            !car_getMarca(car,auxMarca) &&
            !car_getModelo(car,&auxModelo) &&
            !car_getPrecio(car,&auxPrecio)
        )//todo ok
        {
            printf("%03d %10s  %-4d   %.2f\n",auxId,auxMarca,auxModelo,auxPrecio);
            todoOk = 0;
        }
    }

    return todoOk;
}

int findCarsById(LinkedList* pArrayCars, int id)
{
    int todoOk = -1;
    int tam;
    int auxId;
    eAutos* auxCar;

    if(pArrayCars != NULL)
    {
        tam = ll_len(pArrayCars);

        for(int i=0; i<tam; i++)
        {
            auxCar = ll_get(pArrayCars,i);
            car_getId(auxCar,&auxId);

            if(auxCar != NULL && auxId == id)
            {
                todoOk = i;
                break;
            }
        }
    }

    return todoOk;
}


int car_setId(eAutos* lista,int id)
{
    int todoOk = -1;

    if(lista != NULL && id >= 0)
    {
        lista->id = id;
        todoOk = 0;
    }

    return todoOk;
}

int car_getId(eAutos* lista,int* id)
{
    int todoOk = -1;

    if(lista != NULL && id != NULL)
    {
        *id = lista->id;
        todoOk = 0;
    }

    return todoOk;
}


int car_setMarca(eAutos* lista,char* marca)
{
    int todoOk = -1;

    if(lista != NULL && marca != NULL)
    {
        strcpy(lista->marca,marca);
        todoOk = 0;
    }

    return todoOk;
}

int car_getMarca(eAutos* lista,char* marca)
{
    int todoOk = -1;

    if(lista != NULL && marca != NULL)
    {
        strcpy(marca,lista->marca);
        todoOk = 0;
    }

    return todoOk;
}


int car_setModelo(eAutos* lista,int modelo)
{
    int todoOk = -1;

    if(lista != NULL && modelo > 0)
    {
        lista->modelo = modelo;
        todoOk = 0;
    }

    return todoOk;
}

int car_getModelo(eAutos* lista,int* modelo)
{
    int todoOk = -1;

    if(lista != NULL && modelo != NULL)
    {
        *modelo = lista->modelo;
        todoOk = 0;
    }

    return todoOk;
}


int car_setPrecio(eAutos* lista,float precio)
{
    int todoOk = -1;

    if(lista != NULL && precio > 0)
    {
        lista->precio = precio;
        todoOk = 0;
    }

    return todoOk;
}

int car_getPrecio(eAutos* lista,float* precio)
{
    int todoOk = -1;

    if(lista != NULL && precio != NULL)
    {
        *precio = lista->precio;
        todoOk = 0;
    }

    return todoOk;
}



int compararXid(void* car1,void* car2)
{
    int todoOk;
    eAutos* a = (eAutos*) car1;
    eAutos* b = (eAutos*) car2;
    int auxIdA;
    int auxIdB;

    car_getId(a,&auxIdA);
    car_getId(b,&auxIdB);

    if(auxIdA > auxIdB)
    {
        todoOk = 1;
    }
    else if(auxIdA == auxIdB)
    {
        todoOk = 0;
    }
    else
    {
        todoOk = -1;
    }

    return todoOk;
}

int compararXMarca(void* car1,void* car2)
{
    int todoOk;
    eAutos* a = (eAutos*) car1;
    eAutos* b = (eAutos*) car2;
    char bufferA[128];
    char bufferB[128];

    car_getMarca(a,bufferA);
    car_getMarca(b,bufferB);

    todoOk = stricmp(bufferA,bufferB);

    return todoOk;
}

int compararXModelo(void* car1,void* car2)
{
    int todoOk;
    eAutos* a = (eAutos*) car1;
    eAutos* b = (eAutos*) car2;
    int auxModeloA;
    int auxModeloB;

    car_getModelo(a,&auxModeloA);
    car_getModelo(b,&auxModeloB);

    if(auxModeloA > auxModeloB)
    {
        todoOk = 1;
    }
    else if(auxModeloA == auxModeloB)
    {
        todoOk = 0;
    }
    else
    {
        todoOk = -1;
    }

    return todoOk;
}

int compararXPrecio(void* car1,void* car2)
{
    int todoOk;
    eAutos* a = (eAutos*) car1;
    eAutos* b = (eAutos*) car2;
    float auxPrecioA;
    float auxPrecioB;

    car_getPrecio(a,&auxPrecioA);
    car_getPrecio(b,&auxPrecioB);

    if(auxPrecioA > auxPrecioB)
    {
        todoOk = 1;
    }
    else if(auxPrecioA == auxPrecioB)
    {
        todoOk = 0;
    }
    else
    {
        todoOk = -1;
    }

    return todoOk;
}

