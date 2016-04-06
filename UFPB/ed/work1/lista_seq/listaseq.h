#ifndef LISTASEQ_H_INCLUDED
#define LISTASEQ_H_INCLUDED

# define MAX 100  /* Tamanho Máximo da Lista */

typedef struct {
     int dados[MAX]; /* Vetor que contém a Lista */
     int n;      /* Posição após o último elemento*/
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
