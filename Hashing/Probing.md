## Linear Probing
er en _open-addressing_ teknik til hash-tabeller.  Hvis en plads er optaget, prøver vi den næste, og næste…   indtil vi finder en tom plads.

![[Pasted image 20260103162317.png]]
## Quadratic Probing
![[Pasted image 20251214084435.png]]**How Quadratic Probing is done?**

Let hash(x) be the slot index computed using the hash function.

- If the slot hash(x) % S is full, then we try (hash(x) + 1 * 1) % S.
- If (hash(x) + 1 * 1) % S is also full, then we try (hash(x) + 2 * 2) % S.
- If (hash(x) + 2 * 2) % S is also full, then we try (hash(x) + 3 * 3) % S.
- This process is repeated for all the values of i until an empty slot is found.

![[Pasted image 20251214104217.png]]

-