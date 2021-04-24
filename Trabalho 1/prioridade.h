/*
INTEGRANTES:
Nome: Eduardo Marques da Silva - Número: 11721EMT018
Nome: Enrico Sampaio Bonela - Número: 11721EMT007
Nome: Guilherme Salomao Agostini - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro - Número: 11721EMT004
*/

void prioridadeNP(processo *p){
    processo aux;

    for (int j =0; j < N; j++){
        for (int i = 0; i < N; i++){
            if (p[j].prioridade < p[i].prioridade){
                aux = p[j];
                p[j] = p[i];
                p[i] = aux;
            }
        }
    }

    printf("\n\nvetor ordenado:\n");
    for (int i=0;i<N;i++){ //só pra ver se funcionou
        printf("o nome do processo %i eh: %s\n",i,p[i].nome);
        printf("o burst do processo %i eh: %i\n",i,p[i].burst);
        printf("a prioridade do processo %i eh: %i\n\n",i,p[i].prioridade);
    }

}

