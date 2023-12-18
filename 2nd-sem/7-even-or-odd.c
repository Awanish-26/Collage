// WAP that finds whether a given number is even or odd.
#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter Your number: ");
    scanf("%d", &a);
    if (a % 2 == 0)
    {
        printf("EVEN NUMBER");
    }
    else
    {
        printf("ODD NUMBER");
    }
    return 0;
}