#include <stdlib.h>
#include <stdio.h>
#include "seqlist.h"


/**
 *	Funções internas.
 */

void sl_addAll(SeqList list, SeqList add)
{
	int l = list->size;
	int a = 0;

	for (; l < MAX_SIZE && a < add->size; l++, a++)
		list->data[l] = add->data[a];

	list->size += add->size;
}


/**
 *	Funções do usuário.
 */

SeqList sl_newSeqList()
{
	SeqList list = malloc(sizeof(struct __SeqList));
	list->size = 0;

	return list;
}

void sl_add(SeqList list, int value)
{
	if (list->size < MAX_SIZE)
	{
		list->data[list->size] = value;
		list->size++;
	}
}

int sl_get(SeqList list, unsigned int index)
{
	if (index >= list->size) return 0;
	return list->data[index];
}

int sl_removeByIndex(SeqList list, unsigned int index)
{
	if (index >= list->size) return 0;
	
	int i;
	for (i = index; i < list->size - 1; i++)
		list->data[i] = list->data[i + 1];

	list->size--;
	return 1;
}

void sl_about(SeqList list)
{
	printf("Sequential List\n");
	printf("\tSize: %d\n", list->size);

	printf("\tElements:\n\t\t");
	int i;
	for (i = 0; i < list->size; i++)
		printf("%d: %d, ", i, list->data[i]);

	printf("\n");
}

SeqList* sl_split(SeqList list)
{
	SeqList* lists = malloc(2 * sizeof(SeqList));
	lists[0] = sl_newSeqList();
	lists[1] = sl_newSeqList();
	
	int i;
	for (i = 0; i < list->size; i++)
		sl_add(lists[i % 2], list->data[i]);

	return lists;
}

SeqList sl_join(SeqList la, SeqList lb)
{
	if (la == NULL || lb == NULL)
		return NULL;

	SeqList list = sl_newSeqList();
	sl_addAll(list, la);
	sl_addAll(list, lb);

	return list;
}

int sl_set(SeqList list, unsigned int index, int value)
{
	if (index >= list->size) return 0;

	list->data[index] = value;
	return 1;
}

int sl_removeByValue(SeqList list, int value)
{
	if (list->size == 0) return -1;

	int i;
	for (i = 0; i < list->size; i++)
	{
		if (list->data[i] == value)
			return sl_removeByIndex(list, i);
	}

	return 0;
}

int sl_empty(SeqList list)
{
	return list->size == 0;
}

int sl_size(SeqList list)
{
	return list->size;
}

int sl_insert(SeqList list, unsigned int index, int value)
{
	if (index >= list->size && list->size < MAX_SIZE) return 0;

	int i;
	for (i = list->size; i > index; i--)
		list->data[i] = list->data[i - 1];

	list->data[index] = value;
	list->size++;

	return 1;
}