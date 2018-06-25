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

//grava as cores no arquivo csv
void grava_csv(char* arquivo, grafo* rede);

#endif // !ARQUIVO_H_