#include <stdio.h>

int main() {
    int scores[5];
    int i;

    scores[0] = 90;
    scores[1] = 80;
    scores[2] = 70;
    scores[3] = 100;
    scores[4] = 85;

    for (i = 0; i < 5; i++) {
        printf("Score %d: %d\n", i, scores[i]);
    }

    return 0;
}