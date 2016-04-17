#include <stdlib.h>
#include <stdio.h>
#include "linkedstack.h"

LinkedStack ls_createLinkedStack()
{
	LinkedStack s = malloc(sizeof(LinkedStack));
	s->top = NULL;
	s->size = 0;
	return s;
}

Element ls_createElement(int value, Element next)
{
	Element e = malloc(sizeof(Element));
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
	Element e = ls_createElement(value, s->top);
	s->top = e;
	s->size++;
}

int ls_pop(LinkedStack s)
{
	if (s->top == NULL) return 0;

	Element e = s->top;
	s->top = e->next;
	s->size--;

	free(e);
	return 1;
}

// New methods

/* Escreve todos os elementos do primeiro até $e.
 * Recursividade necessária para armazenar todos os elementos até chegar no primeiro.
 * Em backtrack, escreve os valores na ordem. */
void ls_printElements(Element e)
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
void ls_invertNext(LinkedStack s, Element e, Element update)
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

/* Remove $e de $s se o valor de $e for igual a $value e recursivamente verifica
 * 		o próximo elemento.
 * @param previousNext - ponteiro para o ponteiro next do elemento anterior. Se
 *		o elemento $e for removido, o ponteiro next do elemento anterior de $e deve
 *		ser atualizado para apontar para o elemento após $e. */
int ls_removeNextValue(Element e, Element* previousNext, int value)
{
	if (e == NULL) return 0;

	if (e->value == value)
	{
		Element next = e->next;
		*previousNext = next;
		free(e);

		return 1 + ls_removeNextValue(next, previousNext, value);
	}

	return ls_removeNextValue(e->next, &(e->next), value);
}

int ls_removeValue(LinkedStack s, int value)
{
	if (ls_isEmpty(s)) return 0;
	return ls_removeNextValue(s->top, &(s->top), value);
}

/* Verifica se $a é igual a $b e, se for, verifica recursivamente
 * 		se o próximo elemento de $a é igual ao próximo de $b. */
int ls_checkNext(Element a, Element b)
{
	// Se os dois forem NULL, chegou ao final das duas pilhas.
	if (a == NULL && b == NULL)
		return 1;

	if (a != NULL && b != NULL && a->value == b->value)
		return ls_checkNext(a->next, b->next);

	return 0;
}

int ls_equals(LinkedStack a, LinkedStack b) {
	return ls_checkNext(a->top, b->top);
}

void ls_clear(LinkedStack s)
{
	Element e = s->top;

	while (e != NULL)
	{
		Element next = e->next;
		free(e);
		e = next;
	}

	s->top = NULL;
	s->size = 0;
}