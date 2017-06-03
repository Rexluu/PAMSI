#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Graph_matrix.hpp"
#include "Graph_list.hpp"
#include "Priority_queue.hpp"

#ifndef list
#define list
#include "List.hpp"
#endif

 // IMPORTANT because algorithms arent on templates
#define variable_type int
// Include algorithms:
#include "Kruskal.hpp"
#include "Prima.hpp"

double average_time(double *array, int number)
{
    double sum = array[0];
    for (int i = 0; i < number; i++)
        sum+=array[i];

    return sum/number;
}

void random_array(variable_type *array, unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
        array[i] = i;

    for (unsigned int i = 0; i < length; i++) {
        unsigned int index = std::rand() % length;
        variable_type temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
}

void algorithms_test()
{
    int array_V[5] = {10, 50, 100, 250, 500};
    float array_E[4] = {0.25, 0.50, 0.75, 1.0};
    const unsigned int repeat_size = 3;
    
    double time_km[repeat_size];
    double time_kl[repeat_size];
    double time_pm[repeat_size];
    double time_pl[repeat_size];

    unsigned int counter = 0;
    double final_time_km[20];
    double final_time_kl[20];
    double final_time_pm[20];
    double final_time_pl[20];

    time_t start,stop;

       for (unsigned int j = 0; j < 5; j++)
           for (unsigned int o = 0; o < 4; o++) {
            std::cout << "\nLicze dla: " << array_V[j] << "w. | Gestosc: " << array_E[o];
               for (unsigned int i = 0; i < repeat_size; i++) {
                    Graph_matrix <variable_type> gm(array_V[j]);
                    Graph_list <variable_type> gl(array_V[j]);
                    variable_type array_v_value[array_V[j]];
                    random_array(array_v_value, array_V[j]);
                    for (unsigned int p = 0; p < array_V[j] ; p++) {
                        gm.insert_vertex(array_v_value[p]);
                        gl.insert_vertex(array_v_value[p]);
                    }
                    int k = 0;
                    int l = 0;
                    int q = 0;
                    unsigned int edge_size = (array_E[o]*array_V[j]*(array_V[j] - 1))/2;
                    for (unsigned int n = 0; n < edge_size; n++) {
                        if (k % array_V[j] == 0) l++;
                        k = n % array_V[j];
                        q = ((k % array_V[j]) + l) % array_V[j];
                        gm.insert_edge_pos(k, q, rand() % (2 * edge_size));
                        gl.insert_edge_pos(k, q, rand() % (2 * edge_size));
                    }

                    start = clock(); 
                    kruskal_algorithm_matrix(gm);
                    stop = clock();
                    time_km[i] = double (stop-start)/CLOCKS_PER_SEC;

                    start = clock(); 
                    kruskal_algorithm_list(gl);
                    stop = clock();
                    time_kl[i] = double (stop-start)/CLOCKS_PER_SEC;

                    start = clock(); 
                    prima_algorithm_matrix(gm);
                    stop = clock();
                    time_pm[i] = double (stop-start)/CLOCKS_PER_SEC;

                    start = clock(); 
                    prima_algorithm_list(gl);
                    stop = clock();
                    time_pl[i] = double (stop-start)/CLOCKS_PER_SEC;
              }

            counter++;
            final_time_km[counter] =  average_time(time_km, repeat_size);
            final_time_kl[counter] =  average_time(time_kl, repeat_size);
            final_time_pm[counter] =  average_time(time_pm, repeat_size);
            final_time_pl[counter] =  average_time(time_pl, repeat_size);

           }

           counter = 0;

           for (unsigned int i = 0; i < 5; i++)
           for (unsigned int j = 0; j < 4; j++) {
                counter++;
                std::cout << "\n\n\nWierzcholkow: " << array_V[i] << " | Gestosc: " << array_E[j];
                std::cout << "\nCzas Kruskal macierz: " << final_time_km[counter];
                std::cout << "\nCzas Kruskal lista: " << final_time_kl[counter];
                std::cout << "\nCzas Prima macierz: " << final_time_pm[counter];
                std::cout << "\nCzas Prima lista: " << final_time_pl[counter];
           }
}       

void single_test_graph_prima()
{
    int array[8] = {4, 6, 5, 2, 7, 0, 1, 3};
    Graph_matrix <variable_type> gm(8);
    Graph_list <variable_type> gl(8);
    
    for (unsigned int i = 0; i < 8; i++) {
        gm.insert_vertex(array[i]);
        gl.insert_vertex(array[i]);
    }

    gm.insert_edge(1,2,9);
    gm.insert_edge(4,6,1);
    gm.insert_edge(3,6,8);
    gm.insert_edge(0,3,9);
    gm.insert_edge(0,6,3);
    gm.insert_edge(2,4,4);
    gm.insert_edge(0,1,5);
    gm.insert_edge(5,6,6);
    gm.insert_edge(1,7,7);
    gm.insert_edge(2,3,9);
    gm.insert_edge(6,7,9);
    gm.insert_edge(4,5,2);
    gm.insert_edge(2,7,3);
    gm.insert_edge(2,6,5);
    gm.insert_edge(1,5,6);
    gm.insert_edge(1,4,8);

    gl.insert_edge(1,2,9);
    gl.insert_edge(4,6,1);
    gl.insert_edge(3,6,8);
    gl.insert_edge(0,3,9);
    gl.insert_edge(0,6,3);
    gl.insert_edge(2,4,4);
    gl.insert_edge(0,1,5);
    gl.insert_edge(5,6,6);
    gl.insert_edge(1,7,7);
    gl.insert_edge(2,3,9);
    gl.insert_edge(6,7,9);
    gl.insert_edge(4,5,2);
    gl.insert_edge(2,7,3);
    gl.insert_edge(2,6,5);
    gl.insert_edge(1,5,6);
    gl.insert_edge(1,4,8);

    std::cout << "\n\nGraf z użyciem macierzy sąsiedztwa po zastosowaniu algorytmu Prima:";
    prima_algorithm_matrix(gm);
    std::cout << "\nGraf z użyciem listy sąsiedztwa po zastosowaniu algorytmu Prima:";
    prima_algorithm_list(gl);
}

void single_test_graph_kruskal()
{
    int array[8] = {4, 6, 5, 2, 7, 0, 1, 3};
    Graph_matrix <variable_type> gm(8);
    Graph_list <variable_type> gl(8);
    
    for (unsigned int i = 0; i < 8; i++) {
        gm.insert_vertex(array[i]);
        gl.insert_vertex(array[i]);
    }

    gm.insert_edge(1,2,9);
    gm.insert_edge(4,6,1);
    gm.insert_edge(3,6,8);
    gm.insert_edge(0,3,9);
    gm.insert_edge(0,6,3);
    gm.insert_edge(2,4,4);
    gm.insert_edge(0,1,5);
    gm.insert_edge(5,6,6);
    gm.insert_edge(1,7,7);
    gm.insert_edge(2,3,9);
    gm.insert_edge(6,7,9);
    gm.insert_edge(4,5,2);
    gm.insert_edge(2,7,3);
    gm.insert_edge(2,6,5);
    gm.insert_edge(1,5,6);
    gm.insert_edge(1,4,8);
    
    gl.insert_edge(1,2,9);
    gl.insert_edge(4,6,1);
    gl.insert_edge(3,6,8);
    gl.insert_edge(0,3,9);
    gl.insert_edge(0,6,3);
    gl.insert_edge(2,4,4);
    gl.insert_edge(0,1,5);
    gl.insert_edge(5,6,6);
    gl.insert_edge(1,7,7);
    gl.insert_edge(2,3,9);
    gl.insert_edge(6,7,9);
    gl.insert_edge(4,5,2);
    gl.insert_edge(2,7,3);
    gl.insert_edge(2,6,5);
    gl.insert_edge(1,5,6);
    gl.insert_edge(1,4,8);

    std::cout << "\n\nGraf z użyciem macierzy sąsiedztwa po zastosowaniu algorytmu Kruskala:";
    kruskal_algorithm_matrix(gm);
    std::cout << "\nGraf z użyciem listy sąsiedztwa po zastosowaniu algorytmu Kruskala:";
    kruskal_algorithm_list(gl);
}



int main()
{
    srand( time( NULL ) );
    //single_test_graph_kruskal();
    //single_test_graph_prima();
    algorithms_test();
    return 0; 
}