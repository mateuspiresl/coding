#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"


/**
 *	Internal methods.
 */

Node ll_newNode(int value)
{
	Node node = malloc(sizeof(struct __Node));
	node->value = value;
	node->next = NULL;

	return node;
}

Node ll_previous(LinkedList list, unsigned int index)
{
	if (index == 0) return NULL;

	Node node = list->head;

	while (--index)
	{
		if (node == NULL)
			return NULL;

		node = node->next;
	}

	return node;
}

Node ll_at(LinkedList list, unsigned int index)
{
	if (index >= list->size) return NULL;
	if (index == 0) return list->head;

	Node previous = ll_previous(list, index);
	return previous != NULL && previous->next != NULL ? previous->next : NULL;
}

int ll_remove(LinkedList list, Node previous)
{
	if (list->size == 0)
		return 0;

	Node node;

	if (previous == NULL)
	{
		node = list->head;
		list->head = node->next;
	}
	else
	{
		node = previous->next;
		previous->next = node->next;
		
		if (node == list->tail)
			list->tail = previous;
	}
	
	free(node);
	list->size--;

	return 1;
}

void ll_addAll(LinkedList list, Node node)
{
	while (node != NULL)
	{
		ll_add(list, node->value);
		node = node->next;
	}
}


/**
 *	User methods.
 */

LinkedList ll_newLinkedList()
{
	LinkedList list = malloc(sizeof(struct __LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

void ll_add(LinkedList list, int value)
{
	Node node = ll_newNode(value);

	if (list->tail != NULL)
		list->tail->next = node;

	list->tail = node;
	list->size += 1;
	
	if (list->head == NULL)
		list->head = list->tail;
}

int ll_get(LinkedList list, unsigned int index)
{
	Node found = ll_at(list, index);
	return found != NULL ? found->value : -1;
}

int ll_removeByIndex(LinkedList list, unsigned int index)
{
	if (index >= list->size) return 0;
	return ll_remove(list, ll_previous(list, index));
}

void ll_about(LinkedList list)
{
	printf("Linked List\n");
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

LinkedList* ll_split(LinkedList list)
{
	LinkedList* lists = malloc(2 * sizeof(LinkedList));
	lists[0] = ll_newLinkedList();
	lists[1] = ll_newLinkedList();
	
	Node node = list->head;

	int i;
	for (i = 0; i < list->size; i++)
	{
		ll_add(lists[i % 2], node->value);
		node = node->next;
	}

	return lists;
}

LinkedList ll_join(LinkedList la, LinkedList lb)
{
	if (la == NULL || lb == NULL)
		return NULL;

	LinkedList list = ll_newLinkedList();
	ll_addAll(list, la->head);
	ll_addAll(list, lb->head);

	return list;
}

int ll_set(LinkedList list, unsigned int index, int value)
{
	Node node = ll_at(list, index);

	if (node != NULL)
		node->value = value;
	else
		return 0;

	return 1;
}

int ll_removeByValue(LinkedList list, int value)
{
	if (list->size == 0)
		return 0;

	Node node = list->head;

	if (node->value == value)
	{
		ll_remove(list, NULL);
		return 1;
	}
	else
	{
		int i;
		for (i = 0; i < list->size - 1; i++)
		{
			if (node->next->value == value)
				return ll_remove(list, node) ? i + 1 : -1;
			else
				node = node->next;
		}
	}

	return 0;
}

int ll_empty(LinkedList list)
{
	return list->size == 0;
}

int ll_size(LinkedList list)
{
	return list->size;
}

int ll_insert(LinkedList list, unsigned int index, int value)
{
	if (index > list->size) return 0;

	if (index == list->size)
	{
		ll_add(list, value);
		return 1;
	}

	Node previous = ll_previous(list, index);
	Node node = ll_newNode(value);

	if (previous == NULL)
	{
		node->next = list->head;
		list->head = node;
	}
	else
	{
		node->next = previous->next;
		previous->next = node;
	}

	list->size++;
	return 1;
}