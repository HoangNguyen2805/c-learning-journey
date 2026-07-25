/*
7.5A - File Access: worked examples
Compile: gcc -Wall -Wextra -o 7.5A 7.5A_file_access.c
Creates and reads its own demo files in the current directory.
*/
#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp);

int main(void)
{
    FILE *fp;

    /* 1: open for write, fprintf, close */
    printf("=== Example 1: create + write with fprintf ===\n");
    fp = fopen("demo75.txt", "w");
    if (fp == NULL) {
        printf("can't create demo75.txt\n");
        exit(1);
    }
    fprintf(fp, "line one\n");
    fprintf(fp, "value: %d pi: %.2f\n", 42, 3.14159);
    fclose(fp);
    printf("wrote demo75.txt\n");

    /* 2: open for read + NULL check on a missing file */
    printf("\n=== Example 2: fopen failure returns NULL ===\n");
    fp = fopen("no_such_file_xyz.txt", "r");
    printf("opening missing file -> fp = %s\n", fp == NULL ? "NULL" : "??");

    /* 3: read back char by char with getc */
    printf("\n=== Example 3: getc loop ===\n");
    fp = fopen("demo75.txt", "r");
    if (fp == NULL) { printf("can't open demo75.txt\n"); exit(1); }
    int c;
    while ((c = getc(fp)) != EOF)
        putchar(c);
    fclose(fp);

    /* 4: fscanf pulls typed data back out */
    printf("\n=== Example 4: fscanf ===\n");
    fp = fopen("demo75.txt", "r");
    if (fp == NULL) { printf("reopen failed\n"); exit(1); }
    char w1[16], w2[16];
    int v; double pi;
    fscanf(fp, "%15s %15s", w1, w2);          /* "line" "one"     */
    fscanf(fp, "%*s %d %*s %lf", &v, &pi);    /* skip labels      */
    printf("parsed: %s %s | value=%d pi=%.2f\n", w1, w2, v, pi);
    fclose(fp);

    /* 5: append mode adds to the end */
    printf("\n=== Example 5: append mode ===\n");
    fp = fopen("demo75.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "appended line\n");
        fclose(fp);
    }
    printf("appended one line (re-run ex3 mentally!)\n");

    /* 6: "w" truncates - demonstrate on a scratch file */
    printf("\n=== Example 6: \"w\" truncates ===\n");
    fp = fopen("scratch75.txt", "w");
    fprintf(fp, "AAAA-BBBB-CCCC\n");
    fclose(fp);
    fp = fopen("scratch75.txt", "w");        /* reopen w: content gone */
    fprintf(fp, "short\n");
    fclose(fp);
    fp = fopen("scratch75.txt", "r");
    printf("scratch75 now contains: ");
    while ((c = getc(fp)) != EOF)
        putchar(c);
    fclose(fp);

    /* 7: filecopy between arbitrary streams */
    printf("\n=== Example 7: filecopy(file -> stdout) ===\n");
    fp = fopen("demo75.txt", "r");
    if (fp != NULL) {
        filecopy(fp, stdout);
        fclose(fp);
    }

    /* 8: file-to-file copy */
    printf("\n=== Example 8: copy demo75 -> copy75 ===\n");
    FILE *src = fopen("demo75.txt", "r");
    FILE *dst = fopen("copy75.txt", "w");
    if (src && dst) {
        filecopy(src, dst);
        printf("copied.\n");
    }
    if (src) fclose(src);
    if (dst) fclose(dst);

    /* 9: getchar IS getc(stdin) */
    printf("\n=== Example 9: identities ===\n");
    printf("getchar() == getc(stdin); putchar(c) == putc(c, stdout)\n");
    printf("stdin/stdout/stderr are FILE* already opened for you\n");

    /* cleanup demo artifacts */
    remove("demo75.txt");
    remove("scratch75.txt");
    remove("copy75.txt");
    printf("\n(demo files removed)\n");

    return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}
