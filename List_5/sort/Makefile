CPPFLAGS= -c -Iinc -std=c++14 -O2
CXXFLAGS= -std=c++14 -O2

__start__: L5
	./L5

L5: obj/L5.o
	g++ ${CXXFLAGS} -o L5 obj/L5.o

obj/L5.o: src/L5.cpp inc/quicksort.hpp inc/mergesort.hpp inc/introsort.hpp
	g++ ${CPPFLAGS} -o obj/L5.o src/L5.cpp

clean:
	rm obj/*.o
	rm L5
	