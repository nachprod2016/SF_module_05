machine: Snack.o main.o
	g++ -o machine Snack.o main.o
Snack.o: Snack.cpp Snack.h
	g++ -c Snack.cpp
main.o: main.cpp
	g++ -c main.cpp
clear:
	rm -f *.o