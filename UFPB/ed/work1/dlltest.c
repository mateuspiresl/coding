#include <stdio.h>
#include "doublylinkedlist.h"

int main()
{
	DoublyLinkedList list = dll_newDoublyLinkedList();

	printf("Adicionando 10, 100, 21 e 76:\n");
	dll_add(list, 10);
	dll_add(list, 100);
	dll_add(list, 21);
	dll_add(list, 76);
	dll_about(list);

	printf("Consultando valor na posição 2: %d\n", dll_get(list, 2));

	printf("Removendo elemento na posição 1: %d\n", dll_removeByIndex(list, 1));
	dll_about(list);

	printf("Removendo elemento com valor 76: %d\n", dll_removeByValue(list, 76));
	dll_about(list);

	printf("Adicionando 100:\n");
	dll_add(list, 100);
	dll_about(list);

	printf("Removendo elemento na posição 0: %d\n", dll_removeByIndex(list, 0));
	dll_about(list);

	printf("Alterando valor para 430 na posição 1: %d\n", dll_set(list, 1, 430));
	dll_about(list);

	printf("Adicionando 10, 100, 21 e 76:\n");
	dll_add(list, 10);
	dll_add(list, 100);
	dll_add(list, 21);
	dll_add(list, 76);
	dll_about(list);

	printf("Partindo a lista em duas:\n");
	DoublyLinkedList* lists = dll_split(list);
	dll_about(lists[0]);
	dll_about(lists[1]);

	printf("Juntando as duas listas:\n");
	DoublyLinkedList joined = dll_join(lists[0], lists[1]);
	dll_about(joined);

	printf("Inserindo 444 na posição 0 e 555 na posição 5:\n");
	dll_insert(joined, 0, 444);
	dll_insert(joined, 5, 555);
	dll_about(joined);

	return 0;
}