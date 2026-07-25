/*
7.7A - Line Input and Output: worked examples
Compile: gcc -Wall -Wextra -o 7.7A 7.7A_line_input_and_output.c
Uses a self-created demo file, so it runs standalone.
*/
#include <stdio.h>
#include <string.h>

#define MAXLINE 32            /* small ON PURPOSE - see example 5 */

char *my_fgets(char *s, int n, FILE *iop);
int my_fputs(const char *s, FILE *iop);

int main(void)
{
    char line[MAXLINE];
    FILE *fp;

    /* build a demo file */
    fp = fopen("demo77.txt", "w");
    if (!fp) { fprintf(stderr, "can't create demo77.txt\n"); return 1; }
    fputs("first line\n", fp);
    fputs("second line\n", fp);
    fputs("this line is deliberately much longer than thirty-one characters\n", fp);
    fputs("last\n", fp);
    fclose(fp);

    /* 1: canonical fgets loop */
    printf("=== Example 1: fgets loop ===\n");
    fp = fopen("demo77.txt", "r");
    int lineno = 0;
    while (fgets(line, MAXLINE, fp) != NULL)
        printf("%d: %s", ++lineno, line);      /* line has its own \n... */
    fclose(fp);
    printf("(...usually - see example 5!)\n");

    /* 2: fgets keeps the newline */
    printf("\n=== Example 2: the kept newline ===\n");
    fp = fopen("demo77.txt", "r");
    fgets(line, MAXLINE, fp);
    fclose(fp);
    size_t len = strlen(line);
    printf("read %zu chars; last is %s\n", len,
           line[len-1] == '\n' ? "'\\n' (kept!)" : "not newline");

    /* 3: stripping the newline - the standard one-liner */
    printf("\n=== Example 3: strip the newline ===\n");
    if (len > 0 && line[len-1] == '\n')
        line[len-1] = '\0';
    printf("stripped: [%s]\n", line);

    /* 4: fputs adds nothing; puts adds newline */
    printf("\n=== Example 4: fputs vs puts ===\n");
    fputs("fputs: no newline -> ", stdout);
    puts("puts finishes the line (adds \\n)");

    /* 5: long lines arrive in bounded pieces */
    printf("\n=== Example 5: MAXLINE=%d chops long lines safely ===\n", MAXLINE);
    fp = fopen("demo77.txt", "r");
    int piece = 0;
    while (fgets(line, MAXLINE, fp) != NULL) {
        size_t l = strlen(line);
        printf("piece %d (%2zu chars, %s newline)\n",
               ++piece, l, line[l-1] == '\n' ? "with" : "NO");
    }
    fclose(fp);
    printf("no overflow possible - that's why gets() is banned\n");

    /* 6: NULL return distinguishes EOF */
    printf("\n=== Example 6: fgets returns NULL at EOF ===\n");
    fp = fopen("demo77.txt", "r");
    while (fgets(line, MAXLINE, fp) != NULL)
        ;
    printf("loop left: fgets gave NULL; feof=%d ferror=%d\n",
           feof(fp), ferror(fp));
    fclose(fp);

    /* 7: fgets+sscanf - the robust parsing combo */
    printf("\n=== Example 7: fgets + sscanf ===\n");
    const char *rec = "cyrus 150\n";
    char name[16]; int score;
    if (sscanf(rec, "%15s %d", name, &score) == 2)
        printf("parsed record: %s -> %d\n", name, score);

    /* 8: the book's own fgets/fputs (renamed) work identically */
    printf("\n=== Example 8: hand-rolled my_fgets/my_fputs ===\n");
    fp = fopen("demo77.txt", "r");
    my_fgets(line, MAXLINE, fp);
    fclose(fp);
    my_fputs("my_fgets read: ", stdout);
    my_fputs(line, stdout);

    /* 9: line counting with fgets - careful with chopped lines! */
    printf("\n=== Example 9: counting REAL lines ===\n");
    fp = fopen("demo77.txt", "r");
    int lines = 0;
    while (fgets(line, MAXLINE, fp) != NULL)
        if (strchr(line, '\n'))            /* only count pieces ending a line */
            lines++;
    fclose(fp);
    printf("true line count: %d (naive fgets-call count would be wrong)\n",
           lines);

    remove("demo77.txt");
    return 0;
}

/* K&R's fgets, renamed to avoid the library clash */
char *my_fgets(char *s, int n, FILE *iop)
{
    int c = EOF;
    char *cs;

    cs = s;
    while (--n > 0 && (c = getc(iop)) != EOF)
        if ((*cs++ = (char)c) == '\n')
            break;
    *cs = '\0';
    return (c == EOF && cs == s) ? NULL : s;
}

/* K&R's fputs, renamed */
int my_fputs(const char *s, FILE *iop)
{
    int c;

    while ((c = *s++))
        putc(c, iop);
    return ferror(iop) ? EOF : 0;
}
