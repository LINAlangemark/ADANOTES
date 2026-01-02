The more inversions the list contains, the more unsorted it is. 
The discipline of sorting is to reduce the number of inversions in a list of integers to zero.

**INVERSIONS**
- The average number of inversions in a list of N distinct integers is N(N-1)/4.
- If one operation can eliminate one inversion, that kind of sorting must have quadratic time complexity.
- If more than one inversion can be removed in one operation, we might be able to do better than quadratic.
***Example:***
Take a look at this list of integers:  34, 8, 64, 51, 32, 21
	The numbers are clearly unsorted so let’s see if we can measure out just how unsorted they are.
	To assist us we can define a concept called inversion. An inversion is an ordered pair of numbers (i,j), for which i < j, but a[i] > a[j].
	In our example the following inversions occur:
 
	(34,8) (34,32) (34,21) (64,51) (64,32) (64,21) (51,32) (51,21) (32,21)

![[Pasted image 20251220100614.png]]

**EKSEMPEL MED:** data = {5, 2, 9, 1, 5, 6};

![[Pasted image 20251220100708.png]]
**O(N2)** [[Sorting with O(N2)]]
	Insertionsort
	Selectionsort
	Bubblesort

**O(N logN)** [[Sorting with O(N log N)]]
	Mergesort
	Heapsort
	Quicksort

**bucketSort()**
	Under certain circumstances we can do better than O(N log N).
	If we need to sort positive integers with a maximum value M, we can solve the problem by creating an array sized M. 
	The numbers are read from one end to the other and reading value X, index X in M is incremented by one. 
	When all the numbers have been read, the array is output in accordance with the number of occurrences in the indexes. 
	Time complexity O(M+N) -> O(N).