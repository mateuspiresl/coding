#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "list_int.h"

int comparator(void* a, void* b)
{
	int av = *((int*) a);
	int bv = *((int*) b);

	return av - bv;
}

int main()
{
	/*List* list = li_createList();

	li_add(list, 10);
	printf("%d\n", li_get(list, 0));

	li_removeValue(list, 10);
	printf("%d\n", list->size);*/

	List* list = l_createList();
	l_setComparator(list, &comparator);

	int* value = malloc(sizeof(int));
	*value = 11;
	l_add(list, value);

	value = l_get(list, 0);
	int v = *((int*) value);
	printf("%d\n", v);

	l_removeIndex(list, 1);
	printf("%d\n", list->size);

	return 0;
}