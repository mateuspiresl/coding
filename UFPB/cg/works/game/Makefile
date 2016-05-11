drawing.o: drawing.c
	gcc -Wall -Werror -pedantic -std=c99 -c drawing.c

player.o: player.c
	gcc -Wall -Werror -pedantic -std=c99 -c player.c

program: program.c player.o drawing.o
	gcc -Wall -Werror -pedantic -std=c99 -c program.c
	gcc player.o drawing.o program.o -o program -lglut -lGL -lGLU

.PHONY: clear

clear:
	rm *.o