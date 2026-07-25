/*
8.4A - Random Access lseek: worked examples
Compile: gcc -Wall -Wextra -o 8.4A 8.4A_random_access_lseek.c
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define PERMS 0666
#define RECSIZE 16

int get(int fd, long pos, char *buf, int n);

int main(void)
{
    int fd, n;
    char buf[64];
    long pos;

    /* build a playground file: "0123456789ABCDEF..." */
    fd = creat("demo84.txt", PERMS);
    write(fd, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", 36);
    close(fd);

    fd = open("demo84.txt", O_RDWR, 0);
    if (fd == -1) { fprintf(stderr, "open failed\n"); exit(1); }

    /* 1: sequential reads move the position */
    printf("=== Example 1: sequential position ===\n");
    read(fd, buf, 5); buf[5] = '\0';
    printf("first 5: \"%s\"  ", buf);
    read(fd, buf, 5); buf[5] = '\0';
    printf("next 5: \"%s\" (continued where we stopped)\n", buf);

    /* 2: rewind with lseek(fd, 0L, 0) */
    printf("\n=== Example 2: rewind ===\n");
    lseek(fd, 0L, 0);
    read(fd, buf, 5); buf[5] = '\0';
    printf("after rewind: \"%s\" again\n", buf);

    /* 3: absolute jump */
    printf("\n=== Example 3: absolute seek ===\n");
    lseek(fd, 10L, 0);
    read(fd, buf, 6); buf[6] = '\0';
    printf("bytes 10..15: \"%s\"\n", buf);

    /* 4: relative jump (origin 1) */
    printf("\n=== Example 4: relative seek ===\n");
    lseek(fd, 4L, 1);                    /* skip 4 from current */
    read(fd, buf, 3); buf[3] = '\0';
    printf("skip 4, read 3: \"%s\"\n", buf);

    /* 5: from the end (origin 2) */
    printf("\n=== Example 5: seek from end ===\n");
    lseek(fd, -5L, 2);
    n = read(fd, buf, 5); buf[n] = '\0';
    printf("last 5 bytes: \"%s\"\n", buf);

    /* 6: lseek returns the new position */
    printf("\n=== Example 6: return value = position ===\n");
    pos = lseek(fd, 0L, 2);
    printf("seek to end reports file size: %ld bytes\n", pos);
    pos = lseek(fd, 0L, 1);
    printf("seek 0 from current = tell(): %ld\n", pos);

    /* 7: K&R's get() - seek+read in one call */
    printf("\n=== Example 7: get(fd, pos, buf, n) ===\n");
    n = get(fd, 26L, buf, 10);
    buf[n] = '\0';
    printf("get 10 bytes at pos 26: \"%s\"\n", buf);

    /* 8: fixed-size records = disk array */
    printf("\n=== Example 8: record arithmetic ===\n");
    for (int k = 2; k >= 0; k--) {                /* read records BACKWARD */
        lseek(fd, (long)k * RECSIZE, 0);
        n = read(fd, buf, RECSIZE);
        buf[n] = '\0';
        printf("record %d: \"%s\"\n", k, buf);
    }

    /* 9: overwrite in place - random-access WRITE */
    printf("\n=== Example 9: patch bytes in place ===\n");
    lseek(fd, 0L, 0);
    write(fd, "#####", 5);
    lseek(fd, 0L, 0);
    n = read(fd, buf, 12); buf[n] = '\0';
    printf("after patching first 5: \"%s\"\n", buf);

    /* 10: holes - seek past EOF and write */
    printf("\n=== Example 10: files can have holes ===\n");
    lseek(fd, 50L, 0);                   /* beyond the 36-byte end */
    write(fd, "END", 3);
    pos = lseek(fd, 0L, 2);
    lseek(fd, 40L, 0);
    n = read(fd, buf, 13);
    printf("size now %ld; bytes 40..52: ", pos);
    for (int i = 0; i < n; i++)
        printf(buf[i] == '\0' ? "\\0" : "%c", buf[i]);
    printf("  (zeros fill the hole)\n");

    close(fd);
    unlink("demo84.txt");
    return 0;
}

/* K&R 8.4: read n bytes from position pos */
int get(int fd, long pos, char *buf, int n)
{
    if (lseek(fd, pos, 0) >= 0)
        return read(fd, buf, n);
    else
        return -1;
}
