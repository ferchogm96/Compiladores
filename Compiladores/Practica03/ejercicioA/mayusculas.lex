%{
    #include <stdio.h>
    #include <ctype.h>
    #include <string.h>
    char caracter;
    char texto[1024];
    int i = 0;
%}

%option noyywrap
palabra [a-zA-Z]
espacio [ \t]

%%

{palabra}  {texto[i] = toupper(*yytext); i++;}
{espacio} {texto[i] = *yytext; i++;}
.   {texto[i] = *yytext; i++;}
\n {texto[i] = *yytext; i++;}

%%

int main(int argc, char *argv[]){
    FILE *f, *out;
    f = fopen(argv[1], "r");
    out = fopen(strcat(argv[1], "-Mayusculas"), "a");
    yyin = f;
    yyout = out;
    yylex();
    fprintf(out, "%s", texto);
    fclose(yyin);
    fclose(yyout);

}