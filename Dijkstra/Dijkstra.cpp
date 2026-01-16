#include <iostream>
#include <limits>
#include "Dijkstra.h"
using namespace std;

void UndirectedGraph::init_nodes(mt19937 &rng){
	for (int i = 0; i < 50; i++){
		uniform_int_distribution<int> value(1, 300);
		graph[i].data = value(rng); 
	}
}

pair<Node*, Node*> UndirectedGraph::get_start_end(mt19937 &rng) {
    uniform_int_distribution<int> node(0, 49);
    return {&graph[node(rng)], &graph[node(rng)]};
}

void UndirectedGraph::update_edge(Node* vertex1, Node* vertex2, int weight){
	vertex1->neighbors.push_back({vertex2, weight});
	vertex2->neighbors.push_back({vertex1, weight});
}

void UndirectedGraph::randomize_edges(mt19937 &rng, const double epsilon, const pair<int, int> range){
	init_nodes(rng);
	for (int i = 0; i < 50; i ++){
		for (int j = i + 1; j < 50; j++){
			uniform_real_distribution<double> coin(0, 1);
			double probability = coin(rng);
			if (probability < epsilon){
				uniform_int_distribution<int> weight(range.first, range.second);
				update_edge(&graph[i], &graph[j], weight(rng));
		}
	}
}
}

void UndirectedGraph::test_print(){
	for (int i = 0; i < 50; i++){
		cout << "Node: " << graph[i].data << endl;
		cout << "Neighbors: ";
		for (int j = 0; j < graph[i].neighbors.size(); j++){
			cout << graph[i].neighbors[j].first->data << ": " << graph[i].neighbors[j].second << "\t";
		}
		cout << endl;
	}
}

int UndirectedGraph::open_set_min(vector<pair<Node *, int>> &open_set, const size_t size) {
    int min_weight = numeric_limits<int>::max(), min_index = 0;
    for (int i = 0; i < size; i++){
        if (open_set[i].second < min_weight){
            min_index = i;
            min_weight = open_set[i].second;
        }
    }

    return min_index;
}

bool UndirectedGraph::in_closed(Node *node, vector<pair<Node *, int>> &closed, const size_t size) {
    for(int i = 0; i < size; i++){
        if (node == closed[i].first){
            return true;
        }
    }

    return false;
}

int UndirectedGraph::shortest_path(Node *start, Node *end) {
    vector<pair<Node *, int>> closed, open;
    closed.push_back({start, 0});
    int weight = 0;

    for (int i = 0; i < start->neighbors.size(); i++) {
        start->neighbors[i].second += weight;
        open.push_back(start->neighbors[i]);
    }

    int index = 0;
    while (!in_closed(end, closed, closed.size())) {
        index = open_set_min(open, open.size());
        start = open[index].first;
        weight = open[index].second;
        closed.push_back(open[index]);
        open.erase(open.begin() + index);

        for (int i = 0; i < start->neighbors.size(); i++) {
            if (!in_closed(start->neighbors[i].first, closed, closed.size())) {
                open.push_back({start->neighbors[i].first, start->neighbors[i].second + weight});
            }
        }
    }

    for (int i = 0; i < closed.size(); i++) {
        if (end == closed[i].first) {
            return closed[i].second;
        }
    }
    return -1;
}




