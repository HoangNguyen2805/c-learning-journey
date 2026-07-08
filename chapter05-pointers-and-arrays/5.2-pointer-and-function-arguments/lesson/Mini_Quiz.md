**Q1.** What happens when you pass a variable to a function without a pointer? Can the function modify the original variable? Why or why not?
- The function q=will receive a copy of that virable instead of the address, without the address , function can not modify the variable because they have no idead where the variable loacted to get ther and modify it.

**Q2.** Write a function signature for a function called `addTen` that takes a pointer to an int and modifies the value at that address by adding 10 to it.
```c
void addTen (int *x){
    x = (*x) + 10;
}
```

**Q3.** When you pass an array to a function (like `printArray(arr, size)`), what does the function actually receive? Is it a copy of the array or something else?

**Q4.** If you have `int arr[5] = {1, 2, 3, 4, 5};` and `int *p = arr;`, explain what `*(p+2)` gives you and why.

**Q5.** What does pointer arithmetic mean? What happens when you do `p++` if p is a `char *` vs if p is an `int *`?

**Q6.** Write a function that takes a pointer to an int and a new value, and swaps them (exchanges the values). What would the function signature look like?

**Q7.** Strings in C are null-terminated character arrays. What does "null-terminated" mean, and why is it important?

**Q8.** True or false: "When a function modifies an array passed to it, it modifies the original array, not a copy." Explain.

**Q9.** What's the relationship between `arr[i]` and `*(arr+i)`? Are they equivalent?

**Q10.** A function needs to "return" two values: the sum and product of two numbers. It can't return both as a single value. How would you use pointers to solve this?
