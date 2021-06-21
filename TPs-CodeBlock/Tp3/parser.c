#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


//-1 ERROR  0 OK

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* newEmployee;

    int todoOk = -1;
    int cant;
    char buffer[4][128];

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);//encabezado

        do
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cant == 4)//4 campos
            {
                newEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

                if(newEmployee != NULL)
                {
                    ll_add(pArrayListEmployee,newEmployee);
                    todoOk = 0;
                }
            }
            else
            {
                break;
            }
        }
        while(!feof(pFile));


        }

    return todoOk;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;

    Employee* newEmployee = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fread(newEmployee,sizeof(Employee),1,pFile);//encabazado

        do
        {
            newEmployee = employee_new();

            if(newEmployee != NULL)
            {
                if(fread(newEmployee,sizeof(Employee),1,pFile))
                {
                    ll_add(pArrayListEmployee,newEmployee);
                    todoOk = 0;
                }
            }
            else
            {
                break;
            }
        }
        while(!feof(pFile));
        }

    return todoOk;
}
