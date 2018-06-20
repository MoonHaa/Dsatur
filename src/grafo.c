#include "grafo.h"

void free_grafo(grafo * grafico)
{
	int i;
	for (i = 0; i < grafico->tamanho_grafo; i++)
	{
		free(grafico->nos_grafo[i].nos_vizinhos);
	}
	free(grafico->nos_grafo);
	free(grafico);
	return;
}
