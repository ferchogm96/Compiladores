%{
    #include <stdio.h>
    #include <string.h>
    char texto[1024];
    int i = 0;
%}
%option noyywrap
espacio " "|\t

%%

{espacio}+ {/*Ignorar Espacios*/}
.  {texto[i] = *yytext; i++;}
\n {texto[i] = *yytext; i++;}


%%

int main(int argc, char *argv[])
{
    FILE *f, *out;
    f = fopen(argv[1], "r");
    out = fopen(strcat(argv[1], "-SinEspacios"), "a");
	yyin = f;
    yyout = out;
    yylex();
    fprintf(yyout, "%s", texto);
    fclose(yyout);
    fclose(yyin);
}