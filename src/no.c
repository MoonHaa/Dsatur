#include "no.h"

int is_number_related(no* node, int number){
	int i;
	
	for(i = 0; i < node->tam_vetor_vizinhos; i++){
		if(node->nos_vizinhos[i] == number){
			return 1;
		}
	}
	return 0;
}
