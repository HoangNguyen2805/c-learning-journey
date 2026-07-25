/*
Practice 7.5.1 - cat with Line Numbers  [FROM K&R - 7.5 cat, extended]

Problem:
Rebuild cat, then add numbering:

    ./mycat file1.txt file2.txt      # plain concatenation
    ./mycat -n file1.txt             # number every line:      1  text
    ./mycat -b file1.txt             # number NONBLANK lines only (blank
                                       lines print un-numbered)
    ./mycat                          # no files: filter stdin (flags still work)

Requirements:
- Flag parsing first (5.10 idiom); then per-file loop with fopen/NULL
  check/filecopy-style function/fclose.
- Core:  void numcopy(FILE *ifp, FILE *ofp, int mode, int *lineno);
  lineno passed BY POINTER so numbering CONTINUES across multiple files.
- Number format: %6d followed by two spaces. A line = chars up to '\n'.
- On unopenable file: message to stdout (7.6 will move it to stderr),
  continue with remaining files, exit status 1 at the end.

DSA/Algorithm Focus: streaming state machine (start-of-line detection)
Best approach: track a bool at_line_start; decide numbering at the FIRST
char of each line, not at the newline. O(n) single pass.
Complexity: O(total bytes) time, O(1) space.
Constraints: no line buffer - char-at-a-time only (blank-line detection
for -b must work from the state machine: what char at line start means blank?).

Hints (Socratic):
- Why must lineno live in main, not numcopy? What resets it wrongly otherwise?
- For -b: "blank" = the line's first char is '\n'. Does your state machine
  see that case before printing a number?
- What should happen with -n AND -b together? Pick a rule (last wins? error?),
  document it.
*/

#include <stdio.h>

void numcopy(FILE *ifp, FILE *ofp, int mode, int *lineno);

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}

void numcopy(FILE *ifp, FILE *ofp, int mode, int *lineno){
    // Student writes code here
}
