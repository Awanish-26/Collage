// WAP that calculates the Simple Interest and Compound Interest.
#include<stdio.h>
#include<math.h>
void main() 
{
	float p, r, t, a, si, ci;
	printf("Enter Principle=");
	scanf("%f",&p);
	printf("Enter Rate=");
	scanf("%f",&r);
	printf("Enter Time in Years=");
	scanf("%f",&t);

	si=(p*r*t)/100;
	printf("Simple Interest=%.2f",si);
	a = p*(pow((1 + r / 100), t));
	ci =  a - p;
	printf("\nCompound Interest=%0.2f",ci);	
}