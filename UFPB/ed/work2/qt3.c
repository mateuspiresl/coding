#include <stdio.h>
#include "linkedstack.h"

int main()
{
	LinkedStack s = ls_create();

	int invalid = 0;

	char c = 0;
	while ( ! invalid && (c = fgetc(stdin)) != EOF)
	{
		if (c == '(' || c == '[' || c == '{')
			ls_push(s, c);
		else
		{
			int top;
			ls_top(s, &top);

			switch (c)
			{
				case ')':	if (top != '(') invalid = 1;
							else ls_pop(s);
							break;
				case ']':	if (top != '[') invalid = 1;
							else ls_pop(s);
							break;
				case '}':	if (top != '{') invalid = 1;
							else ls_pop(s);
			}
		}
	}

	if (invalid)
		printf("Expressão inválida.\n");
	else
		printf("Expressão válida.\n");

	ls_clear(s);
	free(s);
	return 0;
}