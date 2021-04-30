/*
INTEGRANTES:
Nome: Eduardo Marques da Silva          - Número: 11721EMT018
Nome: Enrico Sampaio Bonela             - Número: 11721EMT007
Nome: Guilherme Salomao Agostini        - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro    - Número: 11721EMT004
*/

#define TAM_NOME 3      // Tamanho do nome do processo -> |T|#|\0|

struct BCP{
    char nome [TAM_NOME];
    unsigned int burst;
    unsigned int prioridade;
    unsigned int ID;
    char status;        // Usar apenas um caractere: (n)ovo, (p)ronto, (e)xecução, (b)loqueado, (f)inalizado.
};

typedef struct BCP processo;


struct statistics{
	unsigned int ID ;
	unsigned int t_enter;
	unsigned int t_init;
	unsigned int t_end;
};

typedef struct statistics estatistica;

