INCS:=` root-config --cflags`
LIBS:=` root-config --libs`

Esercizio: Esercizio.o funzioni.o 
	g++ Esercizio_2.2.o funzioni.o -o Esercizio_2.2

Esercizio.o: Esercizio_2.2.cpp vettore.h
	g++ -c Esercizio_2.2.cpp -o Esercizio_2.2.o

funzioni.o: funzioni.cpp vettore.h
	g++ -c funzioni.cpp -o funzioni.o

root: 
	g++ -o disegnaROOT disegnaROOT.cpp ${INCS} ${LIBS}







