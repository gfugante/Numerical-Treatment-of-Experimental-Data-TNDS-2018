all: esercizio6.1

esercizio6.1: esercizio6.1.o VettoreDati.o Vettore.o Scambia.o
	g++ esercizio6.1.o VettoreDati.o Vettore.o Scambia.o -o esercizio6.1

esercizio6.1.o: esercizio6.1.cpp VettoreDati.h
	g++ -c esercizio6.1.cpp -o esercizio6.1.o

VettoreDati.o: VettoreDati.cpp VettoreDati.h Vettore.h Scambia.h
	g++ -c VettoreDati.cpp -o VettoreDati.o

Vettore.o: Vettore.cpp Vettore.h
	g++ -c Vettore.cpp -o Vettore.o

Scambia.o: Scambia.cpp Scambia.h
	g++ -c Scambia.cpp -o Scambia.o

clean:
	rm -f *.o esercizio6.1
