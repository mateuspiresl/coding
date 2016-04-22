inline3: inline3.c
	gcc -Wall -Werror -pedantic -O2 -std=c99 -E inline3.c > inline3.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -S -fno-asynchronous-unwind-tables inline3.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -c inline3.s
	gcc -Wall -Werror -pedantic -O2 -std=c99 inline3.o -o inline3

.PHONY: clean

clean:
	rm *.i *.s *.o inline3