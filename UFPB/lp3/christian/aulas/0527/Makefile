vector.o: vector.cpp
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -c vector.cpp

program: usage.cpp vector.o
	g++ -Wall -Werror -pedantic -O0 -std=c++11 -c usage.cpp
	g++ -Wall -Werror -pedantic -O0 -std=c++11 vector.o usage.o -o program

sptr:
	g++ -Wall -Werror -pedantic -O0 -std=c++11 smart_ptr.cpp -o sptr

.PHONY: clean

clean:
	rm *.i *.s *.o 