**Q1.** Declare an array of 10 integers called `scores`. How do you access the first element? The last element?
```c
int scores [10];
scores [0] = 1; // first element access
scores [9] = 11; // last element access
```
- 10 slot , but 0 to 9 indices (index).

**Q2.** What's wrong with this code? Explain the error.
```c
int arr[5] = {1, 2, 3, 4, 5};
arr[5] = 10;
```
- So
```c
arr[0] = 1
arr[1] = 2
arr[2] = 3
arr[3] = 4
arr[4] = 5
```
There is no arr[5] at all.

**Q3.** Write a loop that prints all elements of an array of size 7.
```c
int arr [7] = {1,2,3,4,5,6,7};
for (int i = 0; i < 7; i++){
    printf("%d\n", arr [i]);
}
```

**Q4.** How many characters do you need to store the string "hello"? Why?
```
['h']['e']['l']['l']['o']['\0']
  1    2    3    4    5     6
```
6 character even those indices(index) it count from 0 not 1 but it still need 6 slot to store and it including '\0' null null terminator.

**Q5.** What does the null terminator `\0` do in a string?
- Ended a string.

**Q6.** Declare a 2D array (matrix) with 3 rows and 4 columns of integers.
```c
int matrix [3][4];
```

**Q7.** Write code to access the element in row 1, column 2 of a 2D array called `matrix`.
```c
printf("%d", matrix[1][2]);
```

**Q8.** What's an out-of-bounds access? Why is it dangerous?
- An out-of-bounds access means accessing an index outside the valid range (like arr[10] in an array of size 5). It's dangerous because C doesn't check bounds — you read/write to random memory, crashing the program or corrupting data.

**Q9.** True or false: "An array can grow in size after it's declared." Explain.
- False, Arrays have fixed size at declaration. You cannot grow them after creation.

**Q10.** Write a loop that finds the sum of all elements in an array of size 5.
```c
int sum = 0;
int arr [5] = {1,2,3,4,5};
for (int i = 0; i < 5; i++){
    sum = sum + arr [i];
}
printf("Sum = %d", sum);
```