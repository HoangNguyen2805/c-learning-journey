/*
7.8A - Miscellaneous Functions: worked examples
Compile: gcc -Wall -Wextra -o 7.8A 7.8A_miscellaneous_functions.c -lm
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    /* 1: strcpy/strcat build strings */
    printf("=== Example 1: strcpy + strcat ===\n");
    char path[64];
    strcpy(path, "/home/hoang");
    strcat(path, "/c-learning-journey");
    printf("built: %s (len=%zu)\n", path, strlen(path));

    /* 2: strcmp family */
    printf("\n=== Example 2: strcmp / strncmp ===\n");
    printf("strcmp(\"apple\",\"apricot\") = %d\n",
           strcmp("apple", "apricot") < 0 ? -1 : 1);
    printf("strncmp(\"apple\",\"apricot\",2) = %d (first 2 equal)\n",
           strncmp("apple", "apricot", 2));

    /* 3: strchr / strrchr */
    printf("\n=== Example 3: strchr / strrchr ===\n");
    const char *file = "notes.backup.txt";
    printf("first '.': \"%s\"\n", strchr(file, '.'));
    printf("last  '.': \"%s\"  <- extension trick\n", strrchr(file, '.'));
    printf("strchr for missing 'z': %s\n",
           strchr(file, 'z') == NULL ? "NULL" : "?");

    /* 4: ctype tour on one sample */
    printf("\n=== Example 4: ctype classification ===\n");
    const char *sample = "Ab3 !";
    for (const char *p = sample; *p; p++)
        printf("'%c': alpha=%d digit=%d alnum=%d space=%d upper=%d\n",
               *p, isalpha((unsigned char)*p) != 0,
               isdigit((unsigned char)*p) != 0,
               isalnum((unsigned char)*p) != 0,
               isspace((unsigned char)*p) != 0,
               isupper((unsigned char)*p) != 0);

    /* 5: ungetc - one char of lookahead */
    printf("\n=== Example 5: ungetc pushback ===\n");
    FILE *fp = fopen("tmp78.txt", "w");
    fputs("42abc", fp);
    fclose(fp);
    fp = fopen("tmp78.txt", "r");
    int c, n = 0;
    while ((c = getc(fp)) != EOF && isdigit(c))
        n = 10 * n + (c - '0');
    if (c != EOF)
        ungetc(c, fp);                    /* give back the 'a' */
    printf("number parsed: %d; next char after pushback: '%c'\n",
           n, getc(fp));
    fclose(fp);
    remove("tmp78.txt");

    /* 6: malloc vs calloc */
    printf("\n=== Example 6: malloc / calloc ===\n");
    int *mp = (int *) malloc(5 * sizeof(int));
    int *cp = (int *) calloc(5, sizeof(int));
    if (mp == NULL || cp == NULL) {
        fprintf(stderr, "out of memory\n");
        return 1;
    }
    printf("calloc zeroes: %d %d %d %d %d\n", cp[0], cp[1], cp[2], cp[3], cp[4]);
    printf("malloc doesn't (values are indeterminate - we won't read them)\n");
    for (int i = 0; i < 5; i++) mp[i] = i * i;
    printf("after filling malloc'd: %d %d %d %d %d\n",
           mp[0], mp[1], mp[2], mp[3], mp[4]);
    free(mp);
    free(cp);

    /* 7: growing string storage - the dupstr pattern */
    printf("\n=== Example 7: heap-allocated copy ===\n");
    const char *src = "temporary buffer contents";
    char *copy = (char *) malloc(strlen(src) + 1);
    if (copy != NULL) {
        strcpy(copy, src);
        printf("independent copy: %s\n", copy);
        free(copy);
    }

    /* 8: math functions */
    printf("\n=== Example 8: math.h (-lm) ===\n");
    printf("sqrt(2)=%.6f  pow(2,10)=%.0f  fabs(-3.5)=%.1f  log10(1000)=%.0f\n",
           sqrt(2.0), pow(2.0, 10.0), fabs(-3.5), log10(1000.0));

    /* 9: rand/srand - reproducible sequences */
    printf("\n=== Example 9: random numbers ===\n");
    srand(42);
    printf("seed 42: %d %d %d\n", rand() % 100, rand() % 100, rand() % 100);
    srand(42);
    printf("seed 42 again: %d %d %d  <- identical sequence!\n",
           rand() % 100, rand() % 100, rand() % 100);

    /* 10: frand in [0,1) and dice */
    printf("\n=== Example 10: frand + dice ===\n");
    srand(7);
    printf("frand: %.3f %.3f | d6 rolls: %d %d %d %d\n",
           (double) rand() / (RAND_MAX + 1.0),
           (double) rand() / (RAND_MAX + 1.0),
           rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1);

    return 0;
}
