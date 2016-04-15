#ifndef LIST_H_
#define LIST_H_

struct _Element {
	void* value;
	struct _Element* next;
};
typedef struct _Element Element;

typedef struct {
	Element* head;
	Element* tail;
	int size;
	int (*comparator)(void*, void*);
} List;

List* l_createList();
void l_setComparator(List* list, int (*comparatorFunc)(void*, void*));
Element* l_createElement(void* value, Element* next);
void l_add(List* list, void* value);
void l_removeValue(List* list, void* value);
void l_removeIndex(List* list, int index);
void* l_get(List* list, int index);

#endif