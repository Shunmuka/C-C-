#include <iostream>
#include <queue>
#include <tuple>
#include "MinimumSpanning.h"
using namespace std;

void UndirectedGraph::init_edges(std::mt19937 &rng, double epsilon, const pair<int, int> &range) {
  uniform_int_distribution<int> weight(range.first, range.second);
  uniform_real_distribution<double> prob(0.0, 1.0);
  for (int i = 0; i < vertices; i++){
    for (int j = i + 1; j < vertices; j++){
      if (prob(rng) < epsilon){
        adjMatrix[i][j] = adjMatrix[j][i] = weight(rng);
      }
    }
  }
}

vector<vector<int>> UndirectedGraph::prims(int start) {
  vector<vector<int>> mst(vertices, vector<int>(vertices, 0));
  priority_queue<tuple<int, int, int>> minHeap;
  vector<int> visited(vertices, 0);
  int size = 0;
  
  //initialize minHeap with start node neighbors
  for (int i = 0; i < vertices; i++){
    if (adjMatrix[start][i] != 0)
      minHeap.push(make_tuple(-adjMatrix[start][i], start, i));
  }
  
  int new_start, next_node, edge_weight;
  //check loop terminating conditions (closed set == vertices or if graph unconnected when minHeap is empty)
  while ((size < vertices - 1) && (!minHeap.empty())){
    new_start = get<1>(minHeap.top());
    next_node = get<2>(minHeap.top());
    edge_weight = get<0>(minHeap.top());
    minHeap.pop();
   
   //only add if node has not already been added to mst
   if (visited[next_node] == 0){
     mst[new_start][next_node] = mst[next_node][new_start] = -edge_weight;
     size++;
    //add new neighbors to heap
     for (int i = 0; i < vertices; i++){
       if (adjMatrix[next_node][i] != 0)
        minHeap.push(make_tuple(-(adjMatrix[next_node][i]), next_node, i));
     }
    visited[next_node] = 1;
   }
  }
  return mst;
}

void UndirectedGraph::print_MST(const vector<vector<int>> &mst){
  for (const auto &row : mst){
    for (const auto &element : row)
      cout << element << " ";
    cout << endl;
  }
}

ostream& operator<<(ostream &out, const UndirectedGraph &graph) {
  for (auto i = graph.adjMatrix.begin(); i != graph.adjMatrix.end(); i++){
    for (auto j = i->begin(); j != i->end(); j++){
      out << *j << " ";
    }
    out << endl;
  } 
  return out;
}




