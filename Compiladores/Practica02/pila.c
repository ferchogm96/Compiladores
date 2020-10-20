#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "pila.h"

typedef struct _NodoPila NodoPila;

struct _NodoPila{
	void * elemento;
	NodoPila* anterior;
};

struct _Pila{
	NodoPila* primero; //fondo
	NodoPila* ultimo;  //cima
};

//Funciona auxiliar CreaNodo()
NodoPila* CreaNodo(Pila* elemento){
	NodoPila* nodo = (NodoPila *) malloc(sizeof(NodoPila));
	nodo->elemento = elemento;
	nodo->anterior = NULL;
	return nodo;
}

//Funcion auxiliar DestruirNodo()
void DestruirNodo(NodoPila* nodo){
	nodo->elemento = NULL;
	nodo->anterior = NULL;
	free(nodo);
}

Pila *pila_nueva(){
	Pila* pila = (Pila *)malloc(sizeof(Pila));
	pila->ultimo = pila->primero = NULL;
	return pila;
}

void pila_mete(Pila* pila, void* elemento){
	assert(pila != NULL && elemento != NULL);
	NodoPila* nodo = CreaNodo(elemento);
	if(pila_es_vacia(pila)){
		pila->primero = nodo;
		pila->ultimo = nodo;		
	} else {
		nodo->anterior = pila->ultimo;
		pila->ultimo = nodo;
	}
}

void* pila_saca(Pila* pila){
	assert(pila != NULL);
	if(pila->ultimo){
		NodoPila* sacado = pila->ultimo;
		pila->ultimo = pila->ultimo->anterior ;
		DestruirNodo(sacado);
		if(pila_es_vacia(pila)){
			pila->primero = NULL;
			pila->ultimo = NULL;
		}
		return sacado;
	}
}

bool pila_es_vacia(Pila* pila){
	assert(pila != NULL);
	if(pila->ultimo == NULL && pila->primero == NULL){
		return true;
	}
	return false;
}

void pila_libera(Pila* pila){
	assert(pila != NULL);
	while(pila->ultimo){
		pila_saca(pila);
	}
	free(pila);
}

//Para probar la estructura
int* entero_nuevo(int w){
	int* j = malloc(sizeof(int));
	*j = w;
	return j;
}

int main(){
	Pila* p;
	p = pila_nueva();
	for(int i=1; i<21; i++){
		pila_mete(p, entero_nuevo(i));
		printf("%d\n", i);
	}
	pila_saca(p);//20
	pila_saca(p);
	pila_mete(p,entero_nuevo(30));
	NodoPila* iterador = p->ultimo;
	while(iterador -> anterior){
		printf("\nIterador %p\n", iterador);
		printf("Elemento: %d\n", *(int *)iterador->elemento);
		iterador = iterador->anterior;
	}
	printf("\nIterador %p\n", iterador);
	printf("Elemento: %d\n", *(int *)iterador->elemento);

	return 0;
}
