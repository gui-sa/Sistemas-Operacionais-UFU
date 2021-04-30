/*
INTEGRANTES:
Nome: Eduardo Marques da Silva          - Número: 11721EMT018
Nome: Enrico Sampaio Bonela             - Número: 11721EMT007
Nome: Guilherme Salomao Agostini        - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro    - Número: 11721EMT004
*/

void FCFS(int N,processo *p){
    //  A funcao TxtRead já ordena os vetores em um formato First Come First Served.

    for (int i=0;i<N;i++){      // Prepara todos os processos para a fila de pronto.
        p[i].status = 'p';
    }

    unsigned int t=0;           // Tempo, controle da estatistica.
    conta = malloc(N*sizeof(estatistica));
    for (int i=0;i<N;i++){
        conta[i].t_enter = 0;   // Todos os processos entram no mesmo instante.
    }

    for (int i=0;i<N;i++){
        if (p[i].status =='p'){
            printf("\n\nvetor ordenado:\n");
            for (int i=0;i<N;i++){
                printf("o nome do processo [ID=%d] eh: %s\n",p[i].ID,p[i].nome);
                printf("o burst do processo [ID=%d] eh: %d\n",p[i].ID,p[i].burst);
                printf("o status do processo [ID=%d] eh: %c\n",p[i].ID,p[i].status);
                printf("a prioridade do processo [ID=%d] eh: %i\n\n",p[i].ID,p[i].prioridade);
            }
	    conta[i].ID = p[i].ID;
	    conta[i].t_init = t;
	    ProximaTarefa(&p[i],&t);
	    conta[i].t_end = t;
        }
    }

    for (int i=0;i<N;i++){      //DEBUG - só pra ver se funcionou
        printf("o nome do processo [ID=%d] eh: %s\n",p[i].ID,p[i].nome);
        printf("o burst do processo [ID=%d] eh: %d\n",p[i].ID,p[i].burst);
        printf("o status do processo [ID=%d] eh: %c\n",p[i].ID,p[i].status);
        printf("a prioridade do processo [ID=%d] eh: %i\n\n",p[i].ID,p[i].prioridade);
    }

    printf("\a\n\tCPU INATIVA\n\n");

    printf("ESTATISTICAS:\n\n");

    for (int i=0;i<N;i++){//DEBUG
        printf("Tempo entrada na fila do pronto para o processo [ID=%d] eh: %d\n",conta[i].ID,conta[i].t_enter);
        printf("Tempo de inicio de execucao para o processo [ID=%d] eh: %d\n",conta[i].ID,conta[i].t_init);
        printf("Tempo de retorno para o processo [ID=%d] eh: %d\n\n",conta[i].ID,conta[i].t_end);
    }

    FILE* arqNome = fopen("estatistica_FCFS.txt","w");
    float media_retorno = 0;
    float media_inicio = 0;

    for (int i=0;i<N;i++){
        fprintf(arqNome,"Tempo entrada na fila do pronto para o processo [ID=%d] eh: %d\n",conta[i].ID,conta[i].t_enter);
        fprintf(arqNome,"Tempo de inicio de execucao para o processo [ID=%d] eh: %d\n",conta[i].ID,conta[i].t_init);
        fprintf(arqNome,"Tempo de retorno para o processo [ID=%d] eh: %d\n\n",conta[i].ID,conta[i].t_end);
        media_retorno = media_retorno+(conta[i].t_end-conta[i].t_enter);
        media_inicio = media_inicio+(conta[i].t_init-conta[i].t_enter);
    }

    media_retorno = media_retorno/N;
    media_inicio = media_inicio/N;
    fprintf(arqNome,"\n\nTempo medio de inicio eh: %f\n",media_inicio);
    fprintf(arqNome,"Tempo medio de retorno eh: %f\n",media_retorno);
    fclose(arqNome);
    free(p);
    free(conta);

}
