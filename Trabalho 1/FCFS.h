/*
INTEGRANTES:
Nome: Eduardo Marques da Silva - Número: 11721EMT018
Nome: Enrico Sampaio Bonela - Número: 11721EMT007
Nome: Guilherme Salomao Agostini - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro - Número: 11721EMT004
*/

void FCFS(processo *p){
    
    //A funcao TxtRead ja ordena os vetores em um formato First Come First Served
    for (int i=0;i<N;i++){
        p[i].status = 'p';
    }


    for (int i=0;i<N;i++){
        if (p[i].status =='p'){
	    printf("\n\nvetor ordenado:\n");
	    for (int i=0;i<N;i++){ //só pra ver se funcionou
		printf("o nome do processo [ID=%d] eh: %s\n",p[i].ID,p[i].nome);
		printf("o burst do processo [ID=%d] eh: %d\n",p[i].ID,p[i].burst);
		printf("o status do processo [ID=%d] eh: %c\n",p[i].ID,p[i].status);
		printf("a prioridade do processo [ID=%d] eh: %i\n\n",p[i].ID,p[i].prioridade);
	    }
	    ProximaTarefa(&p[i]);	
	}
    }

    for (int i=0;i<N;i++){ //só pra ver se funcionou
	printf("o nome do processo [ID=%d] eh: %s\n",p[i].ID,p[i].nome);
	printf("o burst do processo [ID=%d] eh: %d\n",p[i].ID,p[i].burst);
	printf("o status do processo [ID=%d] eh: %c\n",p[i].ID,p[i].status);
	printf("a prioridade do processo [ID=%d] eh: %i\n\n",p[i].ID,p[i].prioridade);
    }

    printf("\nCPU INATIVA\n");
    printf("\nCPU INATIVA\n");

}
