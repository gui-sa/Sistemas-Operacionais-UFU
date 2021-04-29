/*
INTEGRANTES:
Nome: Eduardo Marques da Silva - Número: 11721EMT018
Nome: Enrico Sampaio Bonela - Número: 11721EMT007
Nome: Guilherme Salomao Agostini - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro - Número: 11721EMT004
*/

void prioridadeNP(int N, processo *p){
    processo aux;

    for (int j =0; j < N; j++){
        for (int i = j+1; i < N; i++){
            if (p[j].prioridade > p[i].prioridade){
                aux = p[j];
                p[j] = p[i];
                p[i] = aux;
            }
        }
    }


    printf("\n\nvetor ordenado:\n");
    for (int i=0;i<N;i++){ //só pra ver se funcionou
	printf("o nome do processo [ID=%d] eh: %s\n",p[i].ID,p[i].nome);
	printf("o burst do processo [ID=%d] eh: %d\n",p[i].ID,p[i].burst);
	printf("o status do processo [ID=%d] eh: %c\n",p[i].ID,p[i].status);
	printf("a prioridade do processo [ID=%d] eh: %i\n\n",p[i].ID,p[i].prioridade);
    }


    free(p);
}

