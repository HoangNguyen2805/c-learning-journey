/*
Practice 7.2.2 - Number Base Table + sprintf Builder

Problem:
Part A: print a conversion table for 0..32 plus a few interesting values
(127, 128, 255, 256, 1023):

     DEC |     HEX |     OCT | BINARY
      10 |     0xa |     012 | 0000001010

- dec %6d, hex %#7x, oct %#7o - binary YOU must build (no %b in C89!).
Part B: write  void to_binary(unsigned n, char *buf, int bits);
  which sprintf/fills buf with exactly `bits` binary digits (leading zeros).
  Use shifts and masks from 6.9 practice: (n >> i) & 1.
Part C: use sprintf to build each FULL row into a char row[80] first,
  then print rows with one puts/printf each. (Why might building rows in
  memory be useful? one-line comment - think: sorting or writing to files.)

DSA/Algorithm Focus: base conversion via bit extraction; string building
Best approach: to_binary walks bit index high->low, O(bits) per number.
Complexity: O(n * bits) total; O(80) row buffer.
Constraints: to_binary must null-terminate; buf size passed implicitly by
bits+1 responsibility - document the contract in a comment.

Hints (Socratic):
- For bits=10, which bit index does buf[0] hold - 9 or 0? Which order
  reads naturally?
- What does (n >> i) & 1 yield, and how does '0' + that give a character?
- sprintf returns a count - how can Part C use it to APPEND the binary
  field after the earlier fields without strcat?
*/

#include <stdio.h>

void to_binary(unsigned n, char *buf, int bits);

int main(){
    // Student writes code here
    return 0;
}

void to_binary(unsigned n, char *buf, int bits){
    // Student writes code here
}
