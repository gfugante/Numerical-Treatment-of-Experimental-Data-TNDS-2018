all: particella

particella: main.o Particella.o
	g++ main.o Particella.o -o particella

main.o: main.C Particella.h
	g++ -c main.C -o main.o

Particella.o: Particella.C
	g++ -c Particella.C -o Particella.o


clean:
	rm -f *.o particella
