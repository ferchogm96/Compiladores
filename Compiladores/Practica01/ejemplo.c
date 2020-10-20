#define START  0  /* */
#define ENDING 9  /* */
#define MAX(A,B)  ((A)>(B)?(A):(B))  /* */ 
#define MIN(A,B)  ((A)>(B)?(B):(A))  /* Macro definitoria de Min */

&nbsp;
 
main(){
	int index,mn,mx;
	int count = 5;
 	&nbsp;
	for (index = START;index <= ENDING;index++) {
		mx = MAX(index,count);
		mn = MIN(index,count);
		printf("Max es %d y min es %d\n",mx,mn);
	}
}
&nbsp;

/* Encontrará cada sitio donde la combinación «START» aparezca y,
simplemente la sustituirá por un 0, ya que esto es una definición. 
El compilador nunca verá la palabra «START» en toda la compilación. Sólo encontrará ceros
De la misma manera, el preprocesador encontrará todas las apariciones de la palabra «ENDING»,
y las cambiará por 9, y el compilador operará en esa línea sin saber que hubo un «ENDING»

Cuando el preprocesador encuentra la palabra «MAX» seguida de un grupo de paréntesis,
esperará a encontrar dos términos entre paréntesis, y realizará una sustitución de los
términos en la segunda definición. Entonces, el primer termino reemplazará cada «A» 
en la segunda definición, y el segundo término sustituirá cada «B» en la segunda definición. 
Cuando encontramos la línea 12 del programa, «index» será sustituido por cada «A», y «count» lo será por cada «B».
«mx» recibirá el máximo valor de «index» o «count». De una manera parecida, el macro «MIN» resultará en «mn», 
recibiendo el mínimo valor de «index» o «count». Los resultados aparecen por pantalla.
*/