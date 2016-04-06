#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct __Node {
	int value;
	struct __Node* next;
};
typedef struct __Node* Node;

struct __LinkedList {
	Node head;
	Node tail;
	int size;
};
typedef struct __LinkedList* LinkedList;

/*	Cria uma lista vazia. */
LinkedList ll_newLinkedList();

/* Adiciona um nó ao final da lista. */
int ll_empty(LinkedList list);

/* Adiciona um nó ao final da lista. */
int ll_size(LinkedList list);

/* Cria um nó e adiciona ao final da lista. */
void ll_add(LinkedList list, int value);

/* Adiciona um valor em determinado índice. */
int ll_insert(LinkedList list, unsigned int index, int value);

/* Retorna o valor por índice do nó. */
int ll_get(LinkedList list, unsigned int index);

/* Altera o valor de um nó pelo índice. */
int ll_set(LinkedList list, unsigned int index, int value);

/* Remove o nó pelo índice. */
int ll_removeByIndex(LinkedList list, unsigned int index);

/* Remove um nó pelo valor. */
int ll_removeByValue(LinkedList list, int value);

/* Imprime as informações da lista na saída padrão. */
void ll_about(LinkedList list);

/* Retorna duas listas, uma com os elementos de índice par e a outra
 *		com os elementos de índice ímpar. */
LinkedList* ll_split(LinkedList list);

/* Retorna a junção de duas listas. */
LinkedList ll_join(LinkedList la, LinkedList lb);

#endif