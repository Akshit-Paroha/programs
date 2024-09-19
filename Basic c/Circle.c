/*The following program could be used to find the area and circumference of a circle using C programming language
this code is developed by Akshit paroha
last date modified- 22/4/23 */
#include <stdio.h>
#define PI 3.14159265359
int main(int argc, char const *argv[])
{
    float R;
    printf("Enter the value of radius (in meters):");

    scanf("%f",&R);
    printf("area of circle = %f sq. meters\n", PI*R*R);
    printf("circumference= %f meters\n",PI*R*2);

    return 0;
}