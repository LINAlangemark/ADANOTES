#include "P2E.h"
#include "hashMap.h"

#include <stdio.h>
#include <string.h>
#include <vector>
#include <cmath>

P2E::P2E(){
    std::cout<<"P2 works"<<std::endl;
  
}

std::string P2E::findMostFrequentWord(std::string text) {
    std::vector<char> buffer(text.begin(), text.end());
    buffer.push_back('\0');  // Ensure it's null-terminated
    
    int tb_size = buffer.size();
    //std::cout<<"tb_size: " << tb_size; 
    tb_size = 211; //fixed prime?
    HashMap hm(tb_size);

    
    //split words by these delimeters
    char del[] = " ,."; 
    char* t = strtok(buffer.data(), del); 
    
    //create hashmap of each word
    while (t != nullptr) {
        //std::cout << "\"" << t << "\" ";
        hm.insert(t); 
        t = strtok(nullptr, del);
    }
    
    //find most frequent word by the largest chain in hashmap
    std::string word = hm.findMostFrequent();
    int count = hm.getCount(word);
    std::cout<< "Most frequent word: "<< word << ", with count: "<< count<<std::endl;
    return word;
}


// Function to construct and print the MST
void  P2E::primMST(const std::vector<std::vector<int>> graph) {
    int v = graph.size();
  
    //stores which vertex accesed v
    std::vector<int> parent(v);

    //weight of smallest edge from v to growing MST
    std::vector<int> dist(v); 

    //tracks vertices that are includd in MST
    std::vector<bool> known(v);
    
    //min-heap priority queue
    std::priority_queue<std::pair<int, int>, // (weight, vertex) -- en priority queue kan kun sortere på først element så vægt er først
                        std::vector<std::pair<int, int>>, //container
                        std::greater<std::pair<int, int>>> pq; //det skal være min-heap ikke default max-heap
  
    std::vector<int> order; // <-- rækkefølgen noder vælges i
    // Initialization
    for (int i = 0; i < v; i++) {
        dist[i] = INFINITY;
        known[i] = false; //from cmath
        parent[i] = -1;
    }

    //assign first vertex as 0, so it is picked as the first vertex.
    dist[0] = 0;

    // Push the source vertex to the min-heap
    pq.push({0, 0}); 

    while (!pq.empty()) {
        int node = pq.top().second; //vertex/node
        pq.pop();
        if (known[node]){
            continue;   // IGNORÉR duplikater i PQ
        }
        known[node] = true;
        order.push_back(node);       // <-- RIGTIG rækkefølge
        for (int i = 0; i < v; i++) {
            if (!known[i] && graph[node][i] != 0 && //hvis den ikke er kendt, og hvis der er en edge mellem vertices
                graph[node][i] < dist[i]) //og hvis distancen er mindre end foregående
            {
                dist[i] = graph[node][i];
                parent[i] = node;
                pq.push({dist[i], i});  //push ny node til top of pq
            }
        }
    }

     
    
    // Print besøgsrækkefølge
    std::cout << "Prim order: ";
    for (int x : order){
         std::cout << x << " ";
    }
    std::cout << "\n";
    
    // Print the edges and their
    // weights in the MST
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < v; i++) {
        std::cout << parent[i] << " - " << i 
          << " \t" << graph[i][parent[i]] << " \n";
    }
}

void P2E::printState(int step,
                const std::vector<int>& dist,
                const std::vector<bool>& known,
                const std::vector<int>& prev)
{
    char names[] = {'A','B','C','D','E','F','G'};

    std::cout << "\n--- Step " << step << " ---\n";
    std::cout << "v   known   d_v   p_v\n";

    for (int i = 0; i < dist.size(); i++) {
        std::cout << names[i] << "   "
                  << (known[i] ? "true " : "false") << "   ";

        if (dist[i] == INFINITY) std::cout << "inf   ";
        else std::cout << dist[i] << "     ";

        if (prev[i] == -1) std::cout << "0";
        else std::cout << names[prev[i]];

        std::cout << "\n";
    }
}

void P2E::djikstra(const std::vector<std::vector<int>> adj)
{
    int n = adj.size();
    std::vector<int> dist(n, INFINITY);
    std::vector<bool> known(n, false);
    std::vector<int> prev(n, -1);

    dist[0] = 0; // Start i A

    int step = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        // Find ukendt node med laveste distance
        for (int v = 0; v < n; v++) {
            if (!known[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }

        if (u == -1 || dist[u] == INFINITY) break;

        known[u] = true;

        // Opdater naboerne
        for (int v = 0; v < n; v++) {
            int weight = adj[u][v];
            if (weight > 0 && !known[v]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                }
            }
        }

        //PRINT mellemkonfiguration efter hver iteration
        //printState(++step, dist, known, prev);
    }

    //Print slutkonfiguration
    printState(step, dist, known, prev);
}
