#include <stdlib.h>
#include <stdio.h>
#include "linkedstack.h"

LinkedStack ls_create()
{
	LinkedStack s = malloc(sizeof(LinkedStack));
	s->top = NULL;
	s->size = 0;
	return s;
}

ls_Element ls_createElement(int value, ls_Element next)
{
	ls_Element e = malloc(sizeof(struct _ls_Element));
	e->value = value;
	e->next = next;
	return e;
}

int ls_isEmpty(LinkedStack s) {
	return s->size == 0;
}

int ls_size(LinkedStack s) {
	return s->size;
}

int ls_top(LinkedStack s, int* mem)
{
	if (ls_isEmpty(s)) return 0;

	*mem = s->top->value;
	return 1;
}

void ls_push(LinkedStack s, int value)
{
	ls_Element e = ls_createElement(value, s->top);
	s->top = e;
	s->size++;
}

int ls_pop(LinkedStack s)
{
	if (s->top == NULL) return 0;

	ls_Element e = s->top;
	s->top = e->next;
	s->size--;

	free(e);
	return 1;
}

// New methods

/* Escreve todos os elementos do primeiro até $e.
 * Recursividade necessária para armazenar todos os elementos até chegar no primeiro.
 * Em backtrack, escreve os valores na ordem. */
void ls_printElements(ls_Element e)
{
	if (e->next != NULL)
		ls_printElements(e->next);

	printf("%d ", e->value);
}

void ls_details(LinkedStack s)
{
	printf("LinkedStack:\n\tSize: %d\n", s->size);

	if ( ! ls_isEmpty(s))
	{
		printf("\tElements: ");
		ls_printElements(s->top);
		printf("\n");
	}
}

/* Troca a diração dos pronteiros next. Fazendo com que a pilha seja invertida.
 * Aponta o next de $e para $update e recursivamente aponta o next
 * 		do proximo elemento de $e para $e.
 * Ao chegar no fim ($e == NULL), atualiza o topo da pilha para $e, que
 *		significa que a inversão está completa e esse $e, que era o último
 *		elemento, agora, é o primeiro. */
void ls_invertNext(LinkedStack s, ls_Element e, ls_Element update)
{
	if (e != NULL)
	{
		ls_invertNext(s, e->next, e);
		e->next = update;
	}
	else s->top = update;
}

void ls_invert(LinkedStack s) {
	ls_invertNext(s, s->top, NULL);
}

int ls_removeValue(LinkedStack s, int value)
{
	if (ls_isEmpty(s)) return 0;

	int removed = 0;
	ls_Element e = s->top;
	ls_Element* toE = &(s->top);

	while (e != NULL)
	{
		if (e->value == value)
		{
			ls_Element next = e->next;
			*toE = next;
			free(e);

			e = next;
			removed++;
			s->size--;
		}
		else
		{
			toE = &(e->next);
			e = e->next;
		}
	}

	return removed;
}

int ls_equals(LinkedStack a, LinkedStack b)
{
	ls_Element ea, eb;
	ea = a->top;
	eb = b->top;

	while (1)
	{
		if (ea == NULL && eb == NULL)
			return 1;

		if (ea == NULL || eb == NULL || ea->value != eb->value)
			return 0;

		ea = ea->next;
		eb = eb->next;
	}
}

void ls_clear(LinkedStack s)
{
	ls_Element e = s->top;

	while (e != NULL)
	{
		ls_Element next = e->next;
		free(e);
		e = next;
	}

	s->top = NULL;
	s->size = 0;
}

void ls_destroy(LinkedStack s)
{
	ls_clear(s);
	free(s);
}