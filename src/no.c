#include "no.h"

int is_number_related(grafo* rede, int indice, int number){
	int i;
	
	for(i = 0; i < rede->nos_grafo[indice].tam_vetor_vizinhos; i++){
		if(rede->nos_grafo[indice].nos_vizinhos[i] == number){
			return 1;
		}
	}
	return 0;
}
