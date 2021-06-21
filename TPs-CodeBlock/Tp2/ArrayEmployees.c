#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"


void printEmployee(eEmployee anEmployee)
{
    printf("%4d   %10s   %10s   %.2f   %4d  \n", anEmployee.id, anEmployee.name, anEmployee.lastName, anEmployee.salary, anEmployee.sector);
}

void printEmployees(eEmployee list[], int len)
{
    int flag = 0;

    system("cls");

    if(list != NULL && len > 0)
    {
        printf("           *** LIST OF EMPLOYEES *** \n\n");
        printf("ID        NAME         LASTNAME     SALARY     SECTOR   \n\n");

        for(int i=0; i<len; i++)
        {
            if(!list[i].isEmpty)
            {
                printEmployee(list[i]);
                flag = 1;
            }
        }

        if(!flag)
        {
            printf("          * NO EMPLOYEES * \n\n");
        }
    }

    printf("\n\n");

}

int initEmployees(eEmployee list[], int len) // Inicializar emp
{
    int allOk = 0;

    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
            allOk = 1;
        }
    }

    return allOk;
}

int findEmptyEmployee(eEmployee list[], int len)
{
    int indice = -1;

    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return  indice;
}

int findEmployeeById(eEmployee list[], int len,int id) // Buscar emp
{
    int indice = -1;

    if(list != NULL && len > 0 && id > 0)
    {
        for(int i=0; i<len; i++)
        {
            if(!list[i].isEmpty && list[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int addEmployee(eEmployee list[], int len, int* pID) // Alta emp
{
    eEmployee newEmp;
    int allOk = 0;
    int indice;

    if(list != NULL && len > 0 && pID > 0)
    {
        system("cls");

        printf(" * ADD EMPLOYEE * \n\n");

        printf("Id: %d \n", *pID);

        indice = findEmptyEmployee(list, len);

        if(indice == -1)
        {
            printf(" * NO PLACE FOR OTHER EMPLOYEE * \n\n");
        }
        else
        {
            newEmp.id = *pID;

            printf("Name: ");
            fflush(stdin);
            gets(newEmp.name);

            printf("LastName: ");
            fflush(stdin);
            gets(newEmp.lastName);

            printf("Salary: ");
            scanf("%f", &newEmp.salary);

            printf("Sector: ");
            scanf("%d", &newEmp.sector);

            newEmp.isEmpty = 0;

            list[indice] = newEmp;

            (*pID)++;

            allOk = 1;
        }
    }

    return allOk;
}


int removeEmployee(eEmployee list[], int len) // Baja emp
{
    int allOk = 0;
    int indice;
    int ID;
    char confirm;

    if(list != NULL && len > 0)
    {
        system("cls");

        printf(" * REMOVE EMPLOYEE * \n\n");

        printEmployees(list, len);

        printf("\n\n");

        printf("Enter ID: ");
        scanf("%d", &ID);

        indice = findEmployeeById(list, len, ID);

        if(indice == -1)
        {
            printf(" * NO FOUND EMPLOYEE * \n\n");
        }
        else
        {
            printEmployee(list[indice]);

            printf("Do you want eliminate this employee?(Y/N) ");
            fflush(stdin);
            scanf("%c", &confirm);

            if(confirm == 'y')
            {
                list[indice].isEmpty = 1;
                allOk = 1;
            }
            else
            {
                printf(" * ACTION CANCELED * Continue...  \n\n");
            }
        }
    }

    return  allOk;
}

int modifyEmployee(eEmployee list[], int len) // Modificar emp
{
    eEmployee newName;
    eEmployee newLastName;
    eEmployee newSalary;
    eEmployee newSector;

    int allOk = 0;
    int indice;
    int ID;
    char confirm;
    char Continue = 'n';
    char exit;

    if(list != NULL && len > 0)
    {
        system("cls");

        printf(" * MODIFY EMPLOYEE * \n\n");

        printEmployees(list, len);

        printf("Enter ID: ");
        scanf("%d", &ID);

        indice = findEmployeeById(list, len, ID);

        if(indice == -1)
        {
            printf(" * NO FOUND EMPLOYEE * \n\n");
        }
        else
        {

            do
            {
                system("cls");

                printf("      * MODIFY EMPLOYEE * \n\n");

                printEmployee(list[indice]);

                printf("\n\n");

                switch(subMenuModify())
                {

                case 1:
                    printf("New Name: ");
                    fflush(stdin);
                    gets(newName.name);

                    printf("Do you want confirm  the cahnge?(Y/N) ");
                    fflush(stdin);
                    scanf("%c", &confirm);

                    if(confirm == 'y')
                    {
                        strcpy(list[indice].name, newName.name);
                        printf(" * Saved Data * \n");
                    }
                    else
                    {
                        printf(" * ACTION CANCELED * Continue...  \n\n");
                    }

                    break;

                case 2:
                    printf("New LastName: ");
                    fflush(stdin);
                    gets(newLastName.lastName);

                    printf("Do you want confirm  the cahnge?(Y/N) ");
                    fflush(stdin);
                    scanf("%c", &confirm);

                    if(confirm == 'y')
                    {
                        strcpy(list[indice].lastName, newLastName.lastName);
                        printf(" * Saved Data * \n");
                    }
                    else
                    {
                        printf(" * ACTION CANCELED * Continue...  \n\n");
                    }

                    break;

                case 3:
                    printf("New Salary: ");
                    scanf("%f", &newSalary.salary);

                    printf("Do you want confirm  the cahnge?(Y/N) ");
                    fflush(stdin);
                    scanf("%c", &confirm);

                    if(confirm == 'y')
                    {
                        list[indice].salary = newSalary.salary;
                        printf(" * Saved Data * \n");
                    }
                    else
                    {
                        printf(" * ACTION CANCELED * Continue...  \n\n");
                    }

                    break;

                case 4:
                    printf("New Sector: ");
                    scanf("%d", &newSector.sector);

                    printf("Do you want confirm  the cahnge?(Y/N) ");
                    fflush(stdin);
                    scanf("%c", &confirm);

                    if(confirm == 'y')
                    {
                        list[indice].sector = newSector.sector;
                        printf(" * Saved Data * \n");
                    }
                    else
                    {
                        printf(" * ACTION CANCELED * Continue...  \n\n");
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

                allOk = 1;

                system("pause");
            }
            while(Continue == 'n');
        }
    }

    return allOk;
}

int sortEmployees(eEmployee list[], int len)// Ordenar emp
{
    int allOk = 0;
    eEmployee auxEmp;

    if(list != NULL && len > 0)
    {
        for(int i=0; i < len; i++)
        {
            for(int j=i+1; j < len; j++)
            {
                if(strcmp(list[i].name, list[j].name) > 0 && list[i].sector > list[j].sector)
                {
                    //swap
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }

            }
        }

        allOk = 1;
    }

    return allOk;
}


int totalAndAverage(eEmployee list[], int len, int numbersEmp) //Total y promedio de salarios, cuantos emp superan el salario prom.
{
    int allOk = 0;
    float total = 0;
    float average;

    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                total+=list[i].salary;
            }
        }

        average = (float) total / numbersEmp;

        if(numbersEmp > 0)
        {
            sortEmployees(list, len);
            printEmployees(list, len);
            printf("\n\n");
            printf("Total salary: $%.2f \n", total);
            printf("Average: %.2f \n", average);
        }
        else
        {
            sortEmployees(list, len);
            printEmployees(list, len);
            printf("\n\n");
            printf("Total salary: 0 \n");
            printf("Average: 0 \n");
        }

        allOk = 1;
    }

    return allOk;
}
