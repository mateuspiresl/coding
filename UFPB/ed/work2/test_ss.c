#include <stdio.h>
#include "seqstack.h"

int main()
{
	SeqStack s = ss_create(10);

	printf("Pilha está vazia? %s\n", ss_isEmpty(s) ? "Sim." : "Não.");

	printf("Empilhando 17.\n");
	ss_push(s, 17);

	printf("Empilhando 41.\n");
	ss_push(s, 41);

	printf("Pilha está vazia? %s\n", ss_isEmpty(s) ? "Sim." : "Não.");
	printf("Pilha está cheia? %s\n", ss_isFull(s) ? "Sim." : "Não.");
	printf("Tamanho da pilha: %d\n", ss_size(s));
	int value; ss_top(s, &value);
	printf("Topo da pilha: %d\n", value);

	printf("Empilhando 25.\n");
	ss_push(s, 25);

	printf("Detalhes da pilha:\n");
	ss_details(s);

	printf("Desempilhando 25.\n");
	ss_pop(s);

	printf("Empilhando 10 e 41.\n");
	ss_push(s, 10);
	ss_push(s, 41);

	ss_details(s);

	printf("Invertendo pilha.\n");
	ss_invert(s);
	ss_details(s);

	printf("Removendo todos os valores 41.\n");
	ss_removeValue(s, 41);
	ss_details(s);

	printf("Criando pilha 2 e empilhando 10.\n");
	SeqStack s2 = ss_create(8);
	ss_push(s2, 10);

	printf("Detalhes da pilha 2:\n");
	ss_details(s2);

	printf("Pilha 1 e 2 são iguais? %s\n", ss_equals(s, s2) ? "Sim." : "Não.");

	printf("Empilhando 17.\n");
	ss_push(s2, 17);
	
	printf("Detalhes da pilha 1:\n");
	ss_details(s);
	
	printf("Detalhes da pilha 2:\n");
	ss_details(s2);

	printf("Pilha 1 e 2 são iguais? %s\n", ss_equals(s, s2) ? "Sim." : "Não.");

	printf("Esvaziando pilha 2.\n");
	ss_clear(s2);

	printf("Detalhes da pilha 2:\n");
	ss_details(s2);

	return 0;
}