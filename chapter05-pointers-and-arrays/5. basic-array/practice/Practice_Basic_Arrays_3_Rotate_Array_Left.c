/*
Practice: Basic Arrays 3 — Rotate Array Left
Rotate an array left by n positions (in-place).
Example: arr = [1, 2, 3, 4, 5], n = 2 → [3, 4, 5, 1, 2]
Hint: Elements that "fall off" the left wrap to the right.
*/
/* DSA
Brute force — rotate one element at a time, n times
Using temp array — copy rotated elements to temp, then back
Reversal algorithm — reverse subarrays to achieve rotation (optimal)
*/
#include <stdio.h>
// this is brute force
int main(){

    printf("Shift the element to the LEFT as much as you want.\n");
    int size;
    printf("How many element would you like to enter ? - ");
    scanf("%d", &size);
    int arr[size];

    for(int i = 0; i < size; i++){
        printf("Enter element number %d: ", i);
        scanf("%d", &arr[i]);
    }

    int n;
    printf("And how many time you want to rotate ? - ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int temp = arr[0];
        for(int j = 0; j < size - 1; j++){
            arr[j] = arr [j + 1];
        }
        arr [size - 1] = temp;
    }

    printf("Your array shift %d to the left is ", n);
    for (int i = 0; i < size; i++){
        printf("%d , ", arr[i]);
    }
    printf("\nDone!\n");


    return 0;
}