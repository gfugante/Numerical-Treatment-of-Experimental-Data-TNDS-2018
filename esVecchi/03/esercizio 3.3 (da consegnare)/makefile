all: potenziale

potenziale: main.o Posizione.o Particella.o
	g++ main.o Posizione.o Particella.o -o potenziale

main.o: main.C Posizione.h Particella.h
	g++ -c main.C -o main.o

Particella.o: Particella.C Particella.h Posizione.h
	g++ -c Particella.C -o Particella.o

Posizione.o: Posizione.C Posizione.h
	g++ -c Posizione.C -o Posizione.o

clean: 
	rm -f *.o potenziale
	
