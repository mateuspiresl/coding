disjointsets: DisjointSets.cpp
	g++ DisjointSets.cpp -c

test: disjointsets test.cpp
	g++ test.cpp -c
	g++ disjointsets.o test.o -o test

uf: unionfind.cpp
	g++ unionfind.cpp -c
	g++ unionfind.o -o uf

.PHONY: clear

clear:
	rm *.o