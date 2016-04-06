#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct __Node {
	int value;
	struct __Node* previous;
	struct __Node* next;
};
typedef struct __Node* Node;

struct __DoublyLinkedList {
	Node head;
	Node tail;
	int size;
};
typedef struct __DoublyLinkedList* DoublyLinkedList;

/*	Cria uma lista vazia. */
DoublyLinkedList dll_newDoublyLinkedList();

/* Adiciona um nó ao final da lista. */
int dll_empty(DoublyLinkedList list);

/* Adiciona um nó ao final da lista. */
int dll_size(DoublyLinkedList list);

/* Cria um nó e adiciona ao final da lista. */
void dll_add(DoublyLinkedList list, int value);

/* Adiciona um valor em determinado índice. */
int dll_insert(DoublyLinkedList list, unsigned int index, int value);

/* Retorna o valor por índice do nó. */
int dll_get(DoublyLinkedList list, unsigned int index);

/* Altera o valor de um nó pelo índice. */
int dll_set(DoublyLinkedList list, unsigned int index, int value);

/* Remove o nó pelo índice. */
int dll_removeByIndex(DoublyLinkedList list, unsigned int index);

/* Remove um nó pelo valor. */
int dll_removeByValue(DoublyLinkedList list, int value);

/* Imprime as informações da lista na saída padrão. */
void dll_about(DoublyLinkedList list);

/* Retorna duas listas, uma com os elementos de índice par e a outra
 *		com os elementos de índice ímpar. */
DoublyLinkedList* dll_split(DoublyLinkedList list);

/* Retorna a junção de duas listas. */
DoublyLinkedList dll_join(DoublyLinkedList la, DoublyLinkedList lb);

#endif