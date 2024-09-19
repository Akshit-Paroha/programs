/*
this code can be used to calculate the distance of a marathon in kilometers
By Akshit Paroha
23 April,2023
*/
#include<stdio.h>
int main(int argc, char const *argv[])
{
    float M,Y;
    double Km;
    printf("please enter miles:\n");
    scanf ("%f",&M);
    printf("Please enter yards:\n");
    scanf ("%f",&Y);
    Km = 1.60934 * (M+Y/1760.0);
    printf("A %f miles and %f yards long marathon is %f Kilometers\n",M,Y,Km);
    return 0;
}

