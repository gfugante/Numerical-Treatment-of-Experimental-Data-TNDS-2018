LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: esercizio9.3

esercizio9.3: esercizio9.3.o integrator.o vettore.o random.o F.o
	g++ esercizio9.3.o vettore.o random.o F.o integrator.o -o esercizio9.3 ${INCS} ${LIBS}

esercizio9.3.o: esercizio9.3.cpp random.h integrator.h funzionebase.h F.h vettore.h
	g++ -c esercizio9.3.cpp -o esercizio9.3.o ${INCS}

integrator.o: integrator.cpp integrator.h funzionebase.h vettore.h
	g++ -c integrator.cpp -o integrator.o

random.o: random.cpp random.h
	g++ -c random.cpp -o random.o

vettore.o: vettore.h vettore.cpp
	g++ -c vettore.cpp -o vettore.o

F.o: F.h F.cpp
	g++ -c F.cpp -o F.o

clean:
	rm *.o esercizio9.3
