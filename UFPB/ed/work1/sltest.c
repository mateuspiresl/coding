#include <stdio.h>
#include "seqlist.h"

int main()
{
	SeqList list = sl_newSeqList();

	printf("Adicionando 10, 100, 21 e 76:\n");
	sl_add(list, 10);
	sl_add(list, 100);
	sl_add(list, 21);
	sl_add(list, 76);
	sl_about(list);

	printf("Consultando valor na posição 2: %d\n", sl_get(list, 2));

	printf("Removendo elemento na posição 1: %d\n", sl_removeByIndex(list, 1));
	sl_about(list);

	printf("Removendo elemento com valor 76: %d\n", sl_removeByValue(list, 76));
	sl_about(list);

	printf("Adicionando 100:\n");
	sl_add(list, 100);
	sl_about(list);

	printf("Removendo elemento na posição 0: %d\n", sl_removeByIndex(list, 0));
	sl_about(list);

	printf("Alterando valor para 430 na posição 1: %d\n", sl_set(list, 1, 430));
	sl_about(list);

	printf("Adicionando 10, 100, 21 e 76:\n");
	sl_add(list, 10);
	sl_add(list, 100);
	sl_add(list, 21);
	sl_add(list, 76);
	sl_about(list);

	printf("Partindo a lista em duas:\n");
	SeqList* lists = sl_split(list);
	sl_about(lists[0]);
	sl_about(lists[1]);

	printf("Juntando as duas listas:\n");
	SeqList joined = sl_join(lists[0], lists[1]);
	sl_about(joined);

	printf("Inserindo 444 na posição 0 e 555 na posição 5:\n");
	sl_insert(joined, 0, 444);
	sl_insert(joined, 5, 555);
	sl_about(joined);

	return 0;
}