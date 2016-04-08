sumdata.o: sumdata.c
	gcc -Wall -Werror -E sumdata.c > sumdata.i
	gcc -Wall -Werror -S -fno-asynchronous-unwind-tables sumdata.i
	gcc -Wall -Werror -c sumdata.s

summain.o: summain.c
	gcc -Wall -Werror -E summain.c > summain.i
	gcc -Wall -Werror -S -fno-asynchronous-unwind-tables summain.i
	gcc -Wall -Werror -c summain.s

sqrmain.o: sqrmain.c
	gcc -Wall -Werror -E sqrmain.c > sqrmain.i
	gcc -Wall -Werror -S -fno-asynchronous-unwind-tables sqrmain.i
	gcc -Wall -Werror -c sqrmain.s

sum: sumdata.o summain.o
	gcc -Wall -Werror sumdata.o summain.o -o sum

sqr: sumdata.o sqrmain.o
	gcc -Wall -Werror sumdata.o sqrmain.o -o sqr

# Diz que os targets seguindes devem executar sempre
.PHONY: clean cleani

cleani:
	rm *.i *.s *.o

clean:
	rm *.i *.s *.o sum sqr