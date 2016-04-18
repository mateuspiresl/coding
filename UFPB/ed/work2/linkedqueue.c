#include <stdlib.h>
#include <stdio.h>
#include "linkedqueue.h"

LinkedQueue lq_create(int maxSize)
{
	LinkedQueue q = malloc(sizeof(struct _LinkedQueue));
	q->first = NULL;
	q->last = NULL;
	q->size = 0;
	return q;
}

lq_Element lq_createElement(int value, lq_Element next)
{
	lq_Element e = malloc(sizeof(struct _lq_Element));
	e->value = value;
	e->next = next;
	return e;
}

int lq_isEmpty(const LinkedQueue q) {
	return q->size == 0;
}

int lq_size(const LinkedQueue q) {
	return q->size;
}

int lq_front(const LinkedQueue q, int* mem)
{
	if (q->size == 0) return 0;

	*mem = q->first->value;
	return 1;
}

void lq_push(LinkedQueue q, int value)
{
	lq_Element e = lq_createElement(value, NULL);

	if (q->last != NULL)
		q->last->next = e;
	else
		q->first = e;

	q->last = e;
	q->size++;
}

int lq_pop(LinkedQueue q)
{
	if (q->size == 0) return 0;

	lq_Element e = q->first;
	q->first = q->first->next;
	q->size--;

	free(e);
	return 1;
}


// Novas funcionalidades

void lq_details(const LinkedQueue q)
{
	printf("LinkedQueue:\n\tSize: %d\n", q->size);

	if ( ! lq_isEmpty(q))
	{
		printf("\tElements:");

		lq_Element e = q->first;
		
		while (e != NULL)
		{
			printf(" %d", e->value);
			e = e->next;
		}
		printf("\n");
	}
}

int lq_find(const LinkedQueue q, int value)
{
	lq_Element e = q->first;

	int i;
	for (i = 1; i <= q->size; i++)
	{
		if (e->value == value)
			return i;

		e = e->next;
	}

	return 0;
}

int lq_interc(const LinkedQueue fromA, const LinkedQueue fromB, LinkedQueue to)
{
	// Erro nos casos:
	//		O tamanho de $fromA e $fromB são diferentes
	//		$to não é uma lista vazia
	if (fromA->size != fromB->size || ! lq_isEmpty(to))
		return 0;

	// Se $fromA estiver vazia, o preenchimento não modifica nada
	if (lq_isEmpty(fromA))
		return 1;

	lq_Element eA = fromA->first;
	lq_Element eB = fromB->first;

	while (eA != NULL)
	{
		lq_push(to, eA->value);
		lq_push(to, eB->value);

		eA = eA->next;
		eB = eB->next;
	}

	return 1;
}

void lq_pushReversed(LinkedQueue reversed, lq_Element from)
{
	if (from->next != NULL)
		lq_pushReversed(reversed, from->next);

	lq_push(reversed, from->value);
}

void lq_reverse(const LinkedQueue q, LinkedQueue reversed)
{
	if (lq_isEmpty(q)) return;
	lq_pushReversed(reversed, q->first);
}