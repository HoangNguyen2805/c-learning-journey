#include <stdio.h>
#include <string.h>

/* Helper functions */
char *month_name(int n);
char *day_name(int n);
char *error_message(int code);

int main()
{
    printf("=== Chapter 5.8: Initialization of Pointer Arrays ===\n\n");

    /* Example 1: Basic month_name function */
    printf("Example 1: month_name lookup\n");
    for (int i = 0; i <= 13; i++) {
        printf("month_name(%2d) = %s\n", i, month_name(i));
    }
    printf("\n");

    /* Example 2: Day of week lookup */
    printf("Example 2: day_name lookup\n");
    for (int i = 0; i < 7; i++) {
        printf("day_name(%d) = %s\n", i, day_name(i));
    }
    printf("\n");

    /* Example 3: Inspect array of pointers */
    printf("Example 3: Pointers themselves (addresses)\n");
    static char *fruits[] = {"apple", "banana", "cherry"};
    for (int i = 0; i < 3; i++) {
        printf("fruits[%d] points to: %p\n", i, (void *)fruits[i]);
    }
    printf("(Each points to a string literal in memory)\n");
    printf("\n");

    /* Example 4: Dereferencing to get characters */
    printf("Example 4: Dereference to get first character\n");
    printf("*fruits[0] = '%c' (first char of apple)\n", *fruits[0]);
    printf("*fruits[1] = '%c' (first char of banana)\n", *fruits[1]);
    printf("*fruits[2] = '%c' (first char of cherry)\n", *fruits[2]);
    printf("\n");

    /* Example 5: Pointer arithmetic through array element */
    printf("Example 5: Pointer arithmetic through array\n");
    printf("fruits[0][2] = '%c' (3rd char of apple)\n", fruits[0][2]);
    printf("fruits[1][3] = '%c' (4th char of banana)\n", fruits[1][3]);
    printf("*(fruits[2] + 1) = '%c' (2nd char of cherry)\n", *(fruits[2] + 1));
    printf("\n");

    /* Example 6: Error codes mapped to messages */
    printf("Example 6: Error message lookup table\n");
    int codes[] = {0, 1, 2, 3, 999};
    for (int i = 0; i < 5; i++) {
        int code = codes[i];
        printf("Error %d: %s\n", code, error_message(code));
    }
    printf("\n");

    /* Example 7: Compiler counts initializers */
    printf("Example 7: Auto-sized array\n");
    static char *colors[] = {
        "red", "green", "blue", "yellow", "purple"
    };
    /* No explicit size needed; compiler counts 5 elements */
    printf("Color array size (inferred): ");
    int color_count = sizeof(colors) / sizeof(colors[0]);
    printf("%d colors\n", color_count);
    for (int i = 0; i < color_count; i++) {
        printf("  [%d] %s\n", i, colors[i]);
    }
    printf("\n");

    /* Example 8: Modifying which string a pointer points to */
    printf("Example 8: Array of pointers can be reassigned\n");
    char *animals[] = {"dog", "cat", "bird"};
    printf("Before: animals[0] = %s\n", animals[0]);
    animals[0] = "elephant";  /* Point to different string */
    printf("After:  animals[0] = %s\n", animals[0]);
    printf("\n");

    /* Example 9: Counting strings until NULL */
    printf("Example 9: Sentinel-terminated string array\n");
    static char *languages[] = {
        "C", "Python", "Java", "Rust", NULL
    };
    int count = 0;
    for (int i = 0; languages[i] != NULL; i++) {
        printf("  [%d] %s\n", i, languages[i]);
        count++;
    }
    printf("Found %d languages\n", count);
    printf("\n");

    /* Example 10: Demonstrating static keyword */
    printf("Example 10: Static array persistence\n");
    printf("Each call to month_name uses same static array:\n");
    for (int i = 1; i <= 3; i++) {
        char *m = month_name(i);
        printf("  Call %d: month_name(%d) = %s\n", i, i, m);
    }
    printf("(Array only initialized once, then reused)\n");
    printf("\n");

    return 0;
}

/* month_name: return name of n-th month */
char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}

/* day_name: return name of n-th day of week */
char *day_name(int n)
{
    static char *name[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };
    return (n < 0 || n > 6) ? name[0] : name[n];
}

/* error_message: return error message for code */
char *error_message(int code)
{
    static char *messages[] = {
        "No error",
        "File not found",
        "Permission denied",
        "Invalid argument"
    };
    if (code < 0 || code > 3)
        return "Unknown error";
    return messages[code];
}
