/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parse1.y"
#include <stdio.h>	
#include <string.h>	
#include <stdlib.h> 
#include <stdbool.h>
#include "tabla_simbolos.h"
#include "tabla_tipo.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(char *s);
int posicionTablaTipo;
int tipoGBL = 0;
int baseGBL;
int tipoDirGBL;
int dirGBL;
int dirGeneral = 0;

int valorArreglo = 4;

int idST = 0;

TSTACK *stackTipos;

SYMTAB generalSimbolos;

TYPTAB *generalTipos;

void iniciarStacks();
#line 32 "parse1.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
    struct{
    int tipo;
    char numeroCaracter[32];
    }numero;

    struct{
    int tipo;
    char numeroCaracter[32];
    }expresion;
 
    char id[32];
    int base;
    int tipo_registro;
    int arreglo;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 76 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ESTRUCTURA 257
#define INICIO 258
#define ENT 259
#define REAL 260
#define DREAL 261
#define CAR 262
#define SIN 263
#define NUM 264
#define ID 265
#define DEF 266
#define SI 267
#define MIENTRAS 268
#define HACER 269
#define SEGUN 270
#define ESCRIBIR 271
#define LEER 272
#define DEVOLVER 273
#define PYC 274
#define COMA 275
#define TERMINAR 276
#define CASO 277
#define DOSPUN 278
#define ENTONCES 279
#define PRED 280
#define O 281
#define Y 282
#define NO 283
#define VERDADERO 284
#define FALSO 285
#define CADENA 286
#define CARACTER 287
#define PUNTO 288
#define MAQ 289
#define MEQ 290
#define MEI 291
#define MAI 292
#define DOSMAME 293
#define IGUAL 294
#define NL 295
#define ASIGNACION 296
#define MAS 297
#define MEN 298
#define MUL 299
#define DIV 300
#define MOD 301
#define LPAR 302
#define RPAR 303
#define LCOR 304
#define RCOR 305
#define FIN 306
#define SINO 307
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    4,    0,    3,    3,    3,    8,   10,    6,    1,    1,
    1,    1,    1,    9,    9,    7,    7,    5,    5,   11,
   11,   13,   13,   14,   16,    2,   15,   15,   12,   12,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   20,   20,   21,   21,   18,   18,   18,   18,   18,
   18,   23,   23,   23,   23,   23,   23,   23,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   25,   19,
   24,   24,   24,   26,   26,   27,   27,   28,   28,   29,
   29,
};
static const YYINT yylen[] = {                            2,
    0,    3,    4,    4,    0,    4,    0,    3,    1,    1,
    1,    1,    1,    4,    0,    3,    1,   11,    0,    1,
    1,    3,    1,    2,    0,    3,    3,    0,    2,    1,
    4,    7,    5,    5,    8,    4,    3,    3,    2,    3,
    2,    5,    4,    3,    0,    3,    3,    2,    1,    1,
    1,    3,    3,    3,    3,    3,    3,    1,    3,    3,
    3,    3,    3,    3,    1,    1,    1,    1,    0,    3,
    1,    1,    3,    3,    0,    3,    4,    1,    0,    3,
    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,    9,   10,   11,   12,   13,    7,    0,
    0,    0,    0,    0,    0,    2,   17,    0,    0,    0,
    0,    8,    0,    0,    0,    0,    6,    0,    0,    3,
   16,    4,    0,    0,   14,    0,   25,    0,    0,    0,
   23,    0,   24,    0,    0,    0,   26,    0,   22,    0,
    0,   27,   69,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   30,    0,    0,   66,    0,   50,   51,   67,
   68,    0,    0,   65,    0,    0,    0,    0,    0,    0,
    0,   39,    0,   41,    0,   29,    0,    0,    0,   70,
    0,    0,   48,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   37,   38,   40,   18,    0,    0,    0,    0,    0,
    0,    0,   64,    0,    0,   47,    0,    0,    0,    0,
   63,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   36,   73,    0,   76,   74,    0,    0,   33,   34,    0,
    0,   77,    0,    0,    0,   32,    0,    0,    0,    0,
    0,   35,    0,   44,   42,
};
static const YYINT yydgoto[] = {                          1,
    9,   38,   10,    2,   16,   11,   18,   12,   22,   14,
   39,   62,   40,   41,   47,   42,   63,   73,   74,  155,
  159,   75,   76,   90,   65,   91,   92,  118,  119,
};
static const YYINT yysindex[] = {                         0,
    0,  245, -221,    0,    0,    0,    0,    0,    0, -217,
 -193, -193,  245, -247,  -22,    0,    0, -208, -174, -224,
 -167,    0, -160,  245, -143,  245,    0, -181, -172,    0,
    0,    0, -247,  200,    0,    0,    0, -134, -169, -137,
    0, -153,    0, -100,  -22, -140,    0,  245,    0, -153,
  199,    0,    0, -194, -194,  199, -138, -200,  -98, -161,
  -99, -238,    0, -114, -111,    0, -194,    0,    0,    0,
    0, -200, -108,    0,  219,  -86, -263,  -68,  -98, -180,
  -59,    0,  -38,    0, -217,    0, -200, -200, -200,    0,
  -64,  -78,    0,  212,  199, -194, -194, -200, -200, -200,
 -200, -200, -200, -200, -200, -200, -200, -200,  199, -194,
  -74,    0,    0,    0,    0,   56,  219,  -73,  -44,  189,
  -32, -200,    0,  -58,  -34,    0, -297, -297,  -46,  -46,
    0,  231, -271,  -96, -178,  -40,  -40,  -42, -175,  -12,
    0,    0, -200,    0,    0,  198,  199,    0,    0,   -1,
  219,    0,  -28,   15,  -15,    0,    3,    4,  -23,  199,
  199,    0,   -1,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    9,    0,    0,    0,    0,    0,    0,    0,  284,
    0,    0,  -19,   23,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    1,    0,    1,    0,    0,    0,    0,
    0,    0,   23,    0,    0, -240,    0,    0,    0,  -14,
    0,   26,    0,    0,    0,    0,    0,  209,    0,   26,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -146,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   97, -142,    0,    0,    0,    0,
    0,    0,    0,    0,  284,    0,    0,   10,    0,    0,
 -113,  -80,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -260,    0,   12,    0,
    0,    0,    0, -192, -109,    0,   43,   70,  -47,   11,
    0,  176,  159,  153,  134,  103,  128,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -258,    0,    0,    0,   13,    0,    0,    0,    0,    0,
    0,    0, -264,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    2,    0,   35,    0,  221,  305,  309,    0,  290,    0,
    0,    0,    0,  281,  277,    0,  -49,  -41,  -51,  165,
    0,  -48,  191,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 525
static const YYINT yytable[] = {                         64,
    5,  100,  101,  102,   64,  109,   78,   81,    5,   80,
   64,   83,   86,   77,   81,   43,   80,   96,   97,  105,
  106,  107,  108,   94,   13,   93,   53,  111,   54,   55,
   56,   57,   58,   59,   60,   37,   13,   61,  116,  117,
  120,   43,   81,   64,   80,  124,   37,   20,   15,  127,
  128,  129,  130,  131,  125,  126,   21,   64,   30,  138,
   32,   13,   21,   66,   53,   24,   25,   85,  139,   66,
   53,   17,   31,  146,   31,   31,   31,   31,   31,   31,
   31,   27,   51,   31,   31,   70,   71,   31,   67,   68,
   69,   70,   71,  112,  151,   64,   28,  153,  149,   26,
   25,   72,   66,   53,   29,   96,   97,   72,   64,   64,
  163,  164,   82,   31,  107,  108,   98,   99,  100,  101,
  102,   31,   75,   33,   70,   71,   49,   75,   75,   34,
   43,   49,   75,   44,   75,   75,   49,   45,   49,   49,
   72,   75,   75,   75,   75,   75,   75,   75,   46,   75,
   75,   75,   75,   75,   75,   71,   75,   48,   75,   46,
   71,   71,   50,   79,   46,   71,   53,   71,   71,   46,
   95,   46,   96,   97,   84,   71,   71,   71,   71,   71,
   71,   87,   71,   71,   71,   71,   71,   71,   72,   71,
   88,   71,   89,   72,   72,  106,  107,  108,   72,  110,
   72,   72,  103,  104,  105,  106,  107,  108,   72,   72,
   72,   72,   72,   72,  113,   72,   72,   72,   72,   72,
   72,   61,   72,  121,   72,  122,   61,   61,  140,  142,
  143,   61,  145,   61,   61,  114,    4,    5,    6,    7,
    8,   61,   61,   61,   61,   61,   61,   97,  147,   61,
   61,   61,   61,  108,  102,   61,  150,   61,   98,   99,
  100,  101,  102,  148,  158,    5,    5,    5,    5,    5,
    5,    5,    5,    5,    5,  154,    5,  156,  157,   62,
  160,  161,  162,   19,   62,   62,    5,   15,   20,   62,
   28,   62,   62,  132,  133,  134,  135,  136,  137,   62,
   62,   62,   62,   62,   62,  115,    5,   62,   62,   62,
   62,   59,   79,   62,   78,   62,   59,   59,   45,   23,
   19,   59,   35,   59,   59,   49,   52,  165,    0,  141,
    0,   59,   59,   59,   59,   59,   59,    0,   60,   59,
   59,    0,    0,   60,   60,   59,    0,   59,   60,    0,
   60,   60,   98,   99,  100,  101,  102,    0,   60,   60,
   60,   60,   60,   60,    0,   58,   60,   60,    0,    0,
   58,   53,   60,    0,   60,   58,   53,   58,   58,    0,
    0,   53,    0,   53,   53,   58,   58,   58,   58,   58,
   58,   53,   53,   53,   53,   53,   52,    0,    0,    0,
    0,   52,   57,    0,    0,    0,   52,   57,   52,   52,
    0,    0,   57,    0,   57,   57,   52,   52,   52,   52,
   52,   56,   57,   57,   57,   57,   56,   55,    0,    0,
    0,   56,   55,   56,   56,    0,    0,   55,    0,   55,
   55,   56,   56,   56,   54,    0,    0,   55,   55,   54,
    0,    0,    0,    0,   54,    0,   54,   54,    4,    5,
    6,    7,   36,   53,   54,   54,   55,   56,   57,   58,
   59,   60,    0,    5,   61,    5,    5,    5,    5,    5,
    5,    5,    0,    0,    5,   98,   99,  100,  101,  102,
    0,    0,    0,  144,   98,   99,  100,  101,  102,    0,
    0,    3,  152,    4,    5,    6,    7,    8,   98,   99,
  100,  101,  102,    0,  123,   98,   99,  100,  101,  102,
  104,  105,  106,  107,  108,
};
static const YYINT yycheck[] = {                         51,
    0,  299,  300,  301,   56,  269,   56,   59,    0,   58,
   62,   60,   62,   55,  275,  280,  275,  281,  282,  291,
  292,  293,  294,   72,  265,   67,  265,   79,  267,  268,
  269,  270,  271,  272,  273,   34,  258,  276,   87,   88,
   89,  306,  303,   95,  303,   95,   45,   13,  266,   98,
   99,  100,  101,  102,   96,   97,  304,  109,   24,  109,
   26,  302,  303,  264,  265,  274,  275,  306,  110,  264,
  265,  265,  265,  122,  267,  268,  269,  270,  271,  272,
  273,  306,   48,  276,  277,  286,  287,  280,  283,  284,
  285,  286,  287,  274,  143,  147,  264,  147,  274,  274,
  275,  302,  264,  265,  265,  281,  282,  302,  160,  161,
  160,  161,  274,  306,  293,  294,  297,  298,  299,  300,
  301,  265,  269,  305,  286,  287,  269,  274,  275,  302,
  265,  274,  279,  303,  281,  282,  279,  275,  281,  282,
  302,  288,  289,  290,  291,  292,  293,  294,  302,  296,
  297,  298,  299,  300,  301,  269,  303,  258,  305,  269,
  274,  275,  303,  302,  274,  279,  265,  281,  282,  279,
  279,  281,  281,  282,  274,  289,  290,  291,  292,  293,
  294,  296,  296,  297,  298,  299,  300,  301,  269,  303,
  302,  305,  304,  274,  275,  292,  293,  294,  279,  268,
  281,  282,  289,  290,  291,  292,  293,  294,  289,  290,
  291,  292,  293,  294,  274,  296,  297,  298,  299,  300,
  301,  269,  303,  288,  305,  304,  274,  275,  303,  303,
  275,  279,  265,  281,  282,  274,  259,  260,  261,  262,
  263,  289,  290,  291,  292,  293,  294,  282,  307,  297,
  298,  299,  300,  294,  301,  303,  269,  305,  297,  298,
  299,  300,  301,  306,  280,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  266,  277,  276,  306,  264,  269,
  278,  278,  306,    0,  274,  275,  306,  265,  303,  279,
  265,  281,  282,  103,  104,  105,  106,  107,  108,  289,
  290,  291,  292,  293,  294,   85,  306,  297,  298,  299,
  300,  269,  303,  303,  303,  305,  274,  275,  306,   15,
   12,  279,   33,  281,  282,   45,   50,  163,   -1,  274,
   -1,  289,  290,  291,  292,  293,  294,   -1,  269,  297,
  298,   -1,   -1,  274,  275,  303,   -1,  305,  279,   -1,
  281,  282,  297,  298,  299,  300,  301,   -1,  289,  290,
  291,  292,  293,  294,   -1,  269,  297,  298,   -1,   -1,
  274,  269,  303,   -1,  305,  279,  274,  281,  282,   -1,
   -1,  279,   -1,  281,  282,  289,  290,  291,  292,  293,
  294,  289,  290,  291,  292,  293,  269,   -1,   -1,   -1,
   -1,  274,  269,   -1,   -1,   -1,  279,  274,  281,  282,
   -1,   -1,  279,   -1,  281,  282,  289,  290,  291,  292,
  293,  269,  289,  290,  291,  292,  274,  269,   -1,   -1,
   -1,  279,  274,  281,  282,   -1,   -1,  279,   -1,  281,
  282,  289,  290,  291,  269,   -1,   -1,  289,  290,  274,
   -1,   -1,   -1,   -1,  279,   -1,  281,  282,  259,  260,
  261,  262,  263,  265,  289,  267,  268,  269,  270,  271,
  272,  273,   -1,  265,  276,  267,  268,  269,  270,  271,
  272,  273,   -1,   -1,  276,  297,  298,  299,  300,  301,
   -1,   -1,   -1,  305,  297,  298,  299,  300,  301,   -1,
   -1,  257,  305,  259,  260,  261,  262,  263,  297,  298,
  299,  300,  301,   -1,  303,  297,  298,  299,  300,  301,
  290,  291,  292,  293,  294,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 307
#define YYUNDFTOKEN 339
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ESTRUCTURA","INICIO","ENT",
"REAL","DREAL","CAR","SIN","NUM","ID","DEF","SI","MIENTRAS","HACER","SEGUN",
"ESCRIBIR","LEER","DEVOLVER","PYC","COMA","TERMINAR","CASO","DOSPUN","ENTONCES",
"PRED","O","Y","NO","VERDADERO","FALSO","CADENA","CARACTER","PUNTO","MAQ","MEQ",
"MEI","MAI","DOSMAME","IGUAL","NL","ASIGNACION","MAS","MEN","MUL","DIV","MOD",
"LPAR","RPAR","LCOR","RCOR","FIN","SINO",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"$$1 :",
"programa : $$1 declaraciones funciones",
"declaraciones : tipo lista_var PYC declaraciones",
"declaraciones : tipo_registro lista_var PYC declaraciones",
"declaraciones :",
"tipo_registro : ESTRUCTURA INICIO declaraciones FIN",
"$$2 :",
"tipo : base $$2 tipo_arreglo",
"base : ENT",
"base : REAL",
"base : DREAL",
"base : CAR",
"base : SIN",
"tipo_arreglo : LCOR NUM RCOR tipo_arreglo",
"tipo_arreglo :",
"lista_var : lista_var COMA ID",
"lista_var : ID",
"funciones : DEF tipo ID LPAR argumentos RPAR INICIO declaraciones sentencias FIN funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg : tipo_arg ID",
"$$3 :",
"tipo_arg : base $$3 param_arr",
"param_arr : LPAR RPAR param_arr",
"param_arr :",
"sentencias : sentencias sentencia",
"sentencias : sentencia",
"sentencia : SI e_bool ENTONCES sentencia",
"sentencia : SI e_bool ENTONCES sentencia SINO sentencia FIN",
"sentencia : MIENTRAS e_bool HACER sentencia FIN",
"sentencia : HACER sentencia MIENTRAS e_bool PYC",
"sentencia : SEGUN LPAR variable RPAR HACER casos predeterminado FIN",
"sentencia : variable ASIGNACION expresion PYC",
"sentencia : ESCRIBIR expresion PYC",
"sentencia : LEER variable PYC",
"sentencia : DEVOLVER PYC",
"sentencia : DEVOLVER expresion PYC",
"sentencia : TERMINAR PYC",
"casos : CASO NUM DOSPUN sentencia casos",
"casos : CASO NUM DOSPUN sentencia",
"predeterminado : PRED DOSPUN sentencia",
"predeterminado :",
"e_bool : e_bool O e_bool",
"e_bool : e_bool Y e_bool",
"e_bool : NO e_bool",
"e_bool : relacional",
"e_bool : VERDADERO",
"e_bool : FALSO",
"relacional : relacional IGUAL relacional",
"relacional : relacional DOSMAME relacional",
"relacional : relacional MAQ relacional",
"relacional : relacional MEQ relacional",
"relacional : relacional MEI relacional",
"relacional : relacional MAI relacional",
"relacional : expresion",
"expresion : expresion MAS expresion",
"expresion : expresion MEN expresion",
"expresion : expresion MUL expresion",
"expresion : expresion DIV expresion",
"expresion : expresion MOD expresion",
"expresion : LPAR expresion RPAR",
"expresion : variable",
"expresion : NUM",
"expresion : CADENA",
"expresion : CARACTER",
"$$4 :",
"variable : ID $$4 variable_comp",
"variable_comp : dato_est_sim",
"variable_comp : arreglo",
"variable_comp : LPAR parametros RPAR",
"dato_est_sim : dato_est_sim PUNTO ID",
"dato_est_sim :",
"arreglo : LCOR expresion RCOR",
"arreglo : arreglo LCOR expresion RCOR",
"parametros : lista_param",
"parametros :",
"lista_param : lista_param COMA expresion",
"lista_param : expresion",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 253 "parse1.y"

void yyerror(char *s){
	printf("%s, linea: %d en el token: %s \n",s, yylineno, yytext);
}

void iniciarStacks(){
	
	
	
	stackTipos  = init_type_tab_stack();

	generalTipos = init_type_tab();

	TYP *tipo0 = init_type();
	tipo0->id = 0;
	strcpy(tipo0->nombre, "ent");
	tipo0->tam = 4;
	
	TYP *tipo1 = init_type();
	tipo1->id = 1;
	strcpy(tipo1->nombre, "real");
	tipo1->tam = 4;
	
	TYP *tipo2 = init_type();
	tipo2->id = 2;
	strcpy(tipo2->nombre, "dreal");
	tipo2->tam = 8;
	
	TYP *tipo3 = init_type();
	tipo3->id = 3;
	strcpy(tipo3->nombre, "char");
	tipo3->tam = 1;

	TYP *tipo4 = init_type();
	tipo4->id = 4;
	strcpy(tipo4->nombre, "sin");
	tipo4->tam = 0;
	
	posicionTablaTipo = tipo4->id;


	append_type(generalTipos, tipo0);
	append_type(generalTipos, tipo1);
	append_type(generalTipos, tipo2);
	append_type(generalTipos, tipo3);
	append_type(generalTipos, tipo4);
	
	push_tst(stackTipos, generalTipos);

	
	


}





#line 566 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 105 "parse1.y"
	{
				iniciarStacks();
				imprimir(&generalSimbolos);
				
			}
break;
case 7:
#line 117 "parse1.y"
	{dirGBL = yystack.l_mark[0].base;}
break;
case 9:
#line 119 "parse1.y"
	{yyval.base = 0;}
break;
case 10:
#line 119 "parse1.y"
	{yyval.base = 1;}
break;
case 11:
#line 119 "parse1.y"
	{yyval.base = 2;}
break;
case 12:
#line 119 "parse1.y"
	{yyval.base = 3;}
break;
case 13:
#line 119 "parse1.y"
	{yyval.base = 4;}
break;
case 14:
#line 122 "parse1.y"
	{	
					
					if(yystack.l_mark[-2].numero.tipo == 0){
						TYP *tipo4 = init_type();
						tipo4->id = posicionTablaTipo + 1;
						strcpy(tipo4->nombre, "array");
						tipo4->tam =  valorArreglo * atoi(yystack.l_mark[-2].numero.numeroCaracter);
						valorArreglo = tipo4->tam;
						posicionTablaTipo = tipo4->id;

						append_type(generalTipos, tipo4);

						pop_tst(stackTipos);
						
						push_tst(stackTipos, generalTipos);

						print_tstack(stackTipos);

					}else{
					yyerror("El numero del arreglo no es compatible");
					}
					
				}
break;
case 16:
#line 147 "parse1.y"
	{	printf("viola 1 aqui\n");
										printf("El id es: %s\n", yystack.l_mark[0].id);
							  }
break;
case 17:
#line 150 "parse1.y"
	{
										if(!getID(&generalSimbolos, yystack.l_mark[0].id)){
					                    	SYM s;
								            strcpy(s.id, yystack.l_mark[0].id);
								            s.tipo = tipoGBL;
								            s.dir = dirGeneral;
								            dirGeneral+= dirGBL;
								            insertar(&generalSimbolos, s);
										}
								}
break;
case 25:
#line 172 "parse1.y"
	{yyval.base = yystack.l_mark[0].base;}
break;
case 66:
#line 218 "parse1.y"
	{
			printf("El valor de num es:%s y tipo %d\n", yystack.l_mark[0].numero.numeroCaracter, yystack.l_mark[0].numero.tipo);}
break;
case 68:
#line 221 "parse1.y"
	{
				printf("El valor de caracter es:%s y tipo %d\n", yystack.l_mark[0].numero.numeroCaracter, yystack.l_mark[0].numero.tipo);}
break;
case 69:
#line 225 "parse1.y"
	{
										if(!getID(&generalSimbolos, yystack.l_mark[0].id)){
					                    	yyerror("El id no fue declarado");
										}
								}
break;
case 74:
#line 235 "parse1.y"
	{
										if(!getID(&generalSimbolos, yystack.l_mark[0].id)){
					                    	yyerror("El id no fue declarado");
										}
								}
break;
#line 875 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
