stdio: stdio.c
	gcc -Wall -Werror -E stdio.c > stdio.i
	gcc -Wall -Werror -S -fno-asynchronous-unwind-tables stdio.i
	gcc -Wall -Werror -c stdio.s
	gcc -Wall -Werror stdio.o -o stdio

maintriangle: maintriangle.c
	gcc -Wall -Werror -E maintriangle.c > maintriangle.i
	gcc -Wall -Werror -S -fno-asynchronous-unwind-tables maintriangle.i
	gcc -Wall -Werror -c maintriangle.s
	gcc -Wall -Werror maintriangle.o -o maintriangle

macro: macro.c
	gcc -Wall -Werror -E macro.c > macro.i
	gcc -Wall -Werror -S -fno-asynchronous-unwind-tables macro.i
	gcc -Wall -Werror -c macro.s
	gcc -Wall -Werror macro.o -o macro

.PHONY: clean

clean:
	rm *.i *.s *.o stdio maintriangle macro