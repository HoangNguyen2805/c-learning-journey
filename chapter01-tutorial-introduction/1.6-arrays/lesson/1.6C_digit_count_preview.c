#include <stdio.h>

int main() {
    int c;
    int i;
    int ndigit[10];

    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    printf("Type numbers, then press Ctrl + D to stop:\n");

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ndigit[c - '0']++;
        }
    }

    printf("\nDigit counts:\n");

    for (i = 0; i < 10; i++) {
        printf("%d: %d\n", i, ndigit[i]);
    }

    return 0;
}