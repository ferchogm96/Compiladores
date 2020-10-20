%{
    #include <stdio.h>
    #include <ctype.h>
    int palabras, lineas, caracteres;
%}

%option noyywrap

%%
[a-zA-Z]+ {palabras++; caracteres+= strlen(yytext);} 
. {caracteres++;}
\n   {lineas++; caracteres++;}

%%
int yywrap(){
    return 1;
}

int main(int argc, char *argv[]){
    FILE *f;
    f = fopen(argv[1], "r");
	yyin = f;
    yylex();
    fclose(yyin);
    printf("Número de palabras: %d\n", palabras);
    printf("Número de líneas: %d\n", lineas);
    printf("Número de caracteres: %d\n", caracteres);
}