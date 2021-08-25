LIBS:= `root-config --libs`
INCS:= `root-config --cflags`

all: esercizio8.2
esercizio8.2: esercizio8.2.o Random.o
	g++ esercizio8.2.o Random.o -o esercizio8.2 ${INCS} ${LIBS}
esercizio8.2.o: esercizio8.2.cc Random.h
	g++ -c esercizio8.2.cc -o esercizio8.2.o ${INCS}
Random.o: Random.cc Random.h
	g++ -c Random.cc -o Random.o
