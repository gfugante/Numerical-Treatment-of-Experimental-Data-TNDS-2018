INCS:=` root-config --cflags`
LIBS:=` root-config --libs`


Esercizio: Esercizio.o vettore.o vettoreDati.o
	g++ Esercizio.o vettore.o vettoreDati.o -o Esercizio_6.2

Esercizio.o: Esercizio_6.2.cpp vettore.h vettoreDati.h
	g++ -c Esercizio_6.2.cpp -o Esercizio.o

vettore.o: vettore.cpp vettore.h
	g++ -c vettore.cpp -o vettore.o

vettoreDati.o: vettoreDati.cpp vettore.h vettoreDati.h
	g++ -c vettoreDati.cpp -o vettoreDati.o


root: 
	g++ -o disegnaROOT disegnaROOT.cpp ${INCS} ${LIBS}


