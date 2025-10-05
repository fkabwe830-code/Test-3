#include <stdio.h>

int main() {
    // Declare variables for loop counter and user input
    int i, n;

    // Prompt the user to enter a value for n
    printf("Enter n: ");
    scanf("%d", &n);

    // Loop from 1 to n inclusive
    for (i = 1; i <= n; i++) {
        // Check if the number is even
        if (i % 2 == 0) {
            // Print even numbers without brackets
            printf("%d ", i);
        } else {
            // Print odd numbers with brackets
            printf("[%d] ", i);
        }
    }

    // Return 0 to indicate successful execution
    return 0;
}