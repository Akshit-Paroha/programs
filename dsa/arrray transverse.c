#include<stdio.h>

int main()
{
    printf("title: array traversing (practical 1)\n\n");
    int a[10],i,size;

    printf("Enter the size of array:");
    scanf("%d",&size);

    
    for (i = 0; i < size; i++)
    {
        printf("Enter your Array element %d:",i+1);
        scanf("%d",&a[i]);
    }

    printf("\nYour array elements are: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
    
    
}
