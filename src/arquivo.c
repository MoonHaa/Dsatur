#include "arquivo.h"

grafo * abre_csv(char * arquivo)
{
	//tenta abrir o arquivo
	FILE* file = fopen(arquivo, "r");
	
	//caso falhe, retorna NULL
	if (file == NULL)
		return NULL;

	char* linha = NULL;
	size_t tamanho = 0;
	size_t n_char_lido = 0;

	while ((n_char_lido = getline(&linha, &tamanho, file)) != -1)
	{
		printf("n_char_lido: %i , tamanho: %i\n", n_char_lido, tamanho);
		printf("%s\n", linha);
	}

	/*while (!feof(file))
	{

	}*/

	//enquanto nao eof
		//conta linha
	//reset
	//cria grafo
		//cria vetor na grafo
	//enquanto nao eof
		//le linha
			//cria vetor de relacoes

	//fecha o arquivo
	fclose(file);
	
	//default nunca deve chegar aqui!!!
	return NULL;
}
