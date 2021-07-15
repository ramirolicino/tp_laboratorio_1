#include "LinkedList.h"

#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

typedef struct
{
    int id;
    char marca[128];
    int modelo;
    int precio;

}Autos;

#endif // AUTOS_H_INCLUDED

Autos* car_new();
Autos* car_newParams(int id,char*marca,int modelo,int precio);
void car_delete(Autos* lista);
int car_setId(Autos* lista,int id);
int car_getId(Autos* lista,int* id);
int car_setMarca(Autos* lista,char* marca);
int car_getMarca(Autos* lista,char* marca);
int car_setModelo(Autos* lista,int modelo);
int car_getModelo(Autos* lista,int* modelo);
int car_setPrecio(Autos* lista,int precio);
int car_getPrecio(Autos* lista,int* precio);
void mostrarAuto(Autos* lista);
int findCarById(LinkedList*pArray,int id);
////////////////////////////////////////////////////////
int compararPorId(void* car1,void* car2);
int compararPorMarca(void* car1,void* car2);
int compararPorModelo(void* car1,void* car2);
int compararPorPrecio(void* car1,void* car2);
