# Basic Arrays (Foundational)

## What is an array?

An **array** is a collection of variables of the **same type**, stored next to each other in memory.

Think of it like a row of mailboxes:
- Each mailbox holds **one value**
- All mailboxes are the **same size**
- You find a mailbox by its **position number** (index)
- Mailboxes are numbered starting from **0**

```
Array: [10] [20] [30] [40] [50]
Index:  0    1    2    3    4
```

---

## Declaring an array

**Syntax:**
```c
type arrayName[size];
```

**Examples:**
```c
int numbers[5];        // array of 5 integers
char letters[10];      // array of 10 characters
double scores[3];      // array of 3 doubles
```

`[5]` means "this array holds 5 elements" — no more, no less.

---

## Initializing an array

### Option 1: Declare, then assign later

```c
int arr[3];
arr[0] = 10;
arr[1] = 20;
arr[2] = 30;
```

### Option 2: Declare and initialize at the same time

```c
int arr[3] = {10, 20, 30};
```

### Option 3: Declare with automatic size

```c
int arr[] = {10, 20, 30};  // compiler figures out size (3)
```

**Important:** You **must** specify the size when declaring, or provide initial values so the compiler can figure it out.

```c
int arr[5];  // OK, size is 5
int arr[] = {1, 2, 3};  // OK, size is 3 (from values)
int arr[];   // ERROR: size is unknown
```

---

## Accessing array elements

Use **square brackets** with an **index** (position):

```c
int arr[5] = {10, 20, 30, 40, 50};

printf("%d\n", arr[0]);  // 10 (first element)
printf("%d\n", arr[2]);  // 30 (third element)
printf("%d\n", arr[4]);  // 50 (fifth element)
```

**Index starts at 0:**
- `arr[0]` = first element
- `arr[1]` = second element
- `arr[n-1]` = last element (for an array of size n)

### Modifying array elements

```c
int arr[5] = {10, 20, 30, 40, 50};
arr[1] = 99;  // change second element
printf("%d\n", arr[1]);  // 99
```

---

## Common mistake: array bounds

If you declare an array of size 5, valid indices are **0 through 4**:

```c
int arr[5] = {10, 20, 30, 40, 50};

arr[0];  // OK
arr[4];  // OK
arr[5];  // ERROR: out of bounds!
arr[10]; // ERROR: out of bounds!
```

**C does NOT check bounds at runtime.** Accessing `arr[5]` won't give you an error message — it will just access **whatever is in memory after the array**, which can crash your program or corrupt data.

**Always be careful with indices.**

---

## Looping over arrays

The most common pattern is using a **for loop**:

```c
int arr[5] = {10, 20, 30, 40, 50};

// Print all elements
for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);  // 10 20 30 40 50
}
```

**Why `i < 5` and not `i <= 5`?**
- Array has 5 elements with indices 0, 1, 2, 3, 4
- `i < 5` loops through 0, 1, 2, 3, 4 (all valid indices)
- `i <= 5` would try to access arr[5], which is out of bounds

### Summing array elements

```c
int arr[5] = {10, 20, 30, 40, 50};
int sum = 0;

for (int i = 0; i < 5; i++) {
    sum = sum + arr[i];
}

printf("Sum: %d\n", sum);  // 150
```

### Finding the maximum

```c
int arr[5] = {10, 50, 20, 40, 30};
int max = arr[0];

for (int i = 1; i < 5; i++) {
    if (arr[i] > max) {
        max = arr[i];
    }
}

printf("Max: %d\n", max);  // 50
```

---

## Arrays of characters (strings)

A **string** in C is an array of characters:

```c
char name[6] = "hello";
```

This creates:
```
['h']['e']['l']['l']['o']['\0']
```

Notice the `\0` at the end — this is the **null terminator**, which marks the end of the string.

**Important:** A string `"hello"` has 5 characters, but you need an array of size 6 to store it (5 chars + 1 null terminator).

### Accessing characters

```c
char name[6] = "hello";

printf("%c\n", name[0]);  // 'h'
printf("%c\n", name[2]);  // 'l'
printf("%c\n", name[4]);  // 'o'
```

### Looping over a string

```c
char name[6] = "hello";

// Option 1: loop by index
for (int i = 0; i < 5; i++) {
    printf("%c", name[i]);  // h e l l o
}

// Option 2: loop until null terminator
for (int i = 0; name[i] != '\0'; i++) {
    printf("%c", name[i]);  // h e l l o
}
```

**Option 2 is safer** because you don't need to manually track the string's length.

---

## 2D arrays (multi-dimensional)

An array can have **multiple dimensions**:

```c
int matrix[3][4];  // 3 rows, 4 columns
```

This creates a 3x4 grid of integers:

```
matrix[0][0]  matrix[0][1]  matrix[0][2]  matrix[0][3]
matrix[1][0]  matrix[1][1]  matrix[1][2]  matrix[1][3]
matrix[2][0]  matrix[2][1]  matrix[2][2]  matrix[2][3]
```

### Accessing 2D array elements

```c
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

printf("%d\n", matrix[0][0]);  // 1 (row 0, column 0)
printf("%d\n", matrix[1][2]);  // 7 (row 1, column 2)
printf("%d\n", matrix[2][3]);  // 12 (row 2, column 3)
```

### Looping over a 2D array

```c
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// Print the entire matrix
for (int i = 0; i < 3; i++) {           // for each row
    for (int j = 0; j < 4; j++) {       // for each column
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}
```

---

## Key points to remember

```text
An array is a collection of same-type variables in memory.

Declaration:     int arr[5];
Initialization:  int arr[5] = {1, 2, 3, 4, 5};

Index starts at 0, ends at size-1.

Loop over arrays with: for (int i = 0; i < size; i++)

Strings are char arrays, null-terminated with '\0'

Out-of-bounds access is dangerous — C doesn't check.

2D arrays are arrays of arrays: int matrix[rows][cols];
```

---

## Common mistakes

### Mistake 1: Array index out of bounds

```c
int arr[5] = {1, 2, 3, 4, 5};
arr[5] = 10;  // WRONG: index 5 is out of bounds
```

### Mistake 2: Forgetting the null terminator for strings

```c
char str[5] = "hello";  // WRONG: needs 6 chars (5 + '\0')
char str[6] = "hello";  // RIGHT
```

### Mistake 3: Loop goes one too far

```c
int arr[5] = {1, 2, 3, 4, 5};

for (int i = 0; i <= 5; i++) {  // WRONG: tries arr[5]
    printf("%d ", arr[i]);
}

for (int i = 0; i < 5; i++) {   // RIGHT
    printf("%d ", arr[i]);
}
```

### Mistake 4: Trying to resize an array

```c
int arr[5];
arr[10] = 20;  // WRONG: you can't expand an array
```

Arrays have a **fixed size** set at declaration time.

---

## Summary

**Arrays are:**
- Collections of same-type variables
- Fixed size (set at declaration)
- Indexed starting at 0
- Stored next to each other in memory
- Essential for working with multiple values of the same type

**Next:** Once you understand basic arrays, Chapter 5.3 will show you the deep connection between arrays and pointers.
