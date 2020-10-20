#include <stdbool.h>

//Estrcutura para pilas
typedef struct _Pila Pila;

//Crea una nueva pila
Pila* pila_nueva (void);

//Permite introducir un elemento a la pila.
void pila_mete (Pila* pila, void* elemento);

//Permite sacar el primer elemento
void* pila_saca (Pila* pila);

//Indica si una pila no contiene elementos.
bool pila_es_vacia (Pila* pila);

//Permite liberar la memoria que utiliza la pila.
void pila_libera (Pila* pila);