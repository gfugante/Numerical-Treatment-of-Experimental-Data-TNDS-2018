INCS = `root-config --cflags`
LIBS = `root-config --libs`


esercizio10.4: esercizio10.4.o Vettore.o VettoreLineare.o OscForzatoSmorzato.o RungeKutta.o
	g++ -o esercizio10.4 esercizio10.4.o Vettore.o VettoreLineare.o OscForzatoSmorzato.o RungeKutta.o $(INCS) $(LIBS)

esercizio10.4.o: esercizio10.4.cpp VettoreLineare.h OscForzatoSmorzato.h
	g++ -c esercizio10.4.cpp -o esercizio10.4.o $(INCS)

Vettore.o: Vettore.cpp Vettore.h
	g++ -c Vettore.cpp -o Vettore.o

VettoreLineare.o: VettoreLineare.cpp VettoreLineare.h
	g++ -c VettoreLineare.cpp -o VettoreLineare.o

RungeKutta.o: RungeKutta.cpp RungeKutta.h
	g++ -c RungeKutta.cpp -o RungeKutta.o  

OscForzatoSmorzato.o: OscForzatoSmorzato.cpp OscForzatoSmorzato.h
	g++ -c OscForzatoSmorzato.cpp -o OscForzatoSmorzato.o

clean:
	rm -f *.o esercizio10.4

