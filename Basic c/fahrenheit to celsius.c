/*
The following program can be used to convert fahrenheit to celsius using C programming language
By Akshit Paroha
22 April, 2023
*/
#include<stdio.h>
int main(int argc, char const *argv[])
{
    float fahrenheit, celsius;
    printf("please enter fahrenheit as an integer:");
    scanf ("%f",&fahrenheit);
    celsius = (fahrenheit-32)/1.8; //note conversion
    printf("\n %f fahrenheit is %f celsius.\n",fahrenheit, celsius);

    return 0;
}
