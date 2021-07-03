#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "autos.h"
#include "parser.h"


//-1 ERROR  0 OK

int parser_CarFromText(FILE* pFile, LinkedList* pArrayListCar)
{
    eAutos* newCar;

    int todoOk = -1;
    int cant;
    char buffer[4][128];

    if(pFile != NULL && pArrayListCar != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);//encabezado

        do
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cant == 4)//4 campos
            {
                newCar = car_newParametros(buffer[0],buffer[1], buffer[2],buffer[3]);

                if(newCar != NULL)
                {
                    ll_add(pArrayListCar,newCar);
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
