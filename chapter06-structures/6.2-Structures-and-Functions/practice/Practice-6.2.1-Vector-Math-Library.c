/*
Practice 6.2.1 - 2D Vector Math Library

Problem:
Implement a small vector library over struct point, mixing by-value and
by-pointer styles ON PURPOSE:

  struct point vmake(int x, int y);                 // by value (constructor)
  struct point vadd(struct point a, struct point b);// by value
  struct point vsub(struct point a, struct point b);// by value
  int          vdot(struct point a, struct point b);// by value, returns a.x*b.x + a.y*b.y
  void         vscale(struct point *p, int k);      // by POINTER (mutates)
  void         vswap(struct point *a, struct point *b); // by POINTER

In main:
  1. Build a=(3,4), b=(1,2); print a+b, a-b, a.b (dot).
  2. vscale(&a, 3); print a.
  3. vswap(&a, &b); print both.
  4. Verify: (a+b).(a+b) == a.a + 2*(a.b) + b.b  - print both sides.

DSA/Algorithm Focus: value vs reference semantics; building an API surface
Best approach: constructors/pure math by value; mutators by pointer. O(1) each.
Complexity: O(1) time/space per operation.
Constraints: vswap must swap WHOLE structs using struct assignment (one temp).

Hints (Socratic):
- Why is by-value the right call for vadd but wrong for vscale?
- In vswap, how many struct copies happen? Could you do it member-by-member,
  and why is whole-struct assignment better?
- For check #4: which earlier function results can you reuse instead of recomputing?
*/

#include <stdio.h>

struct point { int x; int y; };

struct point vmake(int x, int y);
struct point vadd(struct point a, struct point b);
struct point vsub(struct point a, struct point b);
int vdot(struct point a, struct point b);
void vscale(struct point *p, int k);
void vswap(struct point *a, struct point *b);

int main(){
    // Student writes code here
    return 0;
}
