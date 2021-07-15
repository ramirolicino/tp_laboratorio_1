#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"
#include "validar.h"


Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmp = employee_new();

    if(nuevoEmp != NULL)
    {
        if(
            employee_setHorasTrabajadas(nuevoEmp,atoi(horasTrabajadasStr))== -1 ||
            employee_setId(nuevoEmp,atoi(idStr))== -1 ||
            employee_setNombre(nuevoEmp,nombreStr)== -1 ||
            employee_setSueldo(nuevoEmp,atoi(sueldoStr))== -1
        )
        {
            employee_delete(nuevoEmp);
        }
    }

    return nuevoEmp;
}

void employee_delete(Employee* lista)
{
    if(lista != NULL)
    {
        free(lista);
        lista = NULL;
    }
}

int mostrarEmpleado(Employee* empleado)
{
    int todoOk = -1;
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    if(empleado != NULL)
    {
        if(
            !employee_getId(empleado,&auxId) &&
            !employee_getNombre(empleado,auxNombre) &&
            !employee_getHorasTrabajadas(empleado,&auxHoras) &&
            !employee_getSueldo(empleado,&auxSueldo)
        )//todo ok
        {
            printf("%03d %10s  %-3d   %d\n",auxId,auxNombre,auxHoras,auxSueldo);
            todoOk = 0;
        }
    }

    return todoOk;
}

int findEmployeeById(LinkedList* pArrayEmpleados,int id)
{
    int todoOk = -1;
    int tam;
    int auxId;
    Employee* auxEmp;

    if(pArrayEmpleados != NULL)
    {
        tam = ll_len(pArrayEmpleados);

        for(int i=0; i<tam; i++)
        {
            auxEmp = ll_get(pArrayEmpleados,i);
            employee_getId(auxEmp,&auxId);

            if(auxEmp != NULL && auxId == id)
            {
                todoOk = i;
                break;
            }
        }
    }

    return todoOk;
}

int employee_setId(Employee* lista,int id)
{
    int todoOk = -1;

    if(lista != NULL && id >= 0)
    {
        lista->id = id;
        todoOk = 0;
    }

    return todoOk;
}

int employee_getId(Employee* lista,int* id)
{
    int todoOk = -1;

    if(lista != NULL && id != NULL)
    {
        *id = lista->id;
        todoOk = 0;
    }

    return todoOk;
}

int employee_setNombre(Employee* lista,char* nombre)
{
    int todoOk = -1;

    if(lista != NULL && nombre != NULL)
    {
        strcpy(lista->nombre,nombre);
        todoOk = 0;
    }

    return todoOk;
}

int employee_getNombre(Employee* lista,char* nombre)
{
    int todoOk = -1;

    if(lista != NULL && nombre != NULL)
    {
        strcpy(nombre,lista->nombre);
        todoOk = 0;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* lista,int horasTrabajadas)
{
    int todoOk = -1;

    if(lista != NULL && horasTrabajadas >= 0)
    {
        lista->horasTrabajadas = horasTrabajadas;
        todoOk = 0;
    }

    return todoOk;
}

int employee_getHorasTrabajadas(Employee* lista,int* horasTrabajadas)
{
    int todoOk = -1;

    if(lista != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = lista->horasTrabajadas;
        todoOk = 0;
    }

    return todoOk;
}

int employee_setSueldo(Employee* lista,int sueldo)
{
    int todoOk = -1;

    if(lista != NULL && sueldo >= 0)
    {
        lista->sueldo = sueldo;
        todoOk = 0;
    }

    return todoOk;
}

int employee_getSueldo(Employee* lista,int* sueldo)
{
    int todoOk = -1;

    if(lista != NULL && sueldo != NULL)
    {
        *sueldo = lista->sueldo;
        todoOk = 0;
    }

    return todoOk;
}

int compararXid(void* emp1,void* emp2)
{
    int todoOk;
    Employee* a = (Employee*) emp1;
    Employee* b = (Employee*) emp2;
    int auxIdA;
    int auxIdB;

    employee_getId(a,&auxIdA);
    employee_getId(b,&auxIdB);

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

int compararXNombre(void* emp1,void* emp2)
{
    int todoOk;
    Employee* a = (Employee*) emp1;
    Employee* b = (Employee*) emp2;
    char bufferA[128];
    char bufferB[128];

    employee_getNombre(a,bufferA);
    employee_getNombre(b,bufferB);

    todoOk = stricmp(bufferA,bufferB);

    return todoOk;
}

int compararXHs(void* emp1,void* emp2)
{
    int todoOk;
    Employee* a = (Employee*) emp1;
    Employee* b = (Employee*) emp2;
    int auxHorasA;
    int auxHorasB;

    employee_getHorasTrabajadas(a,&auxHorasA);
    employee_getHorasTrabajadas(b,&auxHorasB);

    if(auxHorasA > auxHorasB)
    {
        todoOk = 1;
    }
    else if(auxHorasA == auxHorasB)
    {
        todoOk = 0;
    }
    else
    {
        todoOk = -1;
    }

    return todoOk;
}

int compararXSueldo(void* emp1,void* emp2)
{
    int todoOk;
    Employee* a = (Employee*) emp1;
    Employee* b = (Employee*) emp2;
    int auxHorasA;
    int auxHorasB;

    employee_getSueldo(a,&auxHorasA);
    employee_getSueldo(b,&auxHorasB);

    if(auxHorasA > auxHorasB)
    {
        todoOk = 1;
    }
    else if(auxHorasA == auxHorasB)
    {
        todoOk = 0;
    }
    else
    {
        todoOk = -1;
    }

    return todoOk;
}

