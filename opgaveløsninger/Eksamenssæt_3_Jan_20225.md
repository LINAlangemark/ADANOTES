## Opgave 1 (10 %)
```cpp
[](https://www.google.com/webhp?hl=da&sa=X&ved=0ahUKEwjc8o3A6_ORAxUMBdsEHQU9CjMQPAgJ "Gå til Googles startside")[](https://www.google.com/webhp?hl=da&sa=X&ved=0ahUKEwjc8o3A6_ORAxUMBdsEHQU9CjMQPAgJ "Gå til Googles startside")int Trial::charCounter(std::string s, char c){
	if(s.empty()){
		return 0; //base case
	}
		char cs = s.back(); //save last char in s
		s.pop_back(); //pop last char in s
	if(cs == c){ //string char = char
		return 1 + charCounter(s, c); //count progress
	}
		return charCounter(s, c); //continue recursion
}
```
---
## Opgave 2 (15 %)
![[Pasted image 20260104110252.png]]
***Analyse af tidskompleksiteter***
Første, yderste loop: O(N)
Første, midterste loop: O(N)
![[Pasted image 20260104110545.png]]
Første, inderste loop: O(log N)
![[Pasted image 20260104110757.png]]
Andet loop: O(N log N)

De tre første loops ganges sammen og bliver: O(N² log N)
Dette sammenlignes med det sidste loop:   O(N² log N) +  O(N log N) =>

**Algoritmens tidskompleksitet:**  O(N² log N)

---
**CPP tests** [MANGLER]
Hvis der indtræffer et skifte i det største antal operationer i henholdsvis for-loop nummer 1 og for-loop nummer 2 (i runde tal: værdierne af x og y), så angiv den værdi af N (cirka), hvor skiftet indtræffer.

med tests får jeg 200 og 64

---
## Opgave 3 (25 %)

Hele Source.cpp er kopieret ind i bunden af afleveringen. Her gennemgåes den.
Tilføjet før main i Source.cpp
```cpp
//helper to calculate slack from event duration minus activity duration
int getSlack(int eD, int aD){
	return eD - aD;
}
//tracks the max activity duration in event
std::vector<int> eventDuration = {0}; 
//tracks which activity has most slack
int mostSlack = 0;  
string mostSlackActivity = "";
int activityDuration = 0;
```
Tilføjet til for-løkken hvor totalDuration beregnes
```cpp
int event = 0; //added
for (int i = 0; i < tabel.size(); i++){
	totalDuration += tabel[i].getDuration();
//code from here down was also added
	if(tabel[i].getEvent() == event){ //same event
		//if max duration of this event
		if(tabel[i].getDuration() >eventDuration[event]){ 
			eventDuration[event] = tabel[i].getDuration(); //set event duration
		}
	}else{
		event++; //nyt event
		if(tabel[i].getDuration() >eventDuration[event]){
			eventDuration[event] = tabel[i].getDuration();
		}
	}
}
```

Tilføjet til inderste while-løkke
```cpp
activityDuration = tabel[indeks].getDuration();
int activityevent = tabel[indeks].getEvent();
string activity = tabel[indeks].getTask();
int activitySlack = getSlack(eventDuration[activityevent], activityDuration);

if(activitySlack > mostSlack){
	mostSlack = activitySlack;
	mostSlackActivity = activity;
}
```

Tilføjet et print i bunden af main
```cpp
std::cout << "Most Slack: " << mostSlack << " , Activity: "<<mostSlackActivity << endl;
```
---
## Opgave 4 (20 %)
Tilføjet til cpp-filen

```cpp
// ---------------- findRoute ----------------

std::string BinarySearchTree::findRoute(int value) const{
	if (!root || !contains(value)) {
		return "";
	}
	return findRoute(root, value);
}

std::string BinarySearchTree::findRoute(BinaryNode* node, int value) const {
	if (!node){
		return "";
	} 
	
	if (value == node->element){
		return std::to_string(node->element);
	}
	
	if (value < node->element){
		return std::to_string(node->element) + " " + findRoute(node->left, value);
	}else{
		return std::to_string(node->element) + " " + findRoute(node->right, value);
	}
}
```

---

## Opgave 5 (12 %)
Graf:
![[Pasted image 20260104123553.png]]
Startkonfig:
![[Pasted image 20260104123604.png]]

1. **Traverser grafen med Dijkstras algoritme under anvendelse af den angivne startkonfiguration.**
Fuld Dijkstra-tabel:

	v	known	dv	pv
	F	True	0	-
	A	True	15	B
	B	True	14	D
	C	True	16	A
	D	True	5	E
	E	True	4	F
	G	True	32	J
	H	True	21	C
	I	True	19	A
	J	True	22	I

Korteste stier fra start-node:
v	dv	sti
F	0	F
A	15	F -> E -> D -> B -> A
B	14	F -> E -> D -> B
C	16	F -> E -> D -> B -> A -> C
D	5	F -> E -> D
E	4	F -> E
G	32	F -> E -> D -> B -> A -> I -> J -> G
H	21	F -> E -> D -> B -> A -> C -> H
I	19	F -> E -> D -> B -> A -> I
J	22	F -> E -> D -> B -> A -> I -> J



2. **Etabler et minimum spanning tree for den ’undirectede’ version af grafen ved anvendelse af Kruskals algoritme. Besvarelsen skal bestå af en liste af edges i den rækkefølge, algoritmen vil tilføje dem. Angiv tillige træets samlede vægt.**

**MST (Prim, start = A) – total vægt = 31**
	(A-B, 1)
	(A-C, 1)
	(A-I, 4)
	(I-D, 2)
	(D-E, 1)
	(I-J, 3)
	(E-F, 4)
	(C-H, 5)
	(J-G, 10)



---
## Opgave 6 (13 %)

![[Pasted image 20260104124924.png]]
For Y1: 
	hash(x) = 3 [fyldt]
	hash(x) + 1 * 1 => ***index 4***
For Y2:
	hash(x) = 3 [fyldt]
	hash(x) + 1 * 1 => 4 [fyldt]
	hash(x) + 2 * 2 => **index 7**
For Y3:
	hash(x) = 3 [fyldt]
	hash(x) + 1 * 1 => 4 [fyldt]
	hash(x) + 2 * 2 => 7 [fyldt]
	hash(x) + 3 *  3 => ***index 10*** 

---
**Kørt med computer program**
autogenererede keys
keys[ 1 ]: 3
keys[ 2 ]: 16
keys[ 3 ]: 29
keys[ 4 ]: 42
keys[ 5 ]: 55
keys[ 6 ]: 68
keys[ 7 ]: 81
keys[ 8 ]: 94
keys[ 9 ]: 107
keys[ 10]: 120
keys[ 11 ]: 133
keys[ 12]: 146
keys[ 13]: 159

Resulterende Quadratic Probing Table med rehashing:
0: (55,1)
1: [empty]
2: [empty]
3: (3,1)
4: [empty]
5: [empty]
6: [empty]
7: [empty]
8: [empty]
9: [empty]
10: (120,1)
11: [empty]
12: [empty]
13: (68,1)
14: [empty]
15: [empty]
16: (16,1)
17: [empty]
18: [empty]
19: [empty]
20: [empty]
21: [empty]
22: [empty]
23: (133,1)
24: [empty]
25: [empty]
26: (81,1)
27: [empty]
28: [empty]
29: (29,1)
30: [empty]
31: [empty]
32: [empty]
33: [empty]
34: [empty]
35: [empty]
36: (146,1)
37: [empty]
38: [empty]
39: (94,1)
40: [empty]
41: [empty]
42: (42,1)
43: [empty]
44: [empty]
45: [empty]
46: [empty]
47: [empty]
48: [empty]
49: (159,1)
50: [empty]
51: [empty]
52: (107,1)
53: [empty]
54: [empty]


---
## Opgave 7 (5 %)

**Fordi den ikke overholdr heap-ordenen**
0:    __ 
1:    7
2:    19
3:    11 [mindre end foregående]
4:    22
5:    28
6:    13 [mindre end foregående]
7:    26
8:    34
9:    26 [mindre end foregående]
10: 34
11: 26 [mindre end foregående]
12: 42
13: 27 [mindre end foregående]
14: 21 [mindre end foregående]
15: 14 ** [mindre end foregående]
**15: 81** **[samme indeks som foregåend]** 
17: 18 [mindre end foregående]
18: 69
19: 27 [mindre end foregående]


