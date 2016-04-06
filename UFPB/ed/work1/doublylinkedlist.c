#include <stdlib.h>
#include <stdio.h>
#include "doublylinkedlist.h"


/**
 *	Internal methods.
 */

Node dll_newNode(int value)
{
	Node node = malloc(sizeof(struct __Node));
	node->value = value;
	node->previous = NULL;
	node->next = NULL;

	return node;
}

Node dll_at(DoublyLinkedList list, unsigned int index)
{
	if (index >= list->size) return NULL;
	
	Node node = list->head;

	while (index--)
		node = node->next;

	return node;
}

int dll_remove(DoublyLinkedList list, Node node)
{
	if (list->size == 0) return 0;

	if (node == list->head)
		list->head = node->next;
	else
		node->previous->next = node->next;

	if (node == list->tail)
		list->tail = node->previous;
	else
		node->next->previous = node->previous;
	
	free(node);
	list->size--;

	return 1;
}

void dll_addAll(DoublyLinkedList list, Node node)
{
	while (node != NULL)
	{
		dll_add(list, node->value);
		node = node->next;
	}
}


/**
 *	User methods.
 */

DoublyLinkedList dll_newDoublyLinkedList()
{
	DoublyLinkedList list = malloc(sizeof(struct __DoublyLinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

void dll_add(DoublyLinkedList list, int value)
{
	Node node = dll_newNode(value);

	if (list->tail != NULL)
	{
		list->tail->next = node;
		node->previous = list->tail;
	}

	list->tail = node;
	list->size++;
	
	if (list->head == NULL)
		list->head = list->tail;
}

int dll_get(DoublyLinkedList list, unsigned int index)
{
	Node found = dll_at(list, index);
	return found != NULL ? found->value : -1;
}

int dll_removeByIndex(DoublyLinkedList list, unsigned int index)
{
	return dll_remove(list, dll_at(list, index));
}

void dll_about(DoublyLinkedList list)
{
	printf("Doubly Linked List\n");
	printf("\tSize: %d\n", list->size);

	Node node = list->head;

	printf("\tElements:\n\t\t");
	int i = 0;
	while (node != NULL)
	{
		printf("%d: %d, ", i++, node->value);
		node = node->next;
	}

	printf("\n");
}

DoublyLinkedList* dll_split(DoublyLinkedList list)
{
	DoublyLinkedList* lists = malloc(2 * sizeof(DoublyLinkedList));
	lists[0] = dll_newDoublyLinkedList();
	lists[1] = dll_newDoublyLinkedList();
	
	Node node = list->head;

	int i;
	for (i = 0; i < list->size; i++)
	{
		dll_add(lists[i % 2], node->value);
		node = node->next;
	}

	return lists;
}

DoublyLinkedList dll_join(DoublyLinkedList la, DoublyLinkedList lb)
{
	if (la == NULL || lb == NULL)
		return NULL;

	DoublyLinkedList list = dll_newDoublyLinkedList();
	dll_addAll(list, la->head);
	dll_addAll(list, lb->head);

	return list;
}

int dll_set(DoublyLinkedList list, unsigned int index, int value)
{
	Node node = dll_at(list, index);

	if (node != NULL)
	{
		node->value = value;
		return 1;
	}

	return 0;
}

int dll_removeByValue(DoublyLinkedList list, int value)
{
	if (list->size == 0) return 0;

	Node node = list->head;

	while (node != NULL && node->value != value)
		node = node->next;

	if (node != NULL)
		return dll_remove(list, node);

	return 0;
}

int dll_empty(DoublyLinkedList list)
{
	return list->size == 0;
}

int dll_size(DoublyLinkedList list)
{
	return list->size;
}

int dll_insert(DoublyLinkedList list, unsigned int index, int value)
{
	if (index > list->size) return 0;

	if (index == list->size)
	{
		dll_add(list, value);
		return 1;
	}

	Node there = dll_at(list, index);
	Node node = dll_newNode(value);

	node->previous = there->previous;
	node->next = there;

	if (there == list->head)
		list->head = node;
	else
		there->previous->next = node;
	
	there->previous = node;

	list->size++;
	return 1;
}