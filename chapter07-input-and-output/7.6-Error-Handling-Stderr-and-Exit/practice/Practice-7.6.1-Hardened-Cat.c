/*
Practice 7.6.1 - Hardened cat  [FROM K&R - 7.6 cat v2, extended]

Problem:
Upgrade your Practice 7.5.1 cat to production manners:

- ALL diagnostics to stderr, prefixed "%s: " with prog = argv[0].
- Distinct exit statuses:
      0 all files copied
      1 at least one file could not be opened (but CONTINUE with the rest -
        unlike the book, don't abort on first failure)
      2 write error on stdout (ferror check at the end)
- New flag -q: suppress warnings (errors still counted in exit status!).
- Implement helpers (7.3 skills):
      void warn(const char *fmt, ...);    // stderr, honors -q
      // exit status tracked in main - why not exit() inside warn?

Test matrix to run yourself (put commands in a comment):
    ./hcat a.txt missing.txt b.txt > out.txt ; echo $?
    ./hcat -q missing.txt ; echo $?
    ./hcat < a.txt | wc -c

DSA/Algorithm Focus: error-path design; separation of data/diagnostic channels
Best approach: same O(n) copy; the new work is all control flow discipline.
Complexity: O(total bytes); O(1) space.
Constraints: -q must be parseable anywhere before first filename; warn's
quiet check must NOT be duplicated at every call site (where does the
flag live so warn sees it?).

Hints (Socratic):
- Why does "continue after failure" + exit(1) at end serve users better
  than the book's immediate exit(1)? When is immediate abort better?
- warn honoring -q: global flag, or parameter, or file-static? Weigh them.
- Which stream should the -b/-n numbered OUTPUT use? (Careful - it's data!)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void warn(const char *fmt, ...);
void filecopy(FILE *ifp, FILE *ofp);

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}

void warn(const char *fmt, ...){
    // Student writes code here
}

void filecopy(FILE *ifp, FILE *ofp){
    // Student writes code here
}
