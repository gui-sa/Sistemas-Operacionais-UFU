/*
INTEGRANTES:
Nome: Eduardo Marques da Silva 	- Número: 11721EMT018
Nome: Enrico Sampaio Bonela 		- Número: 11721EMT007
Nome: Guilherme Salomao Agostini 	- Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro 	- Número: 11721EMT004


Consulte nosso git:  https://github.com/guilherme-salomao-agostini/random.git

DOCUMENTAÇÃO:
	
	Todos os prints referentes as cores abaixo estão relacionados com os seguintes execuções:
		Vermelho: CPU1;
		Azul: CPU2;
		Verde: IO;
		Branco: Outros.
	
	Os arquivos de formato txt (estatistica_SJF.txt, estatistica_FCFS.txt, estatistica_prioridade.txt e estatistica_RR.txt) possuem apenas os calculos e estatisticas. Resultante dos algorítimos de escalonamento.

	O type.h é um header que possui duas structs. A struct processo, representa o BCP. A struct thread_args tem todas as informações que são importantes para a execução das threads.

	O randomizador.h é um header que possui uma função int:		
		int randomize_process(int N, processo *p)
			N= número de processos calculado na função QuantProc;
			p=ponteiro dinâmico de vetor struct contendo N instâncias (processos);
			inicializa as variáveis do BCP de forma randomica;
			retorna 0.

	O recurso.c é o arquivo principal:
		-Pergunta ao usuário quantos processos ele deseja executar;
		-Gera o vetor de processos *p;
		-Chama o randomize_process(N,p);
		-Pergunta ao usuário qual escalonador utilizar;
		-Inicia o semáforo, cria funções para alterar as cores dos prints e cria a variavel global de controle de tempo (elapsed);
		-Cria as Threads para CPU1 (vermelho) , CPU2 (azul), IO (verde), CLOCK e preempcao (branco);
		-Calculo da estatistica e geração dos arquivos txt para leitura.
			
	O SJF.h é um header que possui apenas a função SJF():
		void SJF(int N,processo *p)
			Escalona pelo método Shortest Job First;
			Organiza da esquerda para a direita pelo menor tempo restante de execução (menor para maior).
	
	O FCFS.h é um header que possui apenas a função FCFS():
		void FCFS(int N,processo *p)
			Escalona pelo método First-Come First-Served;
			Organiza da esquerda para a direita pelo tempo de chegada (menor para maior).
	
	O prioridade.h é um header que possui apenas a função prioridade():
		void prioridade(int N,processo *p)
			Escalona pelo método prioridade preemptivo;
			Organiza da esquerda para a direita pela prioridade (menor para maior, em que 0 = maior prioridade).
			
	O RR.h é um header que possui apenas a função RR():
		void RR(int N,processo *p)
			Escalona pelo método First-Come First-Served (futuramente será tratado diferente pela CPU.c);
			Organiza da esquerda para a direita pelo tempo de chegada (menor para maior).
	
	O cpu.c faz a "execução" dos processos e controla o tempo:
		*thread_args2= struct que carrega as variaveis de entrada da thread (int N, processo *p, int esc)
		
		As funções abaixo são executadas como threads:
		cpu1: *CPU1(void *thread_args2);
		cpu2: *CPU2(void *thread_args2);
		io: *IO(void *thread_args2);
		cpu_clock: *CPU_CLOCK();
		preempcao: *novo_processo(void *thread_args2).
		
		void *CPU(void *thread_args2)
			Existe uma versão para o SJF, FCFS e prioridade:
				-Varre da esquerda para direita o vetor de processos (prontos), procurando por prontos;
				-Ao encontrar o primeiro pronto ele executa o processo por 1s (1 ciclo), e o deixa no status executando;
				-Caso o tempo de CPU seja executado restando somente o tempo de IO ele muda o status para bloqueado;
				-Caso o tempo total de execução seja executado o processo muda o status pra finalizado;
			Existe uma versão para o RR:
				-Varre o vetor de processos (prontos), procurando por prontos;
				-Ao encontrar o primeiro pronto ele executa o processo por 5s (1 quantum), e o deixa no status executando;
				-Executa o próximo processo na fila de pronto;
				-Quando chega no final da fila de pronto (canto direito) ele retorna para o início (canto esquerdo);
				-Caso o tempo de CPU seja executado restando somente o tempo de IO ele muda o status para bloqueado;
				-Caso o tempo total de execução seja executado o processo muda o status pra finalizado.
		
		void *IO(void *thread_args2)
			Existe uma versão para o SJF, FCFS e prioridade:
				-Varre da esquerda para direita o vetor de processos (prontos), procurando por bloqueados;
				-Ao encontrar o primeiro bloqueado ele executa o processo por 1s (1 ciclo), e o deixa no status executando;
				-Caso o tempo total de execução seja executado o processo muda o status pra finalizado;
			Existe uma versão para o RR:
				-Varre o vetor de processos (prontos), procurando por bloqueados;
				-Ao encontrar o primeiro bloqueado ele executa o processo por 5s (1 quantum), e o deixa no status executando;
				-Executa o próximo processo na fila de pronto;
				-Quando chega no final da fila de pronto (canto direito) ele retorna para o início (canto esquerdo);
				-Caso o tempo total de execução seja executado o processo muda o status pra finalizado.
		
		void *CPU_CLOCK ()
			Funcao que controla o tempo a partir da variável global elapsed.
			
		void *novo_processo(void *thread_args2)
			Varre o vetor de processo procurando por novos processos para gerar uma preempcao e atualizar a fila de processos prontos;
			Chama a função escalonador(N,p,escolha).
		
		void escalonador(int N, processo *p, int escolha)
			Printa o atual estado dos processos existentes;
			Chama o escalonador escolhido pelo usuário.
		
		
			
	Para fazer as compilações dos programas e gerar os arquivos executáveis foram utilizados os arquivos makefile, que irão compilar o programa utilizando o compilador gcc, utilizando os arquivos contido no diterório atual, e retornando o arquivo executavel. Segue em exemplo a execução dos makefile:
		make
	
COMO UTILIZAR:
	cd ../random/"Trabalho2"
	make
	./ex_recurso
	
*/
