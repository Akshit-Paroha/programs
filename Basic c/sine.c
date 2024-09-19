#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main(void)
{
    double x, answer;
    printf("Enter the angle value: ");
    scanf("%lf",&x);
    answer=sin(x);
    printf("the sine of %lf is %lf \a\a\a",x,answer);
    return 0;
    
}