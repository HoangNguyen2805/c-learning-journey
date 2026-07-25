/*
Practice 8.6.1 - tree: indented directory listing

Problem:
Recreate the classic `tree` tool:

    ./mytree [dir]           # default "."
    demo/
        a.txt
        sub/
            c.txt
        b.txt
    3 files, 2 directories

Requirements:
- Recursive walk(char *path, int depth): stat the path; print
  4*depth spaces then the LAST path component (strrchr for '/' - 7.8!),
  with a trailing '/' for directories; then, for directories,
  opendir/readdir loop recursing at depth+1 (skip "." "..").
- Path building with the length guard from the lesson (MAX_PATH 1024).
- Count files and directories in two ints - passed HOW without globals?
  (int* out-params, or a struct counter* - choose and justify in comment.)
- Unreadable directories: report to stderr, continue (don't die).
- Sort? readdir order is arbitrary - OPTIONAL stretch: collect names in
  a char*[] (heapdup!), insertion-sort with strcmp, then recurse. If you
  skip it, note in a comment WHY output may differ between machines.

DSA/Algorithm Focus: tree traversal (DFS) with depth tracking - the
filesystem IS a general tree, and this is your first non-binary tree walk!
Best approach: pre-order DFS (print, then children); depth drives indent.
Complexity: O(total entries) time; O(max depth) stack; sorted variant
adds O(k log k... well, k^2 with insertion sort) per directory.
Constraints: no ftw/nftw library walkers; recursion required.

Hints (Socratic):
- Pre-order vs post-order here: which prints a directory BEFORE its
  contents, and which does fsize in the book do?
- Depth is per-CALL state - why does that make it a parameter rather
  than a static?
- What's the last component of "a/b/" (trailing slash)? Decide a policy.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}
