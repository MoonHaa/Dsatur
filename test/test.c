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

	abre_csv(argv[1]);

	return 0;
}
