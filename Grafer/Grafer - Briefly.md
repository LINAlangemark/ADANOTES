**GRAPH ALGORITHMS: GUIDE:**
![[Pasted image 20251220093743.png]]
**TYPER AF GRAFER-----------------------------------------------------------------------------------------------------------**

 ***Rettet graf (Directed Graph)***
	- Kanter har en retning: `u → v`
	- `(u, v)` betyder kun fra u til v
	- Eksempel: workflows, afhængigheder, veje med ensretning

***Urettet graf (Undirected Graph)***
	- Kanter har ingen retning
	- `(u, v)` betyder både `u ↔ v`
	- Eksempel: netværk, kabler, broer

***Vægtet graf***
	- Kanter har en vægt (fx afstand, pris, tid)
	- Bruges i Dijkstra, Prim, Kruskal

 ***Uvægtet graf***
	- Alle kanter har samme vægt (ofte 1)
	- Bruges i BFS til shortest path

**Repræsentation af grafer**
	Adjacency List:
		- Hver node har en liste af naboer
		- Hukommelse: O(V + E)
		- Hurtig til traversal og sparsomme grafer
	Adjacency Matrix:
		- 2D-matrix `V x V`
		- Hukommelse: O(V²)
		- Hurtig kant-opslag (`O(1)`)

**Eksempel i CPP**
![[Pasted image 20251220092159.png]]	
![[Pasted image 20251220091445.png]]
**Hvis grafen er "directed":**  tilføjes kanten KUN fra u->v
**Hvis grafen er "undirected":**  tilføjes kanten fra u->v OG fra v->u
![[Pasted image 20251220091728.png]]


**Minimum Spanning Tree (MST)**
- Forbinder alle noder
- Ingen cykler
- Minimum samlet vægt
- Har altid V − 1 kanter

**Eksempel på MST fra bogen**
![[Pasted image 20251220083821.png]]

Find MST med: [[Prims Algorithm]] [[Kruskal's Algorithm]]
![[Pasted image 20251220095148.png]]
# Graph Traversal

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

**Shortest Path**
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