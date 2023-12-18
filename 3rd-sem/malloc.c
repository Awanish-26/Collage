#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n = 2; // Number of integers you want to allocate memory for

    arr = (int *)malloc(n * sizeof(int)); // Allocate memory for an array of 'n' integers

    if (arr == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * 10;
    }

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}

// malloc allocates memory with a base address and its default type is void . tpye casting is required to convert it and it should be a pointer
