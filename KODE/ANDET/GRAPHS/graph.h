#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>

enum class GraphType {
    ADJACENCY_MATRIX,
    ADJACENCY_LIST
};

class Graph {
private:
    int vertices;
    bool directed;
    GraphType type;

    // Repræsentationer
    std::vector<std::vector<int>> adjMatrix;
    std::vector<std::vector<std::pair<int,int>>> adjList;

    // Hjælpere
    void addEdgeMatrix(int u, int v, int weight);
    void addEdgeList(int u, int v, int weight);

    int findSet(int x, std::vector<int>& parent);
    void unionSet(int a, int b, std::vector<int>& parent);


public:
    Graph(int vertices, GraphType type, bool directed = false);

    void addEdge(int u, int v, int weight = 1);

    // Algoritmer
    std::vector<int> dijkstra(int start);
    std::vector<int> prim();
    int kruskal();
    std::vector<int> topologicalSort();

    //Deugging
    void print() const;

};

#endif
