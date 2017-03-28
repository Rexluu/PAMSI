CPPFLAGS= -c -Iinc -std=c++14
CXXFLAGS= -std=c++14

__start__: L3_Z4
	./L3_Z4

L3_Z4: obj/L3_Z4.o
	g++ ${CXXFLAGS} -o L3_Z4 obj/L3_Z4.o

obj/L3_Z4.o: src/L3_Z4.cpp inc/Data.hpp inc/Stack.hpp
	g++ ${CPPFLAGS} -o obj/L3_Z4.o src/L3_Z4.cpp

clean:
	rm obj/*.o
	rm L3_Z4
	
