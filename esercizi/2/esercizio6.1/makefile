all: esercizio6.1
esercizio6.1: esercizio6.1.o vettore.o vettoredati.o
	g++ esercizio6.1.o vettore.o vettoredati.o -o esercizio6.1
esercizio6.1.o: esercizio6.1.cc vettore.h vettoredati.h
	g++ -c esercizio6.1.cc -o esercizio6.1.o
vettore.o: vettore.cc vettore.h
	g++ -c vettore.cc -o vettore.o
vettoredati.o: vettoredati.cc vettoredati.h
	g++ -c vettoredati.cc -o vettoredati.o
