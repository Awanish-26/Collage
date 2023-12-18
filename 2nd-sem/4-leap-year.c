// To find leap year or not
#include <stdio.h>
int main()
{
    int Year;
    printf("Enter the Year you want to check leap year or not:");
    scanf("%d", &Year);
    if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
    {
        printf("%d is Leap year", Year);
    }
    else
    {
        printf("%d is not a Leap Year", Year);
    }
    return 0;
}