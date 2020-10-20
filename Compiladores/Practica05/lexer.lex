%{
  #include <stdio.h>
  #include "estructuras.h"
%}

%option noyywrap

digito [0-9]
identificador [a-zA-Z_][a-zA-Z0-9_]{0,31}

%%

"a" {printf("Letra a"); return 1;}
"b" {printf("Letra b"); return 2;}
"+" {printf("Mas +"); return 3;}
"*" {printf("Ast *"); return 4;}
"?" {printf("Opc ?"); return 5;}
"(" {printf("Pariz ("); return 6;}
"|" {printf("Or or"); return 7;}
")" {printf("Parde )"); return 8;}
"$" {printf("Fin $"); return 9;}

" " {/*Ignorar Espacios*/}
"\n" {printf("Salto de Linea"); return 0;}
<<EOF>> {printf("Fin de archivo"); return 0;}
. {printf("No reconocido, termina ejecución.\n"); return 0;}

%%