Nogle bolde vil havne i samme spand og andre vil være tomme --> ligesom med kollisioner i hashing.
![[Pasted image 20251214143847.png]]
**case 1: single random choice**
	each ball picks ONE random bin
	Hvor stort antal bolde kommer der maks i hver spand? *altså hvordan spandende skal dimensioneres*
	maximum load (with high probability): 
	$L_1 \approx ln(N)/ln(ln(N))$
	![[Pasted image 20251214143506.png]]
	*Så kan man vælge at der skal være plads til 5 bolde i hver spand, for at undgå at der kommer overflow!*

**case 2: Power of Two Choices**
	each ball picks TWO random bins
	goes into the less loaded one
	max load (with high probability):
	$L_2 \approx ln(ln(N)/ln(2)+ O(1))$
	![[Pasted image 20251214143809.png]]
	*vælger vi 4 bolde er vi på den sikre side!*


**Påstand:** Som N vokser:
	1 bin: hurtigt voksende ubalance
	2 bins: ubalancen gror meget langsommere

**Load balancing example:**
![[Pasted image 20251214144149.png]]
**Balls N' Bins  er et load-balancing problem:**

*Load factor [lambda] is equal to the number of elements in the table divied by the table size 
	--> should always be less than 0.5
![[Pasted image 20251214153640.png]]

![[Pasted image 20251214150319.png]]
![[Pasted image 20251214153442.png]]
