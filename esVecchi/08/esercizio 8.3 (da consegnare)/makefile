LIBS:= `root-config --libs`
INCS:= `root-config --cflags`

all:esercizio8.3

esercizio8.3: esercizio8.3.o Random.o Vettore.o Gaussiana.o
	g++ esercizio8.3.o Random.o Vettore.o Gaussiana.o -o esercizio8.3 ${INCS} ${LIBS}

esercizio8.3.o: esercizio8.3.cpp Random.h Vettore.h
	g++ -c esercizio8.3.cpp -o esercizio8.3.o ${INCS}

Random.o: Random.cpp Random.h Gaussiana.h
	g++ -c Random.cpp -o Random.o 

Vettore.o: Vettore.cpp Vettore.h
	g++ -c Vettore.cpp -o Vettore.o

Gaussiana.o: Gaussiana.cpp Gaussiana.h FunzioneBase.h
	g++ -c Gaussiana.cpp -o Gaussiana.o

clean:
	rm -f  *.o esercizio8.3
