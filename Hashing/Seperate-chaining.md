**Problem:** flere nøgler kan få samme hash-værdi ⇒ kollisioner.

**Idé:** I stedet for at prøve at undgå kollisioner helt, accepterer vi dem –  men alle elementer med samme hash-værdi samles i en “bucket”, typisk en linked list.

- Vi har en array `table[0..m-1]`
- Hvert `table[i]` er en liste (kæde) af elementer, der hasher til index `i`
- Hvis `h(x) = i`, så ligger `x` et sted i listen `table[i]`

---
**Grundbegreber**
- Tabellens størrelse: `m` (antal buckets)    
- Antal elementer: `n`
- Load factor:
    λ = n/m *= gennemsnitligt antal elementer pr. bucket*

---
**Tidskompleksitet (med fornuftig hash-funktion)**

- **Find / Insert / Delete (gennemsnit)**:  
    O(1+λ)
    – typisk tæt på O(1), når λ  holdes lille (f.eks. omkring 1)
- Worst case: alle nøgler i samme bucket ⇒ O(n)

---
**Operationer (idé)**

Lad `h(key)` give et index i `0..m-1`.

- **Find(key)**  
    → beregn `i = h(key)`  
    → gennemløb listen ved `table[i]` og sammenlign nøgler
    
- **Insert(key, value)**  
    → hvis `key` allerede findes i `table[h(key)]`, evt. opdater værdi  
    → ellers tilføj node forrest i den liste (billigst)
    
- **Delete(key)**  
    → find `key` i listen `table[h(key)]`  
    → unlink node fra kæden og frigør den
---
**Pseudokode**

```
struct Entry {
    Key   key;
    Value value;
    Entry* next;
};

const int TABLE_SIZE = ...;          // fx et primtal
Entry* table[TABLE_SIZE];            // alle pegere starter som nullptr

int h(const Key& k);                 // hash-funktion: returnerer 0..TABLE_SIZE-1

```

init
```
void initTable() {
    for (int i = 0; i < TABLE_SIZE; ++i)
        table[i] = nullptr;
}

```

Find
```
Entry* find(const Key& k) {
    int idx = h(k);          // bucket-index

    Entry* curr = table[idx];
    while (curr != nullptr) {
        if (curr->key == k)
            return curr;     // fundet
        curr = curr->next;
    }
    return nullptr;          // ikke fundet
}

```

Insert
```
void insert(const Key& k, const Value& v) {
    int idx = h(k);

    // tjek om nøglen allerede findes → evt. opdater
    Entry* curr = table[idx];
    while (curr != nullptr) {
        if (curr->key == k) {
            curr->value = v; // opdater eksisterende
            return;
        }
        curr = curr->next;
    }

    // ellers: lav ny node og sæt den forrest i kæden
    Entry* e  = new Entry;
    e->key    = k;
    e->value  = v;
    e->next   = table[idx];
    table[idx] = e;
}

```

Delete
```
bool erase(const Key& k) {
    int idx = h(k);

    Entry* curr = table[idx];
    Entry* prev = nullptr;

    while (curr != nullptr) {
        if (curr->key == k) {
            if (prev == nullptr)
                table[idx] = curr->next;  // første i listen
            else
                prev->next = curr->next;  // midt eller sidst

            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;   // ikke fundet
}


```
