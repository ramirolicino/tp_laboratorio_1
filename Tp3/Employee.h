#include "LinkedList.h"


#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

#endif // employee_H_INCLUDED


Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

void employee_delete(Employee* lista);

int mostrarEmpleado(Employee* empleado);
int findEmployeeById(LinkedList* pArrayEmpleados,int id);

int employee_setId(Employee* lista,int id);
int employee_getId(Employee* lista,int* id);

int employee_setNombre(Employee* lista,char* nombre);
int employee_getNombre(Employee* lista,char* nombre);

int employee_setHorasTrabajadas(Employee* lista,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* lista,int* horasTrabajadas);

int employee_setSueldo(Employee* lista,int sueldo);
int employee_getSueldo(Employee* lista,int* sueldo);

int compararXid(void* emp1,void* emp2);
int compararXNombre(void* emp1,void* emp2);
int compararXHs(void* emp1,void* emp2);
int compararXSueldo(void* emp1,void* emp2);



