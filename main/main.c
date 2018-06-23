#include <stdlib.h>
#include <stdio.h>

#include "grafo.h"
#include "dsatur.h"
#include "arquivo.h"

int main(int argc, char* argv[])
{
	grafo *rede;
	
	if (argc < 2)
	{
		printf("Uso: %s arquivo_grafo.csv\n", argv[0]);
		return(1);
	}

	rede = abre_csv(argv[1]);

	imprime_grafo(rede);
	
	printf("\n\ndsatur:%d\n\n\n", DSATUR(rede));
	
	imprime_grafo(rede);
	
	free_grafo(rede);
	
	return 0;
}
