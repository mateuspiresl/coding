#ifndef SEQ_LIST_H
#define SEQ_LIST_H

#define MAX_SIZE 100

struct __SeqList {
	int data[MAX_SIZE];
	int size;
};
typedef struct __SeqList* SeqList;

/*	Cria uma lista vazia. */
SeqList sl_newSeqList();

/* Adiciona um nó ao final da lista. */
int sl_empty(SeqList list);

/* Adiciona um nó ao final da lista. */
int sl_size(SeqList list);

/* Cria um nó e adiciona ao final da lista. */
void sl_add(SeqList list, int value);

/* Adiciona um valor em determinado índice. */
int sl_insert(SeqList list, unsigned int index, int value);

/* Retorna o valor por índice do nó. */
int sl_get(SeqList list, unsigned int index);

/* Altera o valor de um nó pelo índice. */
int sl_set(SeqList list, unsigned int index, int value);

/* Remove o nó pelo índice. */
int sl_removeByIndex(SeqList list, unsigned int index);

/* Remove um nó pelo valor. */
int sl_removeByValue(SeqList list, int value);

/* Imprime as informações da lista na saída padrão. */
void sl_about(SeqList list);

/* Retorna duas listas, uma com os elementos de índice par e a outra
 *		com os elementos de índice ímpar. */
SeqList* sl_split(SeqList list);

/* Retorna a junção de duas listas. */
SeqList sl_join(SeqList la, SeqList lb);

#endif