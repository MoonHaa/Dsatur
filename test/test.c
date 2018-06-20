#include <stdlib.h>
#include <stdio.h>
#include "arquivo.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Uso: %s arquivo_grafo.csv\n", argv[0]);
		return(1);
	}

	grafo *teste = abre_csv(argv[1]);

	int i,p;

	printf("No | Num_Viz | Grau | Cor | Vizinhos...|\n");

	for (i = 0; i < teste->tamanho_grafo; i++)
	{
		printf("%i | %i | %i | %i |", teste->nos_grafo[i].valor_no, teste->nos_grafo[i].num_vizinhos, teste->nos_grafo[i].grau_dsatur, teste->nos_grafo[i].cor);
		for (p = 0; p < teste->nos_grafo[i].tam_vetor_vizinhos; p++)
		{
			printf(" %i |", teste->nos_grafo[i].nos_vizinhos[p]);
		}
		printf("\n");
	}

	return 0;
}
