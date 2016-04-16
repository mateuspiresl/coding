#ifndef LIST_INT_H_
#define LIST_INT_H_

#include "list.h"

List* li_createList();
void li_add(List* list, int value);
void li_removeValue(List* list, int value);
void li_removeIndex(List* list, int index)
int li_get(List* list, int index);

#endif