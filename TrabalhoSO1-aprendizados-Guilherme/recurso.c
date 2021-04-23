#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>





int escalonador(char *path,char **arg){
    
    int status;
    status = execv(path,arg);
   
   return  status;
}


int main (){

    struct teste{
        int counter;
        float value;
    };
    

    int escolha;

    printf("Escolha o escalonador desejado [1] ou [2]:\n 1 - First Come First Served (FCFS)\n 2 - Prioridade Não-Preemptivo\n");
    scanf("%d", &escolha);
    
    char *arg[] = {"tarefas.txt", NULL};
    int status;

    if (escolha==1){       
        status = escalonador("teste",arg);
    }
    else if (escolha==2){       
        status = escalonador("teste",arg);
    }
    else{
        printf("Erro! Não existe essa opcao...\n");
    }

    return 0;
}



