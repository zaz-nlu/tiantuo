#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;

    // Print the program name (argv[0])
    printf("Program name: %s\n", argv[0]);

    // Print command-line arguments starting from argv[1]
    for (i = 1; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
