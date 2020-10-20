%{
#include <stdio.h>	
#include <string.h>	
#include <stdlib.h> 
#include <stdbool.h>
#include "tabla_simbolos.h"
#include "tabla_tipo.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(char *s);
int posicionTablaTipo;
int tipoGBL = 0;
int baseGBL;
int tipoDirGBL;
int dirGBL;
int dirGeneral = 0;

int valorArreglo = 4;

int idST = 0;

TSTACK *stackTipos;

SYMTAB generalSimbolos;

TYPTAB *generalTipos;

void iniciarStacks();
%}
%union{
    struct{
    int tipo;
    char numeroCaracter[32];
    }numero;

    struct{
    int tipo;
    char numeroCaracter[32];
    }expresion;
 
    char id[32];
    int base;
    int tipo_registro;
    int arreglo;

}

%token ESTRUCTURA
%token INICIO
%token ENT REAL DREAL CAR SIN
%token<numero> NUM
%token<id> ID
%token DEF
%token SI
%token MIENTRAS 
%token HACER
%token SEGUN
%token ESCRIBIR
%token LEER
%token DEVOLVER
%token PYC
%token COMA
%token TERMINAR
%token CASO
%token DOSPUN
%token ENTONCES
%token PRED
%left O
%left  Y
%right NO
%token VERDADERO
%token FALSO
%token CADENA
%token<numero> CARACTER
%token PUNTO
%left MAQ
%left MEQ
%left MEI
%left MAI
%left DOSMAME
%right IGUAL
%token NL
%left ASIGNACION
%left MAS MEN
%left MUL DIV
%left MOD

%nonassoc LPAR RPAR
%nonassoc LCOR RCOR
%nonassoc FIN
%nonassoc SINO


%start programa

%type<base> base tipo_arg

 



%%
programa : {
				iniciarStacks();
				imprimir(&generalSimbolos);
				
			} declaraciones funciones;

declaraciones: tipo lista_var PYC declaraciones 
			|  tipo_registro  lista_var PYC declaraciones
			| ; 

tipo_registro : ESTRUCTURA INICIO declaraciones FIN;

tipo : base {dirGBL = $1;} tipo_arreglo;

base : ENT {$$ = 0;} | REAL {$$ = 1;}| DREAL {$$ = 2;} | CAR {$$ = 3;}| SIN {$$ = 4;};

tipo_arreglo : LCOR NUM RCOR tipo_arreglo 
				{	
					
					if($2.tipo == 0){
						TYP *tipo4 = init_type();
						tipo4->id = posicionTablaTipo + 1;
						strcpy(tipo4->nombre, "array");
						tipo4->tam =  valorArreglo * atoi($2.numeroCaracter);
						valorArreglo = tipo4->tam;
						posicionTablaTipo = tipo4->id;

						append_type(generalTipos, tipo4);

						pop_tst(stackTipos);
						
						push_tst(stackTipos, generalTipos);

						print_tstack(stackTipos);

					}else{
					yyerror("El numero del arreglo no es compatible");
					}
					
				}
				| ;

lista_var : lista_var COMA ID {	printf("viola 1 aqui\n");
										printf("El id es: %s\n", $3);
							  }
			| ID{
										if(!getID(&generalSimbolos, $1)){
					                    	SYM s;
								            strcpy(s.id, $1);
								            s.tipo = tipoGBL;
								            s.dir = dirGeneral;
								            dirGeneral+= dirGBL;
								            insertar(&generalSimbolos, s);
										}
								};
									

funciones : DEF tipo ID  LPAR argumentos RPAR INICIO declaraciones sentencias FIN funciones | ;

argumentos : lista_arg 
			| SIN;

lista_arg : lista_arg COMA arg 
			| arg;

arg : tipo_arg ID;

tipo_arg : base {$$ = $1;} param_arr;

param_arr : LPAR RPAR param_arr 
			| ;
sentencias : sentencias sentencia 
			| sentencia;

sentencia:  SI e_bool ENTONCES sentencia %prec FIN;
		|	SI e_bool ENTONCES sentencia SINO sentencia FIN;
		|	MIENTRAS e_bool HACER sentencia FIN
		|	HACER sentencia MIENTRAS e_bool PYC
		|	SEGUN LPAR variable RPAR HACER casos predeterminado FIN
		|	variable ASIGNACION expresion PYC
		|	ESCRIBIR expresion PYC
		|	LEER variable PYC
		|	DEVOLVER PYC
		|	DEVOLVER expresion PYC
		|	TERMINAR PYC;

casos : CASO NUM DOSPUN sentencia casos | CASO NUM DOSPUN sentencia;

predeterminado : PRED DOSPUN sentencia | ;


e_bool : e_bool O e_bool 
		| e_bool Y e_bool 
		| NO e_bool 
		| relacional 
		| VERDADERO 
		| FALSO;

relacional :  relacional IGUAL relacional 
			| relacional DOSMAME relacional 
			| relacional MAQ relacional 
			| relacional MEQ relacional 
			| relacional MEI relacional 
			| relacional MAI relacional 
			| expresion;

expresion :   expresion MAS expresion 
			| expresion MEN expresion
			| expresion MUL expresion 
			| expresion DIV expresion 
			| expresion MOD expresion 
			| LPAR expresion RPAR 
			| variable 
			| NUM {
			printf("El valor de num es:%s y tipo %d\n", $1.numeroCaracter, $1.tipo);}
			| CADENA
			| CARACTER {
				printf("El valor de caracter es:%s y tipo %d\n", $1.numeroCaracter, $1.tipo);};


variable : ID {
										if(!getID(&generalSimbolos, $1)){
					                    	yyerror("El id no fue declarado");
										}
								} variable_comp;

variable_comp : dato_est_sim 
				| arreglo 
				| LPAR parametros RPAR;

dato_est_sim : dato_est_sim PUNTO ID {
										if(!getID(&generalSimbolos, $3)){
					                    	yyerror("El id no fue declarado");
										}
								}
			|  ;

arreglo: LCOR expresion RCOR 
		| arreglo LCOR expresion RCOR;

parametros : lista_param 
			| ;


lista_param : lista_param COMA expresion 
			| expresion ;

%%

void yyerror(char *s){
	printf("%s, linea: %d en el token: %s \n",s, yylineno, yytext);
}

void iniciarStacks(){
	
	
	
	stackTipos  = init_type_tab_stack();

	generalTipos = init_type_tab();

	TYP *tipo0 = init_type();
	tipo0->id = 0;
	strcpy(tipo0->nombre, "ent");
	tipo0->tam = 4;
	
	TYP *tipo1 = init_type();
	tipo1->id = 1;
	strcpy(tipo1->nombre, "real");
	tipo1->tam = 4;
	
	TYP *tipo2 = init_type();
	tipo2->id = 2;
	strcpy(tipo2->nombre, "dreal");
	tipo2->tam = 8;
	
	TYP *tipo3 = init_type();
	tipo3->id = 3;
	strcpy(tipo3->nombre, "char");
	tipo3->tam = 1;

	TYP *tipo4 = init_type();
	tipo4->id = 4;
	strcpy(tipo4->nombre, "sin");
	tipo4->tam = 0;
	
	posicionTablaTipo = tipo4->id;


	append_type(generalTipos, tipo0);
	append_type(generalTipos, tipo1);
	append_type(generalTipos, tipo2);
	append_type(generalTipos, tipo3);
	append_type(generalTipos, tipo4);
	
	push_tst(stackTipos, generalTipos);

	
	


}





