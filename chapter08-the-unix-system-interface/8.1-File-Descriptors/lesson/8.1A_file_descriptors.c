/*
8.1A - File Descriptors: worked examples
Compile: gcc -Wall -Wextra -o 8.1A 8.1A_file_descriptors.c
Note: <unistd.h> declares read/write/close on modern UNIX
      (K&R's fictional "syscalls.h" stood in for this).
Try:  ./8.1A            then  ./8.1A > out.txt   (fd1 lines vanish into file)
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    /* 1: the three standard descriptors, by number */
    const char *m1 = "=== Example 1: write() to fd 1 (stdout) ===\n";
    write(1, m1, strlen(m1));
    write(1, "this text used NO stdio at all - raw fd 1\n", 42);

    /* 2: fd 2 = stderr - redirect stdout and this still shows */
    const char *m2 = "[fd 2] errors go here - survives > redirection\n";
    write(2, m2, strlen(m2));

    /* 3: the constants have names in unistd.h */
    printf("\n=== Example 3: symbolic names ===\n");
    printf("STDIN_FILENO=%d STDOUT_FILENO=%d STDERR_FILENO=%d\n",
           STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);

    /* 4: FILE* wraps a descriptor - fileno() reveals it */
    printf("\n=== Example 4: fileno(FILE*) ===\n");
    printf("fileno(stdin)=%d fileno(stdout)=%d fileno(stderr)=%d\n",
           fileno(stdin), fileno(stdout), fileno(stderr));

    /* 5: mixing layers needs care - flush before raw writes */
    printf("\n=== Example 5: buffering difference ===\n");
    printf("stdio line (buffered)... ");
    fflush(stdout);                       /* force it out NOW */
    write(1, "[raw write lands here]", 22);
    printf(" ...stdio continues\n");
    printf("without fflush, the raw write could appear FIRST\n");

    /* 6: a new fd from fopen sits above 2 */
    printf("\n=== Example 6: opened files get the next free fd ===\n");
    FILE *fp = fopen("fd_demo81.txt", "w");
    if (fp != NULL) {
        printf("fopen'd file has fd %d (first free after 0,1,2)\n",
               fileno(fp));
        fclose(fp);
        remove("fd_demo81.txt");
    }

    /* 7: redirection is invisible to the program */
    printf("\n=== Example 7: prove redirection transparency ===\n");
    printf("run me twice:  ./8.1A   vs   ./8.1A > out.txt 2> err.txt\n");
    printf("the CODE never changes - the shell moved fds 1 and 2\n");

    /* 8: uniformity - the terminal is a file */
    printf("\n=== Example 8: everything is a file ===\n");
    printf("isatty(1) = %d  (1 when fd 1 is a terminal, 0 when redirected)\n",
           isatty(1));

    return 0;
}
