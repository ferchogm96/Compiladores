%{
#include <stdio.h>
%}

%option noyywrap

digito [0-9]
entero [0-9]+
punto_flot [0-9]{0,6}
punto_dob [0-9]{7,16}
letra [a-zA-Z]
espacio [ \t\n ]+
esps {espacio}

flotante {entero}*.{punto_flot}
double {entero}*.{punto_dob}
aritmetico \+|-|\*|\/|\%
especial :|,|;
asignacion :=|=
logico o|y|no
booleano verdadero|falso
parentesis \(|\)|\[|\]
relacional <|>|<=|>=|==|<>
reservada estructura|inicio|fin|ent|rel|dreal|car|sin|num|id|def|si|entonces|sino|mientras|hacer|segun|escribir|leer|devolver|terminar|caso|pred|verdadero|falso|cadena|caracter
ID (({letra}|[_])({digito}|{letra}|[_]){0,31})
comentariomlinea "<*".*"*>"
%x comentariol
%x comentarioml

%%	
"--"	 BEGIN(comentariol);printf("<Comentario Línea, %s", yytext);
<comentariol>[^-\n]+	printf("%s", yytext);
<comentariol>\n 	printf(">\n");BEGIN(INITIAL);
"<*"	 BEGIN(comentarioml);printf("<Comentario M Línea, %s", yytext);
<comentarioml>[^*>]+	printf("%s", yytext);
<comentarioml>"*>" 	printf("%s>", yytext);

{comentariomlinea} {printf("<Comentario M Linea, %s>\n", yytext);}
{aritmetico} {printf("< ARITMETICO : %s > \n", yytext);}
{logico}+ {printf("< LOGICO : %s > \n", yytext);}
{relacional} {printf("< RELACIONAL : %s > \n", yytext);}
{asignacion} {printf("< ASIGNACION : %s > \n", yytext);}
{booleano} {printf("< BOOLEANO : %s > \n", yytext);}
{parentesis} {printf("< PARENTESIS : %s > \n", yytext);}
{reservada} {printf("< RESERVADA : %s > \n", yytext);}
{especial} {printf("< ESPECIAL : %s > \n", yytext);}

{entero} {printf("< ENTERO : %s > \n", yytext);}
{entero}"."{punto_flot} {printf("< FLOTANTE : %s > \n", yytext);}
{double} {printf("< DOUBLE : %s > \n", yytext);}
{ID} {printf("< IDENTIFICADOR : %s > \n", yytext);}
{espacio} {printf("< ESPACIOS : %s > \n", yytext);}
"//"[^\n]*   {printf("< COMENTARIO : %s > \n", yytext);}
"/*"[^"*/"]*   {printf("< COMENTARIO : %s > \n", yytext);}
"\""[^"\""]*  {printf("< COMENTARIO : %s > \n", yytext);}
%%

int main() {

	yylex();

}