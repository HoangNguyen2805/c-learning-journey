/*
Practice 8.3.2 - Log Rotator (creat/unlink lifecycle)

Problem:
Simulate a logging system with rotation, pure syscalls:

    ./rotator
    writes 20 numbered log lines into app.log, but every 5 lines it
    "rotates":  app.log -> app.log.old  (copy bytes, then truncate app.log)

    final state:  app.log     lines 16..20
                  app.log.old lines 11..15
    then prints both files to stdout with headers, then unlinks both.

Requirements:
- Line format built with sprintf: "log entry %02d\n"; written with write().
- rotate(): open app.log O_RDONLY; creat app.log.old (truncates old
  backup - intended); copy loop with write!=n check; close both;
  then creat(app.log) to truncate it; close. All -1 checks -> error().
- Keep app.log's fd CLOSED between writes OR open once with O_APPEND and
  reopen after each rotation - choose, and justify in a comment (what
  does rotation do to an already-open fd's idea of the file?).
- error(fmt, ...) helper required.

DSA/Algorithm Focus: file lifecycle state machine (create/write/copy/
truncate/delete) - how real logrotate works, miniature
Best approach: O(total bytes); the interesting part is ORDER of operations.
Complexity: O(n) time, O(BUFSIZ) space.
Constraints: after the final unlinks, prove deletion by showing open()
returns -1 for both names.

Hints (Socratic):
- If you hold app.log open with O_APPEND across a rotation-by-truncate,
  where does the NEXT write land? Test it - the answer teaches how fds
  relate to files, not names.
- Why copy-then-truncate instead of rename? (We only have this section's
  calls! What does 8.6's world add later?)
- What's lost if the program crashes between copy and truncate? Between
  truncate and the next write? Order your steps to minimize damage.
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define PERMS 0666

void error(char *fmt, ...);
void rotate(void);

int main(){
    // Student writes code here
    return 0;
}

void error(char *fmt, ...){
    // Student writes code here
}

void rotate(void){
    // Student writes code here
}
