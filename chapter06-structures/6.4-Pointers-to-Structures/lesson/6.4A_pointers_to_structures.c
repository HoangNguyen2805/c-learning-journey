/*
6.4A - Pointers to Structures: worked examples
Compile: gcc -Wall -Wextra -o 6.4A 6.4A_pointers_to_structures.c
*/
#include <stdio.h>
#include <string.h>

struct key {
    char *word;
    int count;
};

struct key keytab[] = {
    { "break", 1 }, { "case", 0 }, { "char", 3 }, { "else", 0 },
    { "for", 2 }, { "if", 5 }, { "int", 4 }, { "while", 2 }
};
#define NKEYS (sizeof keytab / sizeof keytab[0])

struct key *binsearch_p(const char *word, struct key *tab, int n);

int main(void)
{
    struct key *p;

    /* 1: a pointer into a struct array */
    printf("=== Example 1: pointer to a table row ===\n");
    p = &keytab[2];
    printf("p->word=\"%s\"  p->count=%d\n", p->word, p->count);

    /* 2: p++ jumps a WHOLE struct */
    printf("\n=== Example 2: p++ steps one full row ===\n");
    p = keytab;
    printf("row0=%s ", p->word);
    p++;
    printf("after p++: %s (moved %zu bytes)\n", p->word, sizeof(struct key));

    /* 3: pointer-walk the whole table */
    printf("\n=== Example 3: pointer iteration ===\n");
    for (p = keytab; p < keytab + NKEYS; p++)
        printf("%s ", p->word);
    printf("\n");

    /* 4: pointer subtraction counts structs */
    printf("\n=== Example 4: pointer subtraction ===\n");
    struct key *first = &keytab[1], *last = &keytab[6];
    printf("last - first = %td structs apart\n", last - first);

    /* 5: legal midpoint formula */
    printf("\n=== Example 5: low + (high-low)/2 ===\n");
    struct key *low = &keytab[0], *high = &keytab[NKEYS];
    struct key *mid = low + (high - low) / 2;
    printf("midpoint of table = \"%s\"\n", mid->word);
    printf("(low+high)/2 would NOT compile: pointers can't be added)\n");

    /* 6: pointer binary search returning struct* or NULL */
    printf("\n=== Example 6: binsearch returning a pointer ===\n");
    p = binsearch_p("for", keytab, NKEYS);
    if (p != NULL)
        printf("found \"for\" at row %td, count=%d\n", p - keytab, p->count);
    p = binsearch_p("zzz", keytab, NKEYS);
    printf("search \"zzz\" -> %s\n", p == NULL ? "NULL (not found)" : "?");

    /* 7: found-row update through the pointer */
    printf("\n=== Example 7: update via returned pointer ===\n");
    if ((p = binsearch_p("if", keytab, NKEYS)) != NULL) {
        p->count++;
        printf("bumped: %s now %d\n", p->word, p->count);
    }

    /* 8: precedence drills */
    printf("\n=== Example 8: ++p->count vs (++p)->count ===\n");
    p = keytab;                 /* at "break", count 1 */
    ++p->count;
    printf("++p->count : still row \"%s\", count=%d\n", p->word, p->count);
    (++p)->count += 10;
    printf("(++p)->count: moved to \"%s\", count=%d\n", p->word, p->count);

    /* 9: *p->word walks the string, not the table */
    printf("\n=== Example 9: *p->word ===\n");
    p = &keytab[4];             /* "for" */
    printf("first char of p->word: '%c'\n", *p->word);

    /* 10: max-count row via pointer scan */
    printf("\n=== Example 10: find max count ===\n");
    struct key *best = keytab;
    for (p = keytab + 1; p < keytab + NKEYS; p++)
        if (p->count > best->count)
            best = p;
    printf("hottest keyword: %s (%d)\n", best->word, best->count);

    return 0;
}

struct key *binsearch_p(const char *word, struct key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}
