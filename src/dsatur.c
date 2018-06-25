#include "dsatur.h"

void dsatur(grafo * rede)
{
	//atualiza o grau dos vertices -- numero de cores distintas dos vizinhos
	//inicializa_grau_grafo(rede);

	//enquanto grafo não estiver todo colorido
	while (!verifica_grafo_colorido(rede))
	{
		int indice, cor;

		//procura pelo vertice de maior grau ainda não colorido
		indice = procura_maior_grau(rede);
		//procura pelo menor valor de cor disponível -- verifica pelas cores dos vizinhos
		cor = procura_menor_valor_cor(rede, indice);
		//colore com o menor valor
		rede->nos_grafo[indice].cor = cor;
		//aumenta grau dos vizinhos
		aumenta_grau_vizinho(rede, indice);
	}

	//atualiza o grau dsatur final
	update_grau_final(rede);
}

int verifica_grafo_colorido(grafo * rede)
{
	int i;

	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		if (!(rede->nos_grafo[i].cor)) //cor do nó será zero sempre que este não possuir cor
		{
			return 0;
		}
	}

	return 1;
}

int procura_maior_grau(grafo * rede)
{
	int i, indice = 0, maior_grau = 0;

	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		//procura pelo no de maior grau que não tenha sido colorido ainda!
		if ( (!(rede->nos_grafo[i].cor)) && (rede->nos_grafo[i].grau_dsatur > maior_grau) )
		{
			indice = i;
			maior_grau = rede->nos_grafo[i].grau_dsatur;
		}
	}

	return indice;
}

int procura_menor_valor_cor(grafo * rede, int indice)
{
	int i, menor_cor = 1;

	for (i = 0; i < rede->nos_grafo[indice].tam_vetor_vizinhos; i++)
	{
		int vizinho = rede->nos_grafo[indice].nos_vizinhos[i]; //isso tudo é o indice de um no adjacente!!!

		if (rede->nos_grafo[vizinho-1].cor == menor_cor) //se um no vizinho já tiver usando essa mesma cor
		{
			menor_cor++; //aumenta o valor da cor
			i = -1;	//reseta o loop e testa tudo novamente com a nova cor //vai pra 0 no fim do loop!!!
		}
	}

	return menor_cor;
}

void aumenta_grau_vizinho(grafo * rede, int indice)
{
	int i;

	for (i = 0; i < rede->nos_grafo[indice].tam_vetor_vizinhos; i++)
	{
		int vizinho = rede->nos_grafo[indice].nos_vizinhos[i]; //novamente, isso tudo é um unico indice

		if (!(rede->nos_grafo[vizinho - 1].cor)) //não aumente o grau dos nós já coloridos!!!!
		{
			(rede->nos_grafo[vizinho - 1].grau_dsatur)++; //incrementa o grau do vizinho
		}
	}
}

void update_grau_final(grafo * rede)
{
	int i;

	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		int p;

		//zera o grau dsatur
		rede->nos_grafo[i].grau_dsatur = 0;

		//cria um vetor pra contabilizar a cor de cada vizinho
		int *cores = (int*)malloc(rede->nos_grafo[i].tam_vetor_vizinhos * sizeof(int));

		//zera vetor de cores
		for (p = 0; p < rede->nos_grafo[i].tam_vetor_vizinhos; p++)
		{
			cores[p] = 0;
		}

		//percorre os vizinhos, contabilizando o numero de cores diferentes encontradas...
		for (p = 0; p < rede->nos_grafo[i].tam_vetor_vizinhos; p++)
		{
			int q;

			int indice = rede->nos_grafo[i].nos_vizinhos[p];

			int flag = 1; //flag pra sinalizar a necessidade de adicionar uma cor no vetor de cores

			//testa a cor do vizinho para cada posição do vetor...
			for (q = 0; (flag) && (q < rede->nos_grafo[i].tam_vetor_vizinhos) && (cores[q]); q++)
			{
				if (rede->nos_grafo[indice - 1].cor == cores[q])
				{
					flag = 0; //seta a flag pra zero se a cor já existir no vetor de cores
				}
			}

			if (flag) //se a cor nao existir no vetor de cores
			{
				//percorre o veto procurando pela primeira posicao sem cor
				for (q = 0; (q < rede->nos_grafo[i].tam_vetor_vizinhos) && (cores[q]); q++);

				//seta a cor
				cores[q] = rede->nos_grafo[indice - 1].cor;
			}
		}

		//contabiliza a quantidade de cores validas no vetor
		for (p = 0; (p < rede->nos_grafo[i].tam_vetor_vizinhos) && (cores[p]); p++)
		{
			(rede->nos_grafo[i].grau_dsatur)++;
		}

		free(cores);
	}
}

int conta_arestas(grafo * rede)
{
	int i, arestas = 0;

	//percorre todo os nos do grafo
	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		//numero de arestas eh o numero de arestas q já existe, mais o numero de vizinhos nao contabilizados do no
		arestas = arestas + rede->nos_grafo[i].num_vizinhos;

		int p;

		//remove esse no de todos os seus vizinhos
		for (p = 0; p < rede->nos_grafo[i].tam_vetor_vizinhos; p++)
		{
			int indice = rede->nos_grafo[i].nos_vizinhos[p];

			rede->nos_grafo[indice].num_vizinhos--;
		}
	}
	return arestas;
}

int retorna_menor_grau_finalizado(grafo * rede)
{
	int i, grau = 999;

	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		if (rede->nos_grafo[i].grau_dsatur < grau)
		{
			grau = rede->nos_grafo[i].grau_dsatur;
		}
	}

	return grau;
}

int retorna_maior_grau_finalizado(grafo * rede)
{
	int i, grau = 0;

	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		if (rede->nos_grafo[i].grau_dsatur > grau)
		{
			grau = rede->nos_grafo[i].grau_dsatur;
		}
	}

	return grau;
}

float grau_medio_finalizado(grafo * rede)
{
	float menor_grau = (float)retorna_menor_grau_finalizado(rede);
	float maior_grau = (float)retorna_maior_grau_finalizado(rede);
	return (float)((menor_grau+maior_grau)/2.0f);
}

float desvio_padrao_finalizado(grafo * rede)
{
	float media = grau_medio_finalizado(rede);
	float desvio_individual;
	float soma_quadrados_desvio_individual = 0;

	int i;

	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		desvio_individual = rede->nos_grafo[i].grau_dsatur - media;
		soma_quadrados_desvio_individual += (desvio_individual * desvio_individual);
	}

	float media_soma_quadrados = soma_quadrados_desvio_individual / rede->tamanho_grafo;

	return (float)sqrt(media_soma_quadrados);
}

int numero_cores_finalizado(grafo * rede)
{
	int i, cor = 0;

	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		if (rede->nos_grafo[i].cor > cor) //maior valor de cor será o numero total de cores do grafo!!!
		{
			cor = rede->nos_grafo[i].cor;
		}
	}

	return cor;
}
