	 #### Lina Langemark -- Jan. 2. 2026 -- Algoritmer og Datastrukture
## Exercise 1
![[Pasted image 20260102155603.png]]
***Prim MST***
	(A-C, 9)
	(C-D, 4)
	(A-B, 22)
	(D-I, 30)
	(I-H, 19)
	(I-G, 21)
	(G-E, 23)
	(E-F, 18)

hvis man lavede kruskal ville det se anderledes ud:
***Kruskal MST***  
	(C-D, 4)
	(A-C, 9)
	(E-F, 18)
	(H-I, 19)
	(G-I, 21)
	(A-B, 22)
	(E-G, 23)
	(D-I, 30)

## Exercise 2
![[Pasted image 20260102155613.png]]
***Kruskal MST***
	(H-G, 1)
	(C-I, 2)
	(F-G, 2)
	(B-A, 4)
	(C-F, 4)
	(C-D, 7)
	(B-C, 8)
	(D-E, 9)
## Exercise 3
```cpp
int logTwo(int N){
    if (N == 1){ // 2^0 = 1
        return 0;
    }
    if(N <= 0||N%2 != 0){
        return -1;  //error
    }

    int b = logTwo(N/2); //divide and conquer recursive call
    int y = b+1;

    return y;
}
```
## Exercise 4
![[Pasted image 20260102155440.png]]
***In-order:***  [15, 20, 25, 30, 31, 32, 35, 48, 50, 65, 66, 67, 69, 70, 90, 94, 98, 99]
***Level-order:*** [50, 48, 70, 30, 65, 90, 20, 32, 67, 98, 15, 25, 31, 35, 66, 69, 94, 99]
	A Queue is used to implement a level order traversal, as level order traversal requires breadth-first search...

***Internal Path Length:*** 52
***Træets højde:***  4
???
## Exercise 5
![[Pasted image 20260102155535.png]]
***MST (Prim, start = A)***
	(A-B, 1)
	(B-C, 4)
	(C-F, 2)
	(C-D, 6)
	(B-E, 7)
	(E-G, 10)

***Tree size (sum of weights) = 30***
## Exercise 6[FIKS]
### Linear Probing Table with Rehashing:
0: [empty]
1: (1,1)
2: (2,1)
3: (3,1)
4: (4,1)
5: (5,1)
6: [empty]
7: [empty]
8: (8,1)
9: [empty]
10: [empty]
11: [empty]
12: [empty]
13: [empty]
14: [empty]
15: [empty]
16: [empty]
17: [empty]
18: [empty]
19: [empty]
20: [empty]
NOT FINISHED
## Exercise 7
```cpp
int Exam::longestChain(){

int N = 10000; //N is a number under 10000
int bestStart = 1; //initial best start
int chainSize = 0; //initial length
int n;

for(int i = 2; i < N; i++){
	
	n = i;
	int tmp = 0;
	std::cout<<"n: "<<n<<std::endl;
	
	while(n != 1){
		if(n%2 == 0){
			n = n/2;
			tmp++;
			std::cout<<"n: "<<n<<std::endl;
		} else{
			n = n*3+1;
			tmp++;
			std::cout<<"n: "<<n<<std::endl;
		}
	}
	
	if(n == 1 && tmp > chainSize){
		chainSize = tmp;
		bestStart = i;
		tmp = 0;
	}
}

std::cout<<"the best starting number is: " << bestStart 
<<" with chain size = " << chainSize<<std::endl;

return bestStart;
}
```

***returns: the best starting number is: 6171 with chain size = 261***

Running time of algorithm?
How to improve it?
## Exercise 8
![[Pasted image 20260102142936.png]]
Dijkstra er en grådig algoritme som løser problemet trinvist, ved altid at vælge, hvad den mener er den "billigste" mulighed --> dvs den nærmeste node

Kanter i shortest-path-tree:

| Trin | Kant                        | Afstand                            |
| ---- | --------------------------- | ---------------------------------- |
| 1    | seatle - san francisco      | (afstand til san francisco = 1306) |
| 2    | san francisco - los angeles | (afstand til  los angeles  = 1935) |
| 3    | san francisco - las vegas   | (afstand til las vegas = 2225)     |
| 4    | seatle - denver             | (afstand til denver = 2161)        |
| 5    | denver - dallas             | (afstand til dallas = 3419)        |
| 6    | seatle - minneapolis        | (afstand til minneapolis = 2661)   |
| 7    | minneapolis - chicago       | (afstand til chicago = 3322)       |
| 8    | chicago - wash dc           | (afstand til wash dc = 4467)       |
| 9    | dallas - miami              | (afstand til miami = 5580)         |
| 10   | wash dc - new york          | (afstand tilnew york= 4850)        |
| 11   | chicago - boston            | (afstand til boston = 4935)        |

Med start i seatle, kan det ses at den næste node er san-francisco, hvorfra dijkstra både undrsøger los angeles og las vegaes før den går tilkbage til seatle igen, da den næst-nærmeste node til seatle er denver, som har distancen: 2161, fremfor distancerne på kanterne 2 og 3.



## Exercise 9
```cpp
int Exam::pythagoreanTriplet() {
int sum = 1000;

for (int a = 1; a < sum / 3; ++a) {
	for (int b = a + 1; b < sum / 2; ++b) {
		int c = sum - a - b;
		if (a*a + b*b == c*c) {
			std::cout << "a: " << a 
			<< ", b: " << b
			<< ", c: " << c 
			<< " : a+b+c = " 
			<< (a + b + c) << std::endl;
			
			return a * b * c;
		
		}
	}
}
	return -1;
}
```

## Exercise 10

![[Pasted image 20260103113414.png]]
yderste for-loop: O(N)
midterste for-loop: O(N) [N/2 en konstant???
inderste for-loop: O(log N) [halvering af problemet]
**de 3 nestede loops ganges sammen: O(N² log N)**

![[Pasted image 20260103113406.png]]
## Exercise 11
```cpp
int Exam::getNumberEqual(int x[], int n, int val){
int occ = 0;
for(int i = 0; i < n; i++){
	if(n == 0){
		return occ-1;
	}else{
		if(x[i] == val){
			occ++;
		}
	}
}
return occ;
}
```
## Exercise 12 [MANGLER]
![[Pasted image 20260102121807.png]]
## Exercise 13
Heap Order Property: Roden indeholder det mindste element og enhver node er mindre end alle dens efterkommere. En prioritetskø implementeres som en binary heap. 
Vi skal først benytte en find() -operation til at finde elementet [fromP] i vores heap/priority-queue.
Dernest skal vi opdatere heapen/prioritets-køen med en tmp [gammel], så elementet i den gamle plads [fromP], bliver lagt over i den nye plads [toP]
nu skal Heap-ordenen genoprettes. med enten operationen "bubbleUp()" eller "bubbleDown()" 
Hvis "toP" indsættes i et index som er mindre end "fromP", skal vi sørge for at alle elementerne efterfølgende "bubbleUp"
Hvis "toP" indsættes i et index som er større end "fromP", skal vi sørge for at alle elementerne efterfølgende "bubbleDown"

**Pseudokode** 
---
changePriority( int fromP, int toP):

	//0. tjek preconditions? 
		altså om fromP eksistere og at toP != fromP
	
    // 1. find elementet
	    i = index hvor heap[i].priority == fromP

    // 2. opdater
	    gammel = heap[i].priority
	    heap[i].priority = toP

    // 3. genopret heap-orden
	    if toP < gammel:          // min-heap
	        bubbleUp(i)
	    else:
	        bubbleDown(i)


## Exercise 14
hash(x) + 1 * 1 [fyldt]
hash(x) + 2 * 2 [fyldt]
hash(x) + 3 *  3 --> ***index 10*** 

---- Exercise 14: Final Hash Table----
0: (0,1)
1: (1,1)
2: (2,1)
3: [empty]
4: [empty]
5: (5,1)
6: [empty]
7: (7,1)
8: (8,1)
9: [empty]
10: (12,1)

## Exercise 15
jeg føler virkeligt det fucker mig at prøve at køre tests på de her...det ser bare så forkert ud 
![[Pasted image 20260103121410.png]]
men:
i-loop: N/2 --> O(N)
j-loop: N --> O(N)
k-loop: N/2 --> O(N)

***kombineres: i * j * k => O(N³)*** 

## Exercise 16
forkert forsøg.....
```cpp 
int Exam::mostFrequentNum(int nums[], int noOfNums){
	std::cout << "Nums: " << noOfNums << std::endl;
	
	// Sorter tallene
	std::sort(nums, nums + noOfNums);
	
	// find mest forekommende tal
	int num = nums[0];
	int count = 1;
	int max = 0;
	
	for (int i = 1; i < noOfNums; ++i) {
		if (nums[i] == nums[i - 1]) {
			count++;
			std::cout<<"num: "<<nums[i]<<", count: "<<count<<std::endl;
		if (count > max) {
			max = count;
			num = nums[i];
		}
		} else {
			count = 1;
		}
	}
	return num;
}

```
std::sort() har en tidskompleksitet på O(N log N)
det sekventielle for-loop har så en tidskompleksitet på O(N)
det bliver: O(N log N) + O(N) => **O(N log N)**, da vi ignorere det "lille" led

rigtigt forsøg...
```cpp
int Exam::O_N_mostFrequentNum(int nums[], int n){
	// 1. Tælle-array (0..100)
	int count[101] = {0}; // alle sat til 0
	
	// 2. Gå igennem input-arrayet én gang
	for (int i = 0; i < n; ++i) {
		int x = nums[i];
		count[x]++; // tæller forekomster
	}
	
	// 3. Find tallet med størst count
	int bestNum = 0;
	int bestCount = count[0];
	
	for (int v = 1; v <= 100; ++v) {
		if (count[v] > bestCount) {
			bestCount = count[v];
			bestNum = v;
		}
	}
	
	return bestNum;
}
```
2 for-loops i sekvens --> O(N) + O(N) => **O(N) tidskompleksitet**

## Exercise 17
```cpp
int Exam::recursiveSum(int N){
if (N < 1){return 0;} //base case

return N + recursiveSum(N-1);
}
```

## Exercise 18[MANGLER]
![[Pasted image 20260103125306.png]]
## Exercise 19
![[Pasted image 20260103134547.png]]
**MST (Prim, start = A)** 
	(A-B, 3)
	(B-E, 2)
	(E-I, 1)
	(E-H, 2)
	(B-F, 3)
	(F-G, 2)
	(G-C, 1)
	(A-D, 4)
	(I-J, 7)

## Exercise 20
kombinatorik

```cpp
//exercise 20 -- kombinatorik, vælg 6 cifre fra 1-9 [i stigende rækkefølge]
int main(){
Exam e;

int n = 9; //choose from 1 to n
int k = 6; //k times
int possiblePasswords = e.binom(n, k);

return 0;
}

int Exam::binom(int n, int k) {
	if (k == 0 || k == n) return 1;
	return binom(n - 1, k - 1) + binom(n - 1, k);
}


```
## Exercise 21
```cpp
int Exam::evenSquares(int N){
	if (N < 1){
		return 0;
	}
	if(N%2 == 0){
		return N*N + evenSquares(N-2); //N is even
	}else{
		return evenSquares(N-1); //N is odd
	}
}
```

## Exercise 22
![[Pasted image 20260103133142.png]]
I-loop --> O(N)
J-loop --> O(N/2) --> O(N)
k-loop --> O(1)
sammen --> **O(N²)**
## Exercise 23

```cpp
int Exam::oddSum(int N){
	if (N < 1){
		return 0;
	}
	if(N%2 != 0){
		return N + oddSum(N-2); //N is even
	}else{
		return oddSum(N-1); //N is odd
	}
}
```

## Exercise 24
Minimal højde for et træ: h_min = log2(n)
log2(27)= 4.75

Ekstra hjælpe  funktioner til at finde antal noder
```cpp
int BinarySearchTree::noOfNodes()const {
	return noOfNodes(root);
}
int BinarySearchTree::noOfNodes(BinaryNode *t) const{
	if (t == nullptr)
		return 0;
	else
		return 1 + noOfNodes(t->left) + noOfNodes(t->right);
}
```

internal method minimalHeight
```cpp
bool BinarySearchTree::minimalHeight(BinaryNode *t) const{
	//find tree height
	int h = height();
	//find number of nodes
	int n = noOfNodes();
	
	//find next power of two
	int p = 1; //2-tals-potens
	int k = 0; //eksponent [tæller]
	
	while (p < n+1) { //potens skal bare være mindre end number of nodes
	p *= 2; // næste 2-potens
	++k; // eksponent stiger
	}
	
	//subtract one
	k = k-1;
	
	//compare to height
	if(h == k){
		return true;
	}
	return false;
}
```


## Exercise 25
```cpp
bool Exam::isAnagram(const std::string& s1, const std::string& s2) {
	if (s1.size() != s2.size()) return false;
	
	int count[256] = {0}; // eller 26 hvis kun a–z
	
	for (size_t i = 0; i < s1.size(); ++i) {
		unsigned char c1 = s1[i];
		unsigned char c2 = s2[i];
		count[c1]++;
		count[c2]--;
	}
	
	for (int c : count) {
		if (c != 0) return false;
	}
	return true;
}

```
Tidskompleksitet: O(N), hvor N = 256 
tæller for hvert muligt bogstav
tjekker om alle tællere ender på nul