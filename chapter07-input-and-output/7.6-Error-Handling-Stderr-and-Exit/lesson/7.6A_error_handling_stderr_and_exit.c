/*
7.6A - Error Handling stderr and exit: worked examples
Compile: gcc -Wall -Wextra -o 7.6A 7.6A_error_handling_stderr_and_exit.c
Try:     ./7.6A > out.txt        (watch which lines still reach the screen!)
         echo $?                  (see the exit status)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char *prog;                          /* program name for messages */

void warn(const char *fmt, ...);
void fatal(int status, const char *fmt, ...);

int main(int argc, char *argv[])
{
    (void)argc;
    prog = argv[0];

    /* 1: two streams, one program */
    printf("=== Example 1: stdout vs stderr ===\n");
    printf("RESULT: this line goes to stdout (redirectable)\n");
    fprintf(stderr, "NOTICE: this line goes to stderr (stays on screen)\n");

    /* 2: the message convention - prog name prefix */
    printf("\n=== Example 2: prefixed diagnostics ===\n");
    fprintf(stderr, "%s: something worth reporting\n", prog);

    /* 3: fopen failure -> stderr, and a nonzero would follow */
    printf("\n=== Example 3: realistic failure report ===\n");
    FILE *fp = fopen("definitely_missing_file.txt", "r");
    if (fp == NULL)
        fprintf(stderr, "%s: can't open %s\n", prog,
                "definitely_missing_file.txt");
    printf("(a real cat would exit(1) here; we continue for the demo)\n");

    /* 4: a variadic warn() helper - 7.3 pays off */
    printf("\n=== Example 4: warn() wrapper ===\n");
    warn("count %d exceeds limit %d", 120, 100);
    warn("retrying %s", "connection");

    /* 5: feof vs ferror on a healthy stream */
    printf("\n=== Example 5: feof / ferror ===\n");
    fp = fopen("tmp76.txt", "w");
    if (fp) { fprintf(fp, "x\n"); fclose(fp); }
    fp = fopen("tmp76.txt", "r");
    if (fp) {
        int c;
        while ((c = getc(fp)) != EOF)
            ;                                  /* drain */
        printf("after drain: feof=%d ferror=%d\n", feof(fp), ferror(fp));
        fclose(fp);
    }
    remove("tmp76.txt");

    /* 6: checking stdout itself at program end (book pattern) */
    printf("\n=== Example 6: ferror(stdout) final check ===\n");
    if (ferror(stdout))
        fprintf(stderr, "%s: error writing stdout\n", prog);
    else
        printf("stdout healthy\n");

    /* 7: exit statuses - see them from the shell */
    printf("\n=== Example 7: exit status ===\n");
    printf("this run exits 0; run `echo $?` after to confirm\n");
    printf("`./7.6A && echo OK` prints OK only on status 0\n");

    /* 8: exit() vs return in main */
    printf("\n=== Example 8: exit closes+flushes files ===\n");
    printf("exit(expr) == return expr in main; both flush buffers\n");

    /* 9: fatal() - the pattern every real tool has (demonstrated, not fired) */
    printf("\n=== Example 9: fatal() helper exists ===\n");
    printf("fatal(2, \"disk full on %%s\", path) would print to stderr\n");
    printf("and exit(2). We won't call it - the demo wants to reach line end.\n");

    return 0;                                  /* success */
}

/* nonfatal: report and continue */
void warn(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "%s: warning: ", prog);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}

/* fatal: report and quit with status */
void fatal(int status, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "%s: fatal: ", prog);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(status);
}
