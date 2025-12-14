If the table gets too full, the running time for the operations will start taking too long,
and insertions might fail for open-addressing hashing with quadratic resolution. 
	This can happen if there are too many removals intermixed with insertions. 

**Solution:** build another table --> **twice as big** (with an associated new hash function) 
	...and scan down the entire original hash table, computing the new hash value for each
	(non-deleted) element and inserting it in the new table.

![[Pasted image 20251214155159.png]]

**EXAMPLE**
![[Pasted image 20251214155257.png]]
![[Pasted image 20251214155336.png]]


