/*
8.2A - Low Level I/O Read and Write: worked examples
Compile: gcc -Wall -Wextra -o 8.2A 8.2A_low_level_io_read_and_write.c
Note: my_getchar* names avoid clashing with the real library.
Try:  echo "hello low level" | ./8.2A
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int my_getchar_unbuf(void);
int my_getchar_buf(void);

int main(void)
{
    char buf[BUFSIZ];
    int n;

    /* 1: write with explicit byte counts */
    const char *m = "=== Example 1: raw write ===\n";
    write(1, m, strlen(m));
    n = write(1, "exactly-eighteen b\n", 19);
    printf("write returned %d (bytes actually written)\n", n);

    /* 2: BUFSIZ - the efficient chunk */
    printf("\n=== Example 2: BUFSIZ ===\n");
    printf("BUFSIZ on this system = %d bytes\n", BUFSIZ);

    /* 3: the raw copy loop over a real file */
    printf("\n=== Example 3: read/write copy loop ===\n");
    int fd = open("demo82.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    write(fd, "chunked copying demo\nsecond line\n", 33);
    close(fd);
    fd = open("demo82.txt", O_RDONLY, 0);
    while ((n = read(fd, buf, BUFSIZ)) > 0)
        write(1, buf, n);                 /* n, NOT BUFSIZ! */
    close(fd);

    /* 4: read returns the true count - partial chunks */
    printf("\n=== Example 4: partial reads ===\n");
    fd = open("demo82.txt", O_RDONLY, 0);
    n = read(fd, buf, 7);                 /* ask for only 7 */
    buf[n] = '\0';
    printf("asked 7, got %d: \"%s\"\n", n, buf);
    n = read(fd, buf, BUFSIZ);            /* rest of file */
    printf("next read got the remaining %d bytes\n", n);
    n = read(fd, buf, BUFSIZ);
    printf("read at end of file returns %d\n", n);
    close(fd);

    /* 5: unbuffered my_getchar (1 syscall per char) */
    printf("\n=== Example 5: unbuffered getchar ===\n");
    printf("(reading 3 chars from stdin if available)\n");
    for (int i = 0; i < 3; i++) {
        int c = my_getchar_unbuf();
        if (c == EOF) { printf("[EOF]"); break; }
        printf("[%c]", c);
    }
    printf("\n");

    /* 6: buffered my_getchar (static state) */
    printf("\n=== Example 6: buffered getchar ===\n");
    int c, shown = 0;
    while ((c = my_getchar_buf()) != EOF && shown < 12) {
        if (c == '\n') printf("\\n");
        else putchar(c);
        shown++;
    }
    printf("\n(one read() call likely served ALL those chars)\n");

    /* 7: why the unsigned char cast matters */
    printf("\n=== Example 7: the (unsigned char) cast ===\n");
    printf("byte 0xFF as signed char = -1 = would equal EOF by accident!\n");
    printf("cast to unsigned char -> 255, distinct from EOF\n");

    /* 8: no records at this layer */
    printf("\n=== Example 8: bytes, not lines ===\n");
    printf("read() never heard of 'lines' - '\\n' is just byte 0x0a\n");
    printf("line structure is a program-level convention\n");

    remove("demo82.txt");
    return 0;
}

/* K&R unbuffered getchar */
int my_getchar_unbuf(void)
{
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

/* K&R buffered getchar */
int my_getchar_buf(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) {                /* buffer empty */
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
