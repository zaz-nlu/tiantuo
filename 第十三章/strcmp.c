#include <stdio.h>
#include <string.h>

int main() {
    const char *s1 = "hello";
    const char *s2 = "world";

    int result = strcmp(s1, s2);

    if (result == 0) {
        printf("%s is equal to %s\n", s1, s2);
    } else if (result < 0) {
        printf("%s is less than %s\n", s1, s2);
    } else {
        printf("%s is greater than %s\n", s1, s2);
    }

    return 0;
}