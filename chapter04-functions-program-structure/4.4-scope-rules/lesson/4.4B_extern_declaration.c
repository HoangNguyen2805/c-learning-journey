#include <stdio.h>

extern int count;

void addOne(void);
void printCount(void);

int main() {
    count = 0;

    printCount();

    addOne();
    addOne();

    printCount();

    return 0;
}

int count;

void addOne(void) {
    count++;
}

void printCount(void) {
    printf("count = %d\n", count);
}