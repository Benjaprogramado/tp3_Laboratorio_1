#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/////////////////
//OBTENER DATOS//
/////////////////

int showMenu();

float getFloat (char[]);
int getInt(char mensaje[]);

char getChar(char mensaje[]);
void getString(char mensaje[],char input[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);



///////////////////////////
//OBTENER DATOS VALIDADOS//
///////////////////////////

int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);


////////////////
//VALIDACIONES//
////////////////

int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);



///////////////
//OPERACIONES//
///////////////


float suma (float, float);
float resta (float, float);
float multiplicacion (float, float);
float division (float, float);
float factorial (float);


////////////////
//ORDENAMIENTO//
////////////////


//////////////////////
//MOSTRAR IFORMACION//
//////////////////////



#endif // FUNCIONES_H_INCLUDED
