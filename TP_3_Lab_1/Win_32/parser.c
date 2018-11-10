#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    char var1[50],var3[50],var2[50],var4[50];
    Employee *p;

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);//Lee titulos

    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4)
        {
            p=employee_newParametros(var1, var2, var3, var4);
            ll_add(pArrayListEmployee, p);//Aca agrego lo que lei antes
        }
        else
            {
               printf("Error de formato al leer el archivo");
               getch();
               return -1;
               break;
            }

      }while( !feof(pFile) );

    fclose(pFile);

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    char var1[50],var3[50],var2[50],var4[50];
    Employee *p;

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4)
        {
            p=employee_newParametros(var1, var2, var3, var4);
            ll_add(pArrayListEmployee, p);//Aca agrego lo que lei antes
        }
        else
            {
               printf("Error de formato al leer el archivo");
               getch();
               return -1;
               break;
            }

      }while( !feof(pFile) );

    fclose(pFile);


    return 1;
}



