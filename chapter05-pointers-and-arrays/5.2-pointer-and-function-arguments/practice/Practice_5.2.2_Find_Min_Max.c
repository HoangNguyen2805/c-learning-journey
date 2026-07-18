/* Find Min and Max
Practice 5.2.2: Write a function that finds min and max in an array using pointers.
Write a function that takes an array and size, finds the minimum and maximum values, and returns them via pointers.
Example: findMinMax(arr, size, &min, &max);
*/
// make user input array size and array value.
#include <stdio.h>

void findMinMax(int *arr, int size, int *min, int *max);

int main(){

    int size;
    printf("Finds min and max of your array.\n"
           "Amount of elements of the array: ");
    scanf("%d", &size);
    printf("Enter each element of the array.\n");
    int arr[size];
    for(int i = 0; i < size; i++){
        printf("Element number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int min, max;
    findMinMax(arr, size, &min, &max);
    printf("Max is %d\n", max);
    printf("Min is %d\n", min);

    return 0;
}

void findMinMax(int *arr, int size, int *min, int *max){
    *max = arr[0];
    *min = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > *max){
            *max = arr[i];
        }
        if(arr[i] < *min){
            *min = arr[i];
        }
    }
}