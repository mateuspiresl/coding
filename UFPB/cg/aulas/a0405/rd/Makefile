point3d: point3d.c
	gcc -c point3d.c

quadface: point3d quadface.c
	gcc -c quadface.c

reader: quadface reader.c
	gcc -c reader.c

readraw: reader readraw.c
	gcc -c readraw.c
	gcc point3d.o quadface.o reader.o readraw.o -o readraw -lopengl32 -lglu32 -lfreeglut


gdbreader: reader.c
	gcc -c reader.c -g3
	mv reader.o gdbreader.o

gdbreadraw: gdbreader readraw.c
	gcc -c readraw.c -g3
	mv readraw.o gdbreadraw.o
	gcc gdbreader.o gdbreadraw.o -o gdbreadraw -lopengl32 -lglu32 -lfreeglut

.PHONY: clear

clear:
	rm *.o