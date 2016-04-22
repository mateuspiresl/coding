seqstack.o: seqstack.c
	gcc -Wall -Werror -pedantic -std=c99 -c seqstack.c

test_ss: test_ss.c seqstack.o
	gcc -Wall -Werror -pedantic -std=c99 -c test_ss.c
	gcc -Wall -Werror -pedantic -std=c99 seqstack.o test_ss.o -o test_ss

linkedstack.o: linkedstack.c
	gcc -Wall -Werror -pedantic -std=c99 -c linkedstack.c

test_ls: test_ls.c linkedstack.o
	gcc -Wall -Werror -pedantic -std=c99 -c test_ls.c
	gcc -Wall -Werror -pedantic -std=c99 linkedstack.o test_ls.o -o test_ls

qt3: qt3.c linkedstack.o
	gcc -Wall -Werror -pedantic -std=c99 -c qt3.c
	gcc -Wall -Werror -pedantic -std=c99 linkedstack.o qt3.o -o qt3

qt4: qt4.c linkedstack.o
	gcc -Wall -Werror -pedantic -std=c99 -c qt4.c
	gcc -Wall -Werror -pedantic -std=c99 linkedstack.o qt4.o -o qt4

seqqueue.o: seqqueue.c
	gcc -Wall -Werror -pedantic -std=c99 -c seqqueue.c

test_sq: test_sq.c seqqueue.o
	gcc -Wall -Werror -pedantic -std=c99 -c test_sq.c
	gcc -Wall -Werror -pedantic -std=c99 seqqueue.o test_sq.o -o test_sq

linkedqueue.o: linkedqueue.c
	gcc -Wall -Werror -pedantic -std=c99 -c linkedqueue.c

test_lq: test_lq.c linkedqueue.o
	gcc -Wall -Werror -pedantic -std=c99 -c test_lq.c
	gcc -Wall -Werror -pedantic -std=c99 linkedqueue.o test_lq.o -o test_lq


.PHONY: clean comp_exe

comp_exe_out:
	make test_ss
	make test_ls
	make test_sq
	make test_lq
	./test_ss > test_ss.out
	./test_ls > test_ls.out
	./test_sq > test_sq.out
	./test_lq > test_lq.out

clean:
	rm *.o *.exe