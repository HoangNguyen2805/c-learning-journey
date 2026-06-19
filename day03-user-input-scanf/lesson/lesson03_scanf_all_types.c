#include <stdio.h>
#include <stdbool.h>

int main() {
    int age;
    float price;
    double gpa;
    char grade;
    char name[50];

    short smallNumber;
    long population;
    long long bigNumber;
    unsigned int count;

    int studentInput;
    bool isStudent;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter price: ");
    scanf("%f", &price);

    printf("Enter GPA: ");
    scanf("%lf", &gpa);

    printf("Enter grade: ");
    scanf(" %c", &grade);

    printf("Enter your first name: ");
    scanf("%s", name);

    printf("Enter a short number: ");
    scanf("%hd", &smallNumber);

    printf("Enter a long number: ");
    scanf("%ld", &population);

    printf("Enter a long long number: ");
    scanf("%lld", &bigNumber);

    printf("Enter unsigned count: ");
    scanf("%u", &count);

    printf("Are you a student? Type 1 for yes, 0 for no: ");
    scanf("%d", &studentInput);
    isStudent = studentInput;

    printf("\n--- Result ---\n");
    printf("Age: %d\n", age);
    printf("Price: %.2f\n", price);
    printf("GPA: %.2f\n", gpa);
    printf("Grade: %c\n", grade);
    printf("Name: %s\n", name);
    printf("Short number: %hd\n", smallNumber);
    printf("Long number: %ld\n", population);
    printf("Long long number: %lld\n", bigNumber);
    printf("Unsigned count: %u\n", count);
    printf("Student: %d\n", isStudent);

    return 0;
}