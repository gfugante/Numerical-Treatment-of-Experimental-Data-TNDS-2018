LIBS:= `root-config --libs`
INCS:= `root-config --cflags`

all: esercizio9.3

esercizio9.3: esercizio9.3.o Integratore.o SferaChar.o Vettore.o Random.o Gaussiana.o
	g++ esercizio9.3.o Integratore.o SferaChar.o Vettore.o Random.o Gaussiana.o -o esercizio9.3 ${INCS} ${LIBS}

esercizio9.3.o: esercizio9.3.cpp Integratore.h SferaChar.h
	g++ -c esercizio9.3.cpp -o esercizio9.3.o ${INCS}

Integratore.o: Integratore.cpp Integratore.h Random.h Vettore.h
	g++ -c Integratore.cpp -o Integratore.o

SferaChar.o: SferaChar.cpp SferaChar.h FunzioneBase.h
	g++ -c SferaChar.cpp -o SferaChar.o

Vettore.o: Vettore.cpp Vettore.h
	g++ -c Vettore.cpp -o Vettore.o

Random.o: Random.cpp Random.h Gaussiana.h
	g++ -c Random.cpp -o Random.o

Gaussiana.o: Gaussiana.cpp Gaussiana.h FunzioneBase.h
	g++ -c Gaussiana.cpp -o Gaussiana.o

clean:
	rm -f *.o esercizio9.3
