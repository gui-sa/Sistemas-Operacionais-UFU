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
//#include "SJF.h"
//#include "prioridade.h"
#include "leitura_txt.h"



void escalonador(int N, processo *p, int escolha){ 
	
	/*for (int i=0;i<N;i++){ //DEBUG
		printf("o tipo do processo [ID=%d] eh: ",p[i].ID);
		if(p[i].tipo=='c'){
			printf("CPU Bound\n");	
		}else{
			printf("I/O Bound\n");
		}
		printf("o burst do processo [ID=%d] eh: %d\n",p[i].ID,p[i].burst);
		printf("o tempo burst de cpu [ID=%d] eh: %f\n",p[i].ID, round(p[i].burst*p[i].cpu/100.0));
		printf("o tempo de entrada [ID=%d] eh: %d\n",p[i].ID,p[i].time_in);	
		printf("o status do processo [ID=%d] eh: ",p[i].ID);
		switch(p[i].status){
			case 'n':
			printf("NOVO\n");
			break;

			case 'p':
			printf("PRONTO\n");
			break;

			case 'e':
			printf("EXECUCAO\n");
			break;

			case 'b':
			printf("ESPERA\n");
			break;

			case 'f':
			printf("TERMINADO\n");
			break;

			default:
			break;

		}
	printf("\n\n");
	}//FINAL DO DEBUG*/


	/*for (int i=0;i<N;i++){// DEBUG DO TIMER 
		p[i].status = 'i';
	}

	clock_t start = clock();
	double elapsed = 0;
	clock_t current = clock();

	while(elapsed <= 10){
		current = clock();
	    	elapsed = (double)(current - start)/CLOCKS_PER_SEC;
		
		for(int i=0; i<N; i++){
		    if((p[i].time_in <= elapsed) & (p[i].status == 'i')){
		        printf("\n elapsed = %lf\n",elapsed);
		        p[i].status = 'n';
		        p[i].status = 'p';
		        printf("o tempo de entrada [ID=%d] eh: %d\n",p[i].ID,p[i].time_in);	
		        printf("o status do processo [ID=%d] eh: ",p[i].ID);
		        switch(p[i].status){
		            case 'n':
		                printf("NOVO\n");
		            break;

		            case 'p':
		                printf("PRONTO\n");
		            break;

		            case 'e':
		                printf("EXECUCAO\n");
		            break;

		            case 'b':
		                printf("ESPERA\n");
		            break;

		            case 'f':
		                printf("TERMINADO\n");
		            break;

		            default:
		            break;

		        }
		        printf("\n\n");
		    
		    }
		}
	}//FINAL DO DEBUG*/


	if (escolha==1){       
		//SJF(N,pointer);
	}
	else if (escolha==2){       
		//prioridadeNP(N,pointer);
	}
	else{
		printf("\nERRO: nao existe essa opcao.\n");
	}

}



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


	//THREAD: TIMER funcao que povoa o vetor pronto (i -> n) e (n -> p)
	//THREAD: CPU1
	//THREAD: CPU2	
	
	//escalonador(N,p,escolha);//NAO PODE TA AQUI!! --> CONSEQUENCIA // NAO EH UMA ACAO MAIS

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
