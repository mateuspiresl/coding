struct _lq_Element {
	int value;
	struct _lq_Element* next;
};
typedef struct _lq_Element* lq_Element;

struct _LinkedQueue {
	lq_Element first;
	lq_Element last;
	int size;
};
typedef struct _LinkedQueue* LinkedQueue;

/* Cria uma fila de tamanho $maxSize. */
LinkedQueue lq_create(int maxSize);

/* Verifica se a fila está vazia. */
int lq_isEmpty(const LinkedQueue q);

/* Retorna o tamanho da fila. */
int lq_size(const LinkedQueue q);

/* Retorna o primeiro elemento da fila. */
int lq_front(const LinkedQueue q, int* mem);

/* Insere um elemento no final da fila. */
void lq_enqueue(LinkedQueue q, int value);

/* Remove o primeiro elemento da fila. */
int lq_dequeue(LinkedQueue q);


// Novas funcionalidades

/* Escreve os detalhes da fila. */
void lq_details(const LinkedQueue q);

/* Retorna o índice do primeiro elemento que tem valor igual a $value. */
int lq_find(const LinkedQueue q, int value);

/* Insere na fila $to todos os elementos de $fromA e $fromB de forma intercalada. */
int lq_interc(const LinkedQueue fromA, const LinkedQueue fromB, LinkedQueue to);

/* Inverte a fila $q armazenando na fila $inverted. */
void lq_reverse(const LinkedQueue q, LinkedQueue reversed);