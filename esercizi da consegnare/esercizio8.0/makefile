LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: esercizio8.0

esercizio8.0: main.o Random.o
	g++ main.o Random.o -o esercizio8.0 ${INCS} ${LIBS}

main.o: main.C Random.h
	g++ -c main.C -o main.o ${INCS}
	
Random.o: Random.C Random.h
	g++ -c Random.C -o Random.o
	
clean:
	rm -f *.o esercizio8.0
