%{
	#include <stdio.h>
%}

digito [0-9]
letra [a-zA-Z]
espacio [ \t \n}]
esps {espacio}

%%

{esps} {/*Ignorar los espacios en blanco*/}
{digito}+ {printf("Encontre un numero %s \n", yytext);}
{letra}+ {printf("Encontre una palabra %s \n", yytext);}

%%
int main(){
	yylex();
}
