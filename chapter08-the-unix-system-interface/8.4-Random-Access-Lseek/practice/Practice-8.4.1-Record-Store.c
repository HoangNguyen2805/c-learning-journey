/*
Practice 8.4.1 - Fixed-Record Database (disk array + CRUD)

Problem:
A tiny on-disk database of fixed-size records:

  #define RECSIZE sizeof(struct rec)
  struct rec { int id; char name[20]; int score; };   // fixed size!

Commands read from stdin, one per line (fgets+sscanf - Ch7 skills):
    put 3 alice 90        # write record at slot 3 (seek + write struct)
    get 3                 # seek, read, print slot 3
    del 3                 # overwrite slot with an all-zero record (id 0 = empty)
    list                  # scan file start to end, print nonempty slots
    quit

Requirements:
- open("recs.db", O_RDWR|O_CREAT, 0666) once at start; close at quit.
- put: lseek((long)slot * RECSIZE, 0) then write(&r, RECSIZE); check both.
- get on a slot beyond EOF: read returns 0 -> "empty". Holes read as
  zeros -> id 0 -> also "empty". Convince yourself both cases unify!
- Validate slot 0..999; reject junk lines with a stderr warning.
- write the struct directly (binary file!) - then answer in a comment:
  why can't you cat recs.db meaningfully, and what would break moving
  the file to a different machine? (padding/endianness - 6.3 flashback)

DSA/Algorithm Focus: direct addressing on disk - array semantics via lseek;
O(1) reads/writes by slot number
Best approach: offset = (long)slot * RECSIZE; every op is seek+one I/O.
Complexity: put/get/del O(1); list O(max_slot); space O(1) in memory.
Constraints: no in-memory table of records - the FILE is the data structure.

Hints (Socratic):
- Why do fixed-size records make O(1) access possible while text lines don't?
- del by zeroing vs actually shrinking the file: why is shrinking hard
  with only this chapter's calls?
- What does sizeof(struct rec) include beyond 28 bytes of fields, and why
  MUST you use sizeof anyway?
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct rec {
    int id;
    char name[20];
    int score;
};

#define RECSIZE ((long)sizeof(struct rec))

int main(){
    // Student writes code here
    return 0;
}
