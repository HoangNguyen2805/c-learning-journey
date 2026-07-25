/*
Practice 7.4.1 - Robust Number Reader (line + sscanf)

Problem:
Read stdin LINE BY LINE. Each line should contain one integer. Report:

    ok: 42
    bad line 3: "hello"
    ok: -7
    ...
    ---
    sum=35 count=2 bad=1

Requirements:
- mygetline(char *, int) built from getchar (from memory - Ch1 muscle).
- Parse each line with sscanf("%d", ...); count successes/failures.
- A line like "42 extra" should be BAD: detect trailing junk with the
  two-spec trick  sscanf(line, "%d %1s", &n, tail)  - what result means
  "clean"? Work it out.
- Print the running report exactly as above; line numbers start at 1.

DSA/Algorithm Focus: defensive parsing / input validation state machine
Best approach: line-oriented reading isolates errors to one line - O(L) per line.
Complexity: O(total input) time, O(MAXLINE) space.
Constraints: MAXLINE 256; must survive: empty lines, spaces-only lines,
"12abc", overlong lines (getline truncation - decide the policy, comment it).

Hints (Socratic):
- Why does reading a LINE first make error recovery trivial compared to
  scanf("%d") straight from stdin?
- For "42 extra": how many conversions does the two-spec sscanf report?
  For "42"? For "abc"? Build your validity test from those three cases.
- Is a line of only whitespace bad or skippable? Choose; document.
*/

#include <stdio.h>

#define MAXLINE 256

int mygetline(char *line, int max);

int main(){
    // Student writes code here
    return 0;
}

int mygetline(char *line, int max){
    // Student writes code here
    return 0;
}
