CPPFLAGS= -c -Iinc -std=c++14
CXXFLAGS= -std=c++14

__start__: L2_Z4
	./L2_Z4

L2_Z4: obj/L2_Z4.o
	g++ ${CXXFLAGS} -o L2_Z4 obj/L2_Z4.o

obj/L2_Z4.o: src/L2_Z4.cpp inc/libraries.hpp inc/Data.hpp inc/Deque.hpp
	g++ ${CPPFLAGS} -o obj/L2_Z4.o src/L2_Z4.cpp

clean:
	rm obj/*.o
	rm L2_Z4
	
