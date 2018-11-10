#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "conio.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    char continuar;
    printf("ADVERTENCIA: Se perderan todas las modificaciones que no hayan sido guardadas\n\n");
    continuar=getChar("Para continuar presione s, de lo contrario cualquier otra tecla...\n\n");
    if(continuar!='s')
    {
        printf("Carga de archivo cancelada.\n\n");
        system("pause");
        return -1;
    }
    ll_clear(pArrayListEmployee);
    pFile = fopen(path,"r");
    if(pFile==NULL||pArrayListEmployee==NULL)
    {
        printf("Error al intentar leer el archivo...\n\nPuede que el mismo este corrupto o no exista\n\n");
        system("pause");
        return -1;
    }

    if(parser_EmployeeFromText(pFile , pArrayListEmployee)==1)
    {
        printf("Archivo leido y cargado con exito\n\n");
        system("pause");
    }

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    char continuar;
    printf("ADVERTENCIA: Se perderan todas las modificaciones que no hayan sido guardadas\n\n");
    continuar=getChar("Para continuar presione s, de lo contrario cualquier otra tecla...\n\n");
    if(continuar!='s')
    {
        printf("Carga de archivo cancelada.\n\n");
        system("pause");
        return -1;
    }
    ll_clear(pArrayListEmployee);
    pFile = fopen(path,"rb");
    if(pFile==NULL||pArrayListEmployee==NULL)
    {
        printf("Error al intentar leer el archivo...\n\nPuede que el mismo este corrupto o no exista\n\n");
        system("pause");
        return -1;
    }

    if(parser_EmployeeFromBinary(pFile , pArrayListEmployee)==1)
    {
        printf("Archivo leido y cargado con exito\n\n");
        system("pause");
    }

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
  Employee* p;
  int i, len;
  int flag=0;
  char var1[51];
  char var2[51];
  char var3[51];
  char var4[51];

  if(pArrayListEmployee==NULL)
    {
        printf("Error al leer la lista");
        return -1;
    }
  if(getStringNumeros("Ingrese ID del empleado\n\n", var1)!=1)
    {
    printf("El ID debe ser numerico");
    getch();
    return -1;
    }
  len = ll_len(pArrayListEmployee);
  for(i=0; i<len; i++)
  {
      p = ll_get(pArrayListEmployee, i);
      if(p->id==atoi(var1))
      {
          flag=1;
          break;
      }
  }
  if(flag==1)
  {
      printf("Error, ID ingresado actualmente en uso!!");
      getch();
      return -1;
  }
  if(getStringLetras("Ingrese el nombre del empleado\n\n", var2)!=1)
    {
    printf("El nombre debe estar compuesto por letras");
    getch();
    return -1;
    }
  if(getStringNumeros("Ingrese las horas trabajadas\n\n", var3)!=1)
    {
    printf("El ingreso debe ser numerico");
    getch();
    return -1;
    }
  if(getStringNumeros("Ingrese el sueldo del empleado\n\n", var4)!=1)
    {
    printf("El sueldo debe ser numerico");
    getch();
    return -1;
    }

    p=employee_newParametros(var1,var2,var3,var4);
    ll_add(pArrayListEmployee, p);
    printf("Empleado cargado con exito!!");
    getch();

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
  Employee* p;
  int i, len;
  int flag=0;
  char var1[51];
  char var2[51];
  char var3[51];
  char var4[51];

  if(pArrayListEmployee==NULL)
  {
      printf("Error al leer la lista!!");
      getch();
      return -1;
  }
  if(!getStringNumeros("Ingrese el ID del empleado a modificar\n\n", var1))
  {
      printf("El ID debe ser numerico!!");
      getch();
      fflush(stdin);
      return -1;
  }

  len = ll_len(pArrayListEmployee);
  for(i=0; i<len; i++)
  {
      p = ll_get(pArrayListEmployee, i);
      if(p->id==atoi(var1))
      {
          flag=1;
          break;
      }
  }
  if(flag==0)
  {
      printf("Error, empleado inexistente!!");
      getch();
      return -1;
  }
  printf("Se modificaran datos del empleado:\nID:\t Nombre:\n%d\t%s \n",p->id,p->nombre);
  getch();
  system("cls");

  if(getStringLetras("Ingrese el nombre del empleado\n\n", var2)!=1)
    {
    printf("El nombre debe estar compuesto por letras");
    getch();
    return -1;
    }

  if(getStringNumeros("Ingrese las horas trabajadas\n\n", var3)!=1)
    {
    printf("El ingreso debe ser numerico");
    getch();
    return -1;
    }

  if(getStringNumeros("Ingrese el sueldo del empleado\n\n", var4)!=1)
    {
    printf("El sueldo debe ser numerico");
    getch();
    return -1;
    }

    p=employee_newParametros(var1,var2,var3,var4);
    ll_set(pArrayListEmployee, atoi(var1)-1,p);
    printf("Empleado modificado con exito!!");
    getch();

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
  Employee* p;
  char aux[51];
  char respuesta;
  int len, i;
  int flag=0;

  if(pArrayListEmployee==NULL)
  {
      printf("Error al leer la lista!!");
      getch();
      return -1;
  }
  if(!getStringNumeros("Ingrese el ID del empleado que desea eliminar...\n\n", aux))
  {
      printf("El ID debe ser numerico!!");
      getch();
      fflush(stdin);
      return -1;
  }

  len = ll_len(pArrayListEmployee);
  for(i=0; i<=len; i++)
  {
      p = ll_get(pArrayListEmployee, i);
      if(p->id==atoi(aux))
      {
          flag=1;
          break;
      }
  }
  if(flag==0)
  {
      printf("Error, empleado inexistente!!");
      getch();
      return -1;
  }
  printf("Se eliminara el empleado:\nID:\t Nombre:\n%d\t%s \n\n",p->id,p->nombre);
  respuesta=getChar("Si desea continuar presione s, de lo contrario cualquier otra tecla...\n\n");
  if(respuesta=='s')
  {
      ll_remove(pArrayListEmployee,(atoi(aux)-1));
      printf("Empleado eliminado con exito");
      getch();
      return 1;
  }
  else
  {
      return 1;
  }

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len, contador=0, i;
    Employee* aux;

    if(pArrayListEmployee==NULL)
    {
        printf("Error de lectura");
        return -1;
    }
    len = ll_len(pArrayListEmployee);

    for(i=0; i<len; i++)
    {
        aux=ll_get(pArrayListEmployee, i);
        printf("%d %s %d %d\n",aux->id,aux->nombre,aux->horasTrabajadas, aux->sueldo);
        contador++;
        if(contador >=260)
             {
               system("pause");
               contador=0;
             }
    }
    system("pause");

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    int len, i;
    Employee *p;
    //char var1[10];
    //char var2[51];


    pFile = fopen(path,"w");

    if(pFile==NULL||pArrayListEmployee==NULL)
    {
        printf("Error al intentar guardar el archivo...\n\n");
        system("pause");
        return -1;
    }

   len = ll_len(pArrayListEmployee);
   for(i=0; i<len; i++)
   {
      p = ll_get(pArrayListEmployee, i);

      //sprintf(var1,"%d",p->id);
      //itoa(p->id, var1)
      //fwrite(p->id, sizeof(int), strlen(p->id), pFile);
      fwrite(p, sizeof(Employee), 1, pFile);
      //fwrite(&p->id, sizeof(int), sizeof(p->id), pFile);
      //fwrite(p->nombre, sizeof(char),sizeof(p->nombre), pFile);
      //fwrite(p->horasTrabajadas, sizeof(int),10, pFile);
      //fwrite(p->sueldo, sizeof(int), 1, pFile);


      //var2 =p->nombre;
      //fwrite(var2, sizeof(char), sizeof(var2), pFile);


   }
   fclose(pFile);
   printf("Archivo guardado con exito\n");
   system("pause");

    return 1;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    int len, i;
    Employee *p;


    pFile = fopen(path,"wb");

    if(pFile==NULL||pArrayListEmployee==NULL)
    {
        printf("Error al intentar guardar el archivo...\n\n");
        system("pause");
        return -1;
    }

   len = ll_len(pArrayListEmployee);
   for(i=0; i<len; i++)
   {
      p = ll_get(pArrayListEmployee, i);

      fwrite(p, sizeof(char), sizeof(Employee), pFile);

   }
   fclose(pFile);
   printf("Archivo guardado con exito\n");
   system("pause");

    return 1;

}


