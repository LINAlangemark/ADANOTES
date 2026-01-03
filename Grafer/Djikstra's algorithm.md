Finder korteste vej fra en startnode s  til alle andre noder i en vægtet graf  
	(så længe alle kanter har ikke-negative vægte).

Du må bruge algoritmen, når:
- grafen er vægtet
- kanterne har ikke-negative vægte
- du vil have korteste vej fra én kilde (single-source)
Du må ikke bruge den hvis der findes negative kanter → brug i stedet Bellman-Ford.
	(vi har ikke haft om Bellman-Ford)

---
**Ideen**
Sæt alle afstande til ∞ (ukendte)  
Sæt startnoden til afstand 0  
Gentag:
- vælg den ukendte node med mindst afstand
- “frys” den (markér `known = true`)
- prøv at forbedre (relax) dens naboers afstande

*Når en node bliver `known`,  er dens korteste afstand endeligt korrekt.*

---
**Datastruktur**
```
known   → er den færdigbehandlet?
dist    → bedste afstand fundet indtil nu
path    → hvilken forgænger leder til korteste vej?
adj     → liste af naboer (adjacency list)

```


`path` peger på den forrige node på den korteste rute.

For at udskrive ruten:
- følg `path` baglæns fra destinationen til start
- vend listen bagefter

---
**Pseudokode**
![[Pasted image 20260102122644.png]]
![[Pasted image 20260102122655.png]]

---
**Tidskompleksitet**
![[Pasted image 20260103155930.png]]
*I praksis bruges priority queue*
