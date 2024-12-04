#include<stdio.h>

int main()
{
    int n,i;
    printf("Enter size of your array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elemets of your array:\n");
    for ( i = 0; i <n; i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&a[i]);
    }
    printf("Your array elements are:");
    for ( i = 0; i < n; i++)
    {
       printf("%d\t",a[i]);
    }
    return 0;
}