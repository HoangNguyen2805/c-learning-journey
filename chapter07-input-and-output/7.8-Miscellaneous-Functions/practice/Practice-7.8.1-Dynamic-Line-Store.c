/*
Practice 7.8.1 - Dynamic Line Store (malloc-backed readlines)

Problem:
Read ALL lines of stdin into heap memory, then print them REVERSED
(last line first) and report stats:

    ./revlines < poem.txt
    <lines in reverse>
    ---
    lines=12 chars=340 heap_bytes~=436

Requirements:
- char *lineptr[MAXLINES] of pointers (5.6 style), MAXLINES 1000.
- Read with fgets into a scratch buffer; strip '\n'; copy into a
  malloc(strlen+1) block (your own heapdup(char*) helper); store pointer.
- Reverse print WITHOUT rearranging the array (loop backwards).
- Stats: count lines and total chars; estimate heap bytes as
  sum(strlen+1) - accumulate as you allocate.
- free EVERY line at the end (loop). Then set pointers NULL? Discuss in
  a one-line comment whether it matters here.
- On malloc failure mid-file: report to stderr, print what you HAVE,
  still free everything, exit(1).

DSA/Algorithm Focus: pointer array + heap strings (the readlines pattern
that 5.6 faked with a static buffer - now with real allocation)
Best approach: O(n) read, O(n) print, O(n) free.
Complexity: O(total chars) time and heap space.
Constraints: no alloc() from ch5; scratch buffer MAXLEN 1000; overlong
lines: store first 999 chars, count the rest toward chars (document).

Hints (Socratic):
- Why can't you store the scratch buffer's address in lineptr directly?
  (You proved this in 6.5 example 8 - restate it for yourself.)
- heapdup's contract: what EXACTLY does the caller now own?
- Freeing in a forward loop after printing backwards - any problem? Why not?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN 1000

char *heapdup(const char *s);

int main(){
    // Student writes code here
    return 0;
}

char *heapdup(const char *s){
    // Student writes code here
    return NULL;
}
