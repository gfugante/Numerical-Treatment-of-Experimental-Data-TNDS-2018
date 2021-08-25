
all: esercizio3.1

esercizio3.1 : main.o Posizione.o
	g++ main.o Posizione.o -o esercizio3.1

main.o : main.C Posizione.h
	g++ -c main.C -o main.o

Posizione.o : Posizione.C 
	g++ -c Posizione.C -o Posizione.o



clean:
	rm -f *.o esercizio3.1
