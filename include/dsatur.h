#ifndef DSATUR_H_
#define DSATUR_H_

#include "no.h"
#include "grafo.h"

#include <stdlib.h>
#include <math.h>

//função principal
void dsatur(grafo* rede);

//verifica se o grafo já foi todo colorido
int verifica_grafo_colorido(grafo* rede);

//procura pelo vertice com maior grau dsatur ainda não colorido
int procura_maior_grau(grafo* rede);

//procura pelo menor valor de cor disponivel para um vertice, ou seja,
//percorre os vizinhos do vertice e verifica pelo menor valor de cor disponivel
int procura_menor_valor_cor(grafo* rede, int indice);

//aumenta o grau dos nos adjacentes ao vertice informado
void aumenta_grau_vizinho(grafo* rede, int indice);

//atualiza o grau final do grafo
void update_grau_final(grafo* rede);

//contabiliza o numero de aresta do grafo
int conta_arestas(grafo* rede);

//procura o menor grau do grafo finalizado
int retorna_menor_grau_finalizado(grafo* rede);

//procura o maior grau do grafo finalizado
int retorna_maior_grau_finalizado(grafo* rede);

//calcula o grau medio do grafo finalizado
float grau_medio_finalizado(grafo* rede);

//calcula o desvio padrao do grafo finalizado
float desvio_padrao_finalizado(grafo* rede);

//conta o numero de cores do grafo finalizado
int numero_cores_finalizado(grafo* rede);

#endif // !DSATUR_H_
