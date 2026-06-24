#include <stdio.h>

int main() {
    int choice = 2;
    char grade = 'B';

    printf("Menu example:\n");

    switch (choice) {
        case 1:
            printf("Start game\n");
            break;

        case 2:
            printf("Open settings\n");
            break;

        case 3:
            printf("Quit\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    printf("\nGrade example:\n");

    switch (grade) {
        case 'A':
            printf("Excellent\n");
            break;

        case 'B':
            printf("Good\n");
            break;

        case 'C':
            printf("Average\n");
            break;

        case 'D':
        case 'F':
            printf("Needs improvement\n");
            break;

        default:
            printf("Unknown grade\n");
    }

    return 0;
}