struct _SeqQueue {
	int* data;
	int maxSize;
	int size;
	int first;
};

typedef struct _SeqQueue* SeqQueue;

/* Cria uma fila de tamanho máximo 100. */
SeqQueue sq_createDefault();

/* Cria uma fila de tamanho $maxSize. */
SeqQueue sq_create(int maxSize);

/* Verifica se a fila está vazia. */
int sq_isEmpty(const SeqQueue q);

/* Verifica se a fila está cheia. */
int sq_isFull(const SeqQueue q);

/* Retorna o tamanho da fila. */
int sq_size(const SeqQueue q);

/* Retorna o primeiro elemento da fila. */
int sq_front(const SeqQueue q, int* mem);

/* Insere um elemento no final da fila. */
int sq_enqueue(SeqQueue q, int value);

/* Remove o primeiro elemento da fila. */
int sq_dequeue(SeqQueue q);


// Novas funcionalidades

/* Escreve os detalhes da fila. */
void sq_details(const SeqQueue q);

/* Retorna a posição do primeiro elemento que tem valor igual a $value. */
int sq_find(const SeqQueue q, int value);

/* Insere na fila $to todos os elementos de $fromA e $fromB de forma intercalada. */
int sq_interc(const SeqQueue fromA, const SeqQueue fromB, SeqQueue to);

/* Inverte a fila $q armazenando na fila $inverted. */
void sq_reverse(const SeqQueue q, SeqQueue reversed);