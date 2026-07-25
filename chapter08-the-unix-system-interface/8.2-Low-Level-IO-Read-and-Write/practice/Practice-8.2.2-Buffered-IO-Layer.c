/*
Practice 8.2.2 - Your Own Buffered I/O Layer

Problem:
Build the reading AND writing halves of a mini-stdio over raw syscalls:

  int  b_getc(void);           // buffered read from fd 0 (K&R's version)
  int  b_putc(int c);          // buffered write to fd 1 - YOU design it
  void b_flush(void);          // force out anything pending
  (state: static buffers, pointers/counts - mirror the getchar pattern)

Then use ONLY b_getc/b_putc to implement the classic filter:
squeeze repeated blanks to one, expand tabs to 4 spaces - and PROVE the
buffering by printing (to fd 2) the number of raw read() and write()
syscalls performed (count them where they happen).

    echo "a    b\tc" | ./bio
    a b    c
    [stats to fd2] reads=1 writes=1

Requirements:
- b_putc buffers BUFSIZ bytes; auto-flushes when full; main MUST call
  b_flush() before exit (what data dies otherwise? demonstrate by
  commenting it out once - describe in a comment).
- EOF handling: b_getc returns EOF; the cast rule from the lesson applies.

DSA/Algorithm Focus: buffer management - the core systems pattern
(producer/consumer against a fixed buffer)
Best approach: symmetric to the lesson's getchar; putc side inverts it:
fill buf, write(1, buf, count) when count==BUFSIZ or on flush.
Complexity: O(n) bytes, O(n/BUFSIZ) syscalls, O(BUFSIZ) space each side.
Constraints: no stdio for DATA (printf allowed only for the fd-2 stats
via dprintf or sprintf+write).

Hints (Socratic):
- Read side tracks "how many left"; write side tracks what instead?
- Why does the READ side never need a flush concept?
- Where's the bug if b_putc flushes when count > BUFSIZ instead of ==?
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int b_getc(void);
int b_putc(int c);
void b_flush(void);

int main(){
    // Student writes code here
    return 0;
}

int b_getc(void){
    // Student writes code here
    return EOF;
}

int b_putc(int c){
    // Student writes code here
    return c;
}

void b_flush(void){
    // Student writes code here
}
