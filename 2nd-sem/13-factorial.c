// 13. WAP to find the factorial of a given number
#include <stdio.h>
int main(){
    int num,fact=1 ,i;
    printf("Enter the number to find factorial :");
    scanf("%d",&num);
    if(num<=0){
        fact=1;
    }
    else{
        for(i=1;i<=num;i++){
            fact=fact*i;
        }
    }
    printf("Factorial of %d = %d ",num,fact);
}