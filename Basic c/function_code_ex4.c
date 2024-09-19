#include<stdio.h>
int takenumber()
{
    int i;
    printf("Enter a number:");
    scanf("%d",i);
    return i;
}
int main()
{
    int c;
    c=takenumber;
    printf("the number entered is %d",c);
}