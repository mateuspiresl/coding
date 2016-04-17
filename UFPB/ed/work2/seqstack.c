#include <stdlib.h>
#include <stdio.h>
#include "seqstack.h"

SeqStack ss_createSeqStack(int maxSize)
{
	SeqStack s = malloc(sizeof(struct _SeqStack));
	s->data = malloc(sizeof(int) * maxSize);
	s->maxSize = maxSize;
	s->top = -1;
	return s;
}

int ss_isEmpty(SeqStack s) {
	return s->top == -1;
}

int ss_size(SeqStack s) {
	return s->top + 1;
}

int ss_isFull(SeqStack s) {
	return ss_size(s) == s->maxSize;
}

int ss_top(SeqStack s, int* mem)
{
	if (ss_isEmpty(s)) return 0;

	*mem = s->data[s->top];
	return 1;
}

int ss_push(SeqStack s, int value)
{
	if (ss_isFull(s)) return 0;

	s->top++;
	s->data[s->top] = value;
	return 1;
}

int ss_pop(SeqStack s)
{
	if (ss_isEmpty(s)) return 0;

	s->top--;
	return 1;
}

// New methods

void ss_details(SeqStack s)
{
	printf("SeqStack:\n\tSize: %d\n", ss_size(s));

	if ( ! ss_isEmpty(s))
	{
		printf("\tElements: ");

		int i;
		for (i = 0; i <= s->top; i++)
			printf("%d ", s->data[i]);
		printf("\n");
	}
}

void ss_invert(SeqStack s)
{
	int* data = malloc(sizeof(int) * s->maxSize);

	int i;
	for (i = 0; i <= s->top; i++)
		data[i] = s->data[s->top - i];

	s->data = data;
}

int ss_removeValue(SeqStack s, int value)
{
	int shift = 0;

	int i;
	for (i = 0; i <= s->top; i++)
	{
		if (s->data[i] == value)
			shift++;
		else
			s->data[i - shift] = s->data[i];
	}

	s->top -= shift;
	return shift;
}

int ss_equals(SeqStack a, SeqStack b)
{
	if (ss_isEmpty(a) && ss_isEmpty(b))
		return 1;

	if (ss_size(a) != ss_size(b))
		return 0;

	int ai = 0, bi = 0;

	while (ai <= a->top)
		if (a->data[ai++] != a->data[bi++])
			return 0;

	return 1;
}

void ss_clear(SeqStack s) {
	s->top = -1;
}