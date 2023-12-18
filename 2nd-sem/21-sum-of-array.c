// WAP that simply takes elements of the array from the user and finds the sum of these elements.

#include<stdio.h>

int main(void){
    int length ,sum = 0;
    printf("Enter the size of array :");
    scanf("%d",&length);

    int array[length];

    for(int i=0;i<length ; i++){
        printf("Enter value to be stored in array[%d]> ",i);
        scanf("%d",&(array[i]));
    }


    for(int j=0;j<length;j++){
        sum = sum + array[j];
    }
    printf("Sum of Elements of Array is %d",sum);
    return 0;
}