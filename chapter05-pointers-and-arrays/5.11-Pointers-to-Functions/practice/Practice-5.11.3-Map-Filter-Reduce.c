/*
Practice 5.11.3 - Map / Filter / Reduce over an int array

Problem:
Implement the three classic higher-order functions using function pointers:

    void map(int a[], int n, int (*f)(int));            // a[i] = f(a[i])
    int  filter(int src[], int dst[], int n,
                int (*pred)(int));                      // copy where pred!=0, return count
    int  reduce(int a[], int n, int init,
                int (*f)(int, int));                    // fold left

Then in main, with int data[] = {3, -1, 4, -1, 5, 9, -2, 6}:
  1. map with square            -> print array
  2. filter with is_positive on the ORIGINAL data -> print kept elements + count
  3. reduce with add, init 0    -> print sum
  4. reduce with maxof, init data[0] -> print maximum

Requirements:
- Write square, is_positive, add, maxof yourself.
- map/filter/reduce must NOT reference any of those names - only their pointer params.
- filter must not modify src.

DSA/Algorithm Focus: higher-order array traversal (the functional trio)
Best approach: single pass each; reduce carries an accumulator.
Complexity: all three O(n) time; filter O(n) extra space for dst; others O(1).
Constraints: no global variables; exact signatures above.

Hints (Socratic):
- In reduce, what is the accumulator's value BEFORE the first element is folded in?
- Why does filter need a destination array while map doesn't?
- What breaks if you run map(square) BEFORE the filter step - order matters why?
*/

#include <stdio.h>

void map(int a[], int n, int (*f)(int));
int filter(int src[], int dst[], int n, int (*pred)(int));
int reduce(int a[], int n, int init, int (*f)(int, int));

int square(int x);
int is_positive(int x);
int add(int x, int y);
int maxof(int x, int y);

int main(){
    // Student writes code here
    return 0;
}
