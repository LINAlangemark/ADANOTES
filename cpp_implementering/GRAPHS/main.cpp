#include <iostream>
#include "graph.h"

int main() {
    std::cout<<"----------------- ADJACENCY LIST GRAPH -----------------"<<std::endl;
    Graph gl(5, GraphType::ADJACENCY_LIST, true);

    gl.addEdge(0, 1);
    gl.addEdge(0, 2);
    gl.addEdge(1, 3);
    gl.addEdge(2, 3);
    gl.print();

    std::cout<<"----------------- ADJACENCY MATRIX GRAPH -----------------"<<std::endl;
    Graph gm(5, GraphType::ADJACENCY_MATRIX, true);

    gm.addEdge(0, 1);
    gm.addEdge(0, 2);
    gm.addEdge(1, 3);
    gm.addEdge(2, 3);

    gm.print();

    std::cout<<"----------------- TOPOLOGICAL SORT -----------------"<<std::endl;
    auto topo = gl.topologicalSort();
    for (int v : topo)
        std::cout << v << " ";
    std::cout<<"\n"<<std::endl;

    std::cout << "----------------- GRAPH FROM P2: EXERCISE 5 -----------------\n";

    Graph g(12, GraphType::ADJACENCY_LIST, false);

    // Øverste række
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 8);
    g.addEdge(2, 3, 14);
    g.addEdge(0, 2, 6);

    // Lodrette
    g.addEdge(0, 4, 1);
    g.addEdge(4, 8, 7);

    g.addEdge(3, 7, 1);
    g.addEdge(7, 11, 3);

    // Midten
    g.addEdge(0, 5, 2);
    g.addEdge(2, 5, 3);
    g.addEdge(5, 6, 20);
    g.addEdge(6, 3, 1);

    // Nederste række
    g.addEdge(8, 9, 4);
    g.addEdge(9, 10, 2);
    g.addEdge(10, 11, 5);

    // Diagonaler
    g.addEdge(8, 5, 3);
    g.addEdge(5, 9, 5);
    g.addEdge(5, 10, 8);
    g.addEdge(6, 10, 8);
    g.addEdge(6, 11, 4);

    g.print();

    std::cout << "\n----------------- DIJKSTRA (start = 0) -----------------\n";
    g.dijkstra(0);

    std::cout << "\n----------------- PRIM -----------------\n";
    g.prim();

    std::cout << "\n----------------- KRUSKAL -----------------\n";
    g.kruskal();

    std::cout << "----------------- ØVELSE 6: DIRECTED GRAPH -----------------\n";

    // 7 noder: A=0, B=1, C=2, D=3, E=4, F=5, G=6
    Graph gd(7, GraphType::ADJACENCY_LIST, true);

    // A
    gd.addEdge(0, 1, 5);  // A -> B
    gd.addEdge(0, 2, 3);  // A -> C

    // B
    gd.addEdge(1, 6, 1);  // B -> G
    gd.addEdge(1, 2, 2);  // B -> C
    gd.addEdge(1, 4, 3);  // B -> E

    // C
    gd.addEdge(2, 3, 7);  // C -> D
    gd.addEdge(2, 4, 7);  // C -> E

    // D
    gd.addEdge(3, 0, 2);  // D -> A
    gd.addEdge(3, 4, 2);  // D -> E
    gd.addEdge(3, 5, 6);  // D -> F

    // G
    gd.addEdge(6, 4, 1);  // G -> E

    // E
    gd.addEdge(4, 5, 1);  // E -> F

    // Print grafen
    gd.print();

    std::cout << "\n----------------- DIJKSTRA FRA A -----------------\n";
    gd.dijkstra(0);  // Start fra A


    return 0;
    
}
