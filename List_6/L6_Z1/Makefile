CPPFLAGS= -c -Iinc -g -Wall -pedantic -std=c++11
CXXFLAGS= -g -std=c++11

__start__: L6
	./L6

L6: obj/L6.o
	g++ ${CXXFLAGS} -o L6 obj/L6.o

obj/L6.o: src/L6.cpp inc/Link.hpp inc/Linear.hpp inc/Double_hash.hpp inc/List.hpp inc/Data.hpp
	g++ ${CPPFLAGS} -o obj/L6.o src/L6.cpp

clean:
	rm obj/*.o
	rm L6
	
