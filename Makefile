game_of_life.x: main.o World.o
	g++ -std=c++11 main.o World.o  -Wall -o game_of_life.x -Wall

main.o: main.cpp World.h
	g++ -std=c++11 -g -c main.cpp -Wall

World.o: World.cpp World.h
	g++ -std=c++11 -g -c World.cpp -Wall

clean:
	rm *.x *.o *.gch