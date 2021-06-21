#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"


#define TAM 5


/**
REALIZAR
1-ALTA
2-MODIFICAR
3-BAJA
4-INFORMAR-> a.Listado de emp, ordenados por apellido y sector
             b.Total y promedio de salarios, cuantos emp superan el salario prom.
**/

/** FUNCIONES **/






int main()
{
    eEmployee listEmp[TAM];
    int flag = 0;
    int nextID = 1000;
    int numberEmployees = 0;
    char Continue = 'n';
    char exit;


    if(initEmployees(listEmp, TAM))
    {
        printf(" * INICIALIZACION CORRECTA * \n\n");
    }
    else
    {
        printf(" * INICIALIZACION ERRONEA * \n\n");
    }

    do
    {
        system("cls");

        switch(menu())
        {
        case 1:
            if(addEmployee(listEmp, TAM, &nextID))
            {
                printf(" * Successfully Added * \n");
                numberEmployees++;
                flag = 1;
            }
            else
            {
                printf(" * Wrong Added * \n");
            }

            break;

        case 2:
            if(!flag)
            {
                printf(" * PRIMERO DAR DE ALTA UN EMPLEADO * \n");
            }
            else
            {
                if(modifyEmployee(listEmp, TAM))
                {
                    printf(" * Successfully Modified * \n");
                }
                else
                {
                    printf(" * Wrong Modified * \n");
                }

            }
            break;

        case 3:
            if(!flag)
            {
                printf(" * PRIMERO DAR DE ALTA UN EMPLEADO * \n");
            }
            else
            {
                if(removeEmployee(listEmp, TAM))
                {
                    printf(" * Successfully Removed * \n");
                    numberEmployees--;
                }
                else
                {
                    printf(" * Wrong Removed * \n");
                }
            }

            break;

        case 4:
            if(!flag)
            {
                printf(" * PRIMERO DAR DE ALTA UN EMPLEADO * \n");
            }
            else
            {
                if(totalAndAverage(listEmp, TAM, numberEmployees))
                {
                    printf("OK \n");
                    printf("%d \n\n", numberEmployees);
                }
                else
                {
                    printf("NOT OK \n");
                }

            }
            break;

        case 5:
            printf("EXIT?(Y/N)-> ");
            fflush(stdin);
            scanf("%c", &exit);

            if(exit == 'y')
            {
                Continue = 'y';
            }

            break;

        default:
            printf("Enter option correct...");
            break;
        }

        system("pause");

    }
    while(Continue == 'n');

    return 0;
}




