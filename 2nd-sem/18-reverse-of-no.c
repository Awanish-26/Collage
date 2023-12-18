// WAP to find the reverse of a number
#include <stdio.h>

int main() {
    int num, remainder, reverse = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Calculate the reverse of the number
    while (num != 0) {
        remainder = num % 10;    // Get the rightmost digit
        reverse = reverse * 10 + remainder;    // Append the digit to the reverse
        num /= 10;    // Remove the rightmost digit
    }

    printf("Reverse of the number: %d\n", reverse);

    return 0;
}
