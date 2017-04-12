CPPFLAGS= -c -Iinc -std=c++11
CXXFLAGS= -std=c++11

__start__: L4_Z3
	./L4_Z3

L4_Z3: obj/L4_Z3.o
	g++ ${CXXFLAGS} -o L4_Z3 obj/L4_Z3.o

obj/L4_Z3.o: src/L4_Z3.cpp inc/Data.hpp inc/Tree.hpp
	g++ ${CPPFLAGS} -o obj/L4_Z3.o src/L4_Z3.cpp

clean:
	rm obj/*.o
	rm L4_Z3
	
