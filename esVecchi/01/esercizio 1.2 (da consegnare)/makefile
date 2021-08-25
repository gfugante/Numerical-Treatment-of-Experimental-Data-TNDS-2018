
all: vett

vett : main.o scambia.o
	g++ main.o scambia.o -o vett

main.o : main.C scambia.h
	g++ -c main.C -o main.o

scambia.o : scambia.C 
	g++ -c scambia.C -o scambia.o



clean:
	rm -f *.o prova
