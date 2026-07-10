/*
Basic Arrays - Foundational Example Code

Demonstrates:
- Array declaration and initialization
- Accessing and modifying elements
- Looping over arrays
- Strings (character arrays)
- 2D arrays
- Common patterns
*/

#include <stdio.h>

int main() {
    printf("=== Example 1: Basic array declaration and access ===\n");
    int arr[5] = {10, 20, 30, 40, 50};
    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("First element: %d\n", arr[0]);
    printf("Last element: %d\n", arr[4]);

    printf("\n=== Example 2: Modifying array elements ===\n");
    arr[2] = 99;  // change third element
    printf("After changing arr[2] to 99: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\n=== Example 3: Sum of array elements ===\n");
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + arr[i];
    }
    printf("Sum: %d\n", sum);

    printf("\n=== Example 4: Find maximum ===\n");
    int numbers[] = {10, 50, 20, 40, 30};
    int max = numbers[0];
    for (int i = 1; i < 5; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    printf("Array: 10 50 20 40 30\n");
    printf("Maximum: %d\n", max);

    printf("\n=== Example 5: Counting occurrences ===\n");
    int data[] = {1, 2, 2, 3, 2, 4, 2, 5};
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (data[i] == 2) {
            count++;
        }
    }
    printf("Array: 1 2 2 3 2 4 2 5\n");
    printf("Number of 2's: %d\n", count);

    printf("\n=== Example 6: Reversing an array ===\n");
    int original[] = {1, 2, 3, 4, 5};
    printf("Original: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", original[i]);
    }
    printf("\n");
    printf("Reversed: ");
    for (int i = 4; i >= 0; i--) {
        printf("%d ", original[i]);
    }
    printf("\n");

    printf("\n=== Example 7: Strings (character arrays) ===\n");
    char name[6] = "hello";  // "hello" + '\0' (null terminator)
    printf("String: %s\n", name);
    printf("Characters: ");
    for (int i = 0; name[i] != '\0'; i++) {
        printf("%c ", name[i]);
    }
    printf("\n");
    printf("String length (by counting): ");
    int len = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        len++;
    }
    printf("%d\n", len);

    printf("\n=== Example 8: Copying an array ===\n");
    int source[] = {1, 2, 3, 4, 5};
    int destination[5];
    
    // Copy elements
    for (int i = 0; i < 5; i++) {
        destination[i] = source[i];
    }
    
    printf("Source:      ");
    for (int i = 0; i < 5; i++) printf("%d ", source[i]);
    printf("\n");
    printf("Destination: ");
    for (int i = 0; i < 5; i++) printf("%d ", destination[i]);
    printf("\n");

    printf("\n=== Example 9: 2D Array (Matrix) ===\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n=== Example 10: Sum of 2D array ===\n");
    int sum2d = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            sum2d = sum2d + matrix[i][j];
        }
    }
    printf("Sum of all elements in matrix: %d\n", sum2d);

    printf("\n=== Example 11: Average of array ===\n");
    int grades[] = {85, 90, 78, 92, 88};
    int sumGrades = 0;
    for (int i = 0; i < 5; i++) {
        sumGrades = sumGrades + grades[i];
    }
    int average = sumGrades / 5;
    printf("Grades: 85 90 78 92 88\n");
    printf("Sum: %d\n", sumGrades);
    printf("Average: %d\n", average);

    printf("\n=== Example 12: Array of strings ===\n");
    char colors[4][10] = {
        "red",
        "green",
        "blue",
        "yellow"
    };
    
    printf("Colors: ");
    for (int i = 0; i < 4; i++) {
        printf("%s ", colors[i]);
    }
    printf("\n");

    return 0;
}
