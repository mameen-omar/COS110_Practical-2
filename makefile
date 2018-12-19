main: Adventurer.o  main.cpp Adventurer.h
	g++ -std=c++11 -static main.cpp  Adventurer.o -o main


Adventurer.o: Adventurer.cpp Adventurer.h
	g++ -std=c++11 -c Adventurer.cpp

run: main
	./main