
all: esercizio1.4

esercizio1.4: main.o funzioni.o
	g++ main.o funzioni.o -o esercizio1.4
	
main.o: main.C funzioni.h
	g++ -c main.C -o main.o

funzioni.o: funzioni.C
	g++ -c funzioni.C -o funzioni.o

clean:
	rm -f *.o esercizio1.4



