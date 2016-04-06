#ifndef LISTASEQ_H_INCLUDED
#define LISTASEQ_H_INCLUDED

# define MAX 100  /* Tamanho M�ximo da Lista */

typedef struct {
     int dados[MAX]; /* Vetor que cont�m a Lista */
     int n;      /* Posi��o ap�s o �ltimo elemento*/
} tLista;

void cria (tLista *lista);
int vazia (tLista lista);
int cheia (tLista lista);
int tamanho (tLista lista);
int elemento (tLista lista, int pos, int *dado );
int posicao (tLista lista, int dado);
int insere (tLista *lista, int pos, int dado );
int remov (tLista *lista, int pos, int *dado );

#endif // LISTASEQ_H_INCLUDED
