#include <stdio.h>

int main() {
    int i;

    printf("For loop:\n");

    for (i = 1; i <= 5; i++) { // ( start at int i = 1 ; run as long as i less than or equal to 5 , if it more than 5 stop ; update each loop by increment of 1)
        printf("%d\n", i);
    }

    printf("Program finished.\n");

    return 0;
}