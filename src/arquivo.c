#include "arquivo.h"

grafo * abre_csv(char * arquivo)
{
	//tenta abrir o arquivo
	FILE* file = fopen(arquivo, "r");

	//caso falhe, retorna NULL
	if (file == NULL)
		return NULL;

	char linha[LINE_BUFFER];
	int numero_linhas = 0;

	//conta 1 a mais por conta do EOF no final do arquivo!!!
	while (!feof(file))
	{
		fgets(linha, LINE_BUFFER, file);
		numero_linhas++;
	}

	//volta pro inicio do arquivo
	rewind(file);

	//cria base do grafo
	grafo* grafico = (grafo*)malloc(sizeof(grafo));

	//seta tamanho de nos no grafo (cada no eh o inicio de uma linha)
	grafico->tamanho_grafo = numero_linhas - 1;

	//cria o vetor de nos do grafo
	grafico->nos_grafo = (no*)malloc(grafico->tamanho_grafo * sizeof(no));

	//contador pra criacao do grafo em ordem
	int i;

	//le as i linhas novamente, contabilizando o valor do nos, e as suas relacoes!!!
	for(i = 0; i <(numero_linhas-1); i++)
	{
		//le a linha
		fgets(linha, LINE_BUFFER, file);

		//seta cor do no pra 0
		grafico->nos_grafo[i].cor = 0;
		//seta grau dsatur pra 0
		grafico->nos_grafo[i].grau_dsatur = 0;

		//conta numero de digitos numericos da linha
		int num_digitos = 0;

		//percorre a string, contando a quantidade de nos
		int p, tamanho_linha = strlen(linha);
		for (p = 0; p < tamanho_linha; p++)
		{
			if (isdigit(linha[p])) //verifica se posicao na string eh um digito numerico
			{
				if(p == 0) //se ele for o primeiro digito da string, considera um numero
					num_digitos++;
				else
				{
					if (!isdigit(linha[p - 1])) //se a posicao anterior nao for um digito, considera um numero
						num_digitos++;			//caso seja, ele jah foi considerado antes...
				}
			}
		}

		//seta o numero de adjacencias
		grafico->nos_grafo[i].num_vizinhos = num_digitos - 1;
		//seta o numero de adjacencias originais
		grafico->nos_grafo[i].tam_vetor_vizinhos = num_digitos - 1;

		//cria o vetor de adjacencias
		grafico->nos_grafo[i].nos_vizinhos = (int*)malloc(grafico->nos_grafo[i].tam_vetor_vizinhos * sizeof(int));

		//le os valores na string
		char *pos = linha;
		//auxiliares
		int valor, q = 0;
		while (*pos)
		{
			if (isdigit(*pos))
			{
				valor = strtol(pos, &pos, 10);
				if (q == 0) //primeiro numero da linha eh o valor do no
				{
					grafico->nos_grafo[i].valor_no = valor;
				}
				else //caso contrario, eh um dos nos adjacentes a ele
				{
					grafico->nos_grafo[i].nos_vizinhos[q - 1] = valor;
				}
				q++;
			}
			else
				pos++;
		}
	}

	//fecha o arquivo
	fclose(file);

	//retorna o grafo criado
	return grafico;
}

void grava_csv(char * arquivo, grafo * rede)
{
	int tamanho_string = strlen(arquivo);
	char *string = (char*)malloc( (tamanho_string + 4) * sizeof(char));

	int i;

	for (i = 0; i < (tamanho_string - 4); i++)
	{
		string[i] = arquivo[i];
	}

	string[tamanho_string - 4 + 0] = '_';
	string[tamanho_string - 4 + 1] = 'o';
	string[tamanho_string - 4 + 2] = 'u';
	string[tamanho_string - 4 + 3] = 't';
	string[tamanho_string - 4 + 4] = '.';
	string[tamanho_string - 4 + 5] = 'c';
	string[tamanho_string - 4 + 6] = 's';
	string[tamanho_string - 4 + 7] = 'v';
	string[tamanho_string - 4 + 8] = '\0';

	FILE* file = fopen(string, "w");

	if (file == NULL)
	{
		return; //erro!!! nao foi possivel abrir o arquivo!!!
	}

	for (i = 0; i < rede->tamanho_grafo; i++)
	{
		fprintf(file, "%i, %i\n", rede->nos_grafo[i].valor_no, rede->nos_grafo[i].cor);
	}

	fclose(file);

	free(string);
}
