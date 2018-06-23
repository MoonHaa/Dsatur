#ifndef DSATUR_H_
#define DSATUR_H_

#include "no.h"
#include "grafo.h"

#include <stdlib.h>

int dsatur(grafo* rede);
void colorir(grafo* rede, int indice, int* maior_cor);
void inicializar_grafo(grafo* rede);
int indice_proximo_colorir(grafo* rede);
int is_todos_coloridos(grafo* rede);
void atualizar_dsatur_e_vizinhos(grafo* rede, int indice);

#endif // !DSATUR_H_
