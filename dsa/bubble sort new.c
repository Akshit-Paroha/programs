#include <stdio.h>

int main()
{
    int i, j, temp, n;
    printf("Enter the size of your array:");
    scanf("%d", &n);
    int a[n];
    printf("Enter your array elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d:", i + 1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - (i + 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("Your array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
}