#include <stdio.h>
#include <stdlib.h>

void counter();

int main() {
    printf("=== Chapter 5.4: Address Arithmetic ===\n\n");

    // Example 1: Pointer Arithmetic Scaling
    printf("Example 1: Pointer Arithmetic Scaling\n");
    int arr[5] = {10, 20, 30, 40, 50};
    int *ip = arr;
    
    printf("ip points to arr[0]: %d\n", *ip);
    printf("ip+1 points to arr[1]: %d\n", *(ip + 1));
    printf("ip+2 points to arr[2]: %d\n", *(ip + 2));
    printf("Address scaling: ip=%p, ip+1=%p (moved 4 bytes)\n", (void *)ip, (void *)(ip + 1));
    printf("\n");

    // Example 2: Pointer Subtraction
    printf("Example 2: Pointer Subtraction\n");
    int *p1 = &arr[1];
    int *p2 = &arr[4];
    int distance = p2 - p1;
    printf("p1 points to arr[1], p2 points to arr[4]\n");
    printf("p2 - p1 = %d (elements between them)\n", distance);
    printf("\n");

    // Example 3: Pointer Comparisons
    printf("Example 3: Pointer Comparisons\n");
    if (p1 < p2) {
        printf("p1 < p2: TRUE\n");
    }
    if (p1 == p2) {
        printf("p1 == p2: TRUE\n");
    } else {
        printf("p1 == p2: FALSE\n");
    }
    printf("\n");

    // Example 4: malloc - Allocate Single Int
    printf("Example 4: malloc - Single Integer\n");
    int *single = malloc(sizeof(int));
    if (single == NULL) {
        printf("Allocation failed\n");
        return 1;
    }
    *single = 42;
    printf("Allocated and stored: %d\n", *single);
    free(single);
    single = NULL;
    printf("Memory freed\n\n");

    // Example 5: malloc - Allocate Array
    printf("Example 5: malloc - Dynamic Array\n");
    int size = 5;
    int *dyn_arr = malloc(size * sizeof(int));
    if (dyn_arr == NULL) {
        printf("Allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < size; i++) {
        dyn_arr[i] = i * 10;
    }
    
    printf("Dynamic array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dyn_arr[i]);
    }
    printf("\n");
    free(dyn_arr);
    dyn_arr = NULL;
    printf("Memory freed\n\n");

    // Example 6: Pointer to Pointer
    printf("Example 6: Pointer to Pointer\n");
    int *ptr1 = malloc(sizeof(int));
    int **ptr2 = &ptr1;
    
    **ptr2 = 100;
    printf("**ptr2 = %d\n", **ptr2);
    printf("*ptr1 = %d\n", *ptr1);
    free(ptr1);
    ptr1 = NULL;
    printf("Memory freed\n\n");

    // Example 7: Static Local Variable
    printf("Example 7: Static Local Variable\n");
    counter();
    counter();
    counter();
    printf("\n");

    // Example 8: User Input Dynamic Array
    printf("Example 8: Dynamic Array from User Input\n");
    int user_size;
    printf("Enter array size: ");
    scanf("%d", &user_size);
    
    int *user_arr = malloc(user_size * sizeof(int));
    if (user_arr == NULL) {
        printf("Allocation failed\n");
        return 1;
    }
    
    printf("Enter %d elements: ", user_size);
    for (int i = 0; i < user_size; i++) {
        scanf("%d", &user_arr[i]);
    }
    
    printf("Your array: ");
    for (int i = 0; i < user_size; i++) {
        printf("%d ", user_arr[i]);
    }
    printf("\n");
    
    free(user_arr);
    user_arr = NULL;
    printf("Memory freed\n\n");

    // Example 9: NULL Check is Critical
    printf("Example 9: NULL Check\n");
    int *test = malloc(sizeof(int));
    if (test == NULL) {
        printf("Warning: malloc returned NULL\n");
    } else {
        *test = 99;
        printf("Allocated and stored: %d\n", *test);
        free(test);
        test = NULL;
    }
    printf("\n");

    // Example 10: Storage Classes Demo
    printf("Example 10: Storage Classes\n");
    printf("auto int x = 10 (function scope)\n");
    printf("extern int global (file/program scope)\n");
    printf("static int persist (persists across calls)\n");
    printf("register int fast (compiler suggestion)\n");

    return 0;
}

void counter() {
    static int count = 0;
    count++;
    printf("Counter: %d\n", count);
}