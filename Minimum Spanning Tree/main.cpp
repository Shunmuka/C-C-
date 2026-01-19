#include "MinimumSpanning.h"
#include <iostream>
using namespace std;

int main() {
  random_device rd;
  mt19937 rng(rd());
  
  cout << "Insert number of graph nodes: " << endl;

  int nodes;
  cin >> nodes;
  UndirectedGraph graph(nodes);
  
  cout << "Insert the density of the graph (0.0 - 1.0): " << endl;
  double prob;
  cin >> prob;

  cout << "Insert range of edge weights lower bound: " << endl;
  pair<int, int> range;
  cin >> range.first;
  cout << "Insert range of edge weigths upper bound: " << endl;
  cin >> range.second;

  graph.init_edges(rng, prob, range);
  
  cout << endl << "The initialized adjacency matrix for the graph is: " << endl;
  cout << endl << graph;
  cout << endl << endl << "The adjacency matrix of the Minimum Spanning Tree for the graph is: " << endl;
  cout << endl;
  vector<vector<int>> mst = graph.prims(0);
  graph.print_MST(mst); 

  return 0;
}
