all: lab2

lab2: test.o test_str.o str.o
	gcc test.o test_str.o str.o -o lab2

test.o: test.c test_str.h 
	gcc -c test.c -o test.o

test_str.o: test_str.c test_str.h str.h
	gcc -c test_str.c -o test_str.o



str.o: str.c str.h 
	gcc -c str.c -o str.o







