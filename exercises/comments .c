#include<stdio.h>
int main() {
// we declare n as an integer 
    int n;
    // we tell the user to enter the number 
    printf("Enter a number: ");
    // we get the number 
    scanf("%d",&n);
    // if else statement to check if the number is positive or negative 
    if(n>0) {
    //if positive 
        printf("Positive");
    } else {
    //if negative 
        printf("Non-positive");
    }
    return 0;
}