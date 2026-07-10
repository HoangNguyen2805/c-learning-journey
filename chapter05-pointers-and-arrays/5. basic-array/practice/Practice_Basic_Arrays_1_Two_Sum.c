/*
Practice: Basic Arrays 1 — Two Sum
Given an array and a target sum, find two different elements that add up to the target. Print their indices.
Accept user input for the array and target sum.
Example: arr = [2, 7, 11, 15], target = 9 → indices 0 and 1 (because 2 + 7 = 9)
Hint: Use nested loops to check every pair.
*/
#include <stdio.h>

int main(){

    int amountNum = 0;
    int sum;
    printf("Enter your number list and enter your sum up number you want to add up.\n"
           "How many number do you have on your list ?\n"
           "Enter here: ");
    scanf("%d", &amountNum);
    printf("And the Sum of each pair must equal to: ");
    scanf("%d", &sum);

    // Filling user input into the array
    int arr[amountNum];
    for (int i = 0; i < amountNum; i++){  
        printf("Enter the %d number: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int found = 0;  // declare this before the search loops, incase If not found (Sum != arr[i] + arr[j] )
    // Once it fill , then start looking for number that sum up to target.
    for (int i = 0; i < amountNum; i++){           // i is equal to index 0
        for (int j = i + 1; j < amountNum; j++){   // so j can Not be = index 0, j is alway +1 ahead of i
            if ( sum == arr[i] + arr[j] ){
                printf("%d + %d = %d\n", arr[i], arr[j], sum);
                printf("The pair is (%d,%d).\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    // If not found (Sum != arr[i] + arr[j] )
    if (found == 0){
        printf("No pair found\n");  // only prints once, if nothing was found
    }

    return 0;
}

/*
i and j both move. Here's the full picture:
```
i=0: j goes 1,2,3,4  → checks (0,1)(0,2)(0,3)(0,4)
i=1: j goes 2,3,4    → checks (1,2)(1,3)(1,4)
i=2: j goes 3,4      → checks (2,3)(2,4)
i=3: j goes 4        → checks (3,4)
```
See? Every pair gets checked:

- When i=1, j covers 2,3,4 (so 1 pairs with 2, 3, 4)
- When i=2, j covers 3,4 (so 2 pairs with 3, 4)

The pair (1,4) IS checked — when i=1, j=4.
The pair (2,4) IS checked — when i=2, j=4.
Every combination is covered because for each i, j scans everything after it.
The reason j starts at i+1 (not 0) is to avoid checking the same pair twice — (1,4) and (4,1) are the same pair, so we only check it once.
*/