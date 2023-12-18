// WAP to convert binary number into decimal number and vice versa.
#include <stdio.h>
#include <math.h>

// Function to convert binary to decimal
int binaryToDecimal(long long binaryNum) {
    int decimalNum = 0, i = 0, remainder;

    while (binaryNum != 0) {
        remainder = binaryNum % 10;
        binaryNum /= 10;
        decimalNum += remainder * pow(2, i);
        ++i;
    }

    return decimalNum;
}

// Function to convert decimal to binary
long long decimalToBinary(int decimalNum) {
    long long binaryNum = 0;
    int remainder, i = 1;

    while (decimalNum != 0) {
        remainder = decimalNum % 2;
        decimalNum /= 2;
        binaryNum += remainder * i;
        i *= 10;
    }

    return binaryNum;
}

int main() {
    long long binaryNum;
    int decimalNum;

    // Convert binary to decimal
    printf("Enter a binary number: ");
    scanf("%lld", &binaryNum);
    decimalNum = binaryToDecimal(binaryNum);
    printf("Decimal number: %d\n", decimalNum);

    // Convert decimal to binary
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    binaryNum = decimalToBinary(decimalNum);
    printf("Binary number: %lld\n", binaryNum);

    return 0;
}


