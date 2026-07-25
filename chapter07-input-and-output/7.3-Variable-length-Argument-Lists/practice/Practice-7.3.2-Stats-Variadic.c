/*
Practice 7.3.2 - Variadic Statistics + a Safe Join

Problem:
Part A - numeric stats in ONE pass each:
  double v_mean(int count, ...);        // doubles
  double v_range(int count, ...);       // max - min, single walk tracking both
  int    v_count_above(double lim, int count, ...);  // how many exceed lim

Part B - string join with sentinel INSTEAD of count:
  void join(const char *sep, ...);      // args are char*, list ENDS at NULL
  join(", ", "red", "green", "blue", (char*)NULL);   -> red, green, blue\n

main: demonstrate all four; include edge cases count=0 and join with
only the NULL.

DSA/Algorithm Focus: streaming folds (min/max/mean) + sentinel-terminated lists
Best approach: v_range keeps TWO accumulators in one va_arg walk;
join prints sep BEFORE every element except the first (the classic trick).
Complexity: O(count) each; O(1) space.
Constraints: each function walks its va_list exactly once; v_mean of 0
args must not divide by zero.

Hints (Socratic):
- Sentinel vs count-first: which is safer for strings and why does NULL
  work as a sentinel here but -1 wouldn't?
- The "sep before all but first" trick: what tiny piece of state does it need?
- Why must the caller cast NULL to (char*) in the call? (Think promotions
  and pointer size vs int size - subtle but real on 64-bit.)
*/

#include <stdio.h>
#include <stdarg.h>

double v_mean(int count, ...);
double v_range(int count, ...);
int v_count_above(double lim, int count, ...);
void join(const char *sep, ...);

int main(){
    // Student writes code here
    return 0;
}
