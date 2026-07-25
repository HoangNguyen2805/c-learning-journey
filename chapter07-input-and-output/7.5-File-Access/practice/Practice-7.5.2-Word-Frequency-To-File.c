/*
Practice 7.5.2 - Word Frequency Report to File (grand integration)

Problem:
Combine Ch6's BST with Ch7's files:

    ./wordreport input.txt report.txt

- Read words from input.txt (fopen "r"; your getword adapted to take a
  FILE* : int getwordf(char *word, int lim, FILE *fp)).
- Build the 6.5 word-frequency BST (addtree with mystrdup etc.).
- Write to report.txt (fopen "w"):
      header line:  words analyzed from input.txt
      one "%4d %s" line per word, alphabetical (in-order traversal
      needs the FILE* - thread it through: treeprintf(root, fp))
      footer:       total=N distinct=D
- Free the tree; close both files; handle EVERY fopen failure with a
  message and exit(1).

DSA/Algorithm Focus: BST reuse + I/O plumbing (threading a FILE* through recursion)
Best approach: identical algorithms as 6.5 - only the I/O endpoints change.
That's the lesson: good structure makes retargeting trivial.
Complexity: O(W log D) average build; O(D) print; space O(D).
Constraints: total word count needs an extra counter - where does it live
without a global? (Pass int* or return counts - your call, justify it.)

Hints (Socratic):
- getword used getch/ungetch on stdin. What are the FILE* equivalents?
  (getc/ungetc - check ungetc's signature: which arg order?)
- treeprintf differs from treeprint by ONE parameter. Where does fp go
  in the recursive calls?
- Why open the OUTPUT file only AFTER input parsing succeeds? What
  half-finished artifact does that ordering prevent?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int getwordf(char *word, int lim, FILE *fp);

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}

int getwordf(char *word, int lim, FILE *fp){
    // Student writes code here
    return 0;
}
