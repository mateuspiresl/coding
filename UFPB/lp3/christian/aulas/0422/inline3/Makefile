insertion.o: insertion.c
	gcc -Wall -Werror -pedantic -O2 -std=c99 -E insertion.c > insertion.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -S -fno-asynchronous-unwind-tables insertion.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -c insertion.s

inline3: insertion.o inline3.c
	gcc -Wall -Werror -pedantic -O2 -std=c99 -E inline3.c > inline3.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -S -fno-asynchronous-unwind-tables inline3.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -c inline3.s
	gcc -Wall -Werror -pedantic -O2 -std=c99 insertion.o inline3.o -o inline3

.PHONY: clean

clean:
	rm *.i *.s *.o inline3