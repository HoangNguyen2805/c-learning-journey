/*
Practice 4 — no solution

Task: ask user for:

age
price
grade

Expected output:

Enter age: 25
Enter price: 9.99
Enter grade: A

--- Profile ---
Age: 25
Price: $9.99
Grade: A

Hints only:

age = int
price = float
grade = char

scanf for int = %d
scanf for float = %f
scanf for char = use space before %c
print price with 2 decimals

cd ~/c-learning-journey/01-c-basics/day03-user-input-scanf/practice
gcc practice04_read_profile.c -o practice04
./practice04
*/

#include <stdio.h>

int main() {

    int age;
    float price;
    char grade;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter price: ");
    scanf("%f", &price);

    printf("Enter grade: ");
    scanf(" %c", &grade);

    printf("--- Profile ---\n");
    printf("Age: %d\n", age);
    printf("Price: $%.2f\n", price);
    printf("Grade: %c\n", grade);

    return 0;
}