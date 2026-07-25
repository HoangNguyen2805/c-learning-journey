/*
Practice 6.2.2 - Rectangle Intersection (AABB collision)

Problem:
The heart of every 2D game engine: do two rectangles overlap, and where?

  struct point { int x; int y; };
  struct rect  { struct point pt1; struct point pt2; };  // canonical form

Implement:
  struct rect canonrect(struct rect r);                       // by value
  int  overlaps(const struct rect *a, const struct rect *b);  // 1/0
  struct rect intersection(const struct rect *a, const struct rect *b);
        // valid only if overlaps() - the overlap region
  void grow(struct rect *r, int d);   // expand by d on all sides (mutates)

In main, test at least:
  - two overlapping rects -> print the intersection rect + its area
  - two separated rects   -> print "no overlap"
  - grow a rect until two separated rects DO overlap; print how it changed

DSA/Algorithm Focus: interval overlap logic (1D intervals x2 = AABB test)
Best approach: overlap iff a->pt1.x < b->pt2.x && b->pt1.x < a->pt2.x (and same
for y). Intersection corners: max of the mins, min of the maxes.
Complexity: O(1) time/space.
Constraints: pointer params for the read paths must be const; use -> throughout.

Hints (Socratic):
- Derive the 1D rule first: when do intervals [a1,a2) and [b1,b2) overlap?
  Try to state when they DON'T overlap - then negate it.
- Why does intersection = (max of pt1s, min of pt2s)? Draw it.
- What makes canonical form a REQUIREMENT for the overlap test to be correct?
*/

#include <stdio.h>

struct point { int x; int y; };
struct rect  { struct point pt1; struct point pt2; };

struct rect canonrect(struct rect r);
int overlaps(const struct rect *a, const struct rect *b);
struct rect intersection(const struct rect *a, const struct rect *b);
void grow(struct rect *r, int d);

int main(){
    // Student writes code here
    return 0;
}
