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
        //Graph initialization functions
		UndirectedGraph() : graph(50)   {}
		void init_nodes(mt19937 &rng);
		void update_edge(Node* vertex1, Node* vertex2, const int weight);
		void randomize_edges(mt19937 &rng, const double epsilon, const pair<int, int> range);
		void test_print();
        pair<Node*, Node*> get_start_end(mt19937 &rng);

        //Graph traversal / finding shortest path
        int shortest_path(Node* start, Node* end);
        int open_set_min(vector<pair<Node*, int>> &open_set, const size_t size);
        bool in_closed(Node* node, vector<pair<Node*, int>> &closed, const size_t size);
	private:
		vector<Node> graph;
};
