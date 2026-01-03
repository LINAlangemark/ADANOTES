
Hopscotch hashing kombinerer fordelene fra:
- **chained hashing** (fleksibel håndtering af kollisioner)
- **linear probing** (kontig tabel → god cache-lokalitet)
- **cuckoo hashing** (hurtig søgning tæt på hjem-position)

*Et element skal altid ligge i sit bucket-område:*

Hvis et element hasher til index `i`, kan det findes i :
	`i … i + (H−1)` — hvor H er en lille konstant.  
*Dette kaldes en virtuel bucket.*

---
**Struktur**
Hver tabelplads har:
- værdien
- et **hop-bitmap** (H bits), der fortæller:
	hvilke af de næste `H−1` pladser indeholder elementer, der hører til dette bucket.

Så lookup er:
	se hop-bitmap  
	 kun tjek de relevante pladser (konstant tid)

---
**Indsættelse** 
Antag `x` hasher til `i`:
	Brug linear probing til at finde første tomme plads `j`.  
	Hvis `j` ligger indenfor området `[i, i+H−1]` → læg `x` der.  
	Hvis `j` er for langt væk:

- find et element mellem `i` og `j`,  
    som kan “hoppe” tættere på `i`    
- byt (skab en tom plads tættere på `i`)
- gentag — indtil `x` kan placeres.

Hvis det ikke lykkes →  [[Rehashing]]

*Hopscotch “skubber” altså elementer kort afstand, så alle bevarer et hjem-nært leje.*

---
**Søgning**
beregn `i = h(x)`  
læs hop-bitmap ved `i`  
scan kun de markerede pladser (≤ H)

*konstant tid i praksis.*

---
**Tidskompleksitet**
- Søgning: O(1) forventet
- Indsættelse: O(1) gennemsnitligt (kan kræve rehash)
- Plads: lille overhead (hop-bitmap)

---
**Pseudokode** --> se også [[HASHING CLASS AND TESTBENCHES]]
Antag:
```
const int TABLE_SIZE = ...;
const int H = 32;          // størrelse på "hop-neighbourhood"

struct Bucket {
    Key      key;
    bool     used;
    uint32_t hop;          // H-bit bitmap
};

Bucket table[TABLE_SIZE];

int h(Key x);              // hash-funktion

```
Find:
```
bool find(Key x) {
    int home = h(x) % TABLE_SIZE;
    uint32_t hopInfo = table[home].hop;

    while (hopInfo != 0) {
        int offset = indexOfLeastSignificantSetBit(hopInfo); // 0..H-1
        int idx = home + offset;

        if (table[idx].used && table[idx].key == x)
            return true;

        hopInfo &= (hopInfo - 1);   // fjern den laveste satte bit
    }
    return false;
}

```
Insert:
```bool insert(Key x) {
    int home = h(x) % TABLE_SIZE;

    // 1) Allerede til stede?
    if (find(x)) return true;

    // 2) Lineær søgning efter første ledige bucket
    int freeIdx = home;
    while (freeIdx < TABLE_SIZE && table[freeIdx].used)
        ++freeIdx;

    if (freeIdx == TABLE_SIZE) {
        rehash();
        return insert(x);
    }

    // 3) Flyt elementer tættere på deres hjem,
    //    indtil freeIdx ligger i [home, home + H - 1]
    while (freeIdx - home >= H) {
        bool moved = false;

        // prøv at finde et bucket j, som har et element i sit hop-interval,
        // der kan flyttes til freeIdx
        for (int j = freeIdx - (H - 1); j < freeIdx; ++j) {
            uint32_t hop = table[j].hop;

            // gå igennem alle offsets i j's hop-bitmap
            for (int offset = 0; offset < H; ++offset) {
                if ((hop & (1u << offset)) == 0) continue;

                int from = j + offset;    // nuværende placering
                if (from >= freeIdx) continue;

                // flyt elementet fra 'from' til 'freeIdx'
                table[freeIdx].key  = table[from].key;
                table[freeIdx].used = true;

                // opdater hop-bits for bucket j
                table[j].hop &= ~(1u << offset);                    // ryd gammel bit
                table[j].hop |=  (1u << (freeIdx - j));             // sæt ny

                freeIdx = from;     // den nye ledige plads
                moved = true;
                break;
            }
            if (moved) break;
        }

        if (!moved) {          // kunne ikke skubbe nogen tættere på
            rehash();
            return insert(x);
        }
    }

    // 4) FreeIdx er nu i hjem-bucket'ens hop-område
    table[freeIdx].key  = x;
    table[freeIdx].used = true;
    table[home].hop    |= (1u << (freeIdx - home));
    return true;
}


```

---
**mine egne noter....**
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
