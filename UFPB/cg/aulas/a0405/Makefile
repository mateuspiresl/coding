reader: reader.c
	gcc -c reader.c

readraw: reader readraw.c
	gcc -c readraw.c
	gcc reader.o readraw.o -o readraw -lopengl32 -lglu32 -lfreeglut