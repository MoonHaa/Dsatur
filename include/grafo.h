#ifndef  GRAFO_H_
#define GRAFO_H_

#include "no.h"
#include <stdlib.h>

typedef struct grafo
{
	int tamanho_grafo;
	no* nos_grafo;
}grafo;

//destroi o grafo
void free_grafo(grafo* grafico);

//tirar
int get_indice_no_numero(grafo* rede, int valor);

#endif // ! GRAFO_H_
