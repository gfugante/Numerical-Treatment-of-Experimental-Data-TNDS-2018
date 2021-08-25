INCS = `root-config --cflags`
LIBS = `root-config --libs`

all:esercizio10.3

esercizio10.3: esercizio10.3.o Vettore.o VettoreLineare.o Pendolo.o RungeKutta.o
	g++ -o esercizio10.3 esercizio10.3.o Vettore.o VettoreLineare.o Pendolo.o RungeKutta.o $(INCS) $(LIBS)

esercizio10.3.o: esercizio10.3.cpp VettoreLineare.h RungeKutta.h Pendolo.h
	g++ -c esercizio10.3.cpp -o esercizio10.3.o $(INCS)

Vettore.o: Vettore.cpp Vettore.h
	g++ -c Vettore.cpp -o Vettore.o

VettoreLineare.o: VettoreLineare.cpp VettoreLineare.h Vettore.h
	g++ -c VettoreLineare.cpp -o VettoreLineare.o

RungeKutta.o: RungeKutta.cpp RungeKutta.h EquazioneDifferenziale.h VettoreLineare.h
	g++ -c RungeKutta.cpp -o RungeKutta.o  

Pendolo.o: Pendolo.cpp Pendolo.h
	g++ -c Pendolo.cpp -o Pendolo.o

clean:
	rm -f *.o esercizio10.3
