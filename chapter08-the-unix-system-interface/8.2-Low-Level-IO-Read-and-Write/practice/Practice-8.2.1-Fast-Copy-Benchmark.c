/*
Practice 8.2.1 - Copy Speed vs Buffer Size  [FROM K&R - 8.2 + Exercise 8-1 spirit]

Problem:
Measure WHY buffering matters. A copier whose chunk size is an argument:

    ./fcopy 1 < big.txt > /dev/null
    copied 1048576 bytes in 1048576 read() calls (bufsize 1)
    ./fcopy 4096 < big.txt > /dev/null
    copied 1048576 bytes in 257 read() calls (bufsize 4096)

Requirements:
- bufsize = atoi(argv[1]); validate 1 <= bufsize <= 65536, else usage
  to fd 2 and exit(2).
- Copy fd 0 to fd 1 with read/write of bufsize chunks; the report line
  (bytes + calls + bufsize) goes to fd 2 (why? your 8.1.1 answer again).
- Handle SHORT WRITES correctly: write may write fewer bytes than asked -
  loop until the whole chunk is out (this is the pro move):
      while (off < n) off += write(1, buf + off, n - off);
  (plus error check for negative).
- Generate a test file: head -c 1000000 /dev/urandom > big.txt
  and verify with cmp after copying to a real file.

DSA/Algorithm Focus: buffering/amortization; correctness under partial ops
Best approach: O(n) bytes either way - the syscall COUNT is what changes.
Complexity: O(n) time, O(bufsize) space; syscalls n/bufsize.
Constraints: heap-allocate the buffer (malloc) since bufsize is dynamic;
free it; check malloc NULL.

Hints (Socratic):
- Why is each syscall expensive relative to a memory copy? (crossing what
  boundary?)
- The short-write loop: what pointer arithmetic feeds write the REMAINDER?
- Time it: bash's `time ./fcopy 1 < big.txt > /dev/null` vs 4096. Record
  the numbers in a comment. Surprised?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}
