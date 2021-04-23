#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//https://stackoverflow.com/questions/30274356/can-we-pass-variables-from-one-c-program-to-another-c-program
//Nao podemos passar uma var para outro programa pelo problema de que processos sao independentes entre si (exceto que essa var seja global e compartilhada)

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


	//Para que o print seja igual tanto no cmd tanto no execv:
	//char *const arg[] = {"teste","printa isso daqui...",NULL};

	//Interessante! https://stackoverflow.com/questions/10878128/are-argc-argv-useless-in-windows
	//	Apesar do argc e argv ter praticidade mesmo no linux, isso funciona no windows tambem! (via cmd) Ou seja, quando rodamos um codigo que usar argc e argv de outros codigos via windows, ele funciona normal... CUIDADO: a lib unistd eh natural do linux... entao no caso, isso daria problema la por causa disso.

	printf("\nAcabou-se\n");	
	
	//Se a funcao exec rodar certinho, o print "acabou-se" nao roda.
	
	

    return 0;
}


