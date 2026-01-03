
**Breadth-First Search (BFS)**
- Traverserer niveau for niveau
- Bruges til:
    - Unweighted shortest path
- Tidskompleksitet: O(V + E)

**Depth-First Search (DFS)**
- Går så dybt som muligt før backtracking
- Bruges til:
    - Cyklusdetektion
    - Sammenhængende komponenter
    - Topologisk sortering
- Tidskompleksitet: O(V + E)

**Shortest Path** [[Djikstra's algorithm]]

• *Unweighted shortest path*
	- Algoritme: BFS
	- Kompleksitet: O(V + E)
	
*• Weighted shortest path (Ingen negative kanter)*
	- Algoritme: Dijkstra
	- Data struktur: Priority Queue
	- Kompleksitet: O(E log V)
	
• *Weighted shortest path (med negative kanter)
	- Algoritme: Bellman-Ford
	- Kompleksitet: O(V · E)
	- Kan detektere negative cykler

*• Weighted acyclic graph (DAG)*
	- Algoritme: Topologisk sortering + relaxation
	- Kompleksitet: O(V + E)

**Topologisk sortering**
- Kun for DAGs (Directed Acyclic Graphs)
- Giver en rækkefølge hvor:
    - `u → v` ⇒ `u` kommer før `v`
- Bruges til:
    - Opgaveplanlægning
    - Afhængigheder

**NP-completeness **
- NP-complete problemer:
    - Ingen kendt hurtig løsning
    - Let at verificere, svært at løse
- Eksempler i grafer:
    - Hamiltonian Path
    - Traveling Salesman Problem (TSP)

**GRAPH ALGORITHMS: GUIDE:**
![[Pasted image 20251220093743.png]]