#include <stdio.h>
int main() {
    float num1, num2;
   
    // Get input from user
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
   
    // Perform calculations and display results
    printf("\nSum = %.2f\n", num1 + num2);
    printf("Difference = %.2f\n", num1 - num2);
    printf("Product = %.2f\n", num1 * num2);
   
    // Check for division by zero
    if (num2 != 0) {
        printf("Quotient = %.2f\n", num1 / num2);
    } else {
        printf("Quotient = undefined (division by zero)\n");
    }
   
    return 0;
}
