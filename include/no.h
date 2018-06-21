#ifndef NO_H_
#define NO_H_

typedef struct no 
{
	int valor_no;
	int* nos_vizinhos;
	int tam_vetor_vizinhos;
	int num_vizinhos;
	int grau_dsatur;
	int cor;
}no;

int is_number_related(grafo* rede, int indice, int number);

#endif // !NO_H_
