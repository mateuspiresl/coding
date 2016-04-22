inline2: inline2.c
	gcc -Wall -Werror -pedantic -O2 -std=c99 -E inline2.c > inline2.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -S -fno-asynchronous-unwind-tables inline2.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -c inline2.s
	gcc -Wall -Werror -pedantic -O2 -std=c99 inline2.o -o inline2

.PHONY: clean

clean:
	rm *.i *.s *.o inline2