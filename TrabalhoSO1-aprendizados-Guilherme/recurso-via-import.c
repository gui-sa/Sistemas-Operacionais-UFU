#include <stdio.h>
#include <stdlib.h>





typedef struct{

	int counter;
	float value;

}teste;
        


void escalonador(teste *teste2, int escolha){

	if (escolha==1){       

		printf("\n%d\n",teste2[0].counter);
		printf("\n%f\n",teste2[0].value);	

	}
	else if (escolha==2){      
 
		printf("\n%d\n",teste2[1].counter);
		printf("\n%f\n",teste2[1].value);	
	
	}
	else{

		printf("Erro! Não existe essa opcao...\n");
	}


	teste2[0].counter = 10000;
	teste2[0].value = 1000.5;


}

void ultimoteste1(teste teste2){

    

	printf("\n%d\n",teste2.counter);
	printf("\n%f\n",teste2.value);	



	teste2.counter = 10000;
	teste2.value = 1000.5;


}

void ultimoteste2(teste *teste2){

    

	printf("\n%d\n",teste2->counter);
	printf("\n%f\n",teste2->value);	



	teste2->counter = 10000;
	teste2->value = 1000.5;


}

//A diferenca de notacao entre o ultimoteste1 e ultimoteste2 eh que o ultimoteste2 esta trabalhando diretamente no endereco e por isso eh percebido alteracao no main. Para trabalhar com o valor quando se tem o endereco, usamos (->).
//No ultimoteste1 trabalhamos diretamente com o valor da struct e por isso usamos o (.). Da mesma forma, como nao trabalhamos com o valor, nao percebemos alteracao na main.

//No caso da escalonador, temos um ponteiro para um array de structs. Quando passamos ele para a funcao e trabalhamos com as structs direcionadas por esse array, estamos mexendo tambem com o endereco da main e por isso usamos o (.) e mesmo assim percebemos alteracao na main.


int main (int argc, char *argv[]){


	int escolha;


	teste teste1[5]; //Ponteiro de structs
	teste ultimo;	

	ultimo.counter = 10;
	ultimo.value = 0.988;	

	printf("\nsobre o Ultimo:\n%d\n",ultimo.counter);
	printf("\n%f\n",ultimo.value);

	teste1[0].counter = 10;
	teste1[0].value = 0.988;

	teste1[1].counter = 20;
	teste1[1].value = 0.5;

	printf("Escolha o escalonador desejado [1] ou [2]:\n 1 - First Come First Served (FCFS)\n 2 - Prioridade Não-Preemptivo\n");
	scanf("%d", &escolha);

	escalonador(teste1, escolha);


	printf("\nNa main:\n%d\n",teste1[0].counter);
	printf("\n%f\n",teste1[0].value);

	ultimoteste1(ultimo);
	printf("\nsobre o Ultimoteste1:\n%d\n",ultimo.counter);
	printf("\n%f\n",ultimo.value);


	ultimoteste2(&ultimo);
	printf("\nsobre o Ultimoteste2:\n%d\n",ultimo.counter);
	printf("\n%f\n",ultimo.value);
	return 0;
}



