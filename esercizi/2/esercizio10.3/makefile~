LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: esercizio10.3
esercizio10.3: esercizio10.3.o VettoreLineare.o equazioniDifferenziali.o vettore.o
	g++ esercizio10.3.o VettoreLineare.o equazioniDifferenziali.o vettore.o -o esercizio10.3 ${INCS} ${LIBS}

esercizio10.3.o: esercizio10.3.cc VettoreLineare.h equazioniDifferenziali.h
	g++ -c esercizio10.3.cc -o esercizio10.3.o ${INCS}

VettoreLineare.o: VettoreLineare.cc VettoreLineare.h vettore.h
	g++ -c VettoreLineare.cc -o VettoreLineare.o

equazioniDifferenziali.o: equazioniDifferenziali.cc VettoreLineare.h equazioniDifferenziali.h
	g++ -c equazioniDifferenziali.cc -o equazioniDifferenziali.o

vettore.o: vettore.cc vettore.h
	g++ -c vettore.cc -o vettore.o

clean:
	rm -f *.o esercizio10.3
