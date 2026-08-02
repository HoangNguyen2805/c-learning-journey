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

/*
1. Read each line with fgets into a temporary buffer
2. Strip the trailing newline get rid of '\0' for correct measurement.
3. Measure the line, malloc storage that size, copy the line in,
   store the address in lineptr[]
4. Sort the pointer array alphabetically (the sort calls swap internally)
5. Print each line by following its pointer
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000  /* how many lines the array can hold */
#define MAXLEN   1000  /* how many characters one line can be */

void writelines(char *lineptr[], int nlines);
int readlines(char *lineptr[], int maxlines);

int main()
{
    
    char *lineptr[MAXLINES];
    int nlines = readlines(lineptr, MAXLINES);
    writelines(lineptr, nlines);

    /* free everything before exit */
    for (int i = 0; i < nlines; i++)
        free(lineptr[i]);

    return 0;
}

void writelines(char *lineptr[], int nlines) // to printout inorder
{
    for (int i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

int readlines(char *lineptr[], int maxlines){
    char line[MAXLEN]; // is a temporary buffer store one string at a time to process and filter.
    int nlines = 0;
    //there is no "Enter your string here: [user input]"
    // Because this one design to be a filter — it reads stdin until it ends.
    // instead of stdin, insert the hile.txt there ./sorter < input.txt
    while (fgets(line, MAXLEN, stdin) != NULL){
        /* 1. measure the line */ 
            /* For better accuracy counting character of string we need to get rid of '\n' , '\n' count but '\0' is not countin strlen
            replace \n with \0
            before:  | c | a | t | \n | \0 |
            after:   | c | a | t | \0 | \0 |   (moved the terminator over the newline)
            to reach then end to get rid of \n then we need strlen - 1
            */
            int len = strlen(line); // len is holding the value of length size so it's an integer
        /* 2. strip the trailing newline */
            if(len > 0 && line[len-1] == '\n'){ // if size of line bigger than 0 and last index is \n, which it alway does because fgets automatic assign it everytime
                line[len-1] = '\0';
            }
        /* 3. malloc storage that size */
        char *storage = malloc(len + 1);  // + 1 is for '\0'
        if (storage == NULL) {
            printf("error: input too big to sort\n");
            return -1; // due to > 0
        }
        /* 4. copy line into it, put the address in lineptr[nlines++] */
        // copy line into storage using strcpy(destination, source)
        strcpy(storage, line);           /* line is copied into malloc'd memory */
        lineptr[nlines++] = storage;     /* save that address in the array */

        // while loop is just reading and storing, Exist the loop to sorting and swap.
    }
    return nlines;
}


/*
PROGRAM FLOW: Line Sorter (No Sort Yet)

INPUT:
banana
apple
cherry
[Ctrl-D]

EXECUTION:

main():
    1. Declare char *lineptr[5000]    <- empty array of 5000 pointers
    2. Call readlines(lineptr, 5000)
    
readlines():
    Iteration 1:
        fgets reads: "banana\n"       <- from stdin
        len = strlen = 7              <- includes \n
        Strip: line[6] = '\0'         <- overwrites \n with \0
        len is now 6                  <- but we already measured 7
        malloc(7)                     <- 6 chars + 1 for \0
        strcpy into storage
        lineptr[0] = storage address  <- points to "banana"
        nlines = 1
    
    Iteration 2:
        fgets reads: "apple\n"
        len = 6
        Strip: line[5] = '\0'
        malloc(6)
        strcpy into storage
        lineptr[1] = storage address  <- points to "apple"
        nlines = 2
    
    Iteration 3:
        fgets reads: "cherry\n"
        len = 6
        Strip: line[5] = '\0'
        malloc(6)
        strcpy into storage
        lineptr[2] = storage address  <- points to "cherry"
        nlines = 3
    
    Iteration 4:
        fgets returns NULL             <- no more input
        Loop exits
    
    return nlines = 3

main() continues:
    3. nlines = 3
    4. Call writelines(lineptr, 3)
    
writelines():
    for i = 0 to 2:
        printf("%s\n", lineptr[i])
        Iteration 1: printf("%s\n", lineptr[0]) -> "banana"
        Iteration 2: printf("%s\n", lineptr[1]) -> "apple"
        Iteration 3: printf("%s\n", lineptr[2]) -> "cherry"

main() continues:
    5. Free loop: free(lineptr[0]), free(lineptr[1]), free(lineptr[2])
    6. return 0

OUTPUT:
banana
apple
cherry
*/