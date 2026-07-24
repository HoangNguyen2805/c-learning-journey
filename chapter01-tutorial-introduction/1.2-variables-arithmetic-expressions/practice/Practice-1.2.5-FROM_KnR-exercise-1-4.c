/*
[FROM K&R] Exercise 1-4

Book text:
  "Write a program to print the corresponding Celsius to Fahrenheit table."

The reverse of the section's program. Celsius in the left column, Fahrenheit
in the right.

Constraints:
- Choose a sensible range and step for Celsius and say in a comment why you
  chose it. 0 to 300 in steps of 20 is the Fahrenheit range and is a poor
  fit here — think about what Celsius values are actually interesting.
- Include a heading, using what you worked out in 1.2.4

Hint, not a solution:
  Invert C = (5/9)(F - 32) and you get F = (9/5)C + 32.

  Now: is 9/5 safe to write directly in C? Work out what the compiler does
  with it before you run anything. This is the same trap as 5/9 but it fails
  quietly instead of loudly — 9/5 does not give you 0, it gives you something
  that looks almost plausible. Predict the wrong output first, then run it and
  confirm you were right about how it breaks.

Concept: applying the section's integer-vs-float lesson to a new formula
Time: O(n) over the number of table rows
Space: O(1)

Check your work: 100 C should print as 212 F. If it prints 212.0 you are
fine. If it prints 132 you have found the trap.
*/

#include <stdio.h>

int main()
{

    return 0;
}
