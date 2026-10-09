/*
Practice 4.11.1 - Grade Calculator with #define Constants

Problem:
Write a program that:
1. Define constants using #define for:
   - MAX_SCORE = 100
   - GRADE_A = 90
   - GRADE_B = 80
   - GRADE_C = 70
   - GRADE_D = 60

2. Read a score from the user
3. Use the constants to print the grade (A, B, C, D, or F)

Example output:
Enter score: 85
Grade: B

Test with a few different scores (like 95, 85, 75, 65, 55)
*/
/*
#include <stdio.h>

// Define your constants here with #define

int main() {
    int score;
    
    printf("Enter score: ");
    scanf("%d", &score);
    
    // Use if/else to check grade using your #define constants
    
    return 0;
}
*/

#include <stdio.h>

// Define your constants here with #define
#define MAX_SCORE 100
#define MIN_SCORE 0
#define GRADE_A 90
#define GRADE_B 80
#define GRADE_C 70
#define GRADE_D 60

int main() {
    int score;
    
    printf("Enter score: ");
    scanf("%d", &score);
    
    // Use if/else to check grade using your #define constants
    
    if (score < MIN_SCORE || score > MAX_SCORE){
        printf("Invalid !\n");
    } else if (score >= GRADE_A){
        printf("Grade: A\n");
    } else if (score >= GRADE_B) {
        printf("Grade: B\n");
    } else if (score >= GRADE_C) {
        printf("Grade: C\n");
    } else if (score >= GRADE_D) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F , You fail.\n");
    }
    
    return 0;
}