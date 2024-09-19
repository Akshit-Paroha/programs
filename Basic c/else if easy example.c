#include<stdio.h>
int main(int argc, char const *argv[])
{
    int number;
    printf("Enter a number:");
    scanf("%d",&number);
    if (number<100)
    printf("\nNumber is less than 100");
    else if (number == 100)
    printf("\n Number is 100");
    else
    printf("\nNumber is greater than 100");
    
    return 0;
}