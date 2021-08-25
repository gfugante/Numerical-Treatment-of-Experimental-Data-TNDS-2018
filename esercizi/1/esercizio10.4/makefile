INCS:=` root-config --cflags`
LIBS:=` root-config --libs`


Esercizio: Esercizio.o  equazionidifferenziali.o  vettorelineare.o vettore.o
	g++ Esercizio.o  equazionidifferenziali.o  vettorelineare.o vettore.o -o Esercizio_10.4 ${INCS} ${LIBS}

Esercizio.o: Esercizio_10.4.cpp  vettorelineare.h
	g++ -c Esercizio_10.4.cpp -o Esercizio.o ${INCS}


vettorelineare.o: vettorelineare.cpp vettorelineare.h vettore.h
	g++ -c vettorelineare.cpp -o vettorelineare.o 

vettore.o: vettore.cpp vettore.h 
	g++ -c vettore.cpp -o vettore.o 

equazionidifferenziali.o: equazionidifferenziali.cpp equazionidifferenziali.h vettorelineare.h vettore.h
	g++ -c equazionidifferenziali.cpp -o equazionidifferenziali.o 


root: 
	g++ -o disegnaROOT.x disegnaROOT.cpp ${INCS} ${LIBS}






