struct edge_help //because graph algorithms are bad, too lazy to rewrite 
{
    variable_type v1;
    variable_type v2;
    unsigned int priority;
};

void kruskal_algorithm_matrix(Graph_matrix <variable_type> &gm)
{
    SL_List <edge_help> outsider; //for special rare cases
    Priority_queue <edge_help> q;
    Graph_matrix <variable_type> out(gm.get_size());
    unsigned int counter = 0;

    for (unsigned int i = 0; i < gm.get_size(); i++) {
        variable_type first = gm.return_vertex(i);
        for (unsigned int j = 0; j < gm.get_size(); j++) {
            variable_type second = gm.return_vertex(j);
            long int priority = gm.return_edge_priority(first, second); //return -1 if first not connected with second
            if (priority != -1) {
                edge_help temp;
                temp.v1 = first;
                temp.v2 = second;
                temp.priority = priority;
                q.push(priority, temp);
            }
        }
    }

    unsigned int size_q = q.length();

    for (unsigned int i = 0; i < size_q; i++){
        variable_type temp1 = q.min().v1;
        variable_type temp2 = q.min().v2;
        bool status_temp1 = out.exist(temp1);
        bool status_temp2 = out.exist(temp2);
        if (status_temp1 == false)
            out.insert_vertex(temp1);
        if (status_temp2 == false)
            out.insert_vertex(temp2);
        if (status_temp1 == false && status_temp2 == false){
                edge_help temp;
                temp.v1 = temp1;
                temp.v2 = temp2;
                counter++;
                temp.priority = counter; // just using the same struct, but here it isint priority - family number
                outsider.push_back(temp);
                out.insert_edge(temp1, temp2, q.min().priority);
        }
        if ((status_temp1 == false && status_temp2 == true) || (status_temp1 == true && status_temp2 == false)) {
            unsigned int length = outsider.length();
            for (unsigned int i = 1; i <=length; i++)
                if (outsider.pop(i).v1 == temp1 || outsider.pop(i).v1 == temp2 || outsider.pop(i).v2 == temp1 || outsider.pop(i).v2 == temp2) {
                    edge_help temp;
                    temp.v1 = temp1;
                    temp.v2 = temp2;
                    temp.priority = outsider.pop(i).priority; // just using the same struct, but here it isint priority
                    outsider.push_back(temp);
                    out.insert_edge(temp1, temp2, q.min().priority);
                    break;
                }
        }
        if (status_temp1 == true && status_temp2 == true) {
            unsigned int family1;
            unsigned int family2;
            for (unsigned int i = 1; i <= outsider.length(); i++)
                if (outsider.pop(i).v1 == temp1 || outsider.pop(i).v2 == temp1)
                    family1 = outsider.pop(i).priority;
            for (unsigned int i = 1; i <= outsider.length(); i++)
                if (outsider.pop(i).v1 == temp2 || outsider.pop(i).v2 == temp2)
                    family2 = outsider.pop(i).priority;

            if (family1 != family2)
            {
                out.insert_edge(temp1, temp2, q.min().priority);
                unsigned int length = outsider.length();
                for (unsigned int i = 1; i <= length; i++)
                    if (outsider.pop(i).priority == family1 || outsider.pop(i).priority == family2) {
                        edge_help temp;
                        temp.v1 = outsider.pop(i).v1;
                        temp.v2 = outsider.pop(i).v2;
                        temp.priority = 0;
                        outsider.remove(i); //important queue
                        outsider.push(i,temp); //important queue
                    }
            }
        }
        q.remove_min();
    }

    //out.show_graph();
}

//////////////////////////////////////////////////////////
//////////////// KRUSKAL FOR LIST ///////////////////////
//////////////////////////////////////////////////////////


void kruskal_algorithm_list(Graph_list <variable_type> &gl)
{
    SL_List <edge_help> outsider; //for special rare cases
    Priority_queue <edge_help> q;
    Graph_list <variable_type> out(gl.get_size());
    unsigned int counter = 0;

    for (unsigned int i = 0; i < gl.get_size(); i++) {
        variable_type first = gl.return_vertex(i);
        for (unsigned int j = 0; j < gl.get_size(); j++) {
            variable_type second = gl.return_vertex(j);
            long int priority = gl.return_edge_priority(first, second); //return -1 if first not connected with second
            if (priority != -1) {
                edge_help temp;
                temp.v1 = first;
                temp.v2 = second;
                temp.priority = priority;
                q.push(priority, temp);
            }
        }
    }

    unsigned int size_q = q.length();

    for (unsigned int i = 0; i < size_q; i++){
        variable_type temp1 = q.min().v1;
        variable_type temp2 = q.min().v2;
        bool status_temp1 = out.exist(temp1);
        bool status_temp2 = out.exist(temp2);
        if (status_temp1 == false)
            out.insert_vertex(temp1);
        if (status_temp2 == false)
            out.insert_vertex(temp2);
        if (status_temp1 == false && status_temp2 == false){
                edge_help temp;
                temp.v1 = temp1;
                temp.v2 = temp2;
                counter++;
                temp.priority = counter; // just using the same struct, but here it isint priority
                outsider.push_back(temp);
                out.insert_edge(temp1, temp2, q.min().priority);
        }
        if ((status_temp1 == false && status_temp2 == true) || (status_temp1 == true && status_temp2 == false)) {
            for (unsigned int i = 1; i <= outsider.length(); i++)
                if (outsider.pop(i).v1 == temp1 || outsider.pop(i).v2 == temp2 || outsider.pop(i).v1 == temp2 || outsider.pop(i).v2 == temp1) {
                    edge_help temp;
                    temp.v1 = temp1;
                    temp.v2 = temp2;
                    temp.priority = outsider.pop(i).priority; // just using the same struct, but here it isint priority
                    outsider.push_back(temp);
                    out.insert_edge(temp1, temp2, temp.priority);
                    break;
                }
        }
        if (status_temp1 == true && status_temp2 == true) {
            unsigned int family1;
            unsigned int family2;
            for (unsigned int i = 1; i <= outsider.length(); i++)
                if (outsider.pop(i).v1 == temp1 || outsider.pop(i).v2 == temp1)
                    family1 = outsider.pop(i).priority;
            for (unsigned int i = 1; i <= outsider.length(); i++)
                if (outsider.pop(i).v1 == temp2 || outsider.pop(i).v2 == temp2)
                    family2 = outsider.pop(i).priority;

            if (family1 != family2)
            {
                out.insert_edge(temp1, temp2, q.min().priority);
                unsigned int length = outsider.length();
                for (unsigned int i = 1; i <= length; i++)
                    if (outsider.pop(i).priority == family1 || outsider.pop(i).priority == family2) {
                        edge_help temp;
                        temp.v1 = outsider.pop(i).v1;
                        temp.v2 = outsider.pop(i).v2;
                        temp.priority = 0;
                        outsider.remove(i); //important queue
                        outsider.push(i,temp); //important queue
                    }
            }
        }
        q.remove_min();
    }

    //out.show_graph();
}