// WAP to print the sum of all numbers up to a given number
#include <stdio.h>  

// int main() {
//     int num,i, sum = 0; 
//     printf("Enter a positive number: ");  
//     scanf("%d", &num);
//     for (i = 0; i <= num; i++)  
//     {  
//         sum = sum + i; 
//     }   
//     printf("Sum of the first %d number is: %d", num, sum);   
//     return 0;
// }  

int sum(int number);

int main(){
    int num,result;

    printf("Enter ther number you want to get sum :");
    scanf("%d",&num);

    result = sum(num);

    printf("sum of digits : %d",result);
    return 0;
}

int sum( int number){
    if (number!=0){
        return number + sum(number-1);
    }
    else{
        return number;
    }
}
