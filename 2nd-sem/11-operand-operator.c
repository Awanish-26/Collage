/* WAP that takes two operands and one operator from the user and perform the operation and prints 
the result by using Switch statement.*/ 

#include <stdio.h>

int main() {
    double operand1, operand2, result;
    char operator;

    printf("Enter first operand: ");
    scanf("%lf", &operand1);

    printf("Enter second operand: ");
    scanf("%lf", &operand2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch (operator) {
        case '+':
            result = operand1 + operand2;
            printf("Result: %.2lf\n", result);
            break;
        case '-':
            result = operand1 - operand2;
            printf("Result: %.2lf\n", result);
            break;
        case '*':
            result = operand1 * operand2;
            printf("Result: %.2lf\n", result);
            break;
        case '/':
            if (operand2 != 0) {
                result = operand1 / operand2;
                printf("Result: %.2lf\n", result);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;
        default:
            printf("Error: Invalid operator!\n");
            break;
    }

    return 0;
}
