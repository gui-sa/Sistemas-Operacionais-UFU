#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




int main (int argc, char *argv[]){

	char *const arg[] = {"printa isso daqui...",NULL};
	execv("teste",arg);

	//Chamando pelo execv:
	//argv[0] = "printa isso daqui"
	//argv[1] = (null)
	//argc = 1


	//Chamando pelo CMD:
	//argv[0] = his own name 
	//argv[1] = string 
	//argc = number of parameters


	//Para que ele fique igual:
	//	char *const arg[] = {"teste","printa isso daqui...",NULL};

	//https://stackoverflow.com/questions/10878128/are-argc-argv-useless-in-windows
	//Desta maneira o argc e argv nao eh inutil no windows...

	printf("\nAcabou-se\n");	
	
	//Se a funcao exec rodar certinho, o print "acabou-se" nao roda.
	
	

    return 0;
}


