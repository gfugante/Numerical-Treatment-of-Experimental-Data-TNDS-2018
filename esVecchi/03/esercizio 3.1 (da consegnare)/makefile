
all: punto

punto : main.o Posizione.o
	g++ main.o Posizione.o -o punto

main.o : main.C Posizione.h
	g++ -c main.C -o main.o

Posizione.o : Posizione.C 
	g++ -c Posizione.C -o Posizione.o



clean:
	rm -f *.o punto
