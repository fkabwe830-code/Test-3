#include <stdio.h>
int main() {
    float num1, num2, result;
    char operation;
   
    // Get numbers and operation from user
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    printf("Choose operation (+, -, *, /): ");
    scanf(" %c", &operation);  // Space before %c to skip whitespace
   
    // Perform calculation based on operation
    switch (operation) {
        case '+':
            result = num1 + num2;  // Addition
            break;
        case '-':
            result = num1 - num2;  // Subtraction
            break;
        case '*':
            result = num1 * num2;  // Multiplication
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;  // Division
            } else {
                printf("Error: Division by zero!\n");
                return 1;  // Exit with error code
            }
            break;
        default:
            printf("Invalid operation!\n");
            return 1;  // Exit with error code
    }
   
    printf("Result = %.2f\n", result);
    return 0;
}
