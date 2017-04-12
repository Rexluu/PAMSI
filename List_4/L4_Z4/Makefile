CPPFLAGS= -c -Iinc -std=c++14
CXXFLAGS= -std=c++14

__start__: L4_Z4
	./L4_Z4

L4_Z4: obj/L4_Z4.o
	g++ ${CXXFLAGS} -o L4_Z4 obj/L4_Z4.o

obj/L4_Z4.o: src/L4_Z4.cpp inc/libraries.hpp inc/Data.hpp inc/Priority_queue.hpp
	g++ ${CPPFLAGS} -o obj/L4_Z4.o src/L4_Z4.cpp

clean:
	rm obj/*.o
	rm L4_Z4
	
