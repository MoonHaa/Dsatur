#include "grafo.h"

void free_grafo(grafo * grafico)
{
	int i;
	for (i = 0; i < grafico->tamanho_grafo; i++)
	{
		free(grafico->nos_grafo[i].nos_vizinhos);
		free(grafico->nos_grafo[i];
	}
	free(grafico->nos_grafo);
	free(grafico);
	return;
}

int get_indice_no_numero(grafo* rede, int valor){
	int i;	
	for(i=0; i<rede->tamanho_grafo;i++){
		if(rede->nos_grafo[i].valor_no == valor){
			return i;
		}
	}
	return -1;
}
