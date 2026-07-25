/*
Practice 8.4.2 - tail -c: last N bytes, the smart way

Problem:
Print the final N bytes of a file WITHOUT reading the whole file:

    ./tailc 100 big.log        # last 100 bytes
    ./tailc 100 < big.log      # BONUS trap: see below

Requirements:
- N = atoi(argv[1]); file = argv[2]; open O_RDONLY with -1 check.
- Find the size with lseek(fd, 0L, 2) (no reading!). If N >= size,
  rewind and print everything.
- Otherwise lseek to size - N and copy the rest to stdout in BUFSIZ
  chunks (8.2 loop).
- Efficiency proof: also print to stderr "seeked past X bytes, read Y" -
  for a big file X should dwarf Y.
- The stdin BONUS: when reading from a pipe (./gen | ./tailc 100 -),
  lseek FAILS (-1) - pipes aren't seekable! Detect that and fall back to
  a ring buffer: keep only the last N bytes seen in a malloc'd buffer of
  size N, using an index that wraps with %. Print it in correct order
  at EOF (two writes: [idx..N) then [0..idx)).

DSA/Algorithm Focus: seek arithmetic + RING BUFFER (circular buffer) fallback
Best approach: seekable: O(N) work regardless of file size (the win!);
pipe path: O(total) read but O(N) memory - the classic streaming tail.
Complexity: seek path O(N); ring path O(total) time, O(N) space.
Constraints: the ring buffer wrap must use modular indexing - no shifting
bytes around; handle N=0 and empty files.

Hints (Socratic):
- Why does the ring buffer's "start" live at idx after filling wraps?
  Draw 8 bytes into a 5-buffer and see where oldest lands.
- How do you detect "not seekable" precisely? (Which call's -1?)
- Two writes reconstruct order - what are the exact (ptr, len) pairs?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}
