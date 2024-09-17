#include<stdio.h>

int main()
{
    int i,s,key,j;
    printf("enter size of your array:");
    scanf("%d",&s);
    int a[s];
    for (i = 0; i < s; i++)
    {
        printf("Enter your Array element %d:",i+1);
        scanf("%d",&a[i]);
    }
    for ( i = 1; i < s; i++)
    {
        key=a[i];
        j=i-1;

        while (j>=0 && key<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key; 
    }
    printf("Your sorted array is:\t");


    for ( i = 0; i < s; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}