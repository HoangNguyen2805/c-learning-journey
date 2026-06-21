#include <stdio.h>

int stringLength(register char s[]) {
    register int i;

    i = 0;

    while (s[i] != '\0') {
        i++;
    }

    return i;
}

int main() {
    char word[] = "hello";
    int length;

    length = stringLength(word);

    printf("Word: %s\n", word);
    printf("Length: %d\n", length);

    return 0;
}