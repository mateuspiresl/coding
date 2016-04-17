seqstack.o: seqstack.c
	gcc -Wall -Werror -pedantic -std=c99 -c seqstack.c

seqtest: seqtest.c seqstack.o
	gcc -Wall -Werror -pedantic -std=c99 -c seqtest.c
	gcc -Wall -Werror -pedantic -std=c99 seqstack.o seqtest.o -o seqtest

linkedstack.o: linkedstack.c
	gcc -Wall -Werror -pedantic -std=c99 -c linkedstack.c

linkedtest: linkedtest.c linkedstack.o
	gcc -Wall -Werror -pedantic -std=c99 -c linkedtest.c
	gcc -Wall -Werror -pedantic -std=c99 linkedstack.o linkedtest.o -o linkedtest

qt3: qt3.c linkedstack.o
	gcc -Wall -Werror -pedantic -std=c99 -c qt3.c
	gcc -Wall -Werror -pedantic -std=c99 linkedstack.o qt3.o -o qt3

.PHONY: clean

clean:
	rm *.o