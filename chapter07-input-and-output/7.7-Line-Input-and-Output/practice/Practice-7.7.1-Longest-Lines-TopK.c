/*
Practice 7.7.1 - Top-K Longest Lines

Problem:
Print the K longest lines of stdin (K from argv, default 3):

    ./longk 2 < novel.txt
    ranked #1 (94 chars): It was the best of times...
    ranked #2 (81 chars): ...

Requirements:
- fgets into char line[MAXLINE]; MAXLINE 1000; strip the newline before
  storing/measuring.
- Keep ONLY the top K seen so far: array of struct { int len; char text[MAXLINE]; }
  size MAXK(10). Maintain it SORTED descending by len at all times: for each
  new line, if it beats the current K-th, insert at its sorted position and
  shift the tail down (dropping the last).
- Chopped lines (no '\n' read - your Mini-Quiz 7.7 Q6/Q7 knowledge!):
  treat continuation pieces as part of the SAME line for length purposes -
  accumulate the length, keep only the first MAXLINE-1 chars for display.
- Ties: earlier line wins (stable) - what insert comparison gives that?

DSA/Algorithm Focus: top-K selection via bounded insertion (poor man's heap)
Best approach: O(n * K) time - fine for small K; a heap would be O(n log K)
(note the tradeoff in a comment).
Complexity: O(nK) time, O(K * MAXLINE) space - INDEPENDENT of file size.
Constraints: two-pass approaches and storing all lines are FORBIDDEN -
the point is bounded memory over unbounded input.

Hints (Socratic):
- Why does keeping the array always-sorted make "does it qualify?" an O(1)
  check against which single element?
- Insertion: scan from where, shift which direction, drop what?
- What does > vs >= in your comparison decide about tie stability?
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000
#define MAXK 10

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}
