/*
Practice 8.7.1 - calloc + Hardened malloc/free  [FROM K&R - Exercises 8-6, 8-7]

Problem:
Start from the lesson's my_malloc/my_free (arena version - copy the
scaffolding in). Add:

1. void *my_calloc(unsigned n, unsigned size);
   n objects of `size` bytes, ZEROED. Implement by calling my_malloc and
   clearing (your own byte loop or memset - justify choice in a comment).
   Return NULL if my_malloc does.

2. Hardening (Exercise 8-7): the originals trust the caller blindly. Add:
   - my_malloc(0) -> return NULL (decide + document; what does real
     malloc do?)
   - my_malloc larger than the whole arena -> NULL immediately (compute
     the unit ceiling - no point scanning).
   - my_free(NULL) -> harmless no-op (real free guarantees this!).
   - my_free of a pointer whose header size field is 0 or absurdly big
     (> ARENA_UNITS) -> print "my_free: corrupt or invalid block" to
     stderr and return WITHOUT touching the list.
   - BONUS sanity: keep a magic number in the header (add a field? or
     encode in size's high bits?) set by malloc, checked+cleared by free -
     catches double-free and wild pointers. Describe your scheme.

main: test calloc zeroing (allocate ints, verify all 0), calloc overflow
n*size wrapping (research: how do you detect multiplication overflow in
unsigned arithmetic? implement the check!), free(NULL), a deliberate
double-free caught by your magic scheme.

DSA/Algorithm Focus: allocator invariants + defensive API design
Best approach: checks are O(1) gates before the original logic.
Complexity: unchanged asymptotics; calloc adds O(bytes) clear.
Constraints: original malloc/free logic untouched inside the guards.

Hints (Socratic):
- calloc(n, size): if n*size overflows unsigned, you allocate a TINY
  block but the caller thinks it's huge. What comparison detects the
  wrap BEFORE multiplying badly? (Hint: divide.)
- Where EXACTLY in free must the magic check run - before which line?
- Zeroing bytes vs zeroing "n objects of size s": any difference? Why not?
*/

#include <stdio.h>
#include <string.h>

// Student copies the Header/arena scaffolding here, then extends

int main(){
    // Student writes code here
    return 0;
}
