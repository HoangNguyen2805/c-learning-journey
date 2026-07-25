/*
Practice 8.7.2 - bfree + Allocator Telemetry  [FROM K&R - Exercise 8-8]

Problem:
Again starting from the lesson scaffolding:

1. int my_bfree(void *p, unsigned n);
   Donate an ARBITRARY block of n bytes (a static array, say) into the
   free list. Steps: if n is too small to hold even a header + 1 unit,
   reject (return 0). Otherwise: place a Header at p (alignment! - see
   hints), set its size in units (rounding DOWN this time - why the
   opposite of malloc?), then my_free(header+1). Return units added.

2. Telemetry:
   void heap_stats(void);   // walks the free list, prints:
     blocks=K  free_units=U  largest=L  (and, tracked in counters:
     total_mallocs, total_frees, morecore_calls)
   Update the counters inside the allocator functions.

3. Fragmentation demo in main:
   - malloc 8 blocks of 100 bytes; free every SECOND one; heap_stats
     (several small holes - can a 300-byte malloc succeed? try!)
   - free the rest; heap_stats (holes coalesce - now can it?)
   - donate a static char pool[2048] via my_bfree; heap_stats; show a
     big malloc now succeeding that failed before.

DSA/Algorithm Focus: free-list surgery + fragmentation measurement -
you're building the observability real allocators have
Best approach: bfree reuses my_free wholesale (like morecore does);
stats is one circular-list walk.
Complexity: bfree O(F) via free's scan; stats O(F).
Constraints: pool donated via bfree must ACTUALLY be handed out by later
mallocs - verify by address range check, print the proof.

Hints (Socratic):
- Alignment: p may be an odd address. Real code aligns p UP to the next
  sizeof(Header) boundary (and shrinks n accordingly). Implement with
  arithmetic on (unsigned long)p - what expression rounds an address up?
- Why round n DOWN to units here, when malloc rounded UP?
- After the interleaved frees, WHY can't first-fit satisfy 300 bytes
  even though total free bytes exceed it? Say it precisely - your
  heap_stats "largest" field IS the answer.
*/

#include <stdio.h>
#include <string.h>

// Student copies the Header/arena scaffolding here, then extends

int main(){
    // Student writes code here
    return 0;
}
