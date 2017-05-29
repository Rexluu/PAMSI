#include <iostream>
#include "Graph_matrix.hpp"
#include "Graph_list.hpp"


void test_graph()
{
    int array[4] = {4, 1, 3, 2};
    Graph_matrix <int> gm(4);
    Graph_list <int> gl(4);
    
    for (unsigned int i = 0; i < 4; i++) {
        gm.insert_vertex(array[i]);
        gl.insert_vertex(array[i]);
    }

    gm.insert_edge(1,2,0);
    gm.insert_edge(2,3,0);
    gm.insert_edge(3,1,0);
    gm.insert_edge(3,4,0);
    gl.insert_edge(1,2,0);
    gl.insert_edge(2,3,0);
    gl.insert_edge(3,1,0);
    gl.insert_edge(3,4,0);

    std::cout << "\nGraf oparty o macierz sąsiedztwa";
    gm.show_graph();
    std::cout << std::endl;
    std::cout << "Po usunięciu wierzchołka 1 i jego krawedzi:";
    gm.remove_vertex(1);
    gm.show_graph();

    std::cout << std::endl;
    std::cout << std::endl;

    
    std::cout << "Graf oparty o liste sąsiedztwa:";
    gl.show_graph();
    std::cout << std::endl;
    std::cout << "Po usunięciu wierzchołka 1 i jego krawedzi: ";
    gl.remove_vertex(1);
    gl.show_graph();
    
    
}


int main()
{
    test_graph();
    return 0; 
}