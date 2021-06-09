/*
INTEGRANTES:
Nome: Eduardo Marques da Silva - Número: 11721EMT018
Nome: Enrico Sampaio Bonela - Número: 11721EMT007
Nome: Guilherme Salomao Agostini - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro - Número: 11721EMT004
*/

void FCFS(int N,processo *p){

    	processo aux;
	for (int j =0; j < N; j++){//Ordena os processos com indice de prioridade menor primeiro
		for (int i = j+1; i < N; i++){
			if ( (p[j].time_in) > (p[i].time_in)){
				aux = p[j];
				p[j] = p[i];
				p[i] = aux;
			}
		}
	}
    
}

