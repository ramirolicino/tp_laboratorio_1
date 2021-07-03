#include <stdio.h>
#include <stdlib.h>
#include "menu.h"



/** FUNCIONES **/

int menu()
{
    int opcion;

    system("cls");

    printf("  *** MENU *** \n\n");

    printf("1.Cargar los datos de los autos desde el archivo data.csv (modo texto)\n\n");
    printf("3.Alta de auto\n");
    printf("4.Modificar datos de auto\n");
    printf("5.Baja de auto\n");
    printf("6.Listar autos\n");
    printf("7.Ordenar autos\n\n");
    printf("8.Guardar los datos de los autos en el\n  archivo data.csv (modo texto)\n\n");
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

    printf("a.Modificar marca\n");
    printf("b.Modificar modelo\n");
    printf("c.Modificar precio\n\n");

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
    printf("b.Ordenar por marca\n");
    printf("c.Ordenar por modelo\n");
    printf("d.Ordenar por precio\n\n");

    printf("Ingrese opcion-> ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}
