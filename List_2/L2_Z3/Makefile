CPPFLAGS= -c -Iinc -std=c++14
CXXFLAGS= -std=c++14

__start__: L2_Z3
	./L2_Z3

L2_Z3: obj/L2_Z3.o
	g++ ${CXXFLAGS} -o L2_Z3 obj/L2_Z3.o

obj/L2_Z3.o: src/L2_Z3.cpp inc/libraries.hpp inc/Data.hpp inc/Queue.hpp
	g++ ${CPPFLAGS} -o obj/L2_Z3.o src/L2_Z3.cpp

clean:
	rm obj/*.o
	rm L2_Z3
	
