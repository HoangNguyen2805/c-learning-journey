/*
Practice 7.6.2 - "extract": a pipeline-safe field extractor

Problem:
A tool designed to live inside shell pipelines, so its streams MUST be clean:

    ./extract 2 < data.txt        # print the 2nd whitespace-separated
                                  # field of every line to stdout
    data.txt:  alpha 10 x         ->   10
               beta 20 y          ->   20
               gamma              ->   (warning to stderr, line skipped)

Requirements:
- argv[1] = field number k (1-based). Validate: missing or non-numeric or
  k < 1 -> usage message to stderr, exit(2).
- Read lines; split into fields by scanning (isspace boundaries - your
  own logic, no strtok); print field k, or warn to stderr
  "line N: only M field(s)" and continue.
- Exit 0 if every line had the field, 1 if any line was skipped.
- The OUTPUT must contain ONLY extracted fields - verify by:
      ./extract 2 < data.txt | sort -n
- ferror(stdout) check -> exit(2) with message.

DSA/Algorithm Focus: tokenization state machine + strict stream hygiene
Best approach: per line, walk chars tracking in-field/between-field state,
counting field starts; emit chars while current field == k. O(n), zero copies.
Complexity: O(total bytes) time, O(1) space (no line buffer needed - try!).
Constraints: fields can be any length (that's WHY no fixed buffer); k up
to INT_MAX must not crash anything.

Hints (Socratic):
- A "field start" is a non-space whose PREVIOUS char was what? What is
  "previous" at line start?
- Streaming without a line buffer: when do you know the line LACKED field k?
- Which of your three exit statuses does the shell's `&&` treat as success?
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}
