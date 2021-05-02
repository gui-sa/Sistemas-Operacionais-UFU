/*
INTEGRANTES:
Nome: Eduardo Marques da Silva - Número: 11721EMT018
Nome: Enrico Sampaio Bonela - Número: 11721EMT007
Nome: Guilherme Salomao Agostini - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro - Número: 11721EMT004
*/

int QuantProc(char *path){
	int pri, temp, contador;
	char nome[TAM_NOME];
	int N;

	contador = 0;
	FILE* arqNome = fopen(path,"r");
	if(arqNome != NULL){
		while(fscanf(arqNome,"%s %d %d\n",nome, &pri,&temp) != EOF){// Ler o arquivo linha por linha, até o final do arquivo (end of file)
			contador++;
		}
	}
	N = contador;
	fclose(arqNome); //fecha o arquivo
	return N;
}


  
int TxtRead(int N, processo *p, char *path){
	int pri; 
	int temp;
	char nome[TAM_NOME];
	int contador=0;
	int i;


	for (i=0;i<N;i++){
		p[i].status = 'n';	//no início todos os processos são novos.
		p[i].ID = i; 		//evitar valor inicial aleatório
	}

	FILE* arqNome = fopen(path,"r");

	if(arqNome != NULL){
		while(fscanf(arqNome,"%s %i %i\n",nome, &pri,&temp) != EOF){// Ler o arquivo linha por linha, até o final do arquivo (end of file)
			//printf("%s %i %i\n",nome,pri,temp);//DEBUG
			strcpy(p[contador].nome,nome);
			p[contador].prioridade = pri;
			p[contador].burst = temp;
			contador++;
		}


		/*for (i=0;i<N;i++){ //DEBUG -  printando struct BCP
		printf("o nome do processo %i eh: %s\n",i,p[i].nome);
		printf("o burst do processo %i eh: %i\n",i,p[i].burst);
		printf("a prioridade do processo %i eh: %i\n\n",i,p[i].prioridade);
		}*/
		for (i=0;i<N;i++){ //só pra ver se funcionou
			printf("o nome do processo [ID=%d] eh: %s\n",p[i].ID,p[i].nome);
			printf("o burst do processo [ID=%d] eh: %d\n",p[i].ID,p[i].burst);
			printf("o status do processo [ID=%d] eh: %c\n",p[i].ID,p[i].status);
			printf("a prioridade do processo [ID=%d] eh: %i\n\n",p[i].ID,p[i].prioridade);
		}

	}
	else{
		printf("\nERRO: Não foi possivel abrir o arquivo (not found)\n");
		fclose(arqNome); //fecha o arquivo
		return -1;
	}

	fclose(arqNome); //fecha o arquivo

	return 0; 
}


