/*
7.3A - Variable-length Argument Lists: worked examples
Compile: gcc -Wall -Wextra -o 7.3A 7.3A_variable_length_argument_lists.c
*/
#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);
int sum_n(int count, ...);
double avg_n(int count, ...);
int max_n(int count, ...);
char *first_match(char c, int count, ...);
void logmsg(const char *level, const char *fmt, ...);
void show_promotions(int count, ...);

int main(void)
{
    /* 1: K&R's minprintf */
    printf("=== Example 1: minprintf ===\n");
    minprintf((char *)"int=%d float=%f str=%s done\n", 42, 3.14, "yay");

    /* 2: literal percent + unknown spec fall-through */
    printf("\n=== Example 2: %%%% and unknown specs ===\n");
    minprintf((char *)"100%% sure; unknown %q passes through\n");

    /* 3: count-first variadics */
    printf("\n=== Example 3: sum_n(count, ...) ===\n");
    printf("sum_n(3, 1,2,3) = %d\n", sum_n(3, 1, 2, 3));
    printf("sum_n(5, 10,20,30,40,50) = %d\n", sum_n(5, 10, 20, 30, 40, 50));

    /* 4: doubles - promotion in action */
    printf("\n=== Example 4: avg_n with float args ===\n");
    float f1 = 1.5f, f2 = 2.5f;              /* floats arrive as doubles */
    printf("avg_n(2, 1.5f, 2.5f) = %.2f\n", avg_n(2, f1, f2));

    /* 5: running maximum */
    printf("\n=== Example 5: max_n ===\n");
    printf("max_n(4, 7, 99, -3, 42) = %d\n", max_n(4, 7, 99, -3, 42));

    /* 6: strings through the list */
    printf("\n=== Example 6: first string containing a char ===\n");
    char *hit = first_match('z', 3, "apple", "zebra", "corn");
    printf("first with 'z': %s\n", hit ? hit : "(none)");

    /* 7: forwarding with vfprintf (the error/log pattern) */
    printf("\n=== Example 7: logmsg forwards to vfprintf ===\n");
    logmsg("INFO", "loaded %d records from %s", 128, "data.csv");
    logmsg("WARN", "disk at %d%%", 91);

    /* 8: why va_arg(ap,int) for chars */
    printf("\n=== Example 8: promotions ===\n");
    char c = 'K';
    short s = 7;
    show_promotions(2, c, s);      /* both arrive as int */

    /* 9: zero extra args is legal */
    printf("\n=== Example 9: empty tail ===\n");
    printf("sum_n(0) = %d (loop body never runs)\n", sum_n(0));

    return 0;
}

/* K&R minprintf */
void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);
}

int sum_n(int count, ...)
{
    va_list ap;
    int total = 0;

    va_start(ap, count);
    for (int i = 0; i < count; i++)
        total += va_arg(ap, int);
    va_end(ap);
    return total;
}

double avg_n(int count, ...)
{
    va_list ap;
    double total = 0;

    if (count == 0)
        return 0;
    va_start(ap, count);
    for (int i = 0; i < count; i++)
        total += va_arg(ap, double);      /* floats were promoted */
    va_end(ap);
    return total / count;
}

int max_n(int count, ...)
{
    va_list ap;
    int best, v;

    va_start(ap, count);
    best = va_arg(ap, int);
    for (int i = 1; i < count; i++) {
        v = va_arg(ap, int);
        if (v > best)
            best = v;
    }
    va_end(ap);
    return best;
}

char *first_match(char c, int count, ...)
{
    va_list ap;
    char *s, *found = NULL;

    va_start(ap, count);
    for (int i = 0; i < count && found == NULL; i++) {
        s = va_arg(ap, char *);
        for (char *p = s; *p; p++)
            if (*p == c) {
                found = s;
                break;
            }
    }
    va_end(ap);
    return found;
}

/* forward variadic args to vfprintf - the 8.3 error() pattern */
void logmsg(const char *level, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    printf("[%s] ", level);
    vfprintf(stdout, fmt, args);
    printf("\n");
    va_end(args);
}

void show_promotions(int count, ...)
{
    va_list ap;

    va_start(ap, count);
    int as_int1 = va_arg(ap, int);       /* the char  'K' */
    int as_int2 = va_arg(ap, int);       /* the short 7   */
    printf("char arrived as int: %d ('%c'), short as int: %d\n",
           as_int1, as_int1, as_int2);
    va_end(ap);
}
