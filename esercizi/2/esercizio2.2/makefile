all: esercizio2.2
esercizio2.2: esercizio2.2.o vettore.o 
	g++ esercizio2.2.o vettore.o -o esercizio2.2
esercizio2.2.o: esercizio2.2.cc vettore.h
	g++ -c esercizio2.2.cc -o esercizio2.2.o
vettore.o: vettore.cc prototipi.h
	g++ -c vettore.cc -o vettore.o
funzioni.o: funzioni.cc prototipi.h
	g++ -c funzioni.cc -o funzioni.o

