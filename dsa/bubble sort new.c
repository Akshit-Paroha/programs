#include<stdio.h>

int main ()
{
    printf("Title: Bubble sort (practical 4)\n\n");
    int i,j,n,temp;
    printf("Enter the Size of array:");
    scanf("%d",&n);
    int a[n];
    printf("enter elements of your array:\n\n");
    for(i=0;i<n;i++)
    {
        printf("Element %d:",i+1);
        scanf("%d",&a[i]);
    }

    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("sorted array: \t");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	
	return 0;
 
}