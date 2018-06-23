#ifndef ARQUIVO_H_
#define ARQUIVO_H_

#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LINE_BUFFER 100

//le o arquivo e cria o grafo!!!
grafo* abre_csv(char* arquivo);
void imprime_grafo(grafo* rede);

#endif // !ARQUIVO_H_