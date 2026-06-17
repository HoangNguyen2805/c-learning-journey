#include <stdio.h>

int main() {

    int age;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Age: %d\n", age);

    if (age >= 18) {                        // TRUE , age is above 18
        printf("You can vote.\n");
    } else {                                // FALSE , age is below 18
        printf("You cannot vote yet.\n");
    }

    printf("Program finished.\n");

    return 0;
}