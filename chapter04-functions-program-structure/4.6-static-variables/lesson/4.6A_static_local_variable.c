#include <stdio.h>

void countCalls(void) {
    static int count = 0;

    count++;

    printf("Function called %d time(s)\n", count);
}

int main() {
    countCalls();
    countCalls();
    countCalls();

    return 0;
}
/*
Expected:

```text
Function called 1 time(s)
Function called 2 time(s)
Function called 3 time(s)
```
*/