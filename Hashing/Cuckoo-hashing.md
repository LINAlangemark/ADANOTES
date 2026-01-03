Cuckoo hashing sikrer worst-case O(1) lookup.
	--> Hvert element har to mulige pladser:
	`h1(x)` eller `h2(x)` — og der må kun ligge ét element pr. plads.

---
**Søgning**
Kig kun:
	`T[h1(x)]`  
	`T[h2(x)]`
Hvis x ikke er der → det findes ikke.

*Altid maks. 2 opslag.*

---
**Indsættelse** 
Indsæt `x`:
	læg `x` i `h1(x)` (selvom der står noget)  
	Hvis pladsen var optaget → smid beboeren ud  
	flyt den udsmidte til dens _anden_ hash-position  
	gentag, indtil:
	
- en tom plads findes, eller    
- der opstår et langt forflytnings-loop → [[Rehashing]]

*Dette minder om en gøgeunge, der skubber andre ud af reden — deraf navnet.*

---
**Tidskompleksitet**
- Søgning: O(1) worst case
- Indsættelse: typisk O(1), men kan i værste fald kræve rehash
- Plads: tabel ≈ størrelse n

---
**Pseudokode**--> se også [[HASHING CLASS AND TESTBENCHES]]
Antag:
```
const int TABLE_SIZE = ...;
const int MAX_KICKS  = 2 * TABLE_SIZE;   // eller anden grænse

Key  table[TABLE_SIZE];  // evt. to tabeller, men én er nok til eksamen
bool used[TABLE_SIZE];

int h1(Key x);
int h2(Key x);
```
Find:
```
bool find(Key x) {
    int i1 = h1(x) % TABLE_SIZE;
    if (used[i1] && table[i1] == x) return true;

    int i2 = h2(x) % TABLE_SIZE;
    if (used[i2] && table[i2] == x) return true;

    return false;
}
```
Insert:
```
bool insert(Key x) {
    if (find(x)) return true;      // ingen dubletter

    int pos = h1(x) % TABLE_SIZE;

    for (int k = 0; k < MAX_KICKS; ++k) {

        if (!used[pos]) {         // tom plads → vi er færdige
            table[pos] = x;
            used[pos]  = true;
            return true;
        }

        // smid nuværende occupant ud ("cuckoo")
        std::swap(x, table[pos]);

        // x er nu det fortrængte element; find dets alternative plads
        int h1x = h1(x) % TABLE_SIZE;
        int h2x = h2(x) % TABLE_SIZE;

        if (pos == h1x) pos = h2x;
        else            pos = h1x;
    }

    // lykkedes ikke inden for MAX_KICKS → rehash og prøv igen
    rehash();
    return insert(x);
}

```

---
**mine egne noter....**

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