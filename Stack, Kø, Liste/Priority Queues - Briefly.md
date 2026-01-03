**Originates from the need to execute queues by a different principle than FIFO**
*Examples:* printjobs, CPU-scheduling, urgent orders
*Necessary Operations:* Insert() and deleteMin()
![[Pasted image 20251215092329.png]]
**Implementation:** 
![[Pasted image 20251215092348.png]]
# **buildHeap():** 

## percolatedown()/bubbleDown()/siftDown()
Du bruger bubbleDown, når elementet burde ligge længere nede i heap’en.
I en min-heap:
	tallet er blevet større end før
	
**Eksempler:**
- du fjerner roden (min-elementet), flytter sidste element op i roden  
    → det er ofte større end sine børn → boble ned
- du øger prioriteten (fx fra 10 til 50)  
    → 50 skal længere væk fra roden → boble ned  
    
*Billede mentalt:  “Elementet synker ned gennem træet.”*

## percolateUp()/bubbleUp()/siftUp()
Du bruger bubbleUp, når elementet burde ligge tættere på roden end hvor det står nu.
For en min-heap betyder det:
	 tallet er blevet mindre end før

**Eksempler:**
- du indsætter et nyt element i bunden  
    → det kan være bedre end sin forælder → boble op
- du sænker prioriteten (fx fra 50 til 10)  
    → 10 bør ligge højere → boble op

*Billede mentalt:  “Elementet kravler op mod roden.”*


timecomplexity?
	![[Pasted image 20251215092504.png]]
	

