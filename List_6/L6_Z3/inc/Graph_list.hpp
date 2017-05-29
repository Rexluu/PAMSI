#ifndef path
#define path
#include "Path.hpp"
#endif

#include "List.hpp"

template <typename Type>
class Graph_list
{
    Type *vertex_value;
    SL_List <Path> *edges;

    unsigned int vertex_size;
    unsigned int counter;
    
    long int find_pos_vertex(Type data);

    public:
    Graph_list(unsigned int v_s);
    ~Graph_list();

    void insert_vertex(Type data);
    void remove_vertex(Type data);
    void replace(Type v, Type data);
    void insert_edge(Type first_vertex, Type second_vertex, unsigned int priority);
    void remove_edge(Type first_vertex, Type second_vertex);
    bool are_adjacent(Type first_vertex, Type second_vertex);

    void show_graph();
};

template <typename Type>
Graph_list<Type>::Graph_list(unsigned int v_s)
{
    vertex_size = v_s;
    counter = 0;

    vertex_value = new Type[vertex_size];
    edges = new SL_List<Path>[vertex_size];
}

template <typename Type>
Graph_list<Type>::~Graph_list()
{
    delete [] vertex_value;
    delete [] edges;
}

template <typename Type>
void Graph_list<Type>::insert_vertex(Type data)
{
    vertex_value[counter] = data;
    counter++;
}

template <typename Type>
long int Graph_list<Type>::find_pos_vertex(Type data)
{
    for (unsigned int i = 0; i < vertex_size; i++)
        if (vertex_value[i] == data) return i;

    return -1;
}

template <typename Type>
void Graph_list<Type>::remove_vertex(Type data)
{
    long int pos = find_pos_vertex(data);
    if (pos != -1) {
        edges[pos].remove_all();
    }

    counter--;
}

template <typename Type>
void Graph_list<Type>::replace(Type v, Type data)
{
    long int pos = find_pos_vertex(v);
    if (pos != -1) vertex_value[pos] = data;
}

template <typename Type>
void Graph_list<Type>::insert_edge(Type first_vertex, Type second_vertex, unsigned int priority)
{
    long int pos1 = find_pos_vertex(first_vertex);
    long int pos2 = find_pos_vertex(second_vertex);
    if (pos1 != -1 && pos2 != -1) {
        Path temp;
        temp.set_value(pos2);
        temp.set_priority(priority);
        edges[pos1].push_back(temp);
        temp.set_value(pos1);            //remove if skierowany
        temp.set_priority(priority);     //remove if skierowany
        edges[pos2].push_back(temp);     //remove if skierowany
    }
}

template <typename Type>
void Graph_list<Type>::remove_edge(Type first_vertex, Type second_vertex)
{
    long int pos1 = find_pos_vertex(first_vertex);
    long int pos2 = find_pos_vertex(second_vertex);
    if (pos1 != -1 && pos2 != -1) {
        for (unsigned int i = 0; i < edges[pos1].length(); i++)
            if (edges[pos1].pop(i).get_value() == pos2) edges[pos1].remove(i);
        for (unsigned int i = 0; i < edges[pos2].length(); i++)
            if (edges[pos2].pop(i).get_value() == pos1) edges[pos2].remove(i); // remove if skierowany
    }
}

template <typename Type>
bool Graph_list<Type>::are_adjacent(Type first_vertex, Type second_vertex)
{
    long int pos1 = find_pos_vertex(first_vertex);
    long int pos2 = find_pos_vertex(second_vertex);
    if (pos1 != -1 && pos2 != -1) 
         for (unsigned int i = 0; i < edges[pos1].length(); i++)
            if (edges[pos1].pop(i).get_value() == pos2) return true;
         for (unsigned int i = 0; i < edges[pos2].length(); i++)
            if (edges[pos2].pop(i).get_value() == pos1) return true;

    return false;
}

template <typename Type>
void Graph_list<Type>::show_graph()
{
    std::cout << "\nGraf nieskierowany: \n"; 
    for (unsigned int i = 0; i < vertex_size; i++)
        for (unsigned int j = 0; j < edges[i].length(); j++) {
            if (edges[i].length() != 0 ) {
                std::cout << vertex_value[i];
                std::cout << " --- " <<  edges[i].pop(j).get_priority() << " ---> ";
                std::cout << vertex_value[edges[i].pop(j).get_value()] << std::endl;
            }
     }
            
}