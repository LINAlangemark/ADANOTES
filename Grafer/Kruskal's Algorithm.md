**Formål:** Kruskal’s algoritme finder et Minimum Spanning Tree (MST) i en urettet, vægtet graf.
[[Grafer - Briefly]]

**Grundidé (intuition):**
* Betragt alle kanter sorteret efter vægt
* Start med ingen kanter
* Tilføj den billigste kant:
	* kun hvis den ikke skaber en cyklus
* Gentag indtil MST er komplet
* Kruskal er en greedy algoritme.

**Kruskal bruger:**
- Sortering / priority queue → vælg billigste kant
- Union-Find (Disjoint Sets) → cyklusdetektion

**Union-Find funktioner:**
- `find(x)` → finder repræsentanten for x
- `union(x, y)` → forbinder to komponenter

**Kompleksitet:**
	Sortering af kanter: O(E log E)
	Union-Find operationer: næsten O(1)
	Samlet: O(E log E)

**Andet:**
	Kruskal virker kun på urettede grafer
	Algoritmen er greedy
	Union-Find bruges til cyklusdetektion
	Resultatet er altid et MST (hvis grafen er sammenhængende)

**Kruskals Algorithm: Trin for Trin**
![[Pasted image 20251220094855.png]]
---

**Kruskal's Algorithm at each stage**
![[Pasted image 20251220084749.png]]
	- Algoritmen starter med **alle noder isoleret**
	- Hver accepteret kant forbinder komponenter
	- Afviste kanter forbinder allerede forbundne komponenter
	- Når **V − 1 kanter** er valgt → MST færdig

**Kruskal stopper når:**  MST indeholder **V − 1 kanter**

**Pseudocode for Kruskal's Algorithm**
![[Pasted image 20251220084823.png]]
**FORKLARING:**
1. Opret disjoint sets (én per node)
2. Sortér alle kanter efter vægt
3. While MST ikke er færdig:
   a. Tag billigste kant
   b. Hvis endepunkterne er i forskellige sets:
      - Accepter kanten
      - Union deres sets
4. Returnér MST
