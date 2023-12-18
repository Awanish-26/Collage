// WAP to find the minimum and maximum element of the array.

#include<stdio.h>
void main(){
    int i,length,min =9999999,max = 0;
    
    printf("Enter the size of array :");
    scanf("%d",&length);

    int array[length];

    // input array
    for(i=0;i<length ; i++){
        printf("Enter value to be stored in array[%d]> ",i);
        scanf("%d",&(array[i]));
    }

    for (i=0;i<length;i++){
        if (array[i]<min){
            min = array[i];
        }
        if (array[i]>max){
            max = array[i];
        }
    }

    printf("Max = %d\n", max);
    printf("Min = %d", min);
}