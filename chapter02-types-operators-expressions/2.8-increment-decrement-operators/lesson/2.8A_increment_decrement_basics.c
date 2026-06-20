#include <stdio.h>

int main() {
    int x = 5;

    printf("Starting x: %d\n", x);

    x++;
    printf("After x++: %d\n", x);

    ++x;
    printf("After ++x: %d\n", x);

    x--;
    printf("After x--: %d\n", x);

    --x;
    printf("After --x: %d\n", x);

    return 0;
}