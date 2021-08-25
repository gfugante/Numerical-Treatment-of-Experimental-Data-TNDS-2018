esercizio7.2: main.o integrale.o trigonometric.o
	g++ main.o integrale.o trigonometric.o -o esercizio7.2
main.o: main.cpp integrale.hpp funzionebase.h trigonometric.hpp
	g++ -c main.cpp -o main.o
integrale.o: integrale.cpp integrale.hpp funzionebase.h
	g++ -c integrale.cpp -o integrale.o
trigonometric.o: trigonometric.cpp trigonometric.hpp funzionebase.h
	g++ -c trigonometric.cpp -o trigonometric.o
