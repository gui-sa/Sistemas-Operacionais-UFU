/*
INTEGRANTES:
Nome: Eduardo Marques da Silva - Número: 11721EMT018
Nome: Enrico Sampaio Bonela - Número: 11721EMT007
Nome: Guilherme Salomao Agostini - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro - Número: 11721EMT004
*/

//#include <unistd.h>
#include "SJF.h"


void *CPU(void *thread_args2){
	while(1){
		//void *thread_args ==> int N e o processo *p)

		thread_args *thread_args1;
		thread_args1 = (thread_args*)thread_args2;

		int N = (int)thread_args1->Number;
		processo *p = (processo*)thread_args1->proc;
		int escolha = (int)thread_args1->esc;
		
		//============================================
		
		//percorrer a lista de pronto --> procurando por processos prontos
		int i;
		for (i = 0;i<N;i++){
			if(p[i].status == 'p'){
				break;
			}	
		}

		p[i].status = 'e';
		printf("\nprogresso [ID=%d]:%d/%d",p[i].ID, p[i].t_interrupt + 1, p[i].burst);
		p[i].t_interrupt++;
		sleep(1);
		p[i].status = 'p';		
		if( p[i].t_interrupt >= p[i].burst){
			p[i].status = 'f';
		}
		
		int count = 0;
		for (int z = 0;z<N;z++){
			if(p[i].status == 'f'){
			count++;
			}	
		}
		if(count == N){
			 break;
		}
		/* usar apenas um caractere (n)ovo, (p)ronto, (e)xecução, (b)loqueado, (f)inalizado , (i)nexistente.*/
	}

}

			/*p[i]->status = 'e';
			for ( int k=1; k<=p[i]->burst; k++){
				printf(" progresso [ID=%d]:%d/%d",p[i]->ID, k, p[i]->burst);
				for(int j=1; j<=k; j++) 
					printf("# ");
				for(int j=k+1; j<=p[i]->burst; j++) 
					printf("- ");
				printf("\n\a");
				sleep(1);
			}
			p->status = 'f';*/

void escalonador(int N, processo *p, int escolha){ 
	
	for (int i=0;i<N;i++){ //DEBUG
		if (p[i].status != 'i'){
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
				printf("'INEXISTENTE'\n");
				break;

			}
			printf("\n\n");
		}

	}//FINAL DO DEBUG*/
	printf("\n___________________________________________________________________________\n");

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
		SJF(N,p);
	}
	else if (escolha==2){       
		//prioridadeNP(N,p);
	}
	else{
		printf("\nERRO: nao existe essa opcao.\n");
	}

}





void *novo_processo(void *thread_args2){

	//void *thread_args ==> int N e o processo *p)

	thread_args *thread_args1;
	thread_args1 = (thread_args*)thread_args2;

	int N = (int)thread_args1->Number;
	processo *p = (processo*)thread_args1->proc;
	int escolha = (int)thread_args1->esc;
	
	//============================================

	clock_t start = clock();
	double elapsed = 0;
	clock_t current = clock();

	while(elapsed <= 10){
		current = clock();
		elapsed = (double)(current - start)/CLOCKS_PER_SEC;

		for(int i=0; i<N; i++){
			if((p[i].time_in <= elapsed) & (p[i].status == 'i')){
				//printf("\n elapsed = %lf\n",elapsed);//DEBUG
				p[i].status = 'n'; //(i -> n);
				p[i].status = 'p'; //(n -> p);
				escalonador(N,p,escolha); //Sempre que um processo entra, o status muda, e ele precisa ser reescalonado.
			}
		}
		
	}
}
