/*
INTEGRANTES:
Nome: Eduardo Marques da Silva 		- Número: 11721EMT018
Nome: Enrico Sampaio Bonela 		- Número: 11721EMT007
Nome: Guilherme Salomao Agostini 	- Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro 	- Número: 11721EMT004
*/

Consulte nosso git:  https://github.com/guilherme-salomao-agostini/random.git

DOCUMENTAÇÃO:

	Os arquivos de formato txt (tarefas2.txt e tarefas3.txt) são reservados para alterações e execução de testes.
	
	Os arquivos de formato txt (estatistica_FCFS.txt e estatistica_prioridade.txt) possuem apenas os calculos e estatisticas. Resultante dos algorítimos de escalonamento.

	O type.h é um header que possui duas structs. A struct processo, representa o BCP e tem como variável global o tamanho do nome do processo. A struct estatistica tem todas as informações de tempo para possíveis cálculos.

	O leitura_txt.h é um header que possui duas funções int:
		int QuantProc(char *path):
			path= string do caminho do arquivo que contém os processos;
			retorna o número de processos contido nesse arquivo.
		
		int TxtRead(int N, processo *p, char *path)
			N= número de processos calculado na função QuantProc;
			p=ponteiro dinâmico de vetor struct contendo N instâncias (processos);
			path= string do caminho do arquivo que contém os processos;
			retorna -1 em caso de erro ou 0 caso não ocorra erro.

	O recurso.c é um arquivo que possui duas funções:
		void escalonador(int N, processo *pointer, int escolha)
			N= número de processos calculado na função QuantProc;
			pointer=ponteiro dinâmico de vetor struct contendo N instâncias (processos);
			escolha= inteiro que representa o método escalanodor escolhido.

		int main (int argc, char *argv[])
			Pergunta ao usuários qual método de escalonamento ele pretende utilizar no arquivo tarefas.txt;
			Obtem N chamando QuantProc;
			Aloca o ponteiro dinâmico de struct processo;
			Faz chamada da função TxtRead que fornecerá os dados da struct processo
			Faz a chamada da função escalonador.
				
	O FCFS.c possui apenas a função principal (main):
		int main(int argc, char *argv[])
			Recebe como parâmetro o arquivo que contém os processos: o parâmetro será passado pelo terminal pelo usuário (exemplo: ./ex_FCFS tarefas.txt) 
			Obtem N chamando QuantProc;
			Aloca o ponteiro dinâmico de struct processo;
			Faz chamada da função TxtRead que fornecerá os dados da struct processo;
			Faz a chamada da função FCFS() contida no FCFS.h.
			
	O FCFS.h é um header que possui apenas a função FCFS():
		void FCFS(int N,processo *p)
			Escalona pelo método First-Come First-Served que ordena pela ordem de chegada dos processos
			Atualiza o status de todos os processos para pronto
			Chama a função ProximaTarefa() que fará a execução dos processos;
			Printa o BCP a cada fim de execução dos processos;
			Escreve em um arquivo (estatistica_FCFS.txt) a estatica calculada do método.
	
	O prioridade.c possui apenas a função principal (main):
		int main(int argc, char *argv[])
			Recebe como parâmetro o arquivo que contém os processos: o parâmetro será passado pelo terminal pelo usuário (exemplo: ./ex_prioridade tarefas.txt);
			Obtem N chamando QuantProc;
			Aloca o ponteiro dinâmico de struct processo;
			Faz chamada da função TxtRead que fornecerá os dados da struct processo;
			Faz a chamada da função prioridadeNP() contida no prioridade.h.
			
	O prioridade.h é um header que possui apenas a função prioridadeNP():
		void prioridadeNP(int N, processo *p)
			Escalona pelo método prioridade não preenpitiva que ordena os processos de prioridade maior (menor indice) primeiro;
			Atualiza o status de todos os processos para pronto;
			Chama a função ProximaTarefa() que fará a execução dos processos;
			Printa o BCP a cada fim de execução dos processos;
			Escreve em um arquivo (estatistica_prioridade.txt) a estatica calculada do método.

	O cpu.c faz a "execução" dos processos chamados pelo método escalonador:
		void ProximaTarefa (processo *p,int *t)
			p=ponteiro dinâmico de vetor struct contendo N instâncias (processos);
			t=tempo de CPU em número de ciclos (cada ciclo possui 1s) (o tempo de ciclo foi definido em 1s para facilitar a visualização do processo, mas pode ser facilmente alterado reduzindo o sleep de 1 para 0.001 para passar para ms);
			Altera o status do processo para execução;
			Printa o progresso do processo após cada ciclo de execução da CPU;
			Ao final da execução altera o status do processo para finalizado.
			
	Para fazer as compilações dos programas e gerar os arquivos executáveis foram utilizados os arquivos makefile, que irão compilar o programa utilizando o compilador gcc, utilizando os arquivos contido no diterório atual, e retornando o arquivo executavel. Segue em exemplo a execução dos makefile:
		make -f makefile_recurso
			retorna o executavel ex_recurso
		make -f makefile_FCFS
			retorna o executavel ex_FCFS
		make -f makefile_prioridade
			retorna o executavel ex_prioridade
	
COMO UTILIZAR:
	cd ../random/"Trabalho 1"
	make -f makefile_recurso
	make -f makefile_FCFS
	make -f makefile_prioridade
	
	./ex_recurso
	./ex_FCFS tarefas.txt
	./ex_prioridade tarefas.txt

TESTES:
	Foram feitos teste em todos os executáveis utilizando tarefas.txt tarefas2.txt tarefas3.txt.
	Os resultados estão presentes Teste_FCFS_tarefas.txt, Teste_FCFS_tarefas2.txt e Teste_FCFS_tarefas3.txt
	Os resultados estão presentes Teste_prioridade_tarefas.txt, Teste_prioridade_tarefas2.txt e Teste_prioridade_tarefas3.txt
	
	
