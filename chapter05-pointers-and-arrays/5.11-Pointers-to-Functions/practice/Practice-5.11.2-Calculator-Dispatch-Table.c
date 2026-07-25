/*
Practice 5.11.2 - Calculator with a Dispatch Table

Problem:
Rebuild your reverse-Polish / command calculator idea, but WITHOUT a switch.
Read single-character commands + operands from stdin, e.g.:

    + 3 4      -> 7
    - 10 2     -> 8
    x 6 7      -> 42
    / 20 5     -> 4
    q          -> quit

Requirements:
- Define: double do_add(double,double); do_sub, do_mul, do_div (guard div-by-0).
- Build two PARALLEL arrays:
      char   opchar[]  = { '+', '-', 'x', '/' };
      double (*optab[])(double,double) = { ... };
- Read the command char with getchar()/scanf; linear-search opchar[] for it;
  call optab[i](a, b). Unknown command -> error message, keep looping.
- No switch statement anywhere. The pairing of arrays IS your dispatch.

DSA/Algorithm Focus: dispatch table / lookup table (function pointer array)
Best approach: linear search over 4 entries (fine at this size), then O(1) call.
Complexity: O(k) lookup for k ops (here k=4), O(1) space beyond the tables.
Constraints: parallel arrays must stay in sync - what guards that? (a #define count?)

Hints (Socratic):
- What must be true about the ORDER of the two arrays for dispatch to be correct?
- How do you compute the number of table entries without hardcoding 4?
- What should the loop do when scanf fails to read two doubles?
*/

#include <stdio.h>

double do_add(double a, double b);
double do_sub(double a, double b);
double do_mul(double a, double b);
double do_div(double a, double b);

int main(){
    // Student writes code here
    return 0;
}

double do_add(double a, double b){ return 0; } // Student rewrites
double do_sub(double a, double b){ return 0; } // Student rewrites
double do_mul(double a, double b){ return 0; } // Student rewrites
double do_div(double a, double b){ return 0; } // Student rewrites
