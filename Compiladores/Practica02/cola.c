#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "cola.h"

typedef struct _NodoCola NodoCola;

struct _NodoCola{
	void* elemento;
	NodoCola* siguiente;
};

struct _Cola{
	NodoCola* primero;
	NodoCola* ultimo;
};

//Funciona auxiliar CreaNodo()
NodoCola* CreaNodo(void* elemento){
	NodoCola* nodo = (NodoCola *) malloc(sizeof(NodoCola));
	nodo->elemento = elemento;
	nodo->siguiente = NULL;
	return nodo;
}

//Funcion auxiliar DestruirNodo()
void DestruirNodo(NodoCola* nodo){
	nodo->elemento = NULL;
	nodo->siguiente = NULL;
	free(nodo);
}


Cola* cola_nueva(){
	Cola* cola = (Cola *)malloc(sizeof(Cola));
	cola->primero = cola->ultimo = NULL;
	return cola;
}

void cola_mete(Cola* cola, void* elemento){
	assert(cola != NULL && elemento != NULL);
	NodoCola* nodo = CreaNodo(elemento);
	if(cola_es_vacia(cola)){
		cola->primero = nodo;
		cola->ultimo = nodo;
	} else {
		nodo->siguiente = cola->ultimo;
		cola->ultimo =nodo;
	}
}

void* cola_saca(Cola* cola){
	assert(cola != NULL);
	if(cola->primero){
		NodoCola* sacado = cola->primero;
		NodoCola* iterador = cola->ultimo;
		while(iterador -> siguiente != cola->primero){
			iterador = iterador->siguiente;
		}
		cola->primero = iterador;
		DestruirNodo(sacado);
		if(cola_es_vacia(cola)){
			cola->ultimo == NULL;
			cola->primero == NULL;
		}
		return sacado;
	}	
}

bool cola_es_vacia(Cola* cola){
	assert(cola != NULL);
	if(cola->primero == NULL && cola->ultimo == NULL){
		return true;
	}
	return false;
}

void cola_libera(Cola* cola){
	assert(cola != NULL);
	while(cola->primero){
		cola_saca(cola);
	}
	free(cola);
}

//Para probar la estructura
int* entero_nuevo(int w){
	int* j = malloc(sizeof(int));
	*j = w;
	return j;
}

int main(){
	Cola* c;
	c = cola_nueva();
	for(int i=1; i<21; i++){
		cola_mete(c, entero_nuevo(i));
		printf("%d\n", i);
	}
	cola_saca(c);
	cola_saca(c);
	cola_saca(c);
	cola_mete(c,entero_nuevo(100));
	//cola_saca(c);
	NodoCola* iterador = c->ultimo;
	while(iterador -> siguiente){
		//printf("\nIterador %p\n", iterador);
		printf("Elemento: %d\n", *(int *)iterador->elemento);
		iterador = iterador->siguiente;
	}
	//printf("\nIterador %p\n", iterador);
	//printf("Elemento: %d\n", *(int *)iterador->elemento);

	return 0;
}

