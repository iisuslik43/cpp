all: lab4

lab4: bin/ms_cli.o bin/mergesort.o
	gcc -g bin/ms_cli.o bin/mergesort.o -o lab4

bin/ms_cli.o: ms_cli.c mergesort.h
	gcc -g -c ms_cli.c -o bin/ms_cli.o

bin/mergesort.o: mergesort.c mergesort.h
	gcc -g -c mergesort.c -o bin/mergesort.o

clean:
	rm -rf bin/*.o lab4
