#include <stdio.h>
int main() {
    int number;
   
    // Get number from user
    printf("Enter a number: ");
    scanf("%d", &number);
   
    // Check if number is even or odd using modulus operator
    // Even numbers divide by 2 with remainder 0
    if (number % 2 == 0) {
        printf("%d is Even\n", number);
    } else {
        printf("%d is Odd\n", number);
    }
   
    return 0;
}
