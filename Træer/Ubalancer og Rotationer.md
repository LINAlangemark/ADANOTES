x
**AVL-træer kan være ubalancerede**
![[Pasted image 20251215093928.png]]

![[Pasted image 20251215093842.png]]
**Ubalance --> Rotation**
![[Pasted image 20251215141959.png]]

![[Pasted image 20251215142016.png]]
insertion af 4 og 5 --> nu er der uligvægt på rodens højre-side, da venstre-siden har højden 1 og venstre siden har højden 3, hvilket giver balance-faktor: 1-3=-2
en rotation på højresien skaber ligevægt igen.

![[Pasted image 20251215143811.png]]


**Single Rotations** [træets yderside]
Bruges til at fikse ubalancer i AVL-træer når:
	problem-noden er tung i samme retning som sit tunge barn
	Rotationen flytter: det tunge barn opad, og den ubalancerede node ned

Dette har til formål at reducere højden på den tunge side, samtidigt med at vi bevare bst ordenen: (X < k1 < Y < k2 < Z)

Vægten er uligeligt fordelt --> single rotation så k1 bliver parent til k2 som nu har børnene: y og z

**LL-tilfælde:** k2 er ubalanceret, venstre subtræ er for øjt --> indsættelsen er sket i venstre barns undertræ.
**Handling:** Der udføres en højre-rotation omkring k2
**Efter rotation:** k1 bliver den nye rod, k2 bliver højre barn, deltræerne X, Y og Z bevare deres rækkefølge.
![[Pasted image 20251215141809.png]]
**RR-tilfælde:** k1 er ubalnceret, højre subtræ er for højy --> indsættelsen er sket i højre barns undertræ
**Handling:** udfør en venstre-rotation omkring k1
**Efter rotation:** k2 bliver ny rod, k1 bliver venstre barn, BST ordene bevares.


![[Pasted image 20251215141952.png]]

**Double Rotatoins** [træets inderside]
Bruges når problem-noden er tung i én retning, men indsættelsen skete i modsatte retning i barnets subtræ
En double rotation er 2 single rotations i træk

**LR-double rotation tilfældet:** k3 er venstre tung, men venstre barn k1 er højre tung
**Handlinger:**  (1) venstre rotation på k1, (2) højre rotation på k3
**Resultat:** k2 bliver ny rod, træet bliver balanceret, BST-ordenen bevares [rækkefølgen af A, B, C og D]
![[Pasted image 20251215142225.png]]
**RL-double rotation tilfældet:** k1 er højre ting, men højre barn k3 er venstre tung
**Handlinger:** (1) højre rotation på k3, (2) venste rotation på k1
**Resultat:**  k2 bliver ny rod, træet bliver balanceret, og BST-ordenen bevares
(rækkefølgen af A, B, C og D ændres ikke)


![[Pasted image 20251215143655.png]]

sletning og ubalancer?
