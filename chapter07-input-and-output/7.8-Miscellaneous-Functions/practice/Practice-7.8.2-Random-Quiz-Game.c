/*
Practice 7.8.2 - Math Quiz Game (rand + strings + everything)

Problem:
An arithmetic drill game that uses half the library at once:

    ./quiz 5 42          # 5 questions, seed 42 (reproducible!)
    Q1: 7 + 12 = ? 19
    correct!
    Q2: 9 * 6 = ? 54
    correct!
    ...
    score 4/5 (80.0%) in questions of difficulty avg 8.3

Requirements:
- argv: count (default 5), seed (default: no srand call - note what that
  means for repeat runs in a comment).
- Per question: rand() picks op from "+-*" and two operands 2..12;
  compute the true answer in an int switch.
- Read the user's reply with fgets + sscanf("%d") - a non-number counts
  as wrong WITHOUT crashing or looping (7.4 robustness).
- Track score; "difficulty" of a question = max(operand1, operand2);
  report average difficulty %.1f via a running sum (float math at the end
  only - why?).
- Use at least: rand, srand, fgets, sscanf, strchr (op picking from the
  "+-*" string is a clean use!), printf field formatting for the report.

DSA/Algorithm Focus: PRNG-driven simulation + input validation loop
Best approach: O(count); all state in a handful of scalars.
Complexity: O(n) time, O(1) space.
Constraints: subtraction results may be negative - allowed; division
excluded (why? one-line comment about integer division ambiguity).

Hints (Socratic):
- ops = "+-*": what does ops[rand() % 3] give, and where does strchr
  fit if you instead read the op back from input?
- Same seed = same quiz. Why is that a FEATURE for testing your program?
- What does sscanf return for the reply "banana", and how does your
  wrong-answer path use that without special cases?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}
