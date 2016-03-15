#include <alloca.h>
#include <stdio.h>

__attribute__((always_inline)) void f(void)
{
	char *cptr = alloca( 100 );
	printf( "%p - ", cptr );
}

int main()
{
	int i;
	
	for ( i = 0; i < 1000000; i++)
		f();
	
	return 0;
}