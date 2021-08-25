LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: esercizio10.2
esercizio10.2: esercizio10.2.o VettoreLineare.o equazioniDifferenziali.o vettore.o
	g++ esercizio10.2.o VettoreLineare.o equazioniDifferenziali.o vettore.o -o esercizio10.2 ${INCS} ${LIBS}

esercizio10.2.o: esercizio10.2.cc VettoreLineare.h equazioniDifferenziali.h
	g++ -c esercizio10.2.cc -o esercizio10.2.o ${INCS}

VettoreLineare.o: VettoreLineare.cc VettoreLineare.h vettore.h
	g++ -c VettoreLineare.cc -o VettoreLineare.o

equazioniDifferenziali.o: equazioniDifferenziali.cc VettoreLineare.h equazioniDifferenziali.h
	g++ -c equazioniDifferenziali.cc -o equazioniDifferenziali.o

vettore.o: vettore.cc vettore.h
	g++ -c vettore.cc -o vettore.o

clean:
	rm -f *.o esercizio10.2
