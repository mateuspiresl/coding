cvector: vector.c
	gcc -Wall -Werror -pedantic -O0 -std=c99 -E vector.c > vectorc.i
	gcc -Wall -Werror -pedantic -O0 -std=c99 -S -fno-asynchronous-unwind-tables vectorc.i
	gcc -Wall -Werror -pedantic -O0 -std=c99 -c vectorc.s
	gcc -Wall -Werror -pedantic -O0 -std=c99 vectorc.o -o cvector

cppvector: vector.cpp
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -E vector.cpp > vectorcpp.i
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -S -fno-asynchronous-unwind-tables vectorcpp.i
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -c vectorcpp.s
	g++ -Wall -Werror -pedantic -O0 -std=c++11 vectorcpp.o -o cppvector

cppclass: class_cpp.cpp
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -E class_cpp.cpp > class_cpp.i
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -S -fno-asynchronous-unwind-tables -fno-dwarf2-cfi-asm class_cpp.i
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -c class_cpp.s
	g++ -Wall -Werror -pedantic -O0 -std=c++11 class_cpp.o -o cppclass

cclass: class_c.c
	gcc -Wall -Werror -pedantic -O0 -std=c99 -E class_c.c > class_c.i
	gcc -Wall -Werror -pedantic -O0 -std=c99 -S -fno-asynchronous-unwind-tables class_c.i
	gcc -Wall -Werror -pedantic -O0 -std=c99 -c class_c.s
	gcc -Wall -Werror -pedantic -O0 -std=c99 class_c.o -o cclass

.PHONY: clean clean2

clean:
	rm *.i *.s *.o 

clean2:
	rm cvector cppvector cppclass cclass