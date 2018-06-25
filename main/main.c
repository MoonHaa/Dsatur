#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

	clock_t init = clock();
	dsatur(rede);
	clock_t end = clock();

	int num_nos = rede->tamanho_grafo;
	int num_arestas = conta_arestas(rede);
	int grau_minimo = retorna_menor_grau_finalizado(rede);
	int grau_maximo = retorna_maior_grau_finalizado(rede);
	float grau_medio = grau_medio_finalizado(rede);
	float desvio_padrao = desvio_padrao_finalizado(rede);
	int num_cores = numero_cores_finalizado(rede);
	double tempo_exec = ((double)(end - init)) / CLOCKS_PER_SEC;

	printf("\nNo. Nos | No. Arestas | Grau Minimo | Grau Maximo | Grau Medio | Desvio Padrao | No. Cores | Tempo Exec. |");
	printf("\n%7i | %11i | %11i | %11i | %10f | %13f | %9i | %8f ms |", num_nos, num_arestas, grau_minimo, grau_maximo, grau_medio, desvio_padrao, num_cores, tempo_exec);

	printf("\n\nNo | Grau | Cor | Vizinhos... |\n");

	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		printf("%2i | %4i | %3i |", rede->nos_grafo[i].valor_no, rede->nos_grafo[i].grau_dsatur, rede->nos_grafo[i].cor);
		for (p = 0; p < rede->nos_grafo[i].tam_vetor_vizinhos; p++)
		{
			printf(" %2i |", rede->nos_grafo[i].nos_vizinhos[p]);
		}
		printf("\n");
	}

	free_grafo(rede);

	return 0;
}
