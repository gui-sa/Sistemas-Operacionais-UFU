/*
INTEGRANTES:
Nome: Eduardo Marques da Silva - Número: 11721EMT018
Nome: Enrico Sampaio Bonela - Número: 11721EMT007
Nome: Guilherme Salomao Agostini - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro - Número: 11721EMT004
*/

#include <unistd.h>

void CPU (processo *p,int *t){
	p->status = 'e';
	int i;
	for ( i=1; i<=p->burst; i++){
		printf(" progresso [ID=%d]:%d/%d",p->ID, i, p->burst);
		for(int j=1; j<=i; j++) 
			printf("# ");
		for(int j=i+1; j<=p->burst; j++) 
			printf("- ");
		printf("\n\a");
		*t = *t+1;
		sleep(1);
	}
	p->status = 'f';


	/* usar apenas um caractere (n)ovo, (p)ronto, (e)xecução, (b)loqueado, (f)inalizado , (i)nexistente.*/
}



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
			printf("'INEXISTENTE'\n");
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
