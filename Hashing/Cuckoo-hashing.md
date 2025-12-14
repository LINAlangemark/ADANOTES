
**2: Hashing with Chaining**
Hashfunctions decide where each item is stored
An item x is stored in position: h1(x), where "h1" is a function that gives a fixed value [index] depending on x
The tablesize >= n [number of elements]
![[Pasted image 20251214101126.png]]
Hashing with chaining uses "buckets"
It is implemented as a list, where each bucket holds a linked list to each item that hashes to the same index/bucket of the hash-table.

![[Pasted image 20251214102218.png]]

**3: Cuckoo Hashing**
*we want to look up items in constant time in worst case, NOT just expected case*
	One approach is to maintain a hash function that has no collisions for elements in the set. This is called a perfect hash function, and allows us to insert the items directly into the array, without having to use a linked list. 

*The above is difficult to implement --> proposal is cuckoo hashing:*
	Instead of requiring that x should be stored at position h1(x), we give two alternatives: Position h1(x) and position h2(x). We allow at most one element to be stored at any position, i.e., there is no need for a data structure holding colliding items

--> this allows us to lookup items by only looking at two positions in the table!

-->during insertations, there still might not be space for the item if both of those positions are occupied
	--> resolved by throwing out the current occupant [y] of the first option/spot, to make room
	--> if the alternative position for y is *not* occupied, place it there
	--> if not, y throws out the occupant in that alternative position, and so on...
	--> repeated until resolved, or until the process has taken too long [then we use rehashing]
![[Pasted image 20251214103058.png]]

*pos:* is where we are currently trying to insert an item
*a<-->b:* means that the contents of a and b are swapped

NOTE: procedure does NOT start with examining if positions h1(x) and h2(x) are vacant, but simply inserts x in position h1(x)