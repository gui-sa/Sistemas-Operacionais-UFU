/*
INTEGRANTES:
Nome: Eduardo Marques da Silva - Número: 11721EMT018
Nome: Enrico Sampaio Bonela - Número: 11721EMT007
Nome: Guilherme Salomao Agostini - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro - Número: 11721EMT004
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "type.h"
#include "cpu.c"
#include "FCFS.h"
#include "prioridade.h"
#include "leitura_txt.h"



void escalonador(int N, processo *pointer, int escolha){ 
	/*
	for (int i=0;i<N;i++){ //DEBUG -  printando struct BCP
		printf("o nome do processo %i eh: %s\n",i,pointer[i].nome);
		printf("o burst do processo %i eh: %i\n",i,pointer[i].burst);
		printf("a prioridade do processo %i eh: %i\n\n",i,pointer[i].prioridade);
	}*/

	if (escolha==1){       
		FCFS(N,pointer);
	}
	else if (escolha==2){       
		prioridadeNP(N,pointer);
	}
	else{
		printf("\nERRO: nao existe essa opcao.\n");
	}

}


int main (int argc, char *argv[]){


	int N = QuantProc("tarefas.txt") ;
	printf("\nN = %d\n",N);//DEBUG
	processo *p;
	p = malloc(N*sizeof(processo));
	TxtRead(N, p, "tarefas.txt");



	int escolha;
	printf("Escolha o escalonador desejado [1] ou [2]:\n 1 - First Come First Served (FCFS)\n 2 - Prioridade Não-Preemptivo\n");
	scanf("%d", &escolha);

	escalonador(N,p,escolha);

	/*   for (int i=0;i<N;i++){ //DEBUG -  printando struct BCP
	printf("o nome do processo %i eh: %s\n",i,p[i].nome);
	printf("o burst do processo %i eh: %i\n",i,p[i].burst);
	printf("a prioridade do processo %i eh: %i\n\n",i,p[i].prioridade);
	}*/

	return 0;
}  

    
