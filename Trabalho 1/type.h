#define TAM_NOME 3 //tamanho do nome do processo

struct BCP{
	char nome [TAM_NOME];
	unsigned int burst;
	unsigned int prioridade;
	unsigned int ID;
	char status; /* usar apenas um caractere (n)ovo, (p)ronto, (e)xecução, (b)loqueado, (f)inalizado.*/
};

typedef struct BCP processo;


struct statistics{
	unsigned int ID ;
	unsigned int t_enter;
	unsigned int t_init;
	unsigned int t_end;
};

typedef struct statistics estatistica;

