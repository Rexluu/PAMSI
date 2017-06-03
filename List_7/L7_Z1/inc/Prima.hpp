struct edge //because graph algorithms are bad, too lazy to rewrite 
{
    unsigned int pos1;
    unsigned int pos2;
    unsigned int priority;
};

void prima_algorithm_matrix(Graph_matrix <variable_type> &gm)
{
     unsigned int pos = 0;
     unsigned int size = gm.get_size();

     Priority_queue <edge> q;
     Graph_matrix <variable_type> out(size);
     bool *visited = new bool[size];

     for (unsigned int i = 0; i < size; i++) {
        visited[i] = false;
        out.insert_vertex(gm.return_vertex(i));
     }

     visited[pos] = true;
     for (unsigned int i = 1; i < size; i++) { // from 1 because first position is 0 - look up
     variable_type v1 = gm.return_vertex(pos);
        for (unsigned int j = 0; j < size; j++) {
            variable_type v2 = gm.return_vertex(j);
             if (gm.are_adjacent(v1, v2)) {
                if (visited[j] == false) {
                    edge temp;
                    temp.pos1 = pos;
                    temp.pos2 = j;
                    temp.priority = gm.return_edge_priority(gm.return_vertex(temp.pos1), gm.return_vertex(temp.pos2));
                    q.push(temp.priority, temp);
                }
            }
        }

     
     while (visited[q.min().pos1] == true && visited[q.min().pos2] == true) {
       q.remove_min();
     }

     v1 = gm.return_vertex(q.min().pos1);
     variable_type v2 = gm.return_vertex(q.min().pos2);
     unsigned int priority = q.min().priority;
     out.insert_edge(v1, v2, priority);

     visited[q.min().pos2] = true;
     pos = q.min().pos2;
     }

     //out.show_graph();
     delete [] visited;

}

void prima_algorithm_list(Graph_list <variable_type> &gl)
{
     unsigned int pos = 0;
     unsigned int size = gl.get_size();

     Priority_queue <edge> q;
     Graph_list <variable_type> out(size);
     bool *visited = new bool[size];

     for (unsigned int i = 0; i < size; i++) {
        visited[i] = false;
        out.insert_vertex(gl.return_vertex(i));
     }

     visited[pos] = true;
     for (unsigned int i = 1; i < size; i++) { // from 1 because first position is 0 - look up
     variable_type v1 = gl.return_vertex(pos);
        for (unsigned int j = 0; j < size; j++) {
            variable_type v2 = gl.return_vertex(j);
             if (gl.are_adjacent(v1, v2)) {
                if (visited[j] == false) {
                    edge temp;
                    temp.pos1 = pos;
                    temp.pos2 = j;
                    temp.priority = gl.return_edge_priority(gl.return_vertex(temp.pos1), gl.return_vertex(temp.pos2));
                    q.push(temp.priority, temp);
                }
            }
        }

     
     while (visited[q.min().pos1] == true && visited[q.min().pos2] == true) {
       q.remove_min();
     }

     v1 = gl.return_vertex(q.min().pos1);
     variable_type v2 = gl.return_vertex(q.min().pos2);
     unsigned int priority = q.min().priority;
     out.insert_edge(v1, v2, priority);

     visited[q.min().pos2] = true;
     pos = q.min().pos2;
     }

     //out.show_graph();
     delete [] visited;

}