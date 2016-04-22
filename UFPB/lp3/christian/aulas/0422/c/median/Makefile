median.o: median.c
	gcc -Wall -Werror -pedantic -O2 -std=c99 -E median.c > median.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -S -fno-asynchronous-unwind-tables median.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -c median.s

inline4: median.o inline4.c
	gcc -Wall -Werror -pedantic -O2 -std=c99 -E inline4.c > inline4.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -S -fno-asynchronous-unwind-tables inline4.i
	gcc -Wall -Werror -pedantic -O2 -std=c99 -c inline4.s
	gcc -Wall -Werror -pedantic -O2 -std=c99 median.o inline4.o -o inline4

.PHONY: clean

clean:
	rm *.i *.s *.o inline3