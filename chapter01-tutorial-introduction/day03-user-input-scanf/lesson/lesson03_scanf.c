#include <stdio.h>

int main() {
    int age;      // Since we want to to asign to this variable by user's input.
    float price;  // We stiull have to declare it here
    char grade;   // But we don't have asign any value.

    // Inorder to help the user Understand what to input, We have to create a promt
    // to guild the user use using printf.
    printf("Enter your age: "); // We dont use \n in this case because we want the
    // user to incert thier in put in the same row a a question so it look better.
    // As long as we don't use \n the next thing it prrint will be next to the previous
    // and stay at the same row.
    scanf("%d", &age);

    printf("Enter a price: ");
    scanf("%f", &price);            // scanf does not need \n to know when to stop

    printf("Enter your grade: ");
    scanf(" %c", &grade);

    printf("\n---result---\n");
    printf("Age: %d\n", age);
    printf("Price: %.2f\n", price);
    printf("Grade: %c\n", grade);

    return 0;
}