INCS:=` root-config --cflags`
LIBS:=` root-config --libs`


esercizio10.4: main.o equazionidifferenziali.o vettore.o vettorelineare.o
	g++ main.o  equazionidifferenziali.o  vettorelineare.o vettore.o -o esercizio10.4 ${INCS} ${LIBS}
main.o: main.C  vettorelineare.h
	g++ -c main.C -o main.o ${INCS}
vettorelineare.o: vettorelineare.cpp vettorelineare.h vettore.h
	g++ -c vettorelineare.cpp -o vettorelineare.o 
vettore.o: vettore.cpp vettore.h 
	g++ -c vettore.cpp -o vettore.o 
equazionidifferenziali.o: equazionidifferenziali.cpp equazionidifferenziali.h vettorelineare.h vettore.h
	g++ -c equazionidifferenziali.cpp -o equazionidifferenziali.o 

