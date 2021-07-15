#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"



/** FUNCIONES **/

int menu()
{
    int option;

    system("cls");

    printf("  *** EMPLOYEE MANAGEMENT *** \n\n");

    printf("1. Add employee \n\n");
    printf("2. Modify employee \n\n");
    printf("3. Remove employee \n\n");
    printf("4. Reports: \n");
    printf("   * Show employee \n");
    printf("   * Total and average wages \n\n");
    printf("5. Exit \n\n");

    printf("Enter option-> ");
    scanf("%d", &option);

    return option;
}

int subMenuModify()
{
    int option;


    printf("1. Modify name \n");
    printf("2. Modify lastName \n");
    printf("3. Modify salary \n");
    printf("4. Modify sector \n");
    printf("5. EXIT \n\n");

    printf("Enter option-> ");
    scanf("%d", &option);

    return option;
}
