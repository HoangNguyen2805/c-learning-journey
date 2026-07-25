/*
Practice 8.5.1 - The Writing Half: _flushbuf, my_fflush, my_fclose
[FROM K&R - Exercise 8-3]

Problem:
The lesson gave you the READ side. Build the WRITE side of mini-stdio:

  int  _flushbuf(int c, MYFILE *fp);   // called by my_putc when buffer full
  int  my_fflush(MYFILE *fp);          // write out pending buffer now
  int  my_fclose(MYFILE *fp);          // flush + close(fd) + free(base) + clear slot

  #define my_putc(x,p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x),p))

_flushbuf duties (mirror _fillbuf):
  - reject if not _WRITE or if _ERR set -> EOF
  - lazy-allocate base (bufsize 1 if _UNBUF)
  - if a buffer exists and holds data: write() it; short/failed write -> _ERR
  - reset ptr=base, cnt=bufsize-1; stash c at *ptr++ ... think through the
    exact sequencing! (cnt bookkeeping is THE puzzle of this exercise)
main test:
  my_fopen a file "w"; my_putc a few thousand chars (verify: how many
  write() syscalls? count them in _flushbuf and report); my_fclose; then
  reopen with the REAL fopen and verify contents+length. Also prove that
  omitting my_fclose loses the tail (do it once, show, restore).

DSA/Algorithm Focus: buffer flush protocol; the write-side state machine
Best approach: symmetric inversion of _fillbuf; all state in the MYFILE.
Complexity: O(n) chars, O(n/BUFSIZ) syscalls.
Constraints: copy the lesson's MYFILE/enum/_my_iob scaffolding into this
file (self-contained); my_fclose must work on my_stdout too (flush only,
fd 1 stays open - why?).

Hints (Socratic):
- On the very FIRST my_putc, cnt is 0, so _flushbuf runs with an empty,
  unallocated buffer. What must it NOT do in that case (write zero bytes?)?
- After a flush, why cnt = bufsize - 1 and not bufsize? (Where did c go?)
- Why must my_fclose flush BEFORE close? What does the order swap lose?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Student copies MYFILE scaffolding here, then implements the write side

int main(){
    // Student writes code here
    return 0;
}
