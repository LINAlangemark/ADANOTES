***Hashing: you gain speed by giving up space!**
	Abstract datatype where objects/items can be fetched and stored in constant time
	Most implementations require at least twice as much space as data to achieve constant time for insertions/fetching

* Each item has a unique key [used for retrieval]
* Items are stored in an array/table with a fixed size (this should be a prime number)
* High performance requires uniform distribution of items in the table
* Load factor [lambda] is equal to the number of elements in the table divied by the table size 
	--> should always be less than 0.5

**Hashing is the most efficient implementation of a dictionary!**
dictionary: data structure for storing a set of items 

	Lookup(x): returns trye if x is in the current set
	Insert(x): adds the item x to the current set
	Delete(x): removes x from current set if present

commonly [some] information is associated with each item, and returned with lookups

Linked list: simple/inefficient implementation of a dictionary
Balanced Search Tree: more scalable dictionary implementation

[these?] hashing algorithms are not deterministic, so performance bounds are specified in "average case"

**Hashing will always lead to collisions**
this can be overcome by:
	seperate chaining
	linear probing
	quadratic probing
	double hashing