#include<stdio.h>
int main()
{
    int rain, outside; 
    printf("\n Enter if outside 1 true 0 false:");
    scanf("%d", &outside);
    printf("\n Enter if rain 1 true 0 false:");
    scanf("%d", &rain);
    if ( outside && rain)
    printf("\nUse an umbrella");
    else 
    printf("\n dress normally");
}