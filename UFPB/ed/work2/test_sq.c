#include <stdio.h>
#include "seqqueue.h"

int main()
{
	SeqQueue q = sq_create(10);

	printf("Fila está vazia? %s\n", sq_isEmpty(q) ? "Sim." : "Não.");

	printf("Enfileirando 17.\n");
	sq_push(q, 17);

	printf("Enfileirando 41.\n");
	sq_push(q, 41);

	printf("Fila está vazia? %s\n", sq_isEmpty(q) ? "Sim." : "Não.");
	printf("Fila está cheia? %s\n", sq_isFull(q) ? "Sim." : "Não.");
	printf("Tamanho da fila: %d\n", sq_size(q));
	int value; sq_front(q, &value);
	printf("Frente da fila: %d\n", value);

	printf("Enfileirando 25.\n");
	sq_push(q, 25);

	printf("Detalhes da fila:\n");
	sq_details(q);

	printf("Desenfileirando 17.\n");
	sq_pop(q);

	printf("Enfileirando 10 e 41.\n");
	sq_push(q, 10);
	sq_push(q, 41);

	printf("Detalhes da fila 1:\n");
	sq_details(q);

	printf("Índice do elemento de valor 10: %d\n", sq_find(q, 10));

	printf("Criando fila 2 com elementos de valor 100 a 103.\n");
	SeqQueue q2 = sq_create(10);
	sq_push(q2, 0);
	sq_push(q2, 41);
	sq_push(q2, 25);
	sq_push(q2, 10);

	printf("\nDetalhes da fila 1:\n");
	sq_details(q);

	printf("Detalhes da fila 2:\n");
	sq_details(q2);

	printf("Criando fila 3 vazia.\n");
	SeqQueue q3 = sq_create(10);

	printf("Detalhes da fila 3:\n");
	sq_details(q3);

	printf("\nIntercalando valores das filas 1 e 2 na fila 3.\n");
	sq_interc(q, q2, q3);

	printf("Detalhes da fila 3:\n");
	sq_details(q3);

	printf("\nTamanho da fila 3: %d.\n", sq_size(q3));
	printf("Adicionando 5 no final da fila 3: %s.\n", sq_push(q3, 5) ? "Feito" : "Falha");
	printf("Tamanho da fila 3: %d.\n", sq_size(q3));
	printf("Adicionando 5 no final da fila 3: %s.\n", sq_push(q3, 5) ? "Feito" : "Falha");
	printf("Tamanho da fila 3: %d.\n", sq_size(q3));
	printf("Adicionando 5 no final da fila 3: %s.\n", sq_push(q3, 5) ? "Feito" : "Falha");
	printf("Tamanho da fila 3: %d.\n", sq_size(q3));
	printf("Detalhes da fila 3:\n");
	sq_details(q3);

	printf("\nCriando fila 4 vazia.\n");
	SeqQueue q4 = sq_create(10);

	printf("Invertendo fila 3 na fila 4.\n");
	sq_reverse(q3, q4);

	printf("Detalhes da fila 4:\n");
	sq_details(q4);

	return 0;
}