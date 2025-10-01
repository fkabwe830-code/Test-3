#include <stdio.h>
int main() {
    float num1, num2, num3, largest;
   
    // Get three numbers from user
    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);
   
    // Assume first number is largest initially
    largest = num1;
   
    // Compare with second number
    if (num2 > largest) {
        largest = num2;
    }
   
    // Compare with third number
    if (num3 > largest) {
        largest = num3;
    }
   
    // Display the largest number found
    printf("The largest number is %.2f\n", largest);
   
    return 0;
}
