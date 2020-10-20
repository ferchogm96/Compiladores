#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabla_tipo.h"




void append_type(TYPTAB *tt, TYP *t){
	if(tt->head != NULL){
		TYP *cola = tt->tail;
		cola->next = t;
		tt->tail = t;
		tt->num = tt->num +1;
	}else{
		tt->head = t;
		tt->tail = t;
		t->next = NULL;
		tt->num = tt->num +1;
		tt->next = NULL;
	}
} //agrega al final de la tabla un nuevo tipo
void clear_type_tab(TYPTAB *tt){
	tt->head = NULL;
	tt->tail = NULL;
	tt->num = 0;
	tt->next = NULL;
} //Deja vacia la tabla

TYPTAB pop_tst(TSTACK *s){
	if(s->top != s->tail){
		TYPTAB *cabeza = s->top;
		TYPTAB *nuevaCabeza = cabeza->next;
		s->top = nuevaCabeza;
		return *cabeza;
	}else{
		TYPTAB *c = s->top;
		s->top = NULL;
		s->tail = NULL;
		return *c;
	}
	
} //ejecuta un pop sobre la pila de tablas de tipos

void push_tst(TSTACK *s, TYPTAB *tt){
	if(s->top != NULL){
		TYPTAB *cabeza = s->top;
		cabeza->next = tt;
		s->top = tt;
	}else{
		s->top = tt;
		s->tail = tt;
		tt->next = NULL;
	}

} //Ingresa una tabla a la pila de tablas de tipos

TSTACK *init_type_tab_stack(){
	TSTACK *ts = (TSTACK*) malloc(sizeof(TSTACK));
	return ts;
} //Reserva memoria para la pila

TYPTAB *init_type_tab(){
	TYPTAB *t = (TYPTAB*) malloc(sizeof(TYPTAB));
	return t;
} //Reserva memoria para una tabla de tipos insertado los tipos nativos

TYP *init_type(){
	TYP *type = (TYP*) malloc(sizeof(TYP));
	return type;
} //reserva memoria para un tipo


void finish_type_tab_stack(TSTACK *s){
	TYPTAB *tt = s->top;
	while(tt != NULL){
		TYPTAB *tem = tt;
		tt = tt->next;
		finish_type_tab(tem);
	}
	free(s);

} //Lobera la memoria para la pila

void finish_type_tab(TYPTAB *st){
	TYP *it = st->head;
	while(it != NULL){
		TYP *tem = it;
		it = it->next;
		finish_type(tem);
	}
	TYPTAB *ts = st->next;
	free(ts);
	free(st);
} //libera memoria para una tabla de tipos

void finish_type(TYP *S){
	TYP *n = S->next;
	free(n);
	free(S);
} //libera memoria para un tipo

int getIDTT(TYPTAB *t, int id){
	TYP *i = t->head;
	while(i != NULL){
		if(i->id == id){
			return i->id;
		}
		i = i->next;
	}
	return -1;
} //retorna el tam de un tipo

int getTamTT(TYPTAB *t, int id){
	TYP *i = t->head;
	while(i != NULL){
		if(i->id == id){
			return i->tam;
		}
		i = i->next;
	}
	return -1;
} //retorna el tam de un tipo

TB getTipoBaseTT(TYPTAB *t, int id){
	TYP *i = t->head;
	while(i != NULL){
		if(i->id == id){
			return i->tb;
		}
		i = i->next;
	}

} //retorna el tipo base

char *getNombreTT(TYPTAB *t, int id){
	TYP *i = t->head;
	while(i != NULL){
		if(i->id == id){
			return i->nombre;
		}
		i = i->next;
	}
	return "";
} //retorna el nombre de un tipo tambien lo puede cambiar por un entero

void print_typetab(TYPTAB *t){
	printf("Tabla de TIPOS\n");
	if(t->head != NULL){
		TYP *type = t->head;
		while(type != NULL){
			printf("%d %s %d\n", type->id, type->nombre, type->tam);
			type = type->next;
		}	
		printf("_____________________________________\n");
	}else{
		printf("La tabla de tipos es vacia\n");
	}
	
} //imprime en pantalla la tabla de tipos



void print_tstack(TSTACK *t){
    printf("PILA DE TIPOS\n");
    if(t->top != NULL) {
    	
    	TYPTAB *s1 = t->top;
	    while(s1 != NULL){
	    	print_typetab(s1);
	        s1 = s1->next;
	    }
	    printf("_____________________________________\n");
    }else{
    	printf("La Pila es vacia\n");
    }

    
    
} //imprime en pantalla la tabla de simbolos