// WAP that inputs two arrays and saves sum of corresponding elements of these arrays in a third array and prints them.

#include<stdio.h>
int main(void){
    int length ,i ;

    // Size of Array
    printf("Enter the size of array :");
    scanf("%d",&length);

    int array[length],array2[length];
    int array3[length];

    // First array input
    for(i=0;i<length ; i++){
        printf("Enter value to be stored in array[%d]> ",i);
        scanf("%d",&(array[i]));
    }

    // Second array input
    for(i=0;i<length ; i++){
        printf("Enter value to be stored in array2[%d]> ",i);
        scanf("%d",&(array2[i]));
    }

    //Sum of elements of array 
    for(i=0;i<length;i++){
        array3[i]=array[i]+array2[i];
    }

    // Print the Result
    for(i=0;i<length;i++){
        printf("\nElements of Array3 [%d]:%d",i,array3[i]);
    }
}
