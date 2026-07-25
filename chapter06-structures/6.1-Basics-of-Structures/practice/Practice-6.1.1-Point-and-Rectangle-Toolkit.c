/*
Practice 6.1.1 - Point and Rectangle Toolkit  [FROM K&R - 6.1 examples]

Problem:
Build the geometric core K&R sketches, using only member access and copies:

  struct point { int x; int y; };
  struct rect  { struct point pt1; struct point pt2; };  // pt1=lower-left

In main (no helper functions yet - that's 6.2):
  1. Define a rect r = {(2,3),(10,9)} using nested initializers.
  2. Compute and print width, height, area, perimeter.
  3. Compute the CENTER point as a struct point (integer division ok).
  4. "Canonicalize": given a rect built from ANY two opposite corners,
     e.g. {(10,9),(2,3)}, rearrange members so pt1 is truly lower-left
     and pt2 upper-right. Hint: min/max per coordinate via if statements.
  5. Point-in-rect test: does point q=(5,5) lie inside r? Print yes/no.

DSA/Algorithm Focus: composite data modeling + axis-aligned bounding box (AABB) logic
Best approach: pt1.x <= q.x && q.x < pt2.x && same for y (half-open, K&R style).
Complexity: all O(1) time/space.
Constraints: no functions besides main; no arrays; struct copies allowed.

Hints (Socratic):
- Why half-open ranges (<= on one side, < on the other)? What double-counting
  does it prevent when rectangles tile a screen?
- For canonicalize: which FOUR comparisons fully determine the two corners?
- Can you swap two ints without a temp here? Should you?
*/

#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

int main(){
    // Student writes code here
    return 0;
}
