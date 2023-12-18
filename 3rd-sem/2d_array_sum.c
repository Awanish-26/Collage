#include <stdio.h>

int main()
{
    // Variable declaration
    int Array1[10][10], Array2[10][10], Array3[10][10];
    int i, j, R1, R2, C1, C2;

    // Input no of row and col of both matrix
    printf("Enter row of 1st martix:");
    scanf("%d", &R1);
    printf("Enter col of 1st martix:");
    scanf("%d", &C1);
    printf("Enter row of 2nd martix:");
    scanf("%d", &R2);
    printf("Enter col of 2nd martix:");
    scanf("%d", &C2);

    if (R1 == R2 && C1 == C2)
    {
        printf("Enter array 1 \n");
        for (i = 0; i < R1; i++)
        {
            for (j = 0; j < C1; j++)
            {
                printf("Enter the Array1[%d][%d]:", i, j);
                scanf("%d", &Array1[i][j]);
            }
        }

        printf("Enter array 2 \n");
        for (i = 0; i < R2; i++)
        {
            for (j = 0; j < C2; j++)
            {
                printf("Enter the Array2[%d][%d]:", i, j);
                scanf("%d", &Array2[i][j]);
            }
        }

        for (i = 0; i < R1; i++)
        {
            for (j = 0; j < C1; j++)
            {
                Array3[i][j] = Array1[i][j] + Array2[i][j];
            }
        }

        printf("Output matrix \n");
        for (i = 0; i < R1; i++)
        {
            for (j = 0; j < C1; j++)
            {
                printf("%d\t", Array3[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}