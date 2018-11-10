#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"



/** \brief  Reseva espacio en meomoria para una nueva persona y la inicializa
 *
 * \param
 * \return Employee*, Retorna un puntero al empleado o NULL en caso de error
 *
 */
Employee* employee_new ()
{
    Employee* this = malloc(sizeof(Employee));
    if(this == NULL)
        printf("Error de escritura");

    return this;
}


/** \brief  Inicializa un empleado recibido como parametro
 * \param Employee* this Puntero al empleado
 * \param char* idStr, id del empleado
 * \param char* sueldoStr, sueldo del empleado
 * \param char* horasTrabajadasStr, horas trabajadas por el empleado
 * \param char* nombreStr, nombre del empleado
 * \return void
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this ;
    int id, sueldo, horasTrabajadas;

    this=employee_new();
    id = atoi(idStr);
    sueldo = atoi(sueldoStr);
    horasTrabajadas = atoi(horasTrabajadasStr);

    employee_setId(this, id);
    employee_setSueldo(this, sueldo);
    employee_setHorasTrabajadas(this, horasTrabajadas);
    employee_setNombre(this, nombreStr);

    return this;
}




///////SETERS///////

int employee_setId(Employee* this, int id)
{
    if(id > 0)
        this->id = id;
        return 1;
}


int employee_setSueldo(Employee* this, int sueldo)
{
    if(sueldo > 0)
        this->sueldo = sueldo;
        return 1;
}


int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    if(horasTrabajadas > 0)
        this->horasTrabajadas = horasTrabajadas;
        return 1;
}


int employee_setNombre(Employee* this, char *nombre)
{
    if(nombre[0] != '\0')
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        return 1;

}


//////GETERS/////////


int employee_getId(Employee* this, int* id)
{
    return this->id;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    return this->sueldo;
}


int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    return this->horasTrabajadas;
}


char* employee_getNombre(Employee* this, char* nombre)
{
    return this->nombre;
}

