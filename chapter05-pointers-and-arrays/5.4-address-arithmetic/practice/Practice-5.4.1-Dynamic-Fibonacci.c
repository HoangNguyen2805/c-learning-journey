/*
Practice 5.4.1 — Dynamic Fibonacci
Write a program that takes n from user input, dynamically allocates an array, fills it with the first n Fibonacci numbers using pointer arithmetic, prints it, and frees memory.
*/
/*
Practice 5.4.1 asks you to:

1. Ask user for n (how many Fibonacci numbers)
2. malloc an array of size n
3. Fill it with first n Fibonacci numbers
4. Print the array
5. free the memory
*/
#include <stdio.h>
#include <stdlib.h>

void calFib(int *arr, int n);

int main(){

    // 1. User input
    int n;
    printf("--- Fibonacci numbers calculator!! ---\n"
           "How many Fibonacci numbers you want to calculate ? - ");
    scanf("%d", &n);

    // 2. Create Dynamic memory for arr
    int *arr = malloc(n * sizeof(int));
    // make sure malloc is not fail
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // 3. call in the function to calculate
    calFib(arr, n);

    // 4. print out the FIB
    printf("Result = { ");
    for(int i = 0; i < n; i++){
        printf("%d, ", arr[i]);
    }
    printf("}");

    // 5. retrun the dynamic memory by free it.
    free(arr);
    arr = NULL;

    return 0;
}

void calFib(int *arr, int n){
    arr[0] = 0;   // first Fibonacci
    arr[1] = 1;   // second Fibonacci

    for(int i = 2; i < n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
}