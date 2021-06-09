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
#include <semaphore.h>
sem_t S;

#include "type.h"

void red () {
  printf("\033[1;31m");
}

void blue () {
  printf("\033[0;34m");
}

void green () {
  printf("\033[0;32m");
}
void reset () {
  printf("\033[0m");
}

clock_t start;//inicio
double elapsed;//tempo relativo
#include "cpu.c"
#include "randomizador.h"


int main (int argc, char *argv[]){

	int N = -1;
	printf("\nQuantos processo? ");
	scanf("%d",&N);
	printf("\n\n");
	processo *p;
	p = malloc(N*sizeof(processo));
	randomize_process(N,p); //Povoar nosso ponteiro de processos da forma exigida.
	


	int escolha;
	printf("Escolha o escalonador desejado [1,2,3 ou 4]:\n 1 - Shortest Job First (SJF)\n 2 - First-Come First-Served(FCFS)\n 3 - Prioridade\n 4 - Round-Robin(RR)\n");
	scanf("%d", &escolha);
	printf("\n\n");


	sem_init(&S,1,1);//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

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

	error = pthread_create(&cpu1, NULL, CPU1, (void*) &thread_args1);
	if (error != 0){
		printf("Erro ao criar a thread cpu 1");
	}

	//THREAD: CPU2
	pthread_t cpu2;

	error = pthread_create(&cpu2, NULL, CPU2, (void*) &thread_args1);
	if (error != 0){
		printf("Erro ao criar a thread cpu 2");
	}
	
	//THREAD: IO
	pthread_t io;

	error = pthread_create(&io, NULL, IO, (void*) &thread_args1);
	if (error != 0){
		printf("Erro ao criar a thread IO");
	}

	
	//pthread_join(timer,NULL);
	pthread_join(cpu1,NULL);
	pthread_join(cpu2,NULL);
	pthread_join(io,NULL);

	//FECHAMENTO ESTATISTICAS
	printf("ESTATISTICAS:\n\n");
	for (int i=0;i<N;i++){//DEBUG
		printf("Tempo entrada na fila do pronto para o processo [ID=%d] eh: %d\n",p[i].ID,p[i].time_in);
		printf("Tempo de inicio de execucao para o processo [ID=%d] eh: %lf\n",p[i].ID,p[i].t_init);
		printf("Tempo de retorno para o processo [ID=%d] eh: %lf\n",p[i].ID,p[i].t_end);
	}

	if(escolha==1){
		FILE* arqNome = fopen("estatistica_SJF.txt","w");
		float media_retorno = 0;
		float media_espera = 0;
		for (int i=0;i<N;i++){
			fprintf(arqNome,"Tempo entrada na fila do pronto para o processo [ID=%d] eh: %d\n",p[i].ID,p[i].time_in);
			fprintf(arqNome,"Tempo de inicio de execucao para o processo [ID=%d] eh: %lf\n",p[i].ID,p[i].t_init);
			fprintf(arqNome,"Tempo de retorno para o processo [ID=%d] eh: %lf\n",p[i].ID,p[i].t_end);
			fprintf(arqNome,"CPU burst [ID=%d] eh: %d\n", p[i].ID, p[i].burst);
			media_retorno = media_retorno+(p[i].t_end-p[i].time_in);
			media_espera = media_espera+(p[i].t_init-p[i].time_in);	
		}
		media_retorno = media_retorno/N;
		media_espera = media_espera/N;
		fprintf(arqNome,"\n\nTempo medio de espera eh: %f\n",media_espera);
		fprintf(arqNome,"Tempo medio de retorno eh: %f\n",media_retorno);
		fclose(arqNome);
		free(p);
	}else if(escolha==2){
		FILE* arqNome = fopen("estatistica_FCFS.txt","w");
		float media_retorno = 0;
		float media_espera = 0;
		for (int i=0;i<N;i++){
			fprintf(arqNome,"Tempo entrada na fila do pronto para o processo [ID=%d] eh: %d\n",p[i].ID,p[i].time_in);
			fprintf(arqNome,"Tempo de inicio de execucao para o processo [ID=%d] eh: %lf\n",p[i].ID,p[i].t_init);
			fprintf(arqNome,"Tempo de retorno para o processo [ID=%d] eh: %lf\n",p[i].ID,p[i].t_end);
			fprintf(arqNome,"CPU burst [ID=%d] eh: %d\n", p[i].ID, p[i].burst);
			media_retorno = media_retorno+(p[i].t_end-p[i].time_in);
			media_espera = media_espera+(p[i].t_init-p[i].time_in);	
		}
		media_retorno = media_retorno/N;
		media_espera = media_espera/N;
		fprintf(arqNome,"\n\nTempo medio de espera eh: %f\n",media_espera);
		fprintf(arqNome,"Tempo medio de retorno eh: %f\n",media_retorno);
		fclose(arqNome);
		free(p);
	}else if(escolha==3){
		FILE* arqNome = fopen("estatistica_prioridade.txt","w");
		float media_retorno = 0;
		float media_espera = 0;
		for (int i=0;i<N;i++){
			fprintf(arqNome,"Tempo entrada na fila do pronto para o processo [ID=%d] eh: %d\n",p[i].ID,p[i].time_in);
			fprintf(arqNome,"Tempo de inicio de execucao para o processo [ID=%d] eh: %lf\n",p[i].ID,p[i].t_init);
			fprintf(arqNome,"Tempo de retorno para o processo [ID=%d] eh: %lf\n",p[i].ID,p[i].t_end);
			fprintf(arqNome,"CPU burst [ID=%d] eh: %d\n", p[i].ID, p[i].burst);
			media_retorno = media_retorno+(p[i].t_end-p[i].time_in);
			media_espera = media_espera+(p[i].t_init-p[i].time_in);	
		}
		media_retorno = media_retorno/N;
		media_espera = media_espera/N;
		fprintf(arqNome,"\n\nTempo medio de espera eh: %f\n",media_espera);
		fprintf(arqNome,"Tempo medio de retorno eh: %f\n",media_retorno);
		fclose(arqNome);
		free(p);
	}else if(escolha==4){
		FILE* arqNome = fopen("estatistica_RR.txt","w");
		float media_retorno = 0;
		float media_espera = 0;
		for (int i=0;i<N;i++){
			fprintf(arqNome,"Tempo entrada na fila do pronto para o processo [ID=%d] eh: %d\n",p[i].ID,p[i].time_in);
			fprintf(arqNome,"Tempo de inicio de execucao para o processo [ID=%d] eh: %lf\n",p[i].ID,p[i].t_init);
			fprintf(arqNome,"Tempo de retorno para o processo [ID=%d] eh: %lf\n",p[i].ID,p[i].t_end);
			fprintf(arqNome,"CPU burst [ID=%d] eh: %d\n", p[i].ID, p[i].burst);
			media_retorno = media_retorno+(p[i].t_end-p[i].time_in);
			media_espera = media_espera+(p[i].t_init-p[i].time_in);	
		}
		media_retorno = media_retorno/N;
		media_espera = media_espera/N;
		fprintf(arqNome,"\n\nTempo medio de espera eh: %f\n",media_espera);
		fprintf(arqNome,"Tempo medio de retorno eh: %f\n",media_retorno);
		fclose(arqNome);
		free(p);
	}
	
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
