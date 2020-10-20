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
extern YYSTYPE yylval;
