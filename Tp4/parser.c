#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "autos.h"

int parserAutoFromTxt(FILE*pFile,LinkedList* pArrayAutos)
{
    int retorno = -1;
    int cant;
    char buffer[4][128];
    Autos* newCar = NULL;

    if(pFile != NULL && pArrayAutos != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);//encabezado

        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            if(cant == 4)
            {
                newCar = car_newParams(atoi(buffer[0]),buffer[1],atoi(buffer[2]),atoi(buffer[3]));
                if(newCar != NULL)
                {
                    ll_add(pArrayAutos,newCar);
                    retorno = 0;
                }
            }
            else
            {
                break;
            }
        }
    }

    return retorno;
}
