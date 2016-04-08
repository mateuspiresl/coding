code: code.c
	gcc -Wall -Werror -E code.c > code.i
	gcc -Wall -Werror -S -fno-asynchronous-unwind-tables code.i
	gcc -Wall -Werror -c code.s
	gcc -Wall -Werror code.o -o code