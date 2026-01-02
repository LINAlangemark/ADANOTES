**Formål:**
Prim’s algoritme finder et Minimum Spanning Tree (MST) i en urettet, vægtet og sammenhængende graf. [[Grafer - Briefly]]

**Kompleksitet:**
- Simpel implementering: **O(V²)**
- Med priority queue: **O(E log V)**

**Andet:**
* Prim virker kun på urettede grafer
* Algoritmen er greedy
* d_v repræsenterer bedste kant ind i MST
* p_v bruges til at rekonstruere MST
* Starter i én vilkårlig node (samme MST-vægt uanset start)

**Initial Configuration table used in Prim's Algorithm**
![[Pasted image 20251220083920.png]]
	*v:*  Den aktuelle node (vertex)
	*known:*
		- `T` (true): noden er allerede en del af MST
		- `F` (false): noden er endnu ikke valgt
	*d_v:* Den mindste kendte vægt på en kant, der forbinder noden til MST
		Initialiseres til:
			0 for startnoden
			∞ for alle andre
	*p_v:* Parent-node i MST
		Angiver hvilken kant der forbinder noden til MST

**Prim’s algoritme – trin for trin**
	Algoritmen gentager følgende trin:
	1. Vælg den ukendte node med laveste d_v
	2. Marker noden som known
	3. Opdater alle naboer:
		Hvis kanten er billigere end deres nuværende d_v
		Opdater:
			d_v
			p_v

***Prim's Algortihm at each Stage***
![[Pasted image 20251220083844.png]]
![[PrimsAlgorithmTables.png]]
# Resultat: Minimum Spanning Tree
MST består af kanterne givet af `p_v`:
- v₁ – v₄
- v₁ – v₂
- v₄ – v₃
- v₄ – v₇
- v₇ – v₆
- v₇ – v₅