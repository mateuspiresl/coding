#ifndef SEQ_STACK_H_
#define SEQ_STACK_H_

struct _SeqStack {
	int* data;
	int maxSize;
	int top;
};
typedef struct _SeqStack* SeqStack;

/* Cria uma pilha e define. */
SeqStack ss_create(int maxSize);

/* Verifica se a pilha está vazia. */
int ss_isEmpty(SeqStack s);

/* Retorna o tamanho da pilha. */
int ss_size(SeqStack s);

/* Verifica se a pilha está cheia. */
int ss_isFull(SeqStack s);

/* Atribui para mem o valor do topo da pilha. */
int ss_top(SeqStack s, int* mem);

/* Empilha o valor. */
int ss_push(SeqStack s, int value);

/* Desempilha o topo. */
int ss_pop(SeqStack s);

// New methods

/* Escreve os detalhes da pilha. */
void ss_details(SeqStack s);

/* Inverte a pilha. */
void ss_invert(SeqStack s);

/* Remove todos os elementos de valor igual ao especificado. */
int ss_removeValue(SeqStack s, int value);

/* Verifica se duas pilhas são iguais. */
int ss_equals(SeqStack a, SeqStack b);

/* Remove todos os elementos da pilha. */
void ss_clear(SeqStack s);

#endif