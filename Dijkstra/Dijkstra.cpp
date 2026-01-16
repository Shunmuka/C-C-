#include <iostream>
#include "Dijkstra.h"
using namespace std;

void UndirectedGraph::init_nodes(mt19937 &rng){
	for (int i = 0; i < 50; i++){
		uniform_int_distribution<int> value(1, 300);
		graph[i].data = value(rng); 
	}
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
				int new_weight = weight(rng);
				update_edge(&graph[i], &graph[j], weight(rng));
				update_edge(&graph[j], &graph[i], weight(rng));
		}
	}
}
}

void UndirectedGraph::test_print(){
	for (int i = 0; i < 50; i++){
		cout << "Node: " << graph[i].data << endl;
		cout << "Neighbors: ";
		for (int j = 0; j < graph[i].neighbors.size(); j++){
			cout << graph[i].neighbors[j].first->data << "\t";
		}
		cout << endl;
	}
}

int main(){
	random_device rd;
	mt19937 rng(rd());

	UndirectedGraph test;
	test.randomize_edges(rng, 0.19, {10, 40});

	test.test_print();

	return 0;
}



