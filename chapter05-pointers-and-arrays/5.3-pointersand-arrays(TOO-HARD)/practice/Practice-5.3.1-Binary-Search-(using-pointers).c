/*
Practice 5.3.1 — Binary Search (using pointers)
Implement binary search using pointer arithmetic instead of array indexing. More efficient than the linear search you did before.
*/
// use user input to get random element and then use sort to put element in the small to big order to do bianrray search then print out the address of that element array inddex.
/*
How binary search work ?
Here is an array arr = { 1, 3 , 5 , 7 , 8 , 9, 10 , 11 , 15 , 18 , 20 };
Search for 8
1. Set 1 as start point and 20 as end point, from there we find the mid point
    Mid point of (1,20) = 9
2. Compare mid point with our search element
    if ( mid_point > search){ // if mid point bigger than search we can eliminate all element from mid point to end point and set current mid point = new end point
        set current mid point = new end point
    } else { // else midpoint is smaller then eliminate all element from start point to mid point and set current mid point = new start point
        set current mid point = new start point
    }
3. Find new mid point again with new array arr = { 1, 3 , 5 , 7 , 8 , 9 }, and start eliminate until you reach the element that you searching for.
Binary search can be either:
Recursive — function calls itself with new low/high
Iterative — while loop that adjusts low/high
We chose Iterative
*/
/*
By complexity:
Best: O(n log n) — merge sort, quick sort, heap sort
Acceptable: O(n²) — bubble sort, selection sort (slower, but fine for small arrays)
*/
/*
Quick sort O(n log n) is best.
Bubble sort O(n²) is simpler to code but slower for large arrays.
We'll use `quick sort` to sort use input. How do `quick sort` work ?
notice that quick sort is recursion, meanfunction call it self.
1. We pick random index as a `pivot`, it could be first , last or middle element. Then we compare that pivot with the rest of the elemnt.
if (element > pivot){
    go right
} else {
    go left
}
2. Then we'll pick a number NEXT RIGHT and NEXT LEFT to Current pivot and do it again
if (element > pivot){
    go right
} else {
    go left
}
3. Pick NEXT RIGHT and NEXT LEFT to New pivot and do it again until no more new pivot. Element that have been use as pivot before can NOT be reuse as pivot again.
*/

#include <stdio.h>

void quickSort(int *arr, int low, int high);
int binarySearch (int *arr, int low, int high, int search);

int main(){

    // User input
    printf("Binary Search (using pointers).\n");
    int size;
    printf("How many element is in your array ? - ");
    scanf("%d", &size);

    int arr[size];
    for( int i = 0; i < size; i++){
        printf("Enter your %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Before Reorded array = { ");
    for ( int i = 0; i < size; i++ ){
        if (i < size - 1) {
            printf("%d, ", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
    printf("}\n");
    
    // Declare start point and end point for both sorting and binary search
    int low = 0;           // 0 and size - 1 is represent indices not arr's value
    int high = size - 1;

    // Sorting using quick sort (recursion)
    quickSort(arr, low, high);

    printf("After Reorded array = { ");
    for ( int i = 0; i < size; i++ ){
        if (i < size - 1) {
            printf("%d, ", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
    printf("}\n");

    // Create a search target from use input
    int search;
    printf("What number of address that you looking for ? - ");
    scanf("%d", &search);
    
    // Binary search
    printf("Your number %d is located at %d index.\n", search, binarySearch(arr, low, high, search));

    return 0;
}

void quickSort(int *arr, int low, int high){
    if (low >= high){ // base case should check first advoid infinite recursion. Exit condition
            return;
    }
    int left = low;    // new variable for left pointer
    int right = high;  // new variable for right pointer
    int pivot = arr[high];
    
    while(left < right){
        while(arr[left] < pivot){   // move left right
            left++;
        }
        while(arr[right] > pivot){  // move right left
            right--;
        }
        if (left < right) {         // check before swap
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    quickSort(arr, low, right - 1);
    quickSort(arr, right + 1, high);
}
/* sorting
void quickSort(int *arr, int low, int high) {
    if (low >= high) return;
    
    int left = low;
    int right = high;
    int pivot = arr[high];
    
    while (left < right) {
        while (arr[left] < pivot) left++;      // move left right
        while (arr[right] > pivot) right--;    // move right left
        if (left < right) {                    // check before swap
            swap arr[left] and arr[right]
        }
    }
    
    // swap pivot into correct position
    
    // recursive calls on left and right parts
}
*/
int binarySearch (int *arr, int low, int high, int search) {
    while(low <= high){
        int mid =  (low + high) / 2;
        if (arr[mid] < search){
            low = mid + 1;
        } else if (arr[mid] > search) {
            high = mid - 1;
        } else if (arr[mid] == search) {
            return mid;
        } 
    }
    return -1;
}
/* Binary search
Write a binary search function that:

1. Takes sorted array, size, and target
2.Uses low and high pointers
3. Finds mid = (low + high) / 2
4. Compares arr[mid] with target
5. If equal, return the index
6. If arr[mid] < target, search right half
7. If arr[mid] > target, search left half
8. Return -1 if not found

Call it in main, ask user for target, print result.
*/