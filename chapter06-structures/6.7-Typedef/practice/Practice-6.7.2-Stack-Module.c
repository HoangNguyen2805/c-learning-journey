/*
Practice 6.7.2 - Typedef'd Stack of Points

Problem:
Build a clean stack API where the user never sees implementation types:

  typedef struct { int x, y; } Point;
  typedef struct {
      Point items[MAXSTACK];
      int top;                  // index of next free slot
  } Stack;

API (all take Stack* so they can mutate):
  void  s_init(Stack *s);
  int   s_empty(const Stack *s);
  int   s_full(const Stack *s);
  int   s_push(Stack *s, Point p);   // 1 ok, 0 overflow
  int   s_pop(Stack *s, Point *out); // 1 ok, 0 underflow
  int   s_peek(const Stack *s, Point *out);

main: push (1,1),(2,4),(3,9),(4,16); peek; pop all while printing;
attempt one extra pop and show the graceful failure; then use the stack
to REVERSE a path: push points A->B->C, pop to print C->B->A.

DSA/Algorithm Focus: stack (LIFO) as a typedef'd abstract data type
Best approach: array-backed stack; top counter; all ops O(1).
Complexity: O(1) per operation, O(MAXSTACK) space.
Constraints: MAXSTACK 16; NO global stack variable - main owns a local
Stack and passes &s everywhere; out-parameters for pop/peek results.

Hints (Socratic):
- Why do pop/peek return status ints and deliver the Point via pointer,
  instead of returning the Point directly? What can't a return value say?
- s->top: does it mean "last used" or "next free"? Pick one, write it in
  a comment, and keep every function consistent with it.
- Why does reversing fall out of LIFO for free?
*/

#include <stdio.h>

#define MAXSTACK 16

// Student writes typedefs here

int main(){
    // Student writes code here
    return 0;
}
