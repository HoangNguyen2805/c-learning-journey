/*
Practice 7.7.2 - Simple diff  [FROM K&R - Exercise 7-6]

Problem:
Compare two files line by line; print the FIRST place they differ:

    ./sdiff a.txt b.txt
    files differ at line 17:
    < the line from a.txt
    > the line from b.txt

If identical: "files are identical (N lines)". If one file is a prefix of
the other: "files identical until a.txt ends at line N" style message.

Requirements:
- fopen both ("r"), NULL checks to stderr with exit(2) (7.6 manners).
- Two synchronized fgets loops - advance BOTH each iteration; compare with
  strcmp. Buffers char la[MAXLINE], lb[MAXLINE].
- Handle ALL end combinations: both end together / a ends first / b ends
  first / lines differ. Enumerate them in a comment BEFORE coding.
- Exit status: 0 identical, 1 different (diff's real convention!).
- Long-line honesty: with MAXLINE 1000, a 2000-char identical line compares
  as two pieces - does your logic still work? Explain in a comment why
  synchronized chopping keeps the comparison valid.

DSA/Algorithm Focus: parallel stream iteration (two-pointer over files)
Best approach: single pass, O(min(A,B)) lines, O(1) memory.
Complexity: O(total chars) time, O(MAXLINE) space.
Constraints: no storing whole files; first difference only (real diff's
LCS algorithm is a later adventure - note this in a comment).

Hints (Socratic):
- Your loop condition must express "both got a line". What are the four
  states after the two fgets calls, and which loop exit handles which?
- Why compare with strcmp instead of == ? (Ch5 flashback.)
- Which file's line does "<" conventionally tag? Match real diff.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}
