# Mini-Quiz 8.7 - A Storage Allocator

1. Draw (in text) the layout of one allocated block: where is the header, what two things does it store, and where does the user's pointer aim?

2. What is the `Align x` member of the header union FOR, given the code never reads or writes it?

3. Sizes are counted in "units". Decode the formula `nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1` — what does each part accomplish? Compute nunits for nbytes=1 and nbytes=33 with 16-byte Headers.

4. Why is the free list kept sorted by ADDRESS rather than, say, by size or insertion order? What operation depends on it?

5. Explain the "allocate the tail end" branch: which block stays on the list, which is returned, and why does this need NO pointer relinking?

6. What does `p == freep` detect in malloc's loop, and what happens next?

7. In morecore: why request at least NALLOC units, what does sbrk return on failure, and what's clever about inserting the new memory with `free((void*)(up+1))`?

8. In free, what does `bp = (Header *)ap - 1` compute, and why is it exactly right?

9. Walk both coalescing tests: what does `bp + bp->s.size == p->s.ptr` mean physically, and what three assignments perform the merge with the upper neighbor?

10. Name the failure mode coalescing fights. Describe the heap state that arises WITHOUT it after many mixed malloc/free cycles, and why a big request can then fail despite plenty of total free bytes.
