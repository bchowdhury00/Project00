all: main.o myTunes.o songLib.o
	gcc -o test main.o

myTunes.o: myTunes.c myTunes.h
	gcc -c myTunes.c

songLib.o: songLib.c songLib.h
	gcc -c songLib.c

main.o: main.c
	gcc -c main.c

run:
	./test

clean:
	rm *.o
	rm *~
