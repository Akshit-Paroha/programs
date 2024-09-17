#include<stdio.h>

int main()
{
    int search,i,a[5],pos=-1;
    printf("Enter your Array elements:-\n");
    for (i = 0; i < 5; i++)
    {
        printf("element %d:",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&search);

    for ( i = 0; i < 5; i++)
    {
        if(a[i]==search)
        {
            pos=1;
            break;
        }  
    }
    
    if (pos=1)
    {
        printf("Your element is found at:%d",i+1);
    }
    else
    {
        printf("Element not found in the array!");
    }
    return 0;
}