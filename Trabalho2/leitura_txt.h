/*
INTEGRANTES:
Nome: Eduardo Marques da Silva - Número: 11721EMT018
Nome: Enrico Sampaio Bonela - Número: 11721EMT007
Nome: Guilherme Salomao Agostini - Número: 11721EMT003
Nome: Luiz Renato Rodrigues Carneiro - Número: 11721EMT004
*/





  
int randomize_process(int N, processo *p){
	int i;

	
	for (i=0 ; i<N ; i++){
		p[i].cpu = rand()%100;
		if (p[i].cpu>50){
			p[i].tipo = 'c';
		} else{
			p[i].tipo = 'i';		
		}
		p[i].ID = i+1;
		p[i].time_in = rand()%10;
		p[i].burst = rand()%10;//10 eh o valor maximo
		p[i].status = 'n';//no início todos os processos são novos
	}



	return 0; 
}


