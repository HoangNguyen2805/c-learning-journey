#include <stdio.h>

int main() {
                                // While loop consist of 3 part:
    int i = 1;                  // 1. Start value. The loop start at int i = 1;

    printf("--- While Loop ---\n");

    while (i <= 5) {            // 2. Condition. The loop will not stop as long as i <= 5
        printf("%d\n", i);      //           -> each time looping, it print i value.
        i++;                    // 3. Update. i value will update each loop by increment of 1
    }

    printf("Program finished.\n");

    return 0;
}