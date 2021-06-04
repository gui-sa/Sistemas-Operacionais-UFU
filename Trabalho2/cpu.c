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



void novo_processo(int N,processo *p){
	clock_t start = clock();
	double elapsed = 0;
	clock_t current = clock();

	while(elapsed <= 10){
		current = clock();
		elapsed = (double)(current - start)/CLOCKS_PER_SEC;

		for(int i=0; i<N; i++){
			if((p[i].time_in <= elapsed) & (p[i].status == 'i')){
				printf("\n elapsed = %lf\n",elapsed);
				p[i].status = 'n'; //(i -> n);
				p[i].status = 'p'; //(n -> p);
			}
		}
		escalonador(N,p,escolha);
	}
}
