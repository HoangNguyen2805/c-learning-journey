/*
Section 5.6 - Pointer Arrays; Pointers to Pointers
Worked examples, book version.

This follows K&R's own presentation: the declaration, then readlines,
writelines, qsort, and swap, built up as the book builds them.

Where the book calls getline and alloc, this uses fgets and malloc so the
file compiles on its own. Those substitutions are marked.

Compile:  gcc 5.6A_pointer-arrays-book-version.c -o 5.6A-book
Run:      ./5.6A-book
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 100        /* max #lines to be sorted */
#define MAXLEN   1000       /* max length of any input line */

char *lineptr[MAXLINES];    /* pointers to text lines */

int  readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void writelines_ptr(char *lineptr[], int nlines);
void qsort_str(char *v[], int left, int right);
void swap(char *v[], int i, int j);
void freelines(char *lineptr[], int nlines);


int main()
{
    /* ------------------------------------------------------------
       The declaration
       ------------------------------------------------------------ */
    char *names[4];

    names[0] = "banana";
    names[1] = "apple";
    names[2] = "cherry";
    names[3] = "date";

    printf("THE DECLARATION\n");
    printf("  char *names[4];\n");
    printf("  says names is an array of 4 elements, each a pointer to char\n");
    printf("\n");
    printf("  names[1]  is a character pointer:        %s\n", names[1]);
    printf("  *names[1] is the character it points to: %c\n", *names[1]);
    printf("\n");


    /* ------------------------------------------------------------
       swap - K&R's version verbatim
       ------------------------------------------------------------ */
    printf("SWAP\n");
    printf("  K&R: since any individual element of v is a character\n");
    printf("  pointer, temp must be also, so one can be copied to the other.\n");
    printf("\n");
    printf("  before: names[0]=%s names[1]=%s\n", names[0], names[1]);
    swap(names, 0, 1);
    printf("  after:  names[0]=%s names[1]=%s\n", names[0], names[1]);
    printf("\n");


    /* ------------------------------------------------------------
       qsort - the Chapter 4 algorithm, unchanged except for strcmp
       ------------------------------------------------------------ */
    char *fruit[7];
    int i;

    fruit[0] = "banana";
    fruit[1] = "apple";
    fruit[2] = "cherry";
    fruit[3] = "date";
    fruit[4] = "elderberry";
    fruit[5] = "fig";
    fruit[6] = "grape";

    printf("QSORT\n");
    printf("  The quicksort from Chapter 4 needs minor changes: the\n");
    printf("  declarations, and the comparison must call strcmp.\n");
    printf("  The algorithm remains the same.\n");
    printf("\n");

    printf("  before: ");
    for (i = 0; i < 7; i++)
        printf("%s ", fruit[i]);
    printf("\n");

    qsort_str(fruit, 0, 6);

    printf("  after:  ");
    for (i = 0; i < 7; i++)
        printf("%s ", fruit[i]);
    printf("\n\n");


    /* ------------------------------------------------------------
       writelines - both forms K&R gives
       ------------------------------------------------------------ */
    printf("WRITELINES, index form\n");
    writelines(fruit, 7);
    printf("\n");

    printf("WRITELINES, pointer form using *lineptr++\n");
    printf("  Initially *lineptr points to the first line; each element\n");
    printf("  advances it to the next line pointer while nlines is\n");
    printf("  counted down.\n");
    writelines_ptr(fruit, 7);
    printf("\n");


    /* ------------------------------------------------------------
       char *v[] and char **v as parameters
       ------------------------------------------------------------ */
    printf("PARAMETER FORMS\n");
    printf("  void writelines(char *lineptr[], int nlines)\n");
    printf("  void writelines(char **lineptr, int nlines)\n");
    printf("  are identical. An array parameter is converted to a pointer\n");
    printf("  to its first element, and that element is a char *.\n");
    printf("\n");


    /* ------------------------------------------------------------
       The full program: read, sort, write
       ------------------------------------------------------------ */
    int nlines;

    printf("THE SORT PROGRAM\n");
    printf("  Type some lines, then press Ctrl-D on a blank line.\n");
    printf("  Or run this with input redirected:  ./5.6A-book < file.txt\n");
    printf("  --- reading ---\n");

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        printf("  --- read %d line(s), sorting ---\n", nlines);
        qsort_str(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        freelines(lineptr, nlines);
    } else {
        printf("  error: input too big to sort\n");
        return 1;
    }

    return 0;
}


/* readlines: read input lines
   K&R uses getline from 1.9 and alloc from 5.4.
   This uses fgets and malloc instead.

   Note: K&R prints this line as
       if (nlines >= maxlines || p = alloc(len) == NULL)
   which parses as p = (alloc(len) == NULL) because == binds tighter
   than =. The parentheses below are the fix. */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while (fgets(line, MAXLEN, stdin) != NULL) {
        len = strlen(line);
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';     /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}


/* writelines: write output lines, index form */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("  %s\n", lineptr[i]);
}


/* writelines_ptr: write output lines, pointer form */
void writelines_ptr(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("  %s\n", *lineptr++);
}


/* qsort_str: sort v[left]...v[right] into increasing order.
   Named qsort_str to avoid colliding with the library qsort.
   Otherwise this is K&R's function verbatim. */
void qsort_str(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)      /* do nothing if array contains */
        return;             /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_str(v, left, last-1);
    qsort_str(v, last+1, right);
}


/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/* freelines: release what readlines allocated */
void freelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        free(lineptr[i]);
}
