#include <vector>
#include <utility>
#include <random>
using namespace std;

struct Node {
	int data;
	vector<pair<Node*, int>> neighbors;
};

class UndirectedGraph {
	public:
		UndirectedGraph() : graph(50)   {}		
		void init_nodes(mt19937 &rng);
		void update_edge(Node* vertex1, Node* vertex2, const int weight);
		void randomize_edges(mt19937 &rng, const double epsilon, const pair<int, int> range);
		void test_print();
		

	private:
		vector<Node> graph;
};
