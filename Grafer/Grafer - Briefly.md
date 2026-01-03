## Typer af grafer

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

---
## **Minimum Spanning Tree (MST)**
- Forbinder alle noder
- Ingen cykler
- Minimum samlet vægt
- Har altid V − 1 kanter

**Eksempel på MST fra bogen**
![[Pasted image 20251220083821.png]]

Find MST med: [[Prims Algorithm]] [[Kruskal's Algorithm]]

![[Pasted image 20251220095148.png]]
