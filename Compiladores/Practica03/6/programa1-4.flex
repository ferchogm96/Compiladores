%{
	#include <stdio.h>
%}

id [a-zA-Z]+
espacio [ \t\n}]+

%%

. {printf("Ha ocurrido un error lexico: %s \n" , yytext);}
{id}+ { printf("Encontre un identificador %s \n" , yytext);}
int { printf("Encontre una palabra reservada %s \n" , yytext);}
float {printf("Encontre una palabra reservada %s \n" , yytext);}
if { printf("Encontre una palabra reservada %s \n" , yytext);}
else { printf("Encontre una palabra reservada %s \n" , yytext);}
{espacio} {/*Ignorar los espacios en blanco*/}

%%

int main(){
	yylex();
}
