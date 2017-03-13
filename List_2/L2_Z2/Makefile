CPPFLAGS= -c -Iinc -std=c++14
CXXFLAGS= -std=c++14

__start__: L2_Z2
	./L2_Z2

L2_Z2: obj/L2_Z2.o
	g++ ${CXXFLAGS} -o L2_Z2 obj/L2_Z2.o

obj/L2_Z2.o: src/L2_Z2.cpp inc/libraries.hpp inc/Data.hpp inc/List.hpp
	g++ ${CPPFLAGS} -o obj/L2_Z2.o src/L2_Z2.cpp

clean:
	rm obj/*.o
	rm L2_Z2
	
