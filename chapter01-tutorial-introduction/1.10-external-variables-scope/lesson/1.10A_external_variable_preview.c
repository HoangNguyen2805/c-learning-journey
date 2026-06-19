#include <stdio.h>

int count;

void addOne(void);

int main() {
    count = 0;

    printf("Before function calls: %d\n", count);

    addOne();
    addOne();
    addOne();

    printf("After function calls: %d\n", count);

    return 0;
}

void addOne(void) {
    count = count + 1;

    printf("Inside addOne: %d\n", count);
}