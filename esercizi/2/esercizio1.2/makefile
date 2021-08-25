all: esercizio1.2
esercizio1.2: esercizio1.2.o funzioni.o
	g++ esercizio1.2.o funzioni.o -o esercizio1.2
esercizio1.2.o: esercizio1.2.cc prototipi.h
	g++ -c esercizio1.2.cc -o esercizio1.2.o
funzioni.o: funzioni.cc prototipi.h
	g++ -c funzioni.cc -o funzioni.o

