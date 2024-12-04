#include<stdio.h>
int main()
{
    int a[5]={12,57,34,10,50};
    int i,j,key,n=5;

    for (i = 1; i < n; i++)
    {
        j=i-1;
        key = a[i];

        while (j >=0 && key <a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;

    }
    printf("Your sorted array is:   ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    return 0;

}