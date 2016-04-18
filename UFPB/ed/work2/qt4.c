#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "linkedstack.h"

const int MAX = 300;

int main()
{
	char str[MAX];
	fgets(str, MAX, stdin);
	str[MAX - 1] = '\0';

	LinkedStack left = ls_create();

	int i;
	for (i = 0; str[i] != '\0'; i++)
		if (isalpha(str[i]) || isdigit(str[i]))
			ls_push(left, str[i]);

	LinkedStack right = ls_create();

	while (ls_size(left) > ls_size(right))
	{
		int value;
		ls_top(left, &value); ls_pop(left);
		ls_push(right, value);
	}

	if (ls_size(right) > ls_size(left))
		ls_pop(right);

	if (ls_equals(left, right))
		printf("É palindrome.\n");
	else
		printf("Não é palindrome.\n");
	
	ls_destroy(left);
	ls_destroy(right);
	return 0;
}