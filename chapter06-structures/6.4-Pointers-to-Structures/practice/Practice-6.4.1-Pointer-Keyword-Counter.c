/*
Practice 6.4.1 - Keyword Counter, Pointer Edition  [FROM K&R - 6.4]

Problem:
Convert YOUR Practice 6.3.1 keyword counter to pure pointer style:

- binsearch returns struct key * (NULL if absent):
      struct key *binsearch(char *word, struct key *tab, int n);
- main's hot loop becomes:
      if (... && (p = binsearch(word, keytab, NKEYS)) != NULL)
          p->count++;
- The report loop walks:  for (p = keytab; p < keytab + NKEYS; p++)
- ZERO [ ] subscripts allowed anywhere except the keytab initializer
  and inside getword's buffer filling.

DSA/Algorithm Focus: binary search with half-open pointer ranges
Best approach: low=&tab[0], high=&tab[n], while (low < high),
mid = low + (high-low)/2. O(W log K) total.
Complexity: same as index version - the change is idiom, not asymptotics.
Constraints: reuse your getword; keep the table sorted.

Hints (Socratic):
- The index version's high starts at n-1 with low <= high. The pointer
  version starts high at &tab[n] with low < high. Why must BOTH changes
  happen together?
- Why does the not-found case fall out of the loop naturally?
- After finding p, what expression gives its INDEX if you ever need it?
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key {
    char *word;
    int count;
};

struct key *binsearch(char *word, struct key *tab, int n);
int getword(char *word, int lim);

int main(){
    // Student writes code here
    return 0;
}

struct key *binsearch(char *word, struct key *tab, int n){
    // Student writes code here
    return NULL;
}

int getword(char *word, int lim){
    // Student writes code here
    return 0;
}
