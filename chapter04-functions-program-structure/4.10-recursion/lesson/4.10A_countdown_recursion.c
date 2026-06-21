#include <stdio.h>

void countdown(int n) {
    if (n <= 0) {
        printf("Done\n");
    }
    else {
        printf("%d\n", n);
        countdown(n - 1);
    }
}

int main() {
    countdown(7);

    return 0;
}