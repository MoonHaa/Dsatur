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

#endif // ! GRAFO_H_