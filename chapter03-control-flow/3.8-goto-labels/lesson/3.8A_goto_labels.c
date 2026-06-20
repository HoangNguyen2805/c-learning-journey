#include <stdio.h>

int main() {
    int row;
    int col;

    printf("Searching for row 2, col 3\n");

    for (row = 1; row <= 3; row++) {
        for (col = 1; col <= 4; col++) {
            printf("Checking row %d, col %d\n", row, col);

            if (row == 2 && col == 3)
                goto found;
        }
    }

    printf("Not found\n");
    return 0;

found:
    printf("Found at row %d, col %d\n", row, col);

    return 0;
}