#include <stdio.h>
#include <stdlib.h>
#include "menu.h"



/** FUNCIONES **/

int menu()
{
    int opcion;

    system("cls");

    printf("  *** MENU *** \n\n");

    printf("1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2.Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n\n");
    printf("3.Alta de empleado\n");
    printf("4.Modificar datos de empleado\n");
    printf("5.Baja de empleado\n");
    printf("6.Listar empleados\n");
    printf("7.Ordenar empleados\n\n");
    printf("8.Guardar los datos de los empleados en el\n  archivo data.csv (modo texto)\n");
    printf("9.Guardar los datos de los empleados en el\n  archivo data.bin (modo binario)\n\n");
    printf("10.Salir\n\n");

    printf("Ingrese opcion-> ");
    scanf("%d", &opcion);

    return opcion;
}

char submenuModificar()
{
    char opcion;

    system("cls");

    printf("  *** MENU MODIFICACIONES ***\n\n");

    printf("a.Modificar nombre\n");
    printf("b.Modificar cantidad de horas trabajadas\n");
    printf("c.Modificar sueldo\n\n");

    printf("Ingrese opcion-> ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}

char submenuOrdenar()
{
    char opcion;

    system("cls");

    printf("   *** MENU ORDEN ***\n\n");

    printf("a.Ordenar por id\n");
    printf("b.Ordenar por nombre\n");
    printf("c.Ordenar por horas trabajadas\n");
    printf("d.Ordenar por sueldos\n\n");

    printf("Ingrese opcion-> ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}
