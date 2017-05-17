CPPFLAGS= -c -Iinc -std=c++11
CXXFLAGS= -std=c++11

__start__: L6_Z2
	./L6_Z2

L6_Z2: obj/L6_Z2.o
	g++ ${CXXFLAGS} -o L6_Z2 obj/L6_Z2.o

obj/L6_Z2.o: src/L6_Z2.cpp inc/Data.hpp inc/AVL_tree.hpp
	g++ ${CPPFLAGS} -o obj/L6_Z2.o src/L6_Z2.cpp

clean:
	rm obj/*.o
	rm L6_Z2
	
