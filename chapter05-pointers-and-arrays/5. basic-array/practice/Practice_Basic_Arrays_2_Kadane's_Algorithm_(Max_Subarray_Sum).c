/*
Practice: Basic Arrays 2 — Kadane's Algorithm (Max Subarray Sum)
Find the contiguous subarray with the largest sum. Return that sum.
Example: arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4] → answer is 6 (from subarray [4, -1, 2, 1])
Hint: Track the maximum sum ending at each position as you loop.
*/
/*
Find a group of CONSECUTIVE numbers (side by side, no gaps) whose sum is the largest.
Example: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Some contiguous groups and their sums:

[4] → sum = 4
[4, -1] → sum = 3
[4, -1, 2] → sum = 5
[4, -1, 2, 1] → sum = 6 ← biggest!
[4, -1, 2, 1, -5] → sum = 1

So the answer is 6.
You must find which contiguous chunk gives the maximum sum.
*/
#include <stdio.h>

int main() {

    int size;
    printf("You can put something like arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]\n");
    printf("How many element is in your array ?\n");
    scanf("%d", &size);
    int arr[size];

    for(int i = 0; i < size; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int currentSum = arr[0];               // loop will start at index 1 not 0
    int maxSum = arr[0];                   // so set both = arr index 0
    
    for(int i = 1; i < size; i++){              // Kadane's Algorithm 
        if (currentSum < 0){                    // If currentSum is negative
            currentSum = arr[i];                // Reset case bby set currentSum = arr[1]
        } else {                                // Else arr > 0 , positive
            currentSum = currentSum + arr[i];   // Extend the case by adding currentSum to current array value
        }

        if (currentSum > maxSum) {              // At any point currentSum get bigger than max sum
            maxSum = currentSum;                // Then set the biggest sum to max sum
        }
    }

    printf("Max sum is = %d\n", maxSum);
    
    return 0;
}