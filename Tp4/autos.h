#include "LinkedList.h"


#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char marca[128];
    int modelo;
    float precio;

}eAutos;

#endif // employee_H_INCLUDED


eAutos* car_new();
eAutos* car_newParametros(char* id, char* marca, char* modelo, char* precio);

void car_delete(eAutos* lista);

int mostrarCar(eAutos* car);
int findCarsById(LinkedList* pArrayCars, int id);

int car_setId(eAutos* lista,int id);
int car_getId(eAutos* lista,int* id);

int car_setMarca(eAutos* lista,char* marca);
int car_getMarca(eAutos* lista,char* marca);

int car_setModelo(eAutos* lista,int modelo);
int car_getModelo(eAutos* lista,int* modelo);

int car_setPrecio(eAutos* lista,float precio);
int car_getPrecio(eAutos* lista,float* precio);

int compararXid(void* car1,void* car2);
int compararXMarca(void* car1,void* car2);
int compararXModelo(void* car1,void* car2);
int compararXPrecio(void* car1,void* car2);



