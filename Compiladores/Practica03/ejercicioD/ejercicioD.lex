%{
    #include <stdio.h>
    #include <string.h>
%}
%option noyywrap
%option yylineno
espacio [ \t\n]
entero [0-9]+
real [0-9]+"."[0-9]*|[0-9]*.[0-9]+
idC [_]*[[a-zA-Z]+[0-9]*]*|[_]+[[a-zA-Z]*[0-9]*]*
reservada "if"|"then"|"else"|"while"|"do"|"case"|"is"|"void"|"true"|"false"|"begin"|"end"|"not"
comentariomlinea "<*".*"*>"
oparitmetico "+"|"-"|"*"|"/"|"%"
oprelacional "¿"|"¡"|"¡¿"|"="
asignacion ":="
especiales "("|")"|"{"|"}"|";"|","
%x cadena
%x reservada
%x comentariol
%x comentarioml
%%
\"		BEGIN(cadena);printf("<Cadena, %s", yytext);
<cadena>[^"]*	   printf("%s", yytext);
<cadena>\"	   printf("%s>\n" , yytext); BEGIN(INITIAL);

\n {/*ignorar*/}
{entero} {printf("<Entero, %s>\n", yytext);}
{real} {printf("<Real, %s>\n", yytext);}
{reservada} {printf("<Reservada, %s>\n", yytext);}
{idC} {printf("<ID, %s>\n", yytext);}

[ \t]+ {printf("<Espacio, %s>\n", yytext);}

"--"    BEGIN(comentariol);printf("<Comentario Línea, %s", yytext);
<comentariol>[^-\n]+     printf("%s", yytext);
<comentariol>\n     printf(">\n");BEGIN(INITIAL);

"<*"    BEGIN(comentarioml);printf("<Comentario M Línea, %s", yytext);
<comentarioml>[^*>]+     printf("%s", yytext);
<comentarioml>"*>"  printf("%s>", yytext);

{comentariomlinea} {printf("<Comentario M Linea, %s>\n", yytext);}
{oparitmetico} {printf("<OP Aritmetico, %s>\n", yytext);}
{oprelacional} {printf("<OP Relacional, %s>\n", yytext);}
{asignacion} {printf("<Asignación, %s>\n", yytext);}
{especiales} {printf("<Sim Especial, %s>\n", yytext);}
. {printf("Error de %s, en la línea %d\n", yytext, yylineno);}
%%

int main(int argc, char *argv[]){
    yylex();
}