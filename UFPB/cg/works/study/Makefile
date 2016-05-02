prog: prog.c
	gcc -Werror -Wall -pedantic -std=c99 -O0 prog.c -o prog -lglut -lGL -lGLU

ex1: ex1_lit-sphere.c
	gcc -Wall -Werror -pedantic -std=c99 -O0 ex1_lit-sphere.c -o ex1 -lglut -lGL -lGLU

ex2: ex2_teapot.c
	gcc -Wall -Werror -pedantic -std=c99 -O0 ex2_teapot.c -o ex2 -lglut -lGL -lGLU

.PHONY: clear clearbin

clear:
	rm *.o

clearbin:
	rm prog ex1