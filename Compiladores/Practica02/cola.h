#include <stdbool.h>

//Estrcutura para Cola
typedef struct _Cola Cola;

//Crea una nueva cola
Cola *cola_nueva (void);

//Permite introducir un elemento a la pila.
void cola_mete (Cola *cola, void* elemento);

//Permite sacar el primer elemento
void* cola_saca (Cola *cola);

//Indica si una pila no contiene elementos.
bool cola_es_vacia (Cola *cola);

//Permite liberar la memoria que utiliza la pila.
void cola_libera (Cola *cola);