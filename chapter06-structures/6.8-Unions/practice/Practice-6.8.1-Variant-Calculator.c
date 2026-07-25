/*
Practice 6.8.1 - Variant Value Calculator (tagged union)

Problem:
Build a tiny dynamically-typed value system, then compute over it.

  enum vtype { V_INT, V_DBL };
  typedef struct {
      enum vtype type;
      union { int i; double d; } as;
  } Value;

Implement:
  Value v_int(int x);                 // constructors
  Value v_dbl(double x);
  double v_tonum(Value v);            // int -> (double), dbl -> itself
  Value v_add(Value a, Value b);      // result is V_INT only if BOTH are ints
  Value v_max(Value a, Value b);
  void  v_print(Value v);             // [int 5] or [dbl 2.50]

main: build the array { v_int(3), v_dbl(2.5), v_int(7), v_dbl(0.5) } and:
  1. print each
  2. sum ALL (what type must the running sum be? justify in a comment)
  3. find max
  4. add v_int(1)+v_int(2) and PROVE the result kept type V_INT

DSA/Algorithm Focus: tagged unions / sum types - foundation of interpreters
Best approach: every operation switches on tags FIRST, then touches .as.
Complexity: O(1) per op, O(n) folds over the array.
Constraints: never read a union member without checking type; no globals.

Hints (Socratic):
- v_add on (int, dbl): which member of which operand do you read, and what
  tag does the result carry? Enumerate all 4 tag combinations.
- Why do constructors (v_int/v_dbl) eliminate half the tag bugs by design?
- Where would a V_STRING variant break v_tonum? What does that tell you
  about adding types to a tagged union later?
*/

#include <stdio.h>

// Student writes typedefs here

int main(){
    // Student writes code here
    return 0;
}
