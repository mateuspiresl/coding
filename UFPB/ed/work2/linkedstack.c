struct _Element {
	int value;
	struct _Element* next;
};
typedef struct _Element* Element;

struct _LinkedLinkedStack {
	Element top;
	int size;
};
typedef struct _LinkedLinkedStack* LinkedLinkedStack;

LinkedStack sl_createLinkedStack()
{
	LinkedStack s = malloc(sizeof(LinkedStack));
	s->top = NULL;
	s->size = 0;
	return s;
}

Element sl_createElement(int value, Element next)
{
	Element e = malloc(sizeof(Element));
	e->value = value;
	e->next = next;
	return e;
}

int sl_isEmpty(LinkedStack s) {
	return s->size == 0;
}

int sl_size(LinkedStack s) {
	return s->size;
}

int sl_top(LinkedStack s) {
	return s->top->value;
}

void sl_push(LinkedStack s, int value)
{
	Element e = sl_createElement(value, s->top);
	s->top = e;
}

void sl_pop(LinkedStack s)
{
	Element e = s->top;
	s->top = e->next;
	free(e);
}

// New methods

void sl_printElements(Element e, int index)
{
	if (e->next != NULL)
		sl_printElements(e, index + 1);

	printf("\t\t%d. %d\n", index, e->value);
}

void sl_details(LinkedStack s)
{
	printf("LinkedStack:\n\tSize: %d\nElements:\n", s->size);
	sl_printElements(e->top, 0);
}

void sl_invertNext(LinkedStack s, Element e, Element update)
{
	if (e != NULL)
	{
		sl_invertNext(s, e->next, e);
		e->next = update;
	}
	else s->top = update;
}

void sl_invert(LinkedStack s) {
	sl_invertNext(s, s->top, NULL);
}

int sl_removeNextValue(LinkedStack s, Element e, Element* previousNext, int value)
{
	if (e->value == value)
	{
		Element next = e->next;
		*previousNext = next;

		free(e);
		return 1 + sl_removeNextValue(s, next, previousNext, value);
	}

	return sl_removeNextValue(s, e->next, &(e->next), value);
}

int sl_removeValue(LinkedStack s, int value) {
	return sl_checkNext(s, s->top, &(s->top), value);
}

int sl_checkNext(Element a, Element b)
{
	if (a == NULL && b == NULL)
		return 1;

	if (a != NULL && b != NULL && a->value == b->value)
		return sl_checkNext(a->next, b->next)

	return 0;
}

int sl_equals(LinkedStack a, LinkedStack b) {
	return sl_checkNextElements(a->top, b->top);
}

void sl_clear(LinkedStack s)
{
	Element e = s->top;

	while (e != NULL)
	{
		Element* next = e->next;
		free(e);
		e = next;
	}

	free(s);
}