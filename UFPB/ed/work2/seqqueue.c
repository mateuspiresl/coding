#include <stdlib.h>
#include <stdio.h>
#include "seqqueue.h"

/* Retorna o índice na array data de $q do elemento de índice $i [de 0 a (size - 1)]. */
#define sq_at(q, i) (q->first + i) % q->maxSize

SeqQueue sq_create(int maxSize)
{
	SeqQueue q = malloc(sizeof(struct _SeqQueue));
	q->data = malloc(sizeof(int) * maxSize);
	q->maxSize = maxSize;
	q->size = 0;
	q->first = 0;
	return q;
}

SeqQueue sq_createDefault() {
	return sq_create(100);
}

int sq_isEmpty(const SeqQueue q) {
	return q->size == 0;
}

int sq_isFull(const SeqQueue q) {
	return q->size == q->maxSize;
}

int sq_size(const SeqQueue q) {
	return q->size;
}

int sq_front(const SeqQueue q, int* mem)
{
	if (q->size == 0) return 0;

	*mem = q->data[q->first];
	return 1;
}

int sq_enqueue(SeqQueue q, int value)
{
	if (q->size == q->maxSize) return 0;

	q->data[sq_at(q, q->size)] = value;
	q->size++;
	return 1;
}

int sq_dequeue(SeqQueue q)
{
	if (q->size == 0) return 0;

	q->first = sq_at(q, 1);
	q->size--;
	return 1;
}


// Novas funcionalidades

void sq_details(const SeqQueue q)
{
	printf("SeqQueue:\n\tSize: %d\n", q->size);

	if ( ! sq_isEmpty(q))
	{
		printf("\tElements:");

		int i;
		for (i = 0; i < q->size; i++)
			printf(" %d", q->data[sq_at(q, i)]);
		printf("\n");
	}
}

int sq_find(const SeqQueue q, int value)
{
	int i;
	for (i = 0; i < q->size; i++)
		if (q->data[sq_at(q, i)] == value)
			return i + 1;

	return 0;
}

int sq_interc(const SeqQueue fromA, const SeqQueue fromB, SeqQueue to)
{
	// Erro nos casos:
	//		O tamanho de $fromA e $fromB são diferentes
	//		$to não é uma lista vazia
	//		O tamanho máximo de $to é menor que o tamanho de $fromA com $fromB
	//			Que significa que $fromA e $fromB não cabem em $to
	if (fromA->size != fromB->size || ! sq_isEmpty(to) || to->maxSize < fromA->size + fromB->size)
		return 0;

	// Se $fromA estiver vazia, o preenchimento não modifica nada
	if (sq_isEmpty(fromA))
		return 1;

	int i;
	for (i = 0; i < fromA->size; i++)
	{
		sq_enqueue(to, fromA->data[sq_at(fromA, i)]);
		sq_enqueue(to, fromB->data[sq_at(fromB, i)]);
	}

	return 1;
}

void sq_reverse(const SeqQueue q, SeqQueue reversed)
{
	int i;
	for (i = sq_size(q) - 1; i >= 0; i--)
		sq_enqueue(reversed, q->data[sq_at(q, i)]);
}