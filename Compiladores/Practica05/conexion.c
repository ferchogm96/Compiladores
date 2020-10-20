#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"
#define NUM_NON_TERM 7
#define NUM_TERM 9
extern int yylex();
extern char *yytext;
extern FILE* yyin;



/**
 * @brief  Función que agrega un elemento en el tope de la pila.
 * @param  *stack: referencia a la pila sobre la cual se trabaja.
 * @param  symbol: símbolo que estará en el nodo en el tope de la pila. 
 * @retval None
 */
void push(Stack *stack, Sym symbol){

  Node * tope = malloc(sizeof(Node));
  tope -> info = symbol;

  if(stack -> num == 0 && stack -> root == NULL){
    stack -> root = tope;
  }else{
    Node * iterador = stack->root;
    //iterador = stack -> root;

    while (iterador -> next){
      iterador = iterador->next;
    }
    iterador -> next = tope;
  }
  stack -> num = stack -> num+1;
  printf("Push a la Pila: %s \n", symbol.name);

}

 /**
  * @brief  Función que elimina el nodo del tope de la pila.
  * @param  *stack: la referencia a la pila sobre la cual se trabaja.
  * @retval None
 */
void pop(Stack *stack){
    Node * iterador = stack -> root -> next;
    Node * penultimo = stack -> root;

  if(stack -> num == 0){
    printf("No hay elementos en la pila.\n");
  }else{
    //Caso en que haya un único elemento
    if (!stack -> root -> next){
      stack -> root = 0;
    }else{
      //Vamos al tope de la pila
      while (iterador -> next){
        iterador = iterador -> next;
        penultimo = penultimo ->next;
      }
      penultimo -> next = 0;
    }
    stack -> num = stack -> num-1;
    
    printf("Pop a la Pila: %s\n", iterador ->info.name );
  }

}

/**
 * @brief  Función que dada un Stack devuelve la referencia al nodo que está al tope de la pila.
 * @param  *stack: referencia a la pila sobre la que se trabaja
 * @retval la referencia al nodo en el tope de la pila.
 */
Node * tope(Stack *stack){

  Node * iterador = stack -> root;
  //iterador = stack -> root;
  while (iterador -> next){
    iterador = iterador -> next;
  }
  return iterador; 
}

/**
 * @brief  Función que imprime la información de la pila que se pasa como parámetro
 * @param  stack: referencia a la pila sobre la cual se trabaja.
 * @retval None
 */
void infoStack(Stack * stack){
  if (stack->num != 0)
  {
    printf("Root: %s\nNum: %d\nTope: %s\n", stack->root->info.name, stack ->num, tope(stack) ->info.name);
  }else
  {
    printf("Root: NULL\nNum: 0\nTope: NULL\n");
  }
}


int main(int argc, char* argv[]) {

  if (argc < 2)
  {
    printf(" USO:\n ./practica <archivo> \n donde <archivo> es un archivo de texto\n");
    return 0;
  }
  

  int matriz[NUM_NON_TERM][NUM_TERM];//creando la matriz para tabla de análisis
  Sym simbolos[17];//arreglo de símbolos
  Prod producciones[14];// arreglo de producciones
  Sym term_a = {type:1, name:"a", pos:0};
  Sym term_b = {type:1, name:"b", pos:1};
  Sym term_mas = {type:1, name: "+", pos:2};
  Sym term_est = {type:1, name: "*", pos:3};
  Sym term_opc = {type:1, name: "?", pos:4};
  Sym term_parizq = {type:1, name: "(", pos:5};
  Sym term_or = {type:1, name:"|", pos:6};
  Sym term_parder = {type:1, name: ")", pos:7};
  Sym term_fin = {type:1, name: "$", pos:8};
  Sym epsilon = {type: 3, name:"epsilon", pos:9};
  
  Sym A = {type: 2, name:"A", pos:0};
  Sym AP = {type: 2, name:"AP", pos:1};
  Sym B = {type: 2, name:"B", pos:2};
  Sym BP = {type: 2, name:"BP", pos:3};
  Sym C = {type: 2, name:"C", pos:4};
  Sym CP = {type: 2, name:"CP", pos:5};
  Sym D = {type: 2, name:"D", pos:6};
  
  simbolos[0] = term_a;
  simbolos[1] = term_b;
  simbolos[2] = term_mas;
  simbolos[3] = term_est;
  simbolos[4] = term_opc;
  simbolos[5] = term_parizq;
  simbolos[6] = term_or;
  simbolos[7] = term_parder;
  simbolos[8] = term_fin;
  simbolos[9] = A;
  simbolos[10] = AP;
  simbolos[11] = B;
  simbolos[12] = BP;
  simbolos[13] = C;
  simbolos[14] = CP;
  simbolos[15] = D;
  simbolos[16] = epsilon;
  //Las producciones están inversas para meterlas directo a la pila
  Prod p0 = {head:9 ,body:"10/11", num:2};  //A->BAP
  Prod p1 = {head:10 ,body:"9/6", num:2};   //AP->orA
  Prod p2 = {head:10 ,body:"16", num:1};    //AP->epsilon
  Prod p3 = {head:11 ,body:"12/13", num:2}; //B->CBP
  Prod p4 = {head:12 ,body:"11", num:1};    //BP->B
  Prod p5 = {head:12 ,body:"16", num:1};    //BP->epsilon
  Prod p6 = {head:13 ,body:"14/15", num:2}; //C->DCP
  Prod p7 = {head:14 ,body:"14/2", num:2};  //CP->+CP
  Prod p8 = {head:14 ,body:"14/3", num:2};  //CP->*CP
  Prod p9 = {head:14 ,body:"14/4", num:2};  //CP->?CP
  Prod p10 = {head:14 ,body:"16", num:1};   //CP-> epsilon
  Prod p11 = {head:15 ,body:"7/9/5", num:3};//D->(A)
  Prod p12 = {head:15 ,body:"0", num:1};    //D->a
  Prod p13 = {head:15 ,body:"1", num:1};    //D->b

  producciones[0] = p0; //A->BAP
  producciones[1] = p1; //AP->orA
  producciones[2] = p2; //AP->epsilon
  producciones[3] = p3; //B->CBP
  producciones[4] = p4; //BP->B
  producciones[5] = p5; //BP->epsilon
  producciones[6] = p6; //C->DCP
  producciones[7] = p7; //CP->+CP
  producciones[8] = p8; //CP->*CP
  producciones[9] = p9; //CP->?CP
  producciones[10] = p10; //CP-> epsilon
  producciones[11] = p11; //D->(A)
  producciones[12] = p12; //D->a
  producciones[13] = p13; //D->b

  //Renglon A
  matriz[0][0] = 0;
  matriz[0][1] = 0;   
  matriz[0][2] = -1;
  matriz[0][3] = -1;
  matriz[0][4] = -1;
  matriz[0][5] = 0;
  matriz[0][6] = -1;
  matriz[0][7] = -1;
  matriz[0][8] = -1;
  //Renglon AP
  matriz[1][0] = -1;
  matriz[1][1] = -1;
  matriz[1][2] = -1;
  matriz[1][3] = -1;
  matriz[1][4] = -1;
  matriz[1][5] = -1;
  matriz[1][6] = 1;
  matriz[1][7] = 2;
  matriz[1][8] = 2;
  //Renglon B
  matriz[2][0] = 3;
  matriz[2][1] = 3;
  matriz[2][2] = -1;
  matriz[2][3] = -1;
  matriz[2][4] = -1;
  matriz[2][5] = 3;
  matriz[2][6] = -1;
  matriz[2][7] = -1;
  matriz[2][8] = -1;
  //Renglon BP
  matriz[3][0] = 4;
  matriz[3][1] = 4;
  matriz[3][2] = -1;
  matriz[3][3] = -1;
  matriz[3][4] = -1;
  matriz[3][5] = 4;
  matriz[3][6] = 5;
  matriz[3][7] = 5;
  matriz[3][8] = 5;
  //Renglon C
  matriz[4][0] = 6;
  matriz[4][1] = 6;
  matriz[4][2] = -1;
  matriz[4][3] = -1;
  matriz[4][4] = -1;
  matriz[4][5] = 6;
  matriz[4][6] = -1;
  matriz[4][7] = -1;
  matriz[4][8] = -1;
  //Renglon CP
  matriz[5][0] = 10;
  matriz[5][1] = 10;
  matriz[5][2] = 7;
  matriz[5][3] = 8;
  matriz[5][4] = 9;
  matriz[5][5] = 10;
  matriz[5][6] = 10;
  matriz[5][7] = 10;
  matriz[5][8] = 10;
  //Renglon D
  matriz[6][0] = 12;
  matriz[6][1] = 13;
  matriz[6][2] = -1;
  matriz[6][3] = -1;
  matriz[6][4] = -1;
  matriz[6][5] = 11;
  matriz[6][6] = -1;
  matriz[6][7] = -1;
  matriz[6][8] = -1;

  printf("Todas las variables cargadas\n");

  FILE *f;
  f = fopen(argv[1], "r");
  yyin = f;

  Stack pila = {root:0, num: 0};//Pila con la que trabajaremos

  while(yylex() != 0) {
    //Obtenemos el token actual
    char *token = (char*)malloc(15);    
    strcpy(token, yytext);

    int indice = 0;//índice del token
    int indPro = 0;//índice de la producción

    push(&pila, simbolos[8]);//ingresamos a la pila el simbolo fin de archivo $
    push(&pila, simbolos[9]);//ingresamos a la pila el Símbolo inicial A

    //Verificamos si la cadena ingresada es correcta
    while(tope(&pila)->info.name !=  term_fin.name) {//Mientras que la pila no esté vacía, que no sea $
      printf("TOKEN ACTUAL %s\n", token);

      //Obtenemos el indice que corresponde al token obtenido de yytext
      if (strcmp(token, term_a.name) == 0) {//Caso en que sea 'a'
        indice = 0;
      }else if (strcmp(token, term_b.name) == 0){//caso en que sea 'b'
        indice = 1;
      }else if (strcmp(token,term_mas.name) == 0){//caso en que sea '+'
        indice = 2;
      }else if (strcmp(token,term_est.name) == 0){//caso en que sea '*'
        indice = 3;
      }else if (strcmp(token, term_opc.name) == 0){//caso en que sea '?'
        indice = 4;
      }else if (strcmp(token, term_parizq.name) == 0){//caso en que sea '('
        indice = 5;
      }else if (strcmp(token, term_or.name) == 0){//caso en que sea 'or'
        indice = 6;
      }else if (strcmp(token, term_parder.name) == 0){//caso en que sea ')'
        indice = 7;
      }else if (strcmp(token, term_fin.name) == 0){//caso en que sea ')'
        indice = 8;
      }      
      /*
      */
      Node topep = *tope(&pila);//Obtenemos el tope de la pila
      if(topep.info.type == 1){//Si el tope es terminal
        
        printf("Tope %s es terminal.\n", topep.info.name);
        printf("Comparamos : %s con %s\n", topep.info.name, token);

        //Verificamos si el tope y el token son ambos $ fin de archivos
        char *findearchivo = "$";
        if(strcmp(topep.info.name, token) == 0 && strcmp(topep.info.name, findearchivo) == 0){
          printf("\n >>>> CADENA ACEPTADA <<<< \n");

          memset(token, 0, 15);//borramos token actual
          yylex();//Avanzamos al siguiente token
          strcpy(token, yytext);//leemos el siguiente token

          //VERIFICAMOS SI YA SE TERMINÓ DE LEER EL ARCHIVO
          if (strcmp(token, "") == 0)
          {
            printf("\n --- FIN DE ARCHIVO ---\n");
            return 0;
          }
          push(&pila, simbolos[9]);//Si no es fin de archivo reiniciamos el tope de la pila
          

        }else

        //Comparamos el valor del tope de la pila con el token actual
        if (strcmp(topep.info.name, token) == 0) {
          printf(" - - MATCH TOPE %s - TOKEN %s\n",topep.info.name, token);
          pop(&pila);
          
          memset(token, 0, 15);//borramos token actual
          yylex();//Avanzamos al siguiente token
          strcpy(token, yytext);//leemos el siguiente token
          printf("SIGUIENTE TOKEN %s", token);
        }else{
          printf(" X - Error de cadena - X\n");
          return 0;
        }
      }else{//Si el tope no es terminal
        printf("Tope %s no es terminal.\n", topep.info.name);
        indPro = matriz[topep.info.pos][indice];

        if(indPro != -1){//Verificamos si existe la produccion en la tabla. 

          //printf("Hay una producción con los símbolos\n");
          Prod actual = producciones[indPro];
          char separador[] = "/";
          printf("\nProducción siguiente %s\n", actual.body);
          char *final = "16";

          //Si hay no_terminales que aceptan epsilon
          if (strcmp(actual.body, final) == 0) {
            pop(&pila);//Hacemos pop de los no terminales

          }else{
            printf("Hacemos pop a la pila\n");
            pop(&pila);

            char str[10];
            strcpy(str, actual.body); //cargamos la cadena de la produccion por la que se cambia
            char *token2;
            token2 = strtok(str, separador);

            //metemos todos los simbolos de la cadena
            while( token2 != NULL ) {
              push(&pila, simbolos[atoi(token2)]);
              token2 = strtok(NULL, separador);
            }
            memset(str, 0, 10);         
          }
        }else{
          printf(" X - Error de cadena - X\n");
          return 0;
        } 
      }
    }//fin while sobre la pila

    memset(token, 0, 15);
  };//fin while yytext
  printf("\n <<<< CADENA RECHAZADA >>>>\n");
  fclose(yyin);
  return 0;
} 