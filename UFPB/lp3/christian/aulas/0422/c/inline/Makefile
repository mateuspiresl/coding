inline1: inline1.c
	gcc -Wall -Werror -pedantic -O2 -std=c99 -E inline1.c > inline1.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -S -fno-asynchronous-unwind-tables inline1.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -c inline1.s
	gcc -Wall -Werror -pedantic -O2 -std=c99 inline1.o -o inline1

.PHONY: clean

clean:
	rm *.i *.s *.o inline1