/*
Practice 6.7.1 - Refactor the BST with Typedef

Problem:
Take your Practice 6.5.1 word-frequency tree and refactor it so the words
"struct tnode" appear EXACTLY ONCE in the whole file (inside the typedef):

  typedef struct tnode *Treeptr;
  typedef struct tnode { ... } Treenode;

All signatures change accordingly:
  Treeptr addtree(Treeptr p, char *w);
  void    treeprint(Treeptr p);
  Treeptr talloc(void);
  void    treefree(Treeptr p);

Also add, using typedef'd types only:
  typedef void (*Visitor)(Treeptr p);       // called on each node
  void treewalk(Treeptr p, Visitor visit);  // in-order, calls visit(node)
and reimplement treeprint as a one-line wrapper: treewalk(root, print_one).

DSA/Algorithm Focus: BST + visitor pattern (traversal decoupled from action)
Best approach: treewalk is your old treeprint with printf swapped for (*visit)(p).
Complexity: unchanged - O(n) traversal, O(height) stack.
Constraints: grep your file: "struct tnode" must appear exactly once.

Hints (Socratic):
- Which of the two typedefs must come first, and why does a forward
  "typedef struct tnode *Treeptr;" work before the struct body exists?
- What OTHER visitor could you pass to treewalk to count nodes? To find
  the max count? (Sketch them - notice treewalk never changes.)
- Why does Visitor take Treeptr instead of char* - what flexibility is kept?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

// Student writes typedefs here

int getword(char *word, int lim);

int main(){
    // Student writes code here
    return 0;
}
