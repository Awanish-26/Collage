// WAP to find the sum of digits of the entered number
#include <stdio.h>

int main() {
    int num, remainder, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Calculate the sum of digits
    while (num > 0) {
        remainder = num % 10;    // Get the rightmost digit
        sum += remainder;        // Add the digit to the sum
        num =num / 10;               // Remove the rightmost digit
    }

    printf("Sum of digits: %d\n", sum);

    return 0;
}
