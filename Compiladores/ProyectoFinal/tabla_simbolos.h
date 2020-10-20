#ifndef TABSYM_H
#define TABSYM_H
#include <stdbool.h>

typedef struct sym{
    char id[32];
    int tipo;
    int dir;    
} SYM;

typedef struct symtab{
    SYM syms[200];
    int num;
} SYMTAB;

void insertar(SYMTAB *st, SYM s);
void imprimir(SYMTAB *st);
int getTipo(SYMTAB *st, char *id);
int getDir(SYMTAB *st, char *id);
bool getID(SYMTAB *st, char *id);

#endif