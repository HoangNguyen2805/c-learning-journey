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


#include <stdio.h>

int main(){

  return 0;
}

/* ACTION 1 — readlines: read lines into one big buffer (no malloc)

readlines(lineptr, maxlines, storage, maxstorage):

    Parameters:
        lineptr    = array of pointers (slots), declared in main
        maxlines   = how many slots lineptr has
        storage    = the one big char buffer, declared in main
        maxstorage = how many bytes storage has

    Variables:
        line[MAXLEN] = scratch space, each line lands here first
        nlines       = lines stored so far, starts at 0
                       (also the index of the next empty slot)
        p            = next free spot in storage, starts at the beginning of storage

    while (fgets reads a line into line, and does not return NULL):

        Step 1: measure the line
                len = my_strlen(line)

        Step 2: remove the \n
                if the last character, line[len - 1], is \n:
                    replace it with \0
                    make len one smaller   (so len is always the real length)
                if there is no \n (often the last line of a file): do nothing

        Step 3: CHECK 1 — is there a free slot in lineptr?
                if nlines >= maxlines:
                    return -1   (too many lines)

        Step 4: CHECK 2 — is there room left in storage?
                bytes needed = len + 1          (letters + \0)
                bytes used   = p - storage
                bytes left   = maxstorage - bytes used
                if bytes needed > bytes left:
                    return -2   (not enough storage)

        Step 5: copy the line from line into storage, starting at p

        Step 6: record where the line starts
                lineptr[nlines] = p
                nlines++

        Step 7: move p forward past the line and its \0
                p = p + len + 1

    return nlines
*/