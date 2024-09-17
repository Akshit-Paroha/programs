#include <stdio.h>

int main()
{
    printf("Title: selection sort(practical 5)\n\n");
    int i,n,j,temp;
    printf("Enter the Size of array:");
    scanf("%d",&n);
    int a[n];
    printf("enter elements of your array:\n");
    for(i=0;i<n;i++)
    {
        printf("Element %d:",i+1);
        scanf("%d",&a[i]);
    }

    for (i = 0; i < n; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if (a[i]>a[j])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            } 
        }
        printf("\nYour sorted array is:");
        for (j = 0; j < 5; j++)
        {
            printf("%d ",a[j]);
        }
    }
    return 0;   
}
