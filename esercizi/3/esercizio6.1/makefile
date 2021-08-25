esercizio6.1: main.o vettoredati.o vettore.o
	g++ main.o vettoredati.o vettore.o -o esercizio6.1
main.o: main.C vettoredati.h vettore.h
	g++ -c main.C -o main.o
vettoredati.o: vettoredati.C vettoredati.h vettore.h
	g++ -c vettoredati.C -o vettoredati.o
vettore.o: vettore.C vettore.h
	g++ -c vettore.C -o vettore.o
