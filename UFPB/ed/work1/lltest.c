#include <stdio.h>
#include "linkedlist.h"

int main()
{
	LinkedList list = ll_newLinkedList();

	printf("Adicionando 10, 100, 21 e 76:\n");
	ll_add(list, 10);
	ll_add(list, 100);
	ll_add(list, 21);
	ll_add(list, 76);
	ll_about(list);

	printf("Consultando valor na posição 2: %d\n", ll_get(list, 2));

	printf("Removendo elemento na posição 1: %d\n", ll_removeByIndex(list, 1));
	ll_about(list);

	printf("Removendo elemento com valor 76: %d\n", ll_removeByValue(list, 76));
	ll_about(list);

	printf("Adicionando 100:\n");
	ll_add(list, 100);
	ll_about(list);

	printf("Removendo elemento na posição 0: %d\n", ll_removeByIndex(list, 0));
	ll_about(list);

	printf("Alterando valor para 430 na posição 1: %d\n", ll_set(list, 1, 430));
	ll_about(list);

	printf("Adicionando 10, 100, 21 e 76:\n");
	ll_add(list, 10);
	ll_add(list, 100);
	ll_add(list, 21);
	ll_add(list, 76);
	ll_about(list);

	printf("Partindo a lista em duas:\n");
	LinkedList* lists = ll_split(list);
	ll_about(lists[0]);
	ll_about(lists[1]);

	printf("Juntando as duas listas:\n");
	LinkedList joined = ll_join(lists[0], lists[1]);
	ll_about(joined);

	printf("Inserindo 444 na posição 0 e 555 na posição 5:\n");
	ll_insert(joined, 0, 444);
	ll_insert(joined, 5, 555);
	ll_about(joined);

	return 0;
}