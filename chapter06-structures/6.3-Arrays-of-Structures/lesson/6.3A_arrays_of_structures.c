/*
6.3A - Arrays of Structures: worked examples
Compile: gcc -Wall -Wextra -o 6.3A 6.3A_arrays_of_structures.c
*/
#include <stdio.h>
#include <string.h>

struct key {
    char *word;
    int count;
};

struct key keytab[] = {
    { "auto", 0 }, { "break", 0 }, { "case", 0 }, { "char", 0 },
    { "const", 0 }, { "continue", 0 }, { "default", 0 }, { "do", 0 },
    { "else", 0 }, { "for", 0 }, { "if", 0 }, { "int", 0 },
    { "return", 0 }, { "while", 0 }
};

#define NKEYS (sizeof keytab / sizeof keytab[0])

struct score { char name[20]; int points; };

int binsearch(const char *word, struct key tab[], int n);
int linsearch(const char *word, struct key tab[], int n);

int main(void)
{
    /* 1: rows and columns */
    printf("=== Example 1: each element is a full row ===\n");
    printf("keytab[0] = {\"%s\", %d}\n", keytab[0].word, keytab[0].count);
    printf("keytab[9] = {\"%s\", %d}\n", keytab[9].word, keytab[9].count);

    /* 2: the sizeof row-count trick */
    printf("\n=== Example 2: NKEYS via sizeof ===\n");
    printf("total bytes=%zu, bytes/row=%zu, rows=%zu\n",
           sizeof keytab, sizeof keytab[0], NKEYS);

    /* 3: iterating rows */
    printf("\n=== Example 3: loop over rows ===\n");
    for (size_t i = 0; i < 5; i++)
        printf("%s ", keytab[i].word);
    printf("... (%zu keywords total)\n", NKEYS);

    /* 4: updating a member in a row */
    printf("\n=== Example 4: bump counts ===\n");
    keytab[10].count++;                   /* "if"    */
    keytab[10].count++;
    keytab[13].count++;                   /* "while" */
    printf("if=%d while=%d\n", keytab[10].count, keytab[13].count);

    /* 5: linear search on the .word member */
    printf("\n=== Example 5: linear search ===\n");
    printf("linsearch(\"return\") -> index %d\n",
           linsearch("return", keytab, NKEYS));
    printf("linsearch(\"banana\") -> index %d\n",
           linsearch("banana", keytab, NKEYS));

    /* 6: binary search - needs sorted rows */
    printf("\n=== Example 6: binary search (O(log n)) ===\n");
    printf("binsearch(\"const\")  -> index %d\n",
           binsearch("const", keytab, NKEYS));
    printf("binsearch(\"pointer\")-> index %d\n",
           binsearch("pointer", keytab, NKEYS));

    /* 7: simulate the keyword counter on a canned "input" */
    printf("\n=== Example 7: mini keyword count ===\n");
    const char *tokens[] = {"int","main","if","int","x","while","if"};
    for (int i = 0; i < 7; i++) {
        int idx = binsearch(tokens[i], keytab, NKEYS);
        if (idx >= 0)
            keytab[idx].count++;
    }
    for (size_t i = 0; i < NKEYS; i++)
        if (keytab[i].count > 0)
            printf("%4d %s\n", keytab[i].count, keytab[i].word);

    /* 8: struct array with char-array member (copyable rows) */
    printf("\n=== Example 8: rows with embedded char arrays ===\n");
    struct score board[3] = { {"ana",120}, {"bo",95}, {"cy",150} };
    struct score tmp = board[0];          /* whole-row copy */
    board[0] = board[2];
    board[2] = tmp;
    for (int i = 0; i < 3; i++)
        printf("%s:%d ", board[i].name, board[i].points);
    printf(" <- rows swapped by struct assignment\n");

    /* 9: padding - struct size vs member sum */
    printf("\n=== Example 9: alignment padding ===\n");
    struct padded { char c; int n; };
    printf("sizeof(char)+sizeof(int)=%zu but sizeof(struct padded)=%zu\n",
           sizeof(char) + sizeof(int), sizeof(struct padded));
    printf("=> always use sizeof, never hand-add members\n");

    return 0;
}

int binsearch(const char *word, struct key tab[], int n)
{
    int cond, low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int linsearch(const char *word, struct key tab[], int n)
{
    for (int i = 0; i < n; i++)
        if (strcmp(word, tab[i].word) == 0)
            return i;
    return -1;
}
