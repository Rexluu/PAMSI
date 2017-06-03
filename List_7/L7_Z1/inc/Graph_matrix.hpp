#ifndef path
#define path
#include "Path.hpp"
#endif

template <typename Type>
class Graph_matrix
{
    Type *vertex_value;
    Path **matrix;

    unsigned int vertex_size;
    unsigned int counter;

    public:
    Graph_matrix(unsigned int v_s);
    ~Graph_matrix();

    long int find_pos_vertex(Type data);

    void insert_vertex(Type data);
    void remove_vertex(Type data);
    void replace(Type v, Type data);
    void insert_edge(Type first_vertex, Type second_vertex, unsigned int priority);
    void insert_edge_pos(unsigned int pos1, unsigned int pos2, unsigned int priority);
    void remove_edge(Type first_vertex, Type second_vertex);
    bool are_adjacent(Type first_vertex, Type second_vertex);
    const Type return_vertex(unsigned int pos);
    const long int return_edge_priority(Type first_vertex, Type second_vertex);
    const unsigned int get_size();
    bool exist(Type data);

    void show_graph();
};

template <typename Type>
Graph_matrix<Type>::Graph_matrix(unsigned int v_s)
{
    vertex_size = v_s;
    counter = 0;

    matrix = new Path* [vertex_size];
    for (unsigned int i = 0; i < vertex_size; i++)
        matrix[i] = new Path[vertex_size];

    for (unsigned int i = 0; i < vertex_size; i++)
        for (unsigned int j = 0; j < vertex_size; j++) {
            matrix[i][j].set_value(0);
            matrix[i][j].set_priority(0);
        }

    vertex_value = new Type [vertex_size];
}

template <typename Type>
Graph_matrix<Type>::~Graph_matrix()
{ 
    for (unsigned int i = 0; i < vertex_size; i++)
        delete [] matrix[i];

    delete [] matrix;
    delete [] vertex_value; 
} 

template <typename Type>
void Graph_matrix<Type>::insert_vertex(Type data)
{
    vertex_value[counter] = data;
    counter++;
}

template <typename Type>
long int Graph_matrix<Type>::find_pos_vertex(Type data)
{
    for (unsigned int i = 0; i < vertex_size; i++)
        if (vertex_value[i] == data) return i;

    return -1;
}


template <typename Type>
void Graph_matrix<Type>::remove_vertex(Type data)
{
    long int pos = find_pos_vertex(data);
    if (pos != -1) {
        for (unsigned int i = 0; i < vertex_size; i++)
        matrix[pos][i].set_value(0);
    }

    counter--;
}

template <typename Type>
void Graph_matrix<Type>::replace(Type v, Type data)
{
    long int pos = find_pos_vertex(v);
    if (pos != -1) vertex_value[pos] = data;
}

template <typename Type>
void Graph_matrix<Type>::insert_edge(Type first_vertex, Type second_vertex, unsigned int priority)
{
    long int pos1 = find_pos_vertex(first_vertex);
    long int pos2 = find_pos_vertex(second_vertex);
    if (pos1 != -1 && pos2 != -1) {
        matrix[pos1][pos2].set_value(1);
        matrix[pos1][pos2].set_priority(priority);
        matrix[pos2][pos1].set_value(1);                // remove if "skierowany
        matrix[pos2][pos1].set_priority(priority);      // remove if "skierowany
    }
}

template <typename Type>
void Graph_matrix<Type>::insert_edge_pos(unsigned int pos1, unsigned int pos2, unsigned int priority)
{
        matrix[pos1][pos2].set_value(1);
        matrix[pos1][pos2].set_priority(priority);
        matrix[pos2][pos1].set_value(1);                // remove if "skierowany
        matrix[pos2][pos1].set_priority(priority);      // remove if "skierowany
}

template <typename Type>
void Graph_matrix<Type>::remove_edge(Type first_vertex, Type second_vertex)
{
    long int pos1 = find_pos_vertex(first_vertex);
    long int pos2 = find_pos_vertex(second_vertex);
    if (pos1 != -1 && pos2 != -1) {
        matrix[pos1][pos2].set_value(0);
        matrix[pos1][pos2].set_priority(0);
        matrix[pos2][pos1].set_value(0);    // remove if "skierowany
        matrix[pos2][pos1].set_priority(0); // remove if "skierowany
    }
}

template <typename Type>
bool Graph_matrix<Type>::are_adjacent(Type first_vertex, Type second_vertex)
{
    long int pos1 = find_pos_vertex(first_vertex);
    long int pos2 = find_pos_vertex(second_vertex);
    if (pos1 != -1 && pos2 != -1) 
        if (matrix[pos1][pos2].get_value() == 1) return true;
        if (matrix[pos2][pos1].get_value() == 1) return true;

    return false;
}

template <typename Type>
void Graph_matrix<Type>::show_graph()
{
    std::cout << "\nGraf nieskierowany: \n"; 
    for (unsigned int i = 0; i < vertex_size; i++) {
        for (unsigned int j = 0; j < vertex_size; j++) {
            if(matrix[i][j].get_value() == 1) {
               std::cout << vertex_value[i];
               std::cout << " --- " <<  matrix[i][j].get_priority() << " ---> " << vertex_value[j] << std::endl;
            }
        }
    }
}

template <typename Type>
const Type Graph_matrix<Type>::return_vertex(unsigned int pos)
{
    return vertex_value[pos];
}

template <typename Type>
const long int Graph_matrix<Type>::return_edge_priority(Type first_vertex, Type second_vertex)
{
    long int pos1 = find_pos_vertex(first_vertex);
    long int pos2 = find_pos_vertex(second_vertex);
    if (pos1 != -1 && pos2 != -1)
        if (matrix[pos1][pos2].get_value() == 1) return matrix[pos1][pos2].get_priority();
        if (matrix[pos2][pos1].get_value() == 1) return matrix[pos2][pos1].get_priority();

    return -1;
}

template <typename Type>
const unsigned int Graph_matrix<Type>::get_size()
{
    return counter;
}

template <typename Type>
bool Graph_matrix<Type>::exist(Type data)
{
    for (unsigned int i = 0; i < counter; i++)
        if(data == vertex_value[i]) return true;

    return false;
}