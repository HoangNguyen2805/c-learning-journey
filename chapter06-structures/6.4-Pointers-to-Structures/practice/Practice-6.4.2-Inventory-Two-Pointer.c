/*
Practice 6.4.2 - Inventory Scan with Two Pointers

Problem:
An inventory table, pre-sorted by price ascending:

  struct item { char *name; int price; int qty; };
  struct item inv[] = {
      {"eraser",1},{"pencil",2},{"pen",4},{"ruler",6},
      {"notebook",9},{"stapler",15},{"backpack",30},{"calculator",45}
  };

Using ONLY struct pointers (no subscripts after the initializer):
  1. total_value(): sum of price*qty over the table (pointer walk).
  2. cheapest_pair_sum(target): TWO-POINTER technique - one pointer at the
     first row, one at the last; find whether two DIFFERENT items' prices
     sum exactly to target. Print the pair or "none". Test target=19 and 8.
  3. price_range(lo, hi): return pointers to the FIRST item with
     price >= lo and the first with price > hi (half-open range), by
     scanning; print every item between them. Test lo=4, hi=15.

DSA/Algorithm Focus: the two-pointer technique on a sorted array (classic!)
Best approach: sum too small -> advance left; too big -> retreat right; O(n).
Complexity: total O(n); two-pointer O(n) vs brute force O(n^2); O(1) space.
Constraints: give every item a qty; NITEMS via sizeof trick; use -> only.

Hints (Socratic):
- WHY does moving the left pointer rightward only ever INCREASE the sum?
  What property of the data guarantees it?
- When left and right meet, what have you proven?
- For price_range: which comparison operators produce the half-open [lo, hi]
  behavior asked for? Off-by-one check: should hi itself be included?
*/

#include <stdio.h>

struct item {
    char *name;
    int price;
    int qty;
};

int main(){
    // Student writes code here
    return 0;
}
