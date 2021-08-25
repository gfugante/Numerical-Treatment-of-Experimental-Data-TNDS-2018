
all: main

main: main.o particella.o
	g++ main.o particella.o -o main
main.o: main.C Particella.h
	g++ -c main.C -o main.o
particella.o: Particella.C Particella.h
	g++ -c Particella.C -o particella.o
