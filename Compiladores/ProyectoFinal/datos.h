typedef struct tipobase{
	int is_est;
	union{
		int tipo;
	}tipo;
}TB;

typedef struct type TYP;
struct type{
	int id;
	char nombre[32];
	TB tb;
	int tam;
	TYP *next;
};

typedef struct type_tab TYPTAB;

struct type_tab{
	TYP *head;
	TYP *tail;
	int num;
	TYPTAB *next;
};

typedef struct typ_stack{
	TYPTAB *top;
	TYPTAB *tail;
}TSTACK;