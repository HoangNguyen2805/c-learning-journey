/*
Practice 6.8.2 - Shape System (tagged union + function dispatch)

Problem:
Model geometric shapes whose data differs per kind:

  enum skind { SH_CIRCLE, SH_RECT, SH_TRIANGLE };
  typedef struct {
      enum skind kind;
      union {
          struct { double r; } circle;
          struct { double w, h; } rect;
          struct { double a, b, c; } tri;    // three side lengths
      } u;
  } Shape;

Implement:
  Shape mk_circle(double r); Shape mk_rect(double w, double h);
  Shape mk_tri(double a, double b, double c);
  double area(const Shape *s);       // circle: pi r^2; rect: w*h;
                                     // triangle: Heron's formula
  double perimeter(const Shape *s);
  const char *name(const Shape *s);

main: array of 4+ mixed shapes; print a table
    circle     r=2.0        area=12.57   perim=12.57
then report which shape has the LARGEST area (linear scan, track a pointer).

DSA/Algorithm Focus: sum types + dispatch-by-tag (hand-rolled polymorphism)
Best approach: single switch per operation; Heron: s=(a+b+c)/2,
sqrt(s(s-a)(s-b)(s-c)).
Complexity: O(1) per shape op; O(n) scan for max.
Constraints: compile with -lm; validate the triangle inequality in mk_tri
(print a warning for impossible triangles and treat area as 0).

Hints (Socratic):
- Why nest little anonymous structs inside the union rather than flat
  doubles r,w,h,a,b,c? What bug does the nesting prevent?
- area() takes const Shape* - why pointer, and why const?
- This IS what C++ virtual functions compile down to (roughly). Which part
  plays the "vtable" role here - the enum, the switch, or both?
*/

#include <stdio.h>
#include <math.h>

// Student writes typedefs here

int main(){
    // Student writes code here
    return 0;
}
