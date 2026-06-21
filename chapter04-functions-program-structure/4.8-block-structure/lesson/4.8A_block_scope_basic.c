#include <stdio.h>

int main() {
    int x = 10;

    printf("x in main: %d\n", x);

    if (x > 0) {
        int y = 20;

        printf("y inside if block: %d\n", y);
    }

    /*
       y cannot be used here.
       It only exists inside the if block.
    */

    return 0;
}