// NOTE: This uses arrays AND demonstrates a concept (file-privacy)
// that only fully matters in multi-file programs. Revisit fully
// after Ch.5 (arrays) and Ch.4.5 (header files).
#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void) {
    if (bufp > 0)
        return buf[--bufp];
    else
        return getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("Error: buffer full\n");
    else
        buf[bufp++] = c;
}

int main() {
    int c;

    printf("Type one character: ");

    c = getch();

    printf("First read: %c\n", c);

    ungetch(c);

    printf("After ungetch, read again: %c\n", getch());

    return 0;
}
/*
Example:

```text
Type one character: A
First read: A
After ungetch, read again: A
```

Important:

```text
buf and bufp are static.
That means they are private buffer data.
main does not directly touch buf or bufp.
main only uses getch and ungetch.
```
*/