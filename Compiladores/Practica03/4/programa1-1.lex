%{
	#include <stdio.h>	
%}

digito [0-9]
letra [a-zA-Z]
espacio [ \t\n]
esps {espacio}
letrahexa [a-fA-F]
/* Definiciones para números en hexadecimal */
s0 "0x"
s1 {s0}{digito}+
s2 {s0}{letrahexa}+
s4 {digito}*{letrahexa}*
s5 {s4}*
s6 {s1}{s5}
s7 {s2}{s5}
hexadecimal {s6}|{s7}
/* Definiciones para números decimales */
pto "."
n0 {digito}*
n1 {digito}+{pto}
n2 {n1}{n0}
n3 {pto}{digito}+
n4 {n0}{n3}
decimal {n2}|{n4}
/* Definiciones para identificadores */
guion "_"
id1 {letra}[a-zA-Z0-9]{1,32}
id2 {guion}[_a-zA-Z0-9]{1,32}
id3 {id1}{id2}
blanco " "

%%

{blanco}* {printf("Espacio en blanco %s\n", yytext);}
{hexadecimal} {printf("Número hexadecimal %s\n", yytext);}
{decimal} {printf("Número decimal %s\n", yytext);}
{digito}+ {printf("Encontre un número %s\n", yytext);}
{id3}|{id1}|{id2} {printf("Identificador %s\n", yytext);}
{letra}+ {printf("Encontre una palabra %s\n", yytext);}
{esps} {/*Ignorar los espacios en blanco.*/}
%%


int main(){
	yylex();
}