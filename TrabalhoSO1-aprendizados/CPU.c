#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>//importa sleep()
 
int main(void) {
	int tempo=10;
	for (int i=1; i<=tempo; i++){
		printf("Progresso:%d/%d ", i, tempo);
		for (int j=1; j<=i; j++) printf("# ");
		for (int j=i+1; j<=tempo; j++) printf("- ");
		printf("\n");
		sleep(1);
	}
	return 0;
}
