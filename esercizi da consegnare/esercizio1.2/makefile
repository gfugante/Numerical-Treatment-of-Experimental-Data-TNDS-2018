
all: esercizio1.2

esercizio1.2 : main.o scambia.o
	g++ main.o scambia.o -o esercizio1.2

main.o : main.C scambia.h
	g++ -c main.C -o main.o

scambia.o : scambia.C 
	g++ -c scambia.C -o scambia.o



clean:
	rm -f *.o esercizio1.2
