#include <stdlib.h>
#include "list.h"
#include "list_int.h"

int li_comparator(void* a, void* b)
{
	int av = *((int*) a);
	int bv = *((int*) b);

	return av - bv;
}

List* li_createList()
{
	List* list = l_createList();
	l_setComparator(list, &li_comparator);
	return list;
}

void* li_generic(int value)
{
	int* v = malloc(sizeof(int));
	*v = value;
	return v;
}

void li_add(List* list, int value) {
	l_add(list, li_generic(value));
}

void li_removeValue(List* list, int value)
{
	void* v = li_generic(value);
	l_removeValue(list, li_generic(value));
	free(v);
}

int li_get(List* list, int index)
{
	void* value = l_get(list, index);
	return *((int*) value);
}