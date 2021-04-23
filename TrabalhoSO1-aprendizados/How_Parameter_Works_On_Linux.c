#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




int main (int argc, char *argv[]){
	//argv[0] = his own name 
	//argv[1] = string of until 100 char
	//argc = number of parameters
	printf("parameter argc : %d\n",argc);	
	printf("parameter [0] : %s\n",argv[0]);	
	printf("parameter [1] : %s\n",argv[1]);	
	
	

    return 0;
}


