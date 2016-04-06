#ifndef LISTAENC_H_INCLUDED
#define LISTAENC_H_INCLUDED

typedef struct no{
    int dado;    /* informa��o */
    struct no *prox; /* ponteiro para pr�ximo n� */
}tNo;  /* tipo do n� */

typedef struct lista{
   struct no *cabeca;
   int tamanho;
}tLista;

void cria (tLista *lista);
int vazia (tLista lista);
int tamanho (tLista lista);
int elemento (tLista lista, int pos, int *dado );
int posicao (tLista lista, int dado);
int insere (tLista *lista, int pos, int dado );
int remov (tLista *lista, int pos, int *dado );

/*int insereInicioLista(tLista *lista, int valor);
int insereMeioLista(tLista *lista, int pos, int dado);
int inserirFimLista(tLista *lista, int dado);*/

#endif // LISTAENC_H_INCLUDED
