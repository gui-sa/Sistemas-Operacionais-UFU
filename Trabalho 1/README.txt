/*
INTEGRANTES:
Nome: Eduardo Marques da Silva 	- Número: 11721EMT018
Nome: Enrico Sampaio Bonela 		- Número: 11721EMT007
Nome: Guilherme Salomao Agostini 	- Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro 	- Número: 11721EMT004
*/

	Os arquivos de formato txt (tarefas2.txt e tarefas3.txt) são reservados para alterações e execução de testes.
	
	Os arquivos de formato txt (estatistica_FCFS.txt e estatistica_prioridade.txt) possuem apenas os calculos e estatisticas.

	O type.h é um header que possui duas structs. A struct processo, representa o BCP e tem como variável global o tamanho do nome do processo. A struct estatistica tem todas as informações de tempo para possíveis cálculos.

	O leitura_txt.h é um header que possui duas funções int. A primeira função faz a contagem de quantidade de processos dentro do txt, recebe um ponteiro como parâmetro do arquivo FCFS.c ou prioridade.c o nome do .txt que será escolhido para a leitura e retorna a contagem como variável N. A segunda função faz de fato a leitura do .txt, recebe três parâmetros, nos quais são a variável N, o ponteiro de processos da struct do arquivo type.h e por último um ponteiro do escalonador como o nome do .txt escolhido.

	O recurso.c possui um função sem retorno (void) e uma principal (main). A função main faz uma chamada dinâmica da função de leitura do header leitura_txt.h, atribui valor para uma variável de escolha e chama a função sem retorno do próprio recurso.c. A função void faz a seleção do escalonador a partir da variável escolha, recebe três parâmetros, sendo eles a variável N do arquivo leitura_txt.h, o ponteiro de processos da struct do arquivo type.h e por último a variável escolha criado no recurso.c.

	O FCFS.c possui apenas a função principal (main), na main temos duas chamadas de função, ambas precisam da declaração da variável N obtida no leitura_txt.h e uma alocação dinâmica da struct de processos do type.h. A primeira função chama a função de leitura do txt que está no arquivo leitura_txt.h e a segunda faz a chamada do escalonador FCFS que se encontra no arquivo FCFS.h.
	
	O FCFS.h é um header que possui apenas uma função sem retorno (void), a função faz a ordenação com base na teoria de escalonamento de processos FCFS (primeiro a chegar primero a ser atendido), nela temos dois parâmetros, que por sua vez são a variável N obtida no arquivo leitura_txt.h e a struct alocada dinamicamente no FCFS.c. A 
função faz o print do BCP e tem informações de quando o processo atual finalizou e quando pode chamar o próximo processo que se encontra no arquivo cpu.c. Além disso, a função faz o print das estatisticas no terminal e escrever todas as estatisticas e cálculos em um arquivo txt chamado estatistica_FCFS.txt.
	
	O prioridade.c possui apenas a função principal(main), na main temos duas chamadas de função, ambas precisam da declaração da variável N obtida no leitura_txt.h e uma alocação dinâmica da struct de processos do type.h. A primeira função chama a função de leitura do txt que está no arquivo leitura_txt.h e a segunda faz a chamada do escalonador por prioridade que se encontra no arquivo prioridade.h.

	O prioridade.h é um header que possui apenas um função sem retorno (void), a função faz a ordenação com base na teoria de escolamento de processos por prioridade (prioridade mais alto é atendido primeiro), nela temos dois parâmetros, nos quais são a variável N obtida no arquivo leitura_txt.h e a struct alocada dinamicamente no prioridade.c. A função faz o print do BCP e tem informações de quando o processo atual finalizou e quando pode chamar o próximo processo que se encontra no arquivo cpu.c. Além disso, a função faz o print das estatisticas no terminal e escreve todas as estatisticas e cálculos em um arquivo txt chamado estatistica_prioridade.txt

	O cpu.c possui apenas a função sem retorno (void), a void recebe como parâmetro um ponteiro da struct de processos do arquivo type.h e ponteiro da variável tempo, a função faz a análise de tamanho do processo e determina quanto de ciclo de CPU será demandado para o processo até que o escalonador chame outro processo para execução. Além disso, a variável tempo é usada para marcações de tempo decorrido para cálculos e estatisticas.
	
	
	
	
	
	
	
	
	
	
