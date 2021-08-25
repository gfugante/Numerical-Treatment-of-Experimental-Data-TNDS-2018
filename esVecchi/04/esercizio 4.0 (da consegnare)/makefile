all: puntomateriale

puntomateriale: main.o Posizione.o Particella.o PuntoMateriale.o CampoVettoriale.o
	g++ main.o Posizione.o Particella.o PuntoMateriale.o CampoVettoriale.o -o puntomateriale

main.o: main.C Posizione.h PuntoMateriale.h CampoVettoriale.h
	g++ -c main.C -o main.o

Posizione.o: Posizione.C
	g++ -c Posizione.C -o Posizione.o

PuntoMateriale.o: PuntoMateriale.C PuntoMateriale.h Posizione.h Particella.h CampoVettoriale.h
	g++ -c PuntoMateriale.C -o PuntoMateriale.o

CampoVettoriale.o: CampoVettoriale.C Posizione.h
	g++ -c CampoVettoriale.C -o CampoVettoriale.o


clean:
	rm -f *.o puntomateriale

esegui:
	./puntomateriale
