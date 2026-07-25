/*
Practice 8.5.2 - my_fseek: seeking WITH a buffer in the way
[FROM K&R - Exercise 8-4]

Problem:
  int my_fseek(MYFILE *fp, long offset, int origin);
Return 0 ok, -1 error. Must cooperate with the buffering - the hard part!

Why it's tricky: after buffered reads, the fd's REAL position is ahead of
what the user has consumed (a whole chunk was read; cnt chars remain
unconsumed). A naive lseek(fp->fd, offset, origin) with origin=1 would be
off by exactly cnt bytes!

Rules to implement:
  READ mode:
    - origin 1 (relative): adjust -> lseek(fd, offset - fp->cnt, 1)
    - origin 0/2: plain lseek is fine
    - on success: invalidate the buffer (cnt = 0) so the next my_getc
      refills from the new position
  WRITE mode:
    - flush pending output FIRST (your 8.5.1 my_fflush), then plain lseek
  Any mode: lseek returning -1 -> return -1, don't touch state.

main test (read side): open a known file; my_getc 5 chars; my_fseek(+0,1)
should land the TRUE position at char 5 - verify by my_getc-ing char 6.
Then my_fseek(0,0) and re-read start. (write side): putc some, fseek back,
overwrite, close, verify with real stdio.

DSA/Algorithm Focus: cache-coherence in miniature - keeping a buffer
consistent with an external position pointer
Best approach: exactly the rules above; the insight is the -cnt correction.
Complexity: O(1) plus any flush.
Constraints: self-contained file with the MYFILE scaffolding + your
8.5.1 write half pasted in (yes, really - integration is the point).

Hints (Socratic):
- Draw it: file pos P after read of BUFSIZ; user consumed k. Where does
  the USER think they are? What's P minus that?
- Why does invalidating (cnt=0) suffice for read mode - what does the
  next getc do that makes it correct?
- Which of the three origins does NOT need the cnt correction, and why
  does one of them need nothing at all?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Student copies MYFILE scaffolding + write half here, then adds my_fseek

int main(){
    // Student writes code here
    return 0;
}
