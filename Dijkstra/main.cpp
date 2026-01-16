#include "Dijkstra.h"
#include <iostream>

int main(){
    random_device rd;
    mt19937 rng(rd());

    UndirectedGraph test;
    test.randomize_edges(rng, .19, {10, 50});

    test.test_print();
    pair<Node*, Node*> start_end = test.get_start_end(rng);

    cout << "The shortest path from " << start_end.first->data << " to " << start_end.second->data << " is " << test.shortest_path(start_end.first, start_end.second) << endl;

    return 0;
}
