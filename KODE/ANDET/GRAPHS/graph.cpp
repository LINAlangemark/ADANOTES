#include "graph.h"
#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>
#include <iomanip>   // <-- til setw til tabellen

// ---------- Constructor ----------
Graph::Graph(int v, GraphType t, bool dir)
    : vertices(v), type(t), directed(dir) {

    if (type == GraphType::ADJACENCY_MATRIX) {
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    } else {
        adjList.resize(vertices);
    }
}

// ---------- Edge handling ----------
void Graph::addEdge(int u, int v, int weight) {
    if (type == GraphType::ADJACENCY_MATRIX)
        addEdgeMatrix(u, v, weight);
    else
        addEdgeList(u, v, weight);
}

void Graph::addEdgeMatrix(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    if (!directed)
        adjMatrix[v][u] = weight;
}

void Graph::addEdgeList(int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    if (!directed)
        adjList[v].push_back({u, weight});
}

std::vector<int> Graph::dijkstra(int start) {
    const int INF = INT_MAX;

    std::vector<int> dist(vertices, INF);
    std::vector<bool> visited(vertices, false);
    std::vector<int> parent(vertices, -1);   // <-- ny

    dist[start] = 0;

    using P = std::pair<int,int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, start});

    std::vector<std::string> labels = {
        "1","2","3","4","5","6","7","8","9","10","11","12"
    };

    const int COLW = 7;

    std::cout << "\n--- Dijkstra-tabel (start = "
              << labels[start] << ") ---\n\n";

    // header
    std::cout << std::left << std::setw(COLW) << "Step"
              << std::setw(COLW) << "U"
              << std::setw(14)    << "Permanent";

    for (int i = 0; i < vertices; ++i)
        std::cout << std::setw(COLW) << labels[i];
    std::cout << "\n";

    auto printRow = [&](int step, int u) {
        std::cout << std::left << std::setw(COLW) << step;

        if (u == -1) std::cout << std::setw(COLW) << "-";
        else         std::cout << std::setw(COLW) << labels[u];

        // S-mængden (permanente knuder)
        std::string S = "{";
        bool first = true;
        for (int i = 0; i < vertices; ++i) {
            if (visited[i]) {
                if (!first) S += ",";
                S += labels[i];
                first = false;
            }
        }
        S += "}";
        std::cout << std::setw(14) << S;

        // afstande
        for (int i = 0; i < vertices; ++i) {
            if (dist[i] == INF)
                std::cout << std::setw(COLW) << "∞";
            else
                std::cout << std::setw(COLW) << dist[i];
        }
        std::cout << "\n";
    };

    int step = 0;
    printRow(step, -1);   // initial tilstand

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        if (d > dist[u]) continue;

        visited[u] = true;
        ++step;
        printRow(step, u);

        for (auto [v, w] : adjList[u]) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;                 // <-- husk hvem der gav forbedringen
                pq.push({dist[v], v});
            }
        }
    }

    std::cout << "\nEndelige distancer fra " << labels[start] << ":\n";
    for (int i = 0; i < vertices; i++) {
        std::cout << "Node " << labels[i] << ": ";
        if (dist[i] == INF) std::cout << "ingen vej\n";
        else                std::cout << dist[i] << "\n";
    }

    std::cout << "\nKanter i shortest-path-tree:\n";
    for (int v = 0; v < vertices; ++v) {
        if (v == start || parent[v] == -1) continue;
        std::cout << labels[parent[v]] << " - " << labels[v]
                  << "  (afstand til " << labels[v]
                  << " = " << dist[v] << ")\n";
    }

    return dist;
}



// ---------- Prim ----------
std::vector<int> Graph::prim() {
    std::vector<int> key(vertices, INT_MAX);
    std::vector<bool> inMST(vertices, false);
    key[0] = 0;

    std::cout << "\n--- Prim's algoritme ---\n";

    for (int i = 0; i < vertices; i++) {
        int u = -1;
        for (int v = 0; v < vertices; v++)
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;

        inMST[u] = true;
        std::cout << "\nTilføjer node " << u 
                  << " til MST (key = " << key[u] << ")\n";

        for (auto [v, w] : adjList[u]) {
            std::cout << "  Kant " << u << " -> " << v
                      << " (vægt " << w << ")";

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                std::cout << "  => OPDATER key[" << v
                          << "] = " << w << "\n";
            } else {
                std::cout << "  => ingen ændring\n";
            }
        }
    }

    std::cout << "\nEndelige keys (MST-vægte):\n";
    for (int i = 0; i < vertices; i++)
        std::cout << "Node " << i << ": " << key[i] << "\n";

    return key;
}


// ---------- Kruskal ----------
int Graph::findSet(int x, std::vector<int>& parent) {
    if (parent[x] != x)
        parent[x] = findSet(parent[x], parent);
    return parent[x];
}

void Graph::unionSet(int a, int b, std::vector<int>& parent) {
    parent[findSet(a, parent)] = findSet(b, parent);
}

int Graph::kruskal() {
    struct Edge {
        int u, v, w;
    };

    std::vector<Edge> edges;
    for (int u = 0; u < vertices; u++)
        for (auto [v, w] : adjList[u])
            if (u < v)
                edges.push_back({u, v, w});

    std::sort(edges.begin(), edges.end(),
              [](Edge a, Edge b) { return a.w < b.w; });

    std::cout << "\n--- Kruskal's algoritme ---\n";

    std::vector<int> parent(vertices);
    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    int mstWeight = 0;

    for (auto e : edges) {
        int ru = findSet(e.u, parent);
        int rv = findSet(e.v, parent);

        std::cout << "\nTjek kant " << e.u << " - " << e.v;

        if (ru != rv) {
            unionSet(e.u, e.v, parent);
            mstWeight += e.w;
            std::cout << "  => TILFØJET til MST\n";
        } else {
            std::cout << "  => AFVIST (cyklus)\n";
        }
    }

    std::cout << "\nTotal MST-vægt = " << mstWeight << "\n";
    return mstWeight;
}


// ---------- Topologisk sortering ----------
std::vector<int> Graph::topologicalSort() {
    std::vector<int> indegree(vertices, 0);
    for (int u = 0; u < vertices; u++)
        for (auto [v, _] : adjList[u])
            indegree[v]++;

    std::queue<int> q;
    for (int i = 0; i < vertices; i++)
        if (indegree[i] == 0)
            q.push(i);

    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (auto [v, _] : adjList[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }
    return order;
}


// ---------- Constructor ----------

void Graph::print() const {
    if (type == GraphType::ADJACENCY_MATRIX) {
        std::cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    } 
    else {
        std::cout << "Adjacency List:\n";
        for (int u = 0; u < vertices; u++) {
            std::cout << u << " -> ";
            for (auto [v, w] : adjList[u]) {
                std::cout << "(" << v << ", weight=" << w << ") ";
            }
            std::cout << "\n";
        }
    }
}
