#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TERM 1
#define NO_TERM 2
#define EPSILON 3
 /**
  * type: indica el tipo de símbolo que es.
  * name: es el nombre del símbolo, que puede ser opcional
  * pos: la posición que ocupa el símbolo dentro de la tabla de análisis, 
  *     ya sea su renglón o su columna dependiendo si es no terminal o terminal.
 */
typedef struct _symbol{
    short type;
    char name[15];
    short pos;
} Sym;

/**
 * head: es el encabezado de la producción, el índice que ocupa en el arreglo de símbolos.
 * body: una cadena de caracteres que continen los índices de los símbolos que conforman el cuerpo de la producción.
 * num: número de símbolos que componen el cuerpo de la producción.
 */
typedef struct _production{
    short head;
    char *body;
    short num;
} Prod;

/**
 * info: el contenido del símbolo que contiene el nodo.
 * next: referencia a un nodo siguiente.
 */
typedef struct _node{
    Sym info;
    struct _node * next;
} Node;

/**
 * root: referencia al nodo inicial de la pila.
 * num: número de nodos dentro que contiene la pila.
 */
typedef struct _stack{
    Node *root;
    int num;
} Stack;