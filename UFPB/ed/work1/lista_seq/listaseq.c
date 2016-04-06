#include <stdio.h>
#include <stdlib.h>
#include "listaseq.h"

/**Cria uma Lista vazia */
void cria (tLista *lista) {
    lista->n = 0;
}

/** Verifica se a Lista está vazia */
int vazia (tLista lista) {
    if (lista.n == 0)
        return 1;
    else
		return 0;
}

/**Verifica se a Lista está cheia */
int cheia (tLista lista) {
    if (lista.n == MAX)
        return 1;
    else
        return 0;
}

/**Obtém o tamanho da Lista*/
int tamanho (tLista lista) {
    return (lista.n);
}

/** Obtém o i-ésimo elemento de uma lista
    Retorna 0 se a posição passada for inválida,
    caso contrário 1. O parâmetro dado irá receber
    o elemento encontrado*/
int elemento (tLista lista, int pos, int *dado ) {
    /* Se posição estiver fora dos limites <= 0 ou > tamanho da lista */
    if ((pos > lista.n) || (pos <= 0))
        return 0;

   *dado = lista.dados[pos-1];
   return 1;
}

/**Retorna a posição de um elemento pesquisado.
    Retorna 0 caso não seja encontrado */
int posicao (tLista lista, int dado) {
    int  i;

    /* Procura elemento a elemento, se o dado está na
    lista. Se estiver, retorna a sua posição no array+1 */
    for (i = 0; i < lista.n; i++){
        if (lista.dados[i] == dado){
            return (i + 1);
        }
    }

    return 0;
}

/**Insere um elemento em uma determinada posição
    Retorna 0 se a lista estiver cheia ou
    a posição for inválida. Caso contrário retorna 1 */
int insere (tLista *lista, int pos, int dado ) {
    int  i;
    /* Verifica se a lista está cheia ou se a posicao a ser
    inserida eh invalida (i.e., > tamanho da lista+1*/
    if ((lista->n == MAX) || (pos > lista->n+1)){
        return 0;
    }

    /* Desloca os elementos após pos, uma posicao a
    direita. Isso serve para abrir espaço para insercao
    do novo elemento */
    for (i = lista->n ; i >= pos; i--){
 		 lista->dados[i] = lista->dados[i-1];
    }

    /* Insere o dado na posicao correta */
    lista->dados[pos - 1] = dado;

 	/* Incrementa o numero de elementos na lista */
    (lista->n)++;
    return 1;
}

/**Remove um elemento de uma determinada posição
    Retorna 0 se a posição for inválida ou a lista
    estiver vazia. Caso contrário retorna 1 */
int remov (tLista *lista, int pos, int *dado ) {
    int  i;

    /* Verifica se a posicao eh valida */
    if ((pos > lista->n ) || (pos <= 0 ))
		   return 0;

    /* Armazena o dado a ser removido na var "dado" */
    *dado = lista->dados[pos-1];

    /* Desloca todos os elementos após 'pos', uma
    posicao a esquerda */
    for (i = pos - 1; i < (lista->n) - 1; i++){
 		  lista->dados[i] = lista->dados[i+1];
	  }

   /* Decrementa o numero de elementos na lista */
    (lista->n)--;
    return 1;
}
