// WAP to print Armstrong numbers from 1 to 100
#include <stdio.h>
#include <math.h>

int main() {
    int num, originalNum, remainder, result;
    int n = 0;

    printf("Armstrong numbers from 1 to 100:\n");

    for (num = 1; num <= 100; num++) {
        originalNum = num;
        result = 0;

        // Calculate the number of digits
        while (originalNum != 0) {
            originalNum /= 10;
            n++;
        }

        originalNum = num;

        // Calculate the result
        while (originalNum != 0) {
            remainder = originalNum % 10;
            result += pow(remainder, n);
            originalNum /= 10;
        }

        // Check if the number is an Armstrong number
        if (result == num) {
            printf("%d\n", num);
        }

        n = 0;
    }

    return 0;
}
