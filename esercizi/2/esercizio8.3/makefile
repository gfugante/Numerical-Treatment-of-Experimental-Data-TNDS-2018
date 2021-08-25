LIBS:= `root-config --libs`
INCS:= `root-config --cflags`

all: esercizio8.3
esercizio8.3: esercizio8.3.o Random.o
	g++ esercizio8.3.o Random.o -o esercizio8.3 ${INCS} ${LIBS}
esercizio8.3.o: esercizio8.3.cc Random.h
	g++ -c esercizio8.3.cc -o esercizio8.3.o ${INCS}
Random.o: Random.cc Random.h
	g++ -c Random.cc -o Random.o
