#include <stdio.h>
even_oddChecker () {

    int number;

    printf("Enter a number to be checked if it's odd or even:\n");
    scanf("%d", &number);
    if(number %2==0) {
        printf("%d is even\n", number);
    } else {
        printf("%d is odd\n", number);
    }
}
int main() {
    even_oddChecker ();
    return 0;
}