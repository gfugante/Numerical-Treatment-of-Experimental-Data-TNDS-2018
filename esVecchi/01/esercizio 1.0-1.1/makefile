
all: prova 

prova: main.o scambia.o
	g++ main.o scambia.o -o prova
main.o: main.C scambia.h
	g++ -c main.C -o main.o
scambia.o : scambia.C 
	g++ -c scambia.C -o scambia.o

clean:
	rm -f *.o prova
