#include <stdlib.h>
#include "list.h"

List* l_createList()
{
	List* list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->comparator = NULL;
	return list;
}

void l_setComparator(List* list, int (*comparatorFunc)(void*, void*)) {
	list->comparator = comparatorFunc;
}

int l_compare(List* list, void* a, void* b)
{
	if (list->comparator == NULL)
		return (int) a - (int) b;
	else
		return (*(list->comparator))(a, b);
}

Element* l_createElement(void* value, Element* next)
{
	Element* e = malloc(sizeof(Element));
	e->value = value;
	e->next = next;
	return e;
}

void l_add(List* list, void* value)
{
	Element* e = l_createElement(value, NULL);

	if (list->tail == NULL)
	{
		list->head = e;
		list->tail = e;
		list->size = 1;
	}
	else
	{
		list->tail->next = e;
		list->tail = e;
		list->size++;
	}
}

void l_removeValue(List* list, void* value)
{
	Element* e = list->head;
	Element* previous = NULL;

	while (e != NULL)
	{
		if ((*(list->comparator))(e->value, value) == 0)
		{
			if (previous == NULL)
				list->head = e->next;
			else
				previous->next = e->next;

			list->size--;
			free(e);
			break;
		}

		previous = e;
		e = e->next;
	}
}

void l_removeIndex(List* list, int index)
{
	Element* e = list->head;
	Element* previous = NULL;

	while (index-- && e != NULL)
	{
		previous = e;
		e = e->next;
	}

	if (e != NULL)
	{
		if (previous == NULL)
			list->head = e->next;
		else
			previous->next = e->next;

		list->size--;
		free(e);
	}
}

void* l_get(List* list, int index)
{
	Element* e = list->head;

	while (index-- && e != NULL)
		e = e->next;
	
	return e->value;
}