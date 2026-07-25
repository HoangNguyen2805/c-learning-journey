/*
Practice 8.6.2 - du + find: biggest files in a tree

Problem:
Walk a directory tree and report the TOP 5 largest regular files plus
per-extension totals:

    ./biggest projects/
    TOP 5:
       1.  1048576  projects/data/big.bin
       ...
    BY EXTENSION:
       .c      12 files   48210 bytes
       .txt     3 files    1204 bytes
       (none)   2 files     880 bytes
    total: 17 files, 1098870 bytes

Requirements:
- Reuse the dirwalk(dir, fcn) pattern EXACTLY as K&R wrote it - your
  callback does all the accumulation. (Constraint: dirwalk itself may
  not be modified once written - that's the point of callbacks!)
- Top-5: your 7.7.1 bounded-insertion technique on {long size; char
  path[MAX_PATH];} - stored via struct assignment.
- Extensions: strrchr(name, '.') AFTER the last '/' (careful: "a.b/c"
  has no extension! check which comes later). Tally in a linear table of
  {char ext[16]; int n; long bytes;} - up to 64 distinct, linear search
  (a hash table (6.6) is overkill at this size - note the judgment call).
- All state reachable by the callback: file-static variables are
  acceptable HERE - write one comment on why callbacks force this
  (what would you change in dirwalk's signature to avoid statics?).

DSA/Algorithm Focus: DFS + top-K selection + frequency table - three
patterns cooperating in one tool
Best approach: single walk O(N); each file does O(5) top-K + O(64) ext scan.
Complexity: O(N * 69) ~ O(N) time; O(1) space beyond the tables.
Constraints: symlinks may loop - use lstat instead of stat and skip
symlinks entirely (research the one-line difference; cite it in a comment).

Hints (Socratic):
- Why does "extension after the last slash" need BOTH strrchr('.') and
  strrchr('/') compared as pointers?
- The void(*fcn)(char*) signature can't carry your tables. What richer
  signature could? (void*, anyone? That's how real libraries do it.)
- Directories have sizes too (stat says so) - why exclude them from totals?
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *));

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}

void dirwalk(char *dir, void (*fcn)(char *)){
    // Student writes code here
}
