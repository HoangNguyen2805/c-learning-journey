/*
Practice 5.11.1 - Generic Insertion Sort with Pluggable Comparators

Problem:
Build ONE sort function that can order an array of strings three ways,
selected by command-line flag:

    ./gsort apple Banana cherry        -> alphabetical (strcmp order)
    ./gsort -n 100 25 3                -> numeric (atoi/atof order)
    ./gsort -l elephant ox cat         -> by string length

Requirements:
- One sort: void isort(char *v[], int n, int (*comp)(char *, char *));
- Three comparators, all with the strcmp contract (<0, 0, >0):
    int alphacmp(char *a, char *b);   // write yourself, pointer style
    int numcmp(char *a, char *b);     // K&R version, use atof
    int lencmp(char *a, char *b);     // write your own strlen too
- Sort argv[...] pointers in place, then print one per line.
- The sort body must contain ZERO knowledge of the comparison rule.

DSA/Algorithm Focus: insertion sort + strategy pattern (comparator injection)
Best approach: insertion sort shifting pointers; comparator called via (*comp)(a,b).
Complexity: O(k^2) comparisons, O(1) extra space; each comparison O(m) for length m.
Constraints: no qsort, no strcmp/strlen from <string.h>.

Hints (Socratic):
- Which single line in your sort decides the ordering? What flows through it?
- If you add a 4th ordering next week, which functions change and which don't?
- Where should the flag check live so main picks the comparator ONCE, before sorting?
*/

#include <stdio.h>
#include <stdlib.h>

void isort(char *v[], int n, int (*comp)(char *, char *));
int alphacmp(char *a, char *b);
int numcmp(char *a, char *b);
int lencmp(char *a, char *b);

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}

void isort(char *v[], int n, int (*comp)(char *, char *)){
    // Student writes code here
}

int alphacmp(char *a, char *b){
    // Student writes code here
    return 0;
}

int numcmp(char *a, char *b){
    // Student writes code here
    return 0;
}

int lencmp(char *a, char *b){
    // Student writes code here
    return 0;
}
