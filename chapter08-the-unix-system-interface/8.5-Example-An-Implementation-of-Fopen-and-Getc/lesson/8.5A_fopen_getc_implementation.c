/*
8.5A - An Implementation of Fopen and Getc (renamed my_* to coexist
       with the real library)
Compile: gcc -Wall -Wextra -o 8.5A 8.5A_fopen_getc_implementation.c
This is K&R's code, complete and runnable, with a demo main().
*/
#include <stdio.h>      /* only for printf in the demo main */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MY_EOF      (-1)
#define MY_BUFSIZ   1024
#define MY_OPEN_MAX 20
#define PERMS       0666

typedef struct _my_iobuf {
    int  cnt;        /* characters left     */
    char *ptr;       /* next char position  */
    char *base;      /* location of buffer  */
    int  flag;       /* mode of file access */
    int  fd;         /* file descriptor     */
} MYFILE;

enum _flags {
    _READ  = 01,
    _WRITE = 02,
    _UNBUF = 04,
    _EOF   = 010,
    _ERR   = 020
};

MYFILE _my_iob[MY_OPEN_MAX] = {
    { 0, NULL, NULL, _READ,  0 },    /* my_stdin  */
    { 0, NULL, NULL, _WRITE, 1 },    /* my_stdout */
    { 0, NULL, NULL, _WRITE | _UNBUF, 2 }  /* my_stderr */
};

#define my_stdin  (&_my_iob[0])
#define my_stdout (&_my_iob[1])

/* the famous macros */
#define my_getc(p)   (--(p)->cnt >= 0 \
                       ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define my_feof(p)   (((p)->flag & _EOF) != 0)
#define my_ferror(p) (((p)->flag & _ERR) != 0)
#define my_fileno(p) ((p)->fd)

int _fillbuf(MYFILE *fp);
MYFILE *my_fopen(char *name, char *mode);
void my_fclose_lite(MYFILE *fp);

int main(void)
{
    /* build a test file with the REAL library (irony intended) */
    FILE *real = fopen("demo85.txt", "w");
    fputs("stdio built from syscalls!\nsecond line here\n", real);
    fclose(real);

    /* 1: what a FILE holds */
    printf("=== Example 1: the FILE struct ===\n");
    printf("MYFILE members: cnt, ptr, base, flag, fd  (%zu bytes)\n",
           sizeof(MYFILE));

    /* 2: stdin/stdout are array slots */
    printf("\n=== Example 2: _iob[] and the standard streams ===\n");
    printf("my_stdin=&_my_iob[0] fd=%d; my_stdout=&_my_iob[1] fd=%d\n",
           my_fileno(my_stdin), my_fileno(my_stdout));

    /* 3: my_fopen finds a slot and opens */
    printf("\n=== Example 3: my_fopen ===\n");
    MYFILE *fp = my_fopen((char *)"demo85.txt", (char *)"r");
    if (fp == NULL) { printf("my_fopen failed\n"); return 1; }
    printf("slot index=%ld fd=%d flag=%03o cnt=%d base=%s\n",
           (long)(fp - _my_iob), fp->fd, fp->flag, fp->cnt,
           fp->base == NULL ? "NULL (lazy!)" : "allocated");

    /* 4: first my_getc triggers _fillbuf */
    printf("\n=== Example 4: first getc -> _fillbuf -> read() ===\n");
    int c = my_getc(fp);
    printf("got '%c'; NOW base=%s cnt=%d (a whole chunk arrived)\n",
           c, fp->base ? "allocated" : "NULL", fp->cnt);

    /* 5: subsequent getc = pure pointer arithmetic */
    printf("\n=== Example 5: fast path ===\n");
    printf("next chars: ");
    for (int i = 0; i < 10; i++)
        putchar(my_getc(fp));
    printf("  <- zero read() calls for these\n");

    /* 6: drain to EOF; flag bits record it */
    printf("\n=== Example 6: EOF sets flag bits ===\n");
    while ((c = my_getc(fp)) != MY_EOF)
        ;
    printf("after drain: my_feof=%d my_ferror=%d flag=%03o\n",
           my_feof(fp), my_ferror(fp), fp->flag);

    /* 7: mode validation */
    printf("\n=== Example 7: bad mode rejected ===\n");
    printf("my_fopen(name, \"x\") -> %s\n",
           my_fopen((char *)"demo85.txt", (char *)"x") == NULL
           ? "NULL" : "?!");

    /* 8: append mode = open/creat + lseek(0L,2) */
    printf("\n=== Example 8: \"a\" mode machinery ===\n");
    MYFILE *ap = my_fopen((char *)"demo85.txt", (char *)"a");
    if (ap) {
        long pos = lseek(ap->fd, 0L, 1);
        printf("append-opened: position already at %ld (the end)\n", pos);
        my_fclose_lite(ap);
    }

    /* 9: OPEN_MAX exhaustion returns NULL */
    printf("\n=== Example 9: slot exhaustion ===\n");
    int opened = 0;
    MYFILE *many[MY_OPEN_MAX];
    while (opened < MY_OPEN_MAX &&
           (many[opened] = my_fopen((char *)"demo85.txt", (char *)"r")) != NULL)
        opened++;
    printf("could open %d more before slots ran out (NULL returned)\n",
           opened);
    for (int i = 0; i < opened; i++)
        my_fclose_lite(many[i]);

    my_fclose_lite(fp);
    remove("demo85.txt");
    return 0;
}

/* K&R fopen */
MYFILE *my_fopen(char *name, char *mode)
{
    int fd;
    MYFILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for (fp = _my_iob; fp < _my_iob + MY_OPEN_MAX; fp++)
        if ((fp->flag & (_READ | _WRITE)) == 0)
            break;                       /* found free slot */
    if (fp >= _my_iob + MY_OPEN_MAX)     /* no free slots   */
        return NULL;

    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)
        return NULL;

    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}

/* K&R _fillbuf: allocate and fill input buffer */
int _fillbuf(MYFILE *fp)
{
    int bufsize;

    if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
        return MY_EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : MY_BUFSIZ;
    if (fp->base == NULL)                /* no buffer yet */
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return MY_EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flag |= _EOF;
        else
            fp->flag |= _ERR;
        fp->cnt = 0;
        return MY_EOF;
    }
    return (unsigned char) *fp->ptr++;
}

/* minimal close for the demo (Exercise 8-3 asks for the real one) */
void my_fclose_lite(MYFILE *fp)
{
    if (fp != NULL && (fp->flag & (_READ | _WRITE))) {
        close(fp->fd);
        free(fp->base);
        fp->base = NULL;
        fp->flag = 0;
        fp->cnt = 0;
    }
}
