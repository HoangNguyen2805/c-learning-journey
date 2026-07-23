#include <stdio.h>

int strlen_custom(char *s);
void strcpy_custom(char *s, char *t);
int strcmp_custom(char *s, char *t);
char *strchr_custom(char *s, char c);

int main() {
    printf("=== Chapter 5.5: Character Pointers and Functions ===\n\n");

    // Example 1: String Array vs Pointer
    printf("Example 1: String Array vs Pointer\n");
    char amessage[] = "now is the time";  // array, mutable
    char *pmessage = "now is the time";   // pointer, read-only
    
    printf("amessage: %s\n", amessage);
    printf("pmessage: %s\n", pmessage);
    
    amessage[0] = 'N';  // OK — change array
    printf("After changing amessage[0]: %s\n", amessage);
    // pmessage[0] = 'N';  // ERROR — read-only, don't do this
    printf("\n");

    // Example 2: String Length via Pointer
    printf("Example 2: Custom strlen\n");
    char *str = "hello";
    printf("String: %s\n", str);
    printf("Length: %d\n", strlen_custom(str));
    printf("\n");

    // Example 3: String Copy via Pointer
    printf("Example 3: Custom strcpy\n");
    char source[] = "world";
    char dest[20];
    strcpy_custom(dest, source);
    printf("Source: %s\n", source);
    printf("Destination: %s\n", dest);
    printf("\n");

    // Example 4: String Compare via Pointer
    printf("Example 4: Custom strcmp\n");
    char *s1 = "apple";
    char *s2 = "apple";
    char *s3 = "banana";
    
    printf("strcmp('%s', '%s'): %d (0=equal)\n", s1, s2, strcmp_custom(s1, s2));
    printf("strcmp('%s', '%s'): %d (negative)\n", s1, s3, strcmp_custom(s1, s3));
    printf("\n");

    // Example 5: Pointer Arithmetic — Advance Through String
    printf("Example 5: Pointer Arithmetic\n");
    char *msg = "ABCDE";
    printf("String: %s\n", msg);
    printf("msg[0]: %c\n", *msg);
    printf("msg[1]: %c via *(msg+1)\n", *(msg + 1));
    printf("msg[2]: %c via *(msg+2)\n", *(msg + 2));
    printf("\n");

    // Example 6: Character-by-Character Copy
    printf("Example 6: Character-by-Character Copy Loop\n");
    char src[] = "copy";
    char dst[20];
    char *s = src;
    char *d = dst;
    
    while ((*d++ = *s++) != '\0')
        ;  // copy until null
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dst);
    printf("\n");

    // Example 7: Finding a Character
    printf("Example 7: Custom strchr (find character)\n");
    char *text = "hello";
    char *found = strchr_custom(text, 'l');
    if (found != NULL) {
        printf("Found 'l' in '%s' at position: %ld\n", text, found - text);
    } else {
        printf("'l' not found\n");
    }
    printf("\n");

    // Example 8: String Comparison Loop
    printf("Example 8: Manual String Comparison\n");
    char *str1 = "test";
    char *str2 = "test";
    char *str3 = "best";
    
    printf("Comparing '%s' and '%s': ", str1, str2);
    if (strcmp_custom(str1, str2) == 0) {
        printf("EQUAL\n");
    }
    
    printf("Comparing '%s' and '%s': ", str1, str3);
    if (strcmp_custom(str1, str3) != 0) {
        printf("NOT EQUAL\n");
    }
    printf("\n");

    // Example 9: String with Spaces (User Input Simulation)
    printf("Example 9: Multi-word String\n");
    char multiword[] = "hello world";
    printf("String with space: %s\n", multiword);
    printf("Length: %d\n", strlen_custom(multiword));
    printf("\n");

    // Example 10: Pointer to Pointer
    printf("Example 10: Pointer to Pointer\n");
    char *str_ptr = "test";
    char **ptr_to_ptr = &str_ptr;
    
    printf("str_ptr: %s\n", str_ptr);
    printf("*ptr_to_ptr: %s\n", *ptr_to_ptr);
    printf("**ptr_to_ptr: %c (first character)\n", **ptr_to_ptr);
    printf("\n");

    return 0;
}

// Custom strlen using pointer arithmetic
int strlen_custom(char *s) {
    int len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    return len;
}

// Custom strcpy using the while loop idiom
void strcpy_custom(char *s, char *t) {
    while (*s++ = *t++)
        ;  // copy until null terminator
}

// Custom strcmp using pointer arithmetic
int strcmp_custom(char *s, char *t) {
    while (*s == *t) {
        if (*s == '\0')
            return 0;  // strings are equal
        s++;
        t++;
    }
    return *s - *t;  // return difference
}

// Custom strchr — find character in string
char *strchr_custom(char *s, char c) {
    while (*s != c) {
        if (*s == '\0')
            return NULL;  // not found
        s++;
    }
    return s;  // found
}