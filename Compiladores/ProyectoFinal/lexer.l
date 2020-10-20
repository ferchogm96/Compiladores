%{
#include <stdio.h>
#include "y.tab.h"
#include <string.h>
extern void yyerror(char *s);
%}

%option yylineno

letra [a-zA-Z_]
caracter [a-zA-Z]
id {letra}({letra}|{digito})*{0,32}
entero {digito}+
esp [ \n \t\r]+
digito [0-9]
punto_flot [0-9]{0,6}
punto_dob [0-9]{0,16}
real {digito}*"."{punto_flot}
dreal {digito}*"."{punto_dob}
cadena [a-zA-Z_0-9 "#" "="]+

%%
"estructura" {return ESTRUCTURA;}
"inicio" {return  INICIO;}
"fin" {return FIN;}
"ent" {return ENT;}
"real" {return REAL;}
"dreal" {return DREAL;}
"car" {return CAR;}
"sin" {return SIN;}
"cadena" {return CADENA;}
		
"def" {return DEF;}
"si" {return SI;}
"entonces" {return ENTONCES;}
"sino" {return SINO;}
"mientras" {return MIENTRAS;}
"hacer" {return HACER;}
"segun" {return SEGUN;}
"escribir" {return ESCRIBIR;}
"leer" {return LEER;}
"devolver" {return DEVOLVER;}
";"  {return PYC;}
"," {return COMA;}
"terminar" {return TERMINAR;}
"caso" {return CASO;}
":" {return DOSPUN;}
"pred" {return PRED;}
"o" {return O;}
"y" {return  Y;}
"no" {return NO;}

"."  {return PUNTO;}
">" {return MAQ;}
"<" {return MEQ;}
"<=" {return MEI;}
">=" {return MAI;}
"<>" {return DOSMAME;}
"=" {return IGUAL;}
":=" {return ASIGNACION;}
"+" {return MAS;}
"-" {return MEN;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}

"verdadero" {return VERDADERO;}
"falso" { return FALSO;}

"(" {return LPAR;}
")" {return RPAR;}

"[" {return LCOR;}
"]" {return RCOR;}

{entero} {	
			yylval.numero.tipo = 0;
			strcpy(yylval.numero.numeroCaracter, yytext);
			return NUM;}
{real} {
		yylval.numero.tipo = 1;
		strcpy(yylval.numero.numeroCaracter, yytext);
		return NUM;}
{dreal} {
		yylval.numero.tipo = 2;
		strcpy(yylval.numero.numeroCaracter, yytext);
		return NUM;}

{caracter} {
			yylval.numero.tipo = 3;
			strcpy(yylval.numero.numeroCaracter, yytext);
			return CARACTER;}
{esp} {}

{id} {
		strcpy(yylval.id, yytext);
		return ID;}




. { yyerror("Error lexico ");}

%%

int yywrap(){
	return 1;
}