#COMPILADOR
CC=gcc

#OPCAO DE COMPILACAO
CFLAGS=-I.

#INFORMA ARQUIVOS HEAD PARA VERIFICAR MODIFICACAO
DEPS = type.h randomizador.h cpu.c FCFS.h SJF.h prioridade.h RR.h
 
#GERA O ARQUIVO OBJETO (.o) E FAZ A DEDPENDENCIA DOS ARQUIVOS .o com .h e .c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
#GERA O EXECUTAVEL PELA FUNCAO MAKE
ex_recurso: recurso.o
	$(CC) -pthread -o ex_recurso recurso.o -lm $(CFLAGS)
