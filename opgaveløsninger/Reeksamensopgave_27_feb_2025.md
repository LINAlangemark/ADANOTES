## Opgave 1 (8 %)
```cpp
int Trial::sumOfDigits(int integer){
	if(!integer){
		return 0;
	}
		int digit = integer % 10;
		integer/=10;
	return digit + sumOfDigits(integer);
}
```
---
## Opgave 2 (12 %)
![[Pasted image 20260104135248.png]]
***Tidskompleksitetsovervejelser***
Yderste løkke: O(log N) [halvering af problemet]
Midterste løkke: O(N)
Inderste løkke: 

**Tidskompleksitet for algoritmen**
![[Pasted image 20260105083012.png]]

----
## Opgave 3 (20 %)

Denne opgave går ud på at tilføje en funktionalitet til den udleverede kode CriticalPath/KritiskVej.

Funktionaliteten skal kunne beregne den samlede mængde af slæk (slack) i hele projektet.

Slæk kan defineres som det antal tidsenheder, der er til rådighed til at udføre aktiviteten minus aktivitetens eget tidsforbrug. I det udleverede data tager event 1 6 (seks) tidsenheder, nemlig den længstvarende aktivitets tidsforbrug, som er 6 tidsenheder (se nedenfor). Aktivitet A har 3 tidsenheders slæk – forskellen mellem event 1’s længste aktivitet (B), som er 6 og A’s tidsforbrug, som er 3. Aktivitet C’s slæk er 2 tidsenheder (forskellen mellem 6 og 4).

1;A;3 slæk 3

1;B;6 slæk 0

1;C;4 slæk 2

2;D;5 slæk 0

3;E;4 slæk 0

3;F;1 slæk 3

4;G;2 slæk 5

4;H;7 slæk 0

4;I;1 slæk 6

5;J;4 slæk 0

Det samlede slæk udskrives, og det korrekte svar i ovenstående eksempel er 19 tidsenheder.

Tip: løs opgaven i en separat metode med aktivitetstabellen som parameter og genbrug af dele af koden fra main-metoden. Opgaven bliver nemmere, hvis man sorterer aktiviteterne.

Hvis du får problemer med koden, så skriv en detaljeret forklaring på, hvordan opgaven kan løses i pseudokode lignende sprog. En besvarelse uden kode kan højest give 12 ud af 20 points.

---
## Opgave 4 (25 %)

```cpp
void Trial::rotate(int arr[], int k, int arrSize){
	int tmp;
	for(int i = 0; i < k; i++){
		tmp = arr[i];
		arr[i] = arr[k+i+1];
		arr[k+i+1] = tmp;
		
		for(int i = 0; i < arrSize; i++){
			std::cout<<arr[i];
		}
		std::cout<<std::endl;
	}
}b

```
---
## Opgave 5 (20 %)
![[Pasted image 20260104135642.png]]
#### Delopgave 1 (12 %)

Tæthed for en rettet graf: m/n(n-1) 
Tæthed for en urettet graf: 2m/n(n−1) 
Man kalder en graf "tæt" hvis antallet af kanter cirka er lig antal noder i anden, ingen af graferne opfylder dette krav.

*Graf 1: rettet og vægtet*
	5 noder (n), 6 kanter (m)
	Tæthed: m/n(n-1) --> 6/5(5-1)=>6/20 = 0.3
	Der er IKKE en stig mellem alle noder, derfor: IKKE STÆRKT connected	
	
*Graf 2: rettet og vægtet* 
	5 noder, 7 kanter
	Tæthed --> 7/5(5-1)=> 7/20 = 0.35
	STÆRKT CONNECTED

*Graf 3: urettet og vægtet*
	8 noder, 16 kanter
	Tæthed:2m/n(n−1) -> 2 * 16 / 8 (8-1)=>32/56 = 0.571
	CONNECTED, da der er en stig mellem alle noder

Man kan kun anvende Djikstra, Prim og Krusual på grafer med vægt, men Prim og Kruskal virker kun på urettede grafer (altså ikke den sidste). Topologisk sortering kan kun anvendes  for DAGs (Directed Acyclic Graphs) --> dvs kun Graf 2.

#### Delopgave 2 (8 %)

Anvend Dijkstras algoritme på Graf 1 med start i node E.
Fuld Dijkstra-tabel:
	v	known	dv	pv
	A	True	7	E
	B	True	39	C
	C	True	19	A
	D	True	51	C
	E	True	0	-

Korteste stier fra start-node:
	v	dv	sti
	A	7	E -> A
	B	39	E -> A -> C -> B
	C	19	E -> A -> C
	D	51	E -> A -> C -> D
	E	0	E
=============================================
                  Graph
=============================================
Graph properties:
	Directed/rettet: True
	vægtet: True
	stærkt_forbundet: False
	svagt_forbundet: True
	tæthed: 0.3
	antal_noder: 5
	antal_kanter: 6
	klassifikation_tæthed: moderat

Grafen indeholder en cyklus – topologisk sortering er ikke mulig


---
## Opgave 6 (10 %)
![[Pasted image 20260104135723.png]]
8 genererede keys
keys 0: 5 --> C
keys 1: 22 --> L
keys 2: 39 --> U
keys 3: 56 --> M
keys 4: 73 --> F
keys 5: 90 --> Y
keys 6: 107 --> ??
keys 7: 124 --> G

Quadratic Probing Table:
0: (0,9)  <--- wut
1: [empty]
2: [empty]
3: (124,1)ingen af ovenstående.
4: (73,1)
5: (5,1)
6: (22,1)
7: (107,1) <--- P Skulle ligge her og ikke på plads 8
8: [empty]
9: (39,1)
10: [empty]
11: [empty]
12: [empty]
13: (90,1)
14: (56,1)
15: [empty]
16: [empty]

---
## Opgave 7 (5 %)
![[Pasted image 20260104135800.png]]

Den nedenstående tabel kan ikke repræsentere en prioritetskø, hvor enhver node skal være mindre end alle sine efterkommere.

Denne såkaldte heap-order fejler ét sted. I hvilket indeks?

I øverste række er prioriteterne angivet; i nederste række står de tilsvarende tabelindeks.

14 17 16 28 22 65 29 31 30 26 23 89 64 35 32 48 47 46 45

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
![[Pasted image 20260105083707.png]]
den fejler ved 64, fordi dens forældre (65) er højere, og alle børn skal have forældre med højere værdier i en min-heap

