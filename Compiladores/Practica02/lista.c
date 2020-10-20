#include <assert.h>
#include <stdlib.h>
#include "lista.h"

struct _NodoLista{
	void* elemento;
	NodoLista* anterior;
	NodoLista* siguiente;
};

struct _Lista{
	NodoLista* cabeza;
	NodoLista* rabo;
	int longitud;
};

//Funcion auxiliar que destruye un nodo.
void DestruirNodo(NodoLista* nodo){
	nodo->anterior = NULL;
	nodo->siguiente = NULL;
	free(nodo);
}

static NodoLista *nodo_lista_nuevo(void *elemento){
	assert (elemento != NULL);
	NodoLista* nodo = (NodoLista *) malloc(sizeof(NodoLista));
	nodo->elemento = elemento;
	nodo->siguiente = NULL;
	nodo->anterior = NULL;
	return nodo;
}

Lista *lista_nueva(void){
	Lista* lista = (Lista*)malloc(sizeof(Lista));
	lista->cabeza = lista->rabo = NULL;
	lista->longitud = 0;
	return lista;
}

NodoLista *lista_cabeza(Lista *lista){
	assert(lista != NULL);
	return lista->cabeza;
}

NodoLista *lista_rabo(Lista *lista){
	assert(lista != NULL);
	return lista->rabo;
}

int lista_longitud(Lista* lista){
	assert(lista != NULL);
	return lista->longitud; 
}

void lista_agrega_inicio(Lista* lista, void* elemento){
	assert(lista != NULL && elemento != NULL);
	NodoLista* nodo = nodo_lista_nuevo(elemento);
	if(lista->cabeza == NULL){
		lista->cabeza = nodo;
		lista->rabo = nodo;
	} else{
		nodo->anterior = lista->cabeza;
		lista->cabeza = nodo;
	}	
	lista->longitud++;
}

void lista_agrega_final(Lista *lista, void *elemento){
	assert(lista != NULL && elemento != NULL);
	NodoLista* nodo = nodo_lista_nuevo(elemento);
	if(lista->cabeza == NULL){
		lista->cabeza = nodo;
		lista->rabo = nodo;
	} else {
		nodo->siguiente = lista->rabo;
		lista->rabo = nodo;
	}
	lista->longitud++;
}

void lista_inserta_antes(Lista *lista, NodoLista *nodo, void *elemento){
	assert(lista != NULL && nodo != NULL && elemento != NULL);
	assert((nodo->anterior != NULL && nodo != lista->cabeza) ||
			(nodo->anterior == NULL && nodo == lista->cabeza));
	NodoLista* nodoAgregado = nodo_lista_nuevo(elemento);
	if(lista->cabeza == NULL){
		lista->cabeza = nodoAgregado;
		lista->rabo = nodoAgregado;
	} else {
		NodoLista* iterador = lista->rabo;
		while(iterador->siguiente != nodo){
			iterador = iterador->siguiente;
		}
		nodoAgregado->anterior = iterador;
		nodoAgregado->siguiente = nodo;
		nodo->anterior = nodoAgregado;
		iterador->siguiente = nodoAgregado;
	}
	lista->longitud++;
}

void lista_inserta_despues(Lista *lista, NodoLista* nodo, void *elemento){
	assert(lista != NULL && nodo != NULL && elemento != NULL);
	assert((nodo->siguiente != NULL && nodo != lista->rabo) ||
			(nodo->siguiente == NULL && nodo == lista->rabo));
	NodoLista* nodoAgregado = nodo_lista_nuevo(elemento);
	if(lista->cabeza == NULL){
		lista->cabeza = nodoAgregado;
		lista->rabo = nodoAgregado;
	} else {
		NodoLista* iterador = lista->cabeza;
		while(iterador->anterior != nodo){
			iterador = iterador->anterior;
		}
		nodoAgregado->siguiente = iterador;
		nodoAgregado->anterior = nodo;
		nodo->siguiente = nodoAgregado;
		iterador->anterior = nodoAgregado;
	}
	lista->longitud++;
}

static void l_elimina_nodo(Lista* lista, NodoLista* nodo){
	assert(lista != NULL && nodo != NULL);
	if(lista->cabeza == NULL){
		return;
	} else{
		NodoLista* iterador = lista->cabeza;
		while(iterador->anterior != nodo){
			iterador = iterador->anterior;
		}
		nodo->anterior->siguiente = iterador;
		iterador->anterior = nodo->anterior;
		DestruirNodo(nodo);
		lista->longitud--;
	}
}

//Elimina un elemento en la lista.
void lista_elimina (Lista* lista,NodoLista* nodo, void* elemento){
	if(lista->cabeza == NULL){
		return;
	} else{
		NodoLista* iterador = lista->cabeza;
		while(iterador->elemento != elemento){
			iterador = iterador->anterior;
		}
		nodo->anterior->siguiente = iterador;
		iterador->anterior = nodo->anterior;
		DestruirNodo(nodo);
		lista->longitud--;
	}
}

void* lista_elimina_primero(Lista* lista){
	assert(lista != NULL && lista->cabeza != NULL);
	void* tmp = lista->cabeza->elemento;
	if(lista->longitud == 1){
		lista->cabeza = NULL;
		lista->rabo = NULL;
	} else {
		lista->cabeza = lista->cabeza->anterior;
		lista->cabeza->siguiente = NULL;
	}
	lista->longitud--;
	return tmp;
}

void* lista_elimina_ultimo(Lista* lista){
	assert(lista != NULL && lista->rabo != NULL);
	void* tmp = lista->rabo->elemento;
	if(lista->longitud == 1){
		lista->cabeza = NULL;
		lista->rabo = NULL;
	} else {
		lista->rabo = lista->rabo->siguiente;
		lista->rabo->anterior = NULL;
	}
	lista->longitud--;
	return tmp;
}

void lista_elimina_nodo(Lista* lista, NodoLista* nodo){
	assert(lista != NULL && nodo != NULL);
	if(lista->cabeza == NULL){
		return;
	} else{
		NodoLista* iterador = lista->cabeza;
		while(iterador->anterior != nodo){
			iterador = iterador->anterior;
		}
		nodo->anterior->siguiente = iterador;
		iterador->anterior = nodo->anterior;
		DestruirNodo(nodo);
		lista->longitud--;
	}
}

NodoLista* lista_dame(Lista* lista, int indice){
	assert(lista != NULL && indice >= 0 && indice < lista->longitud);
	NodoLista* iterador = lista->cabeza;
	int i = 0;
	while(i<=indice){
		iterador = iterador->anterior;
		i++;
	}
	return iterador;
}

void lista_libera(Lista* lista){
	assert(lista != NULL);
	free(lista);
}

void lista_libera_todo(Lista* lista){
	assert(lista != NULL);
	while(lista->cabeza){
		lista_elimina_primero(lista);
	}
	free(lista);
}

void* nodo_lista_elemento(Lista* lista, NodoLista* nodo){
	assert(nodo != NULL);
	void* tmp;
	if(lista->cabeza == NULL){
		return 0;
	} else{
		NodoLista* iterador = lista->cabeza;
		while(iterador->anterior != nodo){
			iterador = iterador->anterior;
		}
		tmp = iterador->anterior->elemento;
	}
	return tmp;
}

NodoLista* nodo_lista_anterior(Lista* lista, NodoLista* nodo){
	assert(nodo != NULL);
	NodoLista* tmp;
	if(lista->longitud == 1){
		return NULL;
	} else {
		NodoLista* iterador = lista->rabo;
		while(iterador->siguiente != nodo){
			iterador = iterador->siguiente;
		}
		tmp = iterador;
	}
	return tmp;
}

NodoLista* nodo_lista_siguiente(Lista* lista, NodoLista* nodo){
	assert(nodo != NULL);
	NodoLista* tmp;
	if(lista->longitud == 1){
		return NULL;
	} else {
		NodoLista* iterador = lista->cabeza;
		while(iterador->anterior != nodo){
			iterador = iterador->anterior;
		}
		tmp = iterador;
	}
	return tmp;
}

//Para probar la estructura
int* entero_nuevo(int w){
	int* j = malloc(sizeof(int));
	*j = w;
	return j;
}

int main(){
	Lista* l;
	l = lista_nueva();
	for(int i=1; i<21; i++){
		lista_agrega_inicio(l, entero_nuevo(i));
		//printf("%d\n", i);
	}
	/*lista_elimina_ultimo(l);//20
	//pila_saca(p);
	//pila_mete(p,entero_nuevo(30));
	NodoLista* iterador = l->cabeza;
	while(iterador -> anterior){
		printf("\nIterador %p\n", iterador);
		printf("Elemento: %d\n", *(int *)iterador->elemento);
		iterador = iterador->anterior;
	}
	printf("\nIterador %p\n", iterador);
	printf("Elemento: %d\n", *(int *)iterador->elemento);
*/
	return 0;
}