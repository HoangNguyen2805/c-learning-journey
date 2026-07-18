/* Array Modifier
Practice 5.2.3: Write a function that doubles all elements in an array.
Write a function that takes an array and size, then doubles every element in the array.
Test with: [1, 2, 3, 4, 5] → [2, 4, 6, 8, 10]
*/

#include <stdio.h>
void doubleArr (int *arr, int size);
int main(){

    int size;
    printf("Double all the element in the array.\n"
           "Amount of elements of the array: ");
    scanf("%d", &size);
    printf("Enter each element of the array.\n");
    int arr[size];
    for(int i = 0; i < size; i++){
        printf("Element number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("Your current array is [ ");
    for(int i = 0; i < size; i++){
        // printf("%d", arr[i]); // This give syntax error Your current array is [ 2, 3, 4, 5, ]
        // Your current array is [ 2, 3, 4, 5 ]
            if (i < size - 1) {
            printf("%d, ", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
    printf("]\n");

    doubleArr (arr, size);

    printf("Your array after double is [ ");
    for(int i = 0; i < size; i++){
        // printf("%d, ", arr[i]); // This give syntax error Your array after double is [ 4, 6, 8, 10, ]
        // Your array after double is [ 4, 6, 8, 10 ]
        if (i < size - 1) {
            printf("%d, ", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
    printf("]\n");


    return 0;
}

void doubleArr (int *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = arr[i] * 2; // OR arr[i] *= 2;
    }
}