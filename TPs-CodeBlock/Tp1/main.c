#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    int numA;
    int numB;
    int flagA = 0;
    int flagB = 0;
    int flagC = 0;
    int suma;
    int resta;
    int multiplicar;
    long long int factorialA;
    long long int factorialB;
    float division;
    char seguir = 'n';
    char salir;



    do
    {
        system("cls");

        switch(menu(numA, numB, flagA, flagB, flagC))
        {
        case '1':
            numA = getInt("Ingrese primer operando: ");
            flagA = 1;
            break;

        case '2':
            numB = getInt("Ingrese segundo operando: ");
            flagB = 1;
            break;

        case '3':
            if(flagA && flagB)
            {
                system("cls");
                printf(" * CALCULOS REALIZADOS CORRECTAMENTE * \n");
                suma = sumar(numA, numB);
                resta = restar(numA, numB);
                division = dividir(numA, numB);
                multiplicar = multiplicacion(numA, numB);
                factorialA = Factorial(numA);
                factorialB = Factorial(numB);
                flagC = 1;
            }
            else
            {
                printf(" * PRIMERO INGRESE LOS VALORES * \n");
            }
            break;

        case '4':
            if(flagC)
            {
                system("cls");
                informeResultados(numA, numB, suma, resta, division, multiplicar, factorialA, factorialB);
                flagC = 0;
            }
            else
            {
                printf(" * PRIMERO CALCULE LOS VALORES * \n");
            }
            break;

        case '5':
            printf("Desea salir? -> ");
            fflush(stdin);
            scanf("%c", &salir);
            if(salir == 's')
            {
                seguir = 's';
            }
            break;

        default:
            printf("Ingrese opcion valida... \n");
            break;

        }

        system("pause");

    }
    while(seguir == 'n');

    return 0;
}
