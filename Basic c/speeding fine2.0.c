#include<stdio.h>
int main()
{
    int speed;
    printf("Enter yours speed as an integer:");
    scanf("%d",&speed);
    speed = (speed<=65)? (65) :(speed<=70)? (70): (90);
    switch (speed)
    
    {
        case 65: printf("\nNo speeding ticket");break;
        case 70: printf("\nspeeding ticket");break;
        case 90: printf("\nexpensive speeding ticket");break;
        default: printf("\nincorrect speed");break;
    }
    return 0;
    
}