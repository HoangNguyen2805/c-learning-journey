/*
Practice 8.1.1 - Raw Echo (no stdio for data!)

Problem:
Re-implement the Chapter 1 copy program using ONLY the raw descriptor
layer for actual data: read(0, ...) and write(1, ...), one char at a time
for now (8.2 fixes the efficiency):

    ./rawecho < input.txt > copy.txt
    diff input.txt copy.txt        # must be identical

Additionally:
- Count chars and newlines as you copy; AFTER the copy, report the stats
  as a message on fd 2 (write() it - build the message with sprintf into
  a buffer first, then write(2, buf, strlen(buf))).
- Why fd 2 for the stats? Answer in a comment (think: copy.txt purity).

DSA/Algorithm Focus: byte-stream processing at the syscall layer
Best approach: while (read(0, &c, 1) == 1) write(1, &c, 1); counters inline.
Complexity: O(n) time - but n syscalls! (note this; 8.2 practice fixes it)
Constraints: NO printf/putchar for the copied data; stats line may use
sprintf for formatting only.

Hints (Socratic):
- read returns how many bytes it actually got. What return value means EOF,
  and what does a negative mean?
- write(1, &c, 1): why the & on a char variable?
- If you accidentally wrote stats to fd 1, what would diff show?
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    // Student writes code here
    return 0;
}
