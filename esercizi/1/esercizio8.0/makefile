INCS:=` root-config --cflags`
LIBS:=` root-config --libs`


Esercizio: Esercizio.o random.o 
	g++ Esercizio.o random.o -o Esercizio_8.0  ${INCS} ${LIBS}

Esercizio.o: Esercizio_8.0.cpp random.h 
	g++ -c Esercizio_8.0.cpp -o Esercizio.o ${INCS}

random.o: random.cpp random.h 
	g++ -c random.cpp -o random.o 






