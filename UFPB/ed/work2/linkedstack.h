#ifndef LINKED_STACK_H_
#define LINKED_STACK_H_

struct _Element {
	int value;
	struct _Element* next;
};
typedef struct _Element* Element;

struct _LinkedStack {
	Element top;
	int size;
};
typedef struct _LinkedStack* LinkedStack;

/* Cria uma pilha e define. */
LinkedStack ls_createLinkedStack();

/* Verifica se a pilha está vazia. */
int ls_isEmpty(LinkedStack s);

/* Retorna o tamanho da pilha. */
int ls_size(LinkedStack s);

/* Atribui para mem o valor do topo da pilha. */
int ls_top(LinkedStack s, int* mem);

/* Empilha o valor. */
void ls_push(LinkedStack s, int value);

/* Desempilha o topo. */
int ls_pop(LinkedStack s);

// New methods

/* Escreve os detalhes da pilha no stdio. */
void ls_details(LinkedStack s);

/* Inverte a pilha. */
void ls_invert(LinkedStack s);

/* Remove todos os elementos de valor igual ao especificado. */
int ls_removeValue(LinkedStack s, int value);

/* Verifica se duas pilhas são iguais. */
int ls_equals(LinkedStack a, LinkedStack b);

/* Remove todos os elementos da pilha. */
void ls_clear(LinkedStack s);

#endif