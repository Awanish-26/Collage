#include <stdio.h>

int main()
{
    int row, col;

    printf("Enter the number of rows and columns for the first array:\n");
    scanf("%d %d", &row, &col);

    // Initialize the array
    int array[row][col];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter the number[%d][%d]:", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // Initalise the output array and swap rows and colums
    int result[col][row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[j][i] = array[i][j];
        }
    }

    // Interchange the row and col call
    printf("\n");
    printf("Transpose of given array-\n");
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}