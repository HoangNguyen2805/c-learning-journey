/*
Practice 5.10.1 - Command-Line Calculator

Problem:
Build a calculator that runs entirely from the command line:

    ./calc 12 + 5      -> 17
    ./calc 20 / 4      -> 5
    ./calc 7 x 3       -> 21     (use 'x' for multiply; '*' is eaten by the shell)

Requirements:
- Validate argc == 4; otherwise print a usage message with argv[0] and return 1.
- Convert argv[1] and argv[3] with atoi.
- The operator is argv[2][0] - switch on it.
- Handle divide-by-zero with an error message to the user.
- Support + - x / and % (modulo).

DSA/Algorithm Focus: input parsing + dispatch (switch as a jump table)
Best approach: single switch on the operator character; O(1) dispatch.
Complexity: O(1) time, O(1) space (input size is fixed).
Constraints: no scanf, no loops needed; all input comes from argv.

Hints (Socratic):
- What type does atoi return, and what does it return for "abc"?
- Why must you check argc BEFORE reading argv[2]?
- Which case in your switch needs a guard before computing?
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}
