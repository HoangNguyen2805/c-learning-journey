#include <stdio.h>

int value = 100;

void showExternalValue(void);
void showLocalValue(void);
void showParameterValue(int value);

int main() {
    int value = 10;

    printf("In main, local value = %d\n", value);

    showExternalValue();
    showLocalValue();
    showParameterValue(50);

    {
        int blockValue = 25;
        printf("Inside block, blockValue = %d\n", blockValue);
    }

    return 0;
}

void showExternalValue(void) {
    printf("External value = %d\n", value);
}

void showLocalValue(void) {
    int value = 5;

    printf("Inside showLocalValue, local value = %d\n", value);
}

void showParameterValue(int value) {
    printf("Inside showParameterValue, parameter value = %d\n", value);
}