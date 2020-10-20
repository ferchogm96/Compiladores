#include <stdio.h>

//#define PI 3.1415926535897

#ifdef PI
#define area(r) (PI * r * r)
#else
#define area(r) (3.1416 * r * r)
#endif

/**
* Compiladores 2019 -2
*
*/
int main ( void ) {
	printf (" Hola Mundo !\n");
	float mi_area = area (3) ; // soy un comentario ... hasta  donde llegare ?
	printf (" Resultado : %f\n",mi_area );
	return 0;
}

