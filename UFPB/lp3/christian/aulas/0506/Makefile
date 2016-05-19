mainref: mainref.cpp
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -E mainref.cpp > mainref.i
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -S -fno-asynchronous-unwind-tables mainref.i
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -c mainref.s
	g++ -Wall -Werror -pedantic -O0 -std=c++11 mainref.o -o mainref

mainptr: mainptr.cpp
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -E mainptr.cpp > mainptr.i
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -S -fno-asynchronous-unwind-tables -fno-dwarf2-cfi-asm mainptr.i
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -c mainptr.s
	g++ -Wall -Werror -pedantic -O0 -std=c++11 mainptr.o -o mainptr

dummy: dummy.cpp
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -E dummy.cpp > dummy.i
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -S -fno-asynchronous-unwind-tables -fno-dwarf2-cfi-asm dummy.i
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -c dummy.s
	g++ -Wall -Werror -pedantic -O0 -std=c++11 dummy.o -o dummy

.PHONY: clean clean2

clean:
	rm *.i *.s *.o 

clean2:
	rm mainref mainptr