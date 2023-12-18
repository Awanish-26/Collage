// WAP that accepts marks of five subjects and finds percentage and prints grades
#include <stdio.h>
int main (void)
{
    int subject_1, subject_2, subject_3, subject_4, subject_5;
    int sum;
    float percentage;
    char grade;

    //Input 5 subjects marks.
    printf ("Input first subject marks: ");
    scanf ("%d", &subject_1);
    printf ("Input second subject marks: ");
    scanf ("%d", &subject_2);
    printf ("Input third subject marks: ");
    scanf ("%d", &subject_3);
    printf ("Input forth subject marks: ");
    scanf ("%d", &subject_4);
    printf ("Input fifth subject marks: ");
    scanf ("%d", &subject_5);

    //Calculate the sum and percentage.
    sum = subject_1 + subject_2 + subject_3 + subject_4 + subject_5;
    percentage = sum / 5.0;

    //Calculate the grade.
    if (percentage >= 90)
        grade = 'A';
    else if (percentage >= 80)
        grade = 'B';
    else if (percentage >= 60)
        grade = 'C';
    else
        grade = 'D';

    //Output the result.
    printf ("Percentage: %.2f %\n", percentage);
    printf ("Grade: %c", grade);
    return 0;
};