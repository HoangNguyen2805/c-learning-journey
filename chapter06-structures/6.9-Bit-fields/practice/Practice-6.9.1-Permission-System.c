/*
Practice 6.9.1 - Unix-style Permission System (masks)

Problem:
Implement chmod-like permissions with pure mask operations on an unsigned:

  bits (octal): owner rwx = 0400 0200 0100
                group rwx = 0040 0020 0010
                other rwx = 0004 0002 0001

Implement:
  unsigned p_set(unsigned p, unsigned bits);
  unsigned p_clear(unsigned p, unsigned bits);
  int      p_has(unsigned p, unsigned bits);     // ALL given bits on?
  void     p_print(unsigned p);                  // prints e.g. rwxr-x--x
  unsigned p_parse(const char *s);               // "rw-r--r--" -> 0644

main test:
  start at 0; build 0644 with p_set calls; print;
  chmod +x for owner (0100); print;
  check p_has for (0400|0200) and for 0002; parse "rwxr-xr--" and print
  its octal with %o; verify p_parse(p_print-output) round-trips.

DSA/Algorithm Focus: bit manipulation - the mask/set/clear/test quartet
Best approach: p_print loops over 9 bit positions high->low: (p >> i) & 1.
Complexity: O(1) ops; O(9) for print/parse.
Constraints: no bit-fields in this one - masks and shifts only; use octal
literals throughout (this is WHY octal survives in Unix).

Hints (Socratic):
- p_has must be true only if ALL requested bits are set. Why is
  (p & bits) == bits correct while (p & bits) != 0 is not?
- In p_print, which bit does position i=8 correspond to? Map i -> "rwx" char.
- Where does p_parse get its bit for character position j? Same map, reversed.
*/

#include <stdio.h>

unsigned p_set(unsigned p, unsigned bits);
unsigned p_clear(unsigned p, unsigned bits);
int p_has(unsigned p, unsigned bits);
void p_print(unsigned p);
unsigned p_parse(const char *s);

int main(){
    // Student writes code here
    return 0;
}
