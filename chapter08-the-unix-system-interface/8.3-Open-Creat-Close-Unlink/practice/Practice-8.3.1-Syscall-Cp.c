/*
Practice 8.3.1 - cp with Manners  [FROM K&R - 8.3 cp, extended]

Problem:
Build the book's cp, then civilize it:

    ./mycp src dst            # classic copy
    ./mycp -n src dst         # refuse to overwrite an existing dst
    ./mycp -v src dst         # verbose: report bytes copied to stderr

Requirements:
- Your own variadic error(char *fmt, ...) exactly as the book: stderr,
  prefix, vfprintf, exit(1).
- open src O_RDONLY (check -1); dst via creat/open+O_CREAT (check -1).
- -n implementation: try open(dst, O_RDONLY, 0) FIRST - success means it
  exists -> error("won't overwrite %s", dst). Close that probe fd!
  (Alternative: open with O_CREAT|O_EXCL - investigate and comment which
  is race-free and why.)
- The copy loop must check write's return != n.
- close both fds; -v prints total bytes.

DSA/Algorithm Focus: syscall error-path discipline + TOCTOU awareness
Best approach: O(n) BUFSIZ-chunked loop; flags parsed 5.10-style.
Complexity: O(n) time, O(BUFSIZ) space.
Constraints: on ANY failure after dst was created, should you unlink the
half-written dst? Decide and implement your policy; document it.

Hints (Socratic):
- Why is probe-then-creat racy (another process between your two calls)?
  What does O_EXCL make atomic?
- Which failures leave a corrupt dst behind - and is deleting it always
  right (what if dst existed before)?
- error() exits - so why must the -n probe's close() happen before it?
  (Or does it matter? think exit semantics.)
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define PERMS 0666

void error(char *fmt, ...);

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}

void error(char *fmt, ...){
    // Student writes code here
}
