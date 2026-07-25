/*
Section 5.6 - Pointer Arrays; Pointers to Pointers
Worked examples, from-scratch version.

These follow the seven layers of 5.6-pointer-arrays-from-scratch.md.
Read that file first. Each example here corresponds to a layer, so when
something in the lesson did not land, run the matching example and watch it.

Compile:  gcc 5.6A_pointer-arrays-from-scratch.c -o 5.6A-scratch
Run:      ./5.6A-scratch
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *v[], int i, int j);
void show(char *label, char *v[], int n);


int main()
{
    /* =====================================================
       LAYER 1 - a pointer is a variable holding an address
       ===================================================== */
    char c;
    char *p;

    c = 'A';
    p = &c;

    printf("LAYER 1: a pointer is a variable holding an address\n");
    printf("  c        = %c\n", c);
    printf("  &c       = %p    <- where c lives\n", (void *)&c);
    printf("  p        = %p    <- p holds that address\n", (void *)p);
    printf("  &p       = %p    <- p has its own address too\n", (void *)&p);
    printf("  *p       = %c            <- follow the arrow\n", *p);
    printf("  p is a variable in its own right. That is the whole basis.\n");
    printf("\n");


    /* =====================================================
       LAYER 2 - a string is an address
       ===================================================== */
    char *s;

    s = "hello";

    printf("LAYER 2: a string is an address\n");
    printf("  s        = %p    <- s holds an address, not text\n", (void *)s);
    printf("  *s       = %c            <- the first character\n", *s);
    printf("  s[0]     = %c\n", s[0]);
    printf("  s[1]     = %c\n", s[1]);
    printf("  printf %%s follows the arrow and prints to the \\0: %s\n", s);
    printf("\n");


    /* =====================================================
       LAYER 3 - an array of pointers
       ===================================================== */
    char *words[3];

    words[0] = "banana";
    words[1] = "apple";
    words[2] = "cherry";

    printf("LAYER 3: an array of pointers\n");
    printf("  the array itself is contiguous:\n");
    printf("    &words[0] = %p\n", (void *)&words[0]);
    printf("    &words[1] = %p   <- exactly %lu bytes further on\n",
           (void *)&words[1], (unsigned long)sizeof(char *));
    printf("    &words[2] = %p\n", (void *)&words[2]);
    printf("  what they point at is scattered:\n");
    printf("    words[0]  = %p  -> %s\n", (void *)words[0], words[0]);
    printf("    words[1]  = %p  -> %s\n", (void *)words[1], words[1]);
    printf("    words[2]  = %p  -> %s\n", (void *)words[2], words[2]);
    printf("\n");

    printf("LAYER 3b: words[i] versus *words[i]\n");
    printf("  words[1]  is a char *, the whole string: %s\n", words[1]);
    printf("  *words[1] is a char, its first letter:   %c\n", *words[1]);
    printf("  words[1][0] is the same char:            %c\n", words[1][0]);
    printf("  words[1][3] is the fourth char:          %c\n", words[1][3]);
    printf("\n");


    /* =====================================================
       LAYER 4 - swapping pointers does not move text
       ===================================================== */
    char *pair[2];

    pair[0] = "second";
    pair[1] = "first";

    printf("LAYER 4: the payoff - swap moves arrows, not characters\n");
    printf("  BEFORE\n");
    printf("    pair[0] = %-8s living at %p\n", pair[0], (void *)pair[0]);
    printf("    pair[1] = %-8s living at %p\n", pair[1], (void *)pair[1]);

    swap(pair, 0, 1);

    printf("  AFTER\n");
    printf("    pair[0] = %-8s living at %p\n", pair[0], (void *)pair[0]);
    printf("    pair[1] = %-8s living at %p\n", pair[1], (void *)pair[1]);
    printf("  Look at the addresses. Each string sits exactly where it did.\n");
    printf("  Only which slot holds which address changed.\n");
    printf("\n");

    printf("LAYER 4b: what a swap costs\n");
    printf("  one pointer is %lu bytes\n", (unsigned long)sizeof(char *));
    printf("  a swap copies that %lu-byte value three times\n",
           (unsigned long)sizeof(char *));
    printf("  and the cost is the same for a 3-char string or a 3000-char one\n");
    printf("\n");


    /* =====================================================
       LAYER 5 - char ** in isolation
       ===================================================== */
    char *word;
    char **wordp;

    word = "hello";
    wordp = &word;

    printf("LAYER 5: peeling back one star at a time\n");
    printf("  wordp   is char **, holds the address of word:  %p\n",
           (void *)wordp);
    printf("  *wordp  is char *,  the string itself:          %s\n", *wordp);
    printf("  **wordp is char,    its first character:        %c\n", **wordp);
    printf("  each * removes one level of indirection\n");
    printf("\n");

    printf("LAYER 5b: an array name used as char **\n");
    printf("  words          -> first element is %s\n", *words);
    printf("  *(words + 1)   -> %s\n", *(words + 1));
    printf("  *(words + 2)   -> %s\n", *(words + 2));
    printf("  words[i] and *(words + i) are the same expression\n");
    printf("\n");


    /* =====================================================
       LAYER 6 - *lineptr++
       ===================================================== */
    char **walk;
    int n;

    printf("LAYER 6: walking with *walk++\n");
    walk = words;
    n = 3;
    while (n-- > 0)
        printf("  got %-8s and walk has now moved on\n", *walk++);
    printf("  walk started at %p and ended at %p\n",
           (void *)words, (void *)walk);
    printf("  the array in main is untouched - walk was only a copy\n");
    printf("  proof, words[0] is still: %s\n", words[0]);
    printf("\n");


    /* =====================================================
       LAYER 7 - why each line needs its own storage
       ===================================================== */
    char buffer[100];
    char *wrong[3];
    char *right[3];
    int i;

    printf("LAYER 7: the reused-buffer trap\n");

    /* the wrong way - store the address of the shared buffer */
    strcpy(buffer, "first line");
    wrong[0] = buffer;
    strcpy(buffer, "second line");
    wrong[1] = buffer;
    strcpy(buffer, "third line");
    wrong[2] = buffer;

    printf("  WRONG - three pointers, one buffer:\n");
    for (i = 0; i < 3; i++)
        printf("    wrong[%d] = %-12s at %p\n",
               i, wrong[i], (void *)wrong[i]);
    printf("    same address three times, so the same text three times\n");

    /* the right way - fresh storage per line */
    strcpy(buffer, "first line");
    right[0] = malloc(strlen(buffer) + 1);
    strcpy(right[0], buffer);

    strcpy(buffer, "second line");
    right[1] = malloc(strlen(buffer) + 1);
    strcpy(right[1], buffer);

    strcpy(buffer, "third line");
    right[2] = malloc(strlen(buffer) + 1);
    strcpy(right[2], buffer);

    printf("  RIGHT - three pointers, three allocations:\n");
    for (i = 0; i < 3; i++)
        printf("    right[%d] = %-12s at %p\n",
               i, right[i], (void *)right[i]);
    printf("    three different addresses, three different lines\n");
    printf("    note the +1 in the malloc - room for the \\0\n");

    for (i = 0; i < 3; i++)
        free(right[i]);
    printf("\n");


    /* =====================================================
       LAYER 7b - strcmp versus <
       ===================================================== */
    printf("LAYER 7b: comparing lines, and the silent wrong answer\n");
    printf("  strcmp(\"apple\", \"banana\")  = %d   negative, apple sorts first\n",
           strcmp("apple", "banana"));
    printf("  strcmp(\"banana\", \"apple\")  = %d   positive\n",
           strcmp("banana", "apple"));
    printf("  strcmp(\"apple\", \"apple\")   = %d   equal\n",
           strcmp("apple", "apple"));
    printf("\n");
    printf("  now the trap. words[0] is %s, words[1] is %s\n",
           words[0], words[1]);
    printf("  strcmp(words[0], words[1]) < 0  is %d   <- compares the text\n",
           strcmp(words[0], words[1]) < 0);
    printf("  words[0] < words[1]             is %d   <- compares ADDRESSES\n",
           words[0] < words[1]);
    printf("  the second one compiles without a warning and is meaningless\n");
    printf("\n");


    /* =====================================================
       Putting it together - a small sort
       ===================================================== */
    char *fruit[6];

    fruit[0] = "banana";
    fruit[1] = "apple";
    fruit[2] = "cherry";
    fruit[3] = "date";
    fruit[4] = "elderberry";
    fruit[5] = "fig";

    printf("ALL TOGETHER: selection sort on the pointer array\n");
    show("  before", fruit, 6);

    {
        int outer, inner, smallest;

        for (outer = 0; outer < 5; outer++) {
            smallest = outer;
            for (inner = outer + 1; inner < 6; inner++)
                if (strcmp(fruit[inner], fruit[smallest]) < 0)
                    smallest = inner;
            if (smallest != outer)
                swap(fruit, outer, smallest);
        }
    }

    show("  after ", fruit, 6);
    printf("  every string is still at the address it started at\n");
    printf("  only the six slots in fruit[] were rearranged\n");

    return 0;
}


/* swap: interchange v[i] and v[j] - three pointer assignments,
   this function is the entire section */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/* show: print each string with the address it lives at */
void show(char *label, char *v[], int n)
{
    int i;

    printf("%s:\n", label);
    for (i = 0; i < n; i++)
        printf("    [%d] %-12s at %p\n", i, v[i], (void *)v[i]);
}
