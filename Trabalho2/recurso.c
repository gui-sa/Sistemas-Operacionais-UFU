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
#include <math.h>
#include <time.h> 
#include <pthread.h>
#include "type.h"
#include "cpu.c"
//#include "prioridade.h"
#include "leitura_txt.h"




int main (int argc, char *argv[]){

	int N = -1;
	printf("\nQuantos processo? ");
	scanf("%d",&N);
	printf("\n\n");
	processo *p;
	p = malloc(N*sizeof(processo));
	randomize_process(N,p); //Povoar nosso ponteiro de processos da forma exigida.
	


	int escolha;
	printf("Escolha o escalonador desejado [1] ou [2]:\n 1 - Shortest Job First (SJF)\n 2 - Round-Robin(RR)\n");
	scanf("%d", &escolha);
	printf("\n\n");



	
	int error;
	thread_args thread_args1;
	thread_args1.Number = N;
	thread_args1.proc = p;
	thread_args1.esc = escolha;

	//THREAD: TIMER funcao que povoa o vetor pronto (i -> n) e (n -> p)
	
	pthread_t timer;

	error = pthread_create(&timer, NULL, novo_processo, (void*) &thread_args1);
	if (error != 0){
		printf("Erro ao criar a thread timer");
	}
	

	//THREAD: CPU1
	pthread_t cpu1;

	error = pthread_create(&cpu1, NULL, CPU, (void*) &thread_args1);
	if (error != 0){
		printf("Erro ao criar a thread cpu 1");
	}

	//THREAD: CPU2	
	
	//pthread_join(timer,NULL);
	pthread_join(cpu1,NULL);

	//FECHAMENTO ESTATISTICAS

	return 0;
}  

    

/*

  --> p 
  -->SE FOR I/O -- CPU: de p -> b
  [ i, i, i, i, i, i, i, i]
  -->Se for b -- I/O b -> be , ao finalizar o percentual i/o -> be para p e trocar tipo para cpu.bound


-------------------------------------- Ideia B ------------------------------------------------------
  
  [ p p p p p p p p] CPU1/CPU2 = sincronizacao
    | $$ funcao atualizacao de listas  -- entrar na sincronizacao $$
    |
    v
  [ f ] I/O

	PROBLEMAS AO TRABALHAR COM VARIOS VETORES
	>>PROBLEMAS: INTEGRIDADE


*/


/*
COMPILACAO COM GCC
>>gcc -pthread -o recurso recurso.c -lm

*/
