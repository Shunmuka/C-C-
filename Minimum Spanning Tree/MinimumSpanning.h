#include <vector>
#include <random>
#include <utility>

class UndirectedGraph {
    public:
      UndirectedGraph(int V) : vertices(V), adjMatrix(V, std::vector<int>(V, 0)) {}
      void init_edges(std::mt19937 &rng, double epsilon,  const std::pair<int, int> &range);
      std::vector<std::vector<int>> prims(int start);

      friend std::ostream& operator<<(std::ostream &out, const UndirectedGraph &graph);
      void print_MST(const std::vector<std::vector<int>> &mst);

    private:
      int vertices;
      std::vector<std::vector<int>> adjMatrix;

};