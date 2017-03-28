CPPFLAGS= -c -Iinc -std=c++14
CXXFLAGS= -std=c++14

__start__: Stack
	./Stack

Stack: obj/Stack.o
	g++ ${CXXFLAGS} -o Stack obj/Stack.o

obj/Stack.o: src/main.cpp inc/Data.hpp inc/Stack.hpp
	g++ ${CPPFLAGS} -o obj/Stack.o src/main.cpp

clean:
	rm obj/*.o
	rm Stack
	
