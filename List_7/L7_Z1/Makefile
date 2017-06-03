CPPFLAGS= -c -Iinc -std=c++11 -g
CXXFLAGS= -std=c++11 -g

__start__: L7_Z1
	./L7_Z1

L7_Z1: obj/L7_Z1.o
	g++ ${CXXFLAGS} -o L7_Z1 obj/L7_Z1.o

obj/L7_Z1.o: src/L7_Z1.cpp inc/Path.hpp inc/Graph_matrix.hpp inc/Graph_list.hpp inc/Data.hpp inc/List.hpp inc/Data_pq.hpp inc/Priority_queue.hpp inc/Kruskal.hpp inc/Prima.hpp
	g++ ${CPPFLAGS} -o obj/L7_Z1.o src/L7_Z1.cpp

clean:
	rm obj/*.o
	rm L7_Z1
	
