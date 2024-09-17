#include <stdio.h>

int main()
{
    int i,n,j,temp;
    printf("Enter the Size of array:");
    scanf("%d",&n);
    int a[n];
    printf("enter elements of your array:");
    for(i=0;i<n;i++)
    {
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
