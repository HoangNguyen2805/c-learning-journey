**Q1.** What happens when you pass a variable to a function without a pointer? Can the function modify the original variable? Why or why not?
- The function will receive a copy of that virable instead of the address, without the address , function can not modify the variable because they have no idead where the variable loacted to get ther and modify it.

**Q2.** Write a function signature for a function called `addTen` that takes a pointer to an int and modifies the value at that address by adding 10 to it.
```c
void addTen(int *x){
    (*x) += 10;  // or *x = *x + 10;
}
```

**Q3.** When you pass an array to a function (like `printArray(arr, size)`), what does the function actually receive? Is it a copy of the array or something else?
- it recieve the arr[0] value or address not just the copy.

**Q4.** If you have `int arr[5] = {1, 2, 3, 4, 5};` and `int *p = arr;`, explain what `*(p+2)` gives you and why.
- int arr[5] = {1, 2, 3, 4, 5};
int *p = arr;
Index:    0  1  2  3  4
Value:    1  2  3  4  5
          ↑
          p

p+2 points here:
          0  1  2  3  4
          1  2  3  4  5
                ↑
               p+2

*(p+2) dereferences it → gives you 3
*(p+2) = 3 (the value at arr[2])
p = index 0 (value 1)
p+2 = index 2 (value 3) move 2 index over , so index 2 = 3.

**Q5.** What does pointer arithmetic mean? What happens when you do `p++` if p is a `char *` vs if p is an `int *`?
- Q5 — Correct Answer:
Pointer arithmetic moves a pointer's address by the size of its type:

char *p; p++ → moves the address 1 byte forward (because sizeof(char) = 1)
int *p; p++ → moves the address 4 bytes forward (because sizeof(int) = 4)

The compiler automatically calculates how many bytes to jump based on the pointer's type.
Example: If p (an int *) points to address 1000, then p++ makes it point to address 1004 (1000 + 4 bytes).

**Q6.** Write a function that takes a pointer to an int and a new value, and swaps them (exchanges the values). What would the function signature look like?
```c
void swap(int *x, int *y){
    int temp = *y; // save y value
    *y = *x;       // y now hold value of x
    *x = temp;     // x now hold value of save y
}
```

**Q7.** Strings in C are null-terminated character arrays. What does "null-terminated" mean, and why is it important?
- `\0` mean end of the string and it show you where is the end of the array.

**Q8.** True or false: "When a function modifies an array passed to it, it modifies the original array, not a copy." Explain.
- True, pointer point at the address, so if a = 1, *a = 9, it will change the value of a from 1 to 9. It bassically set a = to 9.

**Q9.** What's the relationship between `arr[i]` and `*(arr+i)`? Are they equivalent?
- `arr[i]` is value at i index in the array.
- `*(arr+i)` point at that value at i index in the array.
- so yes they are the same.

**Q10.** A function needs to "return" two values: the sum and product of two numbers. It can't return both as a single value. How would you use pointers to solve this?
```c
void sumAndProduct(int a, int b, int *sum, int *product) {
    *sum = a + b;
    *product = a * b;
}
```