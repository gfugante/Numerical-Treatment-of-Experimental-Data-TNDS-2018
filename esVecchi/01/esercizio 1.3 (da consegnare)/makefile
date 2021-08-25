all:esercizio1.3

esercizio1.3: esercizio1.3.o Modulo.o
	g++ esercizio1.3.o Modulo.o -o esercizio1.3

esercizio1.3.o:esercizio1.3.cpp Modulo.h Modulo.cpp
	g++ -c esercizio1.3.cpp -o esercizio1.3.o

Modulo.o: Modulo.h Modulo.cpp
	g++ -c Modulo.cpp -o Modulo.o

clean:
	rm -f *.o esercizio1.3.x
