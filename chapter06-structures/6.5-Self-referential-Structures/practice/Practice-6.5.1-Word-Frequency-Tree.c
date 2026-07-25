/*
Practice 6.5.1 - Word Frequency Tree  [FROM K&R - 6.5 main program]

Problem:
The full book program, from stdin to sorted report:

    ./wordfreq < some_text.txt

Requirements:
- struct tnode with word/count/left/right exactly as in the lesson.
- Reuse your getword from 6.3/6.4 practices.
- Implement yourself (no peeking at the lesson file while typing):
      struct tnode *addtree(struct tnode *, char *);
      void treeprint(struct tnode *);
      struct tnode *talloc(void);
      char *mystrdup(char *);
- main: root=NULL; loop getword; only words starting with a letter go
  into the tree; print the sorted frequency table at EOF.
- Add treefree(root) before return - children first!
- Bonus: also print the count of DISTINCT words (recursive treesize).

DSA/Algorithm Focus: binary search tree - insert, in-order traversal, post-order free
Best approach: recursive addtree; the return-and-reassign linking pattern.
Complexity: O(n log n) average build for n words, O(n^2) worst (sorted input);
space O(d) for d distinct words + O(height) recursion stack.
Constraints: check malloc for NULL (print to stderr and exit(1)); MAXWORD 100.

Hints (Socratic):
- Trace addtree on the 3rd insertion of "the" - which branch runs?
- Which single line makes a NEW node become its parent's child?
- Why is the *first* getword'd character check (isalpha) done in main,
  not inside addtree?
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *w);
void treeprint(struct tnode *p);
struct tnode *talloc(void);
char *mystrdup(char *s);
int getword(char *word, int lim);

int main(){
    // Student writes code here
    return 0;
}
