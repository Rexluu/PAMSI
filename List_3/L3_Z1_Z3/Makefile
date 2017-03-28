CPPFLAGS= -c -Iinc -std=c++14
CXXFLAGS= -std=c++14

__start__: L3_Z1
	./L3_Z1

L3_Z1: obj/L3_Z1.o
	g++ ${CXXFLAGS} -o L3_Z1 obj/L3_Z1.o

obj/L3_Z1.o: src/L3_Z1.cpp inc/Stack_a.hpp inc/Stack.hpp inc/Data.hpp
	g++ ${CPPFLAGS} -o obj/L3_Z1.o src/L3_Z1.cpp

clean:
	rm obj/*.o
	rm L3_Z1
	
