// Sum and percentage of five subject

#include <stdio.h>
int main() {
    float sub1,sub2,sub3,sub4,sub5;
    float total_marks=0;
    printf ("Enter the marks obtained in subject 1:"); 
    scanf("%f", &sub1); 
    printf ("Enter the marks obtained in subject 2: "); 
    scanf("%f", &sub2); 
    printf ("Enter the marks obtained in subject 3: ");
    scanf("%f", &sub3); 
    printf ("Enter the marks obtained in subject 4: "); 
    scanf("%f", &sub4); 
    printf ("Enter the marks obtained in subject 5: "); 
    scanf("%f", &sub5); 
    total_marks = sub1+sub2+sub3+sub4+sub5; 
    float percentage = (total_marks / 500) * 100; 
    printf ("Sum of marks: %.2f\n", total_marks); 
    printf("Percentage marks obtained: %.2f%%\n", percentage); 
    return 0;
}
