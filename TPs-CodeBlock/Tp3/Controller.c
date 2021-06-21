#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
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
            if(!parser_EmployeeFromText(pFile,pArrayListEmployee))
            {
                todoOk = 0;
            }

            fclose(pFile);
        }
    }

    return todoOk;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"rb");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                todoOk = 0;
            }

            fclose(pFile);
        }
    }

    return todoOk;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int auxId;
    int auxHoras;
    int auxSueldo;
    char auxNombre[128];
    Employee* newEmployee = NULL;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("   *** ALTA EMPLEADO **\n\n");

        newEmployee = employee_new();

        if(newEmployee != NULL)
        {
            getString(auxNombre,sizeof(auxNombre),"Ingrese nombre:","ReIngrese nombre:");
            getInt(&auxHoras,"Ingrese la cantidad de horas trabajadas:","ReIngrese cantidad de horas:");
            getInt(&auxSueldo,"Ingrese sueldo:","ReIngrese sueldo:");
            obtenerId(&auxId);
            actualizarId(auxId);

            if(!employee_setId(newEmployee,auxId)&&
                    !employee_setNombre(newEmployee,auxNombre)&&
                    !employee_setHorasTrabajadas(newEmployee,auxHoras)&&
                    !employee_setSueldo(newEmployee,auxSueldo))
            {
                ll_add(pArrayListEmployee,newEmployee);
                todoOk = 0;
            }
        }
    }

    return todoOk;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int bufferInt;// hs , sueldo
    int auxId;
    int indice;
    char bufferNombre[128];
    char confirma;
    Employee* auxEmp;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("   *** MODIFICACIONES ***\n\n");

        controller_ListEmployee(pArrayListEmployee);

        getInt(&auxId,"Ingrese id a modificar: ","ReIngrese id: ");

        indice = findEmployeeById(pArrayListEmployee,auxId);

        if(indice != -1)
        {
            auxEmp = ll_get(pArrayListEmployee,indice);

            if(auxEmp != NULL)
            {
                printf("\n\n");
                printf("ID      NOMBRE HORAS   SUELDO\n");

                mostrarEmpleado(auxEmp);

                getCharTwoOptions(&confirma,"Empleado a modificar? (s/n)\n","Ingrese s o n:",'s','n');

                if(confirma == 's')
                {
                    switch(submenuModificar(pArrayListEmployee))
                    {
                    case 'a':
                        getString(bufferNombre,sizeof(bufferNombre),"\nIngrese nuevo nombre: ","ReIngrese nombre: ");
                        if(!employee_setNombre(auxEmp,bufferNombre))
                        {
                            todoOk = 0;
                        }
                        break;

                    case 'b':
                        getInt(&bufferInt,"Ingrese cantidad de horas trabajadas: ","ReIngrese Hs: ");
                        if(!employee_setHorasTrabajadas(auxEmp,bufferInt))
                        {
                            todoOk = 0;
                        }
                        break;

                    case 'c':
                        getInt(&bufferInt,"Ingrese nuevo sueldo: ","ReIngrese sueldo: ");
                        if(!employee_setSueldo(auxEmp,bufferInt))
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


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int auxId;
    int indice;
    char confirma;
    Employee* auxE;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("   *** BAJA EMPLEADO ***\n\n");

        controller_ListEmployee(pArrayListEmployee);

        getInt(&auxId,"Ingrese el id a dar de baja: ","ReIngrese id: ");

        indice = findEmployeeById(pArrayListEmployee,auxId);

        if(indice != -1)
        {
            auxE = ll_get(pArrayListEmployee,indice);

            printf("\n\n");
            printf("ID      NOMBRE HORAS   SUELDO\n");
            mostrarEmpleado(auxE);

            getCharTwoOptions(&confirma,"Empleado a dar de baja? (s/n)\n","Ingrese s o n:",'s','n');

            if(confirma=='s')
            {
                ll_remove(pArrayListEmployee,indice);
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


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int tam;
    int flag = 0;
    Employee* auxEmp;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("    *** LISTA DE EMPLEADOS ***\n\n");
        printf(" ID  NOMBRE  HORAS  SUELDO\n");

        tam = ll_len(pArrayListEmployee);

        for(int i=0; i<tam; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee,i);

            if(auxEmp != NULL)
            {
                mostrarEmpleado(auxEmp);
                flag = 1;
            }
        }

        if(!flag)
        {
            printf(" * NO HAY EMPLEADOS * \n\n");
        }

        todoOk = 0;
    }

    return todoOk;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int orden;

    if(pArrayListEmployee != NULL)
    {
        getInt(&orden,"\nIngrese 1(ascendente) o 0(descendente):","Ingrese 1 o 0:");

        while(orden !=0 && orden !=1)
        {
            getInt(&orden,"Ingrese 1 o 0:","Ingrese 1 o 0:");
        }

        switch(submenuOrdenar())
        {
        case 'a':
            ll_sort(pArrayListEmployee,compararXid,orden);
            break;

        case 'b':
            ll_sort(pArrayListEmployee,compararXNombre,orden);
            break;

        case 'c':
            ll_sort(pArrayListEmployee,compararXHs,orden);
            break;

        case 'd':
            ll_sort(pArrayListEmployee,compararXSueldo,orden);
            break;

        default:
            printf("Ingrese opcion valida...\n");
            break;
        }

        todoOk = 0;
    }

    return todoOk;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int tam;
    FILE* pFile;
    Employee* auxE;

    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"w");

        if(pFile != NULL)
        {
            tam = ll_len(pArrayListEmployee);
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");//encabezado

            for(int i=0;i<tam;i++)
            {
                auxE = ll_get(pArrayListEmployee,i);

                if(auxE != NULL)
                {
                    if(!employee_getId(auxE,&auxId)&&
                       !employee_getNombre(auxE,auxNombre)&&
                       !employee_getHorasTrabajadas(auxE,&auxHoras)&&
                       !employee_getSueldo(auxE,&auxSueldo))
                    {
                        fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
                        todoOk = 0;
                    }
                }
            }

            fclose(pFile);
        }
    }

    return todoOk;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int tam;
    FILE* pFile;
    Employee* auxE;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"wb");

        if(pFile != NULL)
        {
            tam = ll_len(pArrayListEmployee);
            for(int i=0;i<tam;i++)
            {
                auxE = ll_get(pArrayListEmployee,i);
                if(auxE != NULL)
                {
                    fwrite(auxE,sizeof(Employee),1,pFile);
                    todoOk = 0;
                }
            }

            fclose(pFile);
        }
    }

    return todoOk;
}

