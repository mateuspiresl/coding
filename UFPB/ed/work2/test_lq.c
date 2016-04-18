#include <stdio.h>
#include "linkedqueue.h"

int main()
{
	LinkedQueue q = lq_create(10);

	printf("Fila está vazia? %s\n", lq_isEmpty(q) ? "Sim." : "Não.");

	printf("Enfileirando 17.\n");
	lq_push(q, 17);

	printf("Enfileirando 41.\n");
	lq_push(q, 41);

	printf("Fila está vazia? %s\n", lq_isEmpty(q) ? "Sim." : "Não.");
	printf("Tamanho da fila: %d\n", lq_size(q));
	int value; lq_front(q, &value);
	printf("Frente da fila: %d\n", value);

	printf("Enfileirando 25.\n");
	lq_push(q, 25);

	printf("Detalhes da fila:\n");
	lq_details(q);

	printf("Desenfileirando 17.\n");
	lq_pop(q);

	printf("Enfileirando 10 e 41.\n");
	lq_push(q, 10);
	lq_push(q, 41);

	printf("Detalhes da fila 1:\n");
	lq_details(q);

	printf("Índice do elemento de valor 10: %d\n", lq_find(q, 10));

	printf("Criando fila 2 com elementos de valor 0, 41, 25 e 10.\n");
	LinkedQueue q2 = lq_create(10);
	lq_push(q2, 0);
	lq_push(q2, 41);
	lq_push(q2, 25);
	lq_push(q2, 10);

	printf("\nDetalhes da fila 1:\n");
	lq_details(q);

	printf("Detalhes da fila 2:\n");
	lq_details(q2);

	printf("Criando fila 3 vazia.\n");
	LinkedQueue q3 = lq_create(10);

	printf("Detalhes da fila 3:\n");
	lq_details(q3);

	printf("\nIntercalando valores das filas 1 e 2 na fila 3.\n");
	lq_interc(q, q2, q3);

	printf("Detalhes da fila 3:\n");
	lq_details(q3);

	printf("\nTamanho da fila 3: %d.\n", lq_size(q3));
	printf("Adicionando 5 no final da fila 3.\n");
	lq_push(q3, 5);
	printf("Tamanho da fila 3: %d.\n", lq_size(q3));
	printf("Adicionando 5 no final da fila 3.\n");
	lq_push(q3, 5);
	printf("Tamanho da fila 3: %d.\n", lq_size(q3));
	printf("Adicionando 5 no final da fila 3.\n");
	lq_push(q3, 5);
	printf("Tamanho da fila 3: %d.\n", lq_size(q3));
	printf("Detalhes da fila 3:\n");
	lq_details(q3);

	printf("\nCriando fila 4 vazia.\n");
	LinkedQueue q4 = lq_create(10);

	printf("Invertendo fila 3 na fila 4.\n");
	lq_reverse(q3, q4);

	printf("Detalhes da fila 4:\n");
	lq_details(q4);

	return 0;
}