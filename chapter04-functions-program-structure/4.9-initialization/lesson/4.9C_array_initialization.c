#include <stdio.h>

int main() {
    int numbers[5] = {10, 20};
    char word[] = "hi";
    int i;

    for (i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    printf("word: %s\n", word);

    return 0;
}