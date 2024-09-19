#include<stdio.h>
int main(void)
{
    float a,b,c,d;
    double average;
    printf("Please enter the value of a:\n");
    scanf("%f",&a);
    printf("Please enter the value of b:\n");
    scanf("%f",&b);
    printf("Please enter the value of c:\n");
    scanf("%f",&c);
    printf("Please enter the value of d:\n");
    scanf ("%f",&d);
    average = (a+b+c+d)/4;
    printf("average=%f",average);
    return 0;
}
