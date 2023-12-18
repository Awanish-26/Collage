// WAP that swaps values of two variables using a third variable.

#include <stdio.h>
int main() {
    int a, b, temp;
    printf("Enter the value of a:");
    scanf("%d", &a);
    printf("Enter the value of b:");
    scanf("%d", &b);
    temp = a;
    a = b;
    b = temp;

    printf("After swapping:\n");
    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);
}

