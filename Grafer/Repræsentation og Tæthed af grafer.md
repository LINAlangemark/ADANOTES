## **Repræsentation af grafer**
	Adjacency List:
		- Hver node har en liste af naboer
		- Hukommelse: O(V + E)
		- Hurtig til traversal og sparsomme grafer
	Adjacency Matrix:
		- 2D-matrix `V x V`
		- Hukommelse: O(V²)
		- Hurtig kant-opslag (`O(1)`)

---
**Eksempel i CPP**
![[Pasted image 20251220092159.png]]	
![[Pasted image 20251220091445.png]]
**Hvis grafen er "directed":**  tilføjes kanten KUN fra u->v
**Hvis grafen er "undirected":**  tilføjes kanten fra u->v OG fra v->u
![[Pasted image 20251220091728.png]]

---
## Tæthed (Grafer)
handler om: hvor mange kanter en graf har, sammenlignet med hvor mange den kunne have haft.
	*Tæthed = hvor fyldt grafen er med kanter.*

En graf er:
- **tæt (dense)** → har _mange_ kanter
- **tynd/sparsom (sparse)** → har _få_ kanter i forhold til muligt

Tæthed ligger altid mellem **0 og 1**.
##### **Eksempler**
Lad n = antal noder  
og m = antal kanter.

**Urettet graf (ingen dobbeltrettede kanter)**
	Maksimalt antal mulige kanter: n(n−1)/2​
	Tæthed: density=2m/n(n−1)

**Rettet graf (directed)**
	Maksimalt antal mulige kanter: n(n−1)
	Tæthed: density=m/n(n−1)

---
***Tæthed påvirker valg af datastruktur og algoritmer:***

**Sparsom graf**
- få kanter → m≈n
- bedst at bruge **adjacency list**
- mange graf-algoritmer bliver hurtigere

**Tæt graf**
- mange kanter → m≈n^2
- **adjacency matrix** kan være bedre
- nogle algoritmer bliver dyrere pga mange kanter


