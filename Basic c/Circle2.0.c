#include<stdio.h>
#define PI 3.14159265359
int main ()
{
    float R;
    double Area,circumference,volume;
    printf("Please enter radius (in meters)\a:");
    scanf ("%f",&R);
    Area = PI*R*R; //mathematical formula
    circumference = 2*PI*R;/*mathematical formula*/
    volume = 4*PI*R*R*R/3;
    printf("Circumference of circle = %f meters\a\n",circumference);
    printf("Area of circle = %f sq. meters\a\n",Area);
    printf("Volume of such sphere = %f m³\a",volume);
    printf("\n\nThank You\a");
    return 0;
}