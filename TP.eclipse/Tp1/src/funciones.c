/*
 * funciones.c
 *
 *  Created on: 14 abr. 2021
 *      Author: Rama
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

//***********************************************//

char menu(int numA, int numB, int flagA, int flagB, int flagC)
{
    char opcion;

    printf("      *** CALCULADORA *** \n\n");

    //Punto 1
    if(flagA)
    {
        printf("1. Ingresar primer operando (A = %d) \n\n", numA);
    }
    else
    {
        printf("1. Ingresar primer operando (A = X) \n\n");
    }

    //Punto 2
    if(flagB)
    {
        printf("1. Ingresar segundo operando (B = %d) \n\n", numB);
    }
    else
    {
        printf("1. Ingresar segundo operando (B = Y) \n\n");
    }

    //Punto 3
    printf("3. Calcular todas las operaciones: \n");

    if(flagC)
    {
        printf("   A- Calcular la suma (%d + %d)\n",numA,numB);
        printf("   B- Calcular la resta (%d - %d)\n",numA,numB);
        printf("   C- Calcular la division (%d / %d)\n",numA,numB);
        printf("   D- Calcular la multiplicacion (%d * %d)\n",numA,numB);
        printf("   E- Calcular el factorial (%d)\n\n",numA);
    }
    else
    {
        printf("   A- Calcular la suma (A + B)\n");
        printf("   B- Calcular la resta (A - B)\n");
        printf("   C- Calcular la division (A / B)\n");
        printf("   D- Calcular la multiplicacion (A * B)\n");
        printf("   E- Calcular el factorial (A!)\n\n");
    }

    //Punto 4
    printf("4. Informar resultados: \n\n");

    //Punto 5
    printf("5. Salir \n\n");

    printf("Ingrese opcion -> ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

int getInt(char mensaje[])
{
    int numero;

    puts(mensaje);
    scanf("%d",&numero);

    return numero;
}

void informeResultados(int numA, int numB, int suma,int resta,float division,int multiplicacion,long long int factorialA, long long int factorialB)
{
    printf("   *** RESULTADOS *** \n\n");

    //SUMA
    printf("Suma: %d + %d = %d \n\n", numA, numB, suma);

    //RESTA
    printf("Resta: %d - %d = %d \n\n", numA, numB, resta);

    //DIVICION
    if(numB == 0)
    {
        printf("Division: No es posible dividir por cero. \n\n");
    }
    else
    {
        printf("Division: %d / %d = %.2f \n\n", numA, numB, division);
    }

    //MULTIPLICACION
    printf("Multiplicacion: %d * %d = %d \n\n", numA, numB, multiplicacion);

    //FACTORIAL
    printf("Factorial-> A: %d = %I64d \n", numA, factorialA);
    printf("            B: %d = %I64d \n\n", numB, factorialB);
}



//****************  OPERACIONES  ****************//

int sumar(int numA, int numB)
{
    int suma;

    suma = numA+numB;

    return suma;
}

//***********************************************//

int restar(int numA, int numB)
{
    int resta;

    resta = numA-numB;

    return resta;
}

//***********************************************//

float dividir(int numA, int numB)
{
    float division;

    if(numB==0)
    {
        division = 0;
    }
    else
    {
        division = (float) numA/numB;
    }
    return division;
}

//***********************************************//

int multiplicacion(int numA, int numB)
{
    int multiplicacion;

    multiplicacion = numA*numB;

    return multiplicacion;
}

//***********************************************//

long long int Factorial(int numero)
{
    long long int factorial=0;

    if(numero >= 0)
    {
        if(numero == 0)
        {
            factorial = 1;
        }
        else
        {
            factorial = numero * Factorial(numero-1);
        }
    }

    return factorial;
}
