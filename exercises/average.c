#include <stdio.h>

average() {
    int numb1;
    int numb2;
    int numb3;
    printf("Enter the first number: ");
    scanf("%d", &numb1);
    printf("Enter the second number: ");
    scanf("%d", &numb2);
    printf("Enter the third number: ");
    scanf("%d", &numb3);
    printf("Average is: %.d\n", (numb1+numb2+numb3)/3);
}

int main() {
    average();
    return 0;
}