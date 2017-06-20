CPPFLAGS= -c -Iinc -std=c++11 -g
CXXFLAGS= -std=c++11 -g

__start__: game
	./game

game: game.o
	g++ ${CXXFLAGS} -o game game.o

game.o: game.cpp
	g++ ${CPPFLAGS} -o game.o game.cpp

clean:
	rm obj/*.o
	rm game
	