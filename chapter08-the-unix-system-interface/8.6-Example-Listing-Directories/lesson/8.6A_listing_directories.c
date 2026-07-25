/*
8.6A - Listing Directories: worked examples
Compile: gcc -Wall -Wextra -o 8.6A 8.6A_listing_directories.c
Uses the modern <dirent.h> (same interface K&R builds by hand).
Creates its own small directory tree, walks it, cleans up.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024

void fsize(char *name);
void dirwalk(char *dir, void (*fcn)(char *));
void justname(char *name);

static long total_bytes = 0;
static int file_count = 0;

int main(void)
{
    /* build a demo tree: demo86/{a.txt,b.txt,sub/{c.txt}} */
    mkdir("demo86", 0777);
    mkdir("demo86/sub", 0777);
    int fd = creat("demo86/a.txt", 0666); write(fd, "aaaa\n", 5); close(fd);
    fd = creat("demo86/b.txt", 0666); write(fd, "bbbbbbbb\n", 9); close(fd);
    fd = creat("demo86/sub/c.txt", 0666); write(fd, "cc\n", 3); close(fd);

    /* 1: stat fills a struct with inode info */
    printf("=== Example 1: stat ===\n");
    struct stat st;
    if (stat("demo86/a.txt", &st) == 0)
        printf("a.txt: size=%ld bytes mode=%o\n",
               (long)st.st_size, st.st_mode & 0777);

    /* 2: type testing with S_IFMT */
    printf("\n=== Example 2: file or directory? ===\n");
    stat("demo86", &st);
    printf("demo86 is %s\n",
           (st.st_mode & S_IFMT) == S_IFDIR ? "a DIRECTORY" : "a file");
    stat("demo86/a.txt", &st);
    printf("demo86/a.txt is %s\n",
           (st.st_mode & S_IFMT) == S_IFDIR ? "a directory" : "a regular FILE");

    /* 3: the opendir/readdir loop */
    printf("\n=== Example 3: raw directory read ===\n");
    DIR *dfd = opendir("demo86");
    struct dirent *dp;
    while ((dp = readdir(dfd)) != NULL)
        printf("entry: %s\n", dp->d_name);
    closedir(dfd);
    printf("note '.' and '..' appear in EVERY directory\n");

    /* 4: why we skip . and .. */
    printf("\n=== Example 4: the recursion trap ===\n");
    printf("recursing into '.' revisits the same dir forever -> skip both\n");

    /* 5: building full paths safely */
    printf("\n=== Example 5: path building ===\n");
    char name[MAX_PATH];
    sprintf(name, "%s/%s", "demo86", "a.txt");
    printf("dir + '/' + entry = \"%s\" (with length check first!)\n", name);

    /* 6: the full K&R fsize walk */
    printf("\n=== Example 6: fsize on the tree ===\n");
    fsize((char *)"demo86");

    /* 7: dirwalk is generic - different callback, same walker */
    printf("\n=== Example 7: dirwalk with another callback ===\n");
    dirwalk((char *)"demo86", justname);

    /* 8: accumulate stats via the callback (mini du) */
    printf("\n=== Example 8: totals gathered during the walk ===\n");
    printf("files visited: %d, bytes (files only): %ld\n",
           file_count, total_bytes);

    /* cleanup */
    unlink("demo86/sub/c.txt");
    unlink("demo86/a.txt");
    unlink("demo86/b.txt");
    rmdir("demo86/sub");
    rmdir("demo86");
    printf("\n(demo tree removed)\n");
    return 0;
}

/* K&R fsize: print size of file name; recurse if directory */
void fsize(char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    else {                                   /* count regular files */
        total_bytes += (long)stbuf.st_size;
        file_count++;
    }
    printf("%8ld %s\n", (long)stbuf.st_size, name);
}

/* K&R dirwalk: apply fcn to all entries in dir */
void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0
         || strcmp(dp->d_name, "..") == 0)
            continue;
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n",
                    dir, dp->d_name);
        else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}

/* alternative callback: just print the path */
void justname(char *name)
{
    printf("visit: %s\n", name);
}
