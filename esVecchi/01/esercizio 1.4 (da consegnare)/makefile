
all: funzioni

funzioni: main.o funzioni.o
	g++ main.o funzioni.o -o funzioni
main.o: main.C funzioni.h
	g++ -c main.C -o main.o
funzioni.o: funzioni.C
	g++ -c funzioni.C -o funzioni.o

clean:
	rm -f *.o funzioni



