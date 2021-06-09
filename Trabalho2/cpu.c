/*
INTEGRANTES:
Nome: Eduardo Marques da Silva - Número: 11721EMT018
Nome: Enrico Sampaio Bonela - Número: 11721EMT007
Nome: Guilherme Salomao Agostini - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro - Número: 11721EMT004
*/

//#include <unistd.h>
#include "SJF.h"


void *CPU1(void *thread_args2){
	while(1){
		//void *thread_args ==> int N e o processo *p)
		sem_wait(&S);
		red();
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
		int check = 0;
		if(i!=N){
			if(p[i].t_interrupt==0){
				p[i].t_init=(double)(clock() - start)/CLOCKS_PER_SEC;	
			}
			p[i].status = 'e';
			p[i].t_interrupt++;
			printf("\nprogresso [ID=%d]:%d/%d",p[i].ID, p[i].t_interrupt, p[i].burst);
			check = p[i].ID;
			sem_post(&S);
			sleep(1);
			sem_wait(&S);
			if( check != p[i].ID){
				for (int y =0; y < N; y++){
					if(p[y].ID == check){
						i=y;
						break;
					}				
				}
			}
			red();
			p[i].status = 'p';		
			if( p[i].t_interrupt >= round(p[i].burst*p[i].cpu/100.0)){
				p[i].status = 'b';
			}
			if( p[i].t_interrupt >= p[i].burst){
				p[i].status = 'f';
				p[i].t_end=(double)(clock() - start)/CLOCKS_PER_SEC;
			}
		}
		
		
		int count = 0;
		for (int z = 0;z<N;z++){
			if(p[z].status == 'f'){
				count++;
			}	
		}

		sem_post(&S);
		reset();

		if(count == N){
			 printf("\n");
			 break;
		}	
		
		/* usar apenas um caractere (n)ovo, (p)ronto, (e)xecução, (b)loqueado, (f)inalizado , (i)nexistente.*/
	}

}

void *CPU2(void *thread_args2){
	while(1){
		//void *thread_args ==> int N e o processo *p)
		sem_wait(&S);
		blue();
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
		int check = 0;
		if(i!=N){
			if(p[i].t_interrupt==0){
				p[i].t_init=(double)(clock() - start)/CLOCKS_PER_SEC;	
			}
			p[i].status = 'e';
			p[i].t_interrupt++;
			printf("\nprogresso [ID=%d]:%d/%d",p[i].ID, p[i].t_interrupt, p[i].burst);
			check = p[i].ID;
			sem_post(&S);
			sleep(1);
			sem_wait(&S);
			if( check != p[i].ID){
				for (int y =0; y < N; y++){
					if(p[y].ID == check){
						i=y;
						break;
					}				
				}
			}
			blue();
			p[i].status = 'p';		
			if( p[i].t_interrupt >= round(p[i].burst*p[i].cpu/100.0)){
				p[i].status = 'b';
			}
			if( p[i].t_interrupt >= p[i].burst){
				p[i].status = 'f';
				p[i].t_end=(double)(clock() - start)/CLOCKS_PER_SEC;
			}
		}
		
		
		int count = 0;
		for (int z = 0;z<N;z++){
			if(p[z].status == 'f'){
				count++;
			}	
		}

		sem_post(&S);
		reset();

		//printf("\n%d",count);
		if(count == N){
			 printf("\n");
			 break;
		}
		
		
		/* usar apenas um caractere (n)ovo, (p)ronto, (e)xecução, (b)loqueado, (f)inalizado , (i)nexistente.*/
	}

}

void *IO(void *thread_args2){
	while(1){
		//void *thread_args ==> int N e o processo *p)
		sem_wait(&S);
		green();
		thread_args *thread_args1;
		thread_args1 = (thread_args*)thread_args2;

		int N = (int)thread_args1->Number;
		processo *p = (processo*)thread_args1->proc;
		int escolha = (int)thread_args1->esc;
		
		//============================================
		
		//percorrer a lista de pronto --> procurando por processos prontos
		int i;
		for (i = 0;i<N;i++){
			if(p[i].status == 'b'){
				break;
			}	
		}
		int check = 0;
		if(i!=N){
			p[i].status = 'e';
			p[i].t_interrupt++;
			green();
			printf("\nprogresso [ID=%d]:%d/%d",p[i].ID, p[i].t_interrupt, p[i].burst);
			check = p[i].ID;
			sem_post(&S);
			sleep(1);
			sem_wait(&S);
			if( check != p[i].ID){
				for (int y =0; y < N; y++){
					if(p[y].ID == check){
						i=y;
						break;
					}				
				}
			}
			green();
			p[i].status = 'b';		
			if( p[i].t_interrupt >= p[i].burst){
				p[i].status = 'f';
				p[i].t_end=(double)(clock() - start)/CLOCKS_PER_SEC;
			}
		}
		
		
		int count = 0;
		for (int z = 0;z<N;z++){
			if(p[z].status == 'f'){
				count++;
			}	
		}

		sem_post(&S);
		reset();

		//printf("\n%d",count);
		if(count == N){
			 printf("\n");
			 break;
		}
		
		
		/* usar apenas um caractere (n)ovo, (p)ronto, (e)xecução, (b)loqueado, (f)inalizado , (i)nexistente.*/
	}

}





void escalonador(int N, processo *p, int escolha){ 
	
	for (int i=0;i<N;i++){ //DEBUG
		if (p[i].status != 'i'){
			printf("\no tipo do processo [ID=%d] eh: ",p[i].ID);
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
			printf("\n");
		}

	}//FINAL DO DEBUG*/
	printf("\n___________________________________________________________________________\n");

	

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
	sem_wait(&S);
	thread_args *thread_args1;
	thread_args1 = (thread_args*)thread_args2;

	int N = (int)thread_args1->Number;
	processo *p = (processo*)thread_args1->proc;
	int escolha = (int)thread_args1->esc;
	sem_post(&S);
	//============================================

	start = clock();
	double elapsed = 0;
	clock_t current = clock();

	while(1){
		sem_wait(&S);
		reset();
		current = clock();
		elapsed = (double)(current - start)/CLOCKS_PER_SEC;
		for(int i=0; i<N; i++){
			if((p[i].time_in <= elapsed) & (p[i].status == 'i')){
				//printf("\n elapsed = %lf\n",elapsed);//DEBUG
				p[i].status = 'n'; //(i -> n);
				p[i].status = 'p'; //(n -> p);
				printf("\n\nEntrada de Novo Processo de [ID=%d]\n",p[i].ID);
				escalonador(N,p,escolha); //Sempre que um processo entra, o status muda, e ele precisa ser reescalonado.
			}
		
		}
		
		int count = 0;
		for (int z = 0;z<N;z++){
			if(p[z].status == 'i'){
				count++;
			}	
		}
		//printf("\n%d",count);

		sem_post(&S);
		if(count == 0){
			printf("\nTimer finalizado\n");
			break;
		}
	}
}
