#include <stdio.h>

int externalCount;

void countCalls(void) {
    static int staticCount;

    externalCount++;
    staticCount++;

    printf("externalCount: %d\n", externalCount);
    printf("staticCount: %d\n", staticCount);
}

int main() {
    countCalls();
    countCalls();
    countCalls();

    return 0;
}