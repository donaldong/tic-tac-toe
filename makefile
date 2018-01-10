all: game

game.o: game.h game.cpp
	g++ -std=c++11 -c game.cpp

game: game.o main.cpp
	g++ -std=c++11 game.o main.cpp -o game

clean:
	rm *.o
