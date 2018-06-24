#include "dsatur.h"

int dsatur(grafo* rede)
{
	int maior_cor = 0;
	int indice;

	inicializar_grafo(rede);

	while(!is_todos_coloridos(rede))
	{
		indice = indice_proximo_colorir(rede);
		colorir(rede, indice, &maior_cor);
		atualizar_dsatur_e_vizinhos(rede, indice);
	}
	//free na main
	return maior_cor;
}

void colorir(grafo* rede, int indice, int* maior_cor)
{
	int i, cor_escolhida = 0;
	int *quantos_relacionados_de_cada_cor = (int*)malloc((*maior_cor)*sizeof(int));

	for(i=0; i<*maior_cor; i++)
	{
		quantos_relacionados_de_cada_cor[i] = 0;
	}

	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		if(rede->nos_grafo[i].cor != 0)
		{
			if(is_number_related(rede, indice, rede->nos_grafo[i].valor_no))
			{
				quantos_relacionados_de_cada_cor[rede->nos_grafo[i].cor-1]++;
			}
		}
	}

	for(i=0; i<*maior_cor; i++)
	{
		if(quantos_relacionados_de_cada_cor[i]==0)
		{
			cor_escolhida = i+1;
			break;
		}
	}

	if(cor_escolhida == 0)
	{
		cor_escolhida = ++(*maior_cor);
	}

	rede->nos_grafo[indice].cor = cor_escolhida;

}

void inicializar_grafo(grafo* rede)
{
	int i;

	for(i=0; i<rede->tamanho_grafo; i++)
	{
		rede->nos_grafo[i].num_vizinhos = rede->nos_grafo[i].tam_vetor_vizinhos;
		rede->nos_grafo[i].grau_dsatur = 0;
		rede->nos_grafo[i].cor = 0;
	}
}

int indice_proximo_colorir(grafo* rede)
{
	int i, indice_escolhido = 0, maior_dsatur = 0, is_empate_dsatur = 0, maior_n_vizinhos = 0;

	//procura o maior grau de saturação (e o dono) dos que nao
	//foram coloridos e verifica se houve um empate
	for(i=0; i<rede->tamanho_grafo; i++)
	{
		if(rede->nos_grafo[i].cor == 0)
		{
			if(rede->nos_grafo[i].grau_dsatur == maior_dsatur)
			{
				is_empate_dsatur = 1;
			}
			if(rede->nos_grafo[i].grau_dsatur > maior_dsatur)
			{
				maior_dsatur = rede->nos_grafo[i].grau_dsatur;
				indice_escolhido = i;
				is_empate_dsatur = 0;
			}
		}
	}

	if(is_empate_dsatur)
	{
		for(i=0; i<rede->tamanho_grafo; i++)
		{
			if( (rede->nos_grafo[i].cor == 0) && (rede->nos_grafo[i].num_vizinhos > maior_n_vizinhos) )
			{
				indice_escolhido = i;
				maior_n_vizinhos = rede->nos_grafo[i].num_vizinhos;
			}
		}
	}

	return indice_escolhido;
}

int is_todos_coloridos(grafo* rede)
{
	int i;

	for(i=0; i<rede->tamanho_grafo; i++)
	{
		if(rede->nos_grafo[i].cor == 0)
		{
			return 0;
		}
	}

	return 1;
}

void atualizar_dsatur_e_vizinhos(grafo* rede, int indice)
{
	int i;

	for(i=0; i<rede->tamanho_grafo; i++)
	{
		if(is_number_related(rede, indice, rede->nos_grafo[i].valor_no))
		{
			rede->nos_grafo[i].num_vizinhos--;
			rede->nos_grafo[i].grau_dsatur++;
		}
	}
}
