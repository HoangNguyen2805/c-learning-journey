5.3 Quiz:

1. What is the relationship between an array name and a pointer? Can you reassign an array name?
- An array name ( `arr` ) is also a constant pointer to it's first element.

2. Explain pointer arithmetic. What does p+1 do if p is an int * vs if p is a char *?
- `int *p` is 4 byte each so 
```c
int *p = arr;
p + 1 
```
mean move over 4 byte each -> arr[0] now is arr[1]

- But `char *cp` is 1 byte each because chart is 1 byte so
```c
char *cp = "hello";
cp + 1         // moves 1 byte forward (chars are 1 byte)
```
 
3. Are arr[i] and *(arr+i) equivalent? Explain why or why not.
- Yes they're both equivalent
```c
arr[i]      // array subscript notation
*(arr + i)  // pointer arithmetic and dereference
```

4. When you pass an array to a function, what does the function actually receive?
- When you past an array to a function, the function receive arr[0] by default, function doesn't know the size of the array so you also have to pass the size of the array seperately. 

5. What does "null-terminated" mean for strings in C?
- End of string.

6. Write code that uses pointer arithmetic to print the 3rd element of an array.
```c
int arr[5] = {10, 20, 30, 40, 50};
int *p = arr; // pointed at arr[0]

printf("%d\n", *(p + 2));
```

7. True or false: "A 2D array can be treated as a 1D array using pointer arithmetic." Explain.
- True, 2D array is displace as (x,y) where x is what row and y is what collum the element is located at, we dont have to use (x,y) and use  arr[element's order] to locate the element, 1D array element is store from left to right using from index 0 up to amount of the element in array.

8. What's the difference between arr and &arr[0]? Do they point to the same address?
- `arr` and `&arr[0]` point to the same address (both are the address of the first element).
- But they have different types:
    `arr` is type `int[5]` (array of 5 ints)
    `&arr[0]` is type `int *` (pointer to int)
- In most contexts, `arr` decays to `int *`, so they become equivalent.

9. Can you do pointer arithmetic on array names? Why or why not?
- Yes, you can do pointer arithmetic on array names: arr+1, arr+2 all work.
- But you cannot reassign the array name: arr = something_else doesn't work, because arr is a constant pointer — it always points to the start of the array. You can do arithmetic with it, but you can't change what it points to.

10. Explain why functions receiving arrays need the size passed separately.
- Arrays decay to pointers when passed to functions. Pointers don't carry size information — the function can't know where the array ends without being told.