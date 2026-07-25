/*
Practice 8.1.2 - Descriptor Detective

Problem:
A diagnostic tool that reports the state of its own standard descriptors:

    ./detect
    fd 0 (stdin):  terminal
    fd 1 (stdout): terminal
    fd 2 (stderr): terminal

    ./detect < file.txt > out.log
    (out.log gets:) fd 0 (stdin):  redirected
                    fd 1 (stdout): redirected
                    fd 2 (stderr): terminal      <- but on SCREEN? no - think!

Requirements:
- Use isatty(fd) for each of 0,1,2; print "terminal" or "redirected".
- The REPORT must go to stdout (it's the program's data output).
- ALSO write a one-line copy of the report to stderr, so the user sees it
  even when stdout is redirected. Label the streams so a reader of out.log
  can tell which copy they're seeing.
- Then echo the FIRST line of stdin (fgets) back to stdout prefixed
  "stdin says: " - but ONLY if stdin is redirected (reading a terminal
  would block waiting for typing - explain in a comment).

DSA/Algorithm Focus: introspection + conditional I/O paths (no heavy DSA -
this practice builds SYSTEMS intuition)
Best approach: loop fd 0..2 over a names[] table; isatty each. O(1).
Complexity: O(1) time/space.
Constraints: pure diagnostics tool - must never hang. That constraint IS
the design problem.

Hints (Socratic):
- Run every combination: plain, <file, >file, 2>file, piped both ways.
  Predict each output location BEFORE running. Where were you wrong?
- Why does `./detect | cat` show stdout as redirected? What is fd 1
  attached to there?
- What single header declares isatty?
*/

#include <stdio.h>
#include <unistd.h>

int main(){
    // Student writes code here
    return 0;
}
