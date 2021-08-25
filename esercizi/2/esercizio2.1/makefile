all: esercizio2.1
esercizio2.1: esercizio2.1.o funzioni.o
	g++ esercizio2.1.o funzioni.o -o esercizio2.1
esercizio2.1.o: esercizio2.1.cc prototipi.h
	g++ -c esercizio2.1.cc -o esercizio2.1.o
funzioni.o: funzioni.cc prototipi.h
	g++ -c funzioni.cc -o funzioni.o

