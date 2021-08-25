

all: main

main: main.o Vettore.o
	g++ main.o Vettore.o -o main

main.o: main.C Vettore.h
	g++ -c main.C -o main.o

Vettore.o: Vettore.C Vettore.h
	g++ -c Vettore.C -o Vettore.o

clean:
	rm -f *.o main
