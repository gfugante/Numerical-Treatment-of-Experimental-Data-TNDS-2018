LIBS:= `root-config --libs`
INCS:= `root-config --cflags`

all:esercizio8.3

esercizio8.3: esercizio8.3.o Random.o Vettore.o Gaussiana.o FunzioneBase.o
	g++ esercizio8.3.o Random.o Vettore.o Gaussiana.o FunzioneBase.o -o esercizio8.3 ${INCS} ${LIBS}

esercizio8.3.o: esercizio8.3.C Random.h Vettore.h
	g++ -c esercizio8.3.C -o esercizio8.3.o ${INCS}

Random.o: Random.C Random.h Gaussiana.h
	g++ -c Random.C -o Random.o 

Vettore.o: Vettore.C Vettore.h
	g++ -c Vettore.C -o Vettore.o

Gaussiana.o: Gaussiana.C Gaussiana.h FunzioneBase.h
	g++ -c Gaussiana.C -o Gaussiana.o

FunzioneBase.o: FunzioneBase.C FunzioneBase.h
	g++ -c FunzioneBase.C -o FunzioneBase.o

	
clean:
	rm -f  *.o esercizio8.3
