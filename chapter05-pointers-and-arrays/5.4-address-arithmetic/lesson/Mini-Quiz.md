5.4 Quiz:

1. When you do int *p = arr; p + 1, what does p+1 point to? How many bytes does it move?
- p is default by arr[0] so p+1 is point to arr[1], int is 4 byte so p+1 mean p + 4 byte.

2. Can you subtract two pointers? What does p2 - p1 return (assuming they point to the same array)?
- Yes, p2 - p1 should return the number of elements, not bytes.

If p1 = &arr[1] and p2 = &arr[4], then p2 - p1 = 3 (elements: arr[2], arr[3], arr[4])

3. What does malloc(sizeof(int)) do? What does it return?
- It borrow memory location worth the size of integer, malloc return a pointer to that memory, malloc returns the ADDRESS of the allocated memory, stored in a pointer. it return the address if that integer.
4. Why do you need to check if malloc returned NULL?
- when we call 
```c
int *p = malloc(sizeof(int));
```
is like we renting an apartment size of #int, it well reserve an space worth of the sizeof(int) in the heap memory.
And when we finish use it we need to return the space, which is
```c
free(p);  // release memory back to system
```
And we return the key
```c
p = NULL; // good practice: set to NULL after freeing
```
In case the function `malloc(sizeof(int));` is fail for reasone, it will return the value of `NULL`, and we should check for that.
If we dereferencing the `NULL` pointer, it VERY dangerous, It can cause a ``Segmentation fault``. That why we need to check if malloc returned NULL byt if statement
```c
if (p == NULL) {
    printf("Memory allocation failed\n");
    return 1;
}
```
before we use the memory.

5. What is free() used for? What should you do after calling free(p)?
- `malloc` help us borrow temporary dynamic memory to use, after we done using we should return the space by using `free()` function. Memory is a finite resource. Not freeing causes memory leak.
- After returning the memory we should set pointer to NULL To  Prevents accidental use of freed memory (dangling pointer).

6. Explain the difference between static local variables and regular local variables.
- `static local variables` mean when i compile it will initialized once and the value of that static variable will never bereset no matter if the compiler reset it the value will stay there no change no renew by the compiler.
- `regular local variables` mean are declare without `static` (ex: `int = 1;`), die at the end of the complier , reset to new one when recompile.

7. What does static mean when used with a global variable?
- static globals are visible only within the same file (internal linkage).

8. What are the four storage classes in C?
- C has four storage classes: auto, register, static, extern

9. Write code to allocate space for 10 integers dynamically.
```c
int grade;

int *p = malloc(10 * sizeof(grade));
```

10. What is a "memory leak"? How do you prevent it?
- If you use malloc to create dynamic memory and forgot to use free() function to return the memory then it will cause memory leak. To prevent it we checl to make sure that we use free() to return the space and set the variable to NULL/