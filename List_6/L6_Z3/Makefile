CPPFLAGS= -c -Iinc -std=c++11 -g
CXXFLAGS= -std=c++11 -g

__start__: L6_Z3
	./L6_Z3

L6_Z3: obj/L6_Z3.o
	g++ ${CXXFLAGS} -o L6_Z3 obj/L6_Z3.o

obj/L6_Z3.o: src/L6_Z3.cpp inc/Path.hpp inc/Graph_matrix.hpp inc/Graph_list.hpp inc/Data.hpp inc/List.hpp
	g++ ${CPPFLAGS} -o obj/L6_Z3.o src/L6_Z3.cpp

clean:
	rm obj/*.o
	rm L6_Z3
	
