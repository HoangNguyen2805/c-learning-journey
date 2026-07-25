/*
8.3A - Open, Creat, Close, Unlink: worked examples
Compile: gcc -Wall -Wextra -o 8.3A 8.3A_open_creat_close_unlink.c
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define PERMS 0666

void error(char *fmt, ...);
int filesize_by_read(const char *name);

int main(void)
{
    int fd, n;
    char buf[BUFSIZ];

    /* 1: creat makes a file with permissions */
    printf("=== Example 1: creat ===\n");
    fd = creat("demo83.txt", PERMS);
    if (fd == -1)
        error("can't create demo83.txt");
    printf("created demo83.txt with mode %03o, got fd %d\n", PERMS, fd);
    write(fd, "hello syscalls\nline two\n", 24);
    close(fd);

    /* 2: open existing for read */
    printf("\n=== Example 2: open O_RDONLY ===\n");
    fd = open("demo83.txt", O_RDONLY, 0);
    if (fd == -1)
        error("can't open demo83.txt");
    n = read(fd, buf, BUFSIZ);
    printf("read %d bytes back:\n", n);
    write(1, buf, n);
    close(fd);

    /* 3: open failure returns -1 (not NULL!) */
    printf("\n=== Example 3: failure = -1 ===\n");
    fd = open("no_such_file_83.txt", O_RDONLY, 0);
    printf("opening missing file -> %d (an int, so -1 not NULL)\n", fd);

    /* 4: creat TRUNCATES an existing file */
    printf("\n=== Example 4: creat truncates ===\n");
    printf("size before: %d bytes\n", filesize_by_read("demo83.txt"));
    fd = creat("demo83.txt", PERMS);       /* boom - zero length */
    close(fd);
    printf("size after creat: %d bytes (content destroyed)\n",
           filesize_by_read("demo83.txt"));

    /* 5: the cp core - copy with error checks */
    printf("\n=== Example 5: cp core loop ===\n");
    fd = creat("demo83.txt", PERMS);
    write(fd, "copy me correctly\n", 18);
    close(fd);
    int f1 = open("demo83.txt", O_RDONLY, 0);
    int f2 = creat("copy83.txt", PERMS);
    if (f1 == -1 || f2 == -1)
        error("cp setup failed");
    while ((n = read(f1, buf, BUFSIZ)) > 0)
        if (write(f2, buf, n) != n)
            error("write error on copy83.txt");
    close(f1);
    close(f2);
    printf("copied demo83.txt -> copy83.txt (write==n checked each chunk)\n");

    /* 6: O_CREAT|O_APPEND - the modern log-file open */
    printf("\n=== Example 6: open with O_APPEND ===\n");
    fd = open("copy83.txt", O_WRONLY | O_APPEND, 0);
    write(fd, "appended via O_APPEND\n", 22);
    close(fd);
    printf("appended a line; total now %d bytes\n",
           filesize_by_read("copy83.txt"));

    /* 7: close frees the descriptor slot */
    printf("\n=== Example 7: descriptors are reused after close ===\n");
    int fa = open("demo83.txt", O_RDONLY, 0);
    printf("opened -> fd %d\n", fa);
    close(fa);
    int fb = open("demo83.txt", O_RDONLY, 0);
    printf("closed, reopened -> fd %d (same slot recycled)\n", fb);
    close(fb);

    /* 8: unlink removes the NAME */
    printf("\n=== Example 8: unlink ===\n");
    unlink("demo83.txt");
    unlink("copy83.txt");
    printf("unlink'd both; open now: %d (gone)\n",
           open("demo83.txt", O_RDONLY, 0));

    /* 9: the error() helper is 7.3+7.6 in one function */
    printf("\n=== Example 9: error() anatomy ===\n");
    printf("error(fmt, ...) = va_start + vfprintf(stderr) + exit(1)\n");
    printf("(not fired here - it would end the demo!)\n");

    return 0;
}

/* print an error message and die - K&R 8.3 */
void error(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

/* count a file's bytes the 8.2 way */
int filesize_by_read(const char *name)
{
    char buf[BUFSIZ];
    int fd = open(name, O_RDONLY, 0);
    int n, total = 0;

    if (fd == -1)
        return -1;
    while ((n = read(fd, buf, BUFSIZ)) > 0)
        total += n;
    close(fd);
    return total;
}
