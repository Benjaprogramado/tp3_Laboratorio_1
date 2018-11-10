#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"



/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).  //Parser data
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado  //Aca hay que hacer los sets como vimos en la clase
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();//primer funcion llist usada.
    do{

        option=showMenu();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);//ok
                break;
            case 2:
                controller_loadFromBinary("data.cvs", listaEmpleados);//No funciona, revisar.
                break;
            case 3:
                controller_addEmployee(listaEmpleados);//ok
                break;
            case 4:
                controller_editEmployee(listaEmpleados);//ok
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);//ok
                break;
            case 7:
                break;
            case 8:
                controller_saveAsText("data.txt",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data.bin", listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}
