#include <stdio.h>

char getLetterGrade(int score);
char getYesNo(int value);

int main() {
    int score = 85;
    int isPassing = 1;

    char grade;
    char answer;

    grade = getLetterGrade(score);
    answer = getYesNo(isPassing);

    printf("Score: %d\n", score);
    printf("Letter grade: %c\n", grade);

    printf("Passing? %c\n", answer);

    return 0;
}

char getLetterGrade(int score) {
    if (score >= 90)
        return 'A';
    else if (score >= 80)
        return 'B';
    else if (score >= 70)
        return 'C';
    else
        return 'F';
}

char getYesNo(int value) {
    if (value)
        return 'Y';
    else
        return 'N';
}