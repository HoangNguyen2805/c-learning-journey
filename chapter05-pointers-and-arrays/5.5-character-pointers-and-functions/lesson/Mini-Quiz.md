5.5 Quiz:

1. What's the difference between char arr[] = "hello" and char *ptr = "hello"?
- `char arr[] = "hello"` - can modify individual characters.
- `char *ptr = "hello"` - can't modify, read-only memory.

2. Can you modify individual characters in a string pointer? Why or why not?
- No, because pointer point at the value of the char not element of the array.

3. Write the logic of strlen() using pointer arithmetic — how does it work?
```c strlen() counts characters until it hits the null terminator \0.
int strlen(char *s){
    int len = 0; // set count unit = 0
    while (*s != '\0'){ // while pointer point at value, and the value is not reach NULL terminal.
        len++; // each while loop add 1 to count while going through char *s one by one
        s++; // while each loop move one element to the RIGHT by one using pointer arithmetic
    } // end loop when while reach NULL terminal
    return len; // return value of len when while loop reach NULL terminal.
}
```

4. Explain the loop while (*s++ = *t++). What does it do step-by-step?
- This is for `strcpy()` function, use to copy string. copy value from t and store in s.
while (*s++ = *t++) copies from t TO s, not from s to t.
- *t++ — get character from source (t)
- *s++ — put into destination (s)

5. What does strcmp() return? (0, positive, or negative — when?)
- `strcmp()` is a function use to compare CHARACTERS.
```c
strcmp("apple", "apple");   // 0 — all chars match
strcmp("apple", "banana");  // negative — 'a' < 'b'
strcmp("zebra", "apple");   // positive — 'z' > 'a'
```
ASCII values of characters.
Each character has a number:

'a' = 97
'b' = 98
'A' = 65

Real-world uses:

1. Sorting — alphabetize a list of names:
```c
strcmp("Alice", "Bob");    // negative → Alice comes first
strcmp("Zoe", "Bob");      // positive → Zoe comes after
// Use this to sort names A→Z
```
2. Searching — find if a name exists in a list:
```c
if (strcmp(user_input, stored_name) == 0) {
    printf("Name found!\n");
}
```
3. Login validation — check if password matches:
```c
if (strcmp(entered_password, correct_password) == 0) {
    printf("Access granted\n");
}
```
4. Dictionary/Phone book — organize contacts alphabetically

Without strcmp, you can't:

Sort contacts A→Z
Search efficiently
Validate user input
Organize data

6. If you want to read a string with spaces using scanf, what format specifier do you use instead of %s?
- `[^\n]`

7. What does *(msg+2) do with a string? How is it different from msg[2]?
- `*(msg+2)` is Pointer Arithmetic, if `*(msg)` is point at `h` of the string `"hello"` then `*(msg+2)` pointer at the h + 2 element of the string `"hello"`, which is `l`.
- `msg[2]` is represent the location of the element of the array, array `"hello"` at index 2 is 'l'.

8. Write code that finds a character in a string using a while loop and pointers.
```c
char *strchr(char *s, char c) {
    while (*s != c) // loop WHILE character is NOT the one we're looking for
        if (*s++ == '\0') // if we hit null terminator, character not found
            return NULL;  // not found , if not found the character we looking for
    return s;  // found , loop exited because *s == c, so we found it, found there is an character we expect *s char to have
}
```
```c return s mean found there is an character we expect *s char to have
char *text = "hello";
char *found = strchr(text, 'l');
```
9. In *s++ = *t++, which happens first — dereference or increment?
- dereference

10. What is a "dangling pointer" when working with strings? How do you avoid it?
Dangling pointer = a pointer that points to freed or invalid memory.

With strings, it happens when:

```c
char *str = malloc(20);
strcpy(str, "hello");
free(str);              // free memory
printf("%s\n", str);    // DANGLING POINTER — using freed memory!
```
The pointer str still exists, but the memory it points to is no longer valid.

How to avoid:

1. Set to NULL after freeing:
```c
free(str);
str = NULL;  // now it's safe
```
2. Check before using:
```c
if (str != NULL) {
    printf("%s\n", str);  // only use if valid
}
```
3. Don't return pointers to local variables:
```c
// BAD
char *bad_function() {
    char local[] = "temp";
    return local;  // dangling — local dies when function returns
}

// GOOD
char *good_function() {
    char *str = malloc(20);
    strcpy(str, "temp");
    return str;  // caller must free this
}
```

Key: Always set freed pointers to NULL, and check they're not NULL before using.