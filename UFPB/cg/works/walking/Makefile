drawing.o: drawing.c
	gcc -Wall -Werror -pedantic -std=c99 -c drawing.c

map.o: map.c
	gcc -Wall -Werror -pedantic -std=c99 -c map.c

player.o: player.c
	gcc -Wall -Werror -pedantic -std=c99 -c player.c

#program: program.c player.o map.o drawing.o
program: program.c map.o player.o drawing.o
	gcc -Wall -Werror -pedantic -std=c99 -c program.c
	#gcc drawing.o map.o player.o program.o -o program -lglut -lGL -lGLU
	gcc map.o player.o drawing.o program.o -o program -lglut -lGL -lGLU

.PHONY: clear

clear:
	rm *.o