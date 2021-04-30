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
#include "leitura_txt.h" 

int main(int argc, char *argv[]){

	int N = QuantProc(argv[1]) ;
	printf("\nNumero de processos = %d\n",N);//DEBUG
	processo *p;
	p = malloc(N*sizeof(processo));
	TxtRead(N,p,argv[1]);


	FCFS(N,p);
	/*for (int i=0;i<N;i++){ //DEBUG -  printando struct BCP
		printf("o nome do processo %i eh: %s\n",i,p[i].nome);
		printf("o burst do processo %i eh: %i\n",i,p[i].burst);
		printf("a prioridade do processo %i eh: %i\n\n",i,p[i].prioridade);
	}*/

	return 0;
}
