CPPFLAGS= -c -Iinc -std=c++14
CXXFLAGS= -std=c++14

__start__: L4_Z1
	./L4_Z1

L4_Z1: obj/L4_Z1.o
	g++ ${CXXFLAGS} -o L4_Z1 obj/L4_Z1.o

obj/L4_Z1.o: src/L4_Z1.cpp inc/libraries.hpp inc/Data.hpp inc/Priority_queue.hpp
	g++ ${CPPFLAGS} -o obj/L4_Z1.o src/L4_Z1.cpp

clean:
	rm obj/*.o
	rm L4_Z1
	
