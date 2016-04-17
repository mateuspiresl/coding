#include <stdio.h>
#include "linkedstack.h"

int main()
{
	LinkedStack s = ls_createLinkedStack(10);

	printf("Pilha está vazia? %s\n", ls_isEmpty(s) ? "Sim." : "Não.");

	printf("Empilhando 17.\n");
	ls_push(s, 17);

	printf("Empilhando 41.\n");
	ls_push(s, 41);

	printf("Pilha está vazia? %s\n", ls_isEmpty(s) ? "Sim." : "Não.");
	printf("Tamanho da pilha: %d\n", ls_size(s));
	int value; ls_top(s, &value);
	printf("Topo da pilha: %d\n", value);

	printf("Empilhando 25.\n");
	ls_push(s, 25);

	printf("Detalhes da pilha:\n");
	ls_details(s);

	printf("Desempilhando 25.\n");
	ls_pop(s);

	printf("Empilhando 10 e 41.\n");
	ls_push(s, 10);
	ls_push(s, 41);

	ls_details(s);

	printf("Invertendo pilha.\n");
	ls_invert(s);
	ls_details(s);

	printf("Removendo todos os valores 41.\n");
	ls_removeValue(s, 41);
	ls_details(s);

	printf("Criando pilha 2 e empilhando 10.\n");
	LinkedStack s2 = ls_createLinkedStack(8);
	ls_push(s2, 10);

	printf("Detalhes da pilha 2:\n");
	ls_details(s2);

	printf("Pilha 1 e 2 são iguais? %s\n", ls_equals(s, s2) ? "Sim." : "Não.");

	printf("Empilhando 17.\n");
	ls_push(s2, 17);
	
	printf("Detalhes da pilha 1:\n");
	ls_details(s);
	
	printf("Detalhes da pilha 2:\n");
	ls_details(s2);

	printf("Pilha 1 e 2 são iguais? %s\n", ls_equals(s, s2) ? "Sim." : "Não.");

	printf("Esvaziando pilha 2.\n");
	ls_clear(s2);

	printf("Detalhes da pilha 2:\n");
	ls_details(s2);

	return 0;
}