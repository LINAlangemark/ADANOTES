En **binary heap** er et _komplet binært træ_, hvor noderne ligger i en bestemt orden — men ikke nødvendigvis sorteret som i et BST.

Der findes to typer:

- **Max-heap**: hver node ≥ sine børn  
    (roden er den største værdi)
    
- **Min-heap**: hver node ≤ sine børn  
    (roden er den mindste værdi)
    
![[Pasted image 20260105163342.png]]
EKSEMPEL:
Index:  0  1  2  3  4
Value:  9  7  6  3  5
TRÆ:
	      9
	    /   \
	   7     6
	  / \
	 3   5


![[Pasted image 20260105163439.png]]
![[Pasted image 20260105163523.png]]

> Kun **relationen mellem forælder og børn** garanteres.  
> Ikke hele træet som i et binary search tree.  
Key Differences:  
Min-Heap: The root is the minimum element, and every node is less than its children ((parent\le children)). 
Max-Heap: The root is the maximum element, and every node is greater than its children ((parent\ge children)). 
BST: Left child (<) Parent (<) Right child. No specific structure for min/max element location other than leftmost/rightmost.

Performance: 
Heaps allow (O(1)) access to max/min, while BSTs take (O(\log n)). 
Heaps are built in (O(n)), whereas BSTs require (O(n\log n)).  

Use Cases:  Heap: Best for priority queues, Dijkstra’s algorithm, and finding the smallest/largest element quickly. BST: Best for maintaining sorted data, searching for specific elements, or range queries.