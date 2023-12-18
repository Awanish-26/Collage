// WAP to search an element in a array using Linear Search
#include <stdio.h>

int search(int arr[], int N, int x){
	for (int i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

void main(){
    int i ,x;
    int arr[20]={52,36,26,4,62,5,62,46,2,46,26,30,10,2,44,20,17,63,12,51};

    printf("Elements in array are :");
    for(i=0;i<20;i++){
        printf("%d ",arr[i]);
    }

    printf("\nEnter the element to search :");
    scanf("%d",&x);

    int N = sizeof(arr) / sizeof(arr[0]);
    int result = search(arr, N, x);
    if(result==-1){
        printf("Element is not present in array");
    }
    else{
        printf("Element is present at index %d", result);
    }
}