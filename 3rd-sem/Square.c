#include <stdio.h>

#define ARY_SIZE 5

int main(void){
    int arry[ARY_SIZE];
    printf("Results:\n");
    printf("Element\t Square\n");
    printf("=======\t=======\n");
    
    for(int i=0;i<ARY_SIZE;i++){
            scanf("%d \t",&arry[i]);
            int a=arry[i]*arry[i];
            printf("%5d\t\n",a);
    }
}
            
