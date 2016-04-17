#include <stdio.h>
#include "linkedstack.h"

const int MAX = 300;

int main()
{
	char str[MAX];
	fgets(str, MAX, stdin);

	LinkedStack left = ls_createLinkedStack();

	int i;
	for (i = 0; i < MAX - 1 && str[i] != '\0'; i++)
		if (isalpha(str[i]) || isdigit(str[i]))
			ls_push(s, str[í]);

	LinkedStack right = ls_createLinkedStack();

	while (ls_size(left) > ls_size(right))
	{
		int value;
		ls_top(left, &value); ls_pop(left);
		ls_push(right, value);
	}

	if (ls_size(right) > ls_size(left))
		ls_pop(right);

	while ( ! ls_isEmpty(left))
	{
		int vl, vr;
		ls_top(left, &vl);
		ls_top(right, &vr);

		if (left != right)
		{
			printf("Não são palindromes.\n");
			break;
		}

		ls_pop(left);
		ls_pop(right);
	}

	if (ls_isEmpty(left))
		printf("São palindromes.\n");

	ls_clear(s);
	free(s);
	return 0;
}