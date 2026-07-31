/*
Practice 5.6.3 — The Line Sorter

Build the program K&R describes: read lines from standard input, sort them
alphabetically, print them. A stripped-down version of the UNIX sort.

Run it as:   ./sorter < somefile.txt
Or type lines and press Ctrl-D on a blank line when done.

Structure it as K&R does — three functions plus main:
    readlines(lineptr, MAXLINES)    returns count, or -1 if too many
    qsort_str(lineptr, 0, nlines-1)
    writelines(lineptr, nlines)

Constraints:
- Each line gets its own allocation, sized to that line
- free() everything before exit
- Handle the too-many-lines case rather than overrunning the array
- Strip the trailing newline before storing

Hint, not a solution:
  Use fgets to read into a temporary buffer, then malloc exactly what the line
  needs and strcpy into it. Work out the +1 and be sure you know why it is
  there.

  The classic failure in this program is storing the address of the temporary
  buffer instead of the address of fresh storage. If your output is N copies of
  the last line, that is exactly what happened — and it is worth causing
  deliberately once so you recognize it forever.

  For the sort, use the quicksort from Chapter 4 with strcmp as the comparison.
  The algorithm needs no changes beyond the declarations and that one line.

DSA concept: indirect sorting with dynamic storage
Approach: array of pointers into individually allocated lines, quicksort
Time: O(n log n) comparisons average; each comparison costs O(L) for line
      length L, so O(L n log n) overall
Space: O(total input size) for the text plus O(n) for the pointer array

Two tests worth running:
  1. Sort a file, then sort the sorted output. The second run must produce
     identical output. If it does not, your comparison is inconsistent.
  2. If you have valgrind:  valgrind ./sorter < file.txt
     Every malloc needs its free.
*/
/*
/*Given:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN   1000

int main()
{

    return 0;
}
*/