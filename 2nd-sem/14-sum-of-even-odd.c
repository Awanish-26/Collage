// WAP to print the sum of all numbers up to a given number.
#include <stdio.h>

int main() {
    int N, i;
    int sumEven = 0, sumOdd = 0;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            sumEven += i;  // Add even number to sumEven
        } else {
            sumOdd += i;   // Add odd number to sumOdd
        }
    }

    printf("Sum of even numbers from 1 to %d is: %d\n", N, sumEven);
    printf("Sum of odd numbers from 1 to %d is: %d\n", N, sumOdd);

    return 0;
}

