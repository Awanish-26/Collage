#include <stdio.h>

int main()
{
    int data;
    int arr[5] = {56,52,96,86,12};
    printf("Enter the data to search:");
    scanf("%d", &data);
    for (int i; i < 5; i++)
    {
        if (arr[i] == data)
        {
            printf("data found\n");
            break;
        }
        else
        {
            continue;
        }
    }
    return 0;
}
