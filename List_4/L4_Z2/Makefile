CPPFLAGS= -c -Iinc -std=c++14
CXXFLAGS= -std=c++14

__start__: L4_Z2
	./L4_Z2

L4_Z2: obj/L4_Z2.o
	g++ ${CXXFLAGS} -o L4_Z2 obj/L4_Z2.o

obj/L4_Z2.o: src/L4_Z2.cpp inc/libraries.hpp inc/Data.hpp inc/Priority_queue.hpp
	g++ ${CPPFLAGS} -o obj/L4_Z2.o src/L4_Z2.cpp

clean:
	rm obj/*.o
	rm L4_Z2
	
