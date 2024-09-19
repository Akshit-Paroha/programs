#include<stdio.h>
int main  ()
{
    int speed;
    printf("\nPlease enter your speed as an integer:");
    scanf("%d",&speed);
    if (speed <= 65)
    printf("\n\nNO SPEEDING FINE\a");
    else 
    printf("\n\nSPEEDING FINE\a\a\a");
}