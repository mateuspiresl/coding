list.o: list.c
	gcc -c list.c -Wall -Werror -std=c99 -pedantic

list_int.o: list_int.c
	gcc -c list_int.c -Wall -Werror -std=c99 -pedantic

program: program.c list.o list_int.o
	gcc -c program.c -Wall -Werror -std=c99 -pedantic
	gcc list.o list_int.o program.o -o program

pgdb: program.c list.c
	gcc -c list.c -Wall -Werror -std=c99 -pedantic -g3
	gcc -c program.c -Wall -Werror -std=c99 -pedantic -g3
	gcc list.o list_int.o program.o -o pgdb


.PHONY: clean

clean:
	rm *.o