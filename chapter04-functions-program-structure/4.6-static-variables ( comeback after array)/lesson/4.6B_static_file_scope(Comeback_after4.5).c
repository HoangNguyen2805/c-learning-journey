// NOTE: This uses arrays AND demonstrates a concept (file-privacy)
// that only fully matters in multi-file programs. Revisit fully
// after Ch.5 (arrays) and Ch.4.5 (header files).
#include <stdio.h>

#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        val[sp] = f;
        sp++;
    }
    else {
        printf("Error: stack full\n");
    }
}

double pop(void) {
    if (sp > 0) {
        sp--;
        return val[sp];
    }
    else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

int main() {
    double result;

    push(10.0);
    push(20.0);

    result = pop() + pop();

    printf("Result: %.1f\n", result);

    return 0;
}
/*
Expected:

```text
Result: 30.0
```

Important:

```text
sp and val are static.
That means they are private stack data.
main does not directly touch sp or val.
main only uses push and pop.
```
*/