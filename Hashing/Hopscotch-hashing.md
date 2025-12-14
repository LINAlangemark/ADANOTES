*Chained Hashing:* closed address has table scheme consisting of an array of buckets each of which holds a linked list of items.

*Linear Probing:* open-addressed hash scheme in which items are kept in a contigious array, each entry of which is a bucket for one item. A new item is inserted by hashing the item to an array bucket, and scanning forward from that bucket until an empty bucket is found.

*Cuckoo Hashing:*  is an open-addressed hashing technique that unlike linear probing requires only a deterministic constant number of steps to locate an item. Cuckoo hashing uses two hash functions. A new item x is inserted by hashing the item to two array indexes. If either slot is empty, x is added there. If both are full, one of the occupants is displaced by the new item. The displaced item is then re- inserted using its other hash function, possibly displacing another item, and so on.

**2: The New Hopscotch Algorithm**
Hopscotch hashing combines the advantages of these three approaches in the following way. There is a single hash function h. The item hashed to an entry will always be found either in that entry, or in one of the next H − 1 entries, where H is a constant.

In other words, a “virtual” bucket has fixed size and overlaps with the next H − 1 buckets.

Each entry includes a hop-information word, an H-bit bitmap that indicates which of the next H − 1 entries contain items that hashed to the current entry’s virtual bucket. 

In this way, an item can be found quickly by looking at the word to see which entries belong to the bucket, and then scanning through the constant number

![[Pasted image 20251214103909.png]]
![[Pasted image 20251214103930.png]]
![[Pasted image 20251214104043.png]]
![[Pasted image 20251214104052.png]]
