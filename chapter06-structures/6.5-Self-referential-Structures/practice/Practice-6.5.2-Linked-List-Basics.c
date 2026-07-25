/*
Practice 6.5.2 - Singly Linked List from Scratch

Problem:
The OTHER famous self-referential structure. Build a linked list of ints:

  struct node { int val; struct node *next; };

Implement:
  struct node *push_front(struct node *head, int v);   // O(1) - returns new head
  struct node *push_back(struct node *head, int v);    // O(n) - walk to tail
  int  list_len(struct node *head);
  void list_print(struct node *head);                  // 3 -> 1 -> 4 -> NULL
  struct node *list_reverse(struct node *head);        // ITERATIVE, in place
  struct node *list_delete(struct node *head, int v);  // remove FIRST match
  void list_free(struct node *head);

main test script:
  push_front 3,2,1  -> print (1 -> 2 -> 3 -> NULL)
  push_back 4,5     -> print
  reverse           -> print (5 -> 4 -> 3 -> 2 -> 1 -> NULL)
  delete 3, delete 99 (absent - list unchanged) -> print + length
  free everything

DSA/Algorithm Focus: singly linked list - THE pointer-manipulation workout
Best approach: reverse with three pointers (prev, cur, next); delete with
either a prev pointer or the pointer-to-pointer trick.
Complexity: push_front O(1); push_back/len/print/reverse/delete O(n); O(1) space.
Constraints: iterative reverse (no recursion); malloc-check every node;
no arrays anywhere.

Hints (Socratic):
- In reverse: which pointer must you save BEFORE rewiring cur->next? Why?
- Deleting the HEAD is a special case for the prev-pointer approach.
  How does returning the (possibly new) head - like addtree did - solve it?
- After list_free(head), what should the caller do with head? What bug
  class does that prevent?
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *push_front(struct node *head, int v);
struct node *push_back(struct node *head, int v);
int list_len(struct node *head);
void list_print(struct node *head);
struct node *list_reverse(struct node *head);
struct node *list_delete(struct node *head, int v);
void list_free(struct node *head);

int main(){
    // Student writes code here
    return 0;
}
