// WAP to sort the elements of the array in ascending order using Bubble Sort technique.

#include <stdio.h>
#include <string.h>



int main(){
    int array[2]={5,2};
    if (array[0] > array[1]){
        int num = array[1];
        array[1] = array[0];
        array[0] = num;       
    }
    int size = sizeof(array)/4;
    for (int i = 0; i < 2; i++)
    {
        printf("%d",array[i]);
    }

    return 0;
}
