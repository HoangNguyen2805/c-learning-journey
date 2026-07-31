/*
[FROM K&R] Exercise 5-7

Book text:
  "Rewrite readlines to store lines in an array supplied by main, rather than
  calling alloc to maintain storage. How much faster is the program?"

Start from your 5.6.3. Instead of one malloc per line, main declares a single
large char array and readlines packs the lines into it end to end.

    char storage[MAXSTORAGE];

Each line goes in immediately after the previous one, and lineptr[i] points at
where that line begins inside storage.

    storage:  f i r s t \0 s e c o n d \0 t h i r d \0 . . .
              ^           ^             ^
              lineptr[0]  lineptr[1]    lineptr[2]

Constraints:
- Exactly one large buffer, declared in main, passed to readlines
- readlines must not overrun it
- No malloc at all

Hint, not a solution:
  You need to track where the next free byte is. That is a pointer that moves
  forward by the length of each stored line, plus one for the terminator.

  Two things can now go wrong that could not before: too many lines, and too
  many total characters. They are different limits, hit under different inputs,
  and both need checking. A file of 10 huge lines and a file of 10000 tiny ones
  fail in different ways.

Answer the book's actual question — do not guess:

  Generate a large input first:
      seq 1 200000 | shuf > big.txt

  Then time both versions on the same file:
      time ./sorter_malloc < big.txt > /dev/null
      time ./sorter_array  < big.txt > /dev/null

  Record the numbers in a comment at the bottom of this file. Say whether the
  difference matched what you expected, and where the time is actually going.
  If the two are closer than you predicted, that itself is the finding — most
  of the work in this program is not allocation.

Then answer the question K&R does not ask: what did you give up?
  The malloc version handles one enormous line and a million tiny ones equally
  well. This one does not. Describe the input that breaks the array version but
  not the malloc version.

DSA concept: arena allocation — one bulk reservation carved into pieces
Approach: bump a pointer through a fixed buffer
Time: per-line allocation drops from a malloc call to a pointer addition
Space: O(MAXSTORAGE) fixed, used or not

TIMING RESULTS (fill this in):

  malloc version:
  array version:
  observation:
*/
/*Given:
#include <stdio.h>
#include <string.h>

#define MAXLINES   5000
#define MAXLEN     1000
#define MAXSTORAGE 100000

int main()
{

    return 0;
}
*/