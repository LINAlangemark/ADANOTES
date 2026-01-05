#include <iostream>
#include "graph.h"

int main() {
    /*
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
    Graph gd(7, GraphType::ADJACENCY_LIST, true);
    */


std::cout << "----------------- Exercise 8-----------------\n";
//gd(numbr of vertices, GraphType::ADJACENCY_LIST, directed = false);
Graph gd(12, GraphType::ADJACENCY_LIST, false);

// A=0, B=1, ..., L=11
gd.addEdge(0, 1, 1306);   // 1-2
gd.addEdge(1, 2, 629);    // 2-3
gd.addEdge(2, 3, 435);    // 3-4
gd.addEdge(1, 3, 919);    // 2-4
gd.addEdge(3, 5, 1983);   // 4-6
gd.addEdge(4, 5, 1258);   // 5-6
gd.addEdge(0, 4, 2161);   // 1-5
gd.addEdge(0, 6, 2661);   // 1-7
gd.addEdge(4, 6, 1483);   // 5-7
gd.addEdge(6, 5, 1532);   // 7-6
gd.addEdge(6, 7, 661);    // 7-8
gd.addEdge(5, 8, 2113);   // 6-9
gd.addEdge(5, 9, 2161);   // 6-10
gd.addEdge(8, 9, 1709);   // 9-10
gd.addEdge(7, 8, 1145);   // 8-9
gd.addEdge(7, 11, 1613);  // 8-12
gd.addEdge(8, 11, 725);   // 9-12
gd.addEdge(8, 10, 383);   // 9-11
gd.addEdge(9, 10, 2145);  // 10-11
gd.addEdge(10, 11, 338);  // 11-12

gd.print();

std::cout << "\n----------------- DIJKSTRA FRA A -----------------\n";
gd.dijkstra(0);  // start from A (0)



    return 0;
    
}
