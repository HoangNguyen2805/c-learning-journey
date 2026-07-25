/*
6.6A - Table Lookup (hash table): worked examples
Compile: gcc -Wall -Wextra -o 6.6A 6.6A_table_lookup.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

unsigned hash(const char *s);
struct nlist *lookup(const char *s);
struct nlist *install(const char *name, const char *defn);
int undef(const char *name);
char *dupstr(const char *s);
void table_stats(void);
void free_table(void);

int main(void)
{
    /* 1: the hash function maps strings to slots */
    printf("=== Example 1: hashing strings ===\n");
    printf("hash(\"PI\")=%u  hash(\"EOF\")=%u  hash(\"MAX\")=%u\n",
           hash("PI"), hash("EOF"), hash("MAX"));
    printf("all < HASHSIZE (%d) thanks to %% HASHSIZE\n", HASHSIZE);

    /* 2: install new definitions */
    printf("\n=== Example 2: install ===\n");
    install("PI", "3.14159");
    install("EOF", "-1");
    install("MAXLINE", "1000");
    printf("installed PI, EOF, MAXLINE\n");

    /* 3: lookup hits and misses */
    printf("\n=== Example 3: lookup ===\n");
    struct nlist *np = lookup("PI");
    printf("PI -> %s\n", np ? np->defn : "(missing)");
    printf("TAU -> %s\n", lookup("TAU") ? "found" : "NULL (not defined)");

    /* 4: install on existing name REPLACES */
    printf("\n=== Example 4: redefinition ===\n");
    install("PI", "3.14159265358979");
    printf("PI now -> %s (old defn freed, name kept)\n", lookup("PI")->defn);

    /* 5: forcing a collision to see chaining */
    printf("\n=== Example 5: collisions chain ===\n");
    /* find two short names that collide */
    char a[3] = "aa", found = 0;
    for (char c1 = 'a'; c1 <= 'z' && !found; c1++)
        for (char c2 = 'a'; c2 <= 'z' && !found; c2++) {
            a[0] = c1; a[1] = c2;
            if (strcmp(a, "PI") != 0 && hash(a) == hash("PI")) {
                found = 1;
                install(a, "collider");
                printf("\"%s\" also hashes to %u - chained with PI's slot\n",
                       a, hash(a));
                printf("both still retrievable: %s=%s, PI=%s\n",
                       a, lookup(a)->defn, lookup("PI")->defn);
            }
        }
    if (!found) printf("(no 2-letter collider found)\n");

    /* 6: push-front order - newest first in chain */
    printf("\n=== Example 6: chain order ===\n");
    unsigned h = hash("PI");
    printf("slot %u chain: ", h);
    for (np = hashtab[h]; np != NULL; np = np->next)
        printf("[%s] -> ", np->name);
    printf("NULL   (newest entries first)\n");

    /* 7: the standard list-walk idiom */
    printf("\n=== Example 7: dump entire table ===\n");
    for (int i = 0; i < HASHSIZE; i++)
        for (np = hashtab[i]; np != NULL; np = np->next)
            printf("  slot %3d: %s = %s\n", i, np->name, np->defn);

    /* 8: undef - deletion with chain relinking */
    printf("\n=== Example 8: undef ===\n");
    printf("undef(\"EOF\") -> %s\n", undef("EOF") ? "removed" : "not found");
    printf("lookup(\"EOF\") now -> %s\n", lookup("EOF") ? "found" : "NULL");
    printf("undef(\"NOPE\") -> %s\n", undef("NOPE") ? "removed" : "not found");

    /* 9: distribution stats */
    printf("\n=== Example 9: table statistics ===\n");
    table_stats();

    free_table();
    return 0;
}

unsigned hash(const char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = (unsigned)*s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(const char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(const char *name, const char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = dupstr(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = dupstr(defn)) == NULL)
        return NULL;
    return np;
}

/* remove name from the table; 1 if removed, 0 if absent */
int undef(const char *name)
{
    unsigned h = hash(name);
    struct nlist *np, *prev = NULL;

    for (np = hashtab[h]; np != NULL; prev = np, np = np->next)
        if (strcmp(name, np->name) == 0) {
            if (prev == NULL)
                hashtab[h] = np->next;     /* was chain head */
            else
                prev->next = np->next;     /* bypass it      */
            free(np->name);
            free(np->defn);
            free(np);
            return 1;
        }
    return 0;
}

char *dupstr(const char *s)
{
    char *p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

void table_stats(void)
{
    int used = 0, entries = 0, longest = 0;
    for (int i = 0; i < HASHSIZE; i++) {
        int len = 0;
        for (struct nlist *np = hashtab[i]; np; np = np->next)
            len++;
        if (len > 0) used++;
        entries += len;
        if (len > longest) longest = len;
    }
    printf("entries=%d, slots used=%d/%d, longest chain=%d\n",
           entries, used, HASHSIZE, longest);
}

void free_table(void)
{
    for (int i = 0; i < HASHSIZE; i++) {
        struct nlist *np = hashtab[i];
        while (np != NULL) {
            struct nlist *nx = np->next;
            free(np->name);
            free(np->defn);
            free(np);
            np = nx;
        }
        hashtab[i] = NULL;
    }
}
