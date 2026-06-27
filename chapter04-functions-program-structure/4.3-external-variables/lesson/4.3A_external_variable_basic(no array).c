#include <stdio.h>

int count;

void addOne(void);
void printCount(void);

int main() {
    count = 0;

    printCount();

    addOne();
    addOne();
    addOne();

    printCount();

    return 0;
}

void addOne(void) {
    count = count + 1;
}

void printCount(void) {
    printf("count = %d\n", count);
}