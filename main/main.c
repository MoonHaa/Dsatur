#include <stdlib.h>
#include <stdio.h>

#include "no.h"
#include "grafo.h"
#include "dsatur.h"
#include "arquivo.h"

int main(int argc, char* argv[])
{
	int i, p;

	if (argc < 2)
	{
		printf("Uso: %s arquivo_grafo.csv\n", argv[0]);
		return(1);
	}

	grafo* rede = abre_csv(argv[1]);

	printf("\n\ndsatur:%i\n\n\n", dsatur(rede));

	printf("No | Num_Viz | Grau | Cor | Vizinhos...\n");

	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		printf("%2i | %7i | %4i | %3i |", rede->nos_grafo[i].valor_no, rede->nos_grafo[i].num_vizinhos, rede->nos_grafo[i].grau_dsatur, rede->nos_grafo[i].cor);
		for (p = 0; p < rede->nos_grafo[i].tam_vetor_vizinhos; p++)
		{
			printf(" %2i |", rede->nos_grafo[i].nos_vizinhos[p]);
		}
		printf("\n");
	}

	free_grafo(rede);

	return 0;
}
