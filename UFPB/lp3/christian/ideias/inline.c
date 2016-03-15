#include <stdio.h>

inline int call(int x) {
	return 1 + call(x - 1);
}

int main()
{
	printf("%d\n", call(10));
	return 0;
}