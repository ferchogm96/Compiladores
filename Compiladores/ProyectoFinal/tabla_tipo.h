#ifndef TYPTAB_H
#define TYPTAB_H
#include "datos.h"


void append_type(TYPTAB *tt,TYP *t); //agrega al final de la tabla un nuevo tipo
void clear_type_tab(TYPTAB *tt); //Deja vacia la tabla

TYPTAB pop_tst(TSTACK *s); //ejecuta un pop sobre la pila de tablas de tipos
void push_tst(TSTACK *s, TYPTAB *tt); //Ingresa una tabla a la pila de tablas de tipos

TSTACK *init_type_tab_stack(); //Reserva memoria para la pila
TYPTAB *init_type_tab(); //Reserva memoria para una tabla de tipos insertado los tipos nativos
TYP *init_type(); //reserva memoria para un tipo


void finish_type_tab_stack(TSTACK *s); //Lobera la memoria para la pila
void finish_type_tab(TYPTAB *st); //libera memoria para una tabla de tipos
void finish_type(TYP *S); //libera memoria para un tipo

int getIDTT(TYPTAB *t, int id); //retorna el tam de un tipo
int getTamTT(TYPTAB *t, int id); //retorna el tam de un tipo
TB getTipoBaseTT(TYPTAB *t, int id); //retorna el tipo base
char *getNombreTT(TYPTAB *t, int id); //retorna el nombre de un tipo tambien lo puede cambiar por un entero
void print_typetab(TYPTAB *t); //imprime en pantalla la tabla de tipos
#endif