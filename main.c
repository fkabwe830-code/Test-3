#include <stdio.h>

int main() {
    // Initialize variables
    int age;
    char name[50];
    char hobby[50];

    // Get user input
    printf("Enter your age: ");
    scanf("%d", &age);
    
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("Enter your hobby: ");
    scanf("%s", hobby);

    // Output greeting
    printf("\nHey %s, you're %d years old and you like %s.\n", name, age, hobby);

    return 0;
}
