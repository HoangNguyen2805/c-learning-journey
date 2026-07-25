/*
Practice 6.3.2 - High Score Table (insert + sort + search)

Problem:
Maintain a game leaderboard as an array of structs:

  struct entry { char name[16]; int score; };
  struct entry board[MAXP];   int n = 0;   // rows in use

Read lines "name score" from stdin (scanf("%15s %d", ...)) until EOF, then:
  1. INSERTION SORT the board by score DESCENDING (ties: name ascending
     via strcmp - a two-key comparison like Practice 6.1.2).
  2. Print ranked table:  1. cyrus  150
  3. BINARY SEARCH by exact score: find any entry with score 95 and report
     its rank, or "not found". (Careful: the array is DESCENDING - flip
     your low/high logic accordingly.)

DSA/Algorithm Focus: insertion sort on records + binary search on non-ascending order
Best approach: shift whole structs (struct assignment) while walking left.
Complexity: sort O(n^2) worst, search O(log n); O(1) extra space.
Constraints: MAXP 50; guard overflow when n == MAXP; no qsort.

Hints (Socratic):
- Your Ch3/Ch5 insertion sort moved ints or pointers. What single thing
  changes when the element type is a struct?
- Descending binary search: when a[mid].score > target, which side holds
  the target now?
- Why compare names ONLY when scores tie? What ordering property breaks otherwise?
*/

#include <stdio.h>
#include <string.h>

#define MAXP 50

struct entry {
    char name[16];
    int score;
};

int main(){
    // Student writes code here
    return 0;
}
